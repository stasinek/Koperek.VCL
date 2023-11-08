//---------------------------------------------------------------------------
//-------- COPYRIGHT: Stanislaw Stasiak SSTSOFT.pl @2001-2004 ---------------
//-------- https://github.com/stasinek/Koperek.VCL --------------------------
//---------------------------------------------------------------------------
#ifndef __TSoft_Ari_HDR__
#define __TSoft_Ari_HDR__
//---------------------------------------------------------------------------
#include <windows.h>
#pragma hdrstop
//---------------------------------------------------------------------------
#include "TSoft_build_conf.h"
//---------------------------------------------------------------------------
/************************ Arithmetic Compression ****************************/
//---------------------------------------------------------------------------
class TSoft_Ari
{
//---------------------------------------------------------------------------
unsigned char  underflow_bits;     /* counts for magnifying low and high around Q2 */
unsigned long  low, high, value;
unsigned long *char_to_symb;
unsigned long *symb_to_char;
unsigned long *symb_freq;  /* frequency for symbbols */
unsigned long *symb_cumf;  /* cumulative freq for symbbols */
//---------------------------------------------------------------------------
public:
//---------------------------------------------------------------------------
	  __stdcall  TSoft_Ari(void);
	  __stdcall ~TSoft_Ari();
//---------------------------------------------------------------------------
unsigned int __stdcall Search(unsigned long x);
void __stdcall Initialize(void);
void __stdcall Update(unsigned long axdata_uncoded);
//---------------------------------------------------------------------------
void __stdcall Initialize_Encoder(void);
unsigned char __stdcall Encode(unsigned long *alpcode, unsigned char alpcode_bit, unsigned char axdata_uncoded);
unsigned char __stdcall Flush_Encoder(unsigned long *alpcode, unsigned char alpcode_bit);
//---------------------------------------------------------------------------
unsigned char __stdcall Initialize_Decoder(unsigned long *alpcode, unsigned char alpcode_bit);
unsigned char __stdcall Decode(unsigned char *alpdata_uncoded,unsigned long *alpcode, unsigned char alpcode_bit);
void __stdcall Flush_Decoder(void);
//---------------------------------------------------------------------------
};
//-------------------------------THE END-------------------------------------
#endif

