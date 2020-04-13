//---------------------------------------------------------------------------
#include <windows.h>
#include "..\DLLIO\TSoft_IO.h"
#pragma hdrstop
#include "TSoft_Huff.h"
//---------------------------------------------------------------------------
#define CNUM	 (256) 		   /* kinds of characters (character code = 0..N_CHAR-1) */
#define TREE 	 (CNUM*2-1)    /* size of table */
#define ROOT 	 (TREE-1)      /* position of root */
#define MAX_FREQ (0x80000000)  /* 8*chars encoded so max size 2^28=250MB updates tree when the root frequency comes to this value. */
#define MAX_TREE (0xFFFFFFFF)
//---------------------------------------------------------------------------

__stdcall TSoft_Huff::TSoft_Huff(void)
{
dad = (unsigned long*)LocalAlloc(LMEM_FIXED,sizeof(unsigned long)*(TREE+CNUM));
son = (unsigned long*)LocalAlloc(LMEM_FIXED,sizeof(unsigned long)*(TREE));
frq = (unsigned long*)LocalAlloc(LMEM_FIXED,sizeof(unsigned long)*(TREE+1));
}
//---------------------------------------------------------------------------

__stdcall TSoft_Huff::~TSoft_Huff(void)
{
LocalFree(dad);
LocalFree(son);
LocalFree(frq);
}
//---------------------------------------------------------------------------

void __stdcall TSoft_Huff::Initialize(void)
{
register int  i, e;
//----------------------
for (i = 0; i < CNUM; i++) {
//----------------------
	 son[i] = TREE + i;
	 dad[TREE + i] = i;
	 frq[i] = 1;
	}
//----------------------
for (i = 0, e = CNUM; e < TREE; i+=2, e++) {
//----------------------
	 son[e]   = i;
	 frq[e]   = frq[i] + frq[i+1];
     dad[i+0] = e;
	 dad[i+1] = e;
	}
//----------------------
dad[ROOT] = MAX_TREE;
frq[TREE] = MAX_FREQ-1;
//----------------------
}
//---------------------------------------------------------------------------

void __stdcall TSoft_Huff::Reconstruct(void)
{
register unsigned long i, e, k, f, l;
//----------------------
for (i = 0, e = 0; i < TREE; i++) {          /* collect leaf nodes in the first half of the table and replace the frq by (frq + 1) / 2 */
//----------------------
 if (son[i]>= TREE)
	{son[e] = son[i];
	 frq[e] =(frq[i]+1)>>1;
	 e++;
	}
}
//----------------------
for (i = 0, e = CNUM; e < TREE; i+=2, e++) {  /* begin constructing tree by connecting sons */
//----------------------
     f = frq[i] + frq[i+1];
         frq[e] = f;
    for (k = e; f < frq[k-1];) {
         k-= 1;
        }
         l=(e-k)<<1;
     if (l==0)
     continue;
     ptrMov(&frq[k + 1],&frq[k],l);
     frq[k] = f;
     ptrMov(&son[k + 1],&son[k],l);
     son[k] = i;
}
//----------------------                      /* conect leaf sons /\ to upper */
for (i = 0; i < TREE; i++) {
//----------------------
         k = son[i];
     if (k>= TREE) dad[k] = i;
     else
	       dad[k] = i;
         dad[k+1] = i;
    }
//----------------------
}
//---------------------------------------------------------------------------

void __stdcall TSoft_Huff::Update(unsigned char axdata_uncoded)
{
//------------------------------   /* 2^28=250MB so never overflows*/
if (frq[ROOT]==MAX_FREQ) Reconstruct();
//------------------------------
register unsigned long son_exg, frq_exg, dad_exg, exg;
register unsigned long son_cur, frq_cur, dad_cur, cur = axdata_uncoded + TREE;
//------------------------------
for (;;) {
//------------------------------
      cur =dad[cur];
  if (cur==MAX_TREE)               /* if current node ROOT return */
  return;
      frq[cur]++;                  /* increment freq count */
//----------------------
HUFF_CHECK_ORDER:
//---------------------- 		   /* if the order is disturbed, exchange nodes */
      frq_cur = frq[cur];
      exg = cur;
for (;frq_cur > frq[exg+1];) {
      exg++;
    }
 if (exg==cur)
  continue;
//----------------------           /* exchange nodes at same level /\ */
HUFF_EXCHANGE_NODES:
//----------------------
// new >>> old
//----------------------
 son_cur  = son[cur];
 frq_cur  = frq[cur];
 frq_exg  = frq[exg];
 son_exg  = son[exg];

 dad[son_cur] = exg;
 if (son_cur < TREE) dad[son_cur+1] = exg;
 son[cur] = son_exg;
 frq[cur] = frq_exg;

 dad[son_exg] = cur;
 if (son_exg < TREE) dad[son_exg+1] = cur;
 son[exg] = son_cur;
 frq[exg] = frq_cur;
//----------------------
 cur = exg;
//------------------------------------------
}
//------------------------------------------
}
//---------------------------------------------------------------------------

unsigned char __stdcall TSoft_Huff::Encode(unsigned char *alpcode, unsigned char alpcode_bit, unsigned char axdata_uncoded)
{
register unsigned long node = dad[axdata_uncoded + TREE];
register unsigned long code = 0;
register unsigned char bits = 0;
//----------------------            /* travel from leaf to ROOT */
do {
//----------------------            /* if node's address is odd-numbered, choose "1" add to code */
	code = (code<<1) | node & 0x00000001;
	bits++;
//----------------------
} while ((node =dad[node])!=ROOT);
//----------------------            /* send bits to output and update model */
Update(axdata_uncoded);
unsigned long result = code;
bitMov(alpcode,alpcode_bit,&result,0,bits);
return bits;
}
//---------------------------------------------------------------------------

unsigned char __stdcall TSoft_Huff::Decode(unsigned char *alpdata_uncoded, unsigned char *alpcode, unsigned char alpcode_bit)
{
register unsigned long node = son[ROOT];
register unsigned long code;
register unsigned char bits = 0;
//------------------------------------------
unsigned long indata;
bitMov(&indata,0,alpcode,alpcode_bit,24);
code =  indata;
//----------------------            /* travel from leaf to ROOT */
do {
//----------------------            /* select node depend on next bit */
	node |= code & 0x00000001;
	code>>= 1;
	bits++;
//----------------------
} while ((node =son[node]) <TREE);
//----------------------            /* send bits to output and update model */
alpdata_uncoded[0] = node-=TREE;
Update(node);
return bits;
}
//-------------------------------THE END-------------------------------------


