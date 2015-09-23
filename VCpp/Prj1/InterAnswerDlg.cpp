// InterAnswerDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Lab_Cont.h"
#include "Lab_ContDlg.h"
#include "InterAnswerDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CInterAnswerDlg dialog


CInterAnswerDlg::CInterAnswerDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CInterAnswerDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CInterAnswerDlg)
	m_sAns1 = _T("");
	m_sAns10 = _T("");
	m_sAns11 = _T("");
	m_sAns12 = _T("");
	m_sAns13 = _T("");
	m_sAns14 = _T("");
	m_sAns15 = _T("");
	m_sAns16 = _T("");
	m_sAns17 = _T("");
	m_sAns18 = _T("");
	m_sAns19 = _T("");
	m_sAns2 = _T("");
	m_sAns20 = _T("");
	m_sAns21 = _T("");
	m_sAns22 = _T("");
	m_sAns23 = _T("");
	m_sAns24 = _T("");
	m_sAns25 = _T("");
	m_sAns26 = _T("");
	m_sAns28 = _T("");
	m_sAns29 = _T("");
	m_sAns3 = _T("");
	m_sAns30 = _T("");
	m_sAns4 = _T("");
	m_sAns5 = _T("");
	m_sAns6 = _T("");
	m_sAns7 = _T("");
	m_sAns8 = _T("");
	m_sAns9 = _T("");
	m_sAns27 = _T("");
	//}}AFX_DATA_INIT
}


void CInterAnswerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CInterAnswerDlg)
	DDX_CBString(pDX, IDC_QU1, m_sAns1);
	DDX_CBString(pDX, IDC_QU10, m_sAns10);
	DDX_CBString(pDX, IDC_QU11, m_sAns11);
	DDX_CBString(pDX, IDC_QU12, m_sAns12);
	DDX_CBString(pDX, IDC_QU13, m_sAns13);
	DDX_CBString(pDX, IDC_QU14, m_sAns14);
	DDX_CBString(pDX, IDC_QU15, m_sAns15);
	DDX_CBString(pDX, IDC_QU16, m_sAns16);
	DDX_CBString(pDX, IDC_QU17, m_sAns17);
	DDX_CBString(pDX, IDC_QU18, m_sAns18);
	DDX_CBString(pDX, IDC_QU19, m_sAns19);
	DDX_CBString(pDX, IDC_QU2, m_sAns2);
	DDX_CBString(pDX, IDC_QU20, m_sAns20);
	DDX_CBString(pDX, IDC_QU21, m_sAns21);
	DDX_CBString(pDX, IDC_QU22, m_sAns22);
	DDX_CBString(pDX, IDC_QU23, m_sAns23);
	DDX_CBString(pDX, IDC_QU24, m_sAns24);
	DDX_CBString(pDX, IDC_QU25, m_sAns25);
	DDX_CBString(pDX, IDC_QU26, m_sAns26);
	DDX_CBString(pDX, IDC_QU28, m_sAns28);
	DDX_CBString(pDX, IDC_QU29, m_sAns29);
	DDX_CBString(pDX, IDC_QU3, m_sAns3);
	DDX_CBString(pDX, IDC_QU30, m_sAns30);
	DDX_CBString(pDX, IDC_QU4, m_sAns4);
	DDX_CBString(pDX, IDC_QU5, m_sAns5);
	DDX_CBString(pDX, IDC_QU6, m_sAns6);
	DDX_CBString(pDX, IDC_QU7, m_sAns7);
	DDX_CBString(pDX, IDC_QU8, m_sAns8);
	DDX_CBString(pDX, IDC_QU9, m_sAns9);
	DDX_CBString(pDX, IDC_QU27, m_sAns27);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CInterAnswerDlg, CDialog)
	//{{AFX_MSG_MAP(CInterAnswerDlg)
	ON_BN_CLICKED(IDC_SAVE_ANSWER, OnSaveAnswer)
	ON_BN_CLICKED(ID_OK_ANSWER, OnOkAnswer)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CInterAnswerDlg message handlers

void CInterAnswerDlg::OnSaveAnswer() 
{
	// TODO: Add your control notification handler code here
		UpdateData(TRUE);
		//get answer from edit box
		if(Get_Ans()==TRUE)
		{	
			CString m_sFile1;
			static char BASED_CODE szFilter[]="Ans Files  (*.ans)|*.ans||";
			CFileDialog m_IdFile(FALSE,".ans",m_sFile1,
			OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,szFilter);
			if(m_IdFile.DoModal()==IDOK)
			{
				m_sFile1=m_IdFile.GetPathName();
					CFile file;
					file.Open(m_sFile1,CFile::modeCreate|CFile::modeWrite);
					if(file){
								for(int ff=1;ff<31;ff++)file.Write(&Answer[ff],1);
								file.Close();
								MessageBox("Data save on file","Save Data",MB_OK);
							}

					else MessageBox("Can't Save Data Please Try Again","Error",MB_OK);				
			}
		}
}	
BOOL CInterAnswerDlg::Get_Ans()
{
	UpdateData(TRUE);
		if(m_sAns1=="")
		{
			int iRes=MessageBox("Answer 1 is Empty if you want to continue click OK else click CANCLE","Empty Answer 1",MB_OKCANCEL|MB_ICONQUESTION);
			switch (iRes)
			{
				case IDOK:
					int ff;
					for(ff=1;ff<100;ff++)Answer[ff]=0;
					return TRUE;	
				break;
				
				case IDCANCEL:
					return FALSE;
				break;
			}
		}
		if(m_sAns1=="A")Answer[1]='A';
		if(m_sAns1=="B")Answer[1]='B';
		if(m_sAns1=="C")Answer[1]='C';
		if(m_sAns1=="D")Answer[1]='D';
		//answer2
		if(m_sAns2=="")
		{
			int iRes=MessageBox("Answer 2 is Empty if you want to continue click OK else click CANCLE","Empty Answer 2",MB_OKCANCEL|MB_ICONQUESTION);
			switch (iRes)
			{
				case IDOK:
					int ff;
					for(ff=2;ff<100;ff++)Answer[ff]=0;
					return TRUE;
				break;
				
				case IDCANCEL:
					return FALSE;
				break;
			}
		}
		if(m_sAns2=="A")Answer[2]='A';
		if(m_sAns2=="B")Answer[2]='B';
		if(m_sAns2=="C")Answer[2]='C';
		if(m_sAns2=="D")Answer[2]='D';

		//answer3
		if(m_sAns3=="")
		{
			int iRes=MessageBox("Answer 3 is Empty if you want to continue click OK else click CANCLE","Empty Answer 3",MB_OKCANCEL|MB_ICONQUESTION);
			switch (iRes)
			{
				case IDOK:
					int ff;
					for( ff=3;ff<100;ff++)Answer[ff]=0;
					return TRUE;
				break;
				
				case IDCANCEL:
					return FALSE;
				break;
			}
		}
		if(m_sAns3=="A")Answer[3]='A';
		if(m_sAns3=="B")Answer[3]='B';
		if(m_sAns3=="C")Answer[3]='C';
		if(m_sAns3=="D")Answer[3]='D';

		//answer4
		if(m_sAns4=="")
		{
			int iRes=MessageBox("Answer 4 is Empty if you want to continue click OK else click CANCLE","Empty Answer 4",MB_OKCANCEL|MB_ICONQUESTION);
			switch (iRes)
			{
				case IDOK:
					int ss;
					for( ss=4;ss<100;ss++)Answer[ss]=0;
					return TRUE;
				break;
				
				case IDCANCEL:
					return FALSE;
				break;
			}
		}
		if(m_sAns4=="A")Answer[4]='A';
		if(m_sAns4=="B")Answer[4]='B';
		if(m_sAns4=="C")Answer[4]='C';
		if(m_sAns4=="D")Answer[4]='D';

		//answer5
		if(m_sAns5=="")
		{
			int iRes=MessageBox("Answer 5 is Empty if you want to continue click OK else click CANCLE","Empty Answer 5",MB_OKCANCEL|MB_ICONQUESTION);
			switch (iRes)
			{
				case IDOK:
					int ss;
					for( ss=5;ss<100;ss++)Answer[ss]=0;
					return TRUE;
				break;
				
				case IDCANCEL:
					return FALSE;
				break;
			}
		}
		if(m_sAns5=="A")Answer[5]='A';
		if(m_sAns5=="B")Answer[5]='B';
		if(m_sAns5=="C")Answer[5]='C';
		if(m_sAns5=="D")Answer[5]='D';
		
		//answer6
		if(m_sAns6=="")
		{
			int iRes=MessageBox("Answer 6 is Empty if you want to continue click OK else click CANCLE","Empty Answer 6",MB_OKCANCEL|MB_ICONQUESTION);
			switch (iRes)
			{
				case IDOK:
					int ss;
					for( ss=6;ss<100;ss++)Answer[ss]=0;
					return TRUE;
				break;
				
				case IDCANCEL:
					return FALSE;
				break;
			}
		}
		if(m_sAns6=="A")Answer[6]='A';
		if(m_sAns6=="B")Answer[6]='B';
		if(m_sAns6=="C")Answer[6]='C';
		if(m_sAns6=="D")Answer[6]='D';

		//answer7
		if(m_sAns7=="")
		{
			int iRes=MessageBox("Answer 7 is Empty if you want to continue click OK else click CANCLE","Empty Answer 7",MB_OKCANCEL|MB_ICONQUESTION);
			switch (iRes)
			{
				case IDOK:
					int ss;
					for( ss=7;ss<100;ss++)Answer[ss]=0;
					return TRUE;
				break;
				
				case IDCANCEL:
					return FALSE;
				break;
			}
		}
		if(m_sAns7=="A")Answer[7]='A';
		if(m_sAns7=="B")Answer[7]='B';
		if(m_sAns7=="C")Answer[7]='C';
		if(m_sAns7=="D")Answer[7]='D';

		//answer8
		if(m_sAns8=="")
		{
			int iRes=MessageBox("Answer 8 is Empty if you want to continue click OK else click CANCLE","Empty Answer 8",MB_OKCANCEL|MB_ICONQUESTION);
			switch (iRes)
			{
				case IDOK:
					int ss;
					for( ss=8;ss<100;ss++)Answer[ss]=0;
					return TRUE;
				break;
				
				case IDCANCEL:
					return FALSE;
				break;
			}
		}
		if(m_sAns8=="A")Answer[8]='A';
		if(m_sAns8=="B")Answer[8]='B';
		if(m_sAns8=="C")Answer[8]='C';
		if(m_sAns8=="D")Answer[8]='D';

		//answer9
		if(m_sAns9=="")
		{
			int iRes=MessageBox("Answer 9 is Empty if you want to continue click OK else click CANCLE","Empty Answer 9",MB_OKCANCEL|MB_ICONQUESTION);
			switch (iRes)
			{
				case IDOK:
					int ss;
					for( ss=9;ss<100;ss++)Answer[ss]=0;
					return TRUE;
				break;
				
				case IDCANCEL:
					return FALSE;
				break;
			}
		}
		if(m_sAns9=="A")Answer[9]='A';
		if(m_sAns9=="B")Answer[9]='B';
		if(m_sAns9=="C")Answer[9]='C';
		if(m_sAns9=="D")Answer[9]='D';

		//answer10
		if(m_sAns10=="")
		{
			int iRes=MessageBox("Answer 10 is Empty if you want to continue click OK else click CANCLE","Empty Answer 10",MB_OKCANCEL|MB_ICONQUESTION);
			switch (iRes)
			{
				case IDOK:
					int ss;
					for( ss=10;ss<100;ss++)Answer[ss]=0;
					return TRUE;
				break;
				
				case IDCANCEL:
					return FALSE;
				break;
			}
		}
		if(m_sAns10=="A")Answer[10]='A';
		if(m_sAns10=="B")Answer[10]='B';
		if(m_sAns10=="C")Answer[10]='C';
		if(m_sAns10=="D")Answer[10]='D';

		//answer11
		if(m_sAns11=="")
		{
			int iRes=MessageBox("Answer 11 is Empty if you want to continue click OK else click CANCLE","Empty Answer 11",MB_OKCANCEL|MB_ICONQUESTION);
			switch (iRes)
			{
				case IDOK:
					int ss;
					for( ss=11;ss<100;ss++)Answer[ss]=0;
					return TRUE;
				break;
				
				case IDCANCEL:
					return FALSE;
				break;
			}
		}
		if(m_sAns11=="A")Answer[11]='A';
		if(m_sAns11=="B")Answer[11]='B';
		if(m_sAns11=="C")Answer[11]='C';
		if(m_sAns11=="D")Answer[11]='D';
		
		//answer12
		if(m_sAns12=="")
		{
			int iRes=MessageBox("Answer 12 is Empty if you want to continue click OK else click CANCLE","Empty Answer 12",MB_OKCANCEL|MB_ICONQUESTION);
			switch (iRes)
			{
				case IDOK:
					int ff;
					for( ff=12;ff<100;ff++)Answer[ff]=0;
					return TRUE;
				break;
				
				case IDCANCEL:
					return FALSE;
				break;
			}
		}
		if(m_sAns12=="A")Answer[12]='A';
		if(m_sAns12=="B")Answer[12]='B';
		if(m_sAns12=="C")Answer[12]='C';
		if(m_sAns12=="D")Answer[12]='D';

		//answer13
		if(m_sAns13=="")
		{
			int iRes=MessageBox("Answer 13 is Empty if you want to continue click OK else click CANCLE","Empty Answer 13",MB_OKCANCEL|MB_ICONQUESTION);
			switch (iRes)
			{
				case IDOK:
					int ss;
					for( ss=13;ss<100;ss++)Answer[ss]=0;
					return TRUE;
				break;
				
				case IDCANCEL:
					return FALSE;
				break;
			}
		}
		if(m_sAns13=="A")Answer[13]='A';
		if(m_sAns13=="B")Answer[13]='B';
		if(m_sAns13=="C")Answer[13]='C';
		if(m_sAns13=="D")Answer[13]='D';

		//answer14
		if(m_sAns14=="")
		{
			int iRes=MessageBox("Answer 14 is Empty if you want to continue click OK else click CANCLE","Empty Answer 14",MB_OKCANCEL|MB_ICONQUESTION);
			switch (iRes)
			{
				case IDOK:
					int ss;
					for( ss=14;ss<100;ss++)Answer[ss]=0;
					return TRUE;
				break;
				
				case IDCANCEL:
					return FALSE;
				break;
			}
		}
		if(m_sAns14=="A")Answer[14]='A';
		if(m_sAns14=="B")Answer[14]='B';
		if(m_sAns14=="C")Answer[14]='C';
		if(m_sAns14=="D")Answer[14]='D';

		//answer15
		if(m_sAns15=="")
		{
			int iRes=MessageBox("Answer 15 is Empty if you want to continue click OK else click CANCLE","Empty Answer 15",MB_OKCANCEL|MB_ICONQUESTION);
			switch (iRes)
			{
				case IDOK:
					int ss;
					for( ss=15;ss<100;ss++)Answer[ss]=0;
					return TRUE;
				break;
				
				case IDCANCEL:
					return FALSE;
				break;
			}
		}
		if(m_sAns15=="A")Answer[15]='A';
		if(m_sAns15=="B")Answer[15]='B';
		if(m_sAns15=="C")Answer[15]='C';
		if(m_sAns15=="D")Answer[15]='D';

		//answer16
		if(m_sAns16=="")
		{
			int iRes=MessageBox("Answer 16 is Empty if you want to continue click OK else click CANCLE","Empty Answer 16",MB_OKCANCEL|MB_ICONQUESTION);
			switch (iRes)
			{
				case IDOK:
					int ss;
					for( ss=16;ss<100;ss++)Answer[ss]=0;
					return TRUE;
				break;
				
				case IDCANCEL:
					return FALSE;
				break;
			}
		}
		if(m_sAns16=="A")Answer[16]='A';
		if(m_sAns16=="B")Answer[16]='B';
		if(m_sAns16=="C")Answer[16]='C';
		if(m_sAns16=="D")Answer[16]='D';

		//answer17
		if(m_sAns17=="")
		{
			int iRes=MessageBox("Answer 17 is Empty if you want to continue click OK else click CANCLE","Empty Answer 17",MB_OKCANCEL|MB_ICONQUESTION);
			switch (iRes)
			{
				case IDOK:
					int ss;
					for( ss=17;ss<100;ss++)Answer[ss]=0;
					return TRUE;
				break;
				
				case IDCANCEL:
					return FALSE;
				break;
			}
		}
		if(m_sAns17=="A")Answer[17]='A';
		if(m_sAns17=="B")Answer[17]='B';
		if(m_sAns17=="C")Answer[17]='C';
		if(m_sAns17=="D")Answer[17]='D';

		//answer18
		if(m_sAns18=="")
		{
			int iRes=MessageBox("Answer 18 is Empty if you want to continue click OK else click CANCLE","Empty Answer 18",MB_OKCANCEL|MB_ICONQUESTION);
			switch (iRes)
			{
				case IDOK:
					int ss;
					for( ss=18;ss<100;ss++)Answer[ss]=0;
					return TRUE;
				break;
				
				case IDCANCEL:
					return FALSE;
				break;
			}
		}
		if(m_sAns18=="A")Answer[18]='A';
		if(m_sAns18=="B")Answer[18]='B';
		if(m_sAns18=="C")Answer[18]='C';
		if(m_sAns18=="D")Answer[18]='D';

		//answer19
		if(m_sAns19=="")
		{
			int iRes=MessageBox("Answer 19 is Empty if you want to continue click OK else click CANCLE","Empty Answer 19",MB_OKCANCEL|MB_ICONQUESTION);
			switch (iRes)
			{
				case IDOK:
					int ss;
					for( ss=19;ss<100;ss++)Answer[ss]=0;
					return TRUE;
				break;
				
				case IDCANCEL:
					return FALSE;
				break;
			}
		}
		if(m_sAns19=="A")Answer[19]='A';
		if(m_sAns19=="B")Answer[19]='B';
		if(m_sAns19=="C")Answer[19]='C';
		if(m_sAns19=="D")Answer[19]='D';

		//answer20
		if(m_sAns20=="")
		{
			int iRes=MessageBox("Answer 20 is Empty if you want to continue click OK else click CANCLE","Empty Answer 20",MB_OKCANCEL|MB_ICONQUESTION);
			switch (iRes)
			{
				case IDOK:
					int ss;
					for( ss=20;ss<100;ss++)Answer[ss]=0;
					return TRUE;
				break;
				
				case IDCANCEL:
					return FALSE;
				break;
			}
		}
		if(m_sAns20=="A")Answer[20]='A';
		if(m_sAns20=="B")Answer[20]='B';
		if(m_sAns20=="C")Answer[20]='C';
		if(m_sAns20=="D")Answer[20]='D';

		//answer21
		if(m_sAns21=="")
		{
			int iRes=MessageBox("Answer 21 is Empty if you want to continue click OK else click CANCLE","Empty Answer 21",MB_OKCANCEL|MB_ICONQUESTION);
			switch (iRes)
			{
				case IDOK:
					int ss;
					for( ss=21;ss<100;ss++)Answer[ss]=0;
					return TRUE;
				break;
				
				case IDCANCEL:
					return FALSE;
				break;
			}
		}
		if(m_sAns21=="A")Answer[21]='A';
		if(m_sAns21=="B")Answer[21]='B';
		if(m_sAns21=="C")Answer[21]='C';
		if(m_sAns21=="D")Answer[21]='D';

		//answer22
		if(m_sAns22=="")
		{
			int iRes=MessageBox("Answer 22 is Empty if you want to continue click OK else click CANCLE","Empty Answer 22",MB_OKCANCEL|MB_ICONQUESTION);
			switch (iRes)
			{
				case IDOK:
					int ss;
					for( ss=22;ss<100;ss++)Answer[ss]=0;
					return TRUE;
				break;
				
				case IDCANCEL:
					return FALSE;
				break;
			}
		}
		if(m_sAns22=="A")Answer[22]='A';
		if(m_sAns22=="B")Answer[22]='B';
		if(m_sAns22=="C")Answer[22]='C';
		if(m_sAns22=="D")Answer[22]='D';

		//answer23
		if(m_sAns23=="")
		{
			int iRes=MessageBox("Answer 23 is Empty if you want to continue click OK else click CANCLE","Empty Answer 23",MB_OKCANCEL|MB_ICONQUESTION);
			switch (iRes)
			{
				case IDOK:
					int ss;
					for( ss=23;ss<100;ss++)Answer[ss]=0;
					return TRUE;
				break;
				
				case IDCANCEL:
					return FALSE;
				break;
			}
		}
		if(m_sAns23=="A")Answer[23]='A';
		if(m_sAns23=="B")Answer[23]='B';
		if(m_sAns23=="C")Answer[23]='C';
		if(m_sAns23=="D")Answer[23]='D';

		//answer24
		if(m_sAns24=="")
		{
			int iRes=MessageBox("Answer 24 is Empty if you want to continue click OK else click CANCLE","Empty Answer 24",MB_OKCANCEL|MB_ICONQUESTION);
			switch (iRes)
			{
				case IDOK:
					int ss;
					for( ss=24;ss<100;ss++)Answer[ss]=0;
					return TRUE;
				break;
				
				case IDCANCEL:
					return FALSE;
				break;
			}
		}
		if(m_sAns24=="A")Answer[24]='A';
		if(m_sAns24=="B")Answer[24]='B';
		if(m_sAns24=="C")Answer[24]='C';
		if(m_sAns24=="D")Answer[24]='D';

		//answer25
		if(m_sAns25=="")
		{
			int iRes=MessageBox("Answer 25 is Empty if you want to continue click OK else click CANCLE","Empty Answer 25",MB_OKCANCEL|MB_ICONQUESTION);
			switch (iRes)
			{
				case IDOK:
					int ss;
					for( ss=25;ss<100;ss++)Answer[ss]=0;
					return TRUE;
				break;
				
				case IDCANCEL:
					return FALSE;
				break;
			}
		}
		if(m_sAns25=="A")Answer[25]='A';
		if(m_sAns25=="B")Answer[25]='B';
		if(m_sAns25=="C")Answer[25]='C';
		if(m_sAns25=="D")Answer[25]='D';

		//answer26
		if(m_sAns26=="")
		{
			int iRes=MessageBox("Answer 26 is Empty if you want to continue click OK else click CANCLE","Empty Answer 26",MB_OKCANCEL|MB_ICONQUESTION);
			switch (iRes)
			{
				case IDOK:
					int ss;
					for( ss=26;ss<100;ss++)Answer[ss]=0;
					return TRUE;
				break;
				
				case IDCANCEL:
					return FALSE;
				break;
			}
		}
		if(m_sAns26=="A")Answer[26]='A';
		if(m_sAns26=="B")Answer[26]='B';
		if(m_sAns26=="C")Answer[26]='C';
		if(m_sAns26=="D")Answer[26]='D';

		//answer27
		if(m_sAns27=="")
		{
			int iRes=MessageBox("Answer 27 is Empty if you want to continue click OK else click CANCLE","Empty Answer 27",MB_OKCANCEL|MB_ICONQUESTION);
			switch (iRes)
			{
				case IDOK:
					int ss;
					for( ss=27;ss<100;ss++)Answer[ss]=0;
					return TRUE;
				break;
				
				case IDCANCEL:
					return FALSE;
				break;
			}
		}
		if(m_sAns27=="A")Answer[27]='A';
		if(m_sAns27=="B")Answer[27]='B';
		if(m_sAns27=="C")Answer[27]='C';
		if(m_sAns27=="D")Answer[27]='D';

		//answer28
		if(m_sAns28=="")
		{
			int iRes=MessageBox("Answer 28 is Empty if you want to continue click OK else click CANCLE","Empty Answer 28",MB_OKCANCEL|MB_ICONQUESTION);
			switch (iRes)
			{
				case IDOK:
					int ss;
					for( ss=28;ss<100;ss++)Answer[ss]=0;
					return TRUE;
				break;
				
				case IDCANCEL:
					return FALSE;
				break;
			}
		}
		if(m_sAns28=="A")Answer[28]='A';
		if(m_sAns28=="B")Answer[28]='B';
		if(m_sAns28=="C")Answer[28]='C';
		if(m_sAns28=="D")Answer[28]='D';

		//answer29
		if(m_sAns29=="")
		{
			int iRes=MessageBox("Answer 29 is Empty if you want to continue click OK else click CANCLE","Empty Answer 29",MB_OKCANCEL|MB_ICONQUESTION);
			switch (iRes)
			{
				case IDOK:
					int ss;
					for( ss=29;ss<100;ss++)Answer[ss]=0;
					return TRUE;
				break;
				
				case IDCANCEL:
					return FALSE;
				break;
			}
		}
		if(m_sAns29=="A")Answer[29]='A';
		if(m_sAns29=="B")Answer[29]='B';
		if(m_sAns29=="C")Answer[29]='C';
		if(m_sAns29=="D")Answer[29]='D';

		//answer30
		if(m_sAns30=="")
		{
			int iRes=MessageBox("Answer 30 is Empty if you want to continue click OK else click CANCLE","Empty Answer 30",MB_OKCANCEL|MB_ICONQUESTION);
			switch (iRes)
			{
				case IDOK:
					int ss;
					for( ss=30;ss<100;ss++)Answer[ss]=0;
					return TRUE;
				break;
				
				case IDCANCEL:
					return FALSE;
				break;
			}
		}
		if(m_sAns30=="A")Answer[30]='A';
		if(m_sAns30=="B")Answer[30]='B';
		if(m_sAns30=="C")Answer[30]='C';
		if(m_sAns30=="D")Answer[30]='D';

	return TRUE;
}

void CInterAnswerDlg::OnOkAnswer() 
{
	// TODO: Add your control notification handler code here
	int iResults;
	iResults=MessageBox("Are you sure to exit","Exit",MB_OKCANCEL|MB_ICONQUESTION);
	switch (iResults)
	{
	case IDOK:
			OnOK();
	break;

	case IDCANCEL:
	break;
	}
}
