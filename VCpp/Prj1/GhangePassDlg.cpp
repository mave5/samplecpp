// GhangePassDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Lab_Cont.h"
#include "GhangePassDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGhangePassDlg dialog


CGhangePassDlg::CGhangePassDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CGhangePassDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CGhangePassDlg)
	m_sOldPass = _T("");
	m_sNewPass = _T("");
	m_sConfirmPass = _T("");
	//}}AFX_DATA_INIT
}


void CGhangePassDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CGhangePassDlg)
	DDX_Text(pDX, IDC_OLD_PASSWORD, m_sOldPass);
	DDX_Text(pDX, IDC_NEW_PASSWORD, m_sNewPass);
	DDX_Text(pDX, IDC_CONFIRM_PASSWORD, m_sConfirmPass);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CGhangePassDlg, CDialog)
	//{{AFX_MSG_MAP(CGhangePassDlg)
	ON_BN_CLICKED(IDOKGHANGE, OnOkghange)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGhangePassDlg message handlers

void CGhangePassDlg::OnOkghange() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	char s1[50]={0};
	CFile file;
	file.Open("key.pas",CFile::modeRead);
	if(file)
	{
		file.Read(&s1,file.GetLength());
		file.Close();	
	}
	else MessageBox("Can't Ghange Password","Error!",MB_OK);	
	CString s2=(CString)s1;
	if(m_sOldPass==s2)
	{
		if(m_sNewPass==m_sConfirmPass)
		{
			char s3[50]={0};
			strcpy(s3,m_sNewPass);	
			CFile file;
			file.Open("key.pas",CFile::modeCreate|CFile::modeWrite);
			if(file){
					file.Write(&s3,strlen(s3));
					file.Close();
					MessageBox("Password is Ghanged","Password Ghange",MB_OK);
					}

			else MessageBox("Can't Ghange Password","Error",MB_OK);				
		}
		else MessageBox("Confirm Password is not match with New Password","Error",MB_OK);	
	}
	else MessageBox("Old Password is invalid","Error",MB_OK);			
}

