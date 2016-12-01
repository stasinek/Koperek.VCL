//---------------------------------------------------------------------------
#define WIN32_LEAN_AND_MEAN
#include <vcl.h>
#pragma hdrstop  1
//---------------------------------------------------------------------------
#include "main.h"
//---------------------------------------------------------------------------
 USEFORM("Koper_frm.cpp", KoperForm);
USEFORM("haslo_frm.cpp", HasloForm);
USEFORM("quest_frm.cpp", QuestForm);
USEFORM("break_frm.cpp", BreakForm);
USEFORM("infos_frm.cpp", InfosForm);
USEFORM("Lista_frm.cpp", ListaForm);
USEFORM("Journal_frm.cpp", JournalForm);
//---------------------------------------------------------------------------
#include "Koper_frm.h"
 USEFORM("haslo_frm.cpp", HasloForm);
 USEFORM("quest_frm.cpp", QuestForm);
 USEFORM("break_frm.cpp", BreakForm);
 USEFORM("infos_frm.cpp", InfosForm);
 USEFORM("lista_frm.cpp", ListaForm);
#include "Lista_frm.h"
//---------------------------------------------------------------------------
 USEFORM("Journal_frm.cpp", JournalForm);
#include "Journal_frm.h"
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE hApp, HINSTANCE, char *argts, int State)
{
Kop = new TSoft_Kop32;

try
{
char *commandDst = (char*)malloc(strlen(argts)+1);
	  strcpy(commandDst,argts);
char *temp = (char*)malloc(strlen(argts)+1);
      strupr(strcpy(temp,argts));
char *commandSrc = (char*)malloc(2);
      strcpy(commandSrc,"");

		Application->Initialize();
		Application->Title = "sstoft.Koperek-VCL";
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
       {
        char *clip_str = (char*)GetClipboardData(CF_TEXT);
          if (clip_str!=NULL) {
              commandSrc = strcpy((char*)realloc(clip_str,strlen(clip_str)+1),clip_str);
              }
          else commandSrc[0] = '\0';
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
Kop->Execute(commandDst,commandSrc);
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







