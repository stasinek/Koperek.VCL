//---------------------------------------------------------------------------
#define WIN32_LEAN_AND_MEAN
#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
#include "Kop32_common_main.h"
//---------------------------------------------------------------------------
USEFORM("Lista_frm.cpp", Lista_form);
USEFORM("Quest_frm.cpp", Quest_form);
USEFORM("Infos_frm.cpp", Infos_form);
USEFORM("Haslo_frm.cpp", Haslo_form);
USEFORM("Break_frm.cpp", Break_form);
USEFORM("Koper_frm.cpp", Koper_form);
USEFORM("Journal_frm.cpp", Journal_form);
//---------------------------------------------------------------------------
#include "Lista_frm.h"
#include "Quest_frm.h"
#include "Infos_frm.h"
#include "Haslo_frm.h"
#include "Break_frm.h"
#include "Koper_frm.h"
#include "Journal_frm.h"
//---------------------------------------------------------------------------
// DYNAMICZNE
#include ".\LIB\DLLKop32\TSoft_Kop32.h"
#include <malloc.h>
#include <stdio.h>
#include <fstream>
#include <windows.h>
__declspec(dllimport) TSoft::Kop32 *Kop;

int WINAPI _tWinMain(HINSTANCE hApp, HINSTANCE, LPTSTR argts, int State)
{
bool useWizzard = false;

try
{
Kop = new TSoft::Kop32;
char *commandDst = (char*)malloc(strlen(argts)+1);
strcpy(commandDst,argts);
char *temp = (char*)malloc(strlen(argts)+1);
strupr(strcpy(temp,argts));
char *commandSrc = (char*)malloc(2);
strcpy(commandSrc,"");

	Application->Initialize();
	Application->Title = "SSTSOFT.Koperek-VCL";
	Application->MainFormOnTaskBar = false;
	Application->CreateForm(__classid(TQuest_form), &Quest_form);
		Application->CreateForm(__classid(TBreak_form), &Break_form);
		Application->CreateForm(__classid(THaslo_form), &Haslo_form);
		Application->CreateForm(__classid(TInfos_form), &Infos_form);
		Application->CreateForm(__classid(TJournal_form), &Journal_form);
		Application->CreateForm(__classid(TKoper_form), &Koper_form);
		Application->CreateForm(__classid(TLista_form), &Lista_form);
		Application->ShowMainForm = false;

if (strstr(temp,"/SELECT")!=NULL)
	Application->Icon->Handle = LoadIcon(hApp,"MAINICON6");
else
if (strstr(temp,"/COPY")!=NULL)
	Application->Icon->Handle = LoadIcon(hApp,"MAINICON");
else
if (strstr(temp,"/MOVE")!=NULL)
	Application->Icon->Handle = LoadIcon(hApp,"MAINICON2");
else
if (strstr(temp,"/COMPRESS")!=NULL)
	Application->Icon->Handle = LoadIcon(hApp,"MAINICON4");
else
if (strstr(temp,"/DECOMPRESS")!=NULL)
	Application->Icon->Handle = LoadIcon(hApp,"MAINICON5");
else
if (strstr(temp,"/DELETE")!=NULL)
	Application->Icon->Handle = LoadIcon(hApp,"MAINICON3");
else
if (strstr(temp,"/LIST")!=NULL)
	Application->Icon->Handle = LoadIcon(hApp,"MAINICON8");
else
	useWizzard = true;

//---------------------
if (useWizzard==true) {
Quest_form->ShowModal();
}
else {
//---------------------
if (OpenClipboard(NULL))
   {
	if (IsClipboardFormatAvailable(CF_TEXT))
		{
		char *clip_str = (char*)GetClipboardData(CF_TEXT);
		if (clip_str!=NULL) {
			realloc(commandSrc,strlen(clip_str)+1);
			strcpy(commandSrc,clip_str);
			}
		else commandSrc[0] = '\0';
		}
	CloseClipboard();
	}
	temp = (char*)realloc(temp,strlen("SOURCE: ")+strlen(commandSrc)+strlen("\n\rDESTINATION: ")+strlen(commandDst)+1);
	if (temp) {
		strcpy(temp,"SOURCE: ");
		strcat(temp,commandSrc);
		strcat(temp,"\n\rDESTINATION: ");
		strcat(temp,commandDst);
	}
//JournalForm->ValueListEditor1->InsertRow(commandDst,commandSrc,false);
Kop->Execute(commandDst,commandSrc);
//JournalForm->ValueListEditor1->Strings->SaveToFile("Journal_" +(AnsiString)int(KoperForm->OldCzas)+".txt");
}
//---------------------
EXIT:
//---------------------
Koper_form->Timer1->Enabled = false;
delete commandSrc;
delete temp;
delete commandDst;
}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
if (useWizzard==false) DeleteObject(Application->Icon->Handle);
return 1;
}
//---------------------------------------------------------------------------
