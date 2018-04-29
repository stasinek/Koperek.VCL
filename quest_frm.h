//---------------------------------------------------------------------------
#ifndef __quest_frm_H
#define __quest_frm_H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <StdCtrls.hpp>
#include <Controls.hpp>
#include ".\..\..\PACKAGES\browsedlg.h"
#include ".\..\..\PACKAGES\advbar.h"
#include ".\..\..\PACKAGES\hintbox.h"
#include <ComCtrls.hpp>
#include "BROWSEDLG.h"
//---------------------------------------------------------------------------
class TQuestForm : public TForm
{
__published:	// IDE-managed Components
//---------------------------------------------------------------------------
        TPanel *Panel0;
        TLabel *Label5;
        TLabel *Label6;
        TBrowseDialog *BrowseDialog1;
        TPageControl *PageControl1;
        TTabSheet *TabSheet1;
        TTabSheet *TabSheet2;
        TStaticText *StaticText1;
        TEdit *Edit2;
        TStaticText *StaticText2;
        TEdit *Edit3;
        TStaticText *StaticText3;
        TComboBox *SrcListCombo;
        TStaticText *StaticText4;
        TComboBox *DstListCombo;
        TSpeedButton *SpeedButton3;
        TSpeedButton *SpeedButton4;
        TSpeedButton *SpeedButton1;
        TSpeedButton *SpeedButton2;
        TStaticText *StaticText5;
        TComboBox *ComboBox1;
        TGroupBox *GroupBox1;
        TCheckBox *CheckBox1;
        TCheckBox *CheckBox2;
        TCheckBox *CheckBox3;
        TCheckBox *CheckBox5;
        TCheckBox *CheckBox4;
        TCheckBox *CheckBox6;
        TCheckBox *CheckBox7;
	    TCheckBox *CheckBox8;
	    TPanel *Panel1;
	    TImage *Image1;
	    TImage *Image2;
	    TPanel *Panel2;
	    TButton *Button3;
	    TButton *Button1;
	    TButton *Button2;
        TPanel *Panel3;
        TPanel *Panel4;
        TSpeedButton *SpeedButton9;
        TSpeedButton *SpeedButton5;
        TSpeedButton *SpeedButton6;
        TSpeedButton *SpeedButton7;
        TSpeedButton *SpeedButton8;
        TSpeedButton *SpeedButton10;
        TSpeedButton *SpeedButton11;
    TBevel *Bevel1;
        void __fastcall Edit3Change(TObject *Sender);
        void __fastcall Edit2Change(TObject *Sender);
        void __fastcall SpeedButton1Click(TObject *Sender);
        void __fastcall SpeedButton2Click(TObject *Sender);
        void __fastcall SpeedButton4Click(TObject *Sender);
        void __fastcall SpeedButton3Click(TObject *Sender);
        void __fastcall FormDestroy(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall CheckBox1Click(TObject *Sender);
        void __fastcall CheckBox2Click(TObject *Sender);
        void __fastcall CheckBox3Click(TObject *Sender);
        void __fastcall CheckBox4Click(TObject *Sender);
        void __fastcall CheckBox5Click(TObject *Sender);
        void __fastcall ComboBox1Change(TObject *Sender);
        void __fastcall CheckBox6Click(TObject *Sender);
        void __fastcall CheckBox7Click(TObject *Sender);
    void __fastcall SpeedButton8Click(TObject *Sender);
    void __fastcall SpeedButton5Click(TObject *Sender);
    void __fastcall SpeedButton6Click(TObject *Sender);
    void __fastcall SpeedButton10Click(TObject *Sender);
    void __fastcall SpeedButton7Click(TObject *Sender);
    void __fastcall SpeedButton11Click(TObject *Sender);
    void __fastcall SpeedButton9Click(TObject *Sender);
private:	// User declarations
//---------------------------------------------------------------------------
	HINSTANCE hInst;
//---------------------------------------------------------------------------
public:		// User declarations
//---------------------------------------------------------------------------
	int __fastcall Potwierdz(bool ZEnabled,bool DEnabled);
	    __fastcall TQuestForm(TComponent* Owner);
//---------------------------------------------------------------------------
};
//---------------------------------------------------------------------------
extern PACKAGE TQuestForm *QuestForm;
//---------------------------------------------------------------------------
#endif
