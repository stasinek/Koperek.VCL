//---------------------------------------------------------------------------
#ifndef Search_frm_H
#define Search_frm_H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include ".\..\..\PACKAGES\advbar.h"
#include <Buttons.hpp>
#include "ADVBAR.h"
//---------------------------------------------------------------------------
class TBreakForm : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
    TAdvancedBar *AdvancedBar1;
	TLabel *Label2;
	TSpeedButton *SpeedButton1;
	TSpeedButton *SpeedButton2;
	TLabel *Label3;
	TLabel *Label4;
	TSpeedButton *SpeedButton3;
	void __fastcall SpeedButton1Click(TObject *Sender);
	void __fastcall SpeedButton2Click(TObject *Sender);
	void __fastcall SpeedButton3Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TBreakForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TBreakForm *BreakForm;
//---------------------------------------------------------------------------
#endif
