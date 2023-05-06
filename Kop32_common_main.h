#ifndef __Koperek32_common_main_HDR__
#define __Koperek32_common_main_HDR__
//---------------------------------------------------------------------------
#include ".\LIB\DLLKop32\TSoft_Kop32.h"
//---------------------------------------------------------------------------
__declspec(dllimport) TSoft::Kop32 *Kop;
extern DWORD WINAPI WinMain_common(HINSTANCE hApp, HINSTANCE hInst, char *argts, int State);
#endif

