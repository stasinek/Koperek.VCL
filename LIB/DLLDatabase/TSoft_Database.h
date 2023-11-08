//---------------------------------------------------------------------------
//-------- COPYRIGHT: Stanislaw Stasiak "SSTSOFT.pl" @2001-2002 -------------
//-------- https://github.com/stasinek/Koperek.VCL --------------------------
//---------------------------------------------------------------------------
#ifndef __TSoft_Database_h__
#define __TSoft_Database_h__
//---------------------------------------------------------------------------
#include "./../DLLIO/TSoft_IO.h"
#include "TSoft_build_conf.h"
//---------------------------------------------------------------------------
#define COMMA  1
#define LINES  2
//---------------------------------------------------------------------------
namespace TSoft {
class DATABASE_IMPEXP Database
{
//---------------------------------------------------------------------------
public:
//---------------------------------------------------------------------------
typedef class DATABASE_IMPEXP Item {
	//------------------------------------
	protected:
	//------------------------------------
	struct __maciez {
		Database::Item *fOwner, *fChild;

		TSoft::Database *fnode;
		long  fipos;
		long  fdata_size[8];
		void *fdata[8];
		long  ftext_size;
		char *ftext;

        __stdcall  __maciez() : fnode(NULL), ftext(NULL), ftext_size(0) { ftext = strAlloc(1); fnode = new TSoft::Database; }
        __stdcall ~__maciez() { if (fnode) delete fnode; if (ftext) strFree(ftext);  }
	} maciez;
	//------------------------------------
    private:
	void  __stdcall set_node	  (TSoft::Database *anode);
	TSoft::Database *__stdcall get_node	(void) {return maciez.fnode;}
	void  __stdcall set_ipos	  (long  aipos);
	long  __stdcall get_ipos	  (void) {return maciez.fipos;}
	void  __stdcall set_text_size(long  asize);
	long  __stdcall get_text_size(void) {return maciez.ftext_size;}
	void  __stdcall set_text	  (char *atext);
	char *__stdcall get_text	  (void) {return maciez.ftext;}
	//------------------------------------
	public:
	//------------------------------------
		  __stdcall  Item	(void);
		  __stdcall  Item	(char *atext, TSoft::Database *adatabase, long aipos);
virtual   __stdcall ~Item	(void);
	//------------------------------------
	void __stdcall Mov	(Database::Item *aItems);
	void __stdcall Clr	(void);
	//------------------------------------
	__declspec(property(get=get_node, put=set_node)) TSoft::Database *node;
	__declspec(property(get=get_ipos, put=set_ipos)) long ipos;
	__declspec(property(get=get_text_size, put=set_text_size)) long text_size;
	__declspec(property(get=get_text, put=set_text)) char *text;
	//------------------------------------
	long  *data_size;
	void **data;
	//------------------------------------
} Item, *lpItem;
//------------------------------------
private:
//------------------------------------
char *fText;
struct __maciez {
	TSoft::Database *fOwner, *fChild;
	long  fLevel;
	long  fAlias_size;
	char *fAlias;
	long  fCount;
	Database::Item **fItems;
} maciez;
//------------------------------------
TSoft::Database *__stdcall  get_Owner(void) {return maciez.fOwner;}
void  __stdcall set_Owner	(TSoft::Database *aOwner);
char *__stdcall get_Alias	() {return maciez.fAlias;}
void  __stdcall set_Alias	(char *aAlias);
long  __stdcall get_Level	() {return maciez.fLevel;}
void  __stdcall set_Level	(long  aLevel);
long  __stdcall get_Count	() {return maciez.fCount;}
void  __stdcall set_Count	(long  aCount);
Database::Item * __stdcall get_Items(long  aindex);
void  __stdcall set_Items	(long  aindex, Database::Item *aItems);
char *__stdcall get_Text	(long  aFormat);
void  __stdcall set_Text	(long  aFormat,char *aText);
//------------------------------------
public:
//------------------------------------
 	 __stdcall  Database(void);
 	 __stdcall  Database(char *aAlias);
 	 __stdcall  Database(TSoft::Database *aOwner);
 	 __stdcall ~Database(void);
//------------------------------------
 long __stdcall Mov	  	(TSoft::Database *aDatabase);
 long __stdcall Cat	  	(TSoft::Database *aDatabase);
 long __stdcall Cut	  	(void);
 void __stdcall Clr	  	(void);
//------------------------------------
 long __stdcall Add	  	(Database::Item *aItems);
 void __stdcall Insert	(long aindex, Database::Item *aItems);
 void __stdcall Exchange (long aindex1, long aindex2);
 void __stdcall Delete	(long aindex);
 long __stdcall Find	 	(long aistart, char *aChar);
 void __stdcall Sort	 	();
//------------------------------------
 bool __stdcall Read	 	(void);
 bool __stdcall Save	 	(void);
//------------------------------------
__declspec(property(get=get_Owner,put=set_Owner)) TSoft::Database *Owner;
__declspec(property(get=get_Level,put=set_Level)) long             Level;
__declspec(property(get=get_Alias,put=set_Alias)) char            *Alias;
__declspec(property(get=get_Count,put=set_Count)) long             Count;
__declspec(property(get=get_Items,put=set_Items)) Database::Item  *Items[];
//---------------------------------------------------------------------------
// Text it's serialization element, can set or get database as list or CSV depending index (format)
//---------------------------------------------------------------------------
__declspec(property(get=get_Text, put=set_Text))  char            *Text[];
//---------------------------------------------------------------------------
};
//---------------------------------------------------------------------------
}
extern "C" DATABASE_IMPEXP TSoft::Database *__stdcall DATA_FROM_TEXT(TSoft::Database *aDatabase, char *aText, long aformat);
extern "C" DATABASE_IMPEXP char *__stdcall TEXT_FROM_DATA(char **aText, TSoft::Database *aDatabase, long aformat);
extern "C" DATABASE_IMPEXP TSoft::Database::Item *__stdcall ASCHAR(char *atext);
//---------------------------------------------------------------------------
#endif

