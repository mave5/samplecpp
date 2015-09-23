// CyberScreenDlg.h : header file
//

#if !defined(AFX_CYBERSCREENDLG_H__8136DB87_2F89_11D7_9FC8_CC75D478C430__INCLUDED_)
#define AFX_CYBERSCREENDLG_H__8136DB87_2F89_11D7_9FC8_CC75D478C430__INCLUDED_

#include "..\STATUS AREA ICON CLASS\StatusAreaIconObj.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCyberScreenDlg dialog

class CCyberScreenDlg : public CDialog
{
// Construction
public:

//	BOOL onetwo;
	BOOL restore;
	CStatusAreaIconObj m_SAIObj;
	CString now_open_port;
	BOOL Set_Com_Port(CString com_port);
	CCyberScreenDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCyberScreenDlg)
	enum { IDD = IDD_CYBERSCREEN_DIALOG };
	CSpinButtonCtrl	m_csY;
	CSpinButtonCtrl	m_csX;
	CString	m_sComSel;
	UINT	m_uiX;
	UINT	m_uiY;
	int		m_nDropListIndex;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCyberScreenDlg)
	public:
	virtual int DoModal();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCyberScreenDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnExit();
	afx_msg void OnOkRead();
	afx_msg void OnHelpAbout();
	afx_msg void OnMenuExit();
	afx_msg void OnMenuSetting();
	afx_msg void OnDisDown();
	afx_msg void OnSelchangeDropList();
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CYBERSCREENDLG_H__8136DB87_2F89_11D7_9FC8_CC75D478C430__INCLUDED_)
