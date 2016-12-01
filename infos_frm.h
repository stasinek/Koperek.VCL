//---------------------------------------------------------------------------
#ifndef Infos_frm_H
#define Infos_frm_H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include "..\Packages\exeres.h"
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TInfosForm : public TForm
{
//---------------------------------------------------------------------------
__published:	// IDE-managed Components
//---------------------------------------------------------------------------
	TButton *Tak;
	TButton *TakToAll;
	TButton *Nie;
	TButton *NoToAll;
	TImage *Image1;
	TImage *Image2;
    TLabel *Label0;
	TLabel *Label1;
	TLabel *Label2;
	TStaticText *StaticText1;
	TStaticText *StaticText2;
	TExeResource *ExeResource1;
	TStatusBar *StatusBar1;
	TPanel *Panel1;
	TButton *Button1;
	TLabel *Label3;
	TPanel *Panel2;
	TImage *Image3;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall FormHide(TObject *Sender);
//---------------------------------------------------------------------------



	void __fastcall FormCreate(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
//---------------------------------------------------------------------------
    int time;
	HINSTANCE hInst;
//---------------------------------------------------------------------------
public:		// User declarations
//---------------------------------------------------------------------------
	int __fastcall ZastopInfo(String DocelKPNazwa,String ZrodlKPNazwa);
	    __fastcall TInfosForm(TComponent* Owner);
//---------------------------------------------------------------------------
};
//---------------------------------------------------------------------------
extern PACKAGE TInfosForm *InfosForm;
//---------------------------------------------------------------------------
#endif
