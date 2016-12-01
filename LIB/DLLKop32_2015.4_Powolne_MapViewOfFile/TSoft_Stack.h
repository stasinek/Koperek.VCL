//---------------------------------------------------------------------------
//-----------------Stanislaw Stasiak "TSoft_, where?" 2001-2002---------------
// --------------------cos jak SHFileOperation(..., ...);--------------------
//---------------------------------------------------------------------------
#ifndef __TSoft_Stack_HDR__
#define __TSoft_Stack_HDR__
//---------------------------------------------------------------------------
#include "..\DLLIO\TSoft_IO.h"
#include <windows.h>
//---------------------------------------------------------------------------
extern "C" {
//------------------------------------
#define STACKSTR			(WORD)2048
#define STACKCNT			(WORD)20
//------------------------------------
class __declspec(dllexport) __stack {
private:
	char *Flptr[STACKCNT]; int Fsize[STACKCNT]; int Fcnt;
	public:
		  __stdcall  __stack();
	char *__stdcall Push (int Asize);
	void  __stdcall Pop  (int Acnt, bool Arealloc);
		  __stdcall ~__stack();
};
//---------------------------------------------------------------------------
}
#endif
