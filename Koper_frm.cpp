//---------------------------------------------------------------------------
#include <vcl.h>
//---------------------------------------------------------------------------
#include "koper_frm.h"
#include "quest_frm.h"
#include "haslo_frm.h"
#include "infos_frm.h"
#include "break_frm.h"
#include "lista_frm.h"
#include "journal_frm.h"
#include ".\LIB\DLLIO\TSoft_IO.h"
//---------------------------------------------------------------------------
#include "main.h"
//----------------------------------------------------------------------------
#pragma link "advbar"
#pragma link "systray"
#pragma link "ADVBAR"
#pragma link "SYSTRAY"
#pragma link "ADVBAR"
#pragma link "SYSTRAY"
#pragma link "ADVBAR"
#pragma link "SYSTRAY"
#pragma link "ADVBAR"
#pragma link "SYSTRAY"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
TKoperForm *KoperForm;
//---------------------------------------------------------------------------

__fastcall TKoperForm::TKoperForm(TComponent* Owner)
	: TForm(Owner)
{
lpcaption = new char[255];
temp0 = new char[10240];
temp1 = new char[255];
temp2 = new char[255];
temp3 = new char[255];
temp4 = new char[255];
buffer1 = new char[255];
buffer2 = new char[255];
buffer3 = new char[255];
buffer4 = new char[255];
Kop->OnBreak = KoperForm->DoBreak;
hApp = (HINSTANCE)HInstance;

}
//---------------------------------------------------------------------------

void __fastcall TKoperForm::FormCreate(TObject *Sender)
{
AdvancedBar5->Position = 0;
AdvancedBar6->Position = 0;
AdvancedBar2->Position = 0;
}
//---------------------------------------------------------------------------

void __fastcall TKoperForm::Timer1Timer(TObject *Sender) {
static int tik = 0;
static double x, xold, ic;

if (MineloBajt ==Kop->progress.src.all.Read && ic==Kop->list.iCur) { Application->ProcessMessages();
return;}

ic = Kop->list.iCur;
 MineloBajt = Kop->progress.src.all.Read;
ZostaloBajt = Kop->progress.src.all.Size - Kop->progress.src.all.Read;
 MineloCzas = timeGetTime() - OldCzas;
 MineloCzasTik  = timeGetTime()-MineloCzasTikOld;
 MineloBajtTik  = Kop->progress.src.all.Read-MineloBajtTikOld;
if (MineloBajt > 0)
	 ZostaloCzas = __int64(MineloCzas*ZostaloBajt)/MineloBajt;
else ZostaloCzas = 0;

if  (++tik == 10) {
	tik = 0;
	MineloCzasTikOld = timeGetTime();
	MineloBajtTikOld = Kop->progress.src.all.Read;
}
if  (tik % 10) {
	if (MineloCzasTik!=0 && MineloCzas!=0)
	if (double(MineloBajt)/double(MineloCzas)!=0)
	x = (double(MineloBajtTik)/double(MineloCzasTik)) / (double(MineloBajt)/double(MineloCzas));
	if (xold!=x && x+1!=0)
		{
		xold =x;
		AdvancedBar1->Position = 1000 - (1/(x+1)) * 1000;
		Label3->Caption = "Actual speed ~ " + FloatToStrF(x,ffGeneral,2,4) + " x averange speed";
		}
	if (x==0) {
		AdvancedBar1->Position = 500;
		Label3->Caption = "Actual speed ~ impossible to calulate.";
	}
	}
if (MineloCzas > 0 && MineloCzas/1000!=0)
   {sprintf(buffer1,"Speed ~ %s/s",
		GetBajtText(__int64(MineloBajt)/(MineloCzas/1000)));
   }
else
   {sprintf(buffer1,"Speed ~ 0,00 B/s");
   }
if (ZostaloCzas < 60000)
   {sprintf(buffer2,"seconds %d left",
		int(ZostaloCzas/1000)%60);
   }
else
if (ZostaloCzas < 3600000)
   {sprintf(buffer2,"minutes %d and %d seconds left",
		int(ZostaloCzas/1000/60), int(ZostaloCzas/1000)%60);
   }
else
   {sprintf(buffer2,"hours %d and %d minutes left",
		int(ZostaloCzas/1000/3600), int(ZostaloCzas/1000/60)%60);
   }
if (MineloCzas < 60000)
   {sprintf(buffer3,"Working since %d seconds",
		int(MineloCzas/1000)%60);
   }
else
if (MineloCzas < 3600000)
   {sprintf(buffer3,"Working since %d minutes a and %d seconds",
		int(MineloCzas/1000/60), int(MineloCzas)%60);
   }
else
   {sprintf(buffer3,"Working since %d hours and %d minutes",
		int(MineloCzas/1000/3600), int((MineloCzas/1000)/60)%60);
   }
strcpy(buffer4,buffer3);
strcat(buffer4,", ");
strcat(buffer4,buffer2);
//--------------------------
if (strcmp(buffer1,AnsiString(this->Label1->Caption.c_str()).c_str())!=0)
	this->Label1->Caption = buffer1;
if (strcmp(buffer4,AnsiString(this->Label2->Caption.c_str()).c_str())!=0)
	this->Label2->Caption = buffer4;

sprintf(buffer1,"There is %d files left, in sum %s",(Kop->list.src.Main.Count-(Kop->list.iCur-Kop->list.iBgn)),GetBajtText(Kop->progress.src.all.Size-Kop->progress.src.all.Read));
if (strcmp(buffer1,AnsiString(this->Label5->Caption.c_str()).c_str())!=0)
	Label5->Caption = buffer1;

if (Kop->options.Operation==opKODUJ && Kop->progress.dst.all.Read!=0) {
	double s = float(Kop->progress.src.all.Read)/float(Kop->progress.dst.all.Read);
	sprintf(buffer4,"Compression ratio = %01.2f/1", s);
	if (s+1!=0) AdvancedBar2->Position = 100 - (1/(s+1)) * 100;
	else AdvancedBar2->Position = 100;
	if (strcmp(buffer4,AnsiString(this->Label4->Caption.c_str()).c_str())!=0)
		this->Label4->Caption = buffer3;
	}
else
if (Kop->options.Operation==opKODUJ && Kop->progress.src.all.Read!=0) {
	double s = float(Kop->progress.dst.all.Read)/float(Kop->progress.src.all.Read);
	sprintf(buffer4,"Decompression ratio = %01.2f/1", s);
	if (s+1!=0) AdvancedBar2->Position = 100 - (1/(s+1)) * 100;
	else AdvancedBar2->Position = 100;
	if (strcmp(buffer4,AnsiString(this->Label4->Caption.c_str()).c_str())!=0)
		this->Label4->Caption = buffer3;
	}
else AdvancedBar2->Visible = false;
//--------------------------
Application->Title = KoperForm->Caption;
Application->ProcessMessages();
}
//----------------------------------------------------------------------------

int __stdcall TKoperForm::DoBreak(__int32 BreakCode,__int32 BreakButton) {
//static int ProgressDir = 1;

if (BreakCode&opSEEKPROGRESS)
   {
//	if (BreakForm->AdvancedBar1->Position >= 100 ) ProgressDir = -1;
//	else if (BreakForm->AdvancedBar1->Position == 0) ProgressDir = 1;
//    BreakForm->AdvancedBar1->Position = (BreakForm->AdvancedBar1->Position + ProgressDir);

	if (BreakCode&isSRC) {
	if (Kop->list.src.Main.Count>0) {
		strExtractFilePath(temp0,Kop->list.src.Main.Items[Kop->list.src.Main.Count-1]->text);
		for (;strLen(temp0)>=55; )
			{
			strDel(temp0,3,8);
			strInsert(temp0,3,"...\\\0");
			}
		if (strcmp(temp0, AnsiString(BreakForm->Label2->Caption.c_str()).c_str())!=0)
		BreakForm->Label2->Caption = temp0;
		}
	}
	if (BreakCode&isDST) {
	if (Kop->list.dst.Main.Count>0) {
		strExtractFilePath(temp0,Kop->list.dst.Main.Items[Kop->list.dst.Main.Count-1]->text);
		for (;strLen(temp0)>=55; )
			{
			strDel(temp0,3,8);
			strInsert(temp0,3,"...\\\0");
			}
		if (strcmp(temp0, AnsiString(BreakForm->Label2->Caption.c_str()).c_str())!=0)
		BreakForm->Label2->Caption = temp0;
		}
	}
	BreakForm->Label3->Caption = "There is " + (AnsiString)Kop->list.src.Main.Count + " files, total size " + GetBajtText(Kop->progress.src.all.Size);
	if (Kop->list.dst.Main.Count!=0 && Kop->progress.dst.all.Size!=0) BreakForm->Label4->Caption = "In destination dir. " + (AnsiString)Kop->list.dst.Main.Count + " files, total size " + GetBajtText(Kop->progress.dst.all.Size);
	KoperForm->Label5->Caption = BreakForm->Label3->Caption;
   }
if (BreakCode&onPROGRESS)
   {
	if (Kop->progress.src.all.Size!=0)
	AdvancedBar2->Position = 100*(double(Kop->progress.src.all.Read)/double(Kop->progress.src.all.Size));
	else
	AdvancedBar2->Position = 0;

	if (Kop->progress.src.one.Size!=0)
		AdvancedBar5->Position = 100*(double(Kop->progress.src.one.Read)/double(Kop->progress.src.one.Size));
	else
	AdvancedBar5->Position = 0;

	if (Kop->progress.dst.one.Size!=0)
		AdvancedBar6->Position = 100*(double(Kop->progress.dst.one.Read)/double(Kop->progress.dst.one.Size));
	else
	AdvancedBar6->Position = 0;
   }
if (BreakCode&opKOPIUJ)
   {if (BreakCode&isDIRECTORY) strcpy(lpcaption,"COPY Dir. ");
	else strcpy(lpcaption,"COPY file ");
	if (Kop->list.src.Main.Count!=0 && Kop->list.src.Main.Count!=0)
	sprintf(temp4,"'%s' do '%s'",strExtractFileName(temp1,Kop->list.src.Main.Items[Kop->list.iCur]->text),strExtractFileName(temp2,strExtractFilePath(temp3,Kop->list.dst.Main.Items[Kop->list.iCur]->text)));
	strcat(lpcaption,temp4);
	this->Caption = lpcaption;
   }
else
if (BreakCode&opPRZENIES)
   {if (BreakCode&isDIRECTORY) strcpy(lpcaption,"MOVE dir. ");
	else strcpy(lpcaption,"MOVE plik ");
	if (Kop->list.src.Main.Count!=0 && Kop->list.src.Main.Count!=0)
	sprintf(temp4,"'%s' do '%s'",strExtractFileName(temp1,Kop->list.src.Main.Items[Kop->list.iCur]->text),strExtractFileName(temp2,strExtractFilePath(temp3,Kop->list.dst.Main.Items[Kop->list.iCur]->text)));
	strcat(lpcaption,temp4);
	this->Caption = lpcaption;
   }
else
if (BreakCode&opKODUJ)
   {if (BreakCode&isDIRECTORY) strcpy(lpcaption,"COMPRESS dir. ");
	else strcpy(lpcaption,"COMPRESS File ");
	if (Kop->list.src.Main.Count!=0 && Kop->list.src.Main.Count!=0)
	sprintf(temp4,"'%s' do '%s'",strExtractFileName(temp1,Kop->list.src.Main.Items[Kop->list.iCur]->text),strExtractFileName(temp2,strExtractFilePath(temp3,Kop->list.dst.Main.Items[Kop->list.iCur]->text)));
	strcat(lpcaption,temp4);
	this->Caption = lpcaption;
   }
else
if (BreakCode&opDEKODUJ)
   {if (BreakCode&isDIRECTORY) strcpy(lpcaption,"DECODE dir. ");
	else strcpy(lpcaption,"DECODE file ");
	if (Kop->list.src.Main.Count!=0 && Kop->list.src.Main.Count!=0)
	sprintf(temp4,"'%s' do '%s'",strExtractFileName(temp1,Kop->list.src.Main.Items[Kop->list.iCur]->text),strExtractFileName(temp2,strExtractFilePath(temp3,Kop->list.dst.Main.Items[Kop->list.iCur]->text)));
	strcat(lpcaption,temp4);
	this->Caption = lpcaption;
   }
else
if (BreakCode&opUSUN)
   {if (BreakCode&isDIRECTORY) strcpy(lpcaption,"DELETE dir. ");
	else strcpy(lpcaption,"DELETE file ");
	if (Kop->list.src.Main.Count!=0)
	sprintf(temp4,"'%s' z '%s'",strExtractFileName(temp1,Kop->list.src.Main.Items[Kop->list.iCur]->text),strExtractFileName(temp2,strExtractFilePath(temp3,Kop->list.src.Main.Items[Kop->list.iCur]->text)));
	strcat(lpcaption,temp4);
	this->Caption = lpcaption;
   }

if (BreakCode&onSEEKING)
   {Application->Title = BreakForm->Caption;
	BreakForm->Show();
/*    POINT curMousePoint;
	GetCursorPos(&curMousePoint);
	SetWindowPos(BreakForm->Handle,HWND_NOTOPMOST,
				 curMousePoint.x,curMousePoint.y,0,0,
				 SWP_NOACTIVATE|SWP_NOSIZE|SWP_SHOWWINDOW);
*/   }
else
if (BreakCode&onIO)
   {
	if (Kop->options.Operation==opLISTUJ)
	   {Application->Title = "Listing files...";
		BreakForm->Label1->Caption = Application->Title;
		Application->ProcessMessages();
		return mrNo;
	   }
	else
	   {BreakForm->AdvancedBar1->Position = 1000;
		BreakForm->SpeedButton3->Enabled = true;
		while (Kop->options.Stop!=true && BreakForm->Visible==true) { Application->ProcessMessages(); Sleep(220); }
		if (Kop->options.Stop!=true) {
		this->OldCzas = timeGetTime();
		this->MineloCzasTikOld = timeGetTime();
		this->MineloBajtTikOld = 0;
		Timer1Timer(this);
		Timer1->Enabled = true;
		POINT curMousePoint;
		KoperForm->Show();
		}
/*        GetCursorPos(&curMousePoint);
		SetWindowPos(KoperForm->Handle,HWND_NOTOPMOST,
					 curMousePoint.x,curMousePoint.y,0,0,
					 SWP_NOACTIVATE|SWP_NOSIZE|SWP_SHOWWINDOW);
*/       }
   }
else
if (BreakCode&onQUEST)
   {
	if (Kop->options.Operation==opUSUN) return QuestForm->Potwierdz(1,0);
	else
	if (QuestForm->Potwierdz(1,1)!=mrYes)
		return mrNo;
	else
	if (Kop->options.Operation!=opKODUJ || Kop->options.Operation!=opDEKODUJ)
		return mrYes;
	else
	if (strlen(Kop->GetPassword())==0)
		return HasloForm->ShowModal();
	else
		return mrYes;
   }
else
if (BreakCode&onREPLACE_QUEST)
   {
	if (Kop->list.src.Main.Count!=0 && Kop->list.src.Main.Count!=0)
	return InfosForm->ZastopInfo(Kop->list.dst.Main.Items[Kop->list.iCur]->text,Kop->list.src.Main.Items[Kop->list.iCur]->text);
	else return InfosForm->ZastopInfo("","");
   }
if (MineloCzasJournal!=MineloCzas || BreakButtonJournal!=BreakButton || BreakCodeJournal!=BreakCode) {
	/*JournalForm->ValueListEditor1->InsertRow((AnsiString)(int(MineloCzas/1000)/3600) + ":" + (AnsiString)int((int(MineloCzas/1000)%3600)/60) + ":" + (AnsiString)(int(MineloCzas/1000)%60) + " " + (AnsiString)(int(MineloCzas)%1000) + "ms",
										 (AnsiString)BreakCode + " " + (AnsiString)BreakButton + " " +
										 (AnsiString)Kop->progress.src.one.Read + " " + (AnsiString)Kop->progress.dst.one.Read + " " +
										 (AnsiString)Kop->progress.src.all.Read + " " + (AnsiString)Kop->progress.dst.all.Read
										 ,
										 true);
	*/
	MineloCzasJournal = MineloCzas;
	BreakCodeJournal = BreakCode;
	BreakButtonJournal = BreakButton;

	}
Application->ProcessMessages();
return mrNo;
}
//---------------------------------------------------------------------------

void __fastcall TKoperForm::FormClose(TObject *Sender, TCloseAction &Action)
{
SpeedButton2Click(Sender);
Kop->Stop();
}
//---------------------------------------------------------------------------

char *__stdcall TKoperForm::GetBajtText(__int64 liczbaDoDzielenia) {
static char text[16];

if (liczbaDoDzielenia >= 1048576)
   {if (liczbaDoDzielenia%1048576!=0) sprintf(text,"%d,%02d MB",int(liczbaDoDzielenia/1048576),(100*int(liczbaDoDzielenia%1048576))/1048576);
	else sprintf(text,"%d MB",int(liczbaDoDzielenia/1048576));
	return text;
   }
if (liczbaDoDzielenia >= 1024)
   {if (liczbaDoDzielenia%1024!=0) sprintf(text,"%d,%02d KB",int(liczbaDoDzielenia/1024),(100*int(liczbaDoDzielenia%1024))/1024);
	else sprintf(text,"%d KB",int(liczbaDoDzielenia/1024));
	return text;
   }
if (liczbaDoDzielenia >= 0)
   {if (liczbaDoDzielenia!=0) sprintf(text,"%d KB",int(liczbaDoDzielenia/1024));
	else sprintf(text,"0 KB");
	return text;
   }
else
	return "ERROR";
}
//---------------------------------------------------------------------------


void __fastcall TKoperForm::SpeedButton1Click(TObject *Sender)
{
Pauza = !Pauza;
Timer1->Enabled = !Pauza;

 if (Pauza==true) SpeedButton1->Down = true;
 else
	 SpeedButton1->Down = false;

for (int time = timeGetTime(); Pauza==true; time = timeGetTime())
	{
	 Application->ProcessMessages();
	 Sleep(300);
	 OldCzas+=timeGetTime() - time;
	 MineloCzasTikOld  = timeGetTime()-time;
	}
}
//---------------------------------------------------------------------------

void __fastcall TKoperForm::SpeedButton2Click(TObject *Sender)
{
Pauza = false; Kop->Stop();
}
//---------------------------------------------------------------------------

void __fastcall TKoperForm::SpeedButton3Click(TObject *Sender)
{
ListaForm->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TKoperForm::SpeedButton4Click(TObject *Sender)
{
JournalForm->Show();
}
//---------------------------------------------------------------------------

void __fastcall TKoperForm::FormDestroy(TObject *Sender)
{
delete lpcaption;
delete temp0;
delete temp1;
delete temp2;
delete temp3;
delete temp4;
delete buffer1;
delete buffer2;
delete buffer3;
delete buffer4;
}
//---------------------------------------------------------------------------



void __fastcall TKoperForm::SpeedButton5Click(TObject *Sender)
{
// Resource limiter (inteligent pause)    
}
//---------------------------------------------------------------------------

