#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <dos.h>
#include <iostream.h>

#define ERate   100
#define NSim	10000
#define M	15      // path memory size

#define k	1	// number of input information bits
#define L	3	// constraint length
#define D	2	// range of output data = 2**k
#define S	4	// number of states = 2**k(L-1)
#define n	2	// number of output coded bits

struct BRANCH{
	int OriginState;
	int Input[k];
	int Output[n];
	};
struct STATE{
	BRANCH Branch[D];
	};
struct TRELLIS{
	STATE State[S];
	};
TRELLIS Trellis;

unsigned int ShiftReg[L*k]={0,0,0};
unsigned int cost[S]={0,0,0,0}, newcost[S]={0,0,0,0};
unsigned int path_history[S][M], code[n];
unsigned int data, err, dist, metric, minmetric, minbr, mincost, dstate, ddata;
unsigned long int b;
unsigned int i_data[M], i_data0, Not_Detected_Errors=0;

void Trellis_Paths(){
	// This assignments routine may be automated later, with respect to
	// input parameters k,n and L. Here we have: k=1, n=2 and L=3.

	Trellis.State[0].Branch[0].OriginState = 0;
	Trellis.State[0].Branch[0].Input[0] = 0;
	Trellis.State[0].Branch[0].Output[0]=0;
	Trellis.State[0].Branch[0].Output[1]=0;

	Trellis.State[0].Branch[1].OriginState = 1;
	Trellis.State[0].Branch[1].Input[0] = 0;
	Trellis.State[0].Branch[1].Output[0]=1;
	Trellis.State[0].Branch[1].Output[1]=1;

	Trellis.State[1].Branch[0].OriginState = 2;
	Trellis.State[1].Branch[0].Input[0] = 0;
	Trellis.State[1].Branch[0].Output[0]=0;
	Trellis.State[1].Branch[0].Output[1]=1;

	Trellis.State[1].Branch[1].OriginState = 3;
	Trellis.State[1].Branch[1].Input[0] = 0;
	Trellis.State[1]

	.Branch[1].Output[0]=1;
	Trellis.State[1].Branch[1].Output[1]=0;

	Trellis.State[2].Branch[0].OriginState = 0;
	Trellis.State[2].Branch[0].Input[0] = 1;
	Trellis.State[2].Branch[0].Output[0]=1;
	Trellis.State[2].Branch[0].Output[1]=1;

	Trellis.State[2].Branch[1].OriginState = 1;
	Trellis.State[2].Branch[1].Input[0] = 1;
	Trellis.State[2].Branch[1].Output[0]=0;
	Trellis.State[2].Branch[1].Output[1]=0;

	Trellis.State[3].Branch[0].OriginState = 2;
	Trellis.State[3].Branch[0].Input[0] = 1;
	Trellis.State[3].Branch[0].Output[0]=1;
	Trellis.State[3].Branch[0].Output[1]=0;

	Trellis.State[3].Branch[1].OriginState = 3;
	Trellis.State[3].Branch[1].Input[0] = 1;
	Trellis.State[3].Branch[1].Output[0]=0;
	Trellis.State[3].Branch[1].Output[1]=1;
	}

void Back_Tracking(){
	mincost=0;
	for(int mc=1;mc<S;mc++)
		if(cost[mc] < cost[mincost])
			mincost = mc;

	dstate = path_history[mincost][M-1];
	for(int mbt=M-2;mbt>=0;mbt--){
		dstate = path_history[dstate][mbt];
		}
	ddata=Trellis.State[dstate].Branch[0].Input[0]; // or MSB

	for(int md=0;md<M-1;md++)
		for(int sd=0;sd<S;sd++)
			path_history[sd][md]=path_history[sd][md+1];
//	printf("   %d",ddata);
	}

void Data_Code_Error(){
	data=random(D);
	if(b>=M) i_data[M-1]=data;
	else     i_data[b]=data;

	for(int i=2;i>0;i--)
		ShiftReg[i]=ShiftReg[i-1];
	ShiftReg[0]=data;
//	printf("\n %u",b);
//	printf("\t%d",data);

	code[0]=(ShiftReg[0] ^ ShiftReg[2]) & 1;
	code[1]=(ShiftReg[0] ^ ShiftReg[1] ^ ShiftReg[2]) & 1;

	err=random(D*ERate);
	if(err==0){ code[0] = (~code[0])&1; printf("  <");}
	if(err==1){ code[1] = (~code[1])&1; printf("  >");}
//	printf("\t%d%d",code[0],code[1]);
	}

void Path(){
	for(int s=0;s<S;s++){
		minmetric = 60000;
		for(int br=0;br<D;br++){
			//______________________ distance _____________________________
			dist=0;
			for(int op=0;op<n;op++)
				if(Trellis.State[s].Branch[br].Output[op]!=code[op])
					dist++;
			//_____________________________________________________________
			metric=cost[Trellis.State[s].Branch[br].OriginState]+dist;
			if(metric<minmetric){
				minmetric=metric;
				minbr=br;
				}
			}
		if(b>=M) path_history[s][M-1]=Trellis.State[s].Branch[minbr].OriginState;
		else     path_history[s][b]=Trellis.State[s].Branch[minbr].OriginState;
		newcost[s]=minmetric;
		}
	for(s=0;s<S;s++)
		cost[s]=newcost[s];
	}

int main(){
    clrscr();
    randomize();
    Trellis_Paths();

    for(int j1=0;j1<4;j1++)
    {
	for(int j2=0;j2<4;j2++)
	{
		for(int j3=0;j3<2;j3++)
		       cout <<Trellis.State[j1].Branch[j2].Output[j3];
		cout << "\t";
	}
		cout << "\n";
    }



    for (b=0;b<M;b++){
	Data_Code_Error();
	Path();
	}
    for (b=M;b<NSim;b++){
	Back_Tracking();
	if (i_data0 != ddata)
		Not_Detected_Errors++;
	i_data0=i_data[0];
	for(int ish=0;ish<M-1;ish++)
		i_data[ish]=i_data[ish+1];

	Data_Code_Error();
	Path();
	}
    //printf("\n\n Not Detected Errors: %u",Not_Detected_Errors);
    getch();
    return 0;
    }