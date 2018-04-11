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
TBreakForm *BreakForm;
//---------------------------------------------------------------------------
__fastcall TBreakForm::TBreakForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TBreakForm::SpeedButton1Click(TObject *Sender)
{
SpeedButton1->Down = !SpeedButton1->Down;
KoperForm->SpeedButton2Click(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TBreakForm::SpeedButton2Click(TObject *Sender)
{
SpeedButton2->Down = true;
KoperForm->SpeedButton1Click(Sender);
Hide();
}
//---------------------------------------------------------------------------

void __fastcall TBreakForm::SpeedButton3Click(TObject *Sender)
{
SpeedButton3->Down = !SpeedButton3->Down;
Hide();
}
//---------------------------------------------------------------------------

