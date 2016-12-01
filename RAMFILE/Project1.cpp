
#include <vcl.h>
#pragma hdrstop
//#include <windows.h>
//#include <condefs.h>
#include "DLLTSoftFileRam.h"
 USEUNIT("DLLTSoftFileRam.cpp");
//---------------------------------------------------------------------------
#pragma argsused
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
TSoftFileRam ram("C:\\ram.txt");
ram.Open();
TStringList *lista = new TStringList;
lista->LoadFromFile("c:\\lst.txt");
for (int i = 0; i <lista->Count;i++)
{
lista->Objects[i] = (TObject*)ram.Alloc(strlen(lista->Strings[i].c_str())+1);
strcpy((char*)lista->Objects[i],lista->Strings[i].c_str());
}
/*for (int i = 0; i <lista->Count;i+=2)
{
ram.Free(lista->Objects[i]);
} */
ram.Defrag();
delete lista;
return 0;
}
 