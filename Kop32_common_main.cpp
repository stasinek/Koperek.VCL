//---------------------------------------------------------------------------
#include <vcl.h>
#include <windows.h>
#include <malloc.h>
#include <stdio.h>
#include <fstream>
#pragma hdrstop
#define WIN32_LEAN_AND_MEAN
//---------------------------------------------------------------------------
#include "Break_frm.h"
#include "Infos_frm.h"
#include "Haslo_frm.h"
#include "Koper_frm.h"
#include "Quest_frm.h"
#include "..\..\FORM_TEMPLATES\About_frm.h"
#include "Journal_frm.h"
#include "Kop32_common_main.h"
//---------------------------------------------------------------------------
DWORD WINAPI WinMain_common(HINSTANCE hApp, HINSTANCE hInst, char *argts, int State)
{
bool useWizzard = false;
int temp1_len = 0; char *temp1 = NULL;
int temp2_len = 0; char *temp2 = NULL;
char *commandSrc = NULL;
char *commandDst = NULL;

try
{
temp1_len = strlen(argts); temp1 = (char*)malloc(temp1_len+4);
commandDst = (char*)malloc(temp1_len+4);
strcpy(commandDst,argts);
strcpy(temp1,argts);
strupr(temp1);

	Application->Initialize();
	Application->Title = "SSTSOFT.Koperek-VCL";
    Application->CreateForm(__classid(TBreak_form), &Break_form);
    Application->CreateForm(__classid(TInfos_form), &Infos_form);
    Application->CreateForm(__classid(TJournal_form), &Journal_form);
    Application->CreateForm(__classid(TKoper_form), &Koper_form);
    Application->CreateForm(__classid(TQuest_form), &Quest_form);
    Application->CreateForm(__classid(TAbout_form), &About_form);
    Application->CreateForm(__classid(THaslo_form), &Haslo_form);
    Application->ShowMainForm = false;

if (strstr(temp1,"/SELECT")!=NULL)
    Application->Icon->Handle = LoadIcon(hApp,"MAINICON6");
else
if (strstr(temp1,"/COPY")!=NULL)
    Application->Icon->Handle = LoadIcon(hApp,"MAINICON");
else
if (strstr(temp1,"/MOVE")!=NULL)
    Application->Icon->Handle = LoadIcon(hApp,"MAINICON2");
else
if (strstr(temp1,"/COMPRESS")!=NULL)
    Application->Icon->Handle = LoadIcon(hApp,"MAINICON4");
else
if (strstr(temp1,"/DECOMPRESS")!=NULL)
    Application->Icon->Handle = LoadIcon(hApp,"MAINICON5");
else
if (strstr(temp1,"/DELETE")!=NULL)
    Application->Icon->Handle = LoadIcon(hApp,"MAINICON3");
else
if (strstr(temp1,"/LIST")!=NULL)
    Application->Icon->Handle = LoadIcon(hApp,"MAINICON8");
else
    useWizzard = true;

//---------------------
if (useWizzard==true) {
    Quest_form->ShowModal();
}
else {
//---------------------
char *clip_ptr = NULL;
if (OpenClipboard(NULL))
   {
    if (IsClipboardFormatAvailable(CF_TEXT))
   		{
       	clip_ptr = (char*)GetClipboardData(CF_TEXT);
   		}
   	CloseClipboard();
	}
    if (clip_ptr!=NULL) { // if initialized get data, if not initialize empty string
        commandSrc = (char*)malloc(strlen(clip_ptr)+4);
        strcpy(commandSrc,clip_ptr);
    }
    else commandSrc = (char*)calloc(4,1);
    temp2_len = strlen("SOURCE: ")+strlen(commandSrc)+strlen("\n\rDESTINATION: ")+strlen(commandDst)+4;
	temp2 = (char*)malloc(temp2_len);
    strcpy(temp2,"SOURCE: ");
  	strcat(temp2,commandSrc);
  	strcat(temp2,"\n\rDESTINATION: ");
  	strcat(temp2,commandDst);
//JournalForm->ValueListEditor1->InsertRow(commandDst,commandSrc,false);
Kop->Execute(commandDst,commandSrc);
//JournalForm->ValueListEditor1->Strings->SaveToFile("Journal_" +(AnsiString)int(KoperForm->OldCzas)+".txt");
}
//---------------------
EXIT:
//---------------------
Koper_form->Timer1->Enabled = false;
}
catch (Exception &exception)
{
	Application->ShowException(&exception);
}

if (useWizzard==false) DeleteObject(Application->Icon->Handle);
if (temp1!=NULL) delete temp1;
if (temp2!=NULL) delete temp2;
if (commandSrc!=NULL) delete commandSrc;
if (commandDst!=NULL) delete commandDst;
if (Kop!=NULL) delete Kop;
return 1;
}
//---------------------------------------------------------------------------





