// PasswordDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Lab_Cont.h"
#include "PasswordDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPasswordDlg dialog


CPasswordDlg::CPasswordDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPasswordDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPasswordDlg)
	m_sPassword = _T("");
	//}}AFX_DATA_INIT
}


void CPasswordDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPasswordDlg)
	DDX_Text(pDX, IDC_PASSWORD, m_sPassword);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPasswordDlg, CDialog)
	//{{AFX_MSG_MAP(CPasswordDlg)
	ON_BN_CLICKED(IDOKPASS, OnOkpass)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPasswordDlg message handlers

void CPasswordDlg::OnOkpass() 
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
	else MessageBox("Can't Find Password","Error!",MB_OK);	
	CString s2=(CString)s1;
	if(m_sPassword==s2)
		OnOK();
	else
		MessageBox("sorry password is invalid","Password Invalid",MB_OK);


}
