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
#include ".\..\..\PACKAGES\advbar.h"
#include <Buttons.hpp>
#include ".\..\..\PACKAGES\systray.h"
#include "ADVBAR.h"
#include "SYSTRAY.h"
//---------------------------------------------------------------------------
class TKoper_form : public TForm
{
__published:	// IDE-managed Components
//----------------------------------------------------------------------------
	TTimer *Timer1;
    TPanel *Panel2;
    TSpeedButton *SpeedButton4;
    TSpeedButton *SpeedButton3;
    TSpeedButton *SpeedButton1;
    TSpeedButton *SpeedButton2;
    TPanel *Panel3;
    TPanel *Panel1;
    TPanel *Panel4;
    TLabel *Label1;
    TLabel *Label2;
    TLabel *Label3;
    TLabel *Label4;
    TLabel *Label5;
    TBevel *Bevel2;
    TBevel *Bevel3;
    TBevel *Bevel4;
    TBevel *Bevel5;
    TBevel *Bevel1;
    TSpeedButton *SpeedButton5;
    TBevel *Bevel6;
    TBevel *Bevel7;
    TSysTray *SysTray1;
    TAdvancedBar *AdvancedBar1;
    TAdvancedBar *AdvancedBar2;
    TAdvancedBar *AdvancedBar3;
    TAdvancedBar *AdvancedBar4;
    TAdvancedBar *AdvancedBar5;
    TAdvancedBar *AdvancedBar6;
        void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall Timer1Timer(TObject *Sender);
        void __fastcall SpeedButton1Click(TObject *Sender);
        void __fastcall SpeedButton2Click(TObject *Sender);
	void __fastcall SpeedButton4Click(TObject *Sender);
	void __fastcall FormDestroy(TObject *Sender);
    void __fastcall SpeedButton5Click(TObject *Sender);
//----------------------------------------------------------------------------
private:	// User declarations
//----------------------------------------------------------------------------
	HINSTANCE hApp;
//----------------------------------------------------------------------------
public:		// User declarations
//----------------------------------------------------------------------------
	__fastcall TKoper_form(TComponent* Owner);
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
extern PACKAGE TKoper_form *Koper_form;
//---------------------------------------------------------------------------
#endif
