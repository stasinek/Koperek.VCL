//---------------------------------------------------------------------------
#include <vcl.h>
//---------------------------------------------------------------------------
#pragma hdrstop
//---------------------------------------------------------------------------
#include "Koper_frm.h"
#include "quest_frm.h"
#include "main.h"
//---------------------------------------------------------------------------
#pragma link "browsedlg"
#pragma link "advbar"
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
   {if (kop->list.src.Init.Count==0) SrcListCombo->Items->Text = "";
    else
       {SrcListCombo->Items->Text = kop->list.src.Init.Text[LINES];
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
   {if (kop->list.dst.Init.Count==0) DstListCombo->Items->Text = "";
    else
       {DstListCombo->Items->Text = kop->list.dst.Init.Text[LINES];
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

Edit2->Text = kop->options.Argts.Text[COMMA];
Edit3->Text = kop->options.Masks.Text[COMMA];

switch (kop->options.Operation) {
case opKOPIUJ:
   Image2->Picture->Icon->Handle = LoadIcon(hInst,"MAINICON");
   QuestForm->Caption = "PotwierdŸ kopiowanie...";
break;
case opPRZENIES:
   Image2->Picture->Icon->Handle = LoadIcon(hInst,"MAINICON2");
   QuestForm->Caption = "PotwierdŸ przeniesienie...";
break;
case opUSUN:
   Image2->Picture->Icon->Handle = LoadIcon(hInst,"MAINICON3");
   QuestForm->Caption = "PotwierdŸ usuwanie...";
break;
case opKODUJ:
   Image2->Picture->Icon->Handle = LoadIcon(hInst,"MAINICON4");
   QuestForm->Caption = "PotwierdŸ zakodowanie...";
break;
case opDEKODUJ:
   Image2->Picture->Icon->Handle = LoadIcon(hInst,"MAINICON5");
   QuestForm->Caption = "PotwierdŸ dekodowanie...";
break;
case opLISTUJ:
   Image2->Picture->Icon->Handle = LoadIcon(hInst,"MAINICON8");
   QuestForm->Caption = "PotwierdŸ listowanie...";
break;
}
if (kop->options.Operation==opKODUJ)
   {PageControl1->ActivePageIndex = 0;
    TabSheet2->TabVisible = true;
    Button2->Caption = "&Dalej >";
    Button2->ModalResult = mrNone;
    CheckBox1->Checked = (kop->options.Methods & mtXOR)!=0;
    CheckBox2->Checked = (kop->options.Methods & mtSXQ)!=0;
    CheckBox3->Checked = (kop->options.Methods & mtLZS)!=0;
    CheckBox4->Checked = (kop->options.Methods & mtBWT)!=0;
    CheckBox5->Checked = (kop->options.Methods & mtMTF)!=0;
    CheckBox6->Checked = (kop->options.Methods & mtHUF)!=0;
    CheckBox7->Checked = (kop->options.Methods & mtARI)!=0;
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
kop->options.Masks.Text[COMMA] = Edit3->Text.c_str();
}
//---------------------------------------------------------------------------

void __fastcall TQuestForm::Edit2Change(TObject *Sender)
{
kop->options.Argts.Text[COMMA] = Edit2->Text.c_str();
}
//---------------------------------------------------------------------------

void __fastcall TQuestForm::SpeedButton1Click(TObject *Sender)
{
Application->ProcessMessages();
if (SrcListCombo->ItemIndex==-1)
    return;
kop->list.src.Init.Delete(SrcListCombo->ItemIndex);
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
kop->list.dst.Init.Delete(DstListCombo->ItemIndex);
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
      kop->list.src.Init.Insert(0,ASCHAR(BrowseDialog1->PathName.c_str()));

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
      kop->list.dst.Init.Insert(0,ASCHAR(BrowseDialog1->PathName.c_str()));

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
/*int item = SrcListCombo->ItemIndex;
if (item==-1) SrcListCombo->Text = "";
else
   {SrcListCombo->ItemIndex = item;
   }
int item = DstListCombo->ItemIndex;
if (item==-1) DstListCombo->Text = "";
else
   {DstListCombo->ItemIndex = item;
   }
*/

void __fastcall TQuestForm::Button2Click(TObject *Sender)
{
if (PageControl1->ActivePageIndex==0)
   {PageControl1->ActivePageIndex =1;
    Button1->Caption = "< &Wstecz";
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
    Button2->Caption = "&Dalej >";
    Button2->ModalResult = mrNone;
    return;
   }
if (PageControl1->ActivePageIndex==0)
   {PageControl1->ActivePageIndex =1;
    Button1->Caption = "< &Wstecz";
    Button1->ModalResult = mrNone;
    return;
   }
}
//---------------------------------------------------------------------------

void __fastcall TQuestForm::CheckBox1Click(TObject *Sender)
{
if (CheckBox1->Checked) kop->options.Methods |= mtXOR;
else
    kop->options.Methods &= ~mtXOR;
}
//---------------------------------------------------------------------------

void __fastcall TQuestForm::CheckBox2Click(TObject *Sender)
{
if (CheckBox2->Checked) kop->options.Methods |= mtSXQ;
else
    kop->options.Methods &= ~mtSXQ;
}
//---------------------------------------------------------------------------

void __fastcall TQuestForm::CheckBox3Click(TObject *Sender)
{
if (CheckBox3->Checked) kop->options.Methods |= mtLZS;
else
    kop->options.Methods &= ~mtLZS;
}
//---------------------------------------------------------------------------

void __fastcall TQuestForm::CheckBox4Click(TObject *Sender)
{
if (CheckBox4->Checked) kop->options.Methods |= mtBWT;
else
    kop->options.Methods &= ~mtBWT;
}
//---------------------------------------------------------------------------

void __fastcall TQuestForm::CheckBox5Click(TObject *Sender)
{
if (CheckBox5->Checked) kop->options.Methods |= mtMTF;
else
    kop->options.Methods &= ~mtMTF;
}
//---------------------------------------------------------------------------

void __fastcall TQuestForm::ComboBox1Change(TObject *Sender)
{
kop->options.Dict = ComboBox1->Text.ToIntDef(256);
if (kop->options.Dict > 65536 || kop->options.Dict < 64)
   {kop->options.Dict = 256;
    ComboBox1->Text = kop->options.Dict;
   }
}
//---------------------------------------------------------------------------

void __fastcall TQuestForm::CheckBox6Click(TObject *Sender)
{
if (CheckBox5->Checked) kop->options.Methods |= mtHUF;
else
    kop->options.Methods &= ~mtHUF;
}
//---------------------------------------------------------------------------

void __fastcall TQuestForm::CheckBox7Click(TObject *Sender)
{
if (CheckBox5->Checked) kop->options.Methods |= mtARI;
else
    kop->options.Methods &= ~mtARI;
}
//---------------------------------------------------------------------------

