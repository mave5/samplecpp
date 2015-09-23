# Microsoft Developer Studio Project File - Name="Lab_Cont" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=Lab_Cont - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "Lab_Cont.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Lab_Cont.mak" CFG="Lab_Cont - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Lab_Cont - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "Lab_Cont - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Lab_Cont - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x429 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x429 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "Lab_Cont - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x429 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x429 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "Lab_Cont - Win32 Release"
# Name "Lab_Cont - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\activemovie3.cpp
# End Source File
# Begin Source File

SOURCE=.\BitmapDialog.cpp
# End Source File
# Begin Source File

SOURCE=.\CallSettingDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\dib256.cpp
# End Source File
# Begin Source File

SOURCE=.\dibpal.cpp
# End Source File
# Begin Source File

SOURCE=.\font.cpp
# End Source File
# Begin Source File

SOURCE=.\GhangePassDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\InterAnswerDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Lab_Cont.cpp
# End Source File
# Begin Source File

SOURCE=.\Lab_Cont.rc
# End Source File
# Begin Source File

SOURCE=.\Lab_ContDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\msflexgrid.cpp
# End Source File
# Begin Source File

SOURCE=.\PasswordDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\picture.cpp
# End Source File
# Begin Source File

SOURCE=.\rowcursor.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\TofelDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Wait1Dlg.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\activemovie3.h
# End Source File
# Begin Source File

SOURCE=.\BitmapDialog.h
# End Source File
# Begin Source File

SOURCE=.\CallSettingDlg.h
# End Source File
# Begin Source File

SOURCE=.\dib256.h
# End Source File
# Begin Source File

SOURCE=.\dibpal.h
# End Source File
# Begin Source File

SOURCE=.\font.h
# End Source File
# Begin Source File

SOURCE=.\GhangePassDlg.h
# End Source File
# Begin Source File

SOURCE=.\InterAnswerDlg.h
# End Source File
# Begin Source File

SOURCE=.\Lab_Cont.h
# End Source File
# Begin Source File

SOURCE=.\Lab_ContDlg.h
# End Source File
# Begin Source File

SOURCE=.\msflexgrid.h
# End Source File
# Begin Source File

SOURCE=.\PasswordDlg.h
# End Source File
# Begin Source File

SOURCE=.\picture.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\rowcursor.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\TofelDlg.h
# End Source File
# Begin Source File

SOURCE=.\Wait1Dlg.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\alloff.bmp
# End Source File
# Begin Source File

SOURCE=.\res\allon.bmp
# End Source File
# Begin Source File

SOURCE=.\res\back1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\back2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00001.bmp
# End Source File
# Begin Source File

SOURCE=.\res\c1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\c1_on.bmp
# End Source File
# Begin Source File

SOURCE=.\res\c2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\c2_on.bmp
# End Source File
# Begin Source File

SOURCE=.\res\calloff.bmp
# End Source File
# Begin Source File

SOURCE=.\res\callon.bmp
# End Source File
# Begin Source File

SOURCE=.\res\l1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\l1_on.bmp
# End Source File
# Begin Source File

SOURCE=.\res\l2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\l2_on.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Lab_Cont.ico
# End Source File
# Begin Source File

SOURCE=.\res\Lab_Cont.rc2
# End Source File
# Begin Source File

SOURCE=.\res\LOAD_BTN.bmp
# End Source File
# Begin Source File

SOURCE=.\res\monitoroff.bmp
# End Source File
# Begin Source File

SOURCE=.\res\monitoron.bmp
# End Source File
# Begin Source File

SOURCE=.\res\off.bmp
# End Source File
# Begin Source File

SOURCE=.\res\pc.bmp
# End Source File
# Begin Source File

SOURCE=.\res\pc_on.bmp
# End Source File
# Begin Source File

SOURCE=.\res\red1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\shayback.bmp
# End Source File
# Begin Source File

SOURCE=.\res\st10call.bmp
# End Source File
# Begin Source File

SOURCE=.\res\st10off.bmp
# End Source File
# Begin Source File

SOURCE=.\res\st10on.bmp
# End Source File
# Begin Source File

SOURCE=.\res\st11call.bmp
# End Source File
# Begin Source File

SOURCE=.\res\st11off.bmp
# End Source File
# Begin Source File

SOURCE=.\res\st11on.bmp
# End Source File
# Begin Source File

SOURCE=.\res\st12call.bmp
# End Source File
# Begin Source File

SOURCE=.\res\st12off.bmp
# End Source File
# Begin Source File

SOURCE=.\res\st12on.bmp
# End Source File
# Begin Source File

SOURCE=.\res\st13call.bmp
# End Source File
# Begin Source File

SOURCE=.\res\st13off.bmp
# End Source File
# Begin Source File

SOURCE=.\res\st13on.bmp
# End Source File
# Begin Source File

SOURCE=.\res\st14call.bmp
# End Source File
# Begin Source File

SOURCE=.\res\st14off.bmp
# End Source File
# Begin Source File

SOURCE=.\res\st14on.bmp
# End Source File
# Begin Source File

SOURCE=.\res\st1call.bmp
# End Source File
# Begin Source File

SOURCE=.\res\st1off.bmp
# End Source File
# Begin Source File

SOURCE=.\res\st1on.bmp
# End Source File
# Begin Source File

SOURCE=.\res\st2call.bmp
# End Source File
# Begin Source File

SOURCE=.\res\st2off.bmp
# End Source File
# Begin Source File

SOURCE=.\res\st2on.bmp
# End Source File
# Begin Source File

SOURCE=.\res\st3call.bmp
# End Source File
# Begin Source File

SOURCE=.\res\st3off.bmp
# End Source File
# Begin Source File

SOURCE=.\res\st3on.bmp
# End Source File
# Begin Source File

SOURCE=.\res\st4call.bmp
# End Source File
# Begin Source File

SOURCE=.\res\st4off.bmp
# End Source File
# Begin Source File

SOURCE=.\res\st4on.bmp
# End Source File
# Begin Source File

SOURCE=.\res\st5call.bmp
# End Source File
# Begin Source File

SOURCE=.\res\st5off.bmp
# End Source File
# Begin Source File

SOURCE=.\res\st5on.bmp
# End Source File
# Begin Source File

SOURCE=.\res\st6call.bmp
# End Source File
# Begin Source File

SOURCE=.\res\st6off.bmp
# End Source File
# Begin Source File

SOURCE=.\res\st6on.bmp
# End Source File
# Begin Source File

SOURCE=.\res\st7call.bmp
# End Source File
# Begin Source File

SOURCE=.\res\st7off.bmp
# End Source File
# Begin Source File

SOURCE=.\res\st7on.bmp
# End Source File
# Begin Source File

SOURCE=.\res\st8call.bmp
# End Source File
# Begin Source File

SOURCE=.\res\st8off.bmp
# End Source File
# Begin Source File

SOURCE=.\res\st8on.bmp
# End Source File
# Begin Source File

SOURCE=.\res\st9call.bmp
# End Source File
# Begin Source File

SOURCE=.\res\st9off.bmp
# End Source File
# Begin Source File

SOURCE=.\res\st9on.bmp
# End Source File
# Begin Source File

SOURCE=.\res\t.bmp
# End Source File
# Begin Source File

SOURCE=.\res\t_off_c1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\t_off_c2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\t_off_l1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\t_off_l2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\t_off_pc.bmp
# End Source File
# Begin Source File

SOURCE=.\res\t_on.bmp
# End Source File
# Begin Source File

SOURCE=.\res\t_on_c1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\t_on_c2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\t_on_l1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\t_on_l2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\t_on_pc.bmp
# End Source File
# Begin Source File

SOURCE=.\res\tape1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Teach.bmp
# End Source File
# Begin Source File

SOURCE=.\res\tofeloff.bmp
# End Source File
# Begin Source File

SOURCE=.\res\tofelon.bmp
# End Source File
# Begin Source File

SOURCE=.\res\toffhi.bmp
# End Source File
# Begin Source File

SOURCE=.\res\ton2.bmp
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
# Section Lab_Cont : {7BF80981-BF32-101A-8BBB-00AA00300CAB}
# 	2:5:Class:CPicture
# 	2:10:HeaderFile:picture.h
# 	2:8:ImplFile:picture.cpp
# End Section
# Section Lab_Cont : {9F6AA700-D188-11CD-AD48-00AA003C9CB6}
# 	2:5:Class:CRowCursor
# 	2:10:HeaderFile:rowcursor.h
# 	2:8:ImplFile:rowcursor.cpp
# End Section
# Section Lab_Cont : {265EC140-AE62-11D1-8500-00A0C91F9CA0}
# 	2:5:Class:CActiveMovie3
# 	2:10:HeaderFile:activemovie3.h
# 	2:8:ImplFile:activemovie3.cpp
# End Section
# Section Lab_Cont : {05589FA1-C356-11CE-BF01-00AA0055595A}
# 	2:21:DefaultSinkHeaderFile:activemovie3.h
# 	2:16:DefaultSinkClass:CActiveMovie3
# End Section
# Section Lab_Cont : {5F4DF280-531B-11CF-91F6-C2863C385E30}
# 	2:5:Class:CMSFlexGrid
# 	2:10:HeaderFile:msflexgrid.h
# 	2:8:ImplFile:msflexgrid.cpp
# End Section
# Section Lab_Cont : {6262D3A0-531B-11CF-91F6-C2863C385E30}
# 	2:21:DefaultSinkHeaderFile:msflexgrid.h
# 	2:16:DefaultSinkClass:CMSFlexGrid
# End Section
# Section Lab_Cont : {BEF6E003-A874-101A-8BBA-00AA00300CAB}
# 	2:5:Class:COleFont
# 	2:10:HeaderFile:font.h
# 	2:8:ImplFile:font.cpp
# End Section
