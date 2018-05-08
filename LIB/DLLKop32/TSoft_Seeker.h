//---------------------------------------------------------------------------
//-----------------Stanislaw Stasiak "SSTSOFT.pl" 2001-2002------------------
// --------------------cos jak SHFileOperation(..., ...);--------------------
//---------------------------------------------------------------------------
#ifndef __TSoft_Kop32_HDR__
#define __TSoft_Kop32_HDR__
//---------------------------------------------------------------------------
#include "..\DLLDatabase\TSoft_Database.h"
//---------------------------------------------------------------------------
#include "TSoft_build_conf.h"
//---------------------------------------------------------------------------
#ifndef mrOk
#define mrOk		(DWORD)1
#define mrCancel	(DWORD)2
#define mrNo		(DWORD)7
#define mrNoToAll	(DWORD)9
#define mrYes		(DWORD)6
#define mrYesToAll 	(DWORD)10
#endif
//---------------------------------------------------------------------------
extern "C" {
//---------------------------------------------------------------------------
#define HEADER_SIG (WORD)'ZL'
typedef struct {
	  WORD sig;
	  WORD ver;

	 DWORD size;
	 DWORD attr;
	 DWORD time;
} __header;
#define BLOCK_HEADER_SIG (WORD)'LB'
typedef struct {
	  WORD sig;
	  WORD methods;

	 DWORD size[4];
     DWORD range;
     DWORD crc32;
} __block_header;
#define AID_HEADER_SIG (WORD)'AD'
typedef struct {
	  WORD sig;
	  WORD methods;

	 DWORD size[4];
     DWORD range;
     DWORD crc32;
} __aid_header;
//------------------------------------
typedef struct {
	int Next;
	HANDLE Hand;
	WIN32_FIND_DATA Data;
} __find;
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
//------------------------------------
typedef struct {
	void *Lptr;
	unsigned __int32 Size, Offset;
} __buffer;
//------------------------------------
class __declspec(dllexport) TSoft_Kop32
{
//------------------------------------
private:
//------------------------------------
int  __stdcall FOnBreak		  	(int abrParam,int abrButtons);
int  __stdcall FOnError		  	(int aerParam,int aerButtons);
//------------------------------------
int  __stdcall SeekSrc			(char *alpStrSrc);
int  __stdcall SeekSrcFile	  	(char *alpStrSrc);
int  __stdcall SeekDst			(char *alpStrDst);
//------------------------------------
void __stdcall Clr				(void);
int  __stdcall Procede			(int aindex, int anaction);
int  __stdcall Skip				(int aindex, bool an_all_not_one);
//------------------------------------
__int64 __stdcall DiskSpace	(char *avolumin, __int64 abajtSrc, __int64 abajtDst, bool auntilPositive, bool acouldOmit);
//------------------------------------
__buffer mem_buffer[8];
  __int8 mem_index, mem_count;
__stack stack;
//------------------------------------
struct __file {
struct __destination {
	  __find find;
	HANDLE Hand, Hand_map;
	unsigned __int32 Read, Size; __int8 Percent;
	__buffer buffer;
}  src, dst;
} file;
//------------------------------------
struct __password {
	char  lpEnc[48], lpUsr[48];
	unsigned __int8  Size;
} password;
//------------------------------------
public:
//------------------------------------
#define opNULL			 (BYTE)0x00L
#define opKOPIUJ			 (BYTE)0x01L
#define opKODUJ		 (BYTE)0x02L
#define opDEKODUJ		 (BYTE)0x04L
#define opPRZENIES			 (BYTE)0x08L
#define opUSUN		 (BYTE)0x10L
#define opLISTUJ			 (BYTE)0x20L
#define opZAZNACZ		 (BYTE)0x40L
//------------------------------------
struct __options {
	unsigned __int32 Operation, Break, Error;
	bool Stop;
	TSoft_Database Masks, Argts, Batch;

	unsigned __int32 Cut, Block, Methods, Dict;
	bool Cached;
} options;
//------------------------------------
struct __progress {
struct __destination {
struct __group {
	unsigned __int64 Read, Size; __int8 Percent;
} one, all;
} src, dst;
} progress;
//------------------------------------
#define IS					(BYTE)0
#define SIZE				(BYTE)1
#define ATTRIB				(BYTE)2
//------------------------------------
#define EXISTS				(long)0xFFFFFFFFL
//------------------------------------
struct __list {
	struct __destination {
		TSoft_Database Init, Main;
	} src, dst;
	int iCur, iInc, iBgn;
} list;
//------------------------------------
__stdcall TSoft_Kop32 (void);
//------------------------------------
void  __stdcall set_Password (char *ausrpassword);
char *__stdcall get_Password ();
//------------------------------------
int	  __stdcall Execute  	(char *alpDst, char *alpSrc);
void  __stdcall Stop		(void);
//------------------------------------
#define anQUEST		 (BYTE)0x00L
#define anNO			 (BYTE)0x01L
#define anALL			 (BYTE)0x02L
//------------------------------------

#define onNULL			(DWORD)0x00000000L
#define onPROGRESS	(DWORD)0x10000000L

#define onSTART		(DWORD)0x00001000L
#define onIO	 		(DWORD)0x00004000L
#define onQUEST		(DWORD)0x00008000L
#define onREPLACE_QUEST		(DWORD)0x00010000L
#define onFREESPACE_QUEST		(DWORD)0x00020000L
#define onSTOP			(DWORD)0x00040000L

#define isFILE			(DWORD)0x00000800L
#define isDIRECTORY	(DWORD)0x00000400L
#define isSRC			(DWORD)0x00000200L
#define isDST			(DWORD)0x00000100L

#define onSEEKING			(DWORD)0x00080000L

//------------------------------------
int __stdcall (__closure *OnBreak)(int,int);
int __stdcall DoBreak	(int aCode,int aParam);
int __stdcall (__closure *OnError)(int,int);
int __stdcall DoError	(int aCode,int aParam);
//------------------------------------
__stdcall ~TSoft_Kop32 (void);
//------------------------------------
//typedef int __stdcall(__closure *DoX_DEF)(int,int);
//DoX_DEF OnBreak;
//DoX_DEF OnError;
};
//---------------------------------------------------------------------------
}
//---------------------------------------------------------------------------
#endif
