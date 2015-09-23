#if !defined(AFX_GHANGEPASSDLG_H__51F0FDA5_3F84_11D7_9FC8_8B2277AF4B32__INCLUDED_)
#define AFX_GHANGEPASSDLG_H__51F0FDA5_3F84_11D7_9FC8_8B2277AF4B32__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// GhangePassDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CGhangePassDlg dialog

class CGhangePassDlg : public CDialog
{
// Construction
public:
	CGhangePassDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CGhangePassDlg)
	enum { IDD = IDD_GHANGE_PASS_DIALOG };
	CString	m_sOldPass;
	CString	m_sNewPass;
	CString	m_sConfirmPass;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGhangePassDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CGhangePassDlg)
	afx_msg void OnOkghange();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GHANGEPASSDLG_H__51F0FDA5_3F84_11D7_9FC8_8B2277AF4B32__INCLUDED_)
