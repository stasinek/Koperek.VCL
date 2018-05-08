//---------------------------------------------------------------------------
//-----------------Stanislaw Stasiak "SSTSOFT.pl" 2001-2002------------------
// --------------------cos jak SHFileOperation(..., ...);--------------------
//---------------------------------------------------------------------------
#ifndef __TSoft_Stack_HDR__
#define __TSoft_Stack_HDR__
//---------------------------------------------------------------------------
#include "..\DLLIO\TSoft_IO.h"
#include <windows.h>
//---------------------------------------------------------------------------
#include "TSoft_build_conf.h"
//------------------------------------
#define STACKSTR			(WORD)2048
#define STACKCNT			(WORD)20
//------------------------------------
class KOP_IMPEXP __stack {
private:
	char *Flptr[STACKCNT]; int Fsize[STACKCNT]; int Fcnt;
	public:
	KOP_IMPEXP 	  __stdcall  __stack();
	KOP_IMPEXP char *__stdcall Push (int Asize);
	KOP_IMPEXP void  __stdcall Pop  (int Acnt, bool Arealloc);
	KOP_IMPEXP 	  __stdcall ~__stack();
};
//---------------------------------------------------------------------------
#endif
