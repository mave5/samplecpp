//#include"msdsd_od.h"
#include "mex.h"
/////////////////////////////////////////////////////////////
//MSDSD Decoder especially for orthogonal design (alamouti)//
/////////////////////////////////////////////////////////////

double msdsd_od( int1D dataHat, complex3D r, double2D U,int M )
{ 
  int i, j,k, n, nn, N, nR, nT, index=0;
  static int prevN=0, sqrtM=0;
  double d_new, d_best, delta;
  static int1D m, mSave, step, stepSave, numPoints;
  static double1D ds;
  static complex1D codebook, alpha;
  static complex3D X, S;
  static complex4D RTilde;

  double fanoBias;
  double fanoDelta;

  double flops = 0;

  N = r.dim1;
  nT = 2;
  nR = r.dim3;

  fanoBias = 0;//nT*nR;
  fanoDelta = 0;//1;

      
  //(Re-)allocation of memory
  if( prevN!=N ){
    sqrtM = sqrt(M);
    if( prevN!=0 ){
      destroy1D( ds );
      destroy1D( numPoints );
      destroy1D( m );
      destroy1D( mSave );
      destroy1D( step );
      destroy1D( stepSave );
      destroy1D( alpha );
      destroy1D( codebook );
      destroy3D( S, i, j );
      destroy3D( X, i, j );
      destroy4D( RTilde, i, j, n );
    }
    create1D( ds,         N, double );
    create1D( numPoints,2*N, int );
    create1D( m,        2*N, int );
    create1D( mSave,    2*N, int );
    create1D( step,     2*N, int );
    create1D( stepSave, 2*N, int );
    create1D( alpha,    2*N, complex );
    create1D( codebook,   sqrtM, complex );
    create3D( S,          N,   nT, nT, complex, i, j );
    create3D( X,          N-1, nT, nR, complex, i, j );
    create4D( RTilde,     N-1, N, nT, nR, complex, i, j, n );
    
    S.val[N-1][0][0] = S.val[N-1][1][1] = cmake(1,0);
    S.val[N-1][1][0] = S.val[N-1][0][1] = cmake(0,0);
    
    for( i=0; i<sqrtM; i++ )//generate list of (weighted) PSK symbols
      codebook.val[i] = cmake(cos(twopi/sqrtM*i)/sqrt(2), sin(twopi/sqrtM*i)/sqrt(2));
    
    prevN = N;
  }
  
  for( i = 0; i < N-1; i++ )
    for( j = i; j < N; j++ )
      for( k=0; k<nT; k++ )
	for( n=0; n<nR; n++ )
	  RTilde.val[i][j][k][n] = cmake(U.val[i][j]*r.val[j][k][n].re,
					 U.val[i][j]*r.val[j][k][n].im);
  flops += N*(N-1)/2*nR*nT*2;

  //start of alg
  n  = N-2;
  nn = 2*n;
  d_best = 1e12;
  ds.val[N-1] = 0;

  flops += calc_X_n_od( X.val[n], S.val, RTilde.val[n], n, N, nR );

  flops += findBest_od_Tilde( &m.val[nn],         &m.val[nn+1], 
			      &mSave.val[nn],     &mSave.val[nn+1], 
			      &step.val[nn],      &step.val[nn+1], 
			      &stepSave.val[nn],  &stepSave.val[nn+1], 
			      &numPoints.val[nn], &numPoints.val[nn+1], 
			      &alpha.val[nn],     &alpha.val[nn+1],
			      RTilde.val[n][n],   X.val[n], 
			      sqrtM, nR );//find best cand. for m[nn] and m[nn+1]
  //printf("\nnewblock\n");
  while( flops<=1e8 ){
    //dispI(n,"n");
    //dispI(nn,"nn");
    //flops += calc_delta_n_od( &delta,RTilde.val[n][n], X.val[n],codebook.val[m.val[2*n]], codebook.val[m.val[2*n+1]],nR );
    flops += calc_delta_n_od_Tilde( &delta, RTilde.val[n][n], X.val[n], codebook.val[m.val[2*n]], codebook.val[m.val[2*n+1]], alpha.val[2*n], alpha.val[2*n+1], nR );
    d_new = ds.val[n+1]+delta-fanoBias;  flops+=1+(fanoBias!=0);
    //PAUSE
    if( d_new < d_best+fanoDelta ){
      ds.val[n] = d_new;
      if( n > 0 ){//not at a leaf of the tree yet
        flops += calc_S_n_od( S.val[n], S.val[n+1], codebook.val[m.val[2*n]], codebook.val[m.val[2*n+1]] );
        n--;
        nn = 2*n;
    	flops += calc_X_n_od( X.val[n], S.val, RTilde.val[n], n, N, nR );
        flops += findBest_od_Tilde( &m.val[nn],         &m.val[nn+1], 
				    &mSave.val[nn],     &mSave.val[nn+1], 
				    &step.val[nn],      &step.val[nn+1], 
				    &stepSave.val[nn],  &stepSave.val[nn+1], 
				    &numPoints.val[nn], &numPoints.val[nn+1], 
				    &alpha.val[nn],     &alpha.val[nn+1],
				    RTilde.val[n][n],   X.val[n], 
				    sqrtM, nR );
      }
      else{//reached a leaf of tree
        if( ds.val[0]<d_best ){
            for( j=0; j<N-1; j++ )
                dataHat.val[j] = sqrtM*m.val[2*j]+m.val[2*j+1];
            }
        if( N==2 ) 
            return flops;
        d_best = ds.val[n];
        nn++;//one extra, because of independence of a pair of decisions
        do{
        if( nn==2*N-3 ) 
            return flops;
            nn++;
        }
        while( numPoints.val[nn]>=sqrtM );
        n = floor((double)nn/2); flops++;
        numPoints.val[nn-1] = 1;                 //only necessary when 
        m.val[nn-1]         = mSave.val[nn-1];   //nn!=2*n but does no 
        step.val[nn-1]      = stepSave.val[nn-1];//harm otherwise
        flops += findNext_od( &m.val[nn], &step.val[nn], &numPoints.val[nn], sqrtM );
      }
    }
    else{
      if( numPoints.val[nn]==1 && numPoints.val[nn+1]==1 )
        nn++;//NEW BEST pair of candidates has too large metric
      do{
        if( nn==2*N-3 ) 
            return flops;
        nn++;
      }
      while( numPoints.val[nn]>=sqrtM );
      n = floor(nn/2); flops++;
      numPoints.val[nn-1] = 1;                 //only necessary when 
      m.val[nn-1]         = mSave.val[nn-1];   //nn!=2*n but does no
      step.val[nn-1]      = stepSave.val[nn-1];//harm otherwise
      flops += findNext_od( &m.val[nn], &step.val[nn], &numPoints.val[nn], sqrtM );
    }
  }
}
//=========================================================================
double findBest_od( int *m_a, int *m_b, 
		    int *m_aBest, int *m_bBest,
		    int *step_a, int *step_b,
		    int *stepSave_a, int *stepSave_b,
		    int *nP_a, int *nP_b, 
		    complex **RTilde, 
		    complex **X, 
		    int sqrtM,
		    int nR )
{
  int mu, nu;
  double  m_aTilde, m_bTilde;
  double flops=0;
  complex alpha, beta;
  static double factor=0; 

  if( factor==0 ) factor = sqrtM/twopi;

  for( alpha=cmake(0,0), beta=cmake(0,0), mu=0; mu<nR; mu++ )
    {
      alpha = cadd(alpha, cmul(conjcomp(X[0][mu]),          RTilde[0][mu]));
      alpha = cadd(alpha, cmul(         X[1][mu] , conjcomp(RTilde[1][mu])));
      beta  = cadd(beta , cmul(conjcomp(X[1][mu]),          RTilde[0][mu]));
      beta  = csub(beta , cmul(         X[0][mu] , conjcomp(RTilde[1][mu])));
    }
  flops += 32*nR;

  m_aTilde = factor*atan2(alpha.im, -alpha.re);       flops += 2;
  m_bTilde = factor*atan2(beta.im,  -beta.re );       flops += 2;
  *m_a = round(m_aTilde);                             flops++;
  *m_b = round(m_bTilde);                             flops++;
  *step_a = *stepSave_a = ( m_aTilde>(*m_a) )? 1: -1; flops++;
  *step_b = *stepSave_b = ( m_bTilde>(*m_b) )? 1: -1; flops++;
  *m_a = *m_aBest = modulo(*m_a,sqrtM);               flops++;
  *m_b = *m_bBest = modulo(*m_b,sqrtM);               flops++;
  *nP_a = 1;
  *nP_b = 1;
  return flops;
}

double findBest_od_Tilde( int *m_a, int *m_b, 
			  int *m_aBest, int *m_bBest,
			  int *step_a, int *step_b,
			  int *stepSave_a, int *stepSave_b,
			  int *nP_a, int *nP_b, 
			  complex *alpha, complex *beta,
			  complex **RTilde, 
			  complex **X, 
			  int sqrtM,
			  int nR )
{
  int mu, nu;
  double  m_aTilde, m_bTilde;
  double flops=0;
  static double factor=0; 

  if( factor==0 ) factor = sqrtM/twopi;

  for( *alpha=*beta=cmake(0,0), mu=0; mu<nR; mu++ )
    {
      *alpha = cadd(*alpha, cmul(conjcomp(X[0][mu]),          RTilde[0][mu]));
      *alpha = cadd(*alpha, cmul(         X[1][mu] , conjcomp(RTilde[1][mu])));
      *beta  = cadd(*beta , cmul(conjcomp(X[1][mu]),          RTilde[0][mu]));
      *beta  = csub(*beta , cmul(         X[0][mu] , conjcomp(RTilde[1][mu])));
    }
  flops += 32*(nR-1)+24;;

  m_aTilde = factor*atan2((*alpha).im, -(*alpha).re); flops += 2;
  m_bTilde = factor*atan2((*beta).im,  -(*beta).re ); flops += 2;
  *m_a = round(m_aTilde);                             flops++;
  *m_b = round(m_bTilde);                             flops++;
  *step_a = *stepSave_a = ( m_aTilde>(*m_a) )? 1: -1; flops++;
  *step_b = *stepSave_b = ( m_bTilde>(*m_b) )? 1: -1; flops++;
  *m_a = *m_aBest = modulo(*m_a,sqrtM);               flops++;
  *m_b = *m_bBest = modulo(*m_b,sqrtM);               flops++;
  *nP_a = 1;
  *nP_b = 1;
  return flops;
}

double findNext_od( int *m, int *step, int *numPoints, int sqrtM )
{
  double flops = 4;

  *m    = modulo((*m)+(*step),sqrtM); //flops += 2;
  *step = -(*step)+(1-2*((*step)>0)); //flops += 2;
  (*numPoints)++;
  return flops;
}

double calc_S_n_od( complex **S_n, complex **S_nP1, complex a, complex b )
{
  double flops = 28;

  S_n[0][0] = cadd(cmul(conjcomp(a),       S_nP1[0][0]), cmul(conjcomp(b),S_nP1[1][0]));
  S_n[1][0] = cadd(cmul(cmake(-b.re,-b.im),S_nP1[0][0]), cmul(         a, S_nP1[1][0]));
  S_n[0][1] = cmake(-S_n[1][0].re, S_n[1][0].im);
  S_n[1][1] = conjcomp(S_n[0][0]);

  return flops;
}

double calc_X_n_od( complex **X, complex ***S, complex ***RTilde, int n, int N, int nR )
{
  int i, j;
  complex helper0, helper1;
  double flops = 0;
  
  if( n==N-2 )
    for( i=0; i<nR; i++ )
      {
	X[0][i] = RTilde[n+1][0][i];
	X[1][i] = RTilde[n+1][1][i];
      }
  else
    for( i=0; i<nR; i++ )
      {
	for( helper0=helper1=cmake(0,0), j=n+1; j<N; j++ )
	  {
	    helper0 = cadd(helper0,cmul(conjcomp( S[j][0][0]),                  RTilde[j][0][i]));
	    helper0 = cadd(helper0,cmul(conjcomp( S[j][1][0]),                  RTilde[j][1][i]));
	    helper1 = cadd(helper1,cmul(   cmake(-S[j][1][0].re,-S[j][1][0].im),RTilde[j][0][i]));
	    helper1 = cadd(helper1,cmul(          S[j][0][0],                   RTilde[j][1][i]));
	    flops += 28;
	  }
	X[0][i] = cadd(cmul(S[n+1][0][0], helper0),cmul(S[n+1][0][1],helper1));
	X[1][i] = cadd(cmul(S[n+1][1][0], helper0),cmul(S[n+1][1][1],helper1));
	flops += 28;
      }

  return flops;
}

double calc_delta_n_od( double *delta, complex **RTilde, complex **X, complex a, complex b, int nR )
{
  int i;
  double flops=0;
  complex helper;

  for( *delta=0, i=0; i<nR; i++ )
    {
      helper = cadd(X[0][i], cmul(         a ,RTilde[0][i]));
      helper = csub(helper,  cmul(conjcomp(b),RTilde[1][i]));
      *delta += pow(helper.re,2)+pow(helper.im,2);

      helper = cadd(X[1][i], cmul(         b ,RTilde[0][i]));
      helper = cadd(helper,  cmul(conjcomp(a),RTilde[1][i]));
      *delta += pow(helper.re,2)+pow(helper.im,2);
    }
  flops = nR*38;
  return flops;
}

double calc_delta_n_od_Tilde( double *delta, 
			      complex **RTilde, 
			      complex **X, 
			      complex a, complex b, 
			      complex alpha, complex beta, 
			      int nR )
{
  int i;
  double flops=0;

  *delta = 2*(a.re*alpha.re-a.im*alpha.im+b.re*beta.re-b.im*beta.im);
  flops = 8;
  for( i=0; i<nR; i++ )
    {
      *delta += pow(RTilde[0][i].re,2)+pow(RTilde[0][i].im,2);
      *delta += pow(RTilde[1][i].re,2)+pow(RTilde[1][i].im,2);
      *delta += pow(     X[0][i].re,2)+pow(     X[0][i].im,2);
      *delta += pow(     X[1][i].re,2)+pow(     X[1][i].im,2);
    }
  flops = nR*8;//not counting flops for ||R|| because they are repeated again and again (one could store ||R||)
  return flops;
}


double run_msdsd_od( int1D dataHat, 
		     complex3D r,
		     double esno_dB, 
		     double BfT, 
		     int N, 
		     int M,
		     int DDFadingMode )
{
  int i, j;
  static int prevN = 0, prevNR = 0, prevNT = 0, blocksPerRun;
  static double prevEsno_dB = 0, sigma2_n;
  static double2D Phi_hh, U, Phi_hhInv;
  static complex3D rPart;
  static int1D dataHatPart;

  double flops = 0;

  if( ( prevEsno_dB != esno_dB ) || ( prevN != N ) || ( prevNT != r.dim2 ) || ( prevNR != r.dim3 ) )
  {
    if( ( prevN != N ) || ( prevNT != r.dim2 ) || ( prevNR != r.dim3 ) )
    {
      if( ( prevN != 0 ) && ( prevNT != 0 ) )
	{
	  destroy1D( dataHatPart );
	  destroy2D( Phi_hh, i );
	  destroy2D( Phi_hhInv, i );
	  destroy2D( U, i );
	  destroy3D( rPart, i, j );
	}
      create1D( dataHatPart, N-1, int );
      create2D( Phi_hh,    N, N, double, i );
      create2D( Phi_hhInv, N, N, double, i );
      create2D( U,         N, N, double, i );
      create3D( rPart, N, r.dim2, r.dim3, complex, i, j );
      prevN = N;
      prevNT = r.dim2;
      prevNR = r.dim3;
      blocksPerRun = floor((r.dim1-1)/(N-1));
    }

    sigma2_n = pow(10,-esno_dB/10);
    //sigma2_n = pow(10,-esno_dB/10)+2*(1-BessJ0(twopi*BfT/4*r.dim2) );printf("\nmodified sigma_n^2 in msdsd_od\n");
    generate_Phi_hh_tilde( Phi_hh, BfT, r.dim2, DDFadingMode );
    //generate_Phi_hh( Phi_hh, BfT, r.dim2 );
    //dispD2D(Phi_hh,"Phi_hh");
    //PAUSE

    for( j = 0; j < Phi_hh.row; j++ )
      Phi_hh.val[ j ][ j ] += sigma2_n;

    eye( U.val, U.row );
    gaussj( Phi_hhInv.val, U.val, Phi_hh.val, U.val, Phi_hh.row, Phi_hh.col, U.row, U.col );

    chol_dcmp( U.val, Phi_hhInv.val, Phi_hhInv.row );

    prevEsno_dB = esno_dB;
  }

  for( i = 0; i < blocksPerRun; i++ )
    {
      //dispI(i,"blockindex");
      for( j=0; j<N; j++ )
	copyCArray( rPart.val[j], r.val[i*(N-1)+j], r.dim2,r.dim3 );

      flops += msdsd_od( dataHatPart, rPart, U, M );
      
      for( j=0; j<N-1; j++ )
      	dataHat.val[i*(N-1)+j] = dataHatPart.val[j];
    }
  return flops;
}




double run_msdsd_od_subset( int1D dataHat, 
			    complex3D r, 
			    double esno_dB, 
			    double BfT, 
			    int N,
			    int M )
{
  int i, j;
  static int prevN = 0, prevNR = 0, prevNT = 0, blocksPerRun, decPos, NTick;
  static double prevEsno_dB = 0, sigma2_n;
  static double2D Phi_hh, U, Phi_hhInv;
  static complex3D rPart;
  static int1D dataHatPart;

  double flops = 0;

  if( ( prevEsno_dB != esno_dB ) || ( prevN != N ) || ( prevNT != r.dim2 ) || ( prevNR != r.dim3 ) )
    {
      if( ( prevN != N ) || ( prevNT != r.dim2 ) || ( prevNR != r.dim3 ) )
	{
	  if( ( prevN != 0 ) && ( prevNT != 0 ) )
	    {
	      destroy1D( dataHatPart );
	      destroy2D( Phi_hh, i );
	      destroy2D( Phi_hhInv, i );
	      destroy2D( U, i );
	      destroy3D( rPart, i, j );
	    }
	  create1D( dataHatPart, N-1, int );
	  create2D( Phi_hh,    N, N, double, i );
	  create2D( Phi_hhInv, N, N, double, i );
	  create2D( U,         N, N, double, i );
	  create3D( rPart, N, r.dim2, r.dim3, complex, i, j );
	  prevN = N;
	  prevNT = r.dim2;
	  prevNR = r.dim3;
	  //blocksPerRun = r.dim1-N+1;
	  //decPos = floor((N-1)/2);
	  NTick = N-2;
	  blocksPerRun = floor((r.dim1-1-N+NTick)/(NTick-1));
	}
      
      sigma2_n = pow(10,-esno_dB/10);
      //sigma2_n = pow(10,-esno_dB/10)+2*(1-BessJ0(twopi*BfT/4*r.dim2) );printf("\nmodified sigma_n^2 in msdsd_od_subset\n");
      generate_Phi_hh( Phi_hh, BfT, r.dim2 );

      for( j = 0; j < Phi_hh.row; j++ )
	Phi_hh.val[ j ][ j ] += sigma2_n;
      
      eye( U.val, U.row );
      gaussj( Phi_hhInv.val, U.val, Phi_hh.val, U.val, Phi_hh.row, Phi_hh.col, U.row, U.col );
      
      chol_dcmp( U.val, Phi_hhInv.val, Phi_hhInv.row );
      
      prevEsno_dB = esno_dB;
    }
  printf("\nNTick=%d\n",NTick);
  for( i = 0; i < blocksPerRun; i++ )
    {
      //dispI(i,"blockindex");
      for( j=0; j<N; j++ )
	copyCArray( rPart.val[j], r.val[i*(NTick-1)+j], r.dim2,r.dim3 );
      //for( j=0; j<N; j++ )
      //	copyCArray( rPart.val[j], r.val[i+j], r.dim2,r.dim3 );
      
      flops += msdsd_od( dataHatPart, rPart, U, M );
      
      for( decPos=(N-NTick)/2; decPos<(N+NTick)/2; decPos++ )
      	dataHat.val[i*(NTick-1)+decPos] = dataHatPart.val[decPos];
      //	dataHat.val[i+decPos] = dataHatPart.val[decPos];
    }
  return flops;
}



void mexFunction( int nlhs, mxArray *plhs[],
                  int nrhs, const mxArray *prhs[])
