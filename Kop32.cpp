//---------------------------------------------------------------------------
//-------- COPYRIGHT: Stanislaw Stasiak SSTSOFT.pl @2001-2002 ---------------
//-------- https://github.com/stasinek/Koperek.VCL --------------------------
//---------------------------------------------------------------------------
#include <vcl.h>
#define WIN32_LEAN_AND_MEAN
#pragma hdrstop
//---------------------------------------------------------------------------
 USERES("Kop32.res");
USEUNIT("Kop32_common.cpp");
 USERES("Kop32_common.res");
USEFORM("Haslo_frm.cpp", Haslo_form);
USEFORM("Koper_frm.cpp", Koper_form);
USEFORM("Break_frm.cpp", Break_form);
USEFORM("Infos_frm.cpp", Infos_form);
USEFORM("Journal_frm.cpp", Journal_form);
USEFORM("Lista_frm.cpp", Lista_form);
USEFORM("Quest_frm.cpp", Quest_form);
USEFORM("..\..\FORM_TEMPLATES\About_frm.cpp", About_form);
 USELIB("LIB\DLLIO\DLLIO.lib");
 USELIB("LIB\DLLDatabase\DLLDatabase.lib");
 USELIB("LIB\DLLKop32\DLLKop32.lib");
//---------------------------------------------------------------------------
#include "Kop32_common.h"
TSoft::Kop32 *Kop = NULL;
WINAPI WinMain(HINSTANCE hApp, HINSTANCE hInstance, char *argts, int State)
{
    SetCurrentDir("..");
    Kop = new TSoft::Kop32;
	DWORD ret = WinMain_common(hApp, hInstance , argts, State);
    if (Kop!=NULL) delete Kop;
    return ret;
}
//---------------------------------------------------------------------------
