// CyberScreen.h : main header file for the CYBERSCREEN application
//

#if !defined(AFX_CYBERSCREEN_H__8136DB85_2F89_11D7_9FC8_CC75D478C430__INCLUDED_)
#define AFX_CYBERSCREEN_H__8136DB85_2F89_11D7_9FC8_CC75D478C430__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCyberScreenApp:
// See CyberScreen.cpp for the implementation of this class
//

class CCyberScreenApp : public CWinApp
{
public:
	CCyberScreenApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCyberScreenApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCyberScreenApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CYBERSCREEN_H__8136DB85_2F89_11D7_9FC8_CC75D478C430__INCLUDED_)
