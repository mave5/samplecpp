// CallSettingDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Lab_Cont.h"
#include "Lab_ContDlg.h"
#include "CallSettingDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCallSettingDlg dialog


CCallSettingDlg::CCallSettingDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCallSettingDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCallSettingDlg)
	m_bEnableCall = FALSE;
	m_bDisableTape = FALSE;
	//}}AFX_DATA_INIT
}


void CCallSettingDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCallSettingDlg)
	DDX_Check(pDX, IDC_ENABLECALL, m_bEnableCall);
	DDX_Check(pDX, IDC_DISABLE_TAPE, m_bDisableTape);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCallSettingDlg, CDialog)
	//{{AFX_MSG_MAP(CCallSettingDlg)
	ON_BN_CLICKED(IDC_ENABLECALL, OnEnablecall)
	ON_BN_CLICKED(IDC_DISABLE_TAPE, OnDisableTape)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCallSettingDlg message handlers

void CCallSettingDlg::OnEnablecall() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	CLab_ContDlg *pWlab=(CLab_ContDlg *)GetParent();
	if(m_bEnableCall==TRUE)
	{
							pWlab->m_cCallEnable.ShowWindow(TRUE);	
							pWlab->CallEnable=TRUE;
							//function
							pWlab->Call_Enable(TRUE);
							
	}
	else
	{
			pWlab->m_cCallEnable.ShowWindow(FALSE);	
			pWlab->CallEnable=FALSE;
			//function
			pWlab->Call_Enable(FALSE);
	}
}

void CCallSettingDlg::OnDisableTape() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	CLab_ContDlg *pWlab=(CLab_ContDlg *)GetParent();
	if(m_bDisableTape==TRUE){pWlab->Disable_Tape(TRUE);pWlab->bTapeDisable=TRUE;}
	else	{pWlab->Disable_Tape(FALSE);pWlab->bTapeDisable=FALSE;}
	
	
}
