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
#include "..\Packages\exeres.h"
//----------------------------------------------------------------------------
class THasloForm : public TForm
{
__published:
//----------------------------------------------------------------------------
	TLabel *Label1;
	TLabel *Label2;
	TButton *OKBtn;
	TButton *CancelBtn;
	TEdit *Password1;
	TEdit *Password2;
//----------------------------------------------------------------------------
	TLabel *Label3;
	TImage *Image1;
	TExeResource *ExeResource1;
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
