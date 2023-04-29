//---------------------------------------------------------------------------
#include <vcl.h>
#define WIN32_LEAN_AND_MEAN
#pragma hdrstop
//---------------------------------------------------------------------------
USEUNIT("Koperek32_common_main.cpp");
USEFORM("Haslo_frm.cpp", Haslo_form);
USEFORM("Koper_frm.cpp", Koper_form);
USEFORM("Break_frm.cpp", Break_form);
USEFORM("Infos_frm.cpp", Infos_form);
USEFORM("Journal_frm.cpp", Journal_form);
USEFORM("Lista_frm.cpp", Lista_form);
USEFORM("Quest_frm.cpp", Quest_form);
USEFORM("..\..\FORM_TEMPLATES\About_frm.cpp", About_form);
USERES("Kop32.res");
USELIB("LIB\DLLIO\DLLIO.lib");
USELIB("LIB\DLLDatabase\DLLDatabase.lib");
USELIB("LIB\DLLKop32\DLLKop32.lib");
//---------------------------------------------------------------------------
#include "Koperek32_common_main.h"
TSoft::Kop32 *Kop;
WINAPI WinMain(HINSTANCE hApp, HINSTANCE hInstance, char *argts, int State)
{
    Kop = new TSoft::Kop32;
	return WinMain_common(hApp, hInstance , argts, State);
}
//---------------------------------------------------------------------------
