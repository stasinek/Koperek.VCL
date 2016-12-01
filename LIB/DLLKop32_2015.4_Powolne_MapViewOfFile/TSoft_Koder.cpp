//---------------------------------------------------------------------------
//-----------------Stanislaw Stasiak "TSoft_, where?" 2001-2002---------------
//---------------------------------------------------------------------------
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include "..\DLLIO\TSoft_IO.h"
#include "TSoft_BWTMatrix.h"
#include "TSoft_HDR.h"
#include "TSoft_BinTree.h"
#include "TSoft_Huff.h"
#include "TSoft_Ari.h"
#include "TSoft_Mtf.h"
#pragma hdrstop
#include "TSoft_Koder.h"

static unsigned long CRC32_tab[256] =
 {
  0x00000000, 0x77073096, 0xEE0E612C, 0x990951BA, 0x076DC419,
  0x706AF48F, 0xE963A535, 0x9E6495A3, 0x0EDB8832, 0x79DCB8A4,
  0xE0D5E91E, 0x97D2D988, 0x09B64C2B, 0x7EB17CBD, 0xE7B82D07,
  0x90BF1D91, 0x1DB71064, 0x6AB020F2, 0xF3B97148, 0x84BE41DE,
  0x1ADAD47D, 0x6DDDE4EB, 0xF4D4B551, 0x83D385C7, 0x136C9856,
  0x646BA8C0, 0xFD62F97A, 0x8A65C9EC, 0x14015C4F, 0x63066CD9,
  0xFA0F3D63, 0x8D080DF5, 0x3B6E20C8, 0x4C69105E, 0xD56041E4,
  0xA2677172, 0x3C03E4D1, 0x4B04D447, 0xD20D85FD, 0xA50AB56B,
  0x35B5A8FA, 0x42B2986C, 0xDBBBC9D6, 0xACBCF940, 0x32D86CE3,
  0x45DF5C75, 0xDCD60DCF, 0xABD13D59, 0x26D930AC, 0x51DE003A,
  0xC8D75180, 0xBFD06116, 0x21B4F4B5, 0x56B3C423, 0xCFBA9599,
  0xB8BDA50F, 0x2802B89E, 0x5F058808, 0xC60CD9B2, 0xB10BE924,
  0x2F6F7C87, 0x58684C11, 0xC1611DAB, 0xB6662D3D, 0x76DC4190,
  0x01DB7106, 0x98D220BC, 0xEFD5102A, 0x71B18589, 0x06B6B51F,
  0x9FBFE4A5, 0xE8B8D433, 0x7807C9A2, 0x0F00F934, 0x9609A88E,
  0xE10E9818, 0x7F6A0DBB, 0x086D3D2D, 0x91646C97, 0xE6635C01,
  0x6B6B51F4, 0x1C6C6162, 0x856530D8, 0xF262004E, 0x6C0695ED,
  0x1B01A57B, 0x8208F4C1, 0xF50FC457, 0x65B0D9C6, 0x12B7E950,
  0x8BBEB8EA, 0xFCB9887C, 0x62DD1DDF, 0x15DA2D49, 0x8CD37CF3,
  0xFBD44C65, 0x4DB26158, 0x3AB551CE, 0xA3BC0074, 0xD4BB30E2,
  0x4ADFA541, 0x3DD895D7, 0xA4D1C46D, 0xD3D6F4FB, 0x4369E96A,
  0x346ED9FC, 0xAD678846, 0xDA60B8D0, 0x44042D73, 0x33031DE5,
  0xAA0A4C5F, 0xDD0D7CC9, 0x5005713C, 0x270241AA, 0xBE0B1010,
  0xC90C2086, 0x5768B525, 0x206F85B3, 0xB966D409, 0xCE61E49F,
  0x5EDEF90E, 0x29D9C998, 0xB0D09822, 0xC7D7A8B4, 0x59B33D17,
  0x2EB40D81, 0xB7BD5C3B, 0xC0BA6CAD, 0xEDB88320, 0x9ABFB3B6,
  0x03B6E20C, 0x74B1D29A, 0xEAD54739, 0x9DD277AF, 0x04DB2615,
  0x73DC1683, 0xE3630B12, 0x94643B84, 0x0D6D6A3E, 0x7A6A5AA8,
  0xE40ECF0B, 0x9309FF9D, 0x0A00AE27, 0x7D079EB1, 0xF00F9344,
  0x8708A3D2, 0x1E01F268, 0x6906C2FE, 0xF762575D, 0x806567CB,
  0x196C3671, 0x6E6B06E7, 0xFED41B76, 0x89D32BE0, 0x10DA7A5A,
  0x67DD4ACC, 0xF9B9DF6F, 0x8EBEEFF9, 0x17B7BE43, 0x60B08ED5,
  0xD6D6A3E8, 0xA1D1937E, 0x38D8C2C4, 0x4FDFF252, 0xD1BB67F1,
  0xA6BC5767, 0x3FB506DD, 0x48B2364B, 0xD80D2BDA, 0xAF0A1B4C,
  0x36034AF6, 0x41047A60, 0xDF60EFC3, 0xA867DF55, 0x316E8EEF,
  0x4669BE79, 0xCB61B38C, 0xBC66831A, 0x256FD2A0, 0x5268E236,
  0xCC0C7795, 0xBB0B4703, 0x220216B9, 0x5505262F, 0xC5BA3BBE,
  0xB2BD0B28, 0x2BB45A92, 0x5CB36A04, 0xC2D7FFA7, 0xB5D0CF31,
  0x2CD99E8B, 0x5BDEAE1D, 0x9B64C2B0, 0xEC63F226, 0x756AA39C,
  0x026D930A, 0x9C0906A9, 0xEB0E363F, 0x72076785, 0x05005713,
  0x95BF4A82, 0xE2B87A14, 0x7BB12BAE, 0x0CB61B38, 0x92D28E9B,
  0xE5D5BE0D, 0x7CDCEFB7, 0x0BDBDF21, 0x86D3D2D4, 0xF1D4E242,
  0x68DDB3F8, 0x1FDA836E, 0x81BE16CD, 0xF6B9265B, 0x6FB077E1,
  0x18B74777, 0x88085AE6, 0xFF0F6A70, 0x66063BCA, 0x11010B5C,
  0x8F659EFF, 0xF862AE69, 0x616BFFD3, 0x166CCF45, 0xA00AE278,
  0xD70DD2EE, 0x4E048354, 0x3903B3C2, 0xA7672661, 0xD06016F7,
  0x4969474D, 0x3E6E77DB, 0xAED16A4A, 0xD9D65ADC, 0x40DF0B66,
  0x37D83BF0, 0xA9BCAE53, 0xDEBB9EC5, 0x47B2CF7F, 0x30B5FFE9,
  0xBDBDF21C, 0xCABAC28A, 0x53B39330, 0x24B4A3A6, 0xBAD03605,
  0xCDD70693, 0x54DE5729, 0x23D967BF, 0xB3667A2E, 0xC4614AB8,
  0x5D681B02, 0x2A6F2B94, 0xB40BBE37, 0xC30C8EA1, 0x5A05DF1B,
  0x2D02EF8D
};

//---------------------------------------------------------------------------
/*
Generate a table for a byte-wise 32-bit CRC calculation on the polynomial:
x^32+x^26+x^23+x^22+x^16+x^12+x^11+x^10+x^8+x^7+x^5+x^4+x^2+x+1.

Polynomials over GF(2) are represented in binary, one bit per coefficient,
with the lowest powers in the most significant bit.  Then adding polynomials
is just exclusive-or, and multiplying a polynomial by x is a right shift by
one.  If we call the above polynomial p, and represent a byte as the
polynomial q, also with the lowest power in the most significant bit (so the
byte 0xb1 is the polynomial x^7+x^3+x+1), then the CRC is (q*x^32) mod p,
where a mod b means the remainder after dividing a by b.

This calculation is done using the shift-register method of multiplying and
taking the remainder.  The register is initialized to zero, and for each
incoming bit, x^32 is added mod p to the register if the bit is a one (where
x^32 mod p is p+x^32 = x^26+...+1), and the register is multiplied mod p by
x (which is shifting right by one and adding x^32 mod p if the bit shifted
out is a one).  We start with the highest power (least significant bit) of
q and repeat for all eight bits of q.

The table is simply the CRC of all possible eight bit values.  This is all
the information needed to generate CRC's on data a byte at a time for all
combinations of CRC register values and incoming bytes.

Pseudo Code
Position = (byte_from_input XOR Crc_value) AND 0FFh
Table_value = Crc32_table[position]
Crc_value =  Crc_value >> 8
Crc_value = Crc_Value XOR table_value

unsigned long *lptab  = (unsigned long*)&CRC32_tab[0];
__asm {
 mov ESI,crc32
 mov EAX,[ESI]
 mov ESI,lptab
 xor AL,znak
 shr EAX,8
 xor EAX,[ESI+EBX]
 mov [ESI],EAX
	}
*/
//---------------------------------------------------------------------------

void __stdcall Make_CRC32_tab(void) {
const unsigned char POLY_tab[] = {0,1,2,4,5,7,8,10,11,12,16,22,23,26};
unsigned long POLY_nominal = 0x00000000L, n, k, c;

for (n = 0; n < sizeof(POLY_tab); n++)
	 {POLY_nominal |= 0x01L << (31-POLY_tab[n]);
	 }
for (n = 0; n < 256; n++)
	 {for (c = n, k = 0; k < 8; k++)
			{if (c & 1) c = (c >> 1) ^ POLY_nominal;
			else c = c >> 1;
			}
	  CRC32_tab[n] = c;
	 }
}
//---------------------------------------------------------------------------
/*
Pseudo Code
Crc_value = 0FFFFFFFFh
Loop (for all the bytes in input)
   position = (byte_from_input XOR Crc_value) AND 0FFh
   table_value = Crc32_table[position]
   Crc_value = Crc_value >> 8
   Crc_value = Crc_Value XOR table_value
then in the end
Crc_value = Crc_value XOR 0xFFFFFFFFh
*/
unsigned long __stdcall Calc_CRC32(void *alpDst,unsigned long acount)
{
static unsigned long *lptab = (unsigned long*)&CRC32_tab[0];
__asm {
 mov EDI,alpDst
 mov EDX,EDI
 add EDX,acount
 cmp EDI,EDX
 jnl Calc_CRC32_EXIT

 mov ESI,lptab
 mov EAX,0xFFFFFFFFL
 xor EBX,EBX

Calc_CRC32_NEXT:

 mov BL,[EDI]
 xor BL,AL
 shr EAX,8
 xor EAX,[ESI+EBX]
 inc EDI
 cmp EDI,EDX
 jl  Calc_CRC32_NEXT

 xor EAX,0xFFFFFFFFL

Calc_CRC32_EXIT:
   }
}
//---------------------------------------------------------------------------
#define num_BASE 65521L
/* largest prime smaller than 65536 */
#define num_MAX 5552
/* NMAX is the largest n such that 255n(n+1)/2 + (n+1)(BASE-1) <= 2^32-1 */
/*
Pseudo Code
loop (for all the bytes in input)
   for (num_MAX bytes)
	  s0 += byte from input
	  s1 += s0
   s0 = Adler_lo_value % num_MAX
   s1 = Adler_hi_value % num_MAX
in the end
Adler_value = s1<<16 | s2
*/
unsigned long __stdcall Calc_ADLER32(void *alpDst,unsigned long acount)
{
__asm {
 mov EDI,alpDst
 mov EDX,EDI
 add EDX,acount
 cmp EDI,EDX
 jnl Calc_ADLER32_EXIT

 mov ESI,num_MAX
 xor EAX,EAX
 xor EBX,EBX
 xor ECX,ECX

Calc_ADLER32_NEXT:

 mov CL,[EDI]
 add AX,CX
 add BX,AX
 dec ESI
test ESI,ESI
 jnz Calc_ADLER32_INC
push EDX
 mov EBX,num_BASE
// cdq
 div EBX
push EDX
 mov EAX,EBX
// cdq
 div EBX
push EDX

 pop EBX
 pop EAX
 pop EDX
 mov ESI,num_MAX

Calc_ADLER32_INC:
 inc EDI
 cmp EDI,EDX
 jl  Calc_ADLER32_NEXT
 shl EAX,16
  or AX,BX

Calc_ADLER32_EXIT:
	}
}
//---------------------------------------------------------------------------

unsigned long __stdcall Compress_LZS(void *alpDst, void *alpSrc,unsigned long acount,unsigned long adict)
{
unsigned long hist[256],hist_max=0; ZeroMemory(&hist,4*256); // for debuging,statistics


unsigned long  ptrs     = (unsigned long)alpSrc;
unsigned long  ptrs_end = (unsigned long)alpSrc + acount;
unsigned long  ptrd     = (unsigned long)alpDst;
unsigned long  ptmp;
unsigned long  ptmp_end;
//------------------------------------------
unsigned long  pass_text_length = 0;
unsigned char *pass_text_ptr = (unsigned char*)ptrs;
unsigned long  pass_skip_length = 0;
//------------------------------------------
TSoft_Huff huff;
           huff.Initialize();
TSoft_BinTree tree(adict,acount);
             tree.Initialize((char*)ptrs);
//------------------------------------------
while (1) {
//------------------------------------------
//------------------------------------------
// sprawdz koniec
	if (ptrs + pass_skip_length + tree.find_max_length >= ptrs_end)
	if (ptrs + pass_skip_length + 8 >= ptrs_end)
       {ptrs +=pass_skip_length;
        pass_text_length += ptrs_end - ptrs;
        break;
       }
    else
       {tree.find_max_length = ptrs_end - ptrs - pass_skip_length;
	   }
//------------------------------------------
LZS_UPDATE_DICT:
//------------------------------------------
// delete, copy, insert
	tree.Update((char*)ptrs,pass_skip_length);
	ptrs+=pass_skip_length;
//------------------------------------------
LZS_BRUN:
//------------------------------------------
	tree.Search_brun();
	if (tree.brun_length!=1) {
	    if (tree.Optimum_brun_match(tree.brun_length,pass_text_length)!=0)
	        goto LZS_SAVE_PASS;
	    tree.brun_length =1;
	}
//------------------------------------------
LZS_GREEDY:
//------------------------------------------
	tree.Search_dict();
	if (tree.find_length!=0) {
	    if (tree.Optimum_dict_match(tree.find_length,pass_text_length)!=0)
	        goto LZS_SAVE_PASS;
	    tree.find_length =0;
	}
//------------------------------------------
LZS_NOTHING:
//------------------------------------------
	if (pass_text_length>=FIND_MAX) {
	    pass_skip_length =0;
	        goto LZS_SAVE_PASS;
    }
	pass_skip_length =1;
	pass_text_length+=1;

	continue;
//------------------------------------------
LZS_SAVE_PASS:
//------------------------------------------
	if (pass_text_length==0) {
	    goto LZS_SAVE_BRUN;
	}

#define SAVE_PASS()                                                                     \
	ptrd+=tree.hdrcoder.Code_ptrPass((DWORD*)ptrd,pass_text_length);	                \
	ptrEql((char*)ptrd,(char*)pass_text_ptr,pass_text_length);			                \
	ptrd+=pass_text_length;

	SAVE_PASS();
    hist[pass_text_length]++;
    if (hist[pass_text_length]>hist_max)
    hist_max=hist[pass_text_length];
	pass_text_ptr =(unsigned char*)ptrs;
	pass_text_length = 0;
	/*for (ptmp = (DWORD)pass_text_ptr, ptmp_end = ptmp+pass_text_length; ptmp < ptmp_end; ptmp++) { \
	ptrd_bit+= huff.Encode((char*)ptrd,ptrd_bit,((char*)ptmp)[0]);					                 \
		 ptrd+= ptrd_bit>>3;                                                     	                 \
	ptrd_bit = ptrd_bit & (8-1);                                                	                 \
	} */

//------------------------------------------
LZS_SAVE_BRUN:
//------------------------------------------
	if (tree.brun_length==1) {
	    goto LZS_SAVE_DICT;
	}
#define SAVE_BRUN()                                                                     \
    ptrd+=tree.hdrcoder.Code_ptrBrun((DWORD*)ptrd,tree.brun_elsize,tree.brun_counte);   \
    ptrEql((char*)ptrd,(char*)ptrs,tree.brun_elsize);                                   \
    ptrd+=tree.brun_elsize;

	SAVE_BRUN();
    hist[tree.brun_counte]++;
    if (hist[tree.brun_counte]>hist_max)
    hist_max=hist[tree.brun_counte];
	pass_text_ptr =(unsigned char*)ptrs + tree.brun_length;
	pass_skip_length = tree.brun_length;
	/*for (ptmp = (DWORD)ptrs, ptmp_end = ptmp+tree.brun_elsize; ptmp < ptmp_end; ptmp++) {     \
	ptrd_bit+= huff.Encode((char*)ptrd,ptrd_bit,((char*)ptmp)[0]);		  	 	                \
		 ptrd+= ptrd_bit>>3;                                                     	            \
	ptrd_bit = ptrd_bit & (8-1);                                                	            \
	} */

	continue;
//------------------------------------------
LZS_SAVE_DICT:
//------------------------------------------
	if (tree.find_length==0) {
	    continue;
	}
#define SAVE_DICT()                                                                     \
	ptrd+=tree.hdrcoder.Code_ptrDict((DWORD*)ptrd,tree.find_offset,tree.find_length);

	SAVE_DICT();
    hist[tree.find_length]++;
    if (hist[tree.find_length]>hist_max)
    hist_max=hist[tree.find_length];
	pass_text_ptr =(unsigned char*)ptrs + tree.find_length;
	pass_skip_length = tree.find_length;
	continue;
//------------------------------------------
}
//------------------------------------------
LZS_SAVE_REST:
if (pass_text_length!=0) {
    SAVE_PASS();
   }
//------------------------------------------
/*char bar[64+1];
for (int i = 0,x=0; i < 256; i++)
{
strcpy(bar,"################################################################");
x = ((64*hist[i])/hist_max);
bar[x]='\0';
printf("%d=%5d%s\n",i,hist[i],bar);
}
*/
return (unsigned long)ptrd - (unsigned long)alpDst;
}
//---------------------------------------------------------------------------

void __stdcall UnCompress_LZS(void *alpDst, unsigned long acount, void *alpSrc)
{
unsigned long ptrs     = (unsigned long)alpSrc;
unsigned long ptrd     = (unsigned long)alpDst;
unsigned long ptrd_end = (unsigned long)alpDst + acount;
unsigned long ptmp;
unsigned long ptmp_end;
//------------------------------------------
unsigned long cnt,ofs,siz;
unsigned char hdr;
//------------------------------------------
TSoft_Huff huff;
          huff.Initialize();
__bitptr_hdrcoder hdrcoder;
//------------------------------------------
for (;ptrd < ptrd_end;) {
//------------------------------------------
        hdr = ((char*)ptrs)[0] & XMODE_MASK;
	if (hdr==XDICT_CODE)
		goto LZS_LOAD_DICT_STANDARD;
	if (hdr==XBRUN_CODE)
		goto LZS_LOAD_BRUN_STANDARD;
	if (hdr==XPASS_CODE)
		goto LZS_LOAD_PASS_STANDARD;

//------------------------------------------
LZS_LOAD_PASS_STANDARD:
//------------------------------------------
	 ptrs+= hdrcoder.DeCode_ptrPass(&cnt,(DWORD*)ptrs);
     ptrEql((void*)ptrd,(void*)ptrs,cnt);
     ptrs+= cnt;
     ptrd+= cnt;
	 /*for (; cnt!=0; cnt--) {
	 ptrs_bit+= huff.Decode((unsigned char*)ptrd++,(unsigned char*)ptrs,ptrs_bit);
		  ptrs+= ptrs_bit>>3;
	 ptrs_bit = ptrs_bit & (8-1);
	 }*/
	 continue;
//------------------------------------------
LZS_LOAD_DICT_STANDARD:
//------------------------------------------
	 ptrs+= hdrcoder.DeCode_ptrDict(&ofs,&cnt,(DWORD*)ptrs);
	 ptrEql((char*)ptrd,(unsigned char*)(ptrd-ofs),cnt);
	 ptrd+= cnt;
	 continue;
//------------------------------------------
LZS_LOAD_BRUN_STANDARD:
//------------------------------------------
	 ptrs+= hdrcoder.DeCode_ptrBrun(&siz,&cnt,(DWORD*)ptrs);
	 ptrSetEx((char*)ptrd,(char*)ptrs,siz,cnt);
	 ptrs+= siz;
	 ptrd+= siz*cnt;
	/*for (ptmp = ptrd, ptmp_end = ptmp+siz; ptmp < ptmp_end; ptmp++) {
	 ptrs_bit+= huff.Decode((unsigned char*)ptmp,(unsigned char*)ptrs,ptrs_bit);
		  ptrs+= ptrs_bit>>3;
	 ptrs_bit = ptrs_bit & (8-1);
	 }
	 bitSet((char*)ptmp_end,(char*)ptmp,0,siz,cnt-1);
		  ptrd+= siz*cnt;  */
	 continue;
//------------------------------------------
}
//------------------------------------------
}
//---------------------------------------------------------------------------

unsigned long __stdcall Compress_HUF(void *alpDst, void *alpSrc, unsigned long acount, unsigned short ablock)
{
unsigned long ptrs     = (unsigned long)alpSrc;
unsigned long ptrs_end = (unsigned long)alpSrc + acount;
unsigned long ptrd     = (unsigned long)alpDst;
unsigned char ptrd_bit = 0;

TSoft_Huff huff;
          huff.Initialize();
//------------------------------------------
for ( ;ptrs < ptrs_end; ptrs++) {
//------------------------------------------
       ptrd_bit += huff.Encode((unsigned char*)ptrd,ptrd_bit,((unsigned char*)ptrs)[0]);
	   ptrd += ptrd_bit>>3;
	   ptrd_bit = ptrd_bit & (8-1);
//------------------------------------------
    }
//------------------------------------------
bitEql((char*)ptrd,ptrd_bit,"\0\0\0\0",0,32-ptrd_bit);
ptrd+=4;
return ptrd - (unsigned long)alpDst;
}
//---------------------------------------------------------------------------

void __stdcall UnCompress_HUF(void *alpDst, unsigned long acount, void *alpSrc)
{
unsigned long ptrs     = (unsigned long)alpSrc;
unsigned char ptrs_bit = 0;
unsigned long ptrd     = (unsigned long)alpDst;
unsigned long ptrd_end = (unsigned long)alpDst + acount;
//------------------------------------------
TSoft_Huff huff;
          huff.Initialize();
//------------------------------------------
for ( ;ptrd < ptrd_end; ptrd++) {
//------------------------------------------
	   ptrs_bit += huff.Decode((unsigned char*)ptrd,(unsigned char*)ptrs,ptrs_bit);
	   ptrs += ptrs_bit>>3;
	   ptrs_bit = ptrs_bit & (8-1);
//------------------------------------------
	}
//------------------------------------------
}
//---------------------------------------------------------------------------

unsigned long __stdcall Compress_ARI(void *alpDst, void *alpSrc, unsigned long acount, unsigned short ablock)
{
unsigned long ptrs     = (unsigned long)alpSrc;
unsigned long ptrs_end = (unsigned long)alpSrc + acount;
unsigned long ptrd     = (unsigned long)alpDst;
unsigned char ptrd_bit = 0;

TSoft_Ari ari;
         ari.Initialize_Encoder();
//------------------------------------------
for ( ;ptrs < ptrs_end; ptrs++)	{
//------------------------------------------
       ptrd_bit += ari.Encode((unsigned long*)ptrd,ptrd_bit,((unsigned char*)ptrs)[0]);
	   ptrd += ptrd_bit>>3;
	   ptrd_bit = ptrd_bit & (8-1);
//------------------------------------------
    }
//------------------------------------------
       ptrd_bit += ari.Flush_Encoder((unsigned long*)ptrd,ptrd_bit);
	   ptrd += ptrd_bit>>3;
//------------------------------------------
return ptrd - (unsigned long)alpDst;
}
//---------------------------------------------------------------------------

void __stdcall UnCompress_ARI(void *alpDst, unsigned long acount, void *alpSrc)
{
unsigned long ptrs     = (unsigned long)alpSrc;
unsigned char ptrs_bit = 0;
unsigned long ptrd     = (unsigned long)alpDst;
unsigned long ptrd_end = (unsigned long)alpDst + acount;
//------------------------------------------
TSoft_Ari ari;
	   ptrs_bit += ari.Initialize_Decoder((unsigned long*)ptrs,ptrs_bit);
	   ptrs += ptrs_bit>>3;
	   ptrs_bit = ptrs_bit & (8-1);
//------------------------------------------
for ( ;ptrd < ptrd_end; ptrd++) {
//------------------------------------------
	   ptrs_bit += ari.Decode((unsigned char*)ptrd,(unsigned long*)ptrs,ptrs_bit);
	   ptrs += ptrs_bit>>3;
	   ptrs_bit = ptrs_bit & (8-1);
//------------------------------------------
	}
//------------------------------------------
}
//---------------------------------------------------------------------------

void __stdcall Cript_MTF(void *alpDst,unsigned long acount)
{
unsigned long ptrd     = (unsigned long)alpDst;
unsigned long ptrd_end = (unsigned long)alpDst + acount;
TSoft_Mtf mtf;
		 mtf.Initialize();
//------------------------------------------
for ( ;ptrd < ptrd_end; ptrd++) {
//------------------------------------------
	((unsigned char*)ptrd)[0] = mtf.Encode(((unsigned char*)ptrd)[0]);
//------------------------------------------
	}
//------------------------------------------
}
//---------------------------------------------------------------------------

void __stdcall UnCript_MTF(void *alpDst,unsigned long acount)
{
unsigned long ptrd     = (unsigned long)alpDst;
unsigned long ptrd_end = (unsigned long)alpDst + acount;
TSoft_Mtf mtf;
		 mtf.Initialize();
//------------------------------------------
for (;ptrd < ptrd_end; ptrd++) {
//------------------------------------------
	 ((unsigned char*)ptrd)[0] = mtf.Decode(((unsigned char*)ptrd)[0]);
//------------------------------------------
	 }
//------------------------------------------
}
//---------------------------------------------------------------------------

void __stdcall Cript_XOR(void *alpDst,unsigned long acount, char *alpHaslo,unsigned char aHaslo_count)
{
__asm {
  mov EDI,alpDst
  mov EDX,EDI
  add EDX,acount
  cmp EDI,EDX
  jnl Cript_XOR_EXIT
  mov ESI,alpHaslo
movzx ECX,aHaslo_count
  add ECX,ESI
  cmp ESI,ECX
  jnl Cript_XOR_EXIT
  mov EBX,ESI
Cript_XOR_LOOP:
  mov AL,[ESI]
  xor [EDI],AL
  inc ESI
  cmp ESI,ECX
   jl Cript_XOR_PASS
  mov ESI,EBX
Cript_XOR_PASS:
  inc EDI
  cmp EDI,EDX
   jl Cript_XOR_LOOP
  mov ESI,EBX
Cript_XOR_EXIT:
}
}
//---------------------------------------------------------------------------

void __stdcall UnCript_XOR(void *alpDst,unsigned long acount, char *alpHaslo,unsigned char aHaslo_count)
{
Cript_XOR(alpDst,acount,alpHaslo,aHaslo_count);
}
//---------------------------------------------------------------------------

void __stdcall Cript_SXQ(void *alpDst,unsigned long acount,unsigned char aHaslo_count)
{
if (aHaslo_count<=1)
	{return;
	}
unsigned short buff_count = aHaslo_count;
unsigned short buff_sq = buff_count * buff_count;
char *buff_ptr = strAlloc(buff_count+1);
unsigned long ptrd 	   =(unsigned long)alpDst;
unsigned long ptrd_end =(unsigned long)alpDst + acount - buff_count;
__asm {
movzx EAX,buff_count
movzx EBX,buff_sq
  mov EDI,ptrd
  mov EDX,ptrd_end
  cmp EDI,EDX
   ja Cript_SXQ_BREAK
  nop
Cript_SXQ_main_LOOP:
  xor ECX,ECX
  mov ESI,buff_ptr
 push EDX
  xor EDX,EDX
Cript_SXQ_buff_count:
Cript_SXQ_sq:
 push EAX
  mov  AL,[EDI+ECX]
  mov [ESI],AL
  pop EAX
  inc ESI
  add  CX,AX
  cmp  CX,BX
   jl Cript_SXQ_sq
  sub  CX,BX
  inc  DX
  inc  CX
  cmp  DX,AX
 jnae Cript_SXQ_buff_count
  pop EDX
  mov ESI,buff_ptr
  cld
movzx ECX,BX
  shr ECX,2
  rep MOVSD
movzx ECX,BX
  and ECX,3
  rep MOVSB
  cmp EDI,EDX
  jna Cript_SXQ_main_LOOP
  nop
Cript_SXQ_BREAK:
	}
strFree(buff_ptr);
}
//---------------------------------------------------------------------------

void __stdcall UnCript_SXQ(void *alpDst,unsigned long acount,unsigned char aHaslo_count)
{
Cript_SXQ(alpDst,acount,aHaslo_count);
}
//---------------------------------------------------------------------------
/*
unsigned long __stdcall Compress_BWT(void *alpDst, void *alpSrc, unsigned long asize, unsigned short ablock)
{
unsigned long ptrz     = (unsigned long)alpSrc;
unsigned long ptrz_end = (unsigned long)alpSrc + asize;
unsigned long ptrc     = (unsigned long)alpDst;

unsigned __int8 *macAcc;
macAcc = (unsigned __int8*)LocalAlloc(LPTR,GRAD*2);
unsigned long mD;
unsigned long mY;
unsigned long **mac;
mac =  (unsigned long**)LocalAlloc(LPTR,GRAD*4);

__int8  s_01 = 0;
long  mYB[2][GRAD];
long *mYBs0,*mYBs1;
long  mYE[2][GRAD];
long *mYEs0,*mYEs1;
long  mC[2];
long  mCs0, mCs1;

for (long X,Y,Y1,Y2,YE,p; ptrz <= ptrz_end - GRAD;)
	{
	 //
	 // reverse copying BARBAKAN->>NAKABRAB
	 //
	 for (Y1 = GRAD-1, Y2 = 0; Y1 >= 0; Y1--, Y2++)
	 	   {macAcc[Y1] = ((__int8*)ptrz)[Y2];
		  macAcc[GRAD+Y1] = ((__int8*)ptrz)[Y2];
		 }
	 ptrz+=GRAD;

	 ptrMov(mac,macAcc,sizeof(long)*GRAD);
//	  for (Y = 0; Y < GRAD; Y++)
//	 	   {mac[Y] = (unsigned long*)(&macAcc[Y]);
//		 }
	  mC[s_01]=1;
	 mYB[s_01][0] = 0;
	 mYE[s_01][0] = GRAD-1;

	 for (X = GRAD/4-1, mCs1=1; mCs1!=0; X--)
		 {
		  mYBs0 = mYB[s_01];
		  mYEs0 = mYE[s_01];
		   mCs0 =  mC[s_01];

	 	  for (p = 0; p < mCs0 ; p++)
	 		  {
	 		   for (Y1 = mYBs0[p], YE = mYEs0[p]; Y1 <= YE; Y1++)
  		   {
					mY = Y1;
		  		mD = mac[Y1][X];

	   	  		for (Y2 = Y1+1; Y2 <= YE; Y2++) // find first lower
  		   	{
			   	 if (mD > mac[Y2][X])
				  		{mD = mac[Y2][X];
							 mY = Y2;
							}
			  		}
		   		 if ((long)mY!=Y1)
			  		{	 mD = (unsigned long)mac[Y1];
		   			 mac[Y1] = mac[mY];
					   	 mac[mY] = (unsigned long*)mD;
			  		}
		 	   }
			  }
		   if (X==0) break;

		   s_01 = !s_01;
		  mYBs1 = mYB[s_01];
		  mYEs1 = mYE[s_01];
		   mCs1 = 0;

	 	  for (p = 0; p < mCs0; p++)
			  {
		   for (Y = mYBs0[p], YE = mYEs0[p]; Y <= YE; Y = Y2)
   			   {
					for (mD = mac[Y][X],Y2=++Y; Y2 <= YE; Y2++)
						{
						 if (mD!=mac[Y2][X])
							 break;
						}
  				 if (Y2 > Y)
						{
	   				 mYBs1[mCs1]=Y-1; mYEs1[mCs1]=Y2-1; mCs1++;
	  				}
				   }
		  }
		   mC[s_01] = mCs1;
		 }
	 for (Y1=0; (long)mac[Y1]!=(long)macAcc;)
		 {Y1++;
		 }
	 for (Y =0; Y < GRAD; Y++)
		 {
		  ((__int8*)ptrc)[Y] = *((__int8*)(mac[Y]));
		 }
	 ptrc+=GRAD;
	 ((__int8*)ptrc)[0] = (__int8)Y1;
	 ptrc+=sizeof(__int8);
	}
for (;ptrz < ptrz_end;)
	{
	 *((__int8*)ptrc++) = *((__int8*)ptrz++);
	}
LocalFree(macAcc);
LocalFree(mac);

return (unsigned long)ptrc - (unsigned long)alpDst;
}
//---------------------------------------------------------------------------

void __stdcall UnCompress_BWT(void *alpDst, unsigned long asize, void *alpSrc)
{
unsigned long ptrz     = (unsigned long)alpSrc;
unsigned long ptrc     = (unsigned long)alpDst;
unsigned long ptrc_end = (unsigned long)alpDst + asize;

unsigned __int16 *mac = (unsigned __int16*)LocalAlloc(LPTR,GRAD*2);
unsigned __int16  mD, mY;

for (long Y,Y1,Y2,Z; ptrc+GRAD <= ptrc_end;)
	{
	 for (Y = 0; Y < GRAD; Y++)
		 {
		  mac[Y] = (((unsigned __int8*)ptrz)[Y]<<8) | (unsigned __int8)Y; // hiBYTE=znak, loBYTE=pos
		 }
	 ptrz+=GRAD;

	 for (Y1 = 0; Y1 < GRAD; Y1++)
  	 {
		  mD = mac[Y1];
		  mY = Y1;

	   	  for (Y2 = Y1+1; Y2 < GRAD; Y2++)
  		  {
			   if (mD > mac[Y2])
				  {mD = mac[Y2];
				   mY = Y2;
				  }
			  }
		   if (mY!=Y1)
			  {
					mD = mac[Y1];
		   mac[Y1] = mac[mY];
			   mac[mY] = mD;
			  }
		 }
	 for (Y = *((unsigned __int8*)ptrz++), Z = 0; Z < GRAD; Z++, Y = LOBYTE(mac[Y]))
		 {
		  ((__int8*)ptrc)[Z] = HIBYTE(mac[Y]);
		 }
	 ptrc+=GRAD;
	}
for (;ptrc < ptrc_end;)
	{
	 *((__int8*)ptrc++) = *((__int8*)ptrz++);
	}
LocalFree(mac);
}
*/


unsigned long __stdcall Compress_BWT(void *alpDst, void *alpSrc, unsigned long acount, unsigned short ablock)
{
unsigned long  ptrs     = (unsigned long)alpSrc;
unsigned long  ptrs_end = (unsigned long)alpSrc + acount;
unsigned long  ptrd     = (unsigned long)alpDst;
//------------------------------------------
TSoft_BWTMatrix bwt(ablock);
//------------------------------------------
	((WORD*)ptrd)[0] = bwt.matrix_dim;
	ptrd+=2;
//------------------------------------------
while (ptrs <= ptrs_end - bwt.matrix_dim) {
//------------------------------------------
	bwt.Generate((unsigned char*)ptrs);
	ptrs+=bwt.matrix_dim;
	((WORD*)ptrd)[0] = bwt.Sort();
	ptrd+=2;
	bwt.Flush((unsigned char*)ptrd);
	ptrd+=bwt.matrix_dim;
//------------------------------------------
}
//------------------------------------------
	((WORD*)ptrd)[0]=0;
	ptrd+=2;
while (ptrs < ptrs_end)
	{*((char*)ptrd++) = *((char*)ptrs++);
	}
//------------------------------------------
return (unsigned long)ptrd - (unsigned long)alpDst;
}
//---------------------------------------------------------------------------

void __stdcall UnCompress_BWT(void *alpDst, unsigned long acount, void *alpSrc)
{
unsigned long ptrs     = (unsigned long)alpSrc;
unsigned long ptrd     = (unsigned long)alpDst;
unsigned long ptrd_end = (unsigned long)alpDst + acount;
ptrEql(alpDst,alpSrc,acount - 2*acount/(1024) - 2);
}


//-------------------------------THE END-------------------------------------
