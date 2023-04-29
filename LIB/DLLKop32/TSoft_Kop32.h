//---------------------------------------------------------------------------
//-----------------Stanislaw Stasiak "TSoft"-2001-2002--------------------------
//---------------------------------------------------------------------------
#ifndef __TSoft_Kop32_HDR__
#define __TSoft_Kop32_HDR__
//---------------------------------------------------------------------------
#include "TSoft_build_conf.h"
#include "./../DLLDatabase/TSoft_Database.h"
#include "TSoft_Stack.h"
//---------------------------------------------------------------------------
// z VCL'a
//---------------------------------------------------------------------------
#define SCARD_W_CANCELLED_BY_USER   _HRESULT_TYPEDEF_(0x8010006EL)
//---------------------------------------------------------------------------
#define mtXOR     0x00000010
#define mtSXQ     0x00000020
#define mtCRC     0x00000040
#define mtADLER   0x00000080
#define mtSTORE   mtCRC
#define mtLZS     0x00000008
#define mtHUF     0x00000004
#define mtARI     0x00000100
#define mtDEFAULT (mtCRC|mtLZS)
#define mtBWT     0x00000001
#define mtMTF     0x00000002
#define mtULTRA   (mtCRC|mtLZS|mtMTF|mtHUF)

#ifndef mrOk
#define mrOk		(DWORD)1
#define mrCancel	(DWORD)2
#define mrNo		(DWORD)7
#define mrNoToAll	(DWORD)9
#define mrYes		(DWORD)6
#define mrYesToAll 	(DWORD)10
#endif
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
typedef struct {
	void *Lptr;
	unsigned __int32 Size, Offset;
} __buffer;
//------------------------------------
namespace TSoft {
class KOP_IMPEXP Kop32
{
//------------------------------------
private:
static DWORD WINAPI WriteFileThread( LPVOID );
HANDLE WriteFileThreadHandle;
DWORD  WriteFileThreadId;
DWORD  WriteFileThreadControl;
DWORD  WriteFileThreadIndexQueue[8];
DWORD  WriteFileThreadIndexQueueCount;
//------------------------------------
int  __stdcall FOnBreak		  	(int abrParam,int abrButtons);
int  __stdcall FOnError		  	(int aerParam,int aerButtons);
//------------------------------------
int  __stdcall SeekSrc			(char *alpStrSrc);
int  __stdcall SeekSrcFile	  	(char *alpStrSrc);
int  __stdcall SeekDst			(char *alpStrDst);
//------------------------------------
void __stdcall Clr			(void);
int  __stdcall Procede			(int aindex, int anaction);
int  __stdcall Skip			(int aindex, bool an_all_not_one);
//------------------------------------
__int64 __stdcall DiskSpace	        (char *avolumin, __int64 abajtSrc, __int64 abajtDst, bool auntilPositive, bool acouldOmit);
//------------------------------------
__buffer mem_buffer[10];
 __int8 mem_read_index, mem_write_index, mem_count;
__stack stack;
//------------------------------------
struct __file {
struct __destination {
	  __find find;
	HANDLE Hand, HandMap;
	unsigned __int32 Read, Size; __int8 Percent;
	__buffer buffer;
}  src, dst;
} file;
//------------------------------------
struct __password {
	char  FEnc[48], FUsr[48];
	unsigned __int8  FSize;
} password;
//------------------------------------
public:
//------------------------------------
#define opNULL			    (BYTE)0x00L
#define opKOPIUJ			(BYTE)0x01L
#define opKODUJ		        (BYTE)0x02L
#define opDEKODUJ		    (BYTE)0x04L
#define opPRZENIES			(BYTE)0x08L
#define opUSUN		        (BYTE)0x10L
#define opLISTUJ			(BYTE)0x20L
#define opZAZNACZ		    (BYTE)0x40L
//------------------------------------
struct __options {
	unsigned __int32 Operation, Break, Error;
	bool Stop;
	DATABASE_IMPEXP TSoft::Database Masks, Argts, Batch;

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
#define IS				    (BYTE)0
#define SIZE				(BYTE)1
#define ATTRIB				(BYTE)2
//------------------------------------
#define EXISTS				(long)0xFFFFFFFFL
//------------------------------------
struct __list {
	struct __destination {
		DATABASE_IMPEXP TSoft::Database Init, Main;
	} src, dst;
	int iCur, iInc, iBgn;
} list;
//------------------------------------
KOP_IMPEXP __stdcall  Kop32 (void);
virtual KOP_IMPEXP __stdcall ~Kop32 (void);
//------------------------------------
KOP_IMPEXP void  __stdcall SetPassword          (const char *ausrpassword);
KOP_IMPEXP const char *__stdcall GetPassword    (void);
KOP_IMPEXP int __stdcall GetPasswordSize();
//------------------------------------
KOP_IMPEXP int   __stdcall Execute  	        (const char *alpDst, const char *alpSrc);
KOP_IMPEXP void  __stdcall Stop		            (void);
//------------------------------------
#define anQUEST		        (BYTE)0x00L
#define anNO			    (BYTE)0x01L
#define anALL			    (BYTE)0x02L
//------------------------------------

#define onNULL			    (DWORD)0x00000000L
#define onPROGRESS	        (DWORD)0x10000000L

#define onSTART		        (DWORD)0x00001000L
#define onIO	 		    (DWORD)0x00004000L
#define onQUEST		        (DWORD)0x00008000L
#define onREPLACE_QUEST		(DWORD)0x00010000L
#define onFREESPACE_QUEST	(DWORD)0x00020000L
#define onSTOP			    (DWORD)0x00040000L

#define isFILE			    (DWORD)0x00000800L
#define isDIRECTORY	        (DWORD)0x00000400L
#define isSRC			    (DWORD)0x00000200L
#define isDST			    (DWORD)0x00000100L

#define onSEEKING			(DWORD)0x00080000L
#define opSEEKPROGRESS	    (DWORD)0x00100000L

//------------------------------------
int __stdcall (__closure *OnBreak)(int,int);
int __stdcall DoBreak	(int aCode,int aParam);
int __stdcall (__closure *OnError)(int,int);
int __stdcall DoError	(int aCode,int aParam);
//------------------------------------
//typedef int __stdcall(__closure *DoX_DEF)(int,int);
//DoX_DEF OnBreak;
//DoX_DEF OnError;
//---------------------------------------------------------------------------
};
//---------------------------------------------------------------------------
} // namespace TSoft
//---------------------------------------------------------------------------
#endif
