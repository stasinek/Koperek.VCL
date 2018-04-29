//----------------------------------------------------------------------------
#ifndef haslo_frm_H
#define haslo_frm_H
//----------------------------------------------------------------------------
#include <Buttons.hpp>
#include <StdCtrls.hpp>
#include <Controls.hpp>
#include <Forms.hpp>
#include <Graphics.hpp>
#include <Classes.hpp>
#include <SysUtils.hpp>
#include <Windows.hpp>
#include <System.hpp>
#include <ExtCtrls.hpp>
#include ".\..\..\PACKAGES\EXERES.H"
//----------------------------------------------------------------------------
class THasloForm : public TForm
{
__published:
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
	TExeResource *ExeResource1;
    TPanel *Panel1;
    TButton *OKBtn;
    TButton *CancelBtn;
    TLabel *Label4;
    TPanel *Panel4;
    TBevel *Bevel1;
    TPanel *Panel5;
    TPanel *Panel2;
    TLabel *Label1;
    TLabel *Label2;
    TEdit *Password1;
    TEdit *Password2;
    TPanel *Panel3;
    TLabel *Label3;
    TImage *Image1;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall Password2Change(TObject *Sender);
	void __fastcall Password1Change(TObject *Sender);
	void __fastcall OKBtnClick(TObject *Sender);
//----------------------------------------------------------------------------
	
	void __fastcall FormCreate(TObject *Sender);
private:
//----------------------------------------------------------------------------
	HINSTANCE hInst;
//----------------------------------------------------------------------------
public:
//----------------------------------------------------------------------------
	virtual __fastcall THasloForm(TComponent* AOwner);
//----------------------------------------------------------------------------
};
//----------------------------------------------------------------------------
extern PACKAGE THasloForm *HasloForm;
//----------------------------------------------------------------------------
#endif
