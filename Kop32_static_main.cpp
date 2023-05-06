//---------------------------------------------------------------------------
#include <vcl.h>
#include <windows.h>
#pragma hdrstop
#define WIN32_LEAN_AND_MEAN
//---------------------------------------------------------------------------
#include "Kop32_common_main.h"
//---------------------------------------------------------------------------
USEUNIT("Kop32_common_main.cpp");
USEFORM("Haslo_frm.cpp", Haslo_form);
USEFORM("Koper_frm.cpp", Koper_form);
USEFORM("Break_frm.cpp", Break_form);
USEFORM("Infos_frm.cpp", Infos_form);
USEFORM("Journal_frm.cpp", Journal_form);
USEFORM("Lista_frm.cpp", Lista_form);
USEFORM("Quest_frm.cpp", Quest_form);
USEFORM("..\..\FORM_TEMPLATES\About_frm.cpp", About_form);
USEUNIT("LIB\DLLIO\TSoft_IO.cpp");
USEUNIT("LIB\DLLDatabase\TSoft_Database.cpp");
USEUNIT("LIB\DLLKop32\TSoft_Ari.Cpp");
USEUNIT("LIB\DLLKop32\TSoft_BinTree.cpp");
USEUNIT("LIB\DLLKop32\TSoft_BWTMatrix.cpp");
USEUNIT("LIB\DLLKop32\TSoft_HDR.cpp");
USEUNIT("LIB\DLLKop32\TSoft_Huff.Cpp");
USEUNIT("LIB\DLLKop32\TSoft_Koder.cpp");
USEUNIT("LIB\DLLKop32\TSoft_Kop32.cpp");
USEUNIT("LIB\DLLKop32\TSoft_Mtf.cpp");
USEUNIT("LIB\DLLKop32\TSoft_Pharser.cpp");
USEUNIT("LIB\DLLKop32\TSoft_Stack.cpp");
USERES("Kop32_static_main.res");
USEUNIT("LIB\DLLKop32\TSoft_Kop32_Seeker.cpp");
//---------------------------------------------------------------------------
TSoft::Kop32 *Kop;
WINAPI WinMain(HINSTANCE hApp, HINSTANCE hInst, char *argts, int State)
{
    Kop = new TSoft::Kop32;
    return WinMain_common(hApp,hInst,argts,State);
}
//---------------------------------------------------------------------------
