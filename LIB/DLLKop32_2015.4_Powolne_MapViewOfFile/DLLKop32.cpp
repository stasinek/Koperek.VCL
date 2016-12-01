//---------------------------------------------------------------------------
#include <windows.h>
#pragma hdrstop
#include <condefs.h>
#include "DLLTSoft_Kop32.h"
//---------------------------------------------------------------------------
//   Important note about DLL memory management when your DLL uses the
//   static version of the RunTime Library:
//
//   If your DLL exports any functions that pass String objects (or structs/
//   classes containing nested Strings) as parameter or function results,
//   you will need to add the library MEMMGR.LIB to both the DLL project and
//   any other projects that use the DLL.  You will also need to use MEMMGR.LIB
//   if any other projects which use the DLL will be perfomring new or delete
//   operations on any non-TObject-derived classes which are exported from the
//   DLL. Adding MEMMGR.LIB to your project will change the DLL and its calling
//   EXE's to use the BORLNDMM.DLL as their memory manager.  In these cases,
//   the file BORLNDMM.DLL should be deployed along with your DLL.
//
//   To avoid using BORLNDMM.DLL, pass string information using "char *" or
//   ShortString parameters.
//
//   If your DLL uses the dynamic version of the RTL, you do not need to
//   explicitly add MEMMGR.LIB as this will be done implicitly for you
//---------------------------------------------------------------------------
/*#pragma link "DLLTSoft_Kop32"
#pragma link "DLLTSoft_Koder"
#pragma link "DLLTSoft_BinTree"
#pragma link "DLLTSoft_Database"
#pragma link "DLLTSoft_DlaChara"
*///---------------------------------------------------------------------------

USEUNIT("DLLTSoft_Kop32.cpp");
USEUNIT("DLLTSoft_Koder.cpp");
USEUNIT("DLLTSoft_BinTree.cpp");
USEUNIT("DLLTSoft_Database.cpp");
USEUNIT("DLLTSoft_DlaChara.cpp");
 USERES("DLLKop32.res");
//---------------------------------------------------------------------------
__declspec(dllexport) TSoft_Kop32 *kop;
//---------------------------------------------------------------------------

int WINAPI DllEntryPoint(HINSTANCE, unsigned long reason, void*)
{
if (reason==DLL_PROCESS_ATTACH)
    kop = new TSoft_Kop32;
return 1;
}
//---------------------------------------------------------------------------

