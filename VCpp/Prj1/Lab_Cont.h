// Lab_Cont.h : main header file for the LAB_CONT application
//

#if !defined(AFX_LAB_CONT_H__CD6EF745_3F64_11D7_9FC8_8C6C10779C33__INCLUDED_)
#define AFX_LAB_CONT_H__CD6EF745_3F64_11D7_9FC8_8C6C10779C33__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CLab_ContApp:
// See Lab_Cont.cpp for the implementation of this class
//

class CLab_ContApp : public CWinApp
{
public:
	CLab_ContApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLab_ContApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CLab_ContApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LAB_CONT_H__CD6EF745_3F64_11D7_9FC8_8C6C10779C33__INCLUDED_)
