//---------------------------------------------------------------------------
//-----------------Stanislaw Stasiak "TSoft_, where?" 2001-2002---------------
//---------------------------------------------------------------------------
#include <windows.h>
#pragma hdrstop
#include "TSoft_IO.h"
//---------------------------------------------------------------------------

char *__stdcall strAlloc(long alength)
{
return (char*)LocalAlloc(LPTR,alength);
}
//---------------------------------------------------------------------------

char *__stdcall strAllocEx(long alength, char *alpsrc)
{
return strEql(strAlloc(alength),alpsrc);
}
//---------------------------------------------------------------------------

char *__stdcall strReAlloc(char *alpdst, long alength)
{
return (char*)LocalReAlloc(alpdst,alength,LMEM_MOVEABLE);
}
//---------------------------------------------------------------------------

char *__stdcall strReAllocEx(char *alpdst, long alength, char *alpsrc)
{
return strEql(strReAlloc(alpdst,alength),alpsrc);
}
//---------------------------------------------------------------------------

void __stdcall strFree(char *alpdst)
{
LocalFree(alpdst);
}
//---------------------------------------------------------------------------

char *__stdcall strDup(char *alpdst)
{
return strEql(strAlloc(strLen(alpdst)+1),alpdst);
}
//---------------------------------------------------------------------------

char *__stdcall strReDup(char *alpdst, char *alpsrc)
{
return strEql(strReAlloc(alpdst,strLen(alpsrc)+1),alpsrc);
}
//---------------------------------------------------------------------------

long __stdcall strLen(char *alpdst) {
 __asm {
  mov EDI,alpdst
  mov ESI,EDI
  mov ECX,0xFFFFFFFF
  xor EAX,EAX
  cld
repnz SCASB
  not ECX
  dec ECX
  mov EAX,ECX
}
}
//---------------------------------------------------------------------------

char *__stdcall strEql(char *alpdst,char *alpsrc)
{
ptrEql(alpdst,alpsrc,strLen(alpsrc)+1);
return alpdst;
}
//---------------------------------------------------------------------------

char *__stdcall strMov(char *alpdst, char *alpsrc)
{
ptrMov(alpdst,alpsrc,strLen(alpsrc)+1);
return alpdst;
}
//---------------------------------------------------------------------------

char *__stdcall strnEql(char *alpdst,char *alpsrc,long alength)
{
ptrEql(alpdst,alpsrc,alength);
return alpdst;
}
//---------------------------------------------------------------------------

char *__stdcall strnMov(char *alpdst,char *alpsrc,long alength)
{
ptrMov(alpdst,alpsrc,alength);
return alpdst;
}
//---------------------------------------------------------------------------

char *__stdcall strAdd(char *alpdst, char *alpsrc)
{
return strcat(alpdst,alpsrc);
}
//---------------------------------------------------------------------------

char *__stdcall strInsert(char *alpdst, long astart, char *ainsert)
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

char *__stdcall strDel(char *alpdst, long astart, long alength)
{
strnEql((char*)((long)alpdst+astart),(char*)((long)alpdst+astart+alength),strLen(alpdst)-astart-alength);
alpdst[strlen(alpdst)-alength] = 0;
return alpdst;
}
//---------------------------------------------------------------------------

char *__stdcall strDelEnd(char *alpdst, long astart, long aend)
{
strnEql((char*)((long)alpdst+astart),(char*)((long)alpdst+aend),strLen(alpdst)-aend);
alpdst[strlen(alpdst)-(aend-astart)] = 0;
return alpdst;
}
//---------------------------------------------------------------------------

long __stdcall strPos(char *alpsrc, long abegin, char *alpfnd)
{
long src_size = strLen(alpsrc), fnd_size = strLen(alpfnd);
__asm {
//------------------------------------------
 mov EDX,fnd_size
 cmp EDX,0
 jle strPosERROR
//-----------------
 mov ECX,src_size
 cmp ECX,0
 jle strPosERROR
//-----------------
 mov EBX,abegin
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
 cmp EAX,src_size
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
}
//---------------------------------------------------------------------------

char *__stdcall strSub(char *alpdst, char *alpsrc, long astart, long alength)
{
strnEql(alpdst,(char*)((long)alpsrc+astart),alength);
alpdst[alength] = 0;
return alpdst;
}
//---------------------------------------------------------------------------

char *__stdcall strSubEnd(char *alpdst, char *alpsrc, long astart, long aend)
{
strnEql(alpdst,(char*)((long)alpsrc+astart),aend-astart);
alpdst[aend-astart] = 0;
return alpdst;
}
//---------------------------------------------------------------------------

long __stdcall strDelimiter(char *alpsrc, char adelimiter, long adirection)
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

char *__stdcall strExchange(char *alpdst, char *alpfnd, char *alpexh)
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

char *__stdcall strExchangeChar(char *alpdst, char alpfnd, char alpexh)
{
for (long pos = 0, lencel = strlen(alpdst); pos < lencel; pos++)
	{
	 if (alpdst[pos]==alpfnd) alpdst[pos] =alpexh;
	}
return alpdst;
}
//---------------------------------------------------------------------------

char *__stdcall strExtractFileRoot(char *alpdst, char *alpsrc)
{
int delimiter = strDelimiter(alpsrc,'\\',+1);

if (delimiter>=0)
	{return strSubEnd(alpdst,alpsrc,0,delimiter);
	}
else
if ((long)alpdst!=(long)alpsrc)
	{return (char*)strnEql(alpdst,alpsrc,strlen(alpsrc)+1);
	}
else
	{alpdst[strLen(alpsrc)]='\0';
	 return alpdst;
	}
}
//---------------------------------------------------------------------------

char *__stdcall strExtractFilePath(char *alpdst, char *alpsrc)
{
int delimiter = strDelimiter(alpsrc,'\\',-1);

if (delimiter>=0)
	{return strSubEnd(alpdst,alpsrc,0,delimiter);
	}
else
if ((long)alpdst!=(long)alpsrc)
	{return (char*)strnEql(alpdst,alpsrc,strlen(alpsrc)+1);
	}
else
	{alpdst[strLen(alpsrc)]='\0';
	 return alpdst;
	}
}
//---------------------------------------------------------------------------

char *__stdcall strExtractFileName(char *alpdst, char *alpsrc)
{
long delimiter = strDelimiter(alpsrc, '\\',-1);

if (delimiter>=0)
	{return strSubEnd(alpdst,alpsrc,delimiter+1, strlen(alpsrc));
	}
else
if ((long)alpdst!=(long)alpsrc)
	{return (char*)strnEql(alpdst,alpsrc,strlen(alpsrc)+1);
	}
else
	{alpdst[strLen(alpsrc)]='\0';
	 return alpdst;
	}
 }
//---------------------------------------------------------------------------

char *__stdcall strFixFilePath(char *alpdst, char *alpsrc)
{
long lensrc = strlen(alpsrc);

if (lensrc==0)
	{alpdst[0]='\0';
	 return alpdst;
	}
else
if (alpsrc[lensrc-1]=='\\')
	{if ((long)alpdst!=(long)alpsrc)
		strnEql(alpdst,alpsrc,lensrc-1);
	 alpdst[lensrc-1]='\0';
	 return alpdst;
	}
else
	{if ((long)alpdst!=(long)alpsrc)
		strnEql(alpdst,alpsrc,lensrc);
	 alpdst[lensrc]='\0';
	 return alpdst;
	}
}
//---------------------------------------------------------------------------
#include <stdlib.h>

char *__stdcall intToStr(long aint)
{
static char str[32];
return std::itoa(aint,str,10);
}
//---------------------------------------------------------------------------

long   __stdcall strToInt(char *asrc)
{
return atol(asrc);
/*__asm {
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
*/}
//---------------------------------------------------------------------------

void *__stdcall ptrAlloc(long acount)
{
return (void*)LocalAlloc(LPTR,acount);
}
//---------------------------------------------------------------------------

void *__stdcall ptrReAlloc(void *alpdst, long acount)
{
return (void*)LocalReAlloc(alpdst,acount,LMEM_MOVEABLE);
}
//---------------------------------------------------------------------------

void __stdcall ptrFree(void *alpdst)
{
LocalFree(alpdst);
}
//---------------------------------------------------------------------------

void __stdcall ptrEql(void *alpdst,void *alpsrc,long acount) {
__asm {
 mov ESI,alpsrc
 mov EDI,alpdst
 mov ECX,acount
 mov EAX,ECX
 shr ECX,2
 cld
 rep MOVSD
 mov ECX,EAX
 and ECX,3
 rep MOVSB
	}
}
//---------------------------------------------------------------------------

void __stdcall ptrRev(void *alpdst,void *alpsrc,long acount) {
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
}
//---------------------------------------------------------------------------

void __stdcall ptrMov(void *alpdst,void *alpsrc,long acount) {
__asm {
 mov ESI,alpsrc
 mov EDI,alpdst
 mov ECX,acount
 mov EAX,ECX
 cmp EDI,ESI
 jb  ptrMovINC
 jz  ptrMovX

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
 jmp ptrMovX

ptrMovINC:
 shr ECX,2
 cld
 rep MOVSD
 mov ECX,EAX
 and ECX,3
 rep MOVSB

ptrMovX:
	}
}
//---------------------------------------------------------------------------

void __stdcall ptrSet(void *alpdst, char aznakb, long acount) {
__asm {
 mov EDI,alpdst
 mov ECX,acount
 mov  AL,aznakb
 cld
 rep STOSB
}
}
//---------------------------------------------------------------------------

void __stdcall ptrSetEx(void *alpdst, void *alpsrc,unsigned char aesize, long acount) {
__asm {
//------------------------------------------
 xor EAX,EAX
 xor EBX,EBX
 xor EDX,EDX
 mov ESI,alpsrc
 mov  BL,aesize
//-------------------
MCODE_00:
//-------------------
 mov  AL,[ESI+0]
 cmp  BL, 1
 jbe MCODE_XX
//-------------------
MCODE_01:
//-------------------
 mov  AH,[ESI+1]
 cmp  BL, 2
 jbe MCODE_XX
//-------------------
MCODE_02:
//-------------------
bswap EAX
 mov  AH,[ESI+2]
bswap EAX
 cmp  BL, 3
 jbe MCODE_XX
//-------------------
MCODE_03:
//-------------------
bswap EAX
 mov  AL,[ESI+3]
bswap EAX
//-------------------
MCODE_XX:
//------------------------------------------<< prepare
MPREP:
 mov EDI,alpdst
 mov ECX,acount
//------------------------------------------<< move  8BIT
 cmp  BL,1
 jne BIT_08_BREAK
BIT_08:
 cld
 rep stosb
 jmp BIT_XX_BREAK
//-------------------
BIT_08_BREAK:
//------------------------------------------<< move 16BIT
 cmp  BL,2
 jne BIT_16_BREAK
BIT_16:
 cld
 rep stosw
 jmp BIT_XX_BREAK
//-------------------
BIT_16_BREAK:
//------------------------------------------<< move 24BIT
 cmp  BL,3
 jne BIT_24_BREAK
test ECX,ECX
  jz BIT_XX_BREAK
BIT_24:
 stosb
 ror EAX,8
 stosw
 rol EAX,8
 dec ECX
test ECX,ECX
 jnz BIT_24
 jmp BIT_XX_BREAK
//-------------------
BIT_24_BREAK:
//------------------------------------------<< move 32BIT
 cmp  BL,4
 jne BIT_32_BREAK
BIT_32:
 cld
 rep stosd
 jmp BIT_XX_BREAK
//-------------------
BIT_32_BREAK:
BIT_XX_BREAK:
}
}
//---------------------------------------------------------------------------

void __stdcall ptrShl(void *alpdst,long acount) {
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
}
//---------------------------------------------------------------------------

void __stdcall ptrShr(void *alpdst,long acount) {
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
}
//---------------------------------------------------------------------------
	  
long __stdcall ptrCmp(void *alpdst,void *alpsrc,long acount) {
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
}
//---------------------------------------------------------------------------
						
long __stdcall ptrSca(void *alpdst,char aznakb,long acount) {
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
}
//---------------------------------------------------------------------------

long __stdcall ptrChr(void *alpdst,char aznakb,long acount) {
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
}
//---------------------------------------------------------------------------

long __stdcall ptrFndLast(char *alpsrc, long asrc_min, long asrc_size,char *alpfnd, long aco_size) {
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
ptrFndLastEQL:
	return ret_i;
ptrFndLastX:
return -1;
}
//---------------------------------------------------------------------------

long __stdcall ptrFnd(char *alpsrc, long asrc_min, long asrc_size,char *alpfnd, long aco_size) {
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
ptrFndEQL:
   return ret_i;
ptrFndX:
return -1;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

void __stdcall bitEql(void *alpdst,unsigned char adst_bit,void *alpsrc,unsigned char asrc_bit,unsigned long abit_num)
{
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
}
//---------------------------------------------------------------------------

void __stdcall bitSet(void *alpdst,void *alpsrc,unsigned char asrc_bit,unsigned char asrc_elsize,unsigned long adst_count)
{
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
 jne BIT_08_BREAK
BIT_08:
 cld  
 rep stosb
 jmp BIT_XX_BREAK
//-------------------
BIT_08_BREAK:
//------------------------------------------<< move 16BIT by 16BIT
 cmp EBX,2
 jne BIT_16_BREAK
BIT_16:
 cld
 rep stosw
 jmp BIT_XX_BREAK
//-------------------
BIT_16_BREAK:
//------------------------------------------<< move 24BIT by 24BIT
 cmp EBX,3
 jne BIT_24_BREAK
test ECX,ECX
  jz BIT_XX_BREAK
BIT_24:
 stosb
 ror EAX,8 
 stosw
 rol EAX,8
 dec ECX
test ECX,ECX
 jnz BIT_24
 jmp BIT_XX_BREAK
//-------------------
BIT_24_BREAK:  
//------------------------------------------<< move 32BIT by 32BIT
 cmp EBX,4
 jne BIT_32_BREAK
BIT_32:
 cld
 rep stosd
 jmp BIT_XX_BREAK
//-------------------
BIT_32_BREAK:
//------------------------------------------<< return number of bits
BIT_XX_BREAK:
}
}
//---------------------------------------------------------------------------
/*ptrEql_MMX:
  cmp EAX,32
  jle ptrEql_MMX_BREAK
  sub EAX,32
 movq mm0,[ESI]
 movq mm1,[ESI+8]
 movq mm2,[ESI+8+8]
 movq mm3,[ESI+8+8+8]
  add ESI,32
 movq [EDI],mm0
 movq [EDI+8],mm1
 movq [EDI+8+8],mm2
 movq [EDI+8+8+8],mm3
  add EDI,32
  jmp ptrEql_MMX
ptrEql_MMX_BREAK:
 emms
*/
/*//------------------------------------------<< if, there MMX copy Q-7BYTES by Q-7BYTES
  cmp EDX,168           // 40_INSTR/168b
  jna BIT_MMX_NOT_NEADED
 push EAX
 push EDX
  mov EAX,1
cpuid
 test EDX,0x00800000   // IS, THERE MMX?
  pop EDX
  pop EAX
	jz BIT_MMX_ABSENT
  xor EAX,EAX
  mov  AL,BL
 movd MM0,EAX           
  mov  AL,BH
 movd MM1,EAX           
  mov  AL,CH
 movd MM2,EAX
 pxor MM3,MM3
  pcmpeqd MM3,MM3       
psrlq MM3,8             
//-------------------
  cmp EDX,168
  jmp BIT_MMX_BREAK
BIT_MMX:
  sub EDX,168

 movq MM5,[ESI+0x00-0]       
 movq MM6,[ESI+0x08-1]     
 movq MM7,[ESI+0x10-2]     

psrlq MM5,MM0        
 pand MM5,MM3           
psllq MM5,MM1
psrlq MM6,MM0
 pand MM6,MM3           
psllq MM6,MM1
psrlq MM7,MM0
 pand MM7,MM3           
psllq MM7,MM1

 movq MM4,[EDI]       
 pand MM4,MM2
  por MM5,MM4
 movq [EDI+0x00-0],MM5
psrlq MM5,64-8          
 pand MM5,MM2
  por MM6,MM5
 movq [EDI+0x80-1],MM6
psrlq MM6,64-8          
 pand MM6,MM2
  por MM7,MM6
 movq [EDI+0x10-2],MM7

  add ESI,21
  add EDI,21
  cmp EDX,168
	ja BIT_MMX
//-------------------
BIT_MMX_BREAK:
 emms
BIT_MMX_NOT_NEADED:
BIT_MMX_ABSENT:
*/

