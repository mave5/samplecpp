// Lab_ContDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Lab_Cont.h"
#include "CallSettingDlg.h"
#include "TofelDlg.h"
#include "InterAnswerDlg.h"
#include "Lab_ContDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLab_ContDlg dialog

CLab_ContDlg::CLab_ContDlg(CWnd* pParent /*=NULL*/)
	: CBitmapDialog(CLab_ContDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLab_ContDlg)
	m_sT1 = _T("");
	m_sQ1 = _T("");
	m_sMaxT1 = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLab_ContDlg::DoDataExchange(CDataExchange* pDX)
{
	CBitmapDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLab_ContDlg)
	DDX_Control(pDX, IDC_TOFEL, m_cTofel);
	DDX_Control(pDX, IDC_SPIN1, m_cSMaxT1);
	DDX_Control(pDX, IDC_ALL, m_cAll);
	DDX_Control(pDX, IDC_MONITOR, m_cMonitor);
	DDX_Control(pDX, IDC_CALL, m_cCall);
	DDX_Control(pDX, IDC_OPEN_FILE, m_cOpenFile);
	DDX_Control(pDX, IDC_CALL_ENABLE, m_cCallEnable);
	DDX_Control(pDX, IDC_CALL_ON, m_cCallOn);
	DDX_Control(pDX, IDC_PC, m_cPc);
	DDX_Control(pDX, IDC_LINE2, m_cLine2);
	DDX_Control(pDX, IDC_LINE1, m_cLine1);
	DDX_Control(pDX, IDC_C2, m_cC2);
	DDX_Control(pDX, IDC_C1, m_cC1);
	DDX_Control(pDX, IDC_TEACHER, m_cTeacher);
	DDX_Control(pDX, IDC_T_PC, m_cTPc);
	DDX_Control(pDX, IDC_T_L2, m_cTL2);
	DDX_Control(pDX, IDC_T_L1, m_cTL1);
	DDX_Control(pDX, IDC_T_C2, m_cTC2);
	DDX_Control(pDX, IDC_T_C1, m_cTC1);
	DDX_Control(pDX, IDC_ST9, m_cSt9);
	DDX_Control(pDX, IDC_ST8, m_cSt8);
	DDX_Control(pDX, IDC_ST7, m_cSt7);
	DDX_Control(pDX, IDC_ST6, m_cSt6);
	DDX_Control(pDX, IDC_ST5, m_cSt5);
	DDX_Control(pDX, IDC_ST4, m_cSt4);
	DDX_Control(pDX, IDC_ST3, m_cSt3);
	DDX_Control(pDX, IDC_ST2, m_cSt2);
	DDX_Control(pDX, IDC_ST14, m_cSt14);
	DDX_Control(pDX, IDC_ST13, m_cSt13);
	DDX_Control(pDX, IDC_ST12, m_cSt12);
	DDX_Control(pDX, IDC_ST11, m_cSt11);
	DDX_Control(pDX, IDC_ST10, m_cSt10);
	DDX_Control(pDX, IDC_ST1, m_cSt1);
	DDX_Control(pDX, IDC_ACTIVEMOVIECONTROL1, m_cMovie);
	DDX_Control(pDX, IDC_MSFLEXGRID1, m_cFlex1);
	DDX_Text(pDX, IDC_T1, m_sT1);
	DDX_Text(pDX, IDC_Q1, m_sQ1);
	DDX_Text(pDX, IDC_MAX_T1, m_sMaxT1);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CLab_ContDlg, CBitmapDialog)
	//{{AFX_MSG_MAP(CLab_ContDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_EXIT, OnExit)
	ON_BN_CLICKED(IDC_LINE1, OnLine1)
	ON_BN_CLICKED(IDC_LINE2, OnLine2)
	ON_BN_CLICKED(IDC_PC, OnPc)
	ON_BN_CLICKED(IDC_C1, OnC1)
	ON_BN_CLICKED(IDC_C2, OnC2)
	ON_BN_CLICKED(IDC_TEACHER, OnTeacher)
	ON_BN_CLICKED(IDC_ST1, OnSt1)
	ON_BN_CLICKED(IDC_GHABGE_PASS, OnGhabgePass)
	ON_BN_CLICKED(IDC_ST2, OnSt2)
	ON_BN_CLICKED(IDC_ST3, OnSt3)
	ON_BN_CLICKED(IDC_ST4, OnSt4)
	ON_BN_CLICKED(IDC_ST5, OnSt5)
	ON_BN_CLICKED(IDC_ST6, OnSt6)
	ON_BN_CLICKED(IDC_ST7, OnSt7)
	ON_BN_CLICKED(IDC_ST8, OnSt8)
	ON_BN_CLICKED(IDC_ST9, OnSt9)
	ON_BN_CLICKED(IDC_ST10, OnSt10)
	ON_BN_CLICKED(IDC_ST11, OnSt11)
	ON_BN_CLICKED(IDC_ST12, OnSt12)
	ON_BN_CLICKED(IDC_ST13, OnSt13)
	ON_BN_CLICKED(IDC_ST14, OnSt14)
	ON_BN_CLICKED(IDC_OPEN_FILE, OnOpenFile)
	ON_BN_CLICKED(IDC_T_L1, OnTL1)
	ON_BN_CLICKED(IDC_T_L2, OnTL2)
	ON_BN_CLICKED(IDC_T_PC, OnTPc)
	ON_BN_CLICKED(IDC_T_C1, OnTC1)
	ON_BN_CLICKED(IDC_T_C2, OnTC2)
	ON_COMMAND(ID_SETTING_GHANGEPASSWORD, OnSettingGhangepassword)
	ON_COMMAND(ID_SETTING_EXIT, OnSettingExit)
	ON_COMMAND(ID_HELP_ABOUT, OnHelpAbout)
	ON_COMMAND(ID_SETTING_PORTSETTING, OnSettingPortsetting)
	ON_BN_CLICKED(IDC_CALL_ON, OnCallOn)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_CALL, OnCall)
	ON_BN_CLICKED(IDC_MONITOR, OnMonitor)
	ON_BN_CLICKED(IDC_ALL, OnAll)
	ON_BN_CLICKED(IDC_TOFEL, OnTofel)
	ON_BN_CLICKED(IDC_START_EX, OnStartEx)
	ON_BN_CLICKED(IDC_CAPTURE, OnCapture)
	ON_COMMAND(ID_TOFEL_SHOWRESULTS, OnTofelShowresults)
	ON_COMMAND(ID_TOFEL_INTER, OnTofelInter)
	ON_BN_CLICKED(IDC_RESET, OnReset)
	ON_BN_CLICKED(IDC_RUN_WINAMP, OnRunWinamp)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLab_ContDlg message handlers

BOOL CLab_ContDlg::OnInitDialog()
{
	CBitmapDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	//inith port 
	if(Set_Com_Port("COM2")==FALSE)
	{
		CString sError;
		sError.Format("Can't open %s port please close port ","COM2"); 
		MessageBox(sError,"Error in Port",MB_OK|MB_ICONWARNING);
	}
	//SYSTEM  RESET 
	send[0]=65;
	send[1]=0;
	bWriteRC=WriteFile( hCom, &send, 2, &l_w,NULL ); 		
	if (!bWriteRC || l_w == 0)MessageBox("Error in send Reset Command","Error Send",MB_OK);
	//modal password dialog
	if(m_cPasswordDlg.DoModal()==IDCANCEL)OnOK();
	//set background 
	SetBitmap(IDB_BACK1,BITMAP_STRETCH);
	//set inith bitmap
	Set_Inith_Bitmap();
	//zero variables of lines
	for(i=0;i<70;i++)
	{
		Line1_St[i]=0;
		Line2_St[i]=0;
		Pc_St[i]=0;
		Conf1_St[i]=0;
		Conf2_St[i]=0;
		T_St[i]=0;
		C_St[i]=0;
		Mon_St[i]=0;
		cCall_St_On[i]=FALSE;
		
	}
	//set line1 bitmap
	m_iLine=1;
	m_cLine1.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_ON_L1)));	
	//set picture box bitmap 	
	m_cCallOn.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_TEACHER)));	
	//disable call teacher	
	CallEnable=FALSE;
	//enable tape
	bTapeDisable=FALSE;
	//set open file bitmap 
	m_cOpenFile.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_LOAD_FILE)));	
	//set call on line false
	Call_On_Line=FALSE;
	//set hide tofel
	tofel_show=FALSE;
	//zero answer student array
	for(int satr=0;satr<20;satr++)for(int sotoon=0;sotoon<100;sotoon++)St_Answer[satr][sotoon]=0;
	//teacher off
	for(int ii=0;ii<10;ii++)bteacher_on[ii]=FALSE;
	//send all_st number
	send[0]=70;
	send[1]=14;
	bWriteRC=WriteFile( hCom, &send, 2, &l_w,NULL ); 		
	if (!bWriteRC || l_w == 0)MessageBox("Error in send Reset Command","Error Send",MB_OK);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CLab_ContDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CBitmapDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CLab_ContDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
	

		CBitmapDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CLab_ContDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CLab_ContDlg::Set_Inith_Bitmap()
{
//-----------set bitmap on student button
	m_cSt1.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_OFF_ST1)));
	m_cSt2.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_OFF_ST2)));
	m_cSt3.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_OFF_ST3)));	
	m_cSt4.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_OFF_ST4)));	
	m_cSt5.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_OFF_ST5)));		
	m_cSt6.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_OFF_ST6)));	
	m_cSt7.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_OFF_ST7)));	
	m_cSt8.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_OFF_ST8)));	
	m_cSt9.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_OFF_ST9)));	
	m_cSt10.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_OFF_ST10)));	
	m_cSt11.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_OFF_ST11)));	
	m_cSt12.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_OFF_ST12)));	
	m_cSt13.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_OFF_ST13)));	
	m_cSt14.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_OFF_ST14)));	
	m_cAll.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_ALL_OFF)));		
//------set bitmap on lines	
	m_cLine1.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_L1)));
	m_cLine2.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_L2)));
	m_cPc.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_PC)));
	m_cC1.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_C1)));
	m_cC2.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_C2)));
	m_cTeacher.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_T)));
	m_cCall.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_CALL_OFF)));
	m_cMonitor.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_MON_OFF)));
	m_cTofel.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_TOFEL_OFF)));
//------set bitmap on teacher
	m_cTL1.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_T_OFF_L1)));
	m_cTL2.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_T_OFF_L2)));
	m_cTPc.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_T_OFF_PC)));
	m_cTC1.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_T_OFF_C1)));
	m_cTC2.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_T_OFF_C2)));

}

void CLab_ContDlg::OnExit() 
{
	// TODO: Add your control notification handler code here
	int iResults;
	iResults=MessageBox("Are you Sure To Exit Lab Control","Exit Lab Control",MB_OKCANCEL|MB_ICONQUESTION);
	switch (iResults)
	{
		case IDOK:
					OnOK();	
		break;
		case IDCANCEL:
		break;
	}
}

void CLab_ContDlg::OnLine1() 
{
	// TODO: Add your control notification handler code here
	//Invalidate();
	m_iLine=1;
	m_cLine1.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_ON_L1)));
	m_cLine2.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_L2)));
	m_cPc.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_PC)));
	m_cC1.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_C1)));
	m_cC2.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_C2)));
	m_cTeacher.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_T)));	
	m_cCall.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_CALL_OFF)));
	m_cMonitor.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_MON_OFF)));

	unsigned char num_st;
	for(num_st=1;num_st<15;num_st++)
	{
		if((Line1_St[num_st]==1))
		{
			if(Set_ON_Bitmap(num_st)==FALSE)MessageBox("Error in Resource","Error Resource",MB_OK);
		}
		else  
		{
			if(Set_Off_Bitmap(num_st)==FALSE)MessageBox("Error in Resourse","Error Resource",MB_OK);
		}
	}

}

void CLab_ContDlg::OnLine2() 
{
	// TODO: Add your control notification handler code here
	//Invalidate();
	m_iLine=2;
	m_cLine1.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_L1)));
	m_cLine2.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_ON_L2)));
	m_cPc.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_PC)));
	m_cC1.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_C1)));
	m_cC2.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_C2)));
	m_cTeacher.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_T)));	
	m_cCall.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_CALL_OFF)));
	m_cMonitor.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_MON_OFF)));
	
	unsigned char num_st;
	for(num_st=1;num_st<15;num_st++)
	{
		if(Line2_St[num_st]==1)Set_ON_Bitmap(num_st);
		else  Set_Off_Bitmap(num_st);
	}

}

void CLab_ContDlg::OnPc() 
{
	// TODO: Add your control notification handler code here
	//Invalidate();
	m_iLine=3;
	m_cLine1.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_L1)));
	m_cLine2.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_L2)));
	m_cPc.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_ON_PC)));
	m_cC1.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_C1)));
	m_cC2.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_C2)));
	m_cTeacher.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_T)));	
	m_cCall.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_CALL_OFF)));
	m_cMonitor.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_MON_OFF)));
	
	unsigned char num_st;
	for(num_st=1;num_st<15;num_st++)
	{
		if(Pc_St[num_st]==1)Set_ON_Bitmap(num_st);
		else  Set_Off_Bitmap(num_st);
	}

}

void CLab_ContDlg::OnC1() 
{
	// TODO: Add your control notification handler code here
	m_iLine=4;
	m_cLine1.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_L1)));
	m_cLine2.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_L2)));
	m_cPc.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_PC)));
	m_cC1.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_ON_C1)));
	m_cC2.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_C2)));
	m_cTeacher.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_T)));		
	m_cCall.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_CALL_OFF)));
	m_cMonitor.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_MON_OFF)));

	unsigned char num_st;
	for(num_st=1;num_st<15;num_st++)
	{
		if(Conf1_St[num_st]==1)Set_ON_Bitmap(num_st);
		else  Set_Off_Bitmap(num_st);
	}

}

void CLab_ContDlg::OnC2() 
{
	// TODO: Add your control notification handler code here
	m_iLine=5;
	m_cLine1.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_L1)));
	m_cLine2.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_L2)));
	m_cPc.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_PC)));
	m_cC1.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_C1)));
	m_cC2.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_ON_C2)));
	m_cTeacher.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_T)));		
	m_cCall.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_CALL_OFF)));
	m_cMonitor.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_MON_OFF)));

	unsigned char num_st;
	for(num_st=1;num_st<15;num_st++)
	{
		if(Conf2_St[num_st]==1)Set_ON_Bitmap(num_st);
		else  Set_Off_Bitmap(num_st);
	}


}

void CLab_ContDlg::OnTeacher() 
{
	// TODO: Add your control notification handler code here
	m_iLine=6;
	m_cLine1.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_L1)));
	m_cLine2.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_L2)));
	m_cPc.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_PC)));
	m_cC1.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_C1)));
	m_cC2.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_C2)));
	m_cTeacher.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_ON_T)));
	m_cCall.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_CALL_OFF)));
	m_cMonitor.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_MON_OFF)));
	
	unsigned char num_st;
	for(num_st=1;num_st<15;num_st++)
	{
		if(T_St[num_st]==1)Set_ON_Bitmap(num_st);
		else  Set_Off_Bitmap(num_st);
	}


}


void CLab_ContDlg::OnSt1() 
{
	// TODO: Add your control notification handler code here
	if(InOutLine(1)==FALSE)MessageBox("Can't set student 1 please try again");;
	
}

void CLab_ContDlg::OnGhabgePass() 
{
	// TODO: Add your control notification handler code here
	//m_cGhangePassDlg.DoModal();	

}




BOOL CLab_ContDlg::InOutLine(unsigned char num_st)
{
	send[0]=0;
	send[1]=0;
	send[0]=num_st;
	unsigned char Num_St=num_st;
//check for call
if(cCall_St[Num_St]==1)
	{
		if(cCall_St_On[Num_St]==FALSE)
		{
			send[0]=0;
			send[1]=80;
			bWriteRC=WriteFile( hCom, &send, 2, &l_w,NULL ); 		
			if (!bWriteRC || l_w == 0)MessageBox("Error in send Reset Command","Error Send",MB_OK);
			//wait 
			Delay(2);
			send[0]=Num_St;
			send[1]=80;
			bWriteRC=WriteFile( hCom, &send, 2, &l_w,NULL ); 		
			if (!bWriteRC || l_w == 0)MessageBox("Error in send Reset Command","Error Send",MB_OK);
			cCall_St_On[Num_St]=TRUE;
			Set_CallSt_Bitmap(Num_St);
			
		}
		else
		{
			cCall_St[Num_St]=0;
			send[0]=0;
			send[1]=100;
			bWriteRC=WriteFile( hCom, &send, 2, &l_w,NULL ); 		
			if (!bWriteRC || l_w == 0)MessageBox("Error in send Reset Command","Error Send",MB_OK);
			cCall_St_On[Num_St]=FALSE;
			//return teacher to old state
			UpdateData(TRUE);
			if(bteacher_on[1]==TRUE)send[1]=10;
			else if(bteacher_on[2]==TRUE)send[1]=20;
			else if(bteacher_on[3]==TRUE)send[1]=30;
			else if(bteacher_on[4]==TRUE)send[1]=50;
			else if(bteacher_on[5]==TRUE)send[1]=60;
			//wait
			Delay(2);
			bWriteRC=WriteFile( hCom, &send, 2, &l_w,NULL ); 		
			if (!bWriteRC || l_w == 0)MessageBox("Error in send Reset Command","Error Send",MB_OK);
			//WAIT
			Delay(2);
			send[0]=Num_St;
			send[1]=110;
			bWriteRC=WriteFile( hCom, &send, 2, &l_w,NULL ); 		
			if (!bWriteRC || l_w == 0)MessageBox("Error in send Reset Command","Error Send",MB_OK);
			//return student to old state 
			UpdateData(TRUE);
			if(Line1_St[Num_St]==1)send[1]=10;
			else if(Line2_St[Num_St]==1)send[1]=20;
			else if(Pc_St[Num_St]==1)send[1]=30;
			else if(Conf1_St[Num_St]==1)send[1]=50;
			else if(Conf2_St[Num_St]==1)send[1]=60;
			else if(T_St[Num_St]==1)send[1]=70;
			send[0]=Num_St;
			//WAIT
			Delay(2);
			bWriteRC=WriteFile( hCom, &send, 2, &l_w,NULL ); 		
			if (!bWriteRC || l_w == 0)MessageBox("Error in send Reset Command","Error Send",MB_OK);
			UpdateData(TRUE);
			switch (m_iLine)
			{
				case 1:
						this->OnLine1();
				break;
				case 2:
						this->OnLine2();
				break;
				case 3:
						this->OnPc();
				break;
				case 4:
						this->OnC1();
				break;
				case 5:
						this->OnC2();
				break;
				case 6:
						this->OnCall();
				break;
				case 7:
						this->OnMonitor();
				break;
			}

		}

	}
	
else{	

	switch(m_iLine)
	{
		//is line1?
		case 1:
			switch (Line1_St[Num_St])
			{
				case 0:
						if(Num_St==65)
						{
							for(int kk=1;kk<66;kk++)
							{
								Line1_St[kk]=1;
								Line2_St[kk]=0;
								Pc_St[kk]=0;
								Conf1_St[kk]=0;
								Conf2_St[kk]=0;
								//T_St[kk]=0;
								//C_St[kk]=0;
								//Mon_St[kk]=0;
							}
						}
						else	
						{
							Line1_St[Num_St]=1;
							Line2_St[Num_St]=0;
							Pc_St[Num_St]=0;
							Conf1_St[Num_St]=0;
							Conf2_St[Num_St]=0;
							//T_St[Num_St]=0;
							//C_St[Num_St]=0;
							//Mon_St[Num_St]=0;
						}
						send[1]=10;
				break;
				case 1:
						if(Num_St==65)
						{
							 for(int kk=1;kk<66;kk++)Line1_St[kk]=0;
						}
						else Line1_St[Num_St]=0;
						send[1]=100;
				break;	
			}
		break;
		//is line2?	
		case 2:
			switch (Line2_St[Num_St])
			{
				case 0:
						if(Num_St==65)
						{
							for(int kk=1;kk<66;kk++)
							{
								Line1_St[kk]=0;
								Line2_St[kk]=1;
								Pc_St[kk]=0;
								Conf1_St[kk]=0;
								Conf2_St[kk]=0;
								//T_St[kk]=0;
								//C_St[kk]=0;
								//Mon_St[kk]=0;
							}
						}
						else	
						{
							Line1_St[Num_St]=0;
							Line2_St[Num_St]=1;
							Pc_St[Num_St]=0;
							Conf1_St[Num_St]=0;
							Conf2_St[Num_St]=0;
							//T_St[Num_St]=0;
							//C_St[Num_St]=0;
							//Mon_St[Num_St]=0;
						}

						send[1]=20;
				break;
				case 1:
						if(Num_St==65)
						{
							for(int kk=1;kk<66;kk++)Line2_St[kk]=0;
						}
						else Line2_St[Num_St]=0;
						send[1]=100;
				break;	
			}
				
		break;
		//is pc?		
		case 3:
			switch (Pc_St[Num_St])
			{
				case 0:
						if(Num_St==65)
						{
							for(int kk=1;kk<66;kk++)
							{
								Line1_St[kk]=0;
								Line2_St[kk]=0;
								Pc_St[kk]=1;
								Conf1_St[kk]=0;
								Conf2_St[kk]=0;
								//T_St[kk]=0;
								//C_St[kk]=0;
								//Mon_St[kk]=0;
							}
						}
						else	
						{
							Line1_St[Num_St]=0;
							Line2_St[Num_St]=0;
							Pc_St[Num_St]=1;
							Conf1_St[Num_St]=0;
							Conf2_St[Num_St]=0;
							//T_St[Num_St]=0;
							//C_St[Num_St]=0;
							//Mon_St[Num_St]=0;
						}
						send[1]=30;
				break;
				case 1:
						if(Num_St==65)
						{
							for(int kk=1;kk<66;kk++)Pc_St[kk]=0;
						}
						else Pc_St[Num_St]=0;
						send[1]=100;
				break;	
			}
				
		break;
		//is conf1?		
		case 4:
		switch (Conf1_St[Num_St])
			{
			case 0:
					if(Num_St==65)
					{
						for(int kk=1;kk<66;kk++)
						{
							Line1_St[kk]=0;
							Line2_St[kk]=0;
							Pc_St[kk]=0;
							Conf1_St[kk]=1;
							Conf2_St[kk]=0;
							T_St[kk]=0;
							//C_St[kk]=0;
							//Mon_St[kk]=0;
						}
					}
					else	
					{
						Line1_St[Num_St]=0;
						Line2_St[Num_St]=0;
						Pc_St[Num_St]=0;
						Conf1_St[Num_St]=1;
						Conf2_St[Num_St]=0;
						T_St[Num_St]=0;
						//C_St[Num_St]=0;
						//Mon_St[Num_St]=0;
					}
					send[1]=50;
			break;
			case 1:
				if(Num_St==65)
				{
					for(int kk=1;kk<66;kk++)Conf1_St[kk]=0;
				}
				else Conf1_St[Num_St]=0;
				send[1]=100;
				break;	
			}
		break;
		//is conf2?	
		case 5:
			switch (Conf2_St[Num_St])
			{
				case 0:
						if(Num_St==65)
						{
							for(int kk=1;kk<66;kk++)
							{
								Line1_St[kk]=0;
								Line2_St[kk]=0;
								Pc_St[kk]=0;
								Conf1_St[kk]=0;
								Conf2_St[kk]=1;
								T_St[kk]=0;
								//C_St[kk]=0;
								//Mon_St[kk]=0;
							}
						}
						else	
						{
							Line1_St[Num_St]=0;
							Line2_St[Num_St]=0;
							Pc_St[Num_St]=0;
							Conf1_St[Num_St]=0;
							Conf2_St[Num_St]=1;
							T_St[Num_St]=0;
							//C_St[Num_St]=0;
							//Mon_St[Num_St]=0;
						}
						send[1]=60;
				break;
				case 1:
					if(Num_St==65)
					{
						for(int kk=1;kk<66;kk++)Conf2_St[kk]=0;
					}
					else Conf2_St[Num_St]=0;
					send[1]=100;
				break;	
			}
		break;	
		//is teacher?	
		case 6:
			switch (T_St[Num_St])
			{
				case 0:
						if(Num_St==65)
						{
							for(int kk=1;kk<66;kk++)
							{
								//Line1_St[kk]=0;
								//Line2_St[kk]=0;
								//Pc_St[kk]=0;
								Conf1_St[kk]=0;
								Conf2_St[kk]=0;
								T_St[kk]=1;
								//C_St[kk]=0;
								//Mon_St[kk]=0;
							}
						}
						else	
						{
							//Line1_St[Num_St]=0;
							//Line2_St[Num_St]=0;
							//Pc_St[Num_St]=0;
							Conf1_St[Num_St]=0;
							Conf2_St[Num_St]=0;
							T_St[Num_St]=1;
							//C_St[Num_St]=0;
							//Mon_St[Num_St]=0;
						}
						send[1]=70;
				break;
				case 1:
						if(Num_St==65)
						{
							for(int kk=1;kk<66;kk++)T_St[kk]=0;
						}
						else T_St[Num_St]=0;
						if(Line1_St[Num_St]||Line2_St[Num_St]||Pc_St[Num_St])send[1]=115;
						else send[1]=117;
				break;	
			}
		break;	
//-------------------------------is call?	
		case 7:
			switch (C_St[Num_St])
			{
				case 0:
					send[0]=0;
					send[1]=80;
					bWriteRC=WriteFile( hCom, &send, 2, &l_w,NULL ); 		
					if (!bWriteRC || l_w == 0)MessageBox("Error in send Reset Command","Error Send",MB_OK);
					//wait
					Delay(2);
					send[0]=Num_St;
					if(Num_St==65)
					{
						for(int kk=1;kk<66;kk++)
						{
							//Line1_St[kk]=0;
							//Line2_St[kk]=0;
							//Pc_St[kk]=0;
							//Conf1_St[kk]=0;
							//Conf2_St[kk]=0;
							//T_St[kk]=0;
							C_St[kk]=1;
							Mon_St[kk]=0;
						}
					}
					else	
					{
						//Line1_St[Num_St]=0;
						//Line2_St[Num_St]=0;
						//Pc_St[Num_St]=0;
						//Conf1_St[Num_St]=0;
						//Conf2_St[Num_St]=0;
						//T_St[Num_St]=0;
						C_St[Num_St]=1;
						Mon_St[Num_St]=0;
					}
					send[1]=80;
				break;
				case 1:
						send[0]=0;
						send[1]=100;
						bWriteRC=WriteFile( hCom, &send, 2, &l_w,NULL ); 		
						if (!bWriteRC || l_w == 0)MessageBox("Error in send Reset Command","Error Send",MB_OK);
						//return teacher to old state
						UpdateData(TRUE);
						if(bteacher_on[1]==TRUE)send[1]=10;
						else if(bteacher_on[2]==TRUE)send[1]=20;
						else if(bteacher_on[3]==TRUE)send[1]=30;
						else if(bteacher_on[4]==TRUE)send[1]=50;
						else if(bteacher_on[5]==TRUE)send[1]=60;
						//wait
						Delay(2);
						bWriteRC=WriteFile( hCom, &send, 2, &l_w,NULL ); 		
						if (!bWriteRC || l_w == 0)MessageBox("Error in send Reset Command","Error Send",MB_OK);
						send[0]=Num_St;
						if(Num_St==65)
						{
							for(int kk=1;kk<66;kk++)C_St[kk]=0;
						}
						else C_St[Num_St]=0;
						send[1]=110;
						//wait
						Delay(2);
						bWriteRC=WriteFile( hCom, &send, 2, &l_w,NULL ); 		
						if (!bWriteRC || l_w == 0)MessageBox("Error in send Reset Command","Error Send",MB_OK);
						if(Line1_St[Num_St]==1)send[1]=10;
						if(Line2_St[Num_St]==1)send[1]=20;
						if(Pc_St[Num_St]==1)send[1]=30;
						if(Conf1_St[Num_St]==1)send[1]=50;
						if(Conf2_St[Num_St]==1)send[1]=60;
						if(T_St[Num_St]==1)send[1]=70;
						//wait
						Delay(2);
						bWriteRC=WriteFile( hCom, &send, 2, &l_w,NULL ); 		
						if (!bWriteRC || l_w == 0)MessageBox("Error in send Reset Command","Error Send",MB_OK);
						
				break;	
			}
		break;	
//----------------------------------is monitor 
		case 8:
			switch (Mon_St[Num_St])
			{
				case 0:
					send[0]=0;
					send[1]=80;
					bWriteRC=WriteFile( hCom, &send, 2, &l_w,NULL ); 		
					if (!bWriteRC || l_w == 0)MessageBox("Error in send Reset Command","Error Send",MB_OK);
					Delay(2);
					send[0]=Num_St;
					if(Num_St==65)
					{
						for(int kk=1;kk<66;kk++)
						{
							//Line1_St[kk]=0;
							//Line2_St[kk]=0;
							//Pc_St[kk]=0;
							//Conf1_St[kk]=0;
							//Conf2_St[kk]=0;
							//T_St[kk]=0;
							C_St[kk]=0;
							Mon_St[kk]=1;
						}
					}
					else	
					{
						//Line1_St[Num_St]=0;
						//Line2_St[Num_St]=0;
						//Pc_St[Num_St]=0;
						//Conf1_St[Num_St]=0;
						//Conf2_St[Num_St]=0;
						//T_St[Num_St]=0;
						C_St[Num_St]=0;
						Mon_St[Num_St]=1;
					}
					send[1]=90;
				break;
				case 1:
					send[0]=0;
					send[1]=100;
					bWriteRC=WriteFile( hCom, &send, 2, &l_w,NULL ); 		
					if (!bWriteRC || l_w == 0)MessageBox("Error in send Reset Command","Error Send",MB_OK);
					//return teacher to old state
					UpdateData(TRUE);
					if(bteacher_on[1]==TRUE)send[1]=10;
					else if(bteacher_on[2]==TRUE)send[1]=20;
					else if(bteacher_on[3]==TRUE)send[1]=30;
					else if(bteacher_on[4]==TRUE)send[1]=50;
					else if(bteacher_on[5]==TRUE)send[1]=60;
					//wait
					Delay(2);
					bWriteRC=WriteFile( hCom, &send, 2, &l_w,NULL ); 		
					if (!bWriteRC || l_w == 0)MessageBox("Error in send Reset Command","Error Send",MB_OK);
					//wait
					Delay(2);
					send[0]=Num_St;
					if(Num_St==65)
					{
						for(int kk=1;kk<66;kk++)Mon_St[kk]=0;
					}
					else Mon_St[Num_St]=0;
					send[1]=120;
				break;	
			}

		break;
	}
	
	if((send[0]!=0)&&(send[1]!=0))
	{
		bWriteRC=WriteFile( hCom, &send, 2, &l_w,NULL ); 		
		if (!bWriteRC || l_w == 0)MessageBox("Error in send Reset Command","Error Send",MB_OK);
	}	


		if  (
				((Line1_St[Num_St]||Line2_St[Num_St]||Pc_St[Num_St]||Conf1_St[Num_St]||Conf2_St[Num_St])&&(m_iLine<6))
			||
				(T_St[Num_St]&&(m_iLine==6))
			||
				((C_St[Num_St]||Mon_St[Num_St])&&(m_iLine>6))
			)
				{
					Set_ON_Bitmap(Num_St);
		}
		else 
		{
			Set_Off_Bitmap(Num_St);
		}
}//else 		
	return TRUE;
}


void CLab_ContDlg::OnSt2() 
{
	// TODO: Add your control notification handler code here
	InOutLine(2);


}

void CLab_ContDlg::OnSt3() 
{
	// TODO: Add your control notification handler code here
		InOutLine(3);
}

void CLab_ContDlg::OnSt4() 
{
	// TODO: Add your control notification handler code here
		InOutLine(4);
}

void CLab_ContDlg::OnSt5() 
{
	// TODO: Add your control notification handler code here
		InOutLine(5);
}

void CLab_ContDlg::OnSt6() 
{
	// TODO: Add your control notification handler code here
		InOutLine(6);
}

void CLab_ContDlg::OnSt7() 
{
	// TODO: Add your control notification handler code here
		InOutLine(7);
}

void CLab_ContDlg::OnSt8() 
{
	// TODO: Add your control notification handler code here
	InOutLine(8);
}

void CLab_ContDlg::OnSt9() 
{
	// TODO: Add your control notification handler code here
	InOutLine(9);
}

void CLab_ContDlg::OnSt10() 
{
	// TODO: Add your control notification handler code here
	InOutLine(10);
}

void CLab_ContDlg::OnSt11() 
{
	// TODO: Add your control notification handler code here
	InOutLine(11);
}

void CLab_ContDlg::OnSt12() 
{
	// TODO: Add your control notification handler code here
	InOutLine(12);
}

void CLab_ContDlg::OnSt13() 
{
	// TODO: Add your control notification handler code here
	InOutLine(13);
}

void CLab_ContDlg::OnSt14() 
{
	// TODO: Add your control notification handler code here
	InOutLine(14);
}




BOOL CLab_ContDlg::Set_ON_Bitmap(unsigned char num_st)
{
	switch (num_st)
	{
		case 1:
			m_cSt1.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_ON_ST1)));	
		break;

		case 2:
			m_cSt2.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_ON_ST2)));	
		break;

		case 3:
			m_cSt3.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_ON_ST3)));	
		break;

		case 4:
			m_cSt4.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_ON_ST4)));	
		break;

		case 5:
			m_cSt5.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_ON_ST5)));	
		break;

		case 6:
			m_cSt6.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_ON_ST6)));	
		break;

		case 7:
			m_cSt7.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_ON_ST7)));	
		break;

		case 8:
			m_cSt8.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_ON_ST8)));	
		break;

		case 9:
		m_cSt9.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_ON_ST9)));	
		break;

		case 10:
			m_cSt10.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_ON_ST10)));	
		break;

		case 11:
		m_cSt11.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_ON_ST11)));	
		break;

		case 12:
			m_cSt12.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_ON_ST12)));	
		break;

		case 13:
		m_cSt13.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_ON_ST13)));	
		break;

		case 14:
			m_cSt14.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_ON_ST14)));	
		break;

		case 65:
			m_cSt1.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_ON_ST1)));	
			m_cSt2.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_ON_ST2)));	
			m_cSt3.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_ON_ST3)));	
			m_cSt4.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_ON_ST4)));	
			m_cSt5.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_ON_ST5)));	
			m_cSt6.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_ON_ST6)));	
			m_cSt7.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_ON_ST7)));	
			m_cSt8.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_ON_ST8)));	
			m_cSt9.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_ON_ST9)));	
			m_cSt10.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_ON_ST10)));	
			m_cSt11.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_ON_ST11)));	
			m_cSt12.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_ON_ST12)));	
			m_cSt13.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_ON_ST13)));	
			m_cSt14.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_ON_ST14)));	
		break;
	
	}

	return TRUE;
}

BOOL CLab_ContDlg::Set_Off_Bitmap(unsigned char num_st)
{
	switch (num_st)
	{
	case 1:
		m_cSt1.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_OFF_ST1)));	
	break;

	case 2:
		m_cSt2.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_OFF_ST2)));	
	break;

	case 3:
		m_cSt3.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_OFF_ST3)));	
	break;

	case 4:
		m_cSt4.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_OFF_ST4)));	
	break;

	case 5:
		m_cSt5.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_OFF_ST5)));	
	break;

	case 6:
		m_cSt6.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_OFF_ST6)));	
	break;

	case 7:
		m_cSt7.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_OFF_ST7)));	
	break;

	case 8:
		m_cSt8.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_OFF_ST8)));	
	break;

	case 9:
		m_cSt9.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_OFF_ST9)));	
	break;

	case 10:
		m_cSt10.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_OFF_ST10)));	
	break;

	case 11:
		m_cSt11.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_OFF_ST11)));	
	break;

	case 12:
		m_cSt12.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_OFF_ST12)));	
	break;

	case 13:
		m_cSt13.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_OFF_ST13)));	
	break;

	case 14:
		m_cSt14.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_OFF_ST14)));	
	break;

	case 65:
		m_cSt1.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_OFF_ST1)));	
		m_cSt2.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_OFF_ST2)));
		m_cSt3.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_OFF_ST3)));	
		m_cSt4.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_OFF_ST4)));	
		m_cSt5.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_OFF_ST5)));	
		m_cSt6.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_OFF_ST6)));	
		m_cSt7.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_OFF_ST7)));	
		m_cSt8.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_OFF_ST8)));	
		m_cSt9.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_OFF_ST9)));	
		m_cSt10.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_OFF_ST10)));	
		m_cSt11.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_OFF_ST11)));	
		m_cSt12.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_OFF_ST12)));	
		m_cSt13.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_OFF_ST13)));	
		m_cSt14.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_OFF_ST14)));	
	break;

	}
	return TRUE;
}

char* CLab_ContDlg::openfile(char filter[], char defuext[], char title[])
{
	char filename[50000]={0};
	char filetitle[50000];
	OPENFILENAME of;
	memset(&of,0,sizeof(of));
	of.lStructSize=sizeof(OPENFILENAME);
	of.hwndOwner=NULL;
	of.hInstance=NULL;
	of.lpstrFilter=TEXT(filter);
	of.lpstrCustomFilter=NULL;
	of.nMaxCustFilter=1;
	of.lpstrFile=filename;
	of.nMaxFile=50000;
	of.nMaxFileTitle=50000;
	of.lpstrFileTitle=filetitle;
	of.lpstrTitle=title;
	of.Flags=OFN_ALLOWMULTISELECT|OFN_FILEMUSTEXIST|OFN_HIDEREADONLY|OFN_LONGNAMES;     
	of.lpstrDefExt=defuext;
	of.lCustData=NULL;
	of.lpfnHook=NULL;
	of.lpTemplateName=NULL;
	GetOpenFileName(&of);
	return (filename);
}

void CLab_ContDlg::OnOpenFile() 
{
	// TODO: Add your control notification handler code here
/*
	char filename[50000];
	strcpy(filename,openfile("*.*\0*.*"
		,"mp3","Open Sound Files"));

	if(filename[0]!='\0')
	{
		m_cMovie.SetFileName(filename);
		m_cMovie.Run();
	}
*/
}

void CLab_ContDlg::OnTL1() 
{
	// TODO: Add your control notification handler code here
	//send line1 command
	if(bteacher_on[1]==FALSE)
	{
		send[0]=0;
		send[1]=10;
		bWriteRC=WriteFile( hCom, &send, 2, &l_w,NULL ); 		
		if (!bWriteRC || l_w == 0)MessageBox("Error in send Reset Command","Error Send",MB_OK);
		bteacher_on[1]=TRUE;
		bteacher_on[2]=FALSE;
		bteacher_on[3]=FALSE;
		bteacher_on[4]=FALSE;
		bteacher_on[5]=FALSE;
		m_cTL1.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_T_ON_L1)));
		m_cTL2.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_T_OFF_L2)));
		m_cTPc.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_T_OFF_PC)));
		m_cTC1.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_T_OFF_C1)));
		m_cTC2.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_T_OFF_C2)));
	}
	else
	{
		send[0]=0;
		send[1]=100;
		bWriteRC=WriteFile( hCom, &send, 2, &l_w,NULL ); 		
		if (!bWriteRC || l_w == 0)MessageBox("Error in send Reset Command","Error Send",MB_OK);
		bteacher_on[1]=FALSE;
		bteacher_on[2]=FALSE;
		bteacher_on[3]=FALSE;
		bteacher_on[4]=FALSE;
		bteacher_on[5]=FALSE;
		m_cTL1.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_T_OFF_L1)));
		m_cTL2.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_T_OFF_L2)));
		m_cTPc.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_T_OFF_PC)));
		m_cTC1.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_T_OFF_C1)));
		m_cTC2.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_T_OFF_C2)));
		
	}


}

void CLab_ContDlg::OnTL2() 
{
	// TODO: Add your control notification handler code here
	//send line2 command
	if(bteacher_on[2]==FALSE)
	{
		send[0]=0;
		send[1]=20;
		bWriteRC=WriteFile( hCom, &send, 2, &l_w,NULL ); 		
		bteacher_on[1]=FALSE;
		bteacher_on[2]=TRUE;
		bteacher_on[3]=FALSE;
		bteacher_on[4]=FALSE;
		bteacher_on[5]=FALSE;
		if (!bWriteRC || l_w == 0)MessageBox("Error in send Reset Command","Error Send",MB_OK);
		m_cTL1.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_T_OFF_L1)));
		m_cTL2.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_T_ON_L2)));
		m_cTPc.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_T_OFF_PC)));
		m_cTC1.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_T_OFF_C1)));
		m_cTC2.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_T_OFF_C2)));
	}
	else
	{
		send[0]=0;
		send[1]=100;
		bWriteRC=WriteFile( hCom, &send, 2, &l_w,NULL ); 
		bteacher_on[1]=FALSE;
		bteacher_on[2]=FALSE;
		bteacher_on[3]=FALSE;
		bteacher_on[4]=FALSE;
		bteacher_on[5]=FALSE;
		if (!bWriteRC || l_w == 0)MessageBox("Error in send Reset Command","Error Send",MB_OK);
		m_cTL1.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_T_OFF_L1)));
		m_cTL2.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_T_OFF_L2)));
		m_cTPc.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_T_OFF_PC)));
		m_cTC1.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_T_OFF_C1)));
		m_cTC2.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_T_OFF_C2)));
	}
}

void CLab_ContDlg::OnTPc() 
{
	// TODO: Add your control notification handler code here
	//send pc command
	if(bteacher_on[3]==FALSE)
	{
		send[0]=0;
		send[1]=30;
		bWriteRC=WriteFile( hCom, &send, 2, &l_w,NULL );
		bteacher_on[1]=FALSE;
		bteacher_on[2]=FALSE;
		bteacher_on[3]=TRUE;
		bteacher_on[4]=FALSE;
		bteacher_on[5]=FALSE;
		if (!bWriteRC || l_w == 0)MessageBox("Error in send Reset Command","Error Send",MB_OK);
		m_cTL1.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_T_OFF_L1)));
		m_cTL2.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_T_OFF_L2)));
		m_cTPc.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_T_ON_PC)));
		m_cTC1.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_T_OFF_C1)));
		m_cTC2.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_T_OFF_C2)));
	}
	else
	{
		send[0]=0;
		send[1]=100;
		bWriteRC=WriteFile( hCom, &send, 2, &l_w,NULL ); 		
		bteacher_on[1]=FALSE;
		bteacher_on[2]=FALSE;
		bteacher_on[3]=FALSE;
		bteacher_on[4]=FALSE;
		bteacher_on[5]=FALSE;
		if (!bWriteRC || l_w == 0)MessageBox("Error in send Reset Command","Error Send",MB_OK);
		m_cTL1.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_T_OFF_L1)));
		m_cTL2.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_T_OFF_L2)));
		m_cTPc.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_T_OFF_PC)));
		m_cTC1.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_T_OFF_C1)));
		m_cTC2.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_T_OFF_C2)));
	}
	
}

void CLab_ContDlg::OnTC1() 
{
	// TODO: Add your control notification handler code here
	//send c1 command
	if(bteacher_on[4]==FALSE)
	{
		send[0]=0;
		send[1]=50;
		bWriteRC=WriteFile( hCom, &send, 2, &l_w,NULL );
		bteacher_on[1]=FALSE;
		bteacher_on[2]=FALSE;
		bteacher_on[3]=FALSE;
		bteacher_on[4]=TRUE;
		bteacher_on[5]=FALSE;
		if (!bWriteRC || l_w == 0)MessageBox("Error in send Reset Command","Error Send",MB_OK);
		m_cTL1.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_T_OFF_L1)));
		m_cTL2.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_T_OFF_L2)));
		m_cTPc.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_T_OFF_PC)));
		m_cTC1.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_T_ON_C1)));
		m_cTC2.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_T_OFF_C2)));
	}
	else
	{
		send[0]=0;
		send[1]=100;
		bWriteRC=WriteFile( hCom, &send, 2, &l_w,NULL ); 		
		bteacher_on[1]=FALSE;
		bteacher_on[2]=FALSE;
		bteacher_on[3]=FALSE;
		bteacher_on[4]=FALSE;
		bteacher_on[5]=FALSE;
		if (!bWriteRC || l_w == 0)MessageBox("Error in send Reset Command","Error Send",MB_OK);
		m_cTL1.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_T_OFF_L1)));
		m_cTL2.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_T_OFF_L2)));
		m_cTPc.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_T_OFF_PC)));
		m_cTC1.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_T_OFF_C1)));
		m_cTC2.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_T_OFF_C2)));
	}

}

void CLab_ContDlg::OnTC2() 
{
	// TODO: Add your control notification handler code here
	//send c2 command
	if(bteacher_on[5]==FALSE)
	{
		send[0]=0;
		send[1]=60;
		bWriteRC=WriteFile( hCom, &send, 2, &l_w,NULL ); 		
		bteacher_on[1]=FALSE;
		bteacher_on[2]=FALSE;
		bteacher_on[3]=FALSE;
		bteacher_on[4]=FALSE;
		bteacher_on[5]=TRUE;
		if (!bWriteRC || l_w == 0)MessageBox("Error in send Reset Command","Error Send",MB_OK);
		m_cTL1.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_T_OFF_L1)));
		m_cTL2.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_T_OFF_L2)));
		m_cTPc.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_T_OFF_PC)));
		m_cTC1.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_T_OFF_C1)));
		m_cTC2.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_T_ON_C2)));
	}
	else
	{
		send[0]=0;
		send[1]=100;
		bWriteRC=WriteFile( hCom, &send, 2, &l_w,NULL ); 		
		bteacher_on[1]=FALSE;
		bteacher_on[2]=FALSE;
		bteacher_on[3]=FALSE;
		bteacher_on[4]=FALSE;
		bteacher_on[5]=FALSE;
		if (!bWriteRC || l_w == 0)MessageBox("Error in send Reset Command","Error Send",MB_OK);
		m_cTL1.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_T_OFF_L1)));
		m_cTL2.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_T_OFF_L2)));
		m_cTPc.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_T_OFF_PC)));
		m_cTC1.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_T_OFF_C1)));
		m_cTC2.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_T_OFF_C2)));
	}

}

void CLab_ContDlg::OnSettingGhangepassword() 
{
	// TODO: Add your command handler code here
	m_cGhangePassDlg.DoModal();	

}

void CLab_ContDlg::OnSettingExit() 
{
	// TODO: Add your command handler code here
	int iResults;
	iResults=MessageBox("Are you Sure To Exit Lab Control","Exit Lab Control",MB_OKCANCEL|MB_ICONQUESTION);
	switch (iResults)
	{
		case IDOK:
					//kill timer 
					KillTimer(ID_TIMER1);
					KillTimer(ID_TIMER_TOFEL);
					KillTimer(ID_CALL_TIMER);
					//close handle
					CloseHandle(hCom);
					OnOK();	
		break;
		case IDCANCEL:
		break;
	}


}

void CLab_ContDlg::OnHelpAbout() 
{
	// TODO: Add your command handler code here
	CAboutDlg m_cAboutDlg;
	m_cAboutDlg.DoModal();
}

void CLab_ContDlg::OnSettingPortsetting() 
{
	// TODO: Add your command handler code here
	CCallSettingDlg m_cCallSettingDlg;	
	m_cCallSettingDlg.m_bEnableCall=CallEnable;
	m_cCallSettingDlg.m_bDisableTape=bTapeDisable;
	m_cCallSettingDlg.DoModal();
}




void CLab_ContDlg::OnCallOn() 
{
	// TODO: Add your control notification handler code here
	CClientDC dc(this);
	if(Call_On_Line==FALSE)
	{
		Call_On_Line=TRUE;
		switch (m_iLine)
		{
			case 1:
				send[0]=65;
				send[1]=81;			//call l1 with teacher
				bWriteRC=WriteFile( hCom, &send, 2, &l_w,NULL ); 		
				if (!bWriteRC || l_w == 0)MessageBox("Error in send Command","Error Send",MB_OK);
				dc.MoveTo(672,170);
				dc.LineTo(617,225);
			break;

			case 2:
				send[0]=65;
				send[1]=83;			//call l2 with teacher
				bWriteRC=WriteFile( hCom, &send, 2, &l_w,NULL ); 		
				if (!bWriteRC || l_w == 0)MessageBox("Error in send Command","Error Send",MB_OK);
				dc.MoveTo(668,170);
				dc.LineTo(668,225);
			break;

			case 3:
				send[0]=65;
				send[1]=85;			//call pc with teacher
				bWriteRC=WriteFile( hCom, &send, 2, &l_w,NULL ); 		
				if (!bWriteRC || l_w == 0)MessageBox("Error in send Command","Error Send",MB_OK);
				dc.MoveTo(660,170);
				dc.LineTo(715,225);
			break;

		}
	}
	else
	{
		send[0]=65;
		send[1]=82;			
		bWriteRC=WriteFile( hCom, &send, 2, &l_w,NULL );
		Delay(2);
		send[0]=65;
		send[1]=84;			
		bWriteRC=WriteFile( hCom, &send, 2, &l_w,NULL );
		Delay(2);
		send[0]=65;
		send[1]=86;			
		bWriteRC=WriteFile( hCom, &send, 2, &l_w,NULL );
		Delay(2);
		Invalidate();
		Call_On_Line=FALSE;
	}

}


void CLab_ContDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	switch(nIDEvent)
	{
		case ID_TIMER1:
						if((Timer_Count%2)==0)	
						{
							if(cCall_St[1]==1)if(cCall_St_On[1]==FALSE)m_cSt1.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_ON_ST1)));	
							if(cCall_St[2]==1)if(cCall_St_On[2]==FALSE)m_cSt2.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_ON_ST2)));	
							if(cCall_St[3]==1)if(cCall_St_On[3]==FALSE)m_cSt3.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_ON_ST3)));	
							if(cCall_St[4]==1)if(cCall_St_On[4]==FALSE)m_cSt4.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_ON_ST4)));	
							if(cCall_St[5]==1)if(cCall_St_On[5]==FALSE)m_cSt5.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_ON_ST5)));	
							if(cCall_St[6]==1)if(cCall_St_On[6]==FALSE)m_cSt6.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_ON_ST6)));	
							if(cCall_St[7]==1)if(cCall_St_On[7]==FALSE)m_cSt7.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_ON_ST7)));			
							if(cCall_St[8]==1)if(cCall_St_On[8]==FALSE)m_cSt8.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_ON_ST8)));	
							if(cCall_St[9]==1)if(cCall_St_On[9]==FALSE)m_cSt9.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_ON_ST9)));	
							if(cCall_St[10]==1)if(cCall_St_On[10]==FALSE)m_cSt10.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_ON_ST10)));	
							if(cCall_St[11]==1)if(cCall_St_On[11]==FALSE)m_cSt11.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_ON_ST11)));	
							if(cCall_St[12]==1)if(cCall_St_On[12]==FALSE)m_cSt12.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_ON_ST12)));	
							if(cCall_St[13]==1)if(cCall_St_On[13]==FALSE)m_cSt13.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_ON_ST13)));	
							if(cCall_St[14]==1)if(cCall_St_On[14]==FALSE)m_cSt14.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_ON_ST14)));	

						}
						else
						{
							if(cCall_St[1]==1)if(cCall_St_On[1]==FALSE)m_cSt1.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_OFF_ST1)));	
							if(cCall_St[2]==1)if(cCall_St_On[2]==FALSE)m_cSt2.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_OFF_ST2)));	
							if(cCall_St[3]==1)if(cCall_St_On[3]==FALSE)m_cSt3.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_OFF_ST3)));	
							if(cCall_St[4]==1)if(cCall_St_On[4]==FALSE)m_cSt4.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_OFF_ST4)));	
							if(cCall_St[5]==1)if(cCall_St_On[5]==FALSE)m_cSt5.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_OFF_ST5)));	
							if(cCall_St[6]==1)if(cCall_St_On[6]==FALSE)m_cSt6.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_OFF_ST6)));	
							if(cCall_St[7]==1)if(cCall_St_On[7]==FALSE)m_cSt7.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_OFF_ST7)));	
							if(cCall_St[8]==1)if(cCall_St_On[8]==FALSE)m_cSt8.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_OFF_ST8)));	
							if(cCall_St[9]==1)if(cCall_St_On[9]==FALSE)m_cSt9.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_OFF_ST9)));	
							if(cCall_St[10]==1)if(cCall_St_On[10]==FALSE)m_cSt10.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_OFF_ST10)));	
							if(cCall_St[11]==1)if(cCall_St_On[11]==FALSE)m_cSt11.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_OFF_ST11)));	
							if(cCall_St[12]==1)if(cCall_St_On[12]==FALSE)m_cSt12.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_OFF_ST12)));	
							if(cCall_St[13]==1)if(cCall_St_On[13]==FALSE)m_cSt13.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_OFF_ST13)));	
							if(cCall_St[14]==1)if(cCall_St_On[14]==FALSE)m_cSt14.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_OFF_ST14)));	

						}
						Timer_Count++;
						if(Timer_Count==100)Timer_Count=0;
		break;
		case ID_TIMER_TOFEL:
							UpdateData(TRUE);
							iTimer_Tofel++;
							m_sT1.Format("%d",iTimer_Tofel);
							UpdateData(FALSE);
							if(m_sT1==m_sMaxT1)
							{
								this->OnCapture();
							}
							
		break;
		case ID_CALL_TIMER:
							Rec[0]=0;Rec[1]=0;
							bReadRC=ReadFile(hCom, &Rec, 4, &iBytesRead, NULL);
							if (bReadRC && iBytesRead >0)
							{
							//CString ss;
							//ss.Format("%d   %d",Rec[0],Rec[1]);
							//MessageBox(ss);
							switch (Rec[0])
								{
									case 1:
											cCall_St[1]=1;
									break;

									case 2:
										cCall_St[2]=2;
									break;
								}
							}


		break;
		

	}
	
	CBitmapDialog::OnTimer(nIDEvent);
}

void CLab_ContDlg::OnCall() 
{
	// TODO: Add your control notification handler code here
	m_iLine=7;
	m_cLine1.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_L1)));
	m_cLine2.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_L2)));
	m_cPc.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_PC)));
	m_cC1.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_C1)));
	m_cC2.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_C2)));
	m_cTeacher.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_T)));		
	m_cCall.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_CALL_ON)));
	m_cMonitor.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_MON_OFF)));

	unsigned char num_st;
	for(num_st=1;num_st<15;num_st++)
	{
		if(C_St[num_st]==1)Set_ON_Bitmap(num_st);
		else  Set_Off_Bitmap(num_st);
	}
	
}


void CLab_ContDlg::OnMonitor() 
{
	// TODO: Add your control notification handler code here
	m_iLine=8;
	m_cLine1.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_L1)));
	m_cLine2.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_L2)));
	m_cPc.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_PC)));
	m_cC1.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_C1)));
	m_cC2.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_C2)));
	m_cTeacher.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_T)));		
	m_cCall.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_CALL_OFF)));
	m_cMonitor.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_MON_ON)));

	unsigned char num_st;
	for(num_st=1;num_st<15;num_st++)
	{
		if(Mon_St[num_st]==1)Set_ON_Bitmap(num_st);
		else  Set_Off_Bitmap(num_st);
	}
	
}

void CLab_ContDlg::OnAll() 
{
	// TODO: Add your control notification handler code here
	InOutLine(65);

}






/*
	m_cSt1.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_ON_ST1)));	
	m_cSt2.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_ON_ST2)));	
	m_cSt3.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_ON_ST3)));	
	m_cSt4.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_ON_ST4)));	
	m_cSt5.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_ON_ST5)));	
	m_cSt6.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_ON_ST6)));	
	m_cSt7.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_ON_ST7)));	
	m_cSt8.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_ON_ST8)));	
	m_cSt9.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_ON_ST9)));	
	m_cSt10.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_ON_ST10)));	
	m_cSt11.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_ON_ST11)));	
	m_cSt12.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_ON_ST12)));	
	m_cSt13.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_ON_ST13)));	
	m_cSt14.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_ON_ST14)));	


			bWriteRC=WriteFile( hCom, &send, 2, &l_w,NULL ); 		
			if (!bWriteRC || l_w == 0)MessageBox("Error in send Command","Error Send",MB_OK);


*/

/*
	m_cSt1.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_OFF_ST1)));	
	m_cSt2.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_OFF_ST2)));
	m_cSt3.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_OFF_ST3)));	
	m_cSt4.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_OFF_ST4)));	
	m_cSt5.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_OFF_ST5)));	
	m_cSt6.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_OFF_ST6)));	
	m_cSt7.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_OFF_ST7)));	
	m_cSt8.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_OFF_ST8)));	
	m_cSt9.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_OFF_ST9)));	
	m_cSt10.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_OFF_ST10)));	
	m_cSt11.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_OFF_ST11)));	
	m_cSt12.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_OFF_ST12)));	
	m_cSt13.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_OFF_ST13)));	
	m_cSt14.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_OFF_ST14)));	

*/
void CLab_ContDlg::OnTofel() 
{
	// TODO: Add your control notification handler code here
	if(tofel_show==FALSE)
	{
				//inith st_answer tofel
				for(int satr=0;satr<20;satr++)for(int sotoon=0;sotoon<100;sotoon++)St_Answer[satr][sotoon]=0;
				int default_MaxT=30; 
				iNum_Qu=0;
				//------------------set bitmap 
				m_cTofel.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_TOFEL_ON)));
				//------------------visable control os tofel
				GetDlgItem(IDC_MSFLEXGRID1)->ShowWindow(TRUE);
				GetDlgItem(IDC_START_EX)->ShowWindow(TRUE);
				GetDlgItem(IDC_T1)->ShowWindow(TRUE);
				GetDlgItem(IDC_Q1)->ShowWindow(TRUE);
				GetDlgItem(IDC_MAX_T1)->ShowWindow(TRUE);
				GetDlgItem(IDC_SPIN1)->ShowWindow(TRUE);
				GetDlgItem(IDC_STATICT)->ShowWindow(TRUE);
				GetDlgItem(IDC_STATICQ)->ShowWindow(TRUE);
				GetDlgItem(IDC_STATICM)->ShowWindow(TRUE);
				GetDlgItem(IDC_STATICG)->ShowWindow(TRUE);
				GetDlgItem(IDC_RESET)->ShowWindow(TRUE);
				//-------------------------set spin control
				m_cSMaxT1.SetRange(1,200);	//range 1 to 200
				m_cSMaxT1.SetBase(10);		//base 10
				m_cSMaxT1.SetPos(default_MaxT);		//default x
				m_sMaxT1.Format("%d",default_MaxT);
				//-------------------------inith timer edit  and qustion edit
				m_sQ1="0";
				m_sT1="0";
			    //-------------------------tofel show
				tofel_show=TRUE;
				UpdateData(FALSE);
				Set_Flex_Grid(St_Answer);		
	}
	else
	{
		int iResults;
		iResults=MessageBox("Are you shure to cancel Tofel","Exit Tofel",MB_OKCANCEL|MB_ICONQUESTION);
		switch (iResults)
		{
			case IDOK:
						//set bitmap off
						m_cTofel.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_TOFEL_OFF)));
						GetDlgItem(IDC_MSFLEXGRID1)->ShowWindow(FALSE);
						GetDlgItem(IDC_START_EX)->ShowWindow(FALSE);
						GetDlgItem(IDC_T1)->ShowWindow(FALSE);
						GetDlgItem(IDC_Q1)->ShowWindow(FALSE);
						GetDlgItem(IDC_MAX_T1)->ShowWindow(FALSE);
						GetDlgItem(IDC_SPIN1)->ShowWindow(FALSE);
						GetDlgItem(IDC_STATICT)->ShowWindow(FALSE);
						GetDlgItem(IDC_STATICQ)->ShowWindow(FALSE);
						GetDlgItem(IDC_STATICM)->ShowWindow(FALSE);
						GetDlgItem(IDC_STATICG)->ShowWindow(FALSE);
						GetDlgItem(IDC_CAPTURE)->ShowWindow(FALSE);
						GetDlgItem(IDC_RESET)->ShowWindow(FALSE);
						//-----------------tofel hide
						tofel_show=FALSE;
						//-----------------kill timer 
						KillTimer(ID_TIMER_TOFEL);
			break;
			case IDCANCEL:
			break;
		}
	}
}

void CLab_ContDlg::OnStartEx() 
{
	// TODO: Add your control notification handler code here
	//disable call teacher in tofel routin
	m_cCallEnable.ShowWindow(FALSE);	
	CallEnable=FALSE;
	Call_Enable(FALSE);
	//wait
	Delay(2);
	//disable reset and tofel button 
	GetDlgItem(IDC_RESET)->EnableWindow(FALSE);
	GetDlgItem(IDC_TOFEL)->ShowWindow(FALSE);
	UpdateData(TRUE);
	//increment qustion number
	    iNum_Qu++;
	//display qustion number
		m_sQ1.Format("%d",iNum_Qu);
	    UpdateData(FALSE);
	//zero timer tofel
	  iTimer_Tofel=0;
	//Start Timer tofel	
		SetTimer(ID_TIMER_TOFEL,1000,NULL);
	//send Tofel begin command
		send[0]=65;
		send[1]=220;
		bWriteRC=WriteFile( hCom, &send, 2, &l_w,NULL ); 		
		if (!bWriteRC || l_w == 0)MessageBox("Error in send Command","Error Send",MB_OK);
	//hide start and show capture button	
		GetDlgItem(IDC_START_EX)->ShowWindow(FALSE);
		GetDlgItem(IDC_CAPTURE)->ShowWindow(TRUE);

}

void CLab_ContDlg::OnCapture() 
{
	// TODO: Add your control notification handler code here
		GetDlgItem(IDC_CAPTURE)->EnableWindow(FALSE);
		//all student
			int All_St=14;
		KillTimer(ID_TIMER_TOFEL);
		//send end tofel time
			send[0]=65;
			send[1]=230;
			bWriteRC=WriteFile( hCom, &send, 2, &l_w,NULL ); 		
			if (!bWriteRC || l_w == 0)MessageBox("Error in send Command","Error Send",MB_OK);
		//wait
			Delay(2);
		//send begin get tofel answer form st by m2
			send[0]=0;
			send[1]=241;
			bWriteRC=WriteFile( hCom, &send, 2, &l_w,NULL ); 		
			if (!bWriteRC || l_w == 0)MessageBox("Error in send Command","Error Send",MB_OK);
		//wait
			Delay(30);
			PurgeComm(hCom,PURGE_RXCLEAR);		
		//send give answer from m2	
			send[0]=0;
			send[1]=242;
			bWriteRC=WriteFile( hCom, &send, 2, &l_w,NULL ); 		
			if (!bWriteRC || l_w == 0)MessageBox("Error in send Command","Error Send",MB_OK);
		//read answer 
				for(int rr=0;rr<50;rr++)Rec[rr]=200;
				bReadRC=ReadFile(hCom, &Rec, 2*All_St, &iBytesRead, NULL); 
				if (!(bReadRC && iBytesRead > 0))MessageBox("Error in Read Data","Error Read",MB_OK);
				CString ss;
				ss.Format("%d %d  %d %d %d %d",Rec[0],Rec[1],Rec[24],Rec[25],Rec[26],Rec[27]);
				//MessageBox(ss);

				for(int aa=All_St;aa>0;aa--)St_Answer[aa][iNum_Qu]=Rec[2*(All_St-aa)+1];
			
			
		//end capture		
			MessageBox("Capture is completed please continue tofel","End Capture",MB_OK);		
		//hide capture control and show start control
			GetDlgItem(IDC_CAPTURE)->EnableWindow(TRUE);
			GetDlgItem(IDC_START_EX)->ShowWindow(TRUE);
			GetDlgItem(IDC_CAPTURE)->ShowWindow(FALSE);
			GetDlgItem(IDC_RESET)->EnableWindow(TRUE);
			GetDlgItem(IDC_TOFEL)->ShowWindow(TRUE);			

		//set answer on table
			Set_Flex_Grid(St_Answer);		
			m_sT1.Format("%d",0);
			UpdateData(FALSE);
//		End_Capture=100;

}

void CLab_ContDlg::Set_Flex_Grid(char answer_tofel[20][100])
{

	CString ss;
		//inith flex
		m_cFlex1.SetRow(0);
		m_cFlex1.SetCol(0);
		m_cFlex1.SetText("");
		m_cFlex1.SetRow(0);
		m_cFlex1.SetCol(1);
		ss.Format("%d  Answer  ",iNum_Qu);
		m_cFlex1.SetText(ss);
	for(int jj=1;jj<15;jj++)
	{
		ss.Format("%c",answer_tofel[jj][iNum_Qu]);
		m_cFlex1.SetRow(jj);
		m_cFlex1.SetCol(1);
		m_cFlex1.SetText(ss);
	}
}
void CLab_ContDlg::OnTofelShowresults() 
{
	// TODO: Add your command handler code here
	CTofelDlg m_cTofelDlg;
	m_cTofelDlg.DoModal();
}

BOOL CLab_ContDlg::Set_Com_Port(CString com_port)
{
  DCB dcb; 
  BOOL fSuccess; 
   hCom = CreateFile( com_port,
                     GENERIC_READ | GENERIC_WRITE,
                     0,    // comm devices must be opened w/exclusive-access
                     NULL, // no security attributes
                     OPEN_EXISTING, // comm devices must use OPEN_EXISTING
                     0,    // not overlapped I/O
                     NULL  // hTemplate must be NULL for comm devices
                     ); 
  
  if (hCom == INVALID_HANDLE_VALUE) 
      // Handle the error.
	return FALSE;	

  // We will build on the current configuration, and skip setting the size
  // of the input and output buffers with SetupComm.
	fSuccess= SetupComm(hCom,128, 128); // set buffer sizes
	  if (!fSuccess) 
		  // Handle the error.
		return FALSE;	

  fSuccess = GetCommState(hCom, &dcb);
  if (!fSuccess) 
      // Handle the error.
	return FALSE;	
	  
  // Fill in the DCB: baud=57,600 bps, 8 data bits, no parity, and 1 stop bit.
  dcb.BaudRate = CBR_19200;     // set the baud rate
  dcb.ByteSize = 8;             // data size, xmit, and rcv
  dcb.Parity = NOPARITY;        // no parity bit
  dcb.StopBits = ONESTOPBIT;    // one stop bit
  fSuccess = SetCommState(hCom, &dcb); 
  if (!fSuccess) 
      // Handle the error.
	return FALSE;	
 COMMTIMEOUTS  m_CommTimeouts ;
  fSuccess= GetCommTimeouts (hCom, &m_CommTimeouts);
  if (!fSuccess) 
      // Handle the error.
	return FALSE;	
    //set time for read from port
		m_CommTimeouts.ReadIntervalTimeout = 2;
		m_CommTimeouts.ReadTotalTimeoutConstant = 5;
		m_CommTimeouts.ReadTotalTimeoutMultiplier = 2;
		m_CommTimeouts.WriteTotalTimeoutConstant = 2;
		m_CommTimeouts.WriteTotalTimeoutMultiplier = 2;
		
  fSuccess =SetCommTimeouts( hCom, &m_CommTimeouts); 
  if (!fSuccess) 
	return FALSE;		//error handle

	return TRUE;

}


void CLab_ContDlg::Delay(int delay)
{
	int loop1,loop2;
	for(loop1=0;loop1<delay;loop1++)
	{
		for(loop2=0;loop2<5000000;loop2++);
	}
}

void CLab_ContDlg::OnTofelInter() 
{
	// TODO: Add your command handler code here
	CInterAnswerDlg m_cAnswerDlg;
	m_cAnswerDlg.DoModal();
}

void CLab_ContDlg::OnReset() 
{
	// TODO: Add your control notification handler code here
	int iResults;
	iResults=MessageBox("Are you shure to Reset tofel","Reset Tofel",MB_OKCANCEL|MB_ICONQUESTION);
	switch (iResults)
	{
		case IDOK:
			//zero answer student array
			int satr;
			for(satr=0;satr<20;satr++)for(int sotoon=0;sotoon<100;sotoon++)St_Answer[satr][sotoon]=0;
			iNum_Qu=0;
			//display qustion number
			m_sQ1.Format("%d",iNum_Qu);
			Set_Flex_Grid(St_Answer);		
		    UpdateData(FALSE);
		break;
		case IDCANCEL:
		
		break;
	}	
}

void CLab_ContDlg::Call_Enable(BOOL bCallEnable)
{

	if(bCallEnable==TRUE)
	{
		SetTimer(ID_CALL_TIMER,60,NULL);
		send[0]=65;				
		send[1]=200;			//enable call teacher
		bWriteRC=WriteFile( hCom, &send, 2, &l_w,NULL ); 		
		if (!bWriteRC || l_w == 0)MessageBox("Error in send Command","Error Send",MB_OK);
		//set timer for call bitmap
		Timer_Count=0;
		SetTimer(ID_TIMER1,500,NULL);
	}
	else 
	{
		KillTimer(ID_TIMER1);
		KillTimer(ID_CALL_TIMER);
		send[0]=65;				
		send[1]=210;			//enable call teacher
		bWriteRC=WriteFile( hCom, &send, 2, &l_w,NULL ); 		
		if (!bWriteRC || l_w == 0)MessageBox("Error in send Command","Error Send",MB_OK);
	}
}

BOOL CLab_ContDlg::Set_CallSt_Bitmap(unsigned char num_st)
{
	switch (num_st)
	{
		case 1:
			m_cSt1.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_CALL_ST1)));	
		break;

		case 2:
			m_cSt2.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_CALL_ST2)));	
		break;

		case 3:
			m_cSt3.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_CALL_ST3)));	
		break;

		case 4:
			m_cSt4.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_CALL_ST4)));	
		break;

		case 5:
			m_cSt5.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_CALL_ST5)));	
		break;

		case 6:
			m_cSt6.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_CALL_ST6)));	
		break;

		case 7:
			m_cSt7.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_CALL_ST7)));	
		break;

		case 8:
			m_cSt8.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_CALL_ST8)));	
		break;

		case 9:
		m_cSt9.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_CALL_ST9)));	
		break;

		case 10:
			m_cSt10.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_CALL_ST10)));	
		break;

		case 11:
		m_cSt11.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_CALL_ST11)));	
		break;

		case 12:
			m_cSt12.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_CALL_ST12)));	
		break;

		case 13:
		m_cSt13.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_CALL_ST13)));	
		break;

		case 14:
			m_cSt14.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_CALL_ST14)));	
		break;
	}
	return TRUE;
}

void CLab_ContDlg::Disable_Tape(BOOL btape)
{
	if(btape==TRUE)
	{
		send[0]=65;
		send[1]=240;
		bWriteRC=WriteFile( hCom, &send, 2, &l_w,NULL ); 		
		if (!bWriteRC || l_w == 0)MessageBox("Error in send Command","Error Send",MB_OK);
		MessageBox("Disable Tapes of Students","Disable Tape",MB_OK);
	}
	else
	{
		send[0]=65;
		send[1]=239;
		bWriteRC=WriteFile( hCom, &send, 2, &l_w,NULL ); 		
		if (!bWriteRC || l_w == 0)MessageBox("Error in send Command","Error Send",MB_OK);
		MessageBox("Enable Tapes of Students","Enable Tape",MB_OK);
	}


}

void CLab_ContDlg::OnRunWinamp() 
{
	// TODO: Add your control notification handler code here
	
}
