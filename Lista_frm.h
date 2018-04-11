//---------------------------------------------------------------------------

#ifndef __Lista_frm_H
#define __Lista_frm_H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <CheckLst.hpp>
#include <FileCtrl.hpp>
#include <Grids.hpp>
#include <Buttons.hpp>
#include <Menus.hpp>
#include <ExtCtrls.hpp>
#if __BORLANDC__ > 0x551
#include <Vcl.ExtCtrls.hpp>
#endif
//---------------------------------------------------------------------------
class TListaForm : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TPanel *Panel1;
	TButton *Button3;
	TButton *Button2;
	TPanel *Panel2;
	TCheckListBox *CheckListBox1;
	TCheckListBox *CheckListBox2;
    TPanel *Panel3;
    TComboBox *ComboBox1;
    TButton *FILTRUJ;
    TPanel *Panel4;
    TSpeedButton *SpeedButton5;
    TSpeedButton *SpeedButton4;
    TSpeedButton *SpeedButton3;
    TSpeedButton *SpeedButton2;
    TSpeedButton *SpeedButton1;
    TMainMenu *MainMenu1;
    TMenuItem *Export1;
    TMenuItem *Right1;
    TMenuItem *Help1;
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TListaForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TListaForm *ListaForm;
//---------------------------------------------------------------------------
#endif
