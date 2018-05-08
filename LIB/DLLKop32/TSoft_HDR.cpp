//---------------------------------------------------------------------------
//-----------------Stanislaw Stasiak "SSTSOFT.pl" 2001-2002------------------
//---------------------------------------------------------------------------
#include <windows.h>
#include "TSoft_HDR.h"
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

unsigned char __stdcall __ptrptr_hdrcoder::Price_ptrPass(DWORD axdata_uncoded_length)
{
return 1;
}
//---------------------------------------------------------------------------

unsigned char __stdcall __ptrptr_hdrcoder::Code_ptrPass(DWORD *alpcode,DWORD axdata_uncoded_length)
{
((BYTE*)alpcode)[0] = ((axdata_uncoded_length-1)<<2) | XPASS_CODE;
return 1;
}
//---------------------------------------------------------------------------

unsigned char __stdcall __ptrptr_hdrcoder::DeCode_ptrPass(DWORD *alpdata_uncoded_length,DWORD *alpcode)
{
alpdata_uncoded_length[0] = (((BYTE*)alpcode)[0]>>2) & 0x3F + 1;
return 1;
}
//---------------------------------------------------------------------------

unsigned char __stdcall __ptrptr_hdrcoder::Price_ptrBrun(DWORD axdata_uncoded_elsize,DWORD axdata_uncoded_counte)
{
return 2;
}
//---------------------------------------------------------------------------

unsigned char __stdcall __ptrptr_hdrcoder::Code_ptrBrun(DWORD *alpcode,DWORD axdata_uncoded_elsize,DWORD axdata_uncoded_counte)
{
((WORD*)alpcode)[0] = ((axdata_uncoded_elsize-1)<<8) | ((axdata_uncoded_counte-1)<<2) | XBRUN_CODE;
return 2;
}
//---------------------------------------------------------------------------

unsigned char __stdcall __ptrptr_hdrcoder::DeCode_ptrBrun(DWORD *alpdata_uncoded_elsize,DWORD *alpdata_uncoded_counte,DWORD *alpcode)
{
alpdata_uncoded_counte[0] = (((WORD*)alpcode)[0]>>2) & 0x3F + 1;
alpdata_uncoded_elsize[0] = (((WORD*)alpcode)[0]>>8) & 0x03 + 1;
return 2;
}
//---------------------------------------------------------------------------

unsigned char __stdcall __ptrptr_hdrcoder::Price_ptrDict(DWORD axdata_uncoded_offset,DWORD axdata_uncoded_length)
{
return 3;
}
//---------------------------------------------------------------------------

unsigned char __stdcall __ptrptr_hdrcoder::Code_ptrDict(DWORD *alpcode,DWORD axdata_uncoded_offset,DWORD axdata_uncoded_length)
{
((DWORD*)alpcode)[0] = ((axdata_uncoded_offset-1)<<8) | ((axdata_uncoded_length-1)<<2) | XDICT_CODE;
return 3;
}
//---------------------------------------------------------------------------

unsigned char __stdcall __ptrptr_hdrcoder::DeCode_ptrDict(DWORD *alpdata_uncoded_offset,DWORD *alpdata_uncoded_length,DWORD *alpcode)
{
alpdata_uncoded_length[0] = (((DWORD*)alpcode)[0]>>2) & 0x3F   + 1;
alpdata_uncoded_offset[0] = (((DWORD*)alpcode)[0]>>8) & 0xFFFF + 1;
return 3;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
// OLD BIT HEADERS Borland C++ 5 Professional/6 Personal, MSVC++
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

unsigned char __stdcall __bitptr_hdrcoder::Price_ptrPass(DWORD axdata_uncoded_length)
{
#if (__BORLANDC__ > 0x551) || defined(_MSC_VER)
asm { xor EAX,EAX                  		}
asm {                           		}
asm { mov EDX,axdata_uncoded_length     }
asm { bsr EAX,EDX               		}
asm { add  AL,3+2                		}
asm {                           		}
asm { mov  AH,AL                   		}
asm {test  AH,0x07                 		}
asm {setnz AH                      		}
asm { shr  AL,3                  		}
asm { add  AL,AH                   		}
#endif
}
//---------------------------------------------------------------------------

unsigned char __stdcall __bitptr_hdrcoder::Code_ptrPass(DWORD *alpcode,DWORD axdata_uncoded_length)
{
#if (__BORLANDC__ > 0x551) || defined(_MSC_VER)
asm { xor EAX,EAX                  		}
asm { xor ECX,ECX               		}
asm { xor EDX,EDX                  		}
asm {                           		}
asm { mov ESI,axdata_uncoded_length     }
asm { bsr ECX,ESI               		}
asm { btr ESI,ECX               		}
asm { mov  DH,CL                  		}
asm {                           		}
asm {  or EAX,ESI                  		}
asm {                           		}
asm { shl EAX,3                 		}
asm {  or  AL,DH                  		}
asm { shl EAX,2                 		}
asm {  or  AL,XPASS_CODE          		}
asm {                           		}
asm { mov  CL,DH                  		}
asm { add  CL,3+2                		}
asm {                           		}
asm { mov  EDI,alpcode           		}
asm {                           		}
asm { mov [EDI+0],AL            		}
asm { cmp  CL, 8                		}
asm { jbe MCODE_XX              		}
asm { mov [EDI+1],AH            		}
asm { cmp  CL,16                		}
asm { jbe MCODE_XX              		}
asm {									}
asm {     MCODE_XX:      			  	}
asm {									}
asm { mov  AL,CL                   		}
asm {test  CL,0x07                 		}
asm {setnz CL                      		}
asm { shr  AL,3                  		}
asm { add  AL,CL                   		}
#endif
}
//---------------------------------------------------------------------------

unsigned char __stdcall __bitptr_hdrcoder::DeCode_ptrPass(DWORD *alpdata_uncoded_length,DWORD *alpcode)
{
#if (__BORLANDC__ > 0x551) || defined(_MSC_VER)
asm { xor EAX,EAX                  		}
asm { xor ECX,ECX                  		}
asm { xor EDX,EDX                  		}
asm {                           		}
asm { mov ESI,alpcode                   }
asm { mov  AX,[ESI]               		}
asm { mov  DH,AL                  		}
asm { shr  DH,2                    		}
asm { and  DH,0x07               		}
asm {                           		}
asm { mov  CL,DH                   		}
asm { add  CL,3+2                  		}
asm {                           		}
/*asm {MCODE_01:                  		}
asm { cmp  CL, 8                 		}
asm { jbe MCODE_XX              		}
asm { mov  AH,[ESI+1]            		}
asm {MCODE_XX:						  	}
*/
asm {                           		}
asm { shr EAX,3+2                 		}
asm { mov EDI,alpdata_uncoded_length	}
asm { mov ESI,0x00000001          		}
asm { mov  CL,DH                    	}
asm { shl ESI,CL                		}
asm { dec ESI                   		}
asm { and ESI,EAX                		}
asm { bts ESI,ECX                  		}
asm { mov [EDI],ESI                		}
asm {                           		}
asm { mov  AL,DH                   		}
asm { add  AL,3+2                  		}
asm { mov  AH,AL                   		}
asm {test  AH,0x07                 		}
asm {setnz AH                      		}
asm { shr  AL,3                  		}
asm { add  AL,AH                   		}
#endif
}
//---------------------------------------------------------------------------

unsigned char __stdcall __bitptr_hdrcoder::Price_ptrBrun(DWORD axdata_uncoded_elsize,DWORD axdata_uncoded_counte)
{
#if (__BORLANDC__ > 0x551) || defined(_MSC_VER)
asm { xor EAX,EAX                  		}
asm { mov EDX,axdata_uncoded_counte     }
asm { bsr EAX,EDX               		}
asm {                           		}
asm { add  AL,3+2+2              		}
asm {                           		}
asm { mov  AH,AL                   		}
asm {test  AH,0x07                 		}
asm {setnz AH                      		}
asm { shr  AL,3                  		}
asm { add  AL,AH                   		}
#endif
}
//---------------------------------------------------------------------------

unsigned char __stdcall __bitptr_hdrcoder::Code_ptrBrun(DWORD *alpcode,DWORD axdata_uncoded_elsize,DWORD axdata_uncoded_counte)
{
#if (__BORLANDC__ > 0x551) || defined(_MSC_VER)
asm { xor EAX,EAX                  		}
asm { xor EDX,EDX                  		}
asm {                           		}
asm { xor ECX,ECX               		}
asm { mov ESI,axdata_uncoded_counte     }
asm { bsr ECX,ESI               		}
asm { btr ESI,ECX               		}
asm { mov  DH,CL                  		}
asm {                           		}
asm {  or EAX,ESI                  		}
asm {                           		}
asm { mov ESI,axdata_uncoded_elsize     }
asm { dec ESI                    		}
asm {                           		}
asm { shl EAX,3                 		}
asm {  or  AL,DH                  		}
asm { shl EAX,2                 		}
asm {  or EAX,ESI                  		}
asm { shl EAX,2                 		}
asm {  or  AL,XBRUN_CODE          		}
asm {                           		}
asm { mov  CL,DH                		}
asm { add  CL,3+2+2              		}
asm {                           		}
asm { mov  EDI,alpcode           		}
asm {                           		}
asm { mov [EDI+0],AL            		}
asm { cmp  CL, 8                		}
asm { jbe MCODE_XX              		}
asm { mov [EDI+1],AH            		}
asm { cmp  CL,16                		}
asm { jbe MCODE_XX              		}
asm {									}
asm {     MCODE_XX:      			  	}
asm {									}
asm { mov  AL,CL                   		}
asm {test  CL,0x07                 		}
asm {setnz CL                      		}
asm { shr  AL,3                  		}
asm { add  AL,CL                   		}
#endif
}
//---------------------------------------------------------------------------

unsigned char __stdcall __bitptr_hdrcoder::DeCode_ptrBrun(DWORD *alpdata_uncoded_elsize,DWORD *alpdata_uncoded_counte,DWORD *alpcode)
{
#if (__BORLANDC__ > 0x551) || defined(_MSC_VER)
asm { xor EAX,EAX                  		}
asm { xor ECX,ECX                  		}
asm { xor EDX,EDX                  		}
asm {                           		}
asm { mov ESI,alpcode                   }
asm { mov  AX,[ESI]               		}
asm { mov  DH,AL                  		}
asm { shr  DH,4                    		}
asm { and  DH,0x07               		}
asm {                           		}
asm { mov EDI,alpdata_uncoded_elsize	}
asm { mov  CL,AL                  		}
asm { shr  CL,2                  		}
asm { and  CL,0x03                 		}
asm { inc  CL                    		}
asm { mov[EDI],ECX                 		}
asm {                           		}
asm { mov  CL,DH                   		}
asm { add  CL,3+2+2                		}
asm {                           		}
/*asm {MCODE_01:                  		}
asm { cmp  CL, 8                 		}
asm { jbe MCODE_XX              		}
asm { mov  AH,[ESI+1]            		}
asm {MCODE_XX:						  	}
*/
asm {                           		}
asm { shr EAX,3+2+2                		}
asm { mov EDI,alpdata_uncoded_counte	}
asm { mov ESI,0x00000001          		}
asm { mov  CL,DH                    	}
asm { shl ESI,CL                		}
asm { dec ESI                   		}
asm { and ESI,EAX                		}
asm { bts ESI,ECX                		}
asm { mov [EDI],ESI                		}
asm {                           		}
asm { mov  AL,DH                   		}
asm { add  AL,3+2+2                		}
asm { mov  AH,AL                   		}
asm {test  AH,0x07                 		}
asm {setnz AH                      		}
asm { shr  AL,3                  		}
asm { add  AL,AH                   		}
#endif
}
//---------------------------------------------------------------------------

unsigned char __stdcall __bitptr_hdrcoder::Price_ptrDict(DWORD axdata_uncoded_offset,DWORD axdata_uncoded_length)
{
#if (__BORLANDC__ > 0x551) || defined(_MSC_VER)
asm { xor EBX,EBX               		}
asm { mov EDX,axdata_uncoded_length	    }
asm { bsr EBX,EDX               		}
asm {                           		}
asm { xor EAX,EAX                  		}
asm { mov EDX,axdata_uncoded_offset	    }
asm { bsr EAX,EDX               		}
asm {                           		}
asm { add  AL,BL              		    }
asm { add  AL,3+4+2              		}
asm {                           		}
asm { mov  AH,AL                   		}
asm {test  AH,0x07                 		}
asm {setnz AH                      		}
asm { shr  AL,3                  		}
asm { add  AL,AH                   		}
#endif
}
//---------------------------------------------------------------------------

unsigned char __stdcall __bitptr_hdrcoder::Code_ptrDict(DWORD *alpcode,DWORD axdata_uncoded_offset,DWORD axdata_uncoded_length)
{
#if (__BORLANDC__ > 0x551) || defined(_MSC_VER)
asm { xor EAX,EAX                  		}
asm { xor EDX,EDX                  		}
asm {                           		}
asm { xor ECX,ECX               		}
asm { mov ESI,axdata_uncoded_length     }
asm { bsr ECX,ESI               		}
asm { btr ESI,ECX               		}
asm { mov  DH,CL                  		}
asm {                           		}
asm {  or EAX,ESI                  		}
asm {                           		}
asm { xor ECX,ECX               		}
asm { mov ESI,axdata_uncoded_offset     }
asm { bsr ECX,ESI               		}
asm { btr ESI,ECX               		}
asm { mov  DL,CL                  		}
asm {                           		}
asm { shl EAX,CL                 		}
asm {  or EAX,ESI                  		}
asm { shl EAX,3                 		}
asm {  or  AL,DH                  		}
asm { shl EAX,4                 		}
asm {  or  AL,DL                  		}
asm { shl EAX,2                 		}
asm {  or  AL,XDICT_CODE  		        }
asm {                           		}
asm { mov  CL,DL                		}
asm { add  CL,DH                		}
asm { add  CL,3+4+2             		}
asm {                           		}
asm { mov  EDI,alpcode           		}
asm {                           		}
asm { mov [EDI+0],AL            		}
asm { cmp  CL, 8                		}
asm { jbe MCODE_XX              		}
asm { mov [EDI+1],AH            		}
asm { cmp  CL,16                		}
asm { jbe MCODE_XX              		}
asm { shr EAX,16                  		}
asm { mov [EDI+2],AL            		}
asm { cmp  CL,24                		}
asm { jbe MCODE_XX              		}
asm { mov [EDI+3],AH            		}
asm { cmp  CL,32                		}
asm { jbe MCODE_XX              		}
asm {									}
asm {     MCODE_XX:      			  	}
asm {									}
asm { mov  AL,CL                   		}
asm {test  CL,0x07                 		}
asm {setnz CL                      		}
asm { shr  AL,3                  		}
asm { add  AL,CL                   		}
#endif
}
//---------------------------------------------------------------------------

unsigned char __stdcall __bitptr_hdrcoder::DeCode_ptrDict(DWORD *alpdata_uncoded_offset,DWORD *alpdata_uncoded_length,DWORD *alpcode)
{
#if (__BORLANDC__ > 0x551) || defined(_MSC_VER)
asm { xor EAX,EAX                  		}
asm { xor ECX,ECX                  		}
asm { xor EDX,EDX                  		}
asm {                           		}
asm { mov ESI,alpcode                   }
asm { mov EAX,[ESI]               		}
asm {                           		}
asm { mov  CX,AX                  		}
asm { shr  CX,2                    		}
asm { mov  DL,CL                   		}
asm { and  DL,0x0F                 		}
asm {                           		}
asm { mov  CX,AX                  		}
asm { shr  CX,2+4                  		}
asm { mov  DH,CL                   		}
asm { and  DH,0x07                		}
asm {                           		}
asm { mov  CL,DH                   		}
asm { add  CL,DL                   		}
asm { add  CL,3+4+2                		}
asm {                           		}
/*asm {MCODE_02:                  		}
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
*/
asm {                           		}
asm { shr EAX,3+4+2                		}
asm { mov EDI,alpdata_uncoded_offset	}
asm { mov ESI,0x00000001          		}
asm { mov  CL,DL                    	}
asm { shl ESI,CL                		}
asm { dec ESI                   		}
asm { and ESI,EAX                		}
asm { bts ESI,ECX                		}
asm { mov [EDI],ESI                		}
asm {                           		}
asm { shr EAX,CL                 		}
asm { mov EDI,alpdata_uncoded_length	}
asm { mov ESI,0x00000001          		}
asm { mov  CL,DH                    	}
asm { shl ESI,CL                		}
asm { dec ESI                   		}
asm { and ESI,EAX                		}
asm { bts ESI,ECX                		}
asm { mov [EDI],ESI                		}
asm {                           		}
asm { mov  AL,DL                   		}
asm { add  AL,DH                   		}
asm { add  AL,3+4+2                		}
asm {                           		}
asm { mov  AH,AL                   		}
asm {test  AH,0x07                 		}
asm {setnz AH                      		}
asm { shr  AL,3                  		}
asm { add  AL,AH                   		}
#endif
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
// OLD BIT HEADERS
//---------------------------------------------------------------------------
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
#if (__BORLANDC__ > 0x551) || defined(_MSC_VER)
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
#endif
}
//---------------------------------------------------------------------------

unsigned char __stdcall DeCode_bitHeader(char *alpdata_uncoded,DWORD *axcode,char axcode_bit)
{
#if (__BORLANDC__ > 0x551) || defined(_MSC_VER)
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
#endif
}
//---------------------------------------------------------------------------

unsigned char __stdcall Price_bitHeader(char axdata_uncoded)
{
#if (__BORLANDC__ > 0x551) || defined(_MSC_VER)
__asm {
 mov  AL,axdata_uncoded
test  AL,0x03
setp  AL
 add  AL,AL
 add  AL,0x0002
}
#endif
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
#if (__BORLANDC__ > 0x551) || defined(_MSC_VER)
BIT_CODE_XP(alpcode,alpcode_bit,axdata_uncoded,3);
#endif
}
//---------------------------------------------------------------------------

unsigned char __stdcall DeCode_bitLength(DWORD *alpdata_uncoded,DWORD *axcode,char axcode_bit)
{
#if (__BORLANDC__ > 0x551) || defined(_MSC_VER)
BIT_DECODE_XP(alpdata_uncoded,3,axcode,axcode_bit);
#endif
}
//---------------------------------------------------------------------------

unsigned char __stdcall  Price_bitLength(DWORD axdata_uncoded)
{
#if (__BORLANDC__ > 0x551) || defined(_MSC_VER)
BIT_PRICE_XP(axdata_uncoded,3);
#endif
}
//---------------------------------------------------------------------------< 65536

unsigned char __stdcall   Code_bitOffset(DWORD *alpcode,char alpcode_bit,DWORD axdata_uncoded)
{
#if (__BORLANDC__ > 0x551) || defined(_MSC_VER)
BIT_CODE_XP(alpcode,alpcode_bit,axdata_uncoded,4);
#endif
}
//---------------------------------------------------------------------------

unsigned char __stdcall DeCode_bitOffset(DWORD *alpdata_uncoded,DWORD *axcode,char axcode_bit)
{
#if (__BORLANDC__ > 0x551) || defined(_MSC_VER)
BIT_DECODE_XP(alpdata_uncoded,4,axcode,axcode_bit);
#endif
}
//---------------------------------------------------------------------------

unsigned char __stdcall  Price_bitOffset(DWORD axdata_uncoded)
{
#if (__BORLANDC__ > 0x551) || defined(_MSC_VER)
BIT_PRICE_XP(axdata_uncoded,4);
#endif
}
//---------------------------------------------------------------------------< 2^32

unsigned char __stdcall   Code_bitString(DWORD *alpcode,char alpcode_bit,DWORD axdata_uncoded)
{
#if (__BORLANDC__ > 0x551) || defined(_MSC_VER)
BIT_CODE_XP(alpcode,alpcode_bit,axdata_uncoded,5);
#endif
}
//---------------------------------------------------------------------------

unsigned char __stdcall DeCode_bitString(DWORD *alpdata_uncoded,DWORD *axcode,char axcode_bit)
{
#if (__BORLANDC__ > 0x551) || defined(_MSC_VER)
BIT_DECODE_XP(alpdata_uncoded,5,axcode,axcode_bit);
#endif
}
//---------------------------------------------------------------------------

unsigned char __stdcall  Price_bitString(DWORD axdata_uncoded)
{
#if (__BORLANDC__ > 0x551) || defined(_MSC_VER)
BIT_PRICE_XP(axdata_uncoded,5);
#endif
}
//---------------------------------------------------------------------------< 65536

