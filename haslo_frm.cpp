//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
#include "haslo_frm.h"
#include "main.h"
//---------------------------------------------------------------------------
#pragma link "exeres"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
THasloForm *HasloForm;
//---------------------------------------------------------------------------

__fastcall THasloForm::THasloForm(TComponent* AOwner)
	: TForm(AOwner)
{
hInst = (HINSTANCE)HInstance;
}
//---------------------------------------------------------------------------

void __fastcall THasloForm::OKBtnClick(TObject *Sender)
{
if (Password1->Text!=Password2->Text) MessageBox(NULL,"Podane has³a siê nie zgadzaj¹. Has³a te musz¹ byæ takie same w obu polach tekstowych.","Zmiana has³a...",MB_OK+MB_ICONWARNING);
else
    kop->set_Password(Password2->Text.c_str());
}
//---------------------------------------------------------------------------

void __fastcall THasloForm::FormShow(TObject *Sender)
{
Password1->Text = "";
Password2->Text = "";
}
//---------------------------------------------------------------------------

void __fastcall THasloForm::Password2Change(TObject *Sender)
{
if (Password1->Text==Password2->Text) OKBtn->ModalResult = mrOk;
else
     OKBtn->ModalResult = mrNone;
}
//---------------------------------------------------------------------------

void __fastcall THasloForm::Password1Change(TObject *Sender)
{
if (Password1->Text==Password2->Text) OKBtn->ModalResult = mrOk;
else
     OKBtn->ModalResult = mrNone;
}
//---------------------------------------------------------------------------

void __fastcall THasloForm::FormCreate(TObject *Sender)
{
Image1->Canvas->Brush->Color = clBtnFace;
Image1->Canvas->FillRect(Rect(0,0,32,32));
DrawIconEx(Image1->Canvas->Handle,
    	   0,0,ExeResource1->Handle["#194"],32,32,
           NULL,NULL,DI_NORMAL);
}
//---------------------------------------------------------------------------

