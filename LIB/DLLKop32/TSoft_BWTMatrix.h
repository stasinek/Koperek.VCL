//---------------------------------------------------------------------------
//-----------------Stanislaw Stasiak "SSTSOFT.pl" 2001-2002------------------
//---------------------------------------------------------------------------
#ifndef __TSoft_BWTMatrix_HDR__
#define __TSoft_BWTMatrix_HDR__
//---------------------------------------------------------------------------
#include "TSoft_build_conf.h"
//---------------------------------------------------------------------------
#define MAX_GRAD	0x1000L
//---------------------------------------------------------------------------
/****** Burrows Wheller Transform Entropy Localizer Pre-Processor ***********/
//---------------------------------------------------------------------------
class __declspec(dllexport) TSoft_BWTMatrix
{
private:
//---------------------------------------------------------------------------
public:
//---------------------------------------------------------------------------
	  __stdcall  TSoft_BWTMatrix(unsigned long ablock);
	  __stdcall ~TSoft_BWTMatrix();
//---------------------------------------------------------------------------
void __stdcall Generate(unsigned char *alpSrc);
unsigned long __stdcall Sort(void);
void __stdcall Flush(unsigned char *alpDst);
unsigned char  *matrix_ptr;
unsigned long  *matrix_idx_ptr;
unsigned long   matrix_dim;
#define BGN 0
#define END 1
void __stdcall Find_groups(unsigned long acolumn,unsigned long arow_bgn,unsigned long arow_end,unsigned long *alist_bgn,unsigned long *alist_end);
unsigned long *groups_bgn[2], *groups_end[2];
void __stdcall Sort_groups(unsigned long acolumn,unsigned long arow_bgn,unsigned long arow_end);
//---------------------------------------------------------------------------
};
//-------------------------------THE END-------------------------------------
/*
typedef unsigned char byte;

byte *rotlexcmp_buf = NULL;
int rottexcmp_bufsize = 0;

int rotlexcmp(const void *l, const void *r)
{
	 int li = *(const int*)l, ri = *(const int*)r, ac=rottexcmp_bufsize;
	 while (rotlexcmp_buf[li] == rotlexcmp_buf[ri])
	 {
		  if (++li == rottexcmp_bufsize)
				li = 0;
		  if (++ri == rottexcmp_bufsize)
				ri = 0;
		  if (!--ac)
				return 0;
	 }
	 if (rotlexcmp_buf[li] > rotlexcmp_buf[ri])
		  return 1;
	 else
		  return -1;
}

void bwt_encode(byte *buf_in, byte *buf_out, int size, int *primary_index)
{
	 int *indices = new int[size];
	 int i;

	 for(i=0; i<size; i++)
		  indices[i] = i;
	 rotlexcmp_buf = buf_in;
	 rottexcmp_bufsize = size;
	 qsort (indices, size, sizeof(int), rotlexcmp);

	 for (i=0; i<size; i++)
		  buf_out[i] = buf_in[(indices[i]+size-1)%size];
	 for (i=0; i<size; i++)
	 {
		  if (indices[i] == 1) {
				*primary_index = i;
				delete indices;
				return;
		  }
	 }
//	 assert (0);

delete indices;
}

void bwt_decode(byte *buf_in, byte *buf_out, int size, int primary_index)
{
	 byte *F = new byte[size];
	 int buckets[256];
	 int i,j,k;
	 int *indices = new int[size];

	 for (i=0; i<256; i++)
		  buckets[i] = 0;
	 for (i=0; i<size; i++)
		  buckets[buf_in[i]] ++;
	 for (i=0,k=0; i<256; i++)
		  for (j=0; j<buckets[i]; j++)
				F[k++] = i;
//	 assert (k==size);
	 for (i=0,j=0; i<256; i++)
	 {
		  while (i>F[j] && j<size)
				j++;
		  buckets[i] = j; // it will get fake values if there is no i in F, but
								// that won't bring us any problems
	 }
	 for(i=0; i<size; i++)
		  indices[buckets[buf_in[i]]++] = i;
	 for(i=0,j=primary_index; i<size; i++)
	 {
		  buf_out[i] = buf_in[j];
		  j=indices[j];
	 }

delete indices,F;
}
*/
#endif
//---------------------------------------------------------------------------
/*
void __stdcall bitMov_08(void *alpdst,char adst_bit,void *alpsrc,char asrc_bit)
{
__asm {

  mov  DL,asrc_bit
  mov ESI,alpsrc
  mov  DH,adst_bit
  mov EDI,alpdst
					
bitMov08_BIT_XXX:
  mov  AL,[ESI+0] 		// dana src
  cmp  DL,0
	jz bitMov08_ESI_01 	// jeden bajt SRC?
  mov  AH,[ESI+1]
bitMov08_ESI_01:
  mov  CL,DL
  shr  AX,CL
  and  AX,0x00FF 		// and maska
  mov  CL,DH
  shl  AX,CL  
  cmp  DH,0
  jnz bitMov08_EDI_CL
  mov [EDI+0],AL
  jmp bitMov08_BIT_XXX_BREAK
bitMov08_EDI_CL:
	or [EDI+0],AL 			// xor dana dst
  mov [EDI+1],AH
bitMov08_BIT_XXX_BREAK:
bitMov08_BIT_OK:
	}
}
//---------------------------------------------------------------------------

void __stdcall bitMov_16(void *alpdst,char adst_bit,void *alpsrc,char asrc_bit)
{
__asm {

  mov  DL,asrc_bit
  mov ESI,alpsrc
  mov  DH,adst_bit
  mov EDI,alpdst
					
bitMov16_BIT_XXX:
  xor EAX,EAX
  mov  AX,[ESI+0] 		// dana src
  cmp  DL,0
	jz bitMov16_ESI_01 	// jeden bajt SRC?
  shl EAX,8
  mov  AL,[ESI+1]
bitMov16_ESI_01:
  mov  CL,DL
  shr EAX,CL
  and EAX,0x0000FFFF 		// and maska
  mov  CL,DH
  shl EAX,CL  
  cmp  DH,0
  jnz bitMov16_EDI_CL
  mov [EDI+0],AX
  jmp bitMov16_BIT_XXX_BREAK
bitMov16_EDI_CL:			
	or [EDI+0],AL        // xor dana dst
  shr EAX,8						
  mov [EDI+1],AX
bitMov16_BIT_XXX_BREAK:
bitMov16_BIT_OK:
	}
}
//---------------------------------------------------------------------------

void __stdcall bitMov_24(void *alpdst,char adst_bit,void *alpsrc,char asrc_bit)
{
__asm {

  mov  DL,asrc_bit
  mov ESI,alpsrc
  mov  DH,adst_bit
  mov EDI,alpdst
					
bitMov24_BIT_XXX:
  xor EAX,EAX
  mov  AX,[ESI+0] 		// dana src
  shl EAX,8
  mov  AL,[ESI+2] 		// dana src
  cmp  DL,0
	jz bitMov24_ESI_01 	// jeden bajt SRC?
  shl EAX,8
  mov  AL,[ESI+3]
bitMov24_ESI_01:
  mov  CL,DL
  shr EAX,CL
  and EAX,0x00FFFFFFL 		// and maska
  mov  CL,DH
  shl EAX,CL  
  cmp  DH,0
  jnz bitMov24_EDI_CL
  mov [EDI+0],AL
  shr EAX,8
  mov [EDI+1],AX
  jmp bitMov24_BIT_XXX_BREAK
bitMov24_EDI_CL:			
	or [EDI+0],AL        // xor dana dst
  shr EAX,8						
  mov [EDI+1],AL
  shr EAX,8						
  mov [EDI+2],AX
bitMov24_BIT_XXX_BREAK:
bitMov24_BIT_OK:
	}
}
//---------------------------------------------------------------------------

void __stdcall bitMov_32(void *alpdst, char adst_bit,void *alpsrc, char asrc_bit)
{
__asm {

  mov  DL,asrc_bit
  mov ESI,alpsrc
  mov  DH,adst_bit
  mov EDI,alpdst
					
bitMov32_BIT_XXX:
  mov EAX,[ESI+0] 		// dana src
  xor EBX,EBX
  cmp  DL,0
	jz bitMov32_ESI_01 	// jeden bajt SRC?
  mov  BL,[ESI+4]
bitMov32_ESI_01:
  mov  CL,DL
 shrd EAX,EBX,CL
  shr EBX,CL
  mov  CL,DH
 shld EBX,EAX,CL  
  shl EAX,CL
  cmp  DH,0
  jnz bitMov32_EDI_CL
  mov [EDI+0],EAX
  jmp bitMov32_BIT_XXX_BREAK
bitMov32_EDI_CL:			
	or [EDI+0],AL        // xor dana dst
 shrd EAX,EBX,8
  mov [EDI+1],EAX
bitMov32_BIT_XXX_BREAK:
bitMov32_BIT_OK:
	}
}


  */
