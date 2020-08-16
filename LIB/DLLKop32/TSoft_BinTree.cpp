//---------------------------------------------------------------------------
#include <windows.h>
#include "..\DLLIO\TSoft_IO.h"
#include "TSoft_HDR.h"
#include "TSoft_BinTree.h"
//---------------------------------------------------------------------------
// tym wiêcej bitów im wiêksze slide window, 12 dla 4096
//#define HASH_SIZE (unsigned long)(256<<8)
//#define HASH(ptr) (WORD)(((WORD)ptr[0])^(((WORD)ptr[1])<<4)^(((WORD)ptr[2])<<6)^(((WORD)ptr[3])<<8)) //1.80MB
//#define HASH_SIZE (unsigned long)(256<<6)
//#define HASH(ptr) (WORD)(((WORD)ptr[0])^(((WORD)ptr[1])<<2)^(((WORD)ptr[2])<<4)^(((WORD)ptr[3])<<6)) //2.80MB
#define HASH_SIZE (unsigned long)(256<<5)
#define HASH(ptr) (WORD)(((WORD)ptr[0])^(((WORD)ptr[1])<<3)^(((WORD)ptr[2])<<4)^(((WORD)ptr[3])<<5)) //3.25MB
//#define HASH_SIZE (unsigned long)(256<<4)
//#define HASH(ptr) (WORD)(((WORD)ptr[0])^(((WORD)ptr[1])<<2)^(((WORD)ptr[2])<<3)^(((WORD)ptr[3])<<4)) //3.15MB
//#define HASH_SIZE (unsigned long)(256<<3)
//#define HASH(ptr) (WORD)(((WORD)ptr[0])^(((WORD)ptr[1])<<1)^(((WORD)ptr[2])<<2)^(((WORD)ptr[3])<<3)) //3.10MB
//#define HASH_SIZE (unsigned long)(256<<2)
//#define HASH(ptr) (WORD)(((WORD)ptr[0])^(((WORD)ptr[1])<<1)^(((WORD)ptr[2])<<2)) //3.00MB
//#define HASH_SIZE (unsigned long)(256<<1)
//#define HASH(ptr) (WORD)(((WORD)ptr[0])^(((WORD)ptr[1])<<1)) //2.80MB
//#define HASH_SIZE (unsigned long)256
//#define HASH(ptr) (WORD)(((WORD)ptr[0])) // 1BYTE SLOW 0.80MB

// proste i 100% trafiania, ale powolne
//#define HASH_SIZE (unsigned long)(256<<8)
//#define HASH(ptr) (WORD)(((WORD)ptr[0])|(((WORD)ptr[1])<<8)) //2.00MB
//#define HASH_SIZE (unsigned long)256
//#define HASH(ptr) (WORD)(((WORD)ptr[0])) // 1BYTE SLOW 0.80MB
//wersje ksi¹¿kowe powolne
//#define HASH_SIZE (unsigned long)(256<<8)
//#define HASH(ptr) (WORD)(((((ptr[0]<<5)+ptr[1])<<5)+ptr[2])) //1.50MB
//#define HASH_SIZE (unsigned long)(256<<4)
//#define HASH(ptr) (WORD)((40543*((((ptr[0]<<4)^ptr[1])<<4)^ptr[2])>>4) & 0xFFF) //2.80MB
//---------------------------------------------------------------------------
// This structure contains binary tree constructed around ring_ptr witch is pointer to
// memory array, text buffer like fifo with dinamicaly updated begin and old characters eaten by new
// dad, son are array of indexes, nodes those makes tree.
// son[TREE]+"character treated as number" points to the index of this character in ring_ptr
// son[previous index] contains index of next (same) character. When last char is found son[]=DICT_NULL
// dad[current index] = index of previous index that is "owner" of it, that points to it
//
__stdcall TSoft_BinTree::TSoft_BinTree(unsigned long adict,unsigned long asize) {
//------------------------------------------
if (asize < FIND_MAX) find_max_length = asize;
else
	find_max_length = FIND_MAX;
//----------------------
if (asize < FIND_MAX || adict < find_max_length) find_max_offset = find_max_length;
else
if (adict > DICT_MAX) find_max_offset = DICT_MAX;
else
	find_max_offset = adict;
//------------------------------------------
     dad = (unsigned long*)LocalAlloc(LMEM_FIXED,sizeof(unsigned long)*(find_max_offset));
     son = (unsigned long*)LocalAlloc(LMEM_FIXED,sizeof(unsigned long)*(find_max_offset+HASH_SIZE));
ring_ptr = (unsigned char*)LocalAlloc(LMEM_FIXED,find_max_offset+find_max_length+sizeof(__int32));
//------------------------------------------
}
//---------------------------------------------------------------------------

__stdcall TSoft_BinTree::~TSoft_BinTree(void)
{
LocalFree(dad); LocalFree(son);
LocalFree(ring_ptr);
}
//---------------------------------------------------------------------------
// dad=son[TREE+for 0 to 256]=DICT_NULL
//

void __stdcall TSoft_BinTree::Initialize(unsigned char *aptr)
{
//------------------------------------------
find_length = 0;
find_offset = 0;
brun_length = 1;
brun_counte = 1;
brun_elsize = 0;
//------------------------------------------
ring_insert = find_max_offset-find_max_length;
ring_delete = 0;
ptrMov((char*)&ring_ptr[find_max_offset-find_max_length],aptr,find_max_length);
//------------------------------------------
register int  i;
for (i = find_max_offset+HASH_SIZE;;)
	{son[--i]=DICT_NULL;
	 if (i==0)
		 break;
	}
for (i = find_max_offset;;)
	{dad[--i]=DICT_NULL;
	 if (i==0)
	     break;
	}
//------------------------------------------
}
//---------------------------------------------------------------------------
// if current 'x' characters of string is "abcdef" and asize=3 so adict=6 and ring buffer probably will be "aaabcdaaa"
// son[TREE+'a']=0 -> son[0]=1 -> son[1]=2 -> son[2]=DICT_NULL ...son[TREE+'d']=5
// when next character would been inserted ring_ptr="gaabcdgaa"
// after this operation son[TREE+'g']=0 and son[TREE+'a']=1 and dad[1] will change form 0 to TREE+'a'
// of course 'a' must be deleted first (TSoft_BinTree::Delete) beacouse it is no longer exists in buffer history
//

void __stdcall TSoft_BinTree::Insert(void)
{
register unsigned long  ref = ring_insert;
register unsigned char *ref_ptr =((unsigned char*)ring_ptr + ref);
register unsigned long  hsh_ref = HASH(ref_ptr);
register unsigned long  stn = find_max_offset+hsh_ref;
register unsigned long  cpx = son[stn];

son[stn]=ref;
dad[ref]=stn;
if (cpx==DICT_NULL)
   {return;
   }
dad[cpx]=ref;
son[ref]=cpx;
}
//---------------------------------------------------------------------------
// skip procedure will delete
//

void __stdcall TSoft_BinTree::Skip(void)
{
register unsigned long  ref = ring_insert;
register unsigned char *ref_ptr =((unsigned char*)ring_ptr + ref);
register unsigned long  hsh_ref = HASH(ref_ptr);
register unsigned long  stn = find_max_offset+hsh_ref;
register unsigned long  cpx = son[stn];

dad[ref]=DICT_NULL;
if (cpx==DICT_NULL)
   {return;
   }
son[ref]=DICT_NULL;
dad[cpx]=stn;
}
//---------------------------------------------------------------------------

void __stdcall TSoft_BinTree::Delete(void)
{
register unsigned long ref = ring_delete;
register unsigned long dad_ref = dad[ref];

if (dad_ref==DICT_NULL) // element nie zarejestrowany
   {return;
   }
dad[ref]=DICT_NULL;
register unsigned long son_ref = son[ref];
son[dad_ref] = son_ref;
if (son_ref==DICT_NULL) // nie ma co siê zaglebiac
   {return;
   }
son[ref]=DICT_NULL;
dad[son_ref] = dad_ref;
}
//---------------------------------------------------------------------------
// will recrusevly search for longest match of string at ref_ptr[ring_insert]...find_max_length with ref_ptr[...]
//

void __stdcall TSoft_BinTree::Search_dict(void)
{
register unsigned long  ref = ring_insert;
register unsigned char *ref_ptr =((unsigned char*)ring_ptr + ref);
register unsigned long  hsh_ref = HASH(ref_ptr);
register unsigned long  stn = find_max_offset + hsh_ref;
register unsigned long  cpx = stn;
find_length = 0;
register unsigned char *cpx_ptr;
register unsigned long  cpx_len, cpx_ofs;
//------------------------------------------
while (1) {
//------------------------------------------
 if (son[cpx]==DICT_NULL)
     return;
 cpx = son[cpx];
//----------------------
TREE_SEARCH_CALC_LENGTH:
//----------------------
	 ref_ptr = &ring_ptr[ref];
	 cpx_ptr = &ring_ptr[cpx];
 if (((__int16*)cpx_ptr)[0]!=((__int16*)ref_ptr)[0]) // warunek konieczny
     continue;
 	 cpx_len =2;
  	 ref_ptr+=2;
   	 cpx_ptr+=2;
  while (cpx_len < find_max_length) {
	 if (cpx_ptr[0]!=ref_ptr[0])
	 break;
	 cpx_ptr+=1;
	 ref_ptr+=1;
	 cpx_len+=1;
	}
 if (cpx_len <= find_length)
     continue;
//----------------------
TREE_SEARCH_CALC_OFFSET_AND_STORE: //sssxxxx, s = cpx_len,s+x = cpx_ofs
//----------------------
 if (ref >= cpx) {
     cpx_ofs = ref-cpx;
    }
 else {
     cpx_ofs = ref-cpx + find_max_offset;
    }
 if (cpx_ofs < 4)
     continue;
//----------------------
TREE_SRORE:
//----------------------
 find_offset = cpx_ofs;
 find_length = cpx_len;
//----------------------
TREE_EXIT_IF_MAX:
//----------------------
 if (cpx_len==find_max_length) return;
//----------------------
}
//------------------------------------------
}
//---------------------------------------------------------------------------
// will search for characters(groups 1,2,3,4) repetitions, faster than dictionary matches more efectively for compression
//

void __stdcall TSoft_BinTree::Search_brun(void)
{
register unsigned char *cpx_ptr_end;
register unsigned char *cpx_bgn = ((unsigned char*)ring_ptr + ring_insert);
register unsigned long  cpx_els = 0;
register unsigned char *cpx_ptr;
//------------------------------------------
if (*((__int32*)cpx_bgn)==*((__int32*)(cpx_bgn+4))) {
	 if (cpx_els!=2*4)
		 cpx_ptr=cpx_bgn+2*4;
	 cpx_els =4;
}
if (*((__int16*)cpx_bgn)==*((__int16*)(cpx_bgn+3)) && *((__int8*)(cpx_bgn+2))==*((__int8*)(cpx_bgn+5))) {
	 if (cpx_els!=2*3)
		 cpx_ptr=cpx_bgn+2*3;
	 cpx_els =3;
}
if (*((__int16*)cpx_bgn)==*((__int16*)(cpx_bgn+2))) {
	 if (cpx_els!=2*2)
		 cpx_ptr=cpx_bgn+2*2;
	 cpx_els =2;
}
if (cpx_bgn[0]==cpx_bgn[1]) {
	 if (cpx_els!=2*1)
		 cpx_ptr=cpx_bgn+2*1;
	 cpx_els =1;
}
//--------------------
if (cpx_els==0) { // NIC BO NIE WARTO
//--------------------
brun_length =1; brun_counte =1;
brun_elsize =0;
return;
}
//--------------------
if (cpx_els==1) { // 1 bajtowe porownania
//--------------------
	   cpx_ptr_end = cpx_bgn + find_max_length-1;
while (cpx_ptr <= cpx_ptr_end) {
   if (cpx_bgn[0]!=cpx_ptr[0])
	   break;
    cpx_ptr+=1;
   }
}
else
//--------------------
if (cpx_els==2) { // 2 bajtowe porownania
//--------------------
	   cpx_ptr_end = cpx_bgn + find_max_length-2;
while (cpx_ptr <= cpx_ptr_end) {
   if (((__int16*)cpx_bgn)[0]!=((__int16*)cpx_ptr)[0])
		 break;
    cpx_ptr+=2;
   }
}
else
//--------------------
if (cpx_els==3) { // 3 bajtowe porownania
//--------------------
	   cpx_ptr_end = cpx_bgn + find_max_length-3;
while (cpx_ptr <= cpx_ptr_end) {
   if (((__int16*)cpx_bgn)[0]!=((__int16*)cpx_ptr)[0] || *((__int8*)(cpx_bgn+2))!=*((__int8*)(cpx_ptr+2)))
		 break;
    cpx_ptr+=3;
   }
}
else
//--------------------
if (cpx_els==4) { // 4 bajtowe porownania
//--------------------
	   cpx_ptr_end = cpx_bgn + find_max_length-4;
while (cpx_ptr <= cpx_ptr_end) {
   if (((__int32*)cpx_bgn)[0]!=((__int32*)cpx_ptr)[0])
		 break;
    cpx_ptr+=4;
   }
}
brun_length =cpx_ptr - cpx_bgn;
brun_elsize =cpx_els;
brun_counte =brun_length / brun_elsize;
//------------------------------------------
}
//---------------------------------------------------------------------------
// updates tree by deleteing old and inserting new characters in ring buffer, also prepares buffer(last characters) for matches
//

void __stdcall TSoft_BinTree::Update(unsigned char *aupdate_ptr, unsigned long aupdate_count)
{
register unsigned long  ucnt = aupdate_count;
register unsigned char *rptr;
register unsigned char *uptr = aupdate_ptr + find_max_length;
//------------------------------------------
register unsigned long  maxl = find_max_length;
register unsigned long  maxp = find_max_offset-1;
//------------------------------------------
while (ucnt!=0) {
		 ucnt--;
//------------------------------------------
	  Delete();
	  rptr = &ring_ptr[ring_delete];
	  rptr[0] = uptr[0];
  if (ring_delete<=maxl)
	 {rptr+= maxp;
	  rptr[1] = uptr[0];
	 }
	  uptr++;
  if (ring_delete>=maxp) ring_delete =0;
 else ring_delete++;
//------------------------------------------
	  Insert();
//-------------------
  if (ring_insert>=maxp) ring_insert =0;
 else ring_insert++;
//------------------------------------------
}
//------------------------------------------
}
//---------------------------------------------------------------------------

char __stdcall TSoft_BinTree::Optimum_brun_match(unsigned long ahead_length,unsigned long pass_length)
{
register unsigned long price = 0;
price+= hdrcoder.Price_ptrPass(pass_length);
price+= pass_length;
price+= hdrcoder.Price_ptrBrun(brun_elsize,brun_counte);
price+= brun_elsize;
//--------------------
register unsigned long repl = 0;
repl += hdrcoder.Price_ptrPass(brun_length + pass_length);
repl += pass_length + brun_length;
//--------------------
if (repl > price) return 1;
else return 0;
}
//---------------------------------------------------------------------------

char __stdcall TSoft_BinTree::Optimum_dict_match(unsigned long ahead_length,unsigned long pass_length)
{
register unsigned long price = 0;
price+= hdrcoder.Price_ptrPass(pass_length);
price+= pass_length;
price+= hdrcoder.Price_ptrDict(find_offset,find_length);
//--------------------
register unsigned long repl = 0;
if (find_length + pass_length > FIND_MAX)
   {repl += hdrcoder.Price_ptrPass(FIND_MAX);
    repl += hdrcoder.Price_ptrPass(find_length + pass_length - FIND_MAX);
   }
else
   {repl += hdrcoder.Price_ptrPass(find_length + pass_length);
   }
repl += pass_length + find_length;
//--------------------
if (repl > price) return 1;
else return 0;
}
//-------------------------------THE END-------------------------------------
