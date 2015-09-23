#if !defined(AFX_CALLSETTINGDLG_H__F33EF8C7_392E_4311_9FFD_48F517B10919__INCLUDED_)
#define AFX_CALLSETTINGDLG_H__F33EF8C7_392E_4311_9FFD_48F517B10919__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CallSettingDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCallSettingDlg dialog

class CCallSettingDlg : public CDialog
{
// Construction
public:
	CCallSettingDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CCallSettingDlg)
	enum { IDD = IDD_CALL_SETTING };
	BOOL	m_bEnableCall;
	BOOL	m_bDisableTape;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCallSettingDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCallSettingDlg)
	afx_msg void OnEnablecall();
	afx_msg void OnDisableTape();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CALLSETTINGDLG_H__F33EF8C7_392E_4311_9FFD_48F517B10919__INCLUDED_)
