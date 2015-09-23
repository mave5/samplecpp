// AnswerDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Tofel.h"
#include "AnswerDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAnswerDlg dialog


CAnswerDlg::CAnswerDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAnswerDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAnswerDlg)
	m_sQu1 = _T("");
	m_sQu2 = _T("");
	m_sQu3 = _T("");
	m_sQu4 = _T("");
	m_sQu5 = _T("");
	m_sQu6 = _T("");
	m_sQu7 = _T("");
	m_sQu8 = _T("");
	m_sQu9 = _T("");
	m_sQu10 = _T("");
	m_sQu11 = _T("");
	m_sQu13 = _T("");
	m_sQu14 = _T("");
	m_sQu15 = _T("");
	m_sQu16 = _T("");
	m_sQu17 = _T("");
	m_sQu18 = _T("");
	m_sQu19 = _T("");
	m_sQu20 = _T("");
	m_sQu12 = _T("");
	//}}AFX_DATA_INIT
}


void CAnswerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAnswerDlg)
	DDX_CBString(pDX, IDC_QU1, m_sQu1);
	DDX_CBString(pDX, IDC_QU2, m_sQu2);
	DDX_CBString(pDX, IDC_QU3, m_sQu3);
	DDX_CBString(pDX, IDC_QU4, m_sQu4);
	DDX_CBString(pDX, IDC_QU5, m_sQu5);
	DDX_CBString(pDX, IDC_QU6, m_sQu6);
	DDX_CBString(pDX, IDC_QU7, m_sQu7);
	DDX_CBString(pDX, IDC_QU8, m_sQu8);
	DDX_CBString(pDX, IDC_QU9, m_sQu9);
	DDX_CBString(pDX, IDC_QU10, m_sQu10);
	DDX_CBString(pDX, IDC_QU11, m_sQu11);
	DDX_CBString(pDX, IDC_QU13, m_sQu13);
	DDX_CBString(pDX, IDC_QU14, m_sQu14);
	DDX_CBString(pDX, IDC_QU15, m_sQu15);
	DDX_CBString(pDX, IDC_QU16, m_sQu16);
	DDX_CBString(pDX, IDC_QU17, m_sQu17);
	DDX_CBString(pDX, IDC_QU18, m_sQu18);
	DDX_CBString(pDX, IDC_QU19, m_sQu19);
	DDX_CBString(pDX, IDC_QU20, m_sQu20);
	DDX_CBString(pDX, IDC_QU12, m_sQu12);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAnswerDlg, CDialog)
	//{{AFX_MSG_MAP(CAnswerDlg)
	ON_BN_CLICKED(IDC_SAVE, OnSave)
	ON_BN_CLICKED(IDC_EXIT_ANSW, OnExitAnsw)
	ON_BN_CLICKED(IDC_IMPORT, OnImport)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAnswerDlg message handlers


void CAnswerDlg::OnSave() 
{
	// TODO: Add your control notification handler code here
	
		UpdateData(TRUE);
		static char BASED_CODE szFilter[]="Ans Files  (*.ans)|*.ans||";
		CFileDialog m_IdFile(FALSE,".ans",m_sFile2,
		OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,szFilter);
		if(m_IdFile.DoModal()==IDOK)
		{
			
		Set_Ans_Reg();
		m_sFile2=m_IdFile.GetPathName();
		HANDLE hFile;
		hFile=CreateFile( m_sFile2,
                     GENERIC_READ | GENERIC_WRITE,
                     0,    // comm devices must be opened w/exclusive-access
                     NULL, // no security attributes
                     CREATE_ALWAYS, // comm devices must use OPEN_EXISTING
                     0,    // not overlapped I/O
                     NULL  // hTemplate must be NULL for comm devices
                     ); 
		WriteFile( hFile, &Answer,20, &l_w,NULL );	
		CloseHandle(hFile);
		}
}


void CAnswerDlg::OnExitAnsw() 
{
	// TODO: Add your control notification handler code here
	OnOK();	
}

void CAnswerDlg::OnImport() 
{
	// TODO: Add your control notification handler code here
	
}

void CAnswerDlg::Set_Ans_Reg()
{

			if(m_sQu1=="")Answer[0]=100;
			if(m_sQu1=="A")Answer[0]=101;
			if(m_sQu1=="B")Answer[0]=102;
			if(m_sQu1=="C")Answer[0]=103;
			if(m_sQu1=="D")Answer[0]=104;


			if(m_sQu2=="")Answer[1]=100;
			if(m_sQu2=="A")Answer[1]=101;
			if(m_sQu2=="B")Answer[1]=102;
			if(m_sQu2=="C")Answer[1]=103;
			if(m_sQu2=="D")Answer[1]=104;

			if(m_sQu3=="")Answer[2]=100;
			if(m_sQu3=="A")Answer[2]=101;
			if(m_sQu3=="B")Answer[2]=102;
			if(m_sQu3=="C")Answer[2]=103;
			if(m_sQu3=="D")Answer[2]=104;

			if(m_sQu4=="")Answer[3]=100;
			if(m_sQu4=="A")Answer[3]=101;
			if(m_sQu4=="B")Answer[3]=102;
			if(m_sQu4="C")Answer[3]=103;
			if(m_sQu4=="D")Answer[3]=104;

			if(m_sQu5=="")Answer[4]=100;
			if(m_sQu5=="A")Answer[4]=101;
			if(m_sQu5=="B")Answer[4]=102;
			if(m_sQu5=="C")Answer[4]=103;
			if(m_sQu5=="D")Answer[4]=104;

			if(m_sQu6=="")Answer[5]=100;
			if(m_sQu6=="A")Answer[5]=101;
			if(m_sQu6=="B")Answer[5]=102;
			if(m_sQu6=="C")Answer[5]=103;
			if(m_sQu6=="D")Answer[5]=104;

			if(m_sQu7=="")Answer[6]=100;
			if(m_sQu7=="A")Answer[6]=101;
			if(m_sQu7=="B")Answer[6]=102;
			if(m_sQu7=="C")Answer[6]=103;
			if(m_sQu7=="D")Answer[6]=104;

			if(m_sQu8=="")Answer[7]=100;
			if(m_sQu8=="A")Answer[7]=101;
			if(m_sQu8=="B")Answer[7]=102;
			if(m_sQu8=="C")Answer[7]=103;
			if(m_sQu8=="D")Answer[7]=104;

			if(m_sQu9=="")Answer[8]=100;
			if(m_sQu9=="A")Answer[8]=101;
			if(m_sQu9=="B")Answer[8]=102;
			if(m_sQu9=="C")Answer[8]=103;
			if(m_sQu9=="D")Answer[8]=104;

			if(m_sQu10=="")Answer[9]=100;
			if(m_sQu10=="A")Answer[9]=101;
			if(m_sQu10=="B")Answer[9]=102;
			if(m_sQu10=="C")Answer[9]=103;
			if(m_sQu10=="D")Answer[9]=104;

			if(m_sQu11=="")Answer[10]=100;
			if(m_sQu11=="A")Answer[10]=101;
			if(m_sQu11=="B")Answer[10]=102;
			if(m_sQu11=="C")Answer[10]=103;
			if(m_sQu11=="D")Answer[10]=104;

			if(m_sQu12=="")Answer[11]=100;
			if(m_sQu12=="A")Answer[11]=101;
			if(m_sQu12=="B")Answer[11]=102;
			if(m_sQu12=="C")Answer[11]=103;
			if(m_sQu12=="D")Answer[11]=104;

			if(m_sQu13=="")Answer[12]=100;
			if(m_sQu13=="A")Answer[12]=101;
			if(m_sQu13=="B")Answer[12]=102;
			if(m_sQu13=="C")Answer[12]=103;
			if(m_sQu13=="D")Answer[12]=104;

			if(m_sQu14=="")Answer[13]=100;
			if(m_sQu14=="A")Answer[13]=101;
			if(m_sQu14=="B")Answer[13]=102;
			if(m_sQu14=="C")Answer[13]=103;
			if(m_sQu14=="D")Answer[13]=104;

			if(m_sQu15=="")Answer[14]=100;
			if(m_sQu15=="A")Answer[14]=101;
			if(m_sQu15=="B")Answer[14]=102;
			if(m_sQu15=="C")Answer[14]=103;
			if(m_sQu15=="D")Answer[14]=104;

			if(m_sQu16=="")Answer[15]=100;
			if(m_sQu16=="A")Answer[15]=101;
			if(m_sQu16=="B")Answer[15]=102;
			if(m_sQu16=="C")Answer[15]=103;
			if(m_sQu16=="D")Answer[15]=104;

			if(m_sQu17=="")Answer[16]=100;
			if(m_sQu17=="A")Answer[16]=101;
			if(m_sQu17=="B")Answer[16]=102;
			if(m_sQu17=="C")Answer[16]=103;
			if(m_sQu17=="D")Answer[16]=104;

			if(m_sQu18=="")Answer[17]=100;
			if(m_sQu18=="A")Answer[17]=101;
			if(m_sQu18=="B")Answer[17]=102;
			if(m_sQu18=="C")Answer[17]=103;
			if(m_sQu18=="D")Answer[17]=104;

			if(m_sQu19=="")Answer[18]=100;
			if(m_sQu19=="A")Answer[18]=101;
			if(m_sQu19=="B")Answer[18]=102;
			if(m_sQu19=="C")Answer[18]=103;
			if(m_sQu19=="D")Answer[18]=104;


			if(m_sQu20=="")Answer[19]=100;
			if(m_sQu20=="A")Answer[19]=101;
			if(m_sQu20=="B")Answer[19]=102;
			if(m_sQu20=="C")Answer[19]=103;
			if(m_sQu20=="D")Answer[19]=104;



}
