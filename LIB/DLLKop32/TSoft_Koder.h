//-------------------------------------------------------------------------
//-----------------Stanislaw Stasiak "TSoft_, where?" 2001-2002---------------
//---------------------------------------------------------------------------
#ifndef __TSoft_Koder_HDR__
#define __TSoft_Koder_HDR__
//---------------------------------------------------------------------------
#include "TSoft_build_conf.h"
//---------------------------------------------------------------------------
extern "C" {
//---------------------------------------------------------------------------
void __stdcall Make_CRC32_tab(void);
//---------------------------------------------------------------------------
unsigned long __stdcall	Calc_CRC32(void *alpDst, unsigned long acount);
unsigned long __stdcall	Calc_ADL32(void *alpDst, unsigned long acount);
//---------------------------------------------------------------------------
#define LZS_TRASH_BPB(bufsize,block) (long)(bufsize/8)
unsigned long __stdcall   Compress_LZS(void *alpDst, void *alpSrc, unsigned long acount, unsigned long adict);
		 void __stdcall UnCompress_LZS(void *alpDst, unsigned long acount, void *alpSrc);
//---------------------------------------------------------------------------
#define HUF_TRASH_BPB(bufsize) (long)(bufsize/8)
unsigned long __stdcall   Compress_HUF(void *alpDst, void *alpSrc, unsigned long acount, unsigned short ablock);
		 void __stdcall UnCompress_HUF(void *alpDst, unsigned long acount, void *alpSrc);
//---------------------------------------------------------------------------
#define ARI_TRASH_BPB(bufsize) (long)(bufsize/8)
unsigned long __stdcall   Compress_ARI(void *alpDst, void *alpSrc, unsigned long acount, unsigned short ablock);
		 void __stdcall UnCompress_ARI(void *alpDst, unsigned long acount, void *alpSrc);
//---------------------------------------------------------------------------
#define GRAD 128
#define BWT_TRASH_BPB(bufsize,block) (long)(bufsize/GRAD)
//#define BWT_TRASH_BPB(bufsize,block) (long)(2+2+(2*bufsize)/block)
unsigned long __stdcall   Compress_BWT(void *alpDst, void *alpSrc, unsigned long acount, unsigned short ablock);
		 void __stdcall UnCompress_BWT(void *alpDst, unsigned long acount, void *alpSrc);
//---------------------------------------------------------------------------
void __stdcall	  Cript_MTF(void *alpDst, unsigned long acount);
void __stdcall	UnCript_MTF(void *alpDst, unsigned long acount);
//---------------------------------------------------------------------------
void __stdcall	  Cript_XOR(void *alpDst, unsigned long acount, char *lpHaslo, unsigned char aHaslo_count);
void __stdcall	UnCript_XOR(void *alpDst, unsigned long acount, char *lpHaslo, unsigned char aHaslo_count);
//---------------------------------------------------------------------------
void __stdcall	  Cript_SXQ(void *alpDst, unsigned long acount, unsigned char aHaslo_count);
void __stdcall	UnCript_SXQ(void *alpDst, unsigned long acount, unsigned char aHaslo_count);
//---------------------------------------------------------------------------
}
//-------------------------------THE END-------------------------------------
/*#define XBRUN_RLE_BIT  0x01L
#define MAX08_RLE_SIZE 0x3FL
#define TAG08_RLE_SIZE 2
#define MAX16_RLE_SIZE 0x1FFFL
#define TAG16_RLE_BIT  0x02L
#define TAG16_RLE_SIZE 3
#define MAX32_RLE_SIZE 0x1FFFFFFFL
#define TAG32_RLE_BIT  0x04L
#define TAG32_RLE_SIZE 3
#define RLE_TRASH_BPB(bufsize) (long)(8)
unsigned long __stdcall Compress_RLE(void *alpDst, void *alpSrc, unsigned long acount);
void __stdcall UnCompress_RLE(void *alpDst, unsigned long acount, void *alpSrc);
//---------------------------------------------------------------------------
*/
//---------------------------------------------------------------------------
/*
typedef unsigned __int8 __intRLE;
//---------------------------------------------------------------------------

unsigned long __stdcall Compress_RLE(void *alpDst,void *alpSrc,unsigned long acount)
{
unsigned long	 ptrs = (unsigned long)alpSrc;
unsigned long ptrs_end = (unsigned long)alpSrc + acount;
unsigned long	 ptrd = (unsigned long)alpDst;

unsigned long iP,iL; bool exit = false;
register __intRLE *acc;
//
for (;exit==false;)
	{
	iL=0,iP=0;

	for (;;iL++)
	 if (ptrs + (iL+8)*sizeof(__intRLE) <= ptrs_end)
		{
			acc = &((__intRLE*)ptrs)[iL];
		if (acc[0]==acc[1])
		if (acc[0]==acc[2])
		if (acc[0]==acc[3])
		if (iL <=MAX08_RLE_SIZE)
		   {iP=3; break;}
		else
		if (acc[0]==acc[4])
		if (iL <=MAX16_RLE_SIZE)
		   {iP=4; break;}
		else
		if (acc[0]==acc[5])
		if (acc[0]==acc[6])
			  {iP=6; break;}
		continue;
	   }
	else
	   {  iL = (ptrs_end-ptrs) / sizeof(__intRLE);
		exit = true;
		break;
	   }
#define SAVE_DIFRENT()\
		if (iL <=MAX08_RLE_SIZE)\
		   {*((__intTAG08*)ptrd) = (iL<<TAG08_RLE_SIZE);\
			ptrd+=sizeof(__intTAG08);\
		   }\
		else\
		if (iL <=MAX16_RLE_SIZE)\
		   {*((__intTAG16*)ptrd) = (iL<<TAG16_RLE_SIZE) | TAG16_RLE_BIT;\
			ptrd+=sizeof(__intTAG16);\
		   }\
		else\
		   {*((__intTAG32*)ptrd) = (iL<<TAG32_RLE_SIZE) | TAG16_RLE_BIT | TAG32_RLE_BIT;\
			ptrd+=sizeof(__intTAG32);\
			}\
		ptrEql((char*)ptrd,(char*)ptrs,iL*sizeof(__intRLE));\
		ptrd+=sizeof(__intRLE)*iL;\
		ptrs+=sizeof(__intRLE)*iL;
	if (iL!=0)
	   {SAVE_DIFRENT();
	   }
   for (;;iP++)
	if (ptrs + (iP+2)*sizeof(__intRLE) <= ptrs_end)
	   {
			acc = &((__intRLE*)ptrs)[iP];
		if (acc[0]!=acc[1])
		   {iP++; break;}
		continue;
	   }
	else
	   {  iP+= 1;
		exit = true;
		break;
	   }
#define SAVE_SAME()\
		if (iP <=MAX08_RLE_SIZE)\
		   {((__intTAG08*)ptrd)[0] = (iP<<TAG08_RLE_SIZE) | XBRUN_RLE_BIT;\
			ptrd+=sizeof(__intTAG08);}\
		else\
		if (iP <=MAX16_RLE_SIZE)\
		   {((__intTAG16*)ptrd)[0] = (iP<<TAG16_RLE_SIZE) | XBRUN_RLE_BIT | TAG16_RLE_BIT;\
			ptrd+=sizeof(__intTAG16);\
			}\
		else\
		   {((__intTAG32*)ptrd)[0] = (iP<<TAG32_RLE_SIZE) | XBRUN_RLE_BIT | TAG16_RLE_BIT | TAG32_RLE_BIT;\
			ptrd+=sizeof(__intTAG32);\
		   }\
		((__intRLE*)ptrd)[0]=((__intRLE*)ptrs)[0];\
		ptrd+=sizeof(__intRLE);\
		ptrs+=sizeof(__intRLE)*iP;
	if (iP >1)
	   {SAVE_SAME();
	   }
	}
for (;ptrs < ptrs_end;)
	{
	 *((__int8*)ptrd++) = *((__int8*)ptrs++);
	}
return (unsigned long)ptrd - (unsigned long)alpDst;
}
//---------------------------------------------------------------------------

void __stdcall UnCompress_RLE(void *alpDst,unsigned long acount, void *alpSrc)
{
unsigned long	 ptrs = (unsigned long)alpSrc;
unsigned long	 ptrd = (unsigned long)alpDst;
unsigned long ptrd_end = (unsigned long)alpDst + acount;
//
register unsigned long iX;

for (;ptrd <= ptrd_end - sizeof(__intRLE);)
	{
	if ((((__intTAG08*)ptrs)[0] & XBRUN_RLE_BIT)==0x00L)
	   {goto RLE_LOADDIFFRENT;
	   }
RLE_LOADSAME:
	if ((((__intTAG08*)ptrs)[0] & TAG16_RLE_BIT)==0x00L)
	   {iX =*((__intTAG08*)ptrs)>>TAG08_RLE_SIZE;
		ptrs+=sizeof(__intTAG08);
	   }
	else
	if ((((__intTAG08*)ptrs)[0] & TAG32_RLE_BIT)==0x00L)
	   {iX =*((__intTAG16*)ptrs)>>TAG16_RLE_SIZE;
		ptrs+=sizeof(__intTAG16);
	   }
	else
	   {iX =*((__intTAG32*)ptrs)>>TAG32_RLE_SIZE;
		ptrs+=sizeof(__intTAG32);
		}
	ptrSet((char*)ptrd,iX,((__intRLE*)ptrs)[0],sizeof(__intRLE));
	ptrd+=sizeof(__intRLE)*iX;
	ptrs+=sizeof(__intRLE);
	continue;

RLE_LOADDIFFRENT:
	if ((((__intTAG08*)ptrs)[0] & TAG16_RLE_BIT)==0x00L)
	   {iX =*((__intTAG08*)ptrs)>>TAG08_RLE_SIZE;
		ptrs+=sizeof(__intTAG08);
		}
	else
	if ((((__intTAG08*)ptrs)[0] & TAG32_RLE_BIT)==0x00L)
	   {iX =*((__intTAG16*)ptrs)>>TAG16_RLE_SIZE;
		ptrs+=sizeof(__intTAG16);
	   }
	else
	   {iX =*((__intTAG32*)ptrs)>>TAG32_RLE_SIZE;
		ptrs+=sizeof(__intTAG32);
	   }

	ptrEql((char*)ptrd,(char*)ptrs,iX*sizeof(__intRLE));
	ptrd+=sizeof(__intRLE)*iX;
	ptrs+=sizeof(__intRLE)*iX;
	continue;
	}
for (;ptrd < ptrd_end;)
	{
	*((__int8*)ptrd++) = *((__int8*)ptrs++);
	}
}*/
#endif

