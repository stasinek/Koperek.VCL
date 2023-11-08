//---------------------------------------------------------------------------
//--------COPYRIGHT: Stanislaw Stasiak sstsoft.pl @2001-2002-----------------
//--------https://github.com/stasinek/Koperek.VCL----------------------------
//---------------------------------------------------------------------------
#ifndef __TSoft_IO_h__
#define __TSoft_IO_h__
//---------------------------------------------------------------------------
#include "TSoft_build_conf.h"
//---------------------------------------------------------------------------
extern "C" IMPEXP char *__stdcall strAlloc(long asize);
extern "C" IMPEXP char *__stdcall strAllocEx(long asize, const char *alpsrc);
extern "C" IMPEXP char *__stdcall strDup(const char *alpsrc);
extern "C" IMPEXP char *__stdcall strReAlloc(char *alpdst, long alength);
extern "C" IMPEXP char *__stdcall strReAllocEx(char *alpdst, long alength, const char *alpsrc);
extern "C" IMPEXP char *__stdcall strReDup(char *alpdst, const char *alpsrc);
extern "C" IMPEXP void  __stdcall strFree(char *alpdst);
//---------------------------------------------------------------------------
extern "C" IMPEXP char *__stdcall strMov(char *alpdst, const char *alpsrc);
extern "C" IMPEXP long  __stdcall strLen(const char *alpsrc);
//---------------------------------------------------------------------------
extern "C" IMPEXP char *__stdcall strAdd(char *alpdst,const char *alpsrc);
extern "C" IMPEXP char *__stdcall strInsert(char *alpdst,long astart,const char *insert);
extern "C" IMPEXP char *__stdcall strDel(char *alpdst,long astart,long alength);
extern "C" IMPEXP char *__stdcall strDelEnd(char *alpdst,long astart,long aend);
extern "C" IMPEXP char *__stdcall strSub(char *alpdst,const char *alpsrc,long astart,long alength);
extern "C" IMPEXP char *__stdcall strSubEnd(char *alpdst,const char *alpsrc,long astart,long aend);
extern "C" IMPEXP long  __stdcall strPos(const char *alpsrc,long abegin,const char *alpfnd);
//---------------------------------------------------------------------------
extern "C" IMPEXP char *__stdcall strExchange(char *alpdst,const char *alpfnd,const char *alpexh);
extern "C" IMPEXP char *__stdcall strExchangeChar(char *alpdst,const char alpfnd,const char alpexh);
//---------------------------------------------------------------------------
extern "C" IMPEXP long  __stdcall strDelimiter(const char *alpsrc,char delimiter,long adirection);
//---------------------------------------------------------------------------
extern "C" IMPEXP char *__stdcall strExtractFileRoot(char *alpdst,const char *alpsrc);
extern "C" IMPEXP char *__stdcall strExtractFilePath(char *alpdst,const char *alpsrc);
extern "C" IMPEXP char *__stdcall strExtractFileName(char *alpdst,const char *alpsrc);
extern "C" IMPEXP char *__stdcall strExtractFileExtt(char *alpdst,const char *alpsrc);
//---------------------------------------------------------------------------
extern "C" IMPEXP char *__stdcall strFixFilePath(char *alpdst, const char *alpsrc);
//---------------------------------------------------------------------------
extern "C" IMPEXP long  __stdcall strToInt(const char *astr);
extern "C" IMPEXP char *__stdcall intToStr(long  aint);
//---------------------------------------------------------------------------
extern "C" IMPEXP void *__stdcall ptrAlloc(long acount);
extern "C" IMPEXP void *__stdcall ptrReAlloc(void *alpdst,long acount);
extern "C" IMPEXP void  __stdcall ptrFree(void *alpdst);
//---------------------------------------------------------------------------
extern "C" IMPEXP void  __stdcall ptrMov(void *alpdst,const void *alpsrc,long acount);
//---------------------------------------------------------------------------
extern "C" IMPEXP void  __stdcall ptrShr(void *alpdst,long  acount);
extern "C" IMPEXP void  __stdcall ptrShl(void *alpdst,long  acount);
//---------------------------------------------------------------------------
extern "C" IMPEXP void  __stdcall ptrRev(void *alpdst,const void *alpsrc,long acount);
extern "C" IMPEXP long  __stdcall ptrCmp(void *alpdst,const void *alpsrc,long acount);
extern "C" IMPEXP void  __stdcall ptrSet(void *alpdst,char  aznakb,long acount);
extern "C" IMPEXP void  __stdcall ptrSetEx(void *alpdst,const void *alpsrc,unsigned char aesize,long acount);
extern "C" IMPEXP long  __stdcall ptrChr(const void *alpsrc,char  aznakb,long acount);
extern "C" IMPEXP long  __stdcall ptrSca(const void *alpsrc,char  aznakb,long acount);
//---------------------------------------------------------------------------
extern "C" IMPEXP long  __stdcall ptrFndLast(const char *alpsrc,long asrc_begin,long asrc_size,const char *alpfnd,long aco_size);
extern "C" IMPEXP long  __stdcall ptrFnd(const char *alpsrc,long asrc_begin,long asrc_size,const char *alpfnd,long aco_size);
//---------------------------------------------------------------------------
extern "C" IMPEXP void  __stdcall bitMov(void *alpdst,unsigned char abit_dst,const void *alpsrc, unsigned char abit_src,unsigned long abit_num);
extern "C" IMPEXP void  __stdcall bitSet(void *alpdst,const void *alpsrc, unsigned char abit_src,unsigned char asrc_elsize,unsigned long adst_count);
//---------------------------------------------------------------------------
#endif
