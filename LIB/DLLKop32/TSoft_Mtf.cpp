//---------------------------------------------------------------------------
#include <windows.h>
#pragma hdrstop
//---------------------------------------------------------------------------
#include "TSoft_Mtf.h"
#include "..\DLLIO\TSoft_IO.h"
//---------------------------------------------------------------------------

__stdcall TSoft_Mtf::TSoft_Mtf(void) {
order = (unsigned char*)LocalAlloc(LMEM_FIXED,sizeof(unsigned char)*256);
}
//---------------------------------------------------------------------------

__stdcall TSoft_Mtf::~TSoft_Mtf(void)
{
LocalFree(order);
}
//---------------------------------------------------------------------------

void __stdcall TSoft_Mtf::Initialize(void)
{
for (unsigned char i = 0;;i++)
	{order[i]=i;
	 if (i==255) break;
	}
}
//---------------------------------------------------------------------------

unsigned char __stdcall TSoft_Mtf::Encode(unsigned char ch)
{
register unsigned char z = ch, d = ptrChr(order,z,256);
ptrShr(order,d);
order[0]=z;
return d;
}
//---------------------------------------------------------------------------

unsigned char __stdcall TSoft_Mtf::Decode(unsigned char ch)
{
register unsigned char z = ch, d = order[z];
ptrShr(order,z);
order[0]=d;
return d;
}
//-------------------------------THE END-------------------------------------
