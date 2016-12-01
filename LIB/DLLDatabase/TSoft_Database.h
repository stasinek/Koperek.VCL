//---------------------------------------------------------------------------
//-----------------Stanislaw Stasiak "TSoft_, where?" 2001-2002---------------
//---------------------------------------------------------------------------
#ifndef __TSoft_Database_HDR__
#define __TSoft_Database_HDR__
//---------------------------------------------------------------------------
#include "..\DLLIO\TSoft_IO.h"
//---------------------------------------------------------------------------
#define COMMA  1
#define LINES  2
//---------------------------------------------------------------------------
extern "C" {
//---------------------------------------------------------------------------
class __declspec(dllexport) TSoft_Database
{
//---------------------------------------------------------------------------
public:
//---------------------------------------------------------------------------
typedef class __declspec(dllexport) TSoft_Item {
	//------------------------------------
	protected:
	//------------------------------------
	struct __maciez {
		TSoft_Item *fOwner, *fChild;
		TSoft_Database *fnode;
		long  fipos;
		long  fdata_size[8];
		void *fdata[8];
		long  ftext_size;
		char *ftext;
	} maciez;
	//------------------------------------
	public:
	//------------------------------------
	      __stdcall  TSoft_Item	(void);
	      __stdcall  TSoft_Item	(char *atext, TSoft_Database *adatabase, long aipos);
	//------------------------------------
	void  __stdcall set_node	  (TSoft_Database *anode);
	TSoft_Database *__stdcall get_node	(void) {return maciez.fnode;}
	void  __stdcall set_ipos	  (long  aipos);
	long  __stdcall get_ipos	  (void) {return maciez.fipos;}
	void  __stdcall set_text_size(long  asize);
	long  __stdcall get_text_size(void) {return maciez.ftext_size;}
	void  __stdcall set_text	  (char *atext);
	char *__stdcall get_text	  (void) {return maciez.ftext;}
	//------------------------------------
	__declspec(property(get=get_ipos, put=set_ipos)) long ipos;
	__declspec(property(get=get_node, put=set_node)) TSoft_Database *node;
	__declspec(property(get=get_text_size, put=set_text_size)) long text_size;
	__declspec(property(get=get_text, put=set_text)) char *text;
	//------------------------------------
	long  *data_size;
	void **data;
	//------------------------------------
	void __stdcall Eql	(TSoft_Item *aItems);
	void __stdcall Clr	(void);
	//------------------------------------
	     __stdcall ~TSoft_Item	(void);
	//------------------------------------
} TSoft_Item, *lpTSoft_Item;
//---------------------------------------------------------------------------
private:
//---------------------------------------------------------------------------
char *fText;
struct __maciez {
	TSoft_Database *fOwner, *fChild;
	char *fAlias;
	long  fAlias_size;
	long  fLevel;
	TSoft_Item **fItems;
	long  fCount;
} maciez;
//---------------------------------------------------------------------------
public:
//---------------------------------------------------------------------------
     __stdcall TSoft_Database(void);
     __stdcall TSoft_Database(char *aAlias);
     __stdcall TSoft_Database(TSoft_Database *aOwner);
//------------------------------------
long __stdcall Eql	  	(TSoft_Database *aDatabase);
long __stdcall Cat	  	(TSoft_Database *aDatabase);
long __stdcall Cut	  	(void);
void __stdcall Clr	  	(void);
//------------------------------------
long __stdcall Add	  	(TSoft_Item *aItemse);
void __stdcall Insert	(long aindex, TSoft_Item *aItems);
void __stdcall Delete	(long aindex);
void __stdcall Exchange (long aindex1, long aindex2);
void __stdcall Sort	 	();
long __stdcall Find	 	(long aistart, char *aChar);
//------------------------------------
bool __stdcall Read	 	(void);
bool __stdcall Post	 	(void);
//------------------------------------
TSoft_Database *__stdcall get_Owner(void) {return maciez.fOwner;}
void  __stdcall set_Owner	(TSoft_Database *aOwner);
char *__stdcall get_Alias	() {return maciez.fAlias;}
void  __stdcall set_Alias	(char *aAlias);
long  __stdcall get_Level	() {return maciez.fLevel;}
void  __stdcall set_Level	(long  aLevel);
long  __stdcall get_Count	() {return maciez.fCount;}
void  __stdcall set_Count	(long  aCount);
TSoft_Item * __stdcall get_Items(long  aindex);
void  __stdcall set_Items	(long  aindex, TSoft_Item *aItems);
char *__stdcall get_Text	(long  aFormat);
void  __stdcall set_Text	(long  aFormat,char *aText);
//------------------------------------
__declspec(property(get=get_Owner,put=set_Owner)) TSoft_Database *Owner;
__declspec(property(get=get_Alias,put=set_Alias)) char *Alias;
__declspec(property(get=get_Level,put=set_Level)) long  Level;
__declspec(property(get=get_Count,put=set_Count)) long  Count;
__declspec(property(get=get_Items,put=set_Items)) TSoft_Item *Items[];
__declspec(property(get=get_Text,put=set_Text))	char *Text[];
//------------------------------------
      __stdcall ~TSoft_Database(void);
//---------------------------------------------------------------------------
};
//---------------------------------------------------------------------------
TSoft_Database __declspec(dllexport) *__stdcall DATA_FROM_TEXT(TSoft_Database *aDatabase, char *aText, long aformat);
char __declspec(dllexport) *__stdcall TEXT_FROM_DATA(char **aText, TSoft_Database *aDatabase, long aformat);
TSoft_Database::TSoft_Item __declspec(dllexport) *__stdcall ASCHAR(char *atext);
//---------------------------------------------------------------------------
}
//---------------------------------------------------------------------------
#endif

