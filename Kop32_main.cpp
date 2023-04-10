//---------------------------------------------------------------------------
#include <vcl.h>
//---------------------------------------------------------------------------
USEFORM("Haslo_frm.cpp", HasloForm);
USEFORM("Koper_frm.cpp", KoperForm);
USEFORM("Break_frm.cpp", BreakForm);
USEFORM("Infos_frm.cpp", InfosForm);
USEFORM("Journal_frm.cpp", JournalForm);
USEFORM("Lista_frm.cpp", ListaForm);
USEFORM("Quest_frm.cpp", QuestForm);
USEFORM("..\..\FORM_TEMPLATES\About_frm.cpp", AboutForm);
USERES("Kop32.res");
USELIB(".\LIB\DLLKop32\DLLKop32.lib");
USELIB(".\LIB\DLLDatabase\DLLDatabase.lib");
USELIB(".\LIB\DLLIO\DLLIO.LIB");
//---------------------------------------------------------------------------
#define WIN32_LEAN_AND_MEAN
#include "main.h"
#include "Kop32_common.cpp"
WINAPI WinMain(HINSTANCE hApp, HINSTANCE hInstance, char *argts, int State)
{
return WinMainCommon(hApp, hInstance , argts, State);
}
//---------------------------------------------------------------------------
