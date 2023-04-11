//---------------------------------------------------------------------------
//-----------------Stanislaw Stasiak "SSTSOFT.pl" 2001-2002------------------
//---------------------------------------------------------------------------
#ifndef __TSoft_BinTree_H
#define __TSoft_BinTree_H
//---------------------------------------------------------------------------
#include "TSoft_build_conf.h"
#include "TSoft_HDR.h"
//---------------------------------------------------------------------------
#define FIND_MIN  (DWORD)0x00000002
#define FIND_MAX  (DWORD)0x000000FF
#define DICT_MIN  (DWORD)FIND_MAX+1
#define DICT_MAX  (DWORD)0x00010000
//---------------------------------------------------------------------------
#define DICT_NULL	0xFFFF0000
//---------------------------------------------------------------------------
class __declspec(dllexport) TSoft_BinTree
{
private:
//---------------------------------------------------------------------------
unsigned long  *son,*dad;
//---------------------------------------------------------------------------
public:
unsigned long   ring_delete,ring_insert;
unsigned char  *ring_ptr;
unsigned long   find_length,find_max_length,find_offset,find_max_offset;
unsigned char  *find_ptr;
//---------------------------------------------------------------------------
unsigned long   brun_length, brun_counte, brun_elsize;
//---------------------------------------------------------------------------
	 __stdcall  TSoft_BinTree(unsigned long adict,unsigned long asize);
	 __stdcall ~TSoft_BinTree();
//---------------------------------------------------------------------------
void __stdcall  Initialize(unsigned char *aptr);
//---------------------------------------------------------------------------
void __stdcall  Update(unsigned char *aupdate_ptr,unsigned long aupdate_count);
void __stdcall  Insert(void);
void __stdcall  Skip(void);
void __stdcall  Delete(void);
//---------------------------------------------------------------------------
void __stdcall  Search_brun(void);
void __stdcall  Search_dict(void);
//---------------------------------------------------------------------------
char __stdcall  Optimum_dict_match(unsigned long ahead_length,unsigned long pass_length);
char __stdcall  Optimum_brun_match(unsigned long ahead_length,unsigned long pass_length);
//---------------------------------------------------------------------------
__ptrptr_hdrcoder hdrcoder;
//---------------------------------------------------------------------------
};
//-------------------------------THE END-------------------------------------
#endif
/* cpx1_bgn =&ring_ptr[p]; cpx2_ptr =find_ptr;
 if (((unsigned __int32*)cpx1_bgn)[0]!=((unsigned __int32*)cpx2_ptr)[0]) // warunek konieczny
 continue;
		cpx1_ptr =cpx1_bgn+4; 
		cpx2_ptr+=4;
	  cpx1_ptr_end = cpx1_bgn + find_max_length-1;
 while (cpx1_ptr <= cpx1_ptr_end) {
	 if (cpx1_ptr[0]!=cpx2_ptr[0])
		break;
		cpx1_ptr+=1;
		cpx2_ptr+=1;
	}
 cpx_len = cpx1_ptr-cpx1_bgn;
*/
