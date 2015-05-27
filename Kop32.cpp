//---------------------------------------------------------------------------
#define WIN32_LEAN_AND_MEAN
#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
#include "main.h"
#include <malloc.h>
#include <fstream>
#include "Koper_frm.h"
#include "Journal_frm.h"
USEFORM("Koper_frm.cpp", KoperForm);
USEFORM("haslo_frm.cpp", HasloForm);
USEFORM("quest_frm.cpp", QuestForm);
USEFORM("break_frm.cpp", BreakForm);
USEFORM("infos_frm.cpp", InfosForm);
USEFORM("Lista_frm.cpp", ListaForm);
USEFORM("Journal_frm.cpp", JournalForm);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE hApp, HINSTANCE, char *argts, int State)
{
kop = new TSoft_Kop32;

try
{
char *commandDst = (char*)malloc(strlen(argts)+1);
	  strcpy(commandDst,argts);
char *temp = (char*)malloc(strlen(argts)+1);
      strupr(strcpy(temp,argts));
char *commandSrc = (char*)malloc(2);
      strcpy(commandSrc,"");

   Application->Initialize();
   Application->Title = "sstoft.Koperek";
                 Application->CreateForm(__classid(THasloForm), &HasloForm);
		Application->CreateForm(__classid(TQuestForm), &QuestForm);
		Application->CreateForm(__classid(TKoperForm), &KoperForm);
		Application->CreateForm(__classid(TInfosForm), &InfosForm);
		Application->CreateForm(__classid(TBreakForm), &BreakForm);
		Application->CreateForm(__classid(TListaForm), &ListaForm);
		Application->CreateForm(__classid(TJournalForm), &JournalForm);
		Application->ShowMainForm = false;

if (strstr(temp,"/ZAZNACZ")!=NULL)
    Application->Icon->Handle = LoadIcon(hApp,"MAINICON6");
else
if (strstr(temp,"/KOPIUJ")!=NULL)
    Application->Icon->Handle = LoadIcon(hApp,"MAINICON");
else
if (strstr(temp,"/PRZENIES")!=NULL)
    Application->Icon->Handle = LoadIcon(hApp,"MAINICON2");
else
if (strstr(temp,"/KODUJ")!=NULL)
    Application->Icon->Handle = LoadIcon(hApp,"MAINICON4");
else
if (strstr(temp,"/DEKODUJ")!=NULL)
    Application->Icon->Handle = LoadIcon(hApp,"MAINICON5");
else
if (strstr(temp,"/USUN")!=NULL)
    Application->Icon->Handle = LoadIcon(hApp,"MAINICON3");
else
if (strstr(temp,"/LISTUJ")!=NULL)
    Application->Icon->Handle = LoadIcon(hApp,"MAINICON8");

if (OpenClipboard(NULL))
   {
    if (IsClipboardFormatAvailable(CF_TEXT))
       {free(commandSrc);
        commandSrc = (char*)GetClipboardData(CF_TEXT);
        commandSrc = strcpy((char*)malloc(strlen(commandSrc)+1),commandSrc);
       }
    CloseClipboard();
   }
   temp = (char*)realloc(temp,strlen("ród³o: ")+strlen(commandSrc)+strlen("\n\rCel: ")+strlen(commandDst)+1);
   if (temp) {
   strcpy(temp,"ród³o: ");
   strcat(temp,commandSrc);
   strcat(temp,"\n\rCel: ");
   strcat(temp,commandDst);
   }
//---------------------
JournalForm->ValueListEditor1->InsertRow(commandDst,commandSrc,false);
kop->Execute(commandDst,commandSrc);
//---------------------
EXIT:
KoperForm->Timer1->Enabled = false;
JournalForm->ValueListEditor1->Strings->SaveToFile("journal-" +(AnsiString)int(KoperForm->OldCzas)+".txt");
delete commandSrc;
delete temp;
delete commandDst;
}
catch (Exception &exception)
{
  Application->ShowException(&exception);
}
DeleteObject(Application->Icon->Handle);
return 1;
}
//---------------------------------------------------------------------------







