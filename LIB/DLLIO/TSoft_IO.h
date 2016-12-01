#ifndef __TSoft_IO_HDR__
#define __TSoft_IO_HDR__
//---------------------------------------------------------------------------
extern "C" {
//---------------------------------------------------------------------------
__declspec(dllexport) char *__stdcall strAlloc(long asize);
__declspec(dllexport) char *__stdcall strAllocEx(long asize, const char *alpsrc);
__declspec(dllexport) char *__stdcall strDup(const char *alpsrc);
__declspec(dllexport) char *__stdcall strReAlloc(char *alpdst, long alength);
__declspec(dllexport) char *__stdcall strReAllocEx(char *alpdst, long alength, const char *alpsrc);
__declspec(dllexport) char *__stdcall strReDup(char *alpdst, const char *alpsrc);
__declspec(dllexport) void  __stdcall strFree(char *alpdst);
//---------------------------------------------------------------------------
__declspec(dllexport) char *__stdcall strEql(char *alpdst, const char *alpsrc);
__declspec(dllexport) char *__stdcall strMov(char *alpdst, const char *alpsrc);
__declspec(dllexport) long  __stdcall strLen(const char *alpsrc);
//---------------------------------------------------------------------------
__declspec(dllexport) char *__stdcall strAdd(char *alpdst,const char *alpsrc);
__declspec(dllexport) char *__stdcall strInsert(char *alpdst,long astart,const char *insert);
__declspec(dllexport) char *__stdcall strDel(char *alpdst,long astart,long alength);
__declspec(dllexport) char *__stdcall strDelEnd(char *alpdst,long astart,long aend);
__declspec(dllexport) char *__stdcall strSub(char *alpdst,const char *alpsrc,long astart,long alength);
__declspec(dllexport) char *__stdcall strSubEnd(char *alpdst,const char *alpsrc,long astart,long aend);
__declspec(dllexport) long  __stdcall strPos(const char *alpsrc,long abegin,const char *alpfnd);
//---------------------------------------------------------------------------
__declspec(dllexport) char *__stdcall strExchange(char *alpdst,const char *alpfnd,const char *alpexh);
__declspec(dllexport) char *__stdcall strExchangeChar(char *alpdst,const char alpfnd,const char alpexh);
//---------------------------------------------------------------------------
__declspec(dllexport) long  __stdcall strDelimiter(const char *alpsrc,char delimiter,long adirection);
//---------------------------------------------------------------------------
__declspec(dllexport) char *__stdcall strExtractFileRoot(char *alpdst,const char *alpsrc);
__declspec(dllexport) char *__stdcall strExtractFilePath(char *alpdst,const char *alpsrc);
__declspec(dllexport) char *__stdcall strExtractFileName(char *alpdst,const char *alpsrc);
//---------------------------------------------------------------------------
__declspec(dllexport) char *__stdcall strFixFilePath(char *alpdst, const char *alpsrc);
//---------------------------------------------------------------------------
__declspec(dllexport) long  __stdcall strToInt(const char *astr);
__declspec(dllexport) char *__stdcall intToStr(long  aint);
//---------------------------------------------------------------------------
__declspec(dllexport) void *__stdcall ptrAlloc(long acount);
__declspec(dllexport) void *__stdcall ptrReAlloc(void *alpdst,long acount);
__declspec(dllexport) void  __stdcall ptrFree(void *alpdst);
//---------------------------------------------------------------------------
__declspec(dllexport) void  __stdcall ptrEql(void *alpdst,const void *alpsrc,long acount);
__declspec(dllexport) void  __stdcall ptrMov(void *alpdst,const void *alpsrc,long acount);
//---------------------------------------------------------------------------
__declspec(dllexport) void  __stdcall ptrShr(void *alpdst,long  acount);
__declspec(dllexport) void  __stdcall ptrShl(void *alpdst,long  acount);
//---------------------------------------------------------------------------
__declspec(dllexport) void  __stdcall ptrRev(void *alpdst,const void *alpsrc,long acount);
__declspec(dllexport) long  __stdcall ptrCmp(void *alpdst,const void *alpsrc,long acount);
__declspec(dllexport) void  __stdcall ptrSet(void *alpdst,char  aznakb,long acount);
__declspec(dllexport) void  __stdcall ptrSetEx(void *alpdst,const void *alpsrc,unsigned char aesize,long acount);
__declspec(dllexport) long  __stdcall ptrChr(const void *alpsrc,char  aznakb,long acount);
__declspec(dllexport) long  __stdcall ptrSca(const void *alpsrc,char  aznakb,long acount);
//---------------------------------------------------------------------------
__declspec(dllexport) long  __stdcall ptrFndLast(const char *alpsrc,long asrc_begin,long asrc_size,const char *alpfnd,long aco_size);
__declspec(dllexport) long  __stdcall ptrFnd(const char *alpsrc,long asrc_begin,long asrc_size,const char *alpfnd,long aco_size);
//---------------------------------------------------------------------------
__declspec(dllexport) void  __stdcall bitEql(void *alpdst,unsigned char abit_dst,const void *alpsrc, unsigned char abit_src,   unsigned long abit_num);
__declspec(dllexport) void  __stdcall bitSet(void *alpdst,const void *alpsrc, unsigned char abit_src,unsigned char asrc_elsize,unsigned long adst_count);
//---------------------------------------------------------------------------
}
//---------------------------------------------------------------------------
#endif
