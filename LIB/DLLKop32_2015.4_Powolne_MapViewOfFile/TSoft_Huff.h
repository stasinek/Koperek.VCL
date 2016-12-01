//---------------------------------------------------------------------------
//-----------------Stanislaw Stasiak "TSoft_, where?" 2001-2002---------------
//---------------------------------------------------------------------------
#ifndef __TSoft_Huff_HDR__
#define __TSoft_Huff_HDR__
#include <windows.h>
#pragma hdrstop
//---------------------------------------------------------------------------
/********** Huffman Compression **********/
//---------------------------------------------------------------------------
class TSoft_Huff
{
//---------------------------------------------------------------------------
public:
unsigned long *son; // pointers to child nodes (son[], son[] + 1)
unsigned long *dad; // pointers to parent nodes, except for the 
						  // elements [TREE..TREE + N_CHAR - 1] which are used to get
						  // the positions of leaves corresponding to the codes.
unsigned long *frq; // frequency table 
//---------------------------------------------------------------------------
	  __stdcall  TSoft_Huff(void);
	  __stdcall ~TSoft_Huff();
//---------------------------------------------------------------------------
void __stdcall Reconstruct(void);
void __stdcall Update(unsigned char axdata_uncoded);
void __stdcall Initialize(void);
//---------------------------------------------------------------------------
unsigned char __stdcall Encode(unsigned char *alpcode, unsigned char alpcode_bit, unsigned char axdata_uncoded);
unsigned char __stdcall Decode(unsigned char *alpdata_uncoded, unsigned char *alpcode, unsigned char alpcode_bit);
//---------------------------------------------------------------------------
};
//-------------------------------THE END-------------------------------------
#endif

