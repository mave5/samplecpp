#if !defined(AFX_ANSWERDLG_H__8DEA86F0_CFD9_4BC2_BF63_4C4DBE399BE1__INCLUDED_)
#define AFX_ANSWERDLG_H__8DEA86F0_CFD9_4BC2_BF63_4C4DBE399BE1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AnswerDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAnswerDlg dialog

class CAnswerDlg : public CDialog
{
// Construction
public:
	void Set_Ans_Reg();
	DWORD l_w;
	unsigned char Answer[50];
	CString m_sFile2;
	CAnswerDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAnswerDlg)
	enum { IDD = IDD_ANSWER };
	CString	m_sQu1;
	CString	m_sQu2;
	CString	m_sQu3;
	CString	m_sQu4;
	CString	m_sQu5;
	CString	m_sQu6;
	CString	m_sQu7;
	CString	m_sQu8;
	CString	m_sQu9;
	CString	m_sQu10;
	CString	m_sQu11;
	CString	m_sQu13;
	CString	m_sQu14;
	CString	m_sQu15;
	CString	m_sQu16;
	CString	m_sQu17;
	CString	m_sQu18;
	CString	m_sQu19;
	CString	m_sQu20;
	CString	m_sQu12;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAnswerDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAnswerDlg)
	afx_msg void OnSave();
	afx_msg void OnExitAnsw();
	afx_msg void OnImport();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ANSWERDLG_H__8DEA86F0_CFD9_4BC2_BF63_4C4DBE399BE1__INCLUDED_)
