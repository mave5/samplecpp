// CyberScreenDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CyberScreen.h"
#include "CyberScreenDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
HANDLE hCom;
volatile int threadController,mouse_down;
int Version;
UINT MAX_X,MAX_Y;
int x_win,y_win;
int click_count=0;
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
// CCyberScreenDlg dialog

CCyberScreenDlg::CCyberScreenDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCyberScreenDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCyberScreenDlg)
	m_sComSel = _T("");
	m_uiX = 0;
	m_uiY = 0;
	m_nDropListIndex = -1;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCyberScreenDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCyberScreenDlg)
	DDX_Control(pDX, IDC_SPINY, m_csY);
	DDX_Control(pDX, IDC_SPINX, m_csX);
	DDX_CBString(pDX, IDC_PORT_SELECT, m_sComSel);
	DDX_Text(pDX, IDC_X, m_uiX);
	DDX_Text(pDX, IDC_EDITY, m_uiY);
	DDX_CBIndex(pDX, IDC_DropList, m_nDropListIndex);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCyberScreenDlg, CDialog)
	//{{AFX_MSG_MAP(CCyberScreenDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_EXIT, OnExit)
	ON_BN_CLICKED(IDC_OK_READ, OnOkRead)
	ON_COMMAND(ID_HELP_ABOUT, OnHelpAbout)
	ON_COMMAND(ID_MENU_EXIT, OnMenuExit)
	ON_COMMAND(ID_MENU_SETTING, OnMenuSetting)
	ON_BN_CLICKED(IDC_DIS_DOWN, OnDisDown)
	ON_CBN_SELCHANGE(IDC_DropList, OnSelchangeDropList)
	ON_WM_SHOWWINDOW()
	ON_WM_LBUTTONDOWN()
	ON_WM_KEYDOWN()
	ON_WM_RBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCyberScreenDlg message handlers

BOOL CCyberScreenDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

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
	m_nDropListIndex = Version = 2 ;	 //Initialize Latest Version 
	// TODO: Add extra initialization here
	UINT default_x,default_y,default_com;

	FILE *data;
	unsigned char data_read;
	data=fopen("c:\\cyberdata.csf","a+");
	data_read=fgetc(data);
	if ((Version==0)||(Version==1)) {

		if(data_read!=255)default_x=data_read;
		else default_x=80;
	}
	if (Version==2) {
		if(data_read!=255)default_x=data_read;
		else default_x=132;
	}
	data_read=fgetc(data);
	if ((Version==0)||(Version==1)) {
		if(data_read!=255)default_y=data_read;
		else default_y=60;
	}
	if (Version==2) {
		if(data_read!=255)default_y=data_read;
		else default_y=75; 
	}

	data_read=fgetc(data);
	if(data_read!=255)default_com=data_read;
	else default_com=2;
	fclose(data);	

//set spin control for x 
	m_csX.SetRange(1,200);	//range 1 to 1000
	m_csX.SetBase(10);		//base 10
	m_csX.SetPos(default_x);		//default x
//set spin control for y 
	m_csY.SetRange(1,200);	//range 1 to 1000
	m_csY.SetBase(10);		//base 10
	m_csY.SetPos(default_y);		//default y
//set inith x ,y
	m_uiX= default_x;
	m_uiY= default_y;
//set inith port select
	switch (default_com)
	{
	case 1:
	m_sComSel.Insert(0,"COM1");
	break;
	case 2:
	m_sComSel.Insert(1,"COM2");
	break;
	case 3:
	m_sComSel.Insert(2,"COM3");
	break;
	case 4:
	m_sComSel.Insert(3,"COM4");
	break;
	}

	UpdateData(FALSE);
//set thread controller to zero
	threadController=0;
//--------
	now_open_port="";
//set icon
	m_SAIObj.SetParent(this);
//mouse down 
	mouse_down=1;
//	onetwo=TRUE;
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CCyberScreenDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CCyberScreenDlg::OnPaint() 
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
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CCyberScreenDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}





BOOL CCyberScreenDlg::Set_Com_Port(CString com_port)
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
//set time for read from port
  COMMTIMEOUTS  CommTimeOuts ;
  CommTimeOuts.ReadIntervalTimeout =  100;
  fSuccess =SetCommTimeouts( hCom, &CommTimeOuts); 
  if (!fSuccess) 
	return FALSE;		//error handle

	return TRUE;
}

void CCyberScreenDlg::OnExit() 
{
	// TODO: Add your control notification handler code here
	OnMenuExit();
	OnOK();
}







UINT ThreadProc(LPVOID param)
{
	unsigned char Rec[2];
	unsigned char x,y;
	DWORD length;
	while (threadController == 1)
	{   
        ReadFile(hCom, &Rec, 2, &length, NULL); 
		x=Rec[0];
		y=Rec[1];
		if(x==0)
		{
			switch (y)
			{
			case 1:
				if(mouse_down==1)
					mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
			break;
			case 2:
				mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);
				click_count++;
				//mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
				//mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);
			break;
			}
		}
		else
		{
			if (Version==0) {
				y=y-MAX_X;
				y=MAX_Y-y;
			}
			if (Version==1){

			}
			if (Version == 2) {
				y=MAX_Y-y;
			}

			SetCursorPos(x*x_win/MAX_X,y*y_win/MAX_Y);
		}
}
 
return 0;
}



void CCyberScreenDlg::OnOkRead() 
{
	// TODO: Add your control notification handler code here

//update control values
	UpdateData(TRUE);
//-----------------
	MAX_X=m_uiX;
	MAX_Y=m_uiY;
//get reselution of page 
	RECT win_size;
	CWnd* main_win=GetDesktopWindow();
	main_win->GetClientRect(&win_size);
	x_win=win_size.right;
	y_win=win_size.bottom;	
//open com port
if(now_open_port!=m_sComSel)
	{
	if(Set_Com_Port(m_sComSel)==FALSE)
	{
		CString sError;
		sError.Format("Can't open %s port please select another port from port select ",m_sComSel); 
		MessageBox(sError,"Error in Port",MB_OK|MB_ICONWARNING);
	}
	else
	{
		now_open_port=m_sComSel;
		if(threadController ==0)
		{
			threadController = 1;
			HWND hWnd = GetSafeHwnd();
			AfxBeginThread(ThreadProc, hWnd, THREAD_PRIORITY_NORMAL);		

		}
	}
}

	FILE *data;
	unsigned char data_write;
	data=fopen("c:\\cyberdata.csf","w+");
	data_write=m_uiX;
	fputc(data_write,data);
	data_write=m_uiY;
	fputc(data_write,data);
	if(m_sComSel=="COM1")data_write=1;
	if(m_sComSel=="COM2")data_write=2;
	if(m_sComSel=="COM3")data_write=3;
	if(m_sComSel=="COM4")data_write=4;
	fputc(data_write,data);
	fclose(data);

	m_SAIObj.InitializeObject(MAKEINTRESOURCE(IDI_FINGER), m_hWnd, 
                          "Cyber Screen", 0);  
	m_SAIObj.SetStatusAreaIcon(TRUE);
	restore=FALSE;

	
}


void CCyberScreenDlg::OnHelpAbout() 
{
	// TODO: Add your command handler code here
	CAboutDlg aboutDlg1;
	aboutDlg1.DoModal();
}

void CCyberScreenDlg::OnMenuExit() 
{
	// TODO: Add your command handler code here
/*
	threadController=0;
	CloseHandle(hCom);
	m_SAIObj.DeleteObject(); 
	OnOK();	
	*/
	int day,month,year;
	CTime now=CTime::GetCurrentTime();      // this is now

	day=now.GetDay();
	month=now.GetMonth();
	year=now.GetYear();

	FILE *log;
	CString s2,s3,s4,s5,s6;
	char s1[15],num1[10];
	int cyber_used;

	log=fopen("c:\\CyberLog.txt","a+");
	fseek(log,-19,SEEK_END);
	fgets(s1,11,log);
	fgets(num1,8,log);
	cyber_used=atoi(num1);
	fclose(log);
	
	log=fopen("c:\\CyberLog.txt","r+");
	s2.Format("%2i/%2i/%4i",day,month,year);
	
	int cmp1,cmp2=0;
	cmp1=strcmp(s1,s2);

	s3.Format("%2i/%2i/%4i\t%6i\n",day,month,year,click_count+cyber_used);

	if(cmp1)
	{
		fseek(log,0,SEEK_END);
		fputs(s3,log);
	}
	else
	{
		fseek(log,-19,SEEK_END);
		fputs(s3,log);
	}

	fclose(log);

	threadController=0;
	m_SAIObj.DeleteObject(); 
	CloseHandle(hCom);
	OnOK();
}

void CCyberScreenDlg::OnMenuSetting() 
{
	// TODO: Add your command handler code here
	if(restore==FALSE)m_SAIObj.RestoreWindow(TRUE);	
}

void CCyberScreenDlg::OnDisDown() 
{
	// TODO: Add your control notification handler code here
	//UpdateData(TRUE);
	if(mouse_down==1)mouse_down=0;
	else mouse_down=1;

}

void CCyberScreenDlg::OnSelchangeDropList() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	if( m_nDropListIndex < 0 ) return;
	switch ( m_nDropListIndex )
	{
		case 0 :
			Version = 0 ;
			MAX_X = 80 ;
			MAX_Y = 60 ;
			break ;
		case 1 :
			Version = 1;
			MAX_X = 80 ;
			MAX_Y = 60 ;
			break ;
		case 2 :
			Version = 2;
			MAX_X = 160 ;
			MAX_Y = 120 ;
			break ;
		default :
			Version = 2;
			MAX_X = 160 ;
			MAX_Y = 120 ;
			break ;

	}


		
			
	

	
}

void CCyberScreenDlg::OnShowWindow(BOOL bShow, UINT nStatus) 
{
	CDialog::OnShowWindow(bShow, nStatus);
	
}

int CCyberScreenDlg::DoModal() 
{
	// TODO: Add your specialized code here and/or call the base class
	
	return CDialog::DoModal();
}

void CCyberScreenDlg::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	CDialog::OnLButtonDown(nFlags, point);
}

void CCyberScreenDlg::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	static int first_time=0;
	// TODO: Add your message handler code here
	
	CDialog::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CCyberScreenDlg::OnRButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	CDialog::OnRButtonDown(nFlags, point);
}

void CCyberScreenDlg::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	static int first_time=0;
	// TODO: Add your message handler code here
	if(first_time==0)
	{
		first_time=1;
		OnOkRead();
	}
	
	CDialog::OnMouseMove(nFlags, point);
}
