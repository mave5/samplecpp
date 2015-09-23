// Lab_ContDlg.h : header file
//
//{{AFX_INCLUDES()
#include "activemovie3.h"
#include "msflexgrid.h"
//}}AFX_INCLUDES

#if !defined(AFX_LAB_CONTDLG_H__CD6EF747_3F64_11D7_9FC8_8C6C10779C33__INCLUDED_)
#define AFX_LAB_CONTDLG_H__CD6EF747_3F64_11D7_9FC8_8C6C10779C33__INCLUDED_

#include "PasswordDlg.h"	// Added by ClassView
#include "GhangePassDlg.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CLab_ContDlg dialog

class CLab_ContDlg : public CBitmapDialog
{
// Construction
public:
	void Disable_Tape(BOOL btape);
	HANDLE hCom;
	void Call_Enable(BOOL bCallEnable);
	BOOL Call_On_Line;
	BOOL CallEnable;
	BOOL bTapeDisable;
	BOOL Set_Off_Bitmap(unsigned char num_st);
	BOOL Set_ON_Bitmap(unsigned char num_st);
	BOOL InOutLine(unsigned char num_st);
//	unsigned char Num_St;
	CGhangePassDlg m_cGhangePassDlg;
	CPasswordDlg m_cPasswordDlg;
	int i;
	unsigned char Mon_St[70];
	unsigned char C_St[70];
	unsigned char T_St[70];
	unsigned char Conf1_St[70];
	unsigned char Conf2_St[70];
	unsigned char Pc_St[70];
	unsigned char Line2_St[70];
	unsigned char Line1_St[70];
	UINT m_iLine;
	unsigned char send[10];
	void Set_Inith_Bitmap();
	CLab_ContDlg(CWnd* pParent = NULL);	// standard constructor
	//answer tofel
		char St_Answer[70][100];//70 number of student and 100 number of qustion

// Dialog Data
	//{{AFX_DATA(CLab_ContDlg)
	enum { IDD = IDD_LAB_CONT_DIALOG };
	CButton	m_cTofel;
	CSpinButtonCtrl	m_cSMaxT1;
	CButton	m_cAll;
	CButton	m_cMonitor;
	CButton	m_cCall;
	CButton	m_cOpenFile;
	CStatic	m_cCallEnable;
	CButton	m_cCallOn;
	CButton	m_cPc;
	CButton	m_cLine2;
	CButton	m_cLine1;
	CButton	m_cC2;
	CButton	m_cC1;
	CButton	m_cTeacher;
	CButton	m_cTPc;
	CButton	m_cTL2;
	CButton	m_cTL1;
	CButton	m_cTC2;
	CButton	m_cTC1;
	CButton	m_cSt9;
	CButton	m_cSt8;
	CButton	m_cSt7;
	CButton	m_cSt6;
	CButton	m_cSt5;
	CButton	m_cSt4;
	CButton	m_cSt3;
	CButton	m_cSt2;
	CButton	m_cSt14;
	CButton	m_cSt13;
	CButton	m_cSt12;
	CButton	m_cSt11;
	CButton	m_cSt10;
	CButton	m_cSt1;
	CActiveMovie3	m_cMovie;
	CMSFlexGrid	m_cFlex1;
	CString	m_sT1;
	CString	m_sQ1;
	CString	m_sMaxT1;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLab_ContDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	char* openfile(char filter[], char defuext[], char title[]);
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CLab_ContDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnExit();
	afx_msg void OnLine1();
	afx_msg void OnLine2();
	afx_msg void OnPc();
	afx_msg void OnC1();
	afx_msg void OnC2();
	afx_msg void OnTeacher();
	afx_msg void OnSt1();
	afx_msg void OnGhabgePass();
	afx_msg void OnSt2();
	afx_msg void OnSt3();
	afx_msg void OnSt4();
	afx_msg void OnSt5();
	afx_msg void OnSt6();
	afx_msg void OnSt7();
	afx_msg void OnSt8();
	afx_msg void OnSt9();
	afx_msg void OnSt10();
	afx_msg void OnSt11();
	afx_msg void OnSt12();
	afx_msg void OnSt13();
	afx_msg void OnSt14();
	afx_msg void OnOpenFile();
	afx_msg void OnTL1();
	afx_msg void OnTL2();
	afx_msg void OnTPc();
	afx_msg void OnTC1();
	afx_msg void OnTC2();
	afx_msg void OnSettingGhangepassword();
	afx_msg void OnSettingExit();
	afx_msg void OnHelpAbout();
	afx_msg void OnSettingPortsetting();
	afx_msg void OnCallOn();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnCall();
	afx_msg void OnMonitor();
	afx_msg void OnAll();
	afx_msg void OnTofel();
	afx_msg void OnStartEx();
	afx_msg void OnCapture();
	afx_msg void OnTofelShowresults();
	afx_msg void OnTofelInter();
	afx_msg void OnReset();
	afx_msg void OnRunWinamp();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	BOOL Set_CallSt_Bitmap(unsigned char  num_st);
	BOOL bteacher_on[10];
	DWORD iBytesRead;
	void Delay(int delay);
	int iTimer_Tofel;
	BOOL bWriteRC;
	BOOL bReadRC;
	DWORD l_w;
	BOOL Set_Com_Port(CString com_port);
	//HANDLE hCom;
	BOOL tofel_show;
	void Set_Flex_Grid(char answer_tofel[20][100]);
	int Timer_Count;
	int	 iNum_Qu;
	unsigned char Rec[50];
	unsigned char  cCall_St[70];
	BOOL cCall_St_On[70];
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LAB_CONTDLG_H__CD6EF747_3F64_11D7_9FC8_8C6C10779C33__INCLUDED_)
