#ifndef __Koperek32_common_main_HDR__
#define __Koperek32_common_main_HDR__
//---------------------------------------------------------------------------
#define WIN32_LEAN_AND_MEAN           // Important fix for Borland C++ 5 Shelobj.h
//---------------------------------------------------------------------------
#include ".\LIB\DLLKop32\TSoft_Kop32.h"
//---------------------------------------------------------------------------
__declspec(dllimport) TSoft::Kop32 *Kop;
extern DWORD WINAPI WinMain_common(HINSTANCE hApp, HINSTANCE hInst, char *argts, int State);
//---------------------------------------------------------------------------
#endif

