//---------------------------------------------------------------------------
#include <vcl.h>
//---------------------------------------------------------------------------
#include "break_frm.h"
#include "koper_frm.h"

#pragma link "advbar"
#pragma link "ADVBAR"
#pragma link "ADVBAR"
#pragma link "ADVBAR"
#pragma link "ADVBAR"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
TBreak_form *Break_form;
//---------------------------------------------------------------------------
__fastcall TBreak_form::TBreak_form(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TBreak_form::SpeedButton1Click(TObject *Sender)
{
SpeedButton1->Down = !SpeedButton1->Down;
Koper_form->SpeedButton2Click(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TBreak_form::SpeedButton2Click(TObject *Sender)
{
SpeedButton2->Down = true;
Koper_form->SpeedButton1Click(Sender);
Hide();
}
//---------------------------------------------------------------------------

void __fastcall TBreak_form::SpeedButton3Click(TObject *Sender)
{
SpeedButton3->Down = !SpeedButton3->Down;
Hide();
}
//---------------------------------------------------------------------------

