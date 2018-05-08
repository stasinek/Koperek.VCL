//---------------------------------------------------------------------------
//-----------------Stanislaw Stasiak "SSTSOFT.pl" 2001-2002------------------
//---------------------------------------------------------------------------
#include <windows.h>
#pragma hdrstop
#include "TSoft_HDR.h"
//---------------------------------------------------------------------------

#define CYCLES_BGN()\
asm {rdtsc         }\
asm {push EAX      }\

#define CYCLES_END()\
asm {push EAX      }\
asm {rdtsc         }\
asm { mov ECX,EAX  }\
asm { pop EAX      }\
asm { mov EBX,EAX  }\
asm { pop EAX      }\
asm { sub ECX,EAX  }\
asm { sub ECX,0x0E }\
asm { mov EAX,EBX  }

//---------------------------------------------------------------------------

unsigned char __stdcall Code_bitHeader(DWORD *alpcode,char alpcode_bit,char axdata_uncoded)
{
__asm {
 xor  AX,AX
 mov  AL,axdata_uncoded
test  AL,0x03
setp  CL
 add  CL,CL
 add  CL,0x0002
 mov  BL,0x01
 shl  BL,CL
 dec  BL
 and  AL,BL
 mov  CH,CL
 
 mov EDI,alpcode
 mov  CL,alpcode_bit
 shl  AX,CL
 mov  BL,0x01
 shl  BL,CL
 dec  BL
 and  BL,[EDI]
 xor  AL,BL

 add  CL,CH
MCODE_00:
 mov [EDI+0],AL
 cmp  CL,8
 jbe MCODE_1X
MCODE_01:
 mov [EDI+1],AH
MCODE_1X:
 mov  AL,CH
}
}
//---------------------------------------------------------------------------

unsigned char __stdcall DeCode_bitHeader(char *alpdata_uncoded,DWORD *axcode,char axcode_bit)
{
__asm {
 mov ESI,axcode
 mov  AX,[ESI]
 mov  CL,axcode_bit
 shr  AX,CL
test  AL,0x03
setp  CL
 add  CL,CL
 add  CL,0x0002
 mov  BX,0xFF00
 rol  BX,CL
 and  AL,BL
 mov  CH,CL

 mov  EDI ,alpdata_uncoded
 mov [EDI],AL
 mov  AL,CH
}
}
//---------------------------------------------------------------------------

unsigned char __stdcall Price_bitHeader(char axdata_uncoded)
{
__asm {
 mov  AL,axdata_uncoded
test  AL,0x03
setp  AL
 add  AL,AL
 add  AL,0x0002
}
}
//---------------------------------------------------------------------------
// WARNING! 0 will have same code as 1 - so don't use it!

#define   BIT_CODE_XP(lpcode,lpcode_bit,data_uncoded,BASE_BITS) \
asm { xor ECX,ECX               }\
asm { mov EAX,data_uncoded    	}\
asm { xor EDX,EDX               }\
asm { bsr ECX,EAX               }\
asm { btr EAX,ECX            	}\
asm {shld EDX,EAX,BASE_BITS		}\
asm { shl EAX,BASE_BITS	  		}\
asm {  or EAX,ECX               }\
asm {                           }\
asm { mov  CH,CL				}\
asm { add  CH,BASE_BITS         }\
asm {							}\
asm { mov EDI,lpcode           	}\
asm { mov  CL,lpcode_bit       	}\
asm { mov  BX,0xFF00        	}\
asm { rol  BX,CL                }\
asm {shld EDX,EAX,CL            }\
asm { shl EAX,CL				}\
asm { and  BL,[EDI]             }\
asm {  or  AL,BL                }\
asm {                           }\
asm { add  CL,CH                }\
asm {                           }\
asm {M_00:  	                }\
asm { mov [EDI+0],AL            }\
asm { cmp  CL, 8                }\
asm { jbe M_3X              	}\
asm {M_01:                      }\
asm { mov [EDI+1],AH            }\
asm { cmp  CL,16                }\
asm { jbe M_3X              	}\
asm {M_1X:    		        	}\
asm {shrd EAX,EDX,16         	}\
asm {M_02:                  	}\
asm { mov [EDI+2],AL            }\
asm { cmp  CL,24                }\
asm { jbe M_3X              	}\
asm {M_03:                  	}\
asm { mov [EDI+3],AH            }\
asm { cmp  CL,32                }\
asm { jbe M_3X              	}\
asm {M_2X:						}\
asm {shrd EAX,EDX,16         	}\
asm {M_04:                  	}\
asm { mov [EDI+4],AL            }\
asm { cmp  CL,40	        	}\
asm { jbe M_3X              	}\
asm {M_05:                  	}\
asm { mov [EDI+5],AH            }\
asm {M_3X:						}\
asm {							}\
asm { mov AL,CH					}

//---------------------------------------------------------------------------

#define   BIT_DECODE_XP(lpdata_uncoded,BASE_BITS,code,code_bit) \
asm { mov ESI,code            	}\
asm { mov  CL,code_bit        	}\
asm { mov EAX,[ESI+0]           }\
asm { mov EDX,[ESI+4]           }\
asm {shrd EAX,EDX,CL			}\
asm { shr EDX,CL				}\
asm {                           }\
asm { mov ECX,0xFF00			}\
asm { rol ECX,BASE_BITS         }\
asm { and  CL,AL				}\
asm {shrd EAX,EDX,BASE_BITS     }\
asm {                           }\
asm { mov  CH,CL				}\
asm { add  CH,BASE_BITS         }\
asm {                           }\
asm { mov EBX,0x00000001      	}\
asm { shl EBX,CL				}\
asm { dec EBX                   }\
asm { and EAX,EBX               }\
asm { inc EBX                   }\
asm {  or EAX,EBX               }\
asm {                           }\
asm { mov  EDI ,lpdata_uncoded 	}\
asm { mov [EDI],EAX             }\
asm {							}\
asm { mov AL,CH					}

//---------------------------------------------------------------------------

#define   BIT_PRICE_XP(data_uncoded,BASE_BITS) \
asm { mov EAX,data_uncoded    	}\
asm { xor ECX,ECX               }\
asm { bsr ECX,EAX               }\
asm { mov  AL,BASE_BITS			}\
asm { add  AL,CL                }

unsigned char __stdcall   Code_bitLength(DWORD *alpcode,char alpcode_bit,DWORD axdata_uncoded)
{
BIT_CODE_XP(alpcode,alpcode_bit,axdata_uncoded,3);
}
//---------------------------------------------------------------------------

unsigned char __stdcall DeCode_bitLength(DWORD *alpdata_uncoded,DWORD *axcode,char axcode_bit)
{
BIT_DECODE_XP(alpdata_uncoded,3,axcode,axcode_bit);
}
//---------------------------------------------------------------------------

unsigned char __stdcall  Price_bitLength(DWORD axdata_uncoded)
{
BIT_PRICE_XP(axdata_uncoded,3);
}
//---------------------------------------------------------------------------< 65536

unsigned char __stdcall   Code_bitOffset(DWORD *alpcode,char alpcode_bit,DWORD axdata_uncoded)
{
BIT_CODE_XP(alpcode,alpcode_bit,axdata_uncoded,4);
}
//---------------------------------------------------------------------------

unsigned char __stdcall DeCode_bitOffset(DWORD *alpdata_uncoded,DWORD *axcode,char axcode_bit)
{
BIT_DECODE_XP(alpdata_uncoded,4,axcode,axcode_bit);
}
//---------------------------------------------------------------------------

unsigned char __stdcall  Price_bitOffset(DWORD axdata_uncoded)
{
BIT_PRICE_XP(axdata_uncoded,4);
}
//---------------------------------------------------------------------------< 2^32

unsigned char __stdcall   Code_bitString(DWORD *alpcode,char alpcode_bit,DWORD axdata_uncoded)
{
BIT_CODE_XP(alpcode,alpcode_bit,axdata_uncoded,5);
}
//---------------------------------------------------------------------------

unsigned char __stdcall DeCode_bitString(DWORD *alpdata_uncoded,DWORD *axcode,char axcode_bit)
{
BIT_DECODE_XP(alpdata_uncoded,5,axcode,axcode_bit);
}
//---------------------------------------------------------------------------

unsigned char __stdcall  Price_bitString(DWORD axdata_uncoded)
{
BIT_PRICE_XP(axdata_uncoded,5);
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------< 2^32

unsigned char __stdcall Code_ptrPass(DWORD *alpcode,DWORD axdata_uncoded_length)
{
// ESI src
// EDI dst
// EBX,EAX DATA64
// CL temp bit cnt
// DL, DH
asm { xor EAX,EAX                  		}
asm { xor EBX,EBX                  		}
asm { xor ECX,ECX               		}
asm { xor EDX,EDX                  		}
asm {                           		}
asm { mov ESI,axdata_uncoded_length     }
asm { bsr ECX,ESI               		}
asm { btr ESI,ECX               		}
asm { mov  DH,CL                  		}
asm { and  DH,0x1F                 		}
asm {                           		}
asm {  or EAX,ESI                  		}
asm {                           		}
asm { shl EAX,3                 		}
asm { mov  CL,DH                   		}
//asm { shr  CL,2                    		}
asm {  or  AL,CL                  		}
asm { shl EAX,2                 		}
asm {  or  AL,XPASS_CODE          		}
asm {                           		}
asm { add  BL,DH                  		}
asm { add  BL,3+2                		}
asm {                           		}
asm { mov EDI,alpcode           		}
asm {MCODE_00:                  		}
asm { mov [EDI+0],AL            		}
asm { cmp  BL, 8                		}
asm { jbe MCODE_XX              		}
asm {MCODE_01:                  		}
asm { mov [EDI+1],AH            		}
asm {MCODE_XX:						  	}
asm {									}
asm { mov  AL,BL                   		}
asm {test  BL,0x07                 		}
asm {setnz BL                      		}
asm { shr  AL,3                  		}
asm { add  AL,BL                   		}
}
//---------------------------------------------------------------------------

unsigned char __stdcall DeCode_ptrPass(DWORD *alpdata_uncoded_length,DWORD *alpcode)
{
asm { xor EAX,EAX                  		}
asm { xor EBX,EBX                  		}
asm { xor ECX,ECX                  		}
asm { xor EDX,EDX                  		}
asm {                           		}
asm {MCODE_00:                  		}
asm { mov ESI,alpcode                   }
asm { mov  AL,[ESI]               		}
asm { mov  DH,AL                  		}
asm { and  DH,0x04               		}
asm { add  DH,4                    		}
asm {                           		}
asm { mov  CL,DH                   		}
asm { add  CL,3                   		}
asm {MCODE_01:                  		}
asm { cmp  CL, 8                 		}
asm { jbe MCODE_XX              		}
asm { mov  AH,[ESI+1]            		}
asm {MCODE_XX:						  	}
asm {                           		}
asm { shr EAX,3                 		}
asm { mov EDI,alpdata_uncoded_length	}
asm { mov EBX,0x00000001          		}
asm { mov  CL,DH                    	}
asm { shl EBX,CL                		}
asm { dec EBX                   		}
asm { and EBX,EAX                		}
asm { mov [EDI],EBX                		}
asm { mov  AL,DH                   		}
asm { add  AL,3                   		}
asm { mov  AH,AL                   		}
asm {test  AH,0x07                 		}
asm {setnz AH                      		}
asm { shr  AL,3                  		}
asm { add  AL,AH                   		}
}
//---------------------------------------------------------------------------

unsigned char __stdcall Price_ptrPass(DWORD axdata_uncoded_length)
{
asm { xor EAX,EAX                  		}
asm {                           		}
asm { mov EDX,axdata_uncoded_length     }
asm { bsr EAX,EDX               		}
asm { and  AL,0x1F                		}
asm { add  AL,3+2                		}
asm {                           		}
asm { mov  AH,AL                   		}
asm {test  AH,0x07                 		}
asm {setnz AH                      		}
asm { shr  AL,3                  		}
asm { add  AL,AH                   		}
}
//---------------------------------------------------------------------------

unsigned char __stdcall Code_ptrDict(DWORD *alpcode,DWORD axdata_uncoded_offset,DWORD axdata_uncoded_length)
{
asm { xor EAX,EAX                  		}
asm { xor EBX,EBX                  		}
asm { xor EDX,EDX                  		}
asm {                           		}
asm { xor ECX,ECX               		}
asm { mov ESI,axdata_uncoded_length     }
asm { bsr ECX,ESI               		}
asm { btr ESI,ECX               		}
asm { mov  DH,CL                  		}
asm { and  DH,0x1F                		}
asm {                           		}
asm {  or EAX,ESI                  		}
asm {                           		}
asm { xor ECX,ECX               		}
asm { mov ESI,axdata_uncoded_offset     }
asm { bsr ECX,ESI               		}
asm { btr ESI,ECX               		}
asm { mov  DL,CL                  		}
asm { and  DL,0x1F                 		}
asm {                           		}
asm { mov  CL,DL                   		}
//asm { add  CL,4                   		}
asm { shl EAX,CL                 		}
asm {  or EAX,ESI                  		}
asm {                           		}
asm { shl EAX,3                 		}
asm { mov  CL,DH                   		}
//asm { shr  CL,2                    		}
asm {  or  AL,CL                  		}
asm { shl EAX,4                 		}
asm { mov  CL,DL                   		}
//asm { shr  CL,2                    		}
asm {  or  AL,CL                  		}
asm { shl EAX,2                 		}
asm {  or  AL,XDICT_CODE  		        }
asm {                           		}
asm { add  BL,DH                		}
asm { add  BL,DL                		}
asm { add  BL,3+4+2            		}
asm {                           		}
asm { mov EDI,alpcode           		}
asm {MCODE_00:                  		}
asm { mov [EDI+0],AL            		}
asm { cmp  BL, 8                		}
asm { jbe MCODE_XX              		}
asm {MCODE_01:                  		}
asm { mov [EDI+1],AH            		}
asm { cmp  BL,16                		}
asm { jbe MCODE_XX              		}
asm { shr EAX,16                  		}
asm {MCODE_02:                  		}
asm { mov [EDI+2],AL            		}
asm { cmp  BL,24                		}
asm { jbe MCODE_XX              		}
asm {MCODE_03:                  		}
asm { mov [EDI+3],AH            		}
asm { cmp  BL,32                		}
asm { jbe MCODE_XX              		}
asm {MCODE_XX:						  	}
asm {									}
asm { mov  AL,BL                   		}
asm {test  BL,0x07                 		}
asm {setnz BL                      		}
asm { shr  AL,3                  		}
asm { add  AL,BL                   		}
}
//---------------------------------------------------------------------------

unsigned char __stdcall DeCode_ptrDict(DWORD *alpdata_uncoded_offset,DWORD *alpdata_uncoded_length,DWORD *alpcode)
{
asm { xor EAX,EAX                  		}
asm { xor EBX,EBX                  		}
asm { xor ECX,ECX                  		}
asm { xor EDX,EDX                  		}
asm {                           		}
asm {MCODE_00:                  		}
asm { mov ESI,alpcode                   }
asm { mov  AL,[ESI]               		}
asm { mov  DL,AL                  		}
asm { and  DL,0x0C               		}
asm { add  DL,4                    		}
asm { mov  DH,AL                  		}
asm { shr  DH,2                    		}
asm { and  DH,0x04               		}
asm { add  DH,4                    		}
asm {                           		}
asm { mov  CL,DL                   		}
asm { add  CL,DH                   		}
asm { add  CL,5                   		}
asm {MCODE_01:                  		}
asm { cmp  CL, 8                 		}
asm { jbe MCODE_XX              		}
asm { mov  AH,[ESI+1]            		}
asm {MCODE_02:                  		}
asm { cmp  CL,16                 		}
asm { jbe MCODE_XX              		}
asm {bswap EAX                   		}
asm { mov  AH,[ESI+2]            		}
asm {bswap EAX                   		}
asm {MCODE_03:                  		}
asm { cmp  CL,24                 		}
asm { jbe MCODE_XX              		}
asm {bswap EAX                   		}
asm { mov  AL,[ESI+3]            		}
asm {bswap EAX                   		}
asm {MCODE_XX:						  	}
asm {                           		}
asm { shr EAX,5                 		}
asm { mov EDI,alpdata_uncoded_offset	}
asm { mov EBX,0x00000001          		}
asm { mov  CL,DL                    	}
asm { shl EBX,CL                		}
asm { dec EBX                   		}
asm { and EBX,EAX                		}
asm { mov [EDI],EBX                		}
asm {                           		}
asm { shr EAX,CL                 		}
asm { mov EDI,alpdata_uncoded_length	}
asm { mov EBX,0x00000001          		}
asm { mov  CL,DH                    	}
asm { shl EBX,CL                		}
asm { dec EBX                   		}
asm { and EBX,EAX                		}
asm { mov [EDI],EBX                		}
asm {                           		}
asm { mov  AL,DL                   		}
asm { add  AL,DH                   		}
asm { add  AL,5                   		}
asm { mov  AH,AL                   		}
asm {test  AH,0x07                 		}
asm {setnz AH                      		}
asm { shr  AL,3                  		}
asm { add  AL,AH                   		}
}
//---------------------------------------------------------------------------

unsigned char __stdcall Price_ptrDict(DWORD axdata_uncoded_offset,DWORD axdata_uncoded_length)
{
asm { xor EBX,EBX               		}
asm { mov EDX,axdata_uncoded_length	    }
asm { bsr EBX,EDX               		}
asm { and  BL,0x1F                		}
asm {                           		}
asm { xor EAX,EAX                  		}
asm { mov EDX,axdata_uncoded_offset	    }
asm { bsr EAX,EDX               		}
asm { and  AL,0x1F                		}
asm {                           		}
asm { add  AL,BL              		    }
asm { add  AL,3+4+2            		}
asm {                           		}
asm { mov  AH,AL                   		}
asm {test  AH,0x07                 		}
asm {setnz AH                      		}
asm { shr  AL,3                  		}
asm { add  AL,AH                   		}
}
//---------------------------------------------------------------------------

unsigned char __stdcall Code_ptrBrun(DWORD *alpcode,DWORD axdata_uncoded_elsize,DWORD axdata_uncoded_counte)
{
asm { xor EAX,EAX                  		}
asm { xor EBX,EBX                  		}
asm { xor EDX,EDX                  		}
asm {                           		}
asm { xor ECX,ECX               		}
asm { mov ESI,axdata_uncoded_counte     }
asm { bsr ECX,ESI               		}
asm { btr ESI,ECX               		}
asm { mov  DH,CL                  		}
asm { and  DH,0x1F                 		}
asm {                           		}
asm {  or EAX,ESI                  		}
asm {                           		}
asm { mov ESI,axdata_uncoded_elsize     }
asm { dec ESI                    		}
asm {                           		}
asm { shl EAX,3                 		}
asm { mov  CL,DH                  		}
//asm { shr  CL,2                  		}
asm {  or  AL,CL                  		}
asm { shl EAX,2                 		}
asm {  or EAX,ESI                  		}
asm { shl EAX,2                 		}
asm {  or  AL,XBRUN_CODE          		}
asm {                           		}
asm { add  BL,DH                		}
asm { add  BL,3+2+2              		}
asm {                           		}
asm { mov EDI,alpcode           		}
asm {MCODE_00:                  		}
asm { mov [EDI+0],AL            		}
asm { cmp  BL, 8                		}
asm { jbe MCODE_XX              		}
asm {MCODE_01:                  		}
asm { mov [EDI+1],AH            		}
asm {MCODE_XX:						  	}
asm {									}
asm { mov  AL,BL                   		}
asm {test  BL,0x07                 		}
asm {setnz BL                      		}
asm { shr  AL,3                  		}
asm { add  AL,BL                   		}
}
//---------------------------------------------------------------------------

unsigned char __stdcall DeCode_ptrBrun(DWORD *alpdata_uncoded_elsize,DWORD *alpdata_uncoded_counte,DWORD *alpcode)
{
asm { xor EAX,EAX                  		}
asm { xor EBX,EBX                  		}
asm { xor ECX,ECX                  		}
asm { xor EDX,EDX                  		}
asm {                           		}
asm {MCODE_00:                  		}
asm { mov ESI,alpcode                   }
asm { mov  AL,[ESI]               		}
asm { mov  DH,AL                  		}
asm { shr  DH,2                    		}
asm { and  DH,0x04               		}
asm { add  DH,4                    		}
asm {                           		}
asm { mov EDI,alpdata_uncoded_elsize	}
asm { mov  BL,AL                  		}
asm { shr  BL,2                  		}
asm { and  BL,0x03                 		}
asm { inc  BL                    		}
asm { mov[EDI],EBX                 		}
asm {                           		}
asm { mov  CL,DH                   		}
asm { add  CL,5                   		}
asm {MCODE_01:                  		}
asm { cmp  CL, 8                 		}
asm { jbe MCODE_XX              		}
asm { mov  AH,[ESI+1]            		}
asm {MCODE_XX:						  	}
asm {                           		}
asm { shr EAX,5                 		}
asm { mov EDI,alpdata_uncoded_counte	}
asm { mov EBX,0x00000001          		}
asm { mov  CL,DH                    	}
asm { shl EBX,CL                		}
asm { dec EBX                   		}
asm { and EBX,EAX                		}
asm { mov [EDI],EBX                		}
asm { mov  AL,DH                   		}
asm { add  AL,5                   		}
asm { mov  AH,AL                   		}
asm {test  AH,0x07                 		}
asm {setnz AH                      		}
asm { shr  AL,3                  		}
asm { add  AL,AH                   		}
}
//---------------------------------------------------------------------------

unsigned char __stdcall Price_ptrBrun(DWORD axdata_uncoded_elsize,DWORD axdata_uncoded_counte)
{
asm { xor EAX,EAX                  		}
asm { mov EDX,axdata_uncoded_counte     }
asm { bsr EAX,EDX               		}
asm { and  AL,0x1F                		}
asm {                           		}
asm { add  AL,3+2+2              		}
asm { mov  AH,AL                   		}
asm {test  AH,0x07                 		}
asm {setnz AH                      		}
asm { shr  AL,3                  		}
asm { add  AL,AH                   		}
}
//---------------------------------------------------------------------------< 65536

