//---------------------------------------------------------------------------
#include <vcl.h>
//---------------------------------------------------------------------------
#include "Koper_frm.h"
#include "quest_frm.h"
#include "main.h"
//---------------------------------------------------------------------------
#pragma link "BROWSEDLG"
#pragma link "BROWSEDLG"
#pragma link "BROWSEDLG"
#pragma link "BROWSEDLG"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
TQuestForm *QuestForm;
//---------------------------------------------------------------------------

__fastcall TQuestForm::TQuestForm(TComponent* Owner)
    : TForm(Owner)
{
hInst = (HINSTANCE)HInstance;
Image1->Picture->Bitmap->Handle = LoadBitmap(hInst,"LEFTQUEST");
}
//---------------------------------------------------------------------------

int __fastcall TQuestForm::Potwierdz(bool ZEnabled,bool DEnabled)
{
if (ZEnabled==true)
   {if (Kop->list.src.Init.Count==0) SrcListCombo->Items->Text = "";
    else
       {SrcListCombo->Items->Text = Kop->list.src.Init.Text[LINES];
       }
    for (int s = 0; s < SrcListCombo->Items->Count; s++)
    for (;Canvas->TextWidth(SrcListCombo->Items->Strings[s]) > SrcListCombo->Width-25;)
        {
         SrcListCombo->Items->Strings[s] = SrcListCombo->Items->Strings[s].Delete(1,8);
         SrcListCombo->Items->Strings[s] = SrcListCombo->Items->Strings[s].Insert("...\\",1);
        }
     if (SrcListCombo->Items->Count > 0)
         SrcListCombo->ItemIndex = 0;
   }
SrcListCombo->Enabled = ZEnabled;

if (DEnabled==true)
   {if (Kop->list.dst.Init.Count==0) DstListCombo->Items->Text = "";
    else
       {DstListCombo->Items->Text = Kop->list.dst.Init.Text[LINES];
       }
   for (int s = 0; s < DstListCombo->Items->Count; s++)
   for (;Canvas->TextWidth(DstListCombo->Items->Strings[s]) > DstListCombo->Width-25;)
       {
        DstListCombo->Items->Strings[s] = DstListCombo->Items->Strings[s].Delete(1,8);
        DstListCombo->Items->Strings[s] = DstListCombo->Items->Strings[s].Insert("...\\",1);
       }
    if (DstListCombo->Items->Count > 0)
        DstListCombo->ItemIndex = 0;
   }
DstListCombo->Enabled = DEnabled;

Edit2->Text = Kop->options.Argts.Text[COMMA];
Edit3->Text = Kop->options.Masks.Text[COMMA];

switch (Kop->options.Operation) {
case opKOPIUJ:
   Image2->Picture->Icon->Handle = LoadIcon(hInst,"MAINICON");
   QuestForm->Caption = "Confirm copying...";
break;
case opPRZENIES:
   Image2->Picture->Icon->Handle = LoadIcon(hInst,"MAINICON2");
   QuestForm->Caption = "Confirm moveing...";
break;
case opUSUN:
   Image2->Picture->Icon->Handle = LoadIcon(hInst,"MAINICON3");
   QuestForm->Caption = "Confirm deletion...";
break;
case opKODUJ:
   Image2->Picture->Icon->Handle = LoadIcon(hInst,"MAINICON4");
   QuestForm->Caption = "Confirm compression...";
break;
case opDEKODUJ:
   Image2->Picture->Icon->Handle = LoadIcon(hInst,"MAINICON5");
   QuestForm->Caption = "Confirm decompression...";
break;
case opLISTUJ:
   Image2->Picture->Icon->Handle = LoadIcon(hInst,"MAINICON8");
   QuestForm->Caption = "Confirm listing...";
break;
}
if (Kop->options.Operation==opKODUJ)
   {PageControl1->ActivePageIndex = 0;
    TabSheet2->TabVisible = true;
    Button2->Caption = "&Next >";
    Button2->ModalResult = mrNone;
    CheckBox1->Checked = (Kop->options.Methods & mtXOR)!=0;
    CheckBox2->Checked = (Kop->options.Methods & mtSXQ)!=0;
    CheckBox3->Checked = (Kop->options.Methods & mtLZS)!=0;
    CheckBox4->Checked = (Kop->options.Methods & mtBWT)!=0;
    CheckBox5->Checked = (Kop->options.Methods & mtMTF)!=0;
    CheckBox6->Checked = (Kop->options.Methods & mtHUF)!=0;
    CheckBox7->Checked = (Kop->options.Methods & mtARI)!=0;
   }
else
   {PageControl1->ActivePageIndex = 0;
    TabSheet2->TabVisible = false;
    Button2->Caption = "&OK";
    Button2->ModalResult = mrYes;
   }

if (!this->Visible) return ShowModal();
else return mrNo;
}
//---------------------------------------------------------------------------

void __fastcall TQuestForm::Edit3Change(TObject *Sender)
{
Kop->options.Masks.Text[COMMA] = AnsiString(Edit3->Text.c_str()).c_str();
}
//---------------------------------------------------------------------------

void __fastcall TQuestForm::Edit2Change(TObject *Sender)
{
Kop->options.Argts.Text[COMMA] = AnsiString(Edit2->Text.c_str()).c_str();
}
//---------------------------------------------------------------------------

void __fastcall TQuestForm::SpeedButton1Click(TObject *Sender)
{
Application->ProcessMessages();
if (SrcListCombo->ItemIndex==-1)
    return;
Kop->list.src.Init.Delete(SrcListCombo->ItemIndex);
SrcListCombo->Items->Delete(SrcListCombo->ItemIndex);

if (SrcListCombo->Items->Count==0) SrcListCombo->Clear();
else
    SrcListCombo->ItemIndex = 0;
}
//---------------------------------------------------------------------------

void __fastcall TQuestForm::SpeedButton2Click(TObject *Sender)
{
Application->ProcessMessages();
if (DstListCombo->ItemIndex==-1)
    return;
Kop->list.dst.Init.Delete(DstListCombo->ItemIndex);
DstListCombo->Items->Delete(DstListCombo->ItemIndex);

if (DstListCombo->Items->Count==0) DstListCombo->Clear();
else
    DstListCombo->ItemIndex = 0;
}
//---------------------------------------------------------------------------

void __fastcall TQuestForm::SpeedButton3Click(TObject *Sender)
{
BrowseDialog1->InitialPath = SrcListCombo->Text;
Application->ProcessMessages();
if (BrowseDialog1->Execute())
   {
     SrcListCombo->Items->Insert(0,BrowseDialog1->PathName);
      Kop->list.src.Init.Insert(0,ASCHAR(BrowseDialog1->PathName.c_str()));

     for (;Canvas->TextWidth(SrcListCombo->Items->Strings[0]) > SrcListCombo->Width-25;)
         {
          SrcListCombo->Items->Strings[0] = SrcListCombo->Items->Strings[0].Delete(1,8);
          SrcListCombo->Items->Strings[0] = SrcListCombo->Items->Strings[0].Insert("...\\",1);
         }
      if (SrcListCombo->Items->Count > 0)
          SrcListCombo->ItemIndex = 0;
   }
}
//---------------------------------------------------------------------------

void __fastcall TQuestForm::SpeedButton4Click(TObject *Sender)
{
BrowseDialog1->InitialPath = DstListCombo->Text;
Application->ProcessMessages();
if (BrowseDialog1->Execute())
   {
     DstListCombo->Items->Insert(0,BrowseDialog1->PathName);
      Kop->list.dst.Init.Insert(0,ASCHAR(BrowseDialog1->PathName.c_str()));

     for (; Canvas->TextWidth(DstListCombo->Items->Strings[0]) > DstListCombo->Width-25;)
         {
          DstListCombo->Items->Strings[0] = DstListCombo->Items->Strings[0].Delete(1,8);
          DstListCombo->Items->Strings[0] = DstListCombo->Items->Strings[0].Insert("...\\",1);
         }
      if (DstListCombo->Items->Count > 0)
          DstListCombo->ItemIndex = 0;
   }
}
//---------------------------------------------------------------------------

void __fastcall TQuestForm::FormDestroy(TObject *Sender)
{
DeleteObject(Image1->Picture->Bitmap->Handle);
}
//---------------------------------------------------------------------------


void __fastcall TQuestForm::Button2Click(TObject *Sender)
{
if (PageControl1->ActivePageIndex==0)
   {PageControl1->ActivePageIndex =1;
    Button1->Caption = "< &Back";
    Button1->ModalResult = mrNone;
    Button2->Caption = "&OK";
    Button2->ModalResult = mrYes;
    return;
   }
if (PageControl1->ActivePageIndex==1)
   {PageControl1->ActivePageIndex =0;
    return;
   }
}
//---------------------------------------------------------------------------

void __fastcall TQuestForm::Button1Click(TObject *Sender)
{
if (PageControl1->ActivePageIndex==1)
   {PageControl1->ActivePageIndex =0;
    Button2->Caption = "&Next >";
    Button2->ModalResult = mrNone;
    return;
   }
if (PageControl1->ActivePageIndex==0)
   {PageControl1->ActivePageIndex =1;
    Button1->Caption = "< &Back";
    Button1->ModalResult = mrNone;
    return;
   }
}
//---------------------------------------------------------------------------

void __fastcall TQuestForm::CheckBox1Click(TObject *Sender)
{
if (CheckBox1->Checked) Kop->options.Methods |= mtXOR;
else
    Kop->options.Methods &= ~mtXOR;
}
//---------------------------------------------------------------------------

void __fastcall TQuestForm::CheckBox2Click(TObject *Sender)
{
if (CheckBox2->Checked) Kop->options.Methods |= mtSXQ;
else
    Kop->options.Methods &= ~mtSXQ;
}
//---------------------------------------------------------------------------

void __fastcall TQuestForm::CheckBox3Click(TObject *Sender)
{
if (CheckBox3->Checked) Kop->options.Methods |= mtLZS;
else
    Kop->options.Methods &= ~mtLZS;
}
//---------------------------------------------------------------------------

void __fastcall TQuestForm::CheckBox4Click(TObject *Sender)
{
if (CheckBox4->Checked) Kop->options.Methods |= mtBWT;
else
    Kop->options.Methods &= ~mtBWT;
}
//---------------------------------------------------------------------------

void __fastcall TQuestForm::CheckBox5Click(TObject *Sender)
{
if (CheckBox5->Checked) Kop->options.Methods |= mtMTF;
else
    Kop->options.Methods &= ~mtMTF;
}
//---------------------------------------------------------------------------

void __fastcall TQuestForm::ComboBox1Change(TObject *Sender)
{
Kop->options.Dict = ComboBox1->Text.ToIntDef(256);
if (Kop->options.Dict > 65536 || Kop->options.Dict < 64)
   {Kop->options.Dict = 256;
    ComboBox1->Text = Kop->options.Dict;
   }
}
//---------------------------------------------------------------------------

void __fastcall TQuestForm::CheckBox6Click(TObject *Sender)
{
if (CheckBox5->Checked) Kop->options.Methods |= mtHUF;
else
    Kop->options.Methods &= ~mtHUF;
}
//---------------------------------------------------------------------------

void __fastcall TQuestForm::CheckBox7Click(TObject *Sender)
{
if (CheckBox5->Checked) Kop->options.Methods |= mtARI;
else
    Kop->options.Methods &= ~mtARI;
}
//---------------------------------------------------------------------------




