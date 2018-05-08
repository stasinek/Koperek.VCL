//---------------------------------------------------------------------------
//-----------------Stanislaw Stasiak "SSTSOFT.pl" 2001-2002------------------
//---------------------------------------------------------------------------
// --------------------cos jak SHFileOperation(..., ...);--------------------
//---------------------------------------------------------------------------
#include "TSoft_Stack.h"
//---------------------------------------------------------------------------

__stdcall __stack::__stack()
{
for (Fcnt = STACKCNT-1;;Fcnt--) {

	Fsize[Fcnt] = STACKSTR;
	Flptr[Fcnt] = strAlloc(STACKSTR);
	if (Fcnt==0)
			break;
}
}
//---------------------------------------------------------------------------

void __stdcall __stack::Pop(int Acnt, bool Arealloc)
{
for (;Acnt!=0;Acnt--) {

	if (Arealloc==true)
		{Fsize[Fcnt] = STACKSTR;
		 Flptr[Fcnt] = strReAlloc(Flptr[Fcnt],STACKSTR);
		}
	if (Fcnt==0) 
		 Fcnt =STACKCNT-1;
	else
		 Fcnt--;
}
}
//---------------------------------------------------------------------------

char *__stdcall __stack::Push(int Asize)
{
if (Fcnt>=STACKCNT-1) Fcnt =0;
else
	Fcnt++;

if (Asize > Fsize[Fcnt]) {
	Fsize[Fcnt] = Asize;
	Flptr[Fcnt] = strReAlloc(Flptr[Fcnt], Asize);
	}
return Flptr[Fcnt];
}
//---------------------------------------------------------------------------

__stdcall __stack::~__stack()
{
for (Fcnt = STACKCNT-1;;Fcnt--) {
 if (Flptr[Fcnt]!=NULL) strFree(Flptr[Fcnt]);
 if (Fcnt==0) break;
}
}
//---------------------------------------------------------------------------
