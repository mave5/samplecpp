#if !defined(AFX_WAIT1DLG_H__E359AD26_B099_42A5_A20F_12CD57D93047__INCLUDED_)
#define AFX_WAIT1DLG_H__E359AD26_B099_42A5_A20F_12CD57D93047__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Wait1Dlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CWait1Dlg dialog

class CWait1Dlg : public CDialog
{
// Construction
public:
	CWait1Dlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CWait1Dlg)
	enum { IDD = IDD_WAIT1 };
	CString	m_cE2;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWait1Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CWait1Dlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WAIT1DLG_H__E359AD26_B099_42A5_A20F_12CD57D93047__INCLUDED_)
