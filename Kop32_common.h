//---------------------------------------------------------------------------
//-------- COPYRIGHT: Stanislaw Stasiak SSTSOFT.pl @2001-2002 ---------------
//-------- https://github.com/stasinek/Koperek.VCL --------------------------
//---------------------------------------------------------------------------
#ifndef __Kop32_common_h__
#define __Kop32_common_h__
//---------------------------------------------------------------------------
#define WIN32_LEAN_AND_MEAN           // Important fix for Borland C++ 5 Shelobj.h
//---------------------------------------------------------------------------
#include ".\LIB\DLLKop32\TSoft_Kop32.h"
//---------------------------------------------------------------------------
__declspec(dllimport) TSoft::Kop32 *Kop;
extern DWORD WINAPI WinMain_common(HINSTANCE hApp, HINSTANCE hInst, char *argts, int State);
//---------------------------------------------------------------------------
#endif

