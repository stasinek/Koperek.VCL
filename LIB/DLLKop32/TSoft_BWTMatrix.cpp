//---------------------------------------------------------------------------
#include <windows.h>
#include "..\DLLIO\TSoft_IO.h"
#include "TSoft_BWTMatrix.h"
#pragma hdrstop
//---------------------------------------------------------------------------

__stdcall TSoft_BWTMatrix::TSoft_BWTMatrix(unsigned long ablock)
{
matrix_dim = ablock;
matrix_idx_ptr = (unsigned long*)LocalAlloc(LPTR,matrix_dim*sizeof(unsigned long));
matrix_ptr 	   = (unsigned char*)LocalAlloc(LPTR,matrix_dim*2);

groups_bgn[0]  = (unsigned long*)LocalAlloc(LPTR,matrix_dim*sizeof(unsigned long)/2);
groups_bgn[1]  = (unsigned long*)LocalAlloc(LPTR,matrix_dim*sizeof(unsigned long)/2);
groups_end[0]  = (unsigned long*)LocalAlloc(LPTR,matrix_dim*sizeof(unsigned long)/2);
groups_end[1]  = (unsigned long*)LocalAlloc(LPTR,matrix_dim*sizeof(unsigned long)/2);
}
//---------------------------------------------------------------------------

void __stdcall TSoft_BWTMatrix::Generate(unsigned char *alpSrc)
{
unsigned long  row, row_max = matrix_dim;
unsigned long  idx;
unsigned long  idx_end;
	// reverse copying BARBAKAN->>NAKABRAB for unsigned long suffix sorting
ptrRev(matrix_ptr,alpSrc,row_max);
	// NAKABRAB->NAKABRABNAKABRAB
ptrEql(matrix_ptr+row_max,matrix_ptr,row_max);
	// matrix_row_ptr addresing
//------------------------------------------
	 idx = (DWORD)matrix_idx_ptr;
	 idx_end = idx + row_max*4 - 4;
	 row = row_max;
while (idx <=idx_end)
	{((DWORD*)idx)[0]=row--;
	 idx+=4;
	}
//------------------------------------------
}
//---------------------------------------------------------------------------

void __stdcall TSoft_BWTMatrix::Flush(unsigned char *alpDst)
{
unsigned char *ptr = matrix_ptr;
unsigned long  row_max = matrix_dim;
unsigned long  idx;
unsigned long  idx_end;
// decode and move to dst
//------------------------------------------
	 idx = (DWORD)matrix_idx_ptr;
	 idx_end = idx + row_max*4 - 4;
while (idx <= idx_end)
	{((unsigned char*)alpDst++)[0] = ptr[((DWORD*)idx)[0]];
	 idx+=4;
	}
//------------------------------------------
}
//---------------------------------------------------------------------------

unsigned long __stdcall TSoft_BWTMatrix::Sort(void)
{
unsigned long *gl_end_cur = groups_end[0], *gl_end_new = groups_end[1];
gl_end_cur[0] = matrix_dim-1;
unsigned long *gl_bgn_cur = groups_bgn[0], *gl_bgn_new = groups_bgn[1];
gl_bgn_cur[0] = 0;
unsigned long  col, row;
//------------------------------------------
for (col = matrix_dim/4 - 1;;) {
//------------------------------------------
BWT_MATRIX_SORT_GROUPS:
//------------------------------------------
for (row = 0; gl_end_cur[row]!=0; row++)
	 {Sort_groups(col,gl_bgn_cur[row],gl_end_cur[row]);
	 }
 if (--col==0) break;
//------------------------------------------
BWT_MATRIX_FIND_GROUPS:
//------------------------------------------
for (row = 0; gl_end_cur[row]!=0; row++)
	 {Find_groups(col,gl_bgn_cur[row],gl_end_cur[row],gl_bgn_new,gl_end_new);
	 }
 if (gl_end_new[0]==0) break;
//------------------------------------------
BWT_MATRIX_FLIP_GROUPS:
//------------------------------------------
row = (DWORD)gl_bgn_cur;
				 gl_bgn_cur = gl_bgn_new;
				 gl_bgn_new =(DWORD*)row;
row = (DWORD)gl_end_cur;
				 gl_end_cur = gl_end_new;
				 gl_end_new =(DWORD*)row;
//------------------------------------------
}
//------------------------------------------
BWT_MATRIX_FIND_FIRST_ROW:
//------------------------------------------
unsigned long *idx_ptr = matrix_idx_ptr, idx_bgn = matrix_dim;
//------------------------------------------
for (row=0;idx_ptr[row]!=idx_bgn;)
	 {row++;
	 }
//------------------------------------------
return row;
}
//---------------------------------------------------------------------------

void __stdcall TSoft_BWTMatrix::Sort_groups(unsigned long acolumn,unsigned long arow_bgn,unsigned long arow_end)
{
unsigned long  row, row_cmp, row_fnd, row_bgn = arow_bgn, row_end = arow_end;
unsigned char     *ptr = matrix_ptr + acolumn;
unsigned long *idx_ptr = matrix_idx_ptr;
unsigned long  cmp;
//------------------------------------------
for (row = row_bgn; row <= row_end; row++) {
//------------------------------------------
for (row_cmp = row, cmp =*((DWORD*)(ptr+idx_ptr[row])), row_fnd = row; ++row_fnd <= row_end;) // find first lower
 if (cmp >*((DWORD*)(ptr+idx_ptr[row_fnd])))
	 {cmp =*((DWORD*)(ptr+idx_ptr[row_fnd]));
	  row_cmp =row_fnd;
	 }
 if (row_cmp!=row)
	 {cmp = idx_ptr[row];
			  idx_ptr[row] = idx_ptr[row_cmp];
								  idx_ptr[row_cmp] = cmp;
	 }
//------------------------------------------
}
//------------------------------------------
}
//---------------------------------------------------------------------------
void __stdcall TSoft_BWTMatrix::Find_groups(unsigned long acolumn,unsigned long arow_bgn,unsigned long arow_end,unsigned long *alist_bgn,unsigned long *alist_end)
{
unsigned long  list_count = 0;
unsigned long  row, row_cmp, row_fnd, row_bgn = arow_bgn, row_end = arow_end;
unsigned char     *ptr = matrix_ptr + acolumn;
unsigned long *idx_ptr = matrix_idx_ptr;
unsigned long  cmp;
//------------------------------------------
for (row = row_bgn; row <= row_end;) {
//------------------------------------------
for (row_cmp = row, cmp =*((DWORD*)(ptr+idx_ptr[row])); ++row <= row_end;)
 if (cmp!=*((DWORD*)(ptr+idx_ptr[row])))
	 {break;
	 }
 if (row-1 > row_cmp)
	 {
	  alist_bgn[list_count] = row_cmp;
	  alist_end[list_count] = row-1;
	  list_count++;
	 }
//------------------------------------------
}
//------------------------------------------
alist_end[list_count] = 0;
}
//---------------------------------------------------------------------------

__stdcall TSoft_BWTMatrix::~TSoft_BWTMatrix(void)
{
LocalFree(groups_bgn[0]);
LocalFree(groups_bgn[1]);
LocalFree(groups_end[0]);
LocalFree(groups_end[1]);
LocalFree(matrix_ptr);
LocalFree(matrix_idx_ptr);
}
//---------------------------------------------------------------------------
/*#include <stdlib.h>
void bwt_encode(char *buf_in, char *buf_out, int size, int *primary_index)
{
	 int *indices = new int[size];
	 int i;

	 for(i=0; i<size; i++)
		  indices[i] = i;
	 char *rotlexcmp_buf = buf_in;
	 int rottexcmp_bufsize = size;
	 qsort(indices, size,sizeof(int), rotlexcmp);

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
//---------------------------------------------------------------------------

void bwt_decode(char *buf_in, char *buf_out, int size, int primary_index)
{
	 char *F = new char[size];
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
//-------------------------------THE END-------------------------------------


