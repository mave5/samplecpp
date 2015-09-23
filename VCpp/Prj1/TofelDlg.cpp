// TofelDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Lab_Cont.h"
#include "Lab_ContDlg.h"
#include "Wait1Dlg.h"
#include "TofelDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTofelDlg dialog


CTofelDlg::CTofelDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTofelDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTofelDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CTofelDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTofelDlg)
	DDX_Control(pDX, IDC_MSFLEXTOFEL, m_cFlexTofel);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTofelDlg, CDialog)
	//{{AFX_MSG_MAP(CTofelDlg)
	ON_BN_CLICKED(IDC_RECENT_RESULT, OnRecentResult)
	ON_BN_CLICKED(IDC_OLD_RESULTS, OnOldResults)
	ON_BN_CLICKED(IDC_SAVE_RESULTS, OnSaveResults)
	ON_BN_CLICKED(IDC_EXIT, OnExit)
	ON_BN_CLICKED(IDC_LOAD_ANSWER, OnLoadAnswer)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_EXIT_RESULT, OnExitResult)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTofelDlg message handlers

void CTofelDlg::OnRecentResult() 
{
	// TODO: Add your control notification handler code here
	CLab_ContDlg *pWlab=(CLab_ContDlg *)GetParent();
	Set_Flex_Tofel(pWlab->St_Answer);
}

void CTofelDlg::OnOldResults() 
{
	// TODO: Add your control notification handler code here
	CString m_sFile1;
	static char BASED_CODE szFilter[]="Ans Files  (*.res)|*.res||";
	CFileDialog m_IdFile(TRUE,".res",m_sFile1,
	OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,szFilter);
	if(m_IdFile.DoModal()==IDOK)
	{
		m_sFile1=m_IdFile.GetPathName();
			CFile file;
			file.Open(m_sFile1,CFile::modeRead);
			if(file)
			{
				for(int istu=0;istu<15;istu++)for(int iqu=0;iqu<31;iqu++)file.Read(&Old_Answer[istu][iqu],1);
				file.Close();
				MessageBox("Answers Load from file","Load Answers",MB_OK);
				//save answer in zero sotoon of st_answer
				for(int iqu=1;iqu<31;iqu++)	Answer[iqu]=Old_Answer[0][iqu];
				for( istu=1;istu<15;istu++)corect[istu]=Old_Answer[istu][0];	
				Set_Flex_Tofel(Old_Answer);
			}
			else MessageBox("Can't Load from file","Load Faild",MB_OK); 
	}

}

void CTofelDlg::OnSaveResults() 
{
	// TODO: Add your control notification handler code here
	//get pointer to lab control dialog
	CLab_ContDlg *pWlab=(CLab_ContDlg *)GetParent();
	//save answer in zero sotoon of st_answer
	for(int iqu=1;iqu<31;iqu++)	pWlab->St_Answer[0][iqu]=Answer[iqu];
	for(int istu=1;istu<15;istu++)pWlab->St_Answer[istu][0]=corect[istu];	
	CString m_sFile1;
	static char BASED_CODE szFilter[]="Ans Files  (*.res)|*.res||";
	CFileDialog m_IdFile(FALSE,".res",m_sFile1,
	OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,szFilter);
	if(m_IdFile.DoModal()==IDOK)
	{
		m_sFile1=m_IdFile.GetPathName();
			CFile file;
			file.Open(m_sFile1,CFile::modeCreate|CFile::modeWrite);
			if(file){
					for(int istu=0;istu<15;istu++)for(int iqu=0;iqu<31;iqu++)file.Write(&(pWlab->St_Answer[istu][iqu]),1);
					file.Close();
					MessageBox("Data save on file","Save Data",MB_OK);
					}
			else MessageBox("Can't Save Data Please Try Again","Error",MB_OK);				
	}	
}

void CTofelDlg::Set_Flex_Tofel(char answer_tofel[20][100])
{
	//hide flex grid 
	GetDlgItem(IDC_MSFLEXTOFEL)->ShowWindow(FALSE);
	//zero number of corect array 
	for(int ii=0;ii<100;ii++)corect[ii]=0;	
	CString ss;

	//set  answers in flex grid	
	for(int satr=1;satr<31;satr++)
	{
		m_cFlexTofel.SetRow(satr);
		m_cFlexTofel.SetCol(1);
		ss.Format("%c",Answer[satr]);
		m_cFlexTofel.SetText(ss);
	}

	//set answer of students in flex grid
	for(int sotoon=2;sotoon<16;sotoon++)
	{
		for(int satr=1;satr<31;satr++)
		{
			
			if((answer_tofel[0][satr])&&(answer_tofel[sotoon-1][satr]==Answer[satr]))corect[sotoon-1]++;
			ss.Format("%c",answer_tofel[sotoon-1][satr]);
			m_cFlexTofel.SetRow(satr);
			m_cFlexTofel.SetCol(sotoon);
			if((answer_tofel[0][satr])&&(answer_tofel[sotoon-1][satr]!=Answer[satr]))m_cFlexTofel.SetCellForeColor(RGB(255,0,0));
			else m_cFlexTofel.SetCellForeColor(RGB(0,0,0));	
			m_cFlexTofel.SetText(ss);
			m_cFlexTofel.SetRow(31);
			m_cFlexTofel.SetCol(sotoon);
			ss.Format("%d",corect[sotoon-1]);
			m_cFlexTofel.SetText(ss);
		}
	}
	
	GetDlgItem(IDC_MSFLEXTOFEL)->ShowWindow(TRUE);
}

void CTofelDlg::OnExit() 
{
	// TODO: Add your control notification handler code here
	OnOK();
}

BOOL CTofelDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	//set inith flex grid
	CString ss;
	for(int sotoon=2;sotoon<16;sotoon++)
	{
		m_cFlexTofel.SetRow(0);
		m_cFlexTofel.SetCol(sotoon);
		ss.Format("Student %d",sotoon-1);		
		m_cFlexTofel.SetText(ss);
	}
	m_cFlexTofel.SetRow(0);
	m_cFlexTofel.SetCol(1);
	m_cFlexTofel.SetText("Corect Ans");
	//set answer zero
	for(int ii=0;ii<100;ii++)Answer[ii]=0;
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CTofelDlg::OnLoadAnswer() 
{
	// TODO: Add your control notification handler code here
	CString m_sFile1;
	static char BASED_CODE szFilter[]="Ans Files  (*.ans)|*.ans||";
	CFileDialog m_IdFile(TRUE,".ans",m_sFile1,
	OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,szFilter);
	if(m_IdFile.DoModal()==IDOK)
	{
		m_sFile1=m_IdFile.GetPathName();
			CFile file;
			file.Open(m_sFile1,CFile::modeRead);
			if(file)
			{
				for(int ff=1;ff<31;ff++)file.Read(&Answer[ff],1);
				file.Close();
				MessageBox("Answers Load from file","Load Answers",MB_OK);
				CString ss;
				for(int satr=1;satr<31;satr++)
				{
					GetDlgItem(IDC_MSFLEXTOFEL)->ShowWindow(FALSE);
					m_cFlexTofel.SetRow(satr);
					m_cFlexTofel.SetCol(1);
					ss.Format("%c",Answer[satr]);
					m_cFlexTofel.SetText(ss);
					GetDlgItem(IDC_MSFLEXTOFEL)->ShowWindow(TRUE);
				}
			}
			else MessageBox("Can't Load from file","Load Faild",MB_OK); 
	}
}

void CTofelDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	
	CDialog::OnTimer(nIDEvent);
}

void CTofelDlg::OnExitResult() 
{
	// TODO: Add your control notification handler code here
	int iResults;
	iResults=MessageBox("Are you sure to exit","Exit",MB_OKCANCEL|MB_ICONQUESTION);
	switch (iResults)
	{
	case IDOK:
			OnOK();
	break;

	case IDCANCEL:
	break;
	}

}
