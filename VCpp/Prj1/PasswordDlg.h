#if !defined(AFX_PASSWORDDLG_H__51F0FDA3_3F84_11D7_9FC8_8B2277AF4B32__INCLUDED_)
#define AFX_PASSWORDDLG_H__51F0FDA3_3F84_11D7_9FC8_8B2277AF4B32__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PasswordDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPasswordDlg dialog

class CPasswordDlg : public CDialog
{
// Construction
public:
	CPasswordDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPasswordDlg)
	enum { IDD = IDD_PASSWORD_DIALOG };
	CString	m_sPassword;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPasswordDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPasswordDlg)
	afx_msg void OnOkpass();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PASSWORDDLG_H__51F0FDA3_3F84_11D7_9FC8_8B2277AF4B32__INCLUDED_)
