//---------------------------------------------------------------------------

#ifndef Lista_frmH
#define Lista_frmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <CheckLst.hpp>
#include <FileCtrl.hpp>
#include <Grids.hpp>
#include <ValEdit.hpp>
//---------------------------------------------------------------------------
class TListaForm : public TForm
{
__published:	// IDE-managed Components
	TCheckListBox *CheckListBox1;
	TFilterComboBox *FilterComboBox1;
	TButton *FILTRUJ;
	TButton *Button2;
	TButton *Button3;
	TLabel *Label1;
	TGroupBox *GroupBox1;
	TCheckListBox *CheckListBox2;
	TValueListEditor *ValueListEditor1;
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
