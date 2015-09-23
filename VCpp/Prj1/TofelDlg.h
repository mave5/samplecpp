//{{AFX_INCLUDES()
#include "msflexgrid.h"
#include "Wait1Dlg.h"	// Added by ClassView
//}}AFX_INCLUDES
#if !defined(AFX_TOFELDLG_H__81EEC913_5A27_49CB_9775_9ED40AD9C56D__INCLUDED_)
#define AFX_TOFELDLG_H__81EEC913_5A27_49CB_9775_9ED40AD9C56D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TofelDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTofelDlg dialog

class CTofelDlg : public CDialog
{
// Construction
public:
	CTofelDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CTofelDlg)
	enum { IDD = IDD_TOFEL };
	CMSFlexGrid	m_cFlexTofel;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTofelDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CTofelDlg)
	afx_msg void OnRecentResult();
	afx_msg void OnOldResults();
	afx_msg void OnSaveResults();
	afx_msg void OnExit();
	virtual BOOL OnInitDialog();
	afx_msg void OnLoadAnswer();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnExitResult();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CWait1Dlg m_cWait1Dlg;
	BOOL wait;
	char Old_Answer[20][100];
	int corect[100];
	char Answer[100];
	void Set_Flex_Tofel(char answer_tofel[20][100]);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TOFELDLG_H__81EEC913_5A27_49CB_9775_9ED40AD9C56D__INCLUDED_)
