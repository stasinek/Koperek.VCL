//---------------------------------------------------------------------------
//-----------------Stanislaw Stasiak "SSTSOFT.pl" 2001-2002------------------
//---------------------------------------------------------------------------
#include <windows.h>
#pragma hdrstop
//---------------------------------------------------------------------------
#include "TSoft_IO.h"
//---------------------------------------------------------------------------

__declspec(dllexport) char *__stdcall strAlloc(long alength)
{
return (char*)LocalAlloc(LPTR,alength);
}
//---------------------------------------------------------------------------

__declspec(dllexport) char *__stdcall strAllocEx(long alength, const char *alpsrc)
{
return strMov(strAlloc(alength),alpsrc);
}
//---------------------------------------------------------------------------

__declspec(dllexport) char *__stdcall strReAlloc(char *alpdst, long alength)
{
return (char*)LocalReAlloc(alpdst,alength,LMEM_MOVEABLE);
}
//---------------------------------------------------------------------------

__declspec(dllexport) char *__stdcall strReAllocEx(char *alpdst, long alength, const char *alpsrc)
{
return strMov(strReAlloc(alpdst,alength),alpsrc);
}
//---------------------------------------------------------------------------

__declspec(dllexport) void __stdcall strFree(char *alpdst)
{
LocalFree(alpdst);
}
//---------------------------------------------------------------------------

__declspec(dllexport) char *__stdcall strDup(const char *alpdst)
{
return strMov(strAlloc(strLen(alpdst)+1),alpdst);
}
//---------------------------------------------------------------------------

__declspec(dllexport) char *__stdcall strReDup(char *alpdst, const char *alpsrc)
{
return strMov(strReAlloc(alpdst,strLen(alpsrc)+1),alpsrc);
}
//---------------------------------------------------------------------------

__declspec(dllexport) long __stdcall strLen(const char *alpsrc) {
#if (__BORLANDC__ > 0x551) || defined(_MSC_VER)
 __asm {
  mov EDI,alpsrc
  mov ESI,EDI
  mov ECX,0xFFFFFFFF
  xor EAX,EAX
  cld
repnz SCASB
  not ECX
  dec ECX
  mov EAX,ECX
}
#else
return strlen(alpsrc);
#endif
}
//---------------------------------------------------------------------------

__declspec(dllexport) char *__stdcall strMov(char *alpdst,const char *alpsrc)
{
ptrMov(alpdst,alpsrc,strLen(alpsrc)+1);
return alpdst;
}
//---------------------------------------------------------------------------

__declspec(dllexport) char *__stdcall strnMov(char *alpdst,const char *alpsrc,long alength)
{
ptrMov(alpdst,alpsrc,alength);
return alpdst;
}
//---------------------------------------------------------------------------

__declspec(dllexport) char *__stdcall strAdd(char *alpdst,const char *alpsrc)
{
return strcat(alpdst,alpsrc);
}
//---------------------------------------------------------------------------

__declspec(dllexport) char *__stdcall strInsert(char *alpdst, long astart,const char *ainsert)
{
long insertlen = strlen(ainsert), cellen = strlen(alpdst);
if (insertlen==0)
	return alpdst;
if (cellen > astart)
	{strnMov((char*)((long)alpdst+astart+insertlen),(char*)((long)alpdst+astart),cellen-astart);
	}
strnMov((char*)((long)alpdst+astart),(char*)ainsert,insertlen);
alpdst[cellen+insertlen] = 0;
return alpdst;
}
//---------------------------------------------------------------------------

__declspec(dllexport) char *__stdcall strDel(char *alpdst, long astart, long alength)
{
strnMov((char*)((long)alpdst+astart),(char*)((long)alpdst+astart+alength),strLen(alpdst)-astart-alength);
alpdst[strlen(alpdst)-alength] = 0;
return alpdst;
}
//---------------------------------------------------------------------------

__declspec(dllexport) char *__stdcall strDelEnd(char *alpdst, long astart, long aend)
{
strnMov((char*)((long)alpdst+astart),(char*)((long)alpdst+aend),strLen(alpdst)-aend);
alpdst[strlen(alpdst)-(aend-astart)] = 0;
return alpdst;
}
//---------------------------------------------------------------------------

__declspec(dllexport) long __stdcall strPos(const char *alpsrc, long a_start, const char *alpfnd)
{
long a_src_size = strLen(alpsrc), fnd_size = strLen(alpfnd);
#if (__BORLANDC__ > 0x551) || defined(_MSC_VER)
__asm {
//------------------------------------------
 mov EDX,fnd_size
 cmp EDX,0
 jle strPosERROR
//-----------------
 mov ECX,a_src_size
 cmp ECX,0
 jle strPosERROR
//-----------------
 mov EBX,a_start
 mov EAX,EBX
 add EAX,EDX
 cmp ECX,EAX
  jl strPosERROR
//-----------------
 dec EDX
//------------------------------------------
strPosDO:
//------------------------------------------
 mov ESI,alpfnd
 mov EDI,alpsrc
 mov AL,[ESI]
 cmp AL,[EDI+EBX]
 jne strPosNEXT
 add EDI,EBX
 mov ECX,fnd_size
 cld
repe CMPSB
 je  strPosFOUND
//-----------------
strPosNEXT:
//-----------------
 inc EBX
 mov EAX,EBX
 add EAX,EDX
 cmp EAX,a_src_size
  jl strPosDO
 jmp strPosERROR
//------------------------------------------
strPosFOUND:
 mov EAX,EBX
 jmp strPosBREAK
strPosERROR:
 mov EAX,-1
 jmp strPosBREAK
strPosBREAK:
//------------------------------------------
}
#else
    if (a_start > a_src_size)
        return -1;
    register size_t isrc_size  = a_src_size - a_start;
    register size_t isrc = 0;
    register size_t ifnd_size  = fnd_size;
    register size_t ifnd = 0;
    if (ifnd_size > isrc_size)
        return -1;
    register size_t imax_start = isrc_size - ifnd_size;
    register char *src = &((char*)alpsrc)[a_start];
    register char *fnd = &((char*)alpfnd)[0];
    for ( ; isrc <= imax_start; isrc++, src = &src[1]) {
        for (;;) {
            if (src[ifnd]!=fnd[ifnd])
                break;
            if (++ifnd >= ifnd_size)  return a_start + isrc;
        }
    }
    return -1;

#endif
}
//---------------------------------------------------------------------------

__declspec(dllexport) char *__stdcall strSub(char *alpdst,const char *alpsrc, long astart, long alength)
{
strnMov(alpdst,(char*)((long)alpsrc+astart),alength);
alpdst[alength] = 0;
return alpdst;
}
//---------------------------------------------------------------------------

__declspec(dllexport) char *__stdcall strSubEnd(char *alpdst,const char *alpsrc, long astart, long aend)
{
strnMov(alpdst,(char*)((long)alpsrc+astart),aend-astart);
alpdst[aend-astart] = 0;
return alpdst;
}
//---------------------------------------------------------------------------

__declspec(dllexport) long __stdcall strDelimiter(const char *alpsrc, char adelimiter, long adirection)
{
if (adirection < 0)
	{for (long pos = (long)strLen(alpsrc)-1; pos >= 0; pos--)
		 if (alpsrc[pos]==adelimiter)
			 return pos;
	 return -1;
	}
else
	{for (long pos = 0; pos < (long)strLen(alpsrc); pos++)
		 if (alpsrc[pos]==adelimiter)
				return pos;
	 return -1;
	}
}
//---------------------------------------------------------------------------

__declspec(dllexport) char *__stdcall strExchange(char *alpdst,const char *alpfnd,const char *alpexh)
{
for (long pos = 0, find, lenco = strLen(alpfnd), lennaco = strLen(alpexh), lencel = strLen(alpdst); pos < lencel; pos = find+lennaco)
	{
	 if ((find=strPos(alpdst, pos, alpfnd))==-1)
		 break;
		 strDel(alpdst, find, lenco);
	 strInsert(alpdst, find, alpexh);
	}
return alpdst;
}
//---------------------------------------------------------------------------

__declspec(dllexport) char *__stdcall strExchangeChar(char *alpdst, char alpfnd, char alpexh)
{
for (long pos = 0, lencel = strlen(alpdst); pos < lencel; pos++)
	{
	 if (alpdst[pos]==alpfnd) alpdst[pos] =alpexh;
	}
return alpdst;
}
//---------------------------------------------------------------------------

__declspec(dllexport) char *__stdcall strExtractFileRoot(char *alpdst,const char *alpsrc)
{
long lensrc = strlen(alpsrc), b = 0, delimiter;

if (lensrc==0)
	{alpdst[0]='\0';
	 return alpdst;
	}
while (b < lensrc ? alpsrc[b]=='\"' || alpsrc[b]==' ' : false)
{   b++;
}
delimiter = lensrc;

while (delimiter < lensrc ? alpsrc[delimiter]!='\\' : false)
{   delimiter++;
}

if (delimiter > b)
	{ptrMov(alpdst,&alpsrc[b],delimiter-b+1);
    }
alpdst[delimiter-b]='\0';
return alpdst;
}
//---------------------------------------------------------------------------

__declspec(dllexport) char *__stdcall strExtractFilePath(char *alpdst,const char *alpsrc)
{
long lensrc = strlen(alpsrc), e = lensrc, b = 0, delimiter;

if (lensrc==0)
	{alpdst[0]='\0';
	 return alpdst;
	}
while (e > 0 ? alpsrc[e-1]=='\"' || alpsrc[e-1]=='\\' || alpsrc[e-1]==' ' : false)
{   e--;
}
while (b < e ? alpsrc[b]=='\"' || alpsrc[b]==' ' : false)
{   b++;
}
delimiter = e;

while (delimiter > 0 ? alpsrc[delimiter]!='\\' : false)
{   delimiter--;
}

if (delimiter-b>0)
	{ptrMov((void*)alpdst,(void*)&alpsrc[b],delimiter-b+1);
    }
alpdst[delimiter-b]='\0';
return alpdst;
}
//---------------------------------------------------------------------------

__declspec(dllexport) char *__stdcall strExtractFileName(char *alpdst,const char *alpsrc)
{
long lensrc = strlen(alpsrc), e = lensrc, b = 0, delimiter;

if (lensrc==0)
	{alpdst[0]='\0';
	 return alpdst;
	}
while (e > 0 ? alpsrc[e-1]=='\"' || alpsrc[e-1]=='\\' || alpsrc[e-1]==' ' : false)
{   e--;
}
while (b < e ? alpsrc[b]=='\"' || alpsrc[b]==' ' : false)
{   b++;
}
delimiter = e;

while (delimiter > 0 ? alpsrc[delimiter-1]!='\\' : false)
{   delimiter--;
}

if (e-delimiter>0)
	{ptrMov((void*)alpdst,(void*)&alpsrc[delimiter],e-delimiter+1);
    }
alpdst[e-delimiter]='\0';
return alpdst;
 }
//---------------------------------------------------------------------------

__declspec(dllexport) char *__stdcall strExtractFileExtt(char *alpdst,const char *alpsrc)
{
long lensrc = strlen(alpsrc), e = lensrc, b = 0, delimiter;

if (lensrc==0)
	{alpdst[0]='\0';
	 return alpdst;
	}
while (e > 0 ? alpsrc[e-1]=='\"' || alpsrc[e-1]=='\\' || alpsrc[e-1]==' ' : false)
{   e--;
}
while (b < e ? alpsrc[b]=='\"' || alpsrc[b]==' ' : false)
{   b++;
}
delimiter = e;

while (delimiter > 0 ? alpsrc[delimiter-1]!='\\' && alpsrc[delimiter-1]!='.'  : false)
{   delimiter--;
}
if (alpsrc[delimiter]=='\\') {
    alpdst[0]='\0';
    return alpdst;
}

if (e-delimiter>0)
	{ptrMov((void*)alpdst,(void*)&alpsrc[delimiter],e-delimiter+1);
    }
alpdst[e-delimiter]='\0';
return alpdst;
 }
//---------------------------------------------------------------------------

__declspec(dllexport) char *__stdcall strFixFilePath(char *alpdst,const char *alpsrc)
{
long lensrc = strlen(alpsrc), e = lensrc, b = 0;

if (lensrc==0)
	{alpdst[0]='\0';
	 return alpdst;
	}
while (e > 0 ? alpsrc[e-1]=='\"' || alpsrc[e-1]=='\\' || alpsrc[e-1]==' ' : false)
{   e--;
}
while (b < e ? alpsrc[b]=='\"' || alpsrc[b]==' ' : false)
{   b++;
}
if (e-b > 0) strnMov(alpdst,&alpsrc[b],e-b);
alpdst[e-b]='\0'; return alpdst;
}
//---------------------------------------------------------------------------
#include <stdlib.h>

__declspec(dllexport) char *__stdcall intToStr(long aint)
{
static char str[32];
return std::itoa(aint,str,10);
}
//---------------------------------------------------------------------------

long   __stdcall strToInt(const char *alpsrc)
{
#if (__BORLANDC__ > 0x551) || defined(_MSC_VER)
__asm {
//lenght
 xor EAX,EAX
 xor EBX,EBX
 xor ESI,ESI
 mov EDI,alpsrc
//spacja
 mov AL,' '
repe SCASB
  jz strToIntX
 dec EDI
//plus minus
strToIntPLUS:
 mov AL,'+'
 cmp AL,[EDI]
 jne strToIntSIGN
 inc EDI
strToIntSIGN:
 mov AL,'-'
 cmp AL,[EDI]
 jne strToIntLOOP
 inc EDI
 not ESI
//liczba
strToIntLOOP:
 mov AL,[EDI]
 cmp AL,'0'
  jl strToIntX
 cmp AL,'9'
  ja strToIntX
 sub AL,'0'

push EAX
 mov EAX,10
 mul EBX
 mov EBX,EAX
 pop EAX
 add EBX,EAX
 inc EDI
 jmp strToIntLOOP

strToIntX:
test ESI,ESI
  jz strToIntRET
 neg EBX
strToIntRET:
 mov EAX,EBX
}
#else
return atol(alpsrc);
#endif
}
//---------------------------------------------------------------------------

__declspec(dllexport) void *__stdcall ptrAlloc(long acount)
{
return (void*)LocalAlloc(LPTR,acount);
}
//---------------------------------------------------------------------------

__declspec(dllexport) void *__stdcall ptrReAlloc(void *alpdst, long acount)
{
return (void*)LocalReAlloc(alpdst,acount,LMEM_MOVEABLE);
}
//---------------------------------------------------------------------------

__declspec(dllexport) void __stdcall ptrFree(void *alpdst)
{
LocalFree(alpdst);
}
//---------------------------------------------------------------------------

__declspec(dllexport) void __stdcall ptrRev(void *alpdst,const void *alpsrc,long acount) {
#if (__BORLANDC__ > 0x551) || defined(_MSC_VER)
__asm {
 mov ESI,alpsrc
 mov EDI,alpdst
 mov ECX,EDI
 add EDI,acount
 dec EDI
 cmp EDI,ECX
 jle ptrRev_EXIT
ptrRev_LOOP:
 mov  AL,[ESI]
 inc ESI
 mov [EDI],AL
 dec EDI
 cmp EDI,ECX
 jnl ptrRev_LOOP
ptrRev_EXIT:
    }
#else
      register char *r_src_start = (char*)alpsrc;
      register char *r_src_end = r_src_start + acount - 1;
      register char *r_dst_start = (char*)alpdst;
      register char *r_dst_end = r_dst_start + acount - 1;
      register char  a;

      for (; r_src_start < r_src_end; r_src_start++, r_src_end--, r_dst_start++, r_dst_end--) {
            a = *r_src_start;
            *r_dst_start = *r_src_end;
            *r_dst_end = a;
      }
#endif
}
//---------------------------------------------------------------------------

__declspec(dllexport) void __stdcall ptrMov(void *alpdst,const void *alpsrc,long acount) {
#if (__BORLANDC__ > 0x551) || defined(_MSC_VER)
__asm {
 mov ESI,alpsrc
 mov EDI,alpdst
 mov ECX,acount
 mov EAX,ECX
 cmp EDI,ESI
 jb  ptrMovINC
 jz  ptrMovEXIT
ptrMovDEC:
 lea ESI,[ESI+ECX-1]
 lea EDI,[EDI+ECX-1]
 and ECX,3
 std
 rep MOVSB
 mov ECX,EAX
 shr ECX,2
 sub ESI,3
 sub EDI,3
 rep MOVSD
 cld
 jmp ptrMovEXIT
ptrMovINC:
 shr ECX,2
 cld
 rep MOVSD
 mov ECX,EAX
 and ECX,3
 rep MOVSB
ptrMovEXIT:
	}
#else
memmove(alpdst,alpsrc,acount);
#endif
}
//---------------------------------------------------------------------------

void __stdcall ptrSet(void *alpdst,char aznakb, long acount) {
#if (__BORLANDC__ > 0x551) || defined(_MSC_VER)
__asm {
 mov EDI,alpdst
 mov ECX,acount
 mov  AL,aznakb
 cld
 rep STOSB
}
#else
memset(alpdst,aznakb,acount);
#endif
}
//---------------------------------------------------------------------------

__declspec(dllexport) void __stdcall ptrSetEx(void *alpdst,const void *alpsrc,unsigned char aesize, long acount) {
#if (__BORLANDC__ > 0x551) || defined(_MSC_VER)
__asm {
//------------------------------------------
 xor EAX,EAX
 xor EBX,EBX
 xor EDX,EDX
 mov ESI,alpsrc
 mov  BL,aesize
//-------------------
SETMCODE_00:
//-------------------
 mov  AL,[ESI+0]
 cmp  BL, 1
 jbe SETMCODE_XX
//-------------------
SETMCODE_01:
//-------------------
 mov  AH,[ESI+1]
 cmp  BL, 2
 jbe SETMCODE_XX
//-------------------
SETMCODE_02:
//-------------------
bswap EAX
 mov  AH,[ESI+2]
bswap EAX
 cmp  BL, 3
 jbe SETMCODE_XX
//-------------------
SETMCODE_03:
//-------------------
bswap EAX
 mov  AL,[ESI+3]
bswap EAX
//-------------------
SETMCODE_XX:
//------------------------------------------<< prepare
SETMPREP:
 mov EDI,alpdst
 mov ECX,acount
//------------------------------------------<< move  8BIT
 cmp  BL,1
 jne SETEXBIT_08_BREAK
SETEXBIT_08:
 cld
 rep stosb
 jmp SETEXBIT_XX_BREAK
//-------------------
SETEXBIT_08_BREAK:
//------------------------------------------<< move 16BIT
 cmp  BL,2
 jne SETEXBIT_16_BREAK
SETEXBIT_16:
 cld
 rep stosw
 jmp SETEXBIT_XX_BREAK
//-------------------
SETEXBIT_16_BREAK:
//------------------------------------------<< move 24BIT
 cmp  BL,3
 jne SETEXBIT_24_BREAK
test ECX,ECX
  jz SETEXBIT_XX_BREAK
SETEXBIT_24:
 stosb
 ror EAX,8
 stosw
 rol EAX,8
 dec ECX
test ECX,ECX
 jnz SETEXBIT_24
 jmp SETEXBIT_XX_BREAK
//-------------------
SETEXBIT_24_BREAK:
//------------------------------------------<< move 32BIT
 cmp  BL,4
 jne SETEXBIT_32_BREAK
SETEXBIT_32:
 cld
 rep stosd
 jmp SETEXBIT_XX_BREAK
//-------------------
SETEXBIT_32_BREAK:
SETEXBIT_XX_BREAK:
}
#else

#endif
}
//---------------------------------------------------------------------------

__declspec(dllexport) void __stdcall ptrShl(void *alpdst,long acount) {
#if (__BORLANDC__ > 0x551) || defined(_MSC_VER)
__asm {
 mov ECX,acount
 mov EAX,ECX
 mov ESI,alpdst
 inc ESI
 mov EDI,alpdst
 shr ECX,2
 cld
 rep MOVSD
 mov ECX,EAX
 and ECX,3
 rep MOVSB
	}
#else
memmove(alpdst,(void*)((size_t)alpdst-1),acount);
#endif
}
//---------------------------------------------------------------------------

__declspec(dllexport) void __stdcall ptrShr(void *alpdst,long acount) {
#if (__BORLANDC__ > 0x551) || defined(_MSC_VER)
__asm {
 mov ESI,alpdst
 mov EDI,alpdst
 mov ECX,acount
 mov EAX,ECX
 inc EDI
 lea ESI,[ESI+ECX-1]
 lea EDI,[EDI+ECX-1]
 and ECX,3
 std
 rep MOVSB
 mov ECX,EAX
 shr ECX,2
 sub ESI,3
 sub EDI,3
 rep MOVSD
 cld
	}
#else
memmove(alpdst,(void*)((size_t)alpdst+1),acount);
#endif
}
//---------------------------------------------------------------------------

__declspec(dllexport) long __stdcall ptrCmp(void *alpdst,const void *alpsrc,long acount) {
#if (__BORLANDC__ > 0x551) || defined(_MSC_VER)
__asm {
  mov ESI,alpsrc
  mov EDI,alpdst
  mov ECX,acount
  mov EAX,ECX
  shr ECX,2
  cld
 repe cmpsd
	je ptrCmpD
  shl ECX,2
  add ECX,4
  sub ESI,4
  sub EDI,4
  sub EAX,ECX
ptrCmpD:
  mov ECX,EAX
  and ECX,3
 repe cmpsb
	je ptrCmpB
  inc ECX
  sub EAX,ECX
ptrCmpB:
}
#else
return memcmp(alpdst,alpsrc,acount);
#endif
}
//---------------------------------------------------------------------------

__declspec(dllexport) unsigned long __stdcall ptrSca(void *alpdst,char aznakb,long acount) {
#if (__BORLANDC__ > 0x551) || defined(_MSC_VER)
__asm {
  mov  AL,aznakb
  mov ECX,acount
  mov EDX,ECX
  mov EDI,alpdst
  cld
 repe SCASB
  jnz ptrScaDIF
  mov EAX,EDX
  jmp ptrScaBREAK
ptrScaDIF:
  inc ECX
  mov EAX,EDX
  sub EAX,ECX
ptrScaBREAK:
	 }
#else
return (size_t)memchr(alpdst,aznakb,acount)-(size_t)alpdst;
#endif
}
//---------------------------------------------------------------------------

__declspec(dllexport) long __stdcall ptrChr(const void *alpdst,char aznakb,long acount) {
#if (__BORLANDC__ > 0x551) || defined(_MSC_VER)
__asm {
  mov  AL,aznakb
  mov ECX,acount
  mov EDX,ECX
  mov EDI,alpdst
  cld
repne SCASB
	je ptrChrDIF
  mov EAX,0xFFFFFFFFL
  jmp ptrChrBREAK
ptrChrDIF:
  inc ECX
  mov EAX,EDX
  sub EAX,ECX
ptrChrBREAK:
	 }
#else
return (size_t)memchr(alpdst,aznakb,acount)-(size_t)alpdst;
#endif
}
//---------------------------------------------------------------------------

__declspec(dllexport) long __stdcall ptrFndLast(const char *alpsrc,long asrc_min,long asrc_size,const char *alpfnd,long aco_size) {
// metoda Boyera-Moroe
if (asrc_min+aco_size > asrc_size || aco_size<=0 || asrc_size<=0)
	 return -1;
static long ret_i,*lpret_i=&ret_i;
static unsigned __int8 shift[0x0100L],*lpshift=&shift[0];

if (aco_size>0xFFL) {
ptrSet(&shift,0x0100L,0xFFL);
for (long i=0xFFL-1; i >= 0; i--)
	{shift[ alpfnd[i] ]=(unsigned __int8)i;
	}
}
else {
ptrSet(&shift,0x0100L,aco_size);
for (long i=aco_size-1; i >= 0; i--)
	{shift[ alpfnd[i] ]=(unsigned __int8)i;
	}
}
#if (__BORLANDC__ > 0x551) || defined(_MSC_VER)
__asm {
 mov EDX,lpshift
 mov EAX,asrc_size
 sub EAX,aco_size
 cmp EAX,asrc_min
 jl  ptrFndLastX
ptrFndLastFIRST:
	 xor EBX,EBX
	 xor ECX,ECX
	 mov ESI,alpsrc
	 mov EDI,alpfnd
ptrFndLastDO:
	 mov BL,[ESI+EAX]
	 cmp BL,[EDI+0]
	 je  ptrFndLastCHECK
	 mov CL,[EDX+EBX]
	 sub EAX,ECX
	 cmp EAX,asrc_min
 jnl ptrFndLastDO

 jmp ptrFndLastX
ptrFndLastCHECK:
 add ESI,EAX
 mov ECX,aco_size
 cld
repe CMPSB
 jne ptrFndLastNEXT
	 mov  EDI ,lpret_i
	 mov [EDI],EAX
	 jmp ptrFndLastEQL
ptrFndLastNEXT:
 dec EAX
 cmp EAX,asrc_min
 jnl ptrFndLastFIRST

 jmp ptrFndLastX
	}
#endif
ptrFndLastEQL:
return ret_i;
ptrFndLastX:
return -1;
}
//---------------------------------------------------------------------------

__declspec(dllexport) long __stdcall ptrFnd(const char *alpsrc, long asrc_min, long asrc_size, const char *alpfnd, long aco_size) {
// metoda Boyera-Moroe
if (asrc_min+aco_size > asrc_size || aco_size<=0 || asrc_size<=0)
	 return -1;
static long ret_i,*lpret_i=&ret_i;
static unsigned __int8 shift[0x0100L],*lpshift=&shift[0];

if (aco_size>0xFFL) {
ptrSet(&shift,0x0100L,0xFFL);
for (long i=aco_size-0x0100L,ic=0x0100L; i < aco_size; i++,ic--)
	{shift[ alpfnd[i] ]=(unsigned __int8)(ic-1);
	}
}
else {
ptrSet(&shift,0x0100L,aco_size);
for (long i=0,ic=aco_size; i < aco_size; i++,ic--)
	{shift[ alpfnd[i] ]=(unsigned __int8)(ic-1);
	}
}
#if (__BORLANDC__ > 0x551) || defined(_MSC_VER)
__asm {
 mov EDX,aco_size
 dec EDX
 mov EAX,asrc_min
 add EAX,EDX
 cmp EAX,asrc_size
 jnl ptrFndX
ptrFndFIRST:
	 xor EBX,EBX
	 xor ECX,ECX
	 mov ESI,alpsrc
	 mov EDI,alpfnd
ptrFndDO:
	 mov BL,[ESI+EAX]
	 cmp BL,[EDI+EDX]
	 je  ptrFndCMP
	 mov ECX,lpshift
	 mov CL,[ECX+EBX]
	 and ECX,0xFFL
	 add EAX,ECX
	 cmp EAX,asrc_size
  jl ptrFndFIRST
 jmp ptrFndX
ptrFndCMP:
 add ESI,EAX
 mov ECX,aco_size
 sub ESI,ECX
 dec ESI
repe CMPSB
 jne ptrFndNEXT
	 sub EAX,EDX
	 mov EDI,lpret_i
	 mov [EDI],EAX
	 jmp ptrFndEQL
ptrFndNEXT:
 inc EAX
 cmp EAX,asrc_size
 jl  ptrFndFIRST
 jmp ptrFndX
	}
#endif
ptrFndEQL:
   return ret_i;
ptrFndX:
return -1;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------


#define PREPARE_FIRST_COPY()                                      \
    do {                                                          \
    if (src_len >= (8 - dst_offset_modulo)) {              \
        *dst     &= reverse_mask[dst_offset_modulo];              \
        src_len -= 8 - dst_offset_modulo;                  \
    } else {                                                      \
        *dst     &= reverse_mask[dst_offset_modulo]               \
              | reverse_mask_xor[dst_offset_modulo + src_len];    \
         c       &= reverse_mask[dst_offset_modulo + src_len];    \
        src_len = 0;                                              \
    } } while (0)


static void bitmov_helper(const unsigned char *src_org, int src_offset, unsigned char *dst_org, int dst_offset,int src_len)
{
    static const unsigned char mask[] =
        { 0x00, 0x01, 0x03, 0x07, 0x0f, 0x1f, 0x3f, 0x7f, 0xff };
    static const unsigned char reverse_mask[] =
        { 0x00, 0x80, 0xc0, 0xe0, 0xf0, 0xf8, 0xfc, 0xfe, 0xff };
    static const unsigned char reverse_mask_xor[] =
        { 0xff, 0x7f, 0x3f, 0x1f, 0x0f, 0x07, 0x03, 0x01, 0x00 };

    if (src_len) {
        const unsigned char *src;
              unsigned char *dst;
        int                  src_offset_modulo,
                             dst_offset_modulo;

        src = src_org + (src_offset / 8);
        dst = dst_org + (dst_offset / 8);

        src_offset_modulo = src_offset % 8;
        dst_offset_modulo = dst_offset % 8;

        if (src_offset_modulo == dst_offset_modulo) {
            int              byte_len;
            int              src_len_modulo;
            if (src_offset_modulo) {
                unsigned char   c;

                c = reverse_mask_xor[dst_offset_modulo]     & *src++;

                PREPARE_FIRST_COPY();
                *dst++ |= c;
            }

            byte_len = src_len / 8;
            src_len_modulo = src_len % 8;

            if (byte_len) {
                memcpy(dst, src, byte_len);
                src += byte_len;
                dst += byte_len;
            }
            if (src_len_modulo) {
                *dst     &= reverse_mask_xor[src_len_modulo];
                *dst |= reverse_mask[src_len_modulo]     & *src;
            }
        } else {
            int             bit_diff_ls,
                            bit_diff_rs;
            int             byte_len;
            int             src_len_modulo;
            unsigned char   c;
            /*
             * Begin: Line things up on destination.
             */
            if (src_offset_modulo > dst_offset_modulo) {
                bit_diff_ls = src_offset_modulo - dst_offset_modulo;
                bit_diff_rs = 8 - bit_diff_ls;

                c = *src++ << bit_diff_ls;
                c |= *src >> bit_diff_rs;
                c     &= reverse_mask_xor[dst_offset_modulo];
            } else {
                bit_diff_rs = dst_offset_modulo - src_offset_modulo;
                bit_diff_ls = 8 - bit_diff_rs;

                c = *src >> bit_diff_rs     &
                    reverse_mask_xor[dst_offset_modulo];
            }
            PREPARE_FIRST_COPY();
            *dst++ |= c;

            /*
             * Middle: copy with only shifting the source.
             */
            byte_len = src_len / 8;

            while (--byte_len >= 0) {
                c = *src++ << bit_diff_ls;
                c |= *src >> bit_diff_rs;
                *dst++ = c;
            }

            /*
             * End: copy the remaing bits;
             */
            src_len_modulo = src_len % 8;
            if (src_len_modulo) {
                c = *src++ << bit_diff_ls;
                c |= *src >> bit_diff_rs;
                c     &= reverse_mask[src_len_modulo];

                *dst     &= reverse_mask_xor[src_len_modulo];
                *dst |= c;
            }
        }
    }
}
//---------------------------------------------------------------------------

__declspec(dllexport) void __stdcall bitMov(void *alpdst,unsigned char adst_bit,const void *alpsrc,unsigned char asrc_bit,unsigned long abit_num)
{
#if (__BORLANDC__ > 0x551) || defined(_MSC_VER)
__asm {
//------------------------------------------
 mov  BL,asrc_bit
 mov ESI,alpsrc
 mov  BH,adst_bit
 mov EDI,alpdst
 mov EDX,abit_num
//------------------------------------------<< can just move?
 cmp  BX,0
 jnz BIT_REP_BREAK
 cmp EDX,8
  jb BIT_REP_01
BIT_REP_32:
 mov ECX,EDX
 shr ECX,5
 cld
 rep MOVSD
 mov ECX,EDX
 shr ECX,3
 and ECX,3
 rep MOVSB
BIT_REP_01:
 and  DL,8-1
  jz BIT_XX_BREAK
 mov  CL,DL
 mov  AX,0xFF00
 rol  AX,CL
 mov  BL,[ESI]
 and  AL,BL
 mov  [EDI],AL
 jmp BIT_XX_BREAK
//-------------------
BIT_REP_BREAK:
//------------------------------------------<< make dst existing bits mask
 mov  CL,BH
 mov  CH,0x01
 shl  CH,CL
 dec  CH
//------------------------------------------<< move 24BIT by 24BIT
 cmp EDX,24
 jbe BIT_24_BREAK
BIT_24_LOOP:
 sub EDX,24

 mov EAX,[ESI+0]
 mov  CL,BL
 shr EAX,CL
 and EAX,0x00FFFFFF
 mov  CL,BH
 shl EAX,CL
 mov  CL,[EDI+0]
 and  CL,CH
 xor  AL,CL
 mov [EDI+0],EAX

 add ESI, 3
 add EDI, 3
 cmp EDX,24
  ja BIT_24_LOOP
//-------------------
BIT_24_BREAK:
//------------------------------------------<< move 8BIT by 8BIT
 cmp EDX,8
 jbe BIT_08_BREAK
BIT_08_LOOP:
 sub EDX,8

 mov  AX,[ESI+0]
 mov  CL,BL
 shr  AX,CL
 and  AX,0x00FF
 mov  CL,BH
 shl  AX,CL
 mov  CL,[EDI+0]
 and  CL,CH
 xor  AL,CL
 mov  [EDI+0],AX

 add ESI, 1
 add EDI, 1
 cmp EDX, 8
  ja BIT_08_LOOP
//-------------------
BIT_08_BREAK:
//------------------------------------------<< move remained BITS
 cmp EDX,0
 jna BIT_XX_BREAK
BIT_XX:
 mov  CH,0x08
 sub  CH,DL
ESI_00:
 mov  AL,[ESI+0]
 cmp  BL,CH
 jna ESI_XX
ESI_01:
 mov  AH,[ESI+1]
ESI_XX:
 mov  CL,CH
 mov EDX,0x000000FF
 shr  DX,CL
 mov  CL,BL
 shr  AX,CL
 and EAX,EDX
 mov  CL,BH
 shl  AX,CL
 mov EDX,0x0000FF00
 rol  DX,CL
 mov  CL,[EDI]
 and  CL,DL
 xor  AL,CL
EDI_00:
 mov [EDI+0],AL
 cmp  BH,CH
 jna EDI_XX
EDI_01:
 mov [EDI+1],AH
EDI_XX:
//------------------------------------------<< EXITING POINTS
BIT_XX_BREAK:
}
#else
bitmov_helper((unsigned char*)alpdst,adst_bit,(unsigned char*)alpsrc,asrc_bit,abit_num);
#endif
}
//---------------------------------------------------------------------------

__declspec(dllexport) void __stdcall bitSet(void *alpdst,const void *alpsrc,unsigned char asrc_bit,unsigned char asrc_elsize,unsigned long adst_count)
{
#if (__BORLANDC__ > 0x551) || defined(_MSC_VER)
__asm {
//------------------------------------------
 mov ESI,alpsrc
 mov  BH,asrc_bit
 mov  BL,asrc_elsize
 xor EAX,EAX
 xor EDX,EDX
//-------------------
MCODE_SS:
 mov  CH,BL
 shl  CH,3
 add  CH,BH
MCODE_00:
 mov  DL,[ESI+0]
 cmp  CH, 8
 jbe MSHRD_32
MCODE_01:
 mov  DH,[ESI+1]
 cmp  CH,16
 jbe MSHRD_32
//-------------------
shrd EAX,EDX,16
 xor EDX,EDX
MCODE_02:
 mov  DL,[ESI+2]
 cmp  CH,24
 jbe MSHRD_16
MCODE_03:
 mov  DH,[ESI+3]
 cmp  CH,32
 jbe MSHRD_16
//-------------------
shrd EAX,EDX,16
 xor EDX,EDX
MCODE_04:
 mov  DL,[ESI+4]
 jmp MSHRD_00
MCODE_XX:
//-------------------
MSHRD_32:
shrd EAX,EDX,16
 xor EDX,EDX
MSHRD_16:
shrd EAX,EDX,16
 xor EDX,EDX
MSHRD_00:
//-------------------
MPREP:
 mov  CL,BH
shrd EAX,EDX,CL
 mov EDI,alpdst
 mov ECX,adst_count
 xor  BH,BH
//------------------------------------------<< move 8BIT by 8BIT
 cmp EBX,1
 jne BITSET_08_BREAK
BITSET_08:
 cld
 rep stosb
 jmp BITSET_XX_BREAK
//-------------------
BITSET_08_BREAK:
//------------------------------------------<< move 16BIT by 16BIT
 cmp EBX,2
 jne BITSET_16_BREAK
BITSET_16:
 cld
 rep stosw
 jmp BITSET_XX_BREAK
//-------------------
BITSET_16_BREAK:
//------------------------------------------<< move 24BIT by 24BIT
 cmp EBX,3
 jne BITSET_24_BREAK
test ECX,ECX
  jz BITSET_XX_BREAK
BITSET_24:
 stosb
 ror EAX,8
 stosw
 rol EAX,8
 dec ECX
test ECX,ECX
 jnz BITSET_24
 jmp BITSET_XX_BREAK
//-------------------
BITSET_24_BREAK:
//------------------------------------------<< move 32BIT by 32BIT
 cmp EBX,4
 jne BITSET_32_BREAK
BITSET_32:
 cld
 rep stosd
 jmp BITSET_XX_BREAK
//-------------------
BITSET_32_BREAK:
//------------------------------------------<< return number of bits
BITSET_XX_BREAK:
}
#else
    register size_t bits = adst_count * 8;
    register void *src = (void*)alpsrc;
    register unsigned __int8 dst_bit = asrc_bit;
    register char *dst = (char*)alpdst;
    register __int32 aku,zr;
    while (bits> 0) {
        for (zr=0; zr < asrc_elsize; zr++) {
            aku = ((char*)src)[zr];
            dst[0] = (dst[0] && (0xFFL>>dst_bit)) | ((aku<<dst_bit) && (0xFFL<<dst_bit));
            dst = &dst[1];
            src = &dst[1];
            bits-=8;
        }
    }
#endif
}

