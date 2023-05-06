//---------------------------------------------------------------------------
#ifndef __Infos_frm_H
#define __Infos_frm_H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
#include ".\..\..\PACKAGES\exeres.h"
#include "EXERES.h"
//---------------------------------------------------------------------------
class TInfos_form : public TForm
{
//---------------------------------------------------------------------------
__published:	// IDE-managed Components
//---------------------------------------------------------------------------
	TExeResource *ExeResource1;
	TStatusBar *StatusBar1;
    TPanel *Panel1;
    TButton *Tak;
    TButton *Ignore;
    TButton *Nie;
    TButton *NoToAll;
    TPanel *Panel3;
    TPanel *Panel2;
    TImage *Image3;
    TBevel *Bevel1;
    TPanel *Panel5;
    TCheckBox *CheckBox1;
    TPanel *Panel4;
    TLabel *Label0;
    TBevel *Bevel2;
    TPanel *Panel6;
    TStaticText *StaticText1;
    TImage *Image1;
    TLabel *Label1;
    TSpeedButton *SpeedButton1;
    TBevel *Bevel3;
    TPanel *Panel7;
    TStaticText *StaticText2;
    TImage *Image2;
    TLabel *Label2;
    TSpeedButton *SpeedButton2;
    TBevel *Bevel4;
	TButton *Button1;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall FormHide(TObject *Sender);
//---------------------------------------------------------------------------



	void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
//---------------------------------------------------------------------------
    int time;
	HINSTANCE hInst;
//---------------------------------------------------------------------------
public:		// User declarations
//---------------------------------------------------------------------------
	int __fastcall ZastopInfo(AnsiString DocelKPNazwa,AnsiString ZrodlKPNazwa);
	    __fastcall TInfos_form(TComponent* Owner);
//---------------------------------------------------------------------------
};
//---------------------------------------------------------------------------
extern PACKAGE TInfos_form *Infos_form;
//---------------------------------------------------------------------------
#endif
