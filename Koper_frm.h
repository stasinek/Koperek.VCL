//---------------------------------------------------------------------------
#ifndef Koper_frm_H
#define Koper_frm_H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <mmsystem.h>
#include "..\Packages\advbar.h"
#include <Buttons.hpp>
#include "systray.h"
//---------------------------------------------------------------------------
class TKoperForm : public TForm
{
__published:	// IDE-managed Components
//----------------------------------------------------------------------------
	TTimer *Timer1;
        TAdvancedBar *AdvancedBar2;
        TSpeedButton *SpeedButton1;
        TSpeedButton *SpeedButton2;
	TSysTray *SysTray1;
	TSpeedButton *SpeedButton3;
	TBevel *Bevel1;
	TSpeedButton *SpeedButton4;
	TPanel *Panel1;
	TAdvancedBar *AdvancedBar5;
	TAdvancedBar *AdvancedBar6;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TAdvancedBar *AdvancedBar4;
	TLabel *Label4;
	TLabel *Label5;
	TBevel *Bevel2;
	TAdvancedBar *AdvancedBar3;
	TBevel *Bevel3;
	TBevel *Bevel4;
	TBevel *Bevel5;
        void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall Timer1Timer(TObject *Sender);
        void __fastcall SpeedButton1Click(TObject *Sender);
        void __fastcall SpeedButton2Click(TObject *Sender);
	void __fastcall SpeedButton3Click(TObject *Sender);
	void __fastcall SpeedButton4Click(TObject *Sender);
	void __fastcall FormDestroy(TObject *Sender);
//----------------------------------------------------------------------------
private:	// User declarations
//----------------------------------------------------------------------------
	HINSTANCE hApp;
//----------------------------------------------------------------------------
public:		// User declarations
//----------------------------------------------------------------------------
	__fastcall TKoperForm(TComponent* Owner);
//----------------------------------------------------------------------------
char *__stdcall GetBajtText (__int64 liczbaDoDzielenia);
int   __stdcall DoBreak(__int32 BreakCode,__int32 BreakButton);
int   __stdcall DoError(__int32 ErrorCode,__int32 ErrorButton);
double OldCzas, MineloCzas, ZostaloCzas, MineloBajt, ZostaloBajt, MineloCzasTik, MineloCzasTikOld;
double MineloBajtTik, MineloBajtTikOld;
double MineloCzasJournal;
int BreakCodeJournal, BreakButtonJournal;
bool Pauza;
char *lpcaption,*temp0,*temp1,*temp2,*temp3,*temp4;
char *buffer1, *buffer2, *buffer3, *buffer4;

//----------------------------------------------------------------------------
};
//---------------------------------------------------------------------------
extern PACKAGE TKoperForm *KoperForm;
//---------------------------------------------------------------------------
#endif
