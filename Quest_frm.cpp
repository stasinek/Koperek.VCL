//---------------------------------------------------------------------------
#include <vcl.h>
//---------------------------------------------------------------------------
#include "Koper_frm.h"
#include "quest_frm.h"
#include "Koperek32_common_main.h"
//---------------------------------------------------------------------------
#pragma link "BROWSEDLG"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
TQuest_form *Quest_form;
//---------------------------------------------------------------------------

__fastcall TQuest_form::TQuest_form(TComponent* Owner)
    : TForm(Owner)
{
hInst = (HINSTANCE)HInstance;
Image1->Picture->Bitmap->Handle = LoadBitmap(hInst,"LEFTQUEST");
}
//---------------------------------------------------------------------------

int __fastcall TQuest_form::Potwierdz(bool ZEnabled,bool DEnabled)
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
    SpeedButton5Click(this);
break;
case opPRZENIES:
    SpeedButton6Click(this);
break;
case opKODUJ:
    SpeedButton8Click(this);
break;
case opDEKODUJ:
    SpeedButton9Click(this);
break;
case opUSUN:
    SpeedButton7Click(this);
break;
case opLISTUJ:
    SpeedButton10Click(this);
break;
}
if (!this->Visible) return ShowModal();
else return mrNo;
}
//---------------------------------------------------------------------------

void __fastcall TQuest_form::Edit3Change(TObject *Sender)
{
Kop->options.Masks.Text[COMMA] = AnsiString(Edit3->Text.c_str()).c_str();
}
//---------------------------------------------------------------------------

void __fastcall TQuest_form::Edit2Change(TObject *Sender)
{
Kop->options.Argts.Text[COMMA] = AnsiString(Edit2->Text.c_str()).c_str();
}
//---------------------------------------------------------------------------

void __fastcall TQuest_form::SpeedButton1Click(TObject *Sender)
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

void __fastcall TQuest_form::SpeedButton2Click(TObject *Sender)
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

void __fastcall TQuest_form::SpeedButton3Click(TObject *Sender)
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

void __fastcall TQuest_form::SpeedButton4Click(TObject *Sender)
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

void __fastcall TQuest_form::FormDestroy(TObject *Sender)
{
DeleteObject(Image1->Picture->Bitmap->Handle);
}
//---------------------------------------------------------------------------


void __fastcall TQuest_form::Button2Click(TObject *Sender)
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

void __fastcall TQuest_form::Button1Click(TObject *Sender)
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

void __fastcall TQuest_form::CheckBox1Click(TObject *Sender)
{
if (CheckBox1->Checked) Kop->options.Methods |= mtXOR;
else
    Kop->options.Methods &= ~mtXOR;
}
//---------------------------------------------------------------------------

void __fastcall TQuest_form::CheckBox2Click(TObject *Sender)
{
if (CheckBox2->Checked) Kop->options.Methods |= mtSXQ;
else
    Kop->options.Methods &= ~mtSXQ;
}
//---------------------------------------------------------------------------

void __fastcall TQuest_form::CheckBox3Click(TObject *Sender)
{
if (CheckBox3->Checked) Kop->options.Methods |= mtLZS;
else
    Kop->options.Methods &= ~mtLZS;
}
//---------------------------------------------------------------------------

void __fastcall TQuest_form::CheckBox4Click(TObject *Sender)
{
if (CheckBox4->Checked) Kop->options.Methods |= mtBWT;
else
    Kop->options.Methods &= ~mtBWT;
}
//---------------------------------------------------------------------------

void __fastcall TQuest_form::CheckBox5Click(TObject *Sender)
{
if (CheckBox5->Checked) Kop->options.Methods |= mtMTF;
else
    Kop->options.Methods &= ~mtMTF;
}
//---------------------------------------------------------------------------

void __fastcall TQuest_form::ComboBox1Change(TObject *Sender)
{
Kop->options.Dict = ComboBox1->Text.ToIntDef(256);
if (Kop->options.Dict > 65536 || Kop->options.Dict < 64)
   {Kop->options.Dict = 4096;
    ComboBox1->Text = Kop->options.Dict;
   }
}
//---------------------------------------------------------------------------

void __fastcall TQuest_form::CheckBox6Click(TObject *Sender)
{
if (CheckBox5->Checked) Kop->options.Methods |= mtHUF;
else
    Kop->options.Methods &= ~mtHUF;
}
//---------------------------------------------------------------------------

void __fastcall TQuest_form::CheckBox7Click(TObject *Sender)
{
if (CheckBox5->Checked) Kop->options.Methods |= mtARI;
else
    Kop->options.Methods &= ~mtARI;
}
//---------------------------------------------------------------------------

void __fastcall TQuest_form::SpeedButton5Click(TObject *Sender)
{
   Image2->Picture->Icon->Handle = LoadIcon(hInst,"MAINICON");
   Quest_form->Caption = "Confirm file COPY...";
   SpeedButton5->Down = true;
   SpeedButton12->Enabled = false; Edit2->Enabled = false;
   PageControl1->ActivePageIndex =0;
   TabSheet2->TabVisible = false;
   Button2->ModalResult = mrYes;
   Button2->Caption = "&OK";
}
//---------------------------------------------------------------------------

void __fastcall TQuest_form::SpeedButton6Click(TObject *Sender)
{
   Image2->Picture->Icon->Handle = LoadIcon(hInst,"MAINICON2");
   Quest_form->Caption = "Confirm file MOVE...";
   SpeedButton6->Down = true;
   SpeedButton12->Enabled = false; Edit2->Enabled = false;
   PageControl1->ActivePageIndex =0;
   TabSheet2->TabVisible = false;
   Button2->ModalResult = mrYes;
   Button2->Caption = "&OK";
}
//---------------------------------------------------------------------------

void __fastcall TQuest_form::SpeedButton7Click(TObject *Sender)
{
   Image2->Picture->Icon->Handle = LoadIcon(hInst,"MAINICON3");
   Quest_form->Caption = "Confirm file DELETION...";
   SpeedButton7->Down = true;
   SpeedButton12->Enabled = false; Edit2->Enabled = false;
   PageControl1->ActivePageIndex =0;
   TabSheet2->TabVisible = false;
   Button2->ModalResult = mrYes;
   Button2->Caption = "&OK";
}
//---------------------------------------------------------------------------

void __fastcall TQuest_form::SpeedButton8Click(TObject *Sender)
{
   Image2->Picture->Icon->Handle = LoadIcon(hInst,"MAINICON4");
   Quest_form->Caption = "Confirm Compression... (.eno)";
   SpeedButton8->Down = true;
   SpeedButton12->Enabled = false; Edit2->Enabled = false;
   PageControl1->ActivePageIndex =0;
   TabSheet2->TabVisible = true;
   if (Kop->options.Operation==opKODUJ) {
    CheckBox1->Checked = (Kop->options.Methods & mtXOR)!=0;
    CheckBox2->Checked = (Kop->options.Methods & mtSXQ)!=0;
    CheckBox3->Checked = (Kop->options.Methods & mtLZS)!=0;
    CheckBox4->Checked = (Kop->options.Methods & mtBWT)!=0;
    CheckBox5->Checked = (Kop->options.Methods & mtMTF)!=0;
    CheckBox6->Checked = (Kop->options.Methods & mtHUF)!=0;
    CheckBox7->Checked = (Kop->options.Methods & mtARI)!=0;
   }
   else {
       CheckBox1->Checked = false;
       CheckBox2->Checked = false;
       CheckBox3->Checked = true;
       CheckBox4->Checked = false;
       CheckBox5->Checked = false;
       CheckBox6->Checked = true;
       CheckBox7->Checked = false;
       Kop->options.Operation==opKODUJ;
       Kop->options.Methods = mtLZS | mtHUF;
   }
   Button2->ModalResult = mrNone;
   Button2->Caption = "&Next >";
}
//---------------------------------------------------------------------------

void __fastcall TQuest_form::SpeedButton9Click(TObject *Sender)
{
   Image2->Picture->Icon->Handle = LoadIcon(hInst,"MAINICON5");
   Quest_form->Caption = "Confirm Decompression...";
   SpeedButton9->Down = true;
   SpeedButton12->Enabled = false; Edit2->Enabled = false;
   PageControl1->ActivePageIndex =0;
   TabSheet2->TabVisible = false;
   Kop->options.Operation==opDEKODUJ;
   Button2->ModalResult = mrYes;
   Button2->Caption = "&OK";
}
//---------------------------------------------------------------------------

void __fastcall TQuest_form::SpeedButton13Click(TObject *Sender)
{
//SpeedButton11->Down = true;
}
//---------------------------------------------------------------------------

void __fastcall TQuest_form::SpeedButton10Click(TObject *Sender)
{
   Image2->Picture->Icon->Handle = LoadIcon(hInst,"MAINICON8");
   Quest_form->Caption = "Confirm listing...";
   SpeedButton10->Down = true;
   SpeedButton12->Enabled = true;
   PageControl1->ActivePageIndex =0;
   TabSheet2->TabVisible = false;
   Edit2->Enabled = true;
   Button2->ModalResult = mrYes;
   Button2->Caption = "&OK";
}
//---------------------------------------------------------------------------






