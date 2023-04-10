#ifndef __main_H__
#define __main_H__
//---------------------------------------------------------------------------
#include <vcl.h>
#define WIN32_LEAN_AND_MEAN
#include ".\LIB\DLLKop32\TSoft_Kop32.h"
#include <windows.h>
#include <malloc.h>
#include <stdio.h>
#include <fstream>
//---------------------------------------------------------------------------
extern TSoft::Kop32 *Kop;
extern DWORD WINAPI WinMain_common(HINSTANCE hApp, HINSTANCE hInst, char *argts, int State);
#endif

