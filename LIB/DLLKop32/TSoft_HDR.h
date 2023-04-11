#ifndef __TSoft_HDR_H
#define __TSoft_HDR_H
//---------------------------------------------------------------------------
#define XMODE_MASK BYTE(0x03L)
#define XPASS_CODE BYTE(0x00L)
#define XDICT_CODE BYTE(0x01L)
#define XBRUN_CODE BYTE(0x02L)
#define XHUFF_CODE BYTE(0x03L)
//---------------------------------------------------------------------------
extern "C" {
//---------------------------------------------------------------------------
__declspec(dllexport) class __bitptr_hdrcoder {
public:
__declspec(dllexport) unsigned char __stdcall   Code_ptrBrun(DWORD *alpcode,DWORD axdata_uncoded_elsize,DWORD axdata_uncoded_counte);
__declspec(dllexport) unsigned char __stdcall DeCode_ptrBrun(DWORD *alpdata_uncoded_elsize,DWORD *alpdata_uncoded_counte,DWORD *alpcode);
__declspec(dllexport) unsigned char __stdcall  Price_ptrBrun(DWORD axdata_uncoded_elsize,DWORD axdata_uncoded_counte);
__declspec(dllexport) unsigned char __stdcall   Code_ptrDict(DWORD *alpcode,DWORD axdata_uncoded_offset,DWORD axdata_uncoded_length);
__declspec(dllexport) unsigned char __stdcall DeCode_ptrDict(DWORD *alpdata_uncoded_offset,DWORD *alpdata_uncoded_length,DWORD *alpcode);
__declspec(dllexport) unsigned char __stdcall  Price_ptrDict(DWORD axdata_uncoded_offset,DWORD axdata_uncoded_length);
__declspec(dllexport) unsigned char __stdcall   Code_ptrPass(DWORD *alpcode,DWORD axdata_uncoded_length);
__declspec(dllexport) unsigned char __stdcall DeCode_ptrPass(DWORD *alpdata_uncoded_length,DWORD *alpcode);
__declspec(dllexport) unsigned char __stdcall  Price_ptrPass(DWORD axdata_uncoded_length);
};
//---------------------------------------------------------------------------
__declspec(dllexport) class __ptrptr_hdrcoder {
public:
__declspec(dllexport) unsigned char __stdcall   Code_ptrBrun(DWORD *alpcode,DWORD axdata_uncoded_elsize,DWORD axdata_uncoded_counte);
__declspec(dllexport) unsigned char __stdcall DeCode_ptrBrun(DWORD *alpdata_uncoded_elsize,DWORD *alpdata_uncoded_counte,DWORD *alpcode);
__declspec(dllexport) unsigned char __stdcall  Price_ptrBrun(DWORD axdata_uncoded_elsize,DWORD axdata_uncoded_counte);
__declspec(dllexport) unsigned char __stdcall   Code_ptrDict(DWORD *alpcode,DWORD axdata_uncoded_offset,DWORD axdata_uncoded_length);
__declspec(dllexport) unsigned char __stdcall DeCode_ptrDict(DWORD *alpdata_uncoded_offset,DWORD *alpdata_uncoded_length,DWORD *alpcode);
__declspec(dllexport) unsigned char __stdcall  Price_ptrDict(DWORD axdata_uncoded_offset,DWORD axdata_uncoded_length);
__declspec(dllexport) unsigned char __stdcall   Code_ptrPass(DWORD *alpcode,DWORD axdata_uncoded_length);
__declspec(dllexport) unsigned char __stdcall DeCode_ptrPass(DWORD *alpdata_uncoded_length,DWORD *alpcode);
__declspec(dllexport) unsigned char __stdcall  Price_ptrPass(DWORD axdata_uncoded_length);
};
//---------------------------------------------------------------------------
}
//---------------------------------------------------------------------------
#endif
//---------------------------------------------------------------------------
/*static unsigned long XLCTBase[64]={
								0,1,2,3,4,6,8,12,
								16,24,32,48,64,96,128,192,
								256,384,512,768,1024,1536,2048,3072,
								4096,6144,8192,12288,16384,24576,32768,49152,
								65536,98304,131072,196608,262144,393216,524288,786432,
								1048576,1572864,2097152,3145728,4194304,6291456,8388608,12582912,
								16777216,25165824,33554432,50331648,67108864,100663296,134217728,201326592,
								268435456,402653184,536870912,805306368,1073741824,1610612736,2147483648,3221225472}; // 20-32bits not fully implemented
static unsigned char XLCTBits[64]={
								0,0,0,0,1,1,2,2,
								3,3,4,4,5,5,6,6,
								7,7,8,8,9,9,10,10,
								11,11,12,12,13,13,14,14,
								15,15,16,16,17,17,18,18,
								19,19,20,20,21,21,22,22,
								23,23,24,24,25,25,26,26,
								27,27,28,28,29,29,30,30}; // 20-32bits not fully implemented
// 16 coding tables   x 0  1  2  3  4  5  6  7  8  9  A  B  C  D  E  F
static unsigned char XLCTBidx[128]={
								0, 1, 2, 3, 4, 4, 5, 5, 6, 6, 6, 6, 7, 7, 7, 7,
								0, 8,10,11,12,12,13,13,14,14,14,14,15,15,15,15,
								0,16,18,19,20,20,21,21,22,22,22,22,23,23,23,23,
								0,24,26,27,28,28,29,29,30,30,30,30,31,31,31,31,
								0,32,34,35,36,36,37,37,38,38,38,38,39,39,39,39,
								0,40,42,43,44,44,45,45,46,46,46,46,47,47,47,47,
								0,48,50,51,52,52,53,53,54,54,54,54,55,55,55,55,
								0,56,58,59,60,60,61,61,62,62,62,62,63,63,63,63}; // 24-32bits not yet implemented
*/
/*
//---------------------------------------------------------------------------
// length - 32 code/decode tables
//------------------------------------------
static unsigned long FLCTBase[32]={
								0x00000000,0x00000001,0x00000002,0x00000003,
								0x00000004,0x00000005,0x00000006,0x00000007,
								0x00000008,0x00000009,0x0000000A,0x0000000B,
								0x0000000C,0x0000000D,0x0000000E,0x0000000F,
								0x00000010,0x00000014,0x00000018,0x0000001C,
								0x00000020,0x00000028,0x00000030,0x00000038,
								0x00000040,0x00000050,0x00000060,0x00000070,
								0x00000080,0x000000A0,0x000000C0,0x000000E0};
static unsigned char FLCTBits[32]={
								0x00,0x00,0x00,0x00,
								0x00,0x00,0x00,0x00,
								0x00,0x00,0x00,0x00,
								0x00,0x00,0x00,0x00,
								0x02,0x02,0x02,0x02,
								0x03,0x03,0x03,0x03,
								0x04,0x04,0x04,0x04,
								0x05,0x05,0x05,0x05};
static unsigned char FLCTBidx[32]={
								0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,
								0x00,0x10,0x14,0x16,0x18,0x19,0x1A,0x1B,0x1C,0x1C,0x1D,0x1D,0x1E,0x1E,0x1F,0x1F};

//------------------------------------------
// offset - 32 code/decode tables
//------------------------------------------
static unsigned long FOCTBase[32]={
								0x00000000,0x00000001,0x00000002,0x00000003,0x00000004,0x00000006,0x00000008,0x0000000C,
								0x00000010,0x00000018,0x00000020,0x00000030,0x00000040,0x00000060,0x00000080,0x000000C0,
								0x00000100,0x00000180,0x00000200,0x00000300,0x00000400,0x00000600,0x00000800,0x00000C00,
								0x00001000,0x00001800,0x00002000,0x00003000,0x00004000,0x00006000,0x00008000,0x0000C000};
static unsigned char FOCTBits[32]={
								0x00,0x00,0x00,0x00,0x01,0x01,0x02,0x02,
								0x03,0x03,0x04,0x04,0x05,0x05,0x06,0x06,
								0x07,0x07,0x08,0x08,0x09,0x09,0x0A,0x0A,
								0x0B,0x0B,0x0C,0x0C,0x0D,0x0D,0x0E,0x0E};
// 16 coding tables   x 0  1  2  3  4  5  6  7  8  9  A  B  C  D  E  F
static unsigned char FOCTBidx[64]={
								0x00,0x01,0x02,0x03,0x04,0x04,0x05,0x05,0x06,0x06,0x06,0x06,0x07,0x07,0x07,0x07,
								0x00,0x08,0x0A,0x0B,0x0C,0x0C,0x0D,0x0D,0x0E,0x0E,0x0E,0x0E,0x0F,0x0F,0x0F,0x0F,
								0x00,0x10,0x12,0x13,0x14,0x14,0x15,0x15,0x16,0x16,0x16,0x16,0x17,0x17,0x17,0x17,
								0x00,0x18,0x1A,0x1B,0x1C,0x1C,0x1D,0x1D,0x1E,0x1E,0x1E,0x1E,0x1F,0x1F,0x1F,0x1F};
//------------------------------------------
// extra long - 64 code/decode tables
//------------------------------------------
static unsigned long PLCTBase[32]={
								0x00000000,0x00000002,0x00000004,0x00000008,
								0x00000010,0x00000020,0x00000040,0x00000080,
								0x00000100,0x00000200,0x00000400,0x00000800,
								0x00001000,0x00002000,0x00004000,0x00008000,
								0x00010000,0x00020000,0x00040000,0x00080000,
								0x00100000,0x00200000,0x00400000,0x00800000,
								0x01000000,0x02000000,0x04000000,0x08000000,
								0x10000000,0x20000000,0x40000000,0x80000000,}; 
static unsigned char PLCTBits[32]={
								0x01,0x01,0x02,0x03,
								0x04,0x05,0x06,0x07,
								0x08,0x09,0x0A,0x0B,
								0x0C,0x0D,0x0E,0x0F,
								0x10,0x11,0x12,0x13,
								0x14,0x15,0x16,0x17,
								0x18,0x19,0x1A,0x1B,
								0x1C,0x1D,0x1E,0x1F}; 
// 16 coding tables   x 0  1  2  3  4  5  6  7  8  9  A  B  C  D  E  F
static unsigned char PLCTBidx[128]={
								0x00,0x00,0x01,0x01,0x02,0x02,0x02,0x02,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,
								0x00,0x04,0x05,0x05,0x06,0x06,0x06,0x06,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,
								0x00,0x08,0x09,0x09,0x0A,0x0A,0x0A,0x0A,0x0B,0x0B,0x0B,0x0B,0x0B,0x0B,0x0B,0x0B,
								0x00,0x0C,0x0D,0x0D,0x0E,0x0E,0x0E,0x0E,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,
								0x00,0x10,0x11,0x11,0x12,0x12,0x12,0x12,0x13,0x13,0x13,0x13,0x13,0x13,0x13,0x13,
								0x00,0x14,0x15,0x15,0x16,0x16,0x16,0x16,0x17,0x17,0x17,0x17,0x17,0x17,0x17,0x17,
								0x00,0x18,0x19,0x19,0x1A,0x1A,0x1A,0x1A,0x1B,0x1B,0x1B,0x1B,0x1B,0x1B,0x1B,0x1B,
								0x00,0x1C,0x1D,0x1D,0x1E,0x1E,0x1E,0x1E,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F};
//------------------------------------------
#define   BIT_CODE_64()	   		\
asm { mov ESI,lpBidx            }\
asm { mov EDI,lpBits            }\
asm { mov EAX,axdata_uncoded    }\
asm { xor EBX,EBX               }\
asm { xor ECX,ECX               }\
asm { mov EDX,0x0000000F        }\
asm {                           }\
asm { bsr ECX,EAX               }\
asm { and ECX,0x1C              }\
asm { sal EDX,CL                }\
asm { and EDX,EAX               }\
asm { sub EAX,EDX               }\
asm { shr EDX,CL                }\
asm { lea ESI,[ESI+ECX*4]       }\
asm { mov  BL,[ESI+EDX]         }\
asm { mov  CL,[EDI+EBX]         }\
asm { shr EAX,CL                }\
asm { and  AL,BIDX_ADD_MASK     }\
asm { add  BL,AL                }\
asm {                           }\
asm { mov EDX,0x00000001        }\
asm { shl EDX,CL                }\
asm { dec EDX                   }\
asm { mov EAX,axdata_uncoded    }\
asm { and EAX,EDX               }\
asm { xor EDX,EDX               }\
asm {shld EDX,EAX,CODE_BITS     }\
asm { shl EAX,CODE_BITS   		  }\
asm { xor EAX,EBX               }\
asm {                           }\
asm { mov  CH,CODE_BITS         }\
asm { add  CH,CL                }\
asm {									  }\
asm { mov EDI,alpcode           }\
asm { mov  CL,alpcode_bit       }\
asm { mov  BX,0xFF00        	  }\
asm { rol  BX,CL                }\
asm {shld EDX,EAX,CL            }\
asm { shl EAX,CL		   		  }\
asm { and  BL,[EDI]             }\
asm { xor  AL,BL                }\
asm {MCODE_SS:                  }\
asm { add  CL,CH                }\
asm {MCODE_00:                  }\
asm { mov [EDI+0],AL            }\
asm { cmp  CL, 8                }\
asm { jbe MCODE_3X              }\
asm {MCODE_01:                  }\
asm { mov [EDI+1],AH            }\
asm { cmp  CL,16                }\
asm { jbe MCODE_3X              }\
asm {MCODE_1X:                  }\
asm {shrd EAX,EDX,16         	  }\
asm {MCODE_02:                  }\
asm { mov [EDI+2],AL            }\
asm { cmp  CL,24                }\
asm { jbe MCODE_3X              }\
asm {MCODE_03:                  }\
asm { mov [EDI+3],AH            }\
asm { cmp  CL,32                }\
asm { jbe MCODE_3X              }\
asm {MCODE_2X:						  }\
asm {shrd EAX,EDX,16         	  }\
asm {MCODE_04:                  }\
asm { mov [EDI+4],AL            }\
asm { cmp  CL,40	              }\
asm { jbe MCODE_3X              }\
asm {MCODE_05:                  }\
asm { mov [EDI+5],AH            }\
asm {MCODE_3X:						  }\
asm {									  }\
asm { mov AL,CH					  }
//---------------------------------------------------------------------------

#define   BIT_DECODE_64()    		\
asm { mov ESI,axcode            }\
asm { mov  CL,axcode_bit        }\
asm { mov EAX,[ESI+0]           }\
asm { mov EDX,[ESI+4]           }\
asm { mov ESI,lpBase            }\
asm { mov EDI,lpBits            }\
asm {shrd EAX,EDX,CL		        }\
asm { shr EDX,CL		        	  }\
asm {                           }\
asm { mov ECX,CODE_MASK         }\
asm { and ECX,EAX               }\
asm { mov ESI,lpBase            }\
asm { mov EDI,lpBits            }\
asm { mov EBX,[ESI+ECX*4]       }\
asm { mov  CL,[EDI+ECX]         }\
asm { mov EDI,0x00000001        }\
asm { shl EDI,CL                }\
asm { dec EDI                   }\
asm {shrd EAX,EDX,CODE_BITS     }\
asm { shr EDX,CODE_BITS		  	  }\
asm { and EAX,EDI               }\
asm { add EAX,EBX               }\
asm {                           }\
asm { mov  CH,CODE_BITS         }\
asm { add  CH,CL                }\
asm {                           }\
asm { mov  EDI,alpdata_uncoded  }\
asm { mov [EDI],EAX             }\
asm {									  }\
asm { mov  AL,CH		           }
*/
//static unsigned long *lpBase = (unsigned long*)&FOCTBase[0];
//static unsigned char *lpBits = (unsigned char*)&FOCTBits[0];
//#define CODE_MASK 0x1FL
//#define CODE_BITS 5
//BIT_DECODE_64();
//static unsigned char *lpBidx = (unsigned char*)&FOCTBidx[0];
//static unsigned char *lpBits = (unsigned char*)&FOCTBits[0];
//#define BIDX_ADD_MASK 0x01L
//#define CODE_BITS	5
//BIT_CODE_64();
/* */
		 
