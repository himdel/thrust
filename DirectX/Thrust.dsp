# Microsoft Developer Studio Project File - Name="Thrust" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 5.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=Thrust - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "Thrust.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Thrust.mak" CFG="Thrust - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Thrust - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "Thrust - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Thrust - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /YX /FD /c
# ADD CPP /nologo /W2 /GX /O2 /I "..\src" /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "HAVE_CONFIG_H" /D HIGHSCOREFILE=\"thrust.hsc\" /D VERSION=\"0.89\" /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /o NUL /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /o NUL /win32
# ADD BASE RSC /l 0x41d /d "NDEBUG"
# ADD RSC /l 0x41d /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib ddraw.lib /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "Thrust - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /YX /FD /c
# ADD CPP /nologo /W3 /Gm /GX /Zi /Od /I "..\src" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "HAVE_CONFIG_H" /D HIGHSCOREFILE=\"thrust.hsc\" /D VERSION=\"pre0.89\" /YX /FD /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /o NUL /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /o NUL /win32
# ADD BASE RSC /l 0x41d /d "_DEBUG"
# ADD RSC /l 0x41d /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib ddraw.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "Thrust - Win32 Release"
# Name "Thrust - Win32 Debug"
# Begin Group "C"

# PROP Default_Filter ".c"
# Begin Source File

SOURCE=..\src\conf.c
# End Source File
# Begin Source File

SOURCE=..\src\DirectX.c
# End Source File
# Begin Source File

SOURCE=..\src\fast_gr.c
# End Source File
# Begin Source File

SOURCE=..\datasrc\font.c
# End Source File
# Begin Source File

SOURCE=..\src\font5x5.c
# End Source File
# Begin Source File

SOURCE=..\src\getopt.c
# End Source File
# Begin Source File

SOURCE=..\src\getopt1.c
# End Source File
# Begin Source File

SOURCE=..\src\graphics.c
# End Source File
# Begin Source File

SOURCE=..\src\hiscore.c
# End Source File
# Begin Source File

SOURCE=..\src\init.c
# End Source File
# Begin Source File

SOURCE=..\src\level.c
# End Source File
# Begin Source File

SOURCE=..\src\things.c
# End Source File
# Begin Source File

SOURCE=..\src\thrust.c
# End Source File
# Begin Source File

SOURCE=..\src\win32key.c
# End Source File
# End Group
# Begin Group "H"

# PROP Default_Filter ".h"
# Begin Source File

SOURCE=..\src\conf.h
# End Source File
# Begin Source File

SOURCE=..\src\config.h
# End Source File
# Begin Source File

SOURCE=..\src\fast_gr.h
# End Source File
# Begin Source File

SOURCE=..\src\font5x5.h
# End Source File
# Begin Source File

SOURCE=..\src\getopt.h
# End Source File
# Begin Source File

SOURCE=..\src\gr_drv.h
# End Source File
# Begin Source File

SOURCE=..\src\graphics.h
# End Source File
# Begin Source File

SOURCE=..\src\hiscore.h
# End Source File
# Begin Source File

SOURCE=..\src\init.h
# End Source File
# Begin Source File

SOURCE=..\src\keyboard.h
# End Source File
# Begin Source File

SOURCE=..\src\level.h
# End Source File
# Begin Source File

SOURCE=..\src\options.h
# End Source File
# Begin Source File

SOURCE=..\src\things.h
# End Source File
# Begin Source File

SOURCE=..\src\thrust.h
# End Source File
# Begin Source File

SOURCE=..\src\thrust_t.h
# End Source File
# End Group
# Begin Group "Data"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\datasrc\blks.c
# End Source File
# Begin Source File

SOURCE=..\datasrc\bullet.c
# End Source File
# Begin Source File

SOURCE=..\datasrc\colors.c
# End Source File
# Begin Source File

SOURCE=..\datasrc\demomove.c
# End Source File
# Begin Source File

SOURCE=..\datasrc\level1.c
# End Source File
# Begin Source File

SOURCE=..\datasrc\level2.c
# End Source File
# Begin Source File

SOURCE=..\datasrc\level3.c
# End Source File
# Begin Source File

SOURCE=..\datasrc\level4.c
# End Source File
# Begin Source File

SOURCE=..\datasrc\level5.c
# End Source File
# Begin Source File

SOURCE=..\datasrc\level6.c
# End Source File
# Begin Source File

SOURCE=..\datasrc\ship.c
# End Source File
# Begin Source File

SOURCE=..\datasrc\shld.c
# End Source File
# Begin Source File

SOURCE=..\datasrc\title.c
# End Source File
# End Group
# Begin Source File

SOURCE=.\nocursor.cur
# End Source File
# Begin Source File

SOURCE=.\thrust.ico
# End Source File
# Begin Source File

SOURCE=.\Thrust.rc

!IF  "$(CFG)" == "Thrust - Win32 Release"

!ELSEIF  "$(CFG)" == "Thrust - Win32 Debug"

!ENDIF 

# End Source File
# End Target
# End Project
