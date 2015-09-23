#if !defined(AFX_INTERANSWERDLG_H__E0B367B1_2757_45EE_90E9_42F47830413B__INCLUDED_)
#define AFX_INTERANSWERDLG_H__E0B367B1_2757_45EE_90E9_42F47830413B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// InterAnswerDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CInterAnswerDlg dialog

class CInterAnswerDlg : public CDialog
{
// Construction
public:
	CInterAnswerDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CInterAnswerDlg)
	enum { IDD = IDD_INTER_ANSWER };
	CString	m_sAns1;
	CString	m_sAns10;
	CString	m_sAns11;
	CString	m_sAns12;
	CString	m_sAns13;
	CString	m_sAns14;
	CString	m_sAns15;
	CString	m_sAns16;
	CString	m_sAns17;
	CString	m_sAns18;
	CString	m_sAns19;
	CString	m_sAns2;
	CString	m_sAns20;
	CString	m_sAns21;
	CString	m_sAns22;
	CString	m_sAns23;
	CString	m_sAns24;
	CString	m_sAns25;
	CString	m_sAns26;
	CString	m_sAns28;
	CString	m_sAns29;
	CString	m_sAns3;
	CString	m_sAns30;
	CString	m_sAns4;
	CString	m_sAns5;
	CString	m_sAns6;
	CString	m_sAns7;
	CString	m_sAns8;
	CString	m_sAns9;
	CString	m_sAns27;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CInterAnswerDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CInterAnswerDlg)
	afx_msg void OnSaveAnswer();
	afx_msg void OnOkAnswer();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	char Answer[100];
	BOOL Get_Ans();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_INTERANSWERDLG_H__E0B367B1_2757_45EE_90E9_42F47830413B__INCLUDED_)
