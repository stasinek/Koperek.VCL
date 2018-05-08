//---------------------------------------------------------------------------
#define WIN32_LEAN_AND_MEAN
#include <vcl.h>
//---------------------------------------------------------------------------
#include "main.h"
//---------------------------------------------------------------------------
USEFORM("Koper_frm.cpp", KoperForm);
USEFORM("Break_frm.cpp", BreakForm);
USEFORM("Haslo_frm.cpp", HasloForm);
USEFORM("Infos_frm.cpp", InfosForm);
USEFORM("Journal_frm.cpp", JournalForm);
USEFORM("Lista_frm.cpp", ListaForm);
USEFORM("Quest_frm.cpp", QuestForm);
USEFORM("..\..\FORM_TEMPLATES\About_frm.cpp", AboutForm);
USERES("Kop32.res");
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
USEUNIT("LIB\DLLKop32\TSoft_Seeker.cpp");
USEUNIT("LIB\DLLKop32\TSoft_Stack.cpp");
USEUNIT("LIB\DLLKop32\DLLKop32.cpp");
//---------------------------------------------------------------------------
#include "Break_frm.h"
#include "Infos_frm.h"
#include "Haslo_frm.h"
#include "Koper_frm.h"
#include "Lista_frm.h"
#include "Quest_frm.h"
#include "..\..\FORM_TEMPLATES\About_frm.h"
#include "Journal_frm.h"
//---------------------------------------------------------------------------

WINAPI WinMain(HINSTANCE hApp, HINSTANCE, char *argts, int State)
{
bool useWizzard = false;

try
{
//DllEntryPoint(hApp,DLL_PROCESS_ATTACH, argts);
Kop = new TSoft::Kop32;

int al = strlen(argts);
if (al<=0) al = 1;
char *temp = (char*)strAlloc(al+1);
strupr(strcpy(temp,argts));

char *commandSrc = (char*)strAlloc(2048);
strcpy(commandSrc,"");
char *commandDst = (char*)strAlloc(al+1);
strcpy(commandDst,argts);

	     Application->Initialize();
	     Application->Title = "SSTSOFT.Koperek-VCL";
         Application->CreateForm(__classid(TBreakForm), &BreakForm);
         Application->CreateForm(__classid(THasloForm), &HasloForm);
         Application->CreateForm(__classid(TInfosForm), &InfosForm);
         Application->CreateForm(__classid(TJournalForm), &JournalForm);
         Application->CreateForm(__classid(TKoperForm), &KoperForm);
         Application->CreateForm(__classid(TListaForm), &ListaForm);
         Application->CreateForm(__classid(TQuestForm), &QuestForm);
         Application->CreateForm(__classid(TAboutForm), &AboutForm);
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
if (useWizzard==true) { QuestForm->ShowModal();
    }
else {
//---------------------
    if (OpenClipboard(NULL))
        {
   	    if (IsClipboardFormatAvailable(CF_TEXT))
   		    {
       	    char *clip_str = (char*)GetClipboardData(CF_TEXT);
       	    if (clip_str!=NULL) {
           	    strReAlloc(commandSrc,strlen(clip_str)+1);
                strcpy(commandSrc,clip_str);
           	    }
       	    else commandSrc[0] = '\0';
   		    }
   	    CloseClipboard();
	    }
    int l1 = strlen("SOURCE: ");
    int l2 = strlen(commandSrc);
    int l3 = strlen("\n\rDESTINATION: ");
    int l4 = strlen(commandDst);
	temp = (char*)strReAlloc(temp,l1+l2+l3+l4+1);
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
KoperForm->Timer1->Enabled = false;
strFree(commandSrc);
strFree(temp);
strFree(commandDst);

//DllEntryPoint(hApp,DLL_PROCESS_DETTACH, argts);
delete Kop;
}
catch (Exception &exception)
{
	Application->ShowException(&exception);
}
if (useWizzard==false) DeleteObject(Application->Icon->Handle);
return 1;
}
//---------------------------------------------------------------------------








