//---------------------------------------------------------------------------
//-------- COPYRIGHT: Stanislaw Stasiak SSTSOFT.pl @2001-2004 ---------------
//-------- https://github.com/stasinek/Koperek.VCL --------------------------
//---------------------------------------------------------------------------
#include <windows.h>
#pragma hdrstop
//---------------------------------------------------------------------------
#include "..\DLLIO\TSoft_IO.h"
#include "TSoft_Pharser.h"
//---------------------------------------------------------------------------
#define PHARSEPARATOR '/'
//---------------------------------------------------------------------------

bool __stdcall Pharser(char *lpsrc, char *lpparameter, char *lpdst, __int32 *lpint)
{
char   tmpch[32];
__int32 init, bgn, end, exit, srclen = strLen(lpsrc), paralen = strLen(lpparameter);
tmpch[0] = PHARSEPARATOR;
ptrMov(&(tmpch[1]),lpparameter,paralen+1);

//----------------
    init = strPos(lpsrc,0,tmpch);
if (init==-1) {
    if (lpdst!=NULL) lpdst[0]='\0';
    if (lpint!=NULL){
        lpint[0]=-1;
        lpint[1]=-1;
        lpint[2]=-1;
        lpint[3]=-1;
        }
    return 0;
   }
//----------------
    bgn = init+1+paralen;
if (bgn+2 > srclen ? true : lpsrc[bgn]!='=' || lpsrc[bgn+1]!='{') {
    if (lpdst!=NULL) lpdst[0] = '\0';
    if (lpint!=NULL){
        lpint[0]=init;
        lpint[1]=-1;
        lpint[2]=-1;
        lpint[3]=bgn;
        }
    return 1;
   }
else
    bgn+= 2;
//----------------
    end = strPos(lpsrc,bgn,"}");
if (end==-1) {
    if (lpdst!=NULL) lpdst[0] = '\0';
    if (lpint!=NULL){
        lpint[0]=-1;
        lpint[1]=-1;
        lpint[2]=-1;
        lpint[3]=-1;
        }
    return 0;
   }
//----------------
    exit = end + 1;
    if (lpdst!=NULL){ ptrMov(lpdst,&(lpsrc[bgn]),end-bgn); lpdst[end-bgn] = '\0'; }
    if (lpint!=NULL){
        lpint[0]=init;
        lpint[1]=bgn;
        lpint[2]=end;
        lpint[3]=exit;
       }
    return 1;
}
//---------------------------------------------------------------------------


