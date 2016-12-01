//---------------------------------------------------------------------------
#include <windows.h>
#include "..\DLLIO\TSoft_IO.h"
#pragma hdrstop
#include "TSoft_Ari.h"
//---------------------------------------------------------------------------

/*  If you are not familiar with arithmetic compression, you should read
		I. E. Witten, R. M. Neal, and J. G. Cleary,
			Communications of the ACM, Vol. 30, pp. 520-540 (1987),
	from which much have been borrowed.  */

#define M   15

/*	Q1 (= 2 to the M) must be sufficiently large, but not so
	large as the unsigned long 4 * Q1 * (Q1 - 1) overflows.  */

#define Q1  	 (1UL << M)
#define Q2  	 (2 * Q1)
#define Q3  	 (3 * Q1)
#define Q4  	 (4 * Q1)
#define MAX_CUMF (Q1 - 1)

#define CNUM 256

#define OUT_BIT_0(code,u,bits)           \
    {code=(code>>(u+1)) | ((0x10000000-((0x10000000>>u)-1))<<1); \
     bits+=u+1;                          \
     u=0;                                \
    }

#define OUT_BIT_1(code,u,bits) \
    {code=(code>>(u+1)) | ((0x10000000>>u));   \
     bits+=1+u;                          \
     u=0;                                \
    }


__stdcall TSoft_Ari::TSoft_Ari(void)
{
char_to_symb = (unsigned long*)LocalAlloc(LMEM_FIXED,sizeof(unsigned long)*(CNUM));
symb_to_char = (unsigned long*)LocalAlloc(LMEM_FIXED,sizeof(unsigned long)*(CNUM+1));
symb_cumf    = (unsigned long*)LocalAlloc(LMEM_FIXED,sizeof(unsigned long)*(CNUM+1));  /* cumulative freq for symbols */
symb_freq    = (unsigned long*)LocalAlloc(LMEM_FIXED,sizeof(unsigned long)*(CNUM+1));  /* frequency for symbols */
}
//---------------------------------------------------------------------------

__stdcall TSoft_Ari::~TSoft_Ari(void)
{
LocalFree(char_to_symb);
LocalFree(symb_freq);
LocalFree(symb_to_char);
LocalFree(symb_cumf);
}
//---------------------------------------------------------------------------

void __stdcall TSoft_Ari::Initialize()
{
//------------------
low = 0, high = Q4, value = 0, underflow_bits = 0;
//------------------
register unsigned long c, i, f;
//------------------
f = 0;
for (i = CNUM; i!=0; i--) {
	 c = i - 1;
	 char_to_symb[c] = i;
     symb_to_char[i] = c;
	 symb_cumf[i] = f;
	 symb_freq[i] = 1;
     f+=1;
}
symb_cumf[0] = f;
symb_freq[0] = 0;
//------------------
}
//---------------------------------------------------------------------------

void __stdcall TSoft_Ari::Update(unsigned long axdata_uncoded)
{
//------------------
register unsigned long symb = axdata_uncoded;
//------------------
register unsigned long i, f;
//------------------
if (symb_cumf[0] >= MAX_CUMF) {
//------------------
    f = 0;
    for (i = CNUM; i!=0; i--) {
	     symb_cumf[i] = f;
	     symb_freq[i] = (symb_freq[i]+1)>>1;
         f += symb_freq[i];
	}
	symb_cumf[0] = f;
//------------------
}
//------------------
register unsigned long char_i, char_symb;
for (i = symb; symb_freq[i]==symb_freq[i-1]; i--);
 if (i < symb) {
     char_i = symb_to_char[i];
     char_symb = symb_to_char[symb];
	 symb_to_char[i]    = char_symb;
     symb_to_char[symb] = char_i;
   	 char_to_symb[char_i]    = symb;
     char_to_symb[char_symb] = i;
    }
//------------------
symb_freq[i]++;
for (;i!=0;i--) symb_cumf[i-1]++;
//------------------
}
//---------------------------------------------------------------------------

unsigned int __stdcall TSoft_Ari::Search(unsigned long x)
{
register unsigned long l, h, c;

for (l = 1, h = CNUM; l < h; ) {
	 c = (l + h) >> 1;
	 if (symb_cumf[c] > x) l = c + 1;
	 else h = c;
}
return l;
}
//---------------------------------------------------------------------------

void __stdcall TSoft_Ari::Initialize_Encoder(void)
{
Initialize();
}
//---------------------------------------------------------------------------

unsigned char __stdcall TSoft_Ari::Encode(unsigned long *alpcode, unsigned char alpcode_bit, unsigned char axdata_uncoded)
{
//------------------
register unsigned long l = low, h = high;
unsigned long r = h - l;
unsigned long symb = char_to_symb[axdata_uncoded];
//------------------
h = l + ((r * symb_cumf[symb-1]) / symb_cumf[0]);
l = l + ((r * symb_cumf[symb-0]) / symb_cumf[0]);
//------------------
register unsigned long code = 0;
register unsigned char u = underflow_bits;
register unsigned char bits = 0;
//------------------
for (;;) {
//------------------
 if (h <= Q2) {
     OUT_BIT_0(code,u,bits)
 }
 else
 if (l >= Q2) {
 	 l -= Q2;
     h -= Q2;
     OUT_BIT_1(code,u,bits)
 }
 else
 if (l >= Q1 && h <= Q3) {
     l -= Q1;
     h -= Q1;
     u++;
 }
 else break;
//------------------
     l += l;
     h += h;
//------------------
}
//------------------
low = l; high = h; underflow_bits = u;
Update(symb);
unsigned long result = code;
bitEql(alpcode,alpcode_bit,&result,0,bits);
return bits;
}
//---------------------------------------------------------------------------

unsigned char __stdcall TSoft_Ari::Flush_Encoder(unsigned long *alpcode, unsigned char alpcode_bit)
{
//------------------
register unsigned char bits = 0;
register unsigned long code = 0;
//------------------
register unsigned char u = ++underflow_bits;

if (low < Q1) OUT_BIT_0(code,u,bits)
else
    OUT_BIT_1(code,u,bits)

unsigned long result = code;
bitEql(alpcode,alpcode_bit,&result,0,bits);
alpcode_bit += bits;
alpcode += alpcode_bit>>3;
alpcode_bit &= (8-1);
alpcode[0]&=(0xFFFFFFFF>>(32-alpcode_bit));
return 32-alpcode_bit+bits;
}
//---------------------------------------------------------------------------

unsigned char __stdcall TSoft_Ari::Initialize_Decoder(unsigned long *alpcode, unsigned char alpcode_bit)
{
Initialize();
//------------------
register unsigned char bits = 0;
register unsigned long code;
//------------------
register unsigned long v = value;
//------------------
unsigned long indata;
bitEql(&indata,0,alpcode,alpcode_bit,32);
code =  indata;
//------------------
register int i;
//------------------
for (i = 0; i < M + 2; i++) {
	 v = v<<1 + (code&1);
     code=code>>1;
     bits++;
    }
value = v;
return bits;
}
//---------------------------------------------------------------------------

unsigned char __stdcall TSoft_Ari::Decode(unsigned char *alpdata_uncoded,unsigned long *alpcode, unsigned char alpcode_bit)
{
//------------------
register unsigned char bits = 0;
register unsigned long code;
register unsigned long v = value;
register unsigned long l = low, h = high, r = h - l;
register unsigned long symb = Search((unsigned int)(((v - l + 1) * symb_cumf[0] - 1) / r));
//------------------
h = l + (r * symb_cumf[symb - 1]) / symb_cumf[0];
l = l + (r * symb_cumf[symb - 0]) / symb_cumf[0];
//------------------
unsigned long indata;
bitEql(&indata,0,alpcode,alpcode_bit,32);
code =  indata;
//------------------
for (;;) {
//------------------
	if (l >= Q2) {
		l -= Q2;
		h -= Q2;
		v -= Q2;
	}
	else
	if (l >= Q1 && h <= Q3) {
		l -= Q1;
		h -= Q1;
		v -= Q1;
	}
	else if (h > Q2) break;
//------------------
	l += l;
	h += h;
	v = v<<1 + (code&1);
    code=code>>1;
    bits++;
//------------------
}
//------------------
alpdata_uncoded[0] = symb_to_char[symb];
//------------------
low = l; high = h; value = v;
Update(symb);
return bits;
}
//---------------------------------------------------------------------------

void __stdcall TSoft_Ari::Flush_Decoder(void)
{
}
//-------------------------------THE END-------------------------------------

