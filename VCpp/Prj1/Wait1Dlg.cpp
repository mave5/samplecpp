// Wait1Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "Lab_Cont.h"
#include "Wait1Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWait1Dlg dialog


CWait1Dlg::CWait1Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CWait1Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CWait1Dlg)
	m_cE2 = _T("");
	//}}AFX_DATA_INIT
}


void CWait1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CWait1Dlg)
	DDX_Text(pDX, IDC_EDIT2, m_cE2);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CWait1Dlg, CDialog)
	//{{AFX_MSG_MAP(CWait1Dlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWait1Dlg message handlers

BOOL CWait1Dlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_cE2.Format("aaaaaaaaa");
	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
