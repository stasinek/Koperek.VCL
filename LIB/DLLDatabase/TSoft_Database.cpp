//---------------------------------------------------------------------------
//-----------------Stanislaw Stasiak "SSTSOFT.pl" 2001-2002------------------
//---------------------------------------------------------------------------
#include <windows.h>
#pragma hdrstop
#pragma package(smart_init)
//---------------------------------------------------------------------------
#include "TSoft_Database.h"
//---------------------------------------------------------------------------
//ASCHAR
//---------------------------------------------------------------------------
__declspec(dllexport) __stdcall TSoft::Database::Item::Item(void) : maciez()
{
data = maciez.fdata;
data_size = maciez.fdata_size;
for (long i = 0; i < 8; i++)
	 {data_size[i] = 0;
	  data[i] = NULL;
	 }
maciez.fipos = 0;
}
//---------------------------------------------------------------------------

__declspec(dllexport)  __stdcall TSoft::Database::Item::Item(char *atext, TSoft::Database *adatabase, long aipos) : maciez()
{
data = maciez.fdata;
data_size = maciez.fdata_size;
for (long i = 0; i < 8; i++)
	 {data_size[i] = 0;
	  data[i] = NULL;
	 }
 if (atext!=NULL)
	  maciez.ftext = strReDup(maciez.ftext,atext);
 if (adatabase!=NULL)
	  maciez.fnode->Mov(adatabase);
maciez.fipos = aipos;
}
//---------------------------------------------------------------------------

__declspec(dllexport)  __stdcall TSoft::Database::Item::~Item(void)
{
strFree(maciez.ftext);
}
//---------------------------------------------------------------------------

__declspec(dllexport)  void __stdcall TSoft::Database::Item::set_ipos(long aipos)
{
maciez.fipos = aipos;
}
//---------------------------------------------------------------------------

__declspec(dllexport)  void  __stdcall TSoft::Database::Item::set_text_size(long asize)
{
maciez.ftext_size = asize;
maciez.ftext = strReAlloc(maciez.ftext,maciez.ftext_size+1);
maciez.ftext[asize] = '\0';
}
//---------------------------------------------------------------------------

__declspec(dllexport)  void __stdcall TSoft::Database::Item::set_text(char *atext)
{
if (atext==NULL)
	{
	 maciez.ftext_size = 0;
	 maciez.ftext = strReAllocEx(maciez.ftext,1,"");
	}
else
	{
	 maciez.ftext_size = strLen(atext);
	 maciez.ftext = strReAllocEx(maciez.ftext, maciez.ftext_size+1, atext);
	}
}
//---------------------------------------------------------------------------

__declspec(dllexport)  void  __stdcall TSoft::Database::Item::set_node(TSoft::Database *anode)
{
if (anode==NULL)
	{
	anode->Mov(NULL); //EQL database a nie item
	}
else
	{
	anode->Mov(anode);
	}
}
//---------------------------------------------------------------------------

__declspec(dllexport)  void __stdcall TSoft::Database::Item::Mov(Item *aItems)
{
if (aItems==NULL)
	{
	for (long i = 0; i < 8; i++)
		 {maciez.fdata_size[i] = 0;
		  maciez.fdata[i] = NULL;
		 }
	set_text(NULL);
	set_node(NULL);
	}
else
	{
	for (long i = 0; i < 8; i++)
		 {maciez.fdata_size[i] = aItems->data_size[i];
		  maciez.fdata[i] = aItems->data[i];
		 }
	set_text(aItems->text);
	set_node(aItems->node);
	}
}
//---------------------------------------------------------------------------

__declspec(dllexport)  void __stdcall TSoft::Database::Item::Clr()
{
Mov(NULL);
}
//---------------------------------------------------------------------------
//DATABASE
//---------------------------------------------------------------------------

__declspec(dllexport)  __stdcall TSoft::Database::Database(void)
{
maciez.fLevel = 0;
maciez.fItems = NULL;
maciez.fCount = 0;
maciez.fAlias = strAlloc(1);
maciez.fOwner = NULL;
//
fText = strAlloc(4000);
}
//---------------------------------------------------------------------------

__declspec(dllexport)  __stdcall TSoft::Database::Database(TSoft::Database *aOwner)
{
maciez.fLevel = 0;
maciez.fItems = NULL;
maciez.fCount = 0;
maciez.fAlias = strAlloc(1);
maciez.fOwner = NULL;
if (aOwner!=NULL)
	{maciez.fOwner = aOwner;
	 maciez.fLevel = aOwner->Level+1;
	 maciez.fAlias = strReDup(maciez.fAlias,aOwner->Alias);
	}
fText = strAlloc(4000);
}
//---------------------------------------------------------------------------

__declspec(dllexport)  __stdcall TSoft::Database::Database(char *aAlias)
{
maciez.fLevel = 0;
maciez.fItems = NULL;
maciez.fCount = 0;
maciez.fAlias = strAlloc(1);
maciez.fOwner = NULL;
if (aAlias!=NULL)
	{maciez.fAlias = strReDup(maciez.fAlias,aAlias);
	}
fText = strAlloc(4000);
}
//---------------------------------------------------------------------------

__declspec(dllexport)  __stdcall TSoft::Database::~Database(void)
{
Clr();
strFree(maciez.fAlias);
strFree(fText);
}
//---------------------------------------------------------------------------

__declspec(dllexport)  void __stdcall TSoft::Database::set_Owner(TSoft::Database *aOwner)
{
maciez.fOwner = aOwner;
}
//---------------------------------------------------------------------------

__declspec(dllexport)  void __stdcall TSoft::Database::set_Alias(char *aAlias)
{
 if (aAlias==NULL)
	 {maciez.fAlias_size = 1;
	  maciez.fAlias = strReAllocEx(maciez.fAlias,1,"");
	 }
 else
	 {maciez.fAlias_size = strLen(aAlias)+1;
	  maciez.fAlias = strReAllocEx(maciez.fAlias,maciez.fAlias_size, aAlias);
	 }
for (long iT = 0; iT < Count; iT++) {

 if (maciez.fItems[iT]->node!=NULL)
	 {maciez.fItems[iT]->node->Alias = maciez.fAlias;
	 }
}
}
//---------------------------------------------------------------------------

__declspec(dllexport)  void __stdcall TSoft::Database::set_Level(long aLevel)
{
maciez.fLevel = aLevel;
//
for (long iT = 0; iT < Count; iT++) {

 if (maciez.fItems[iT]->node!=NULL)
	 {maciez.fItems[iT]->node->Level = maciez.fLevel+1;
	 }
}
}
//---------------------------------------------------------------------------

__declspec(dllexport)  TSoft::Database::Item *__stdcall TSoft::Database::get_Items(long index)
{
return maciez.fItems[index];
}
//---------------------------------------------------------------------------

__declspec(dllexport)  void __stdcall TSoft::Database::set_Items(long aindex, Item *aItems)
{
if (aItems==NULL)
	{
	 maciez.fItems[aindex]->Mov(NULL);
	}
else
	{
	 maciez.fItems[aindex]->Mov(aItems);
	}
}
//---------------------------------------------------------------------------

__declspec(dllexport)  void __stdcall TSoft::Database::set_Count(long aCount)
{
if (maciez.fCount==aCount)
	 return;
if (maciez.fItems==NULL)
	{maciez.fItems =(Item**)LocalAlloc(LPTR,aCount*sizeof(Item*));
	}
if (maciez.fCount <aCount)
	{
	 maciez.fItems =(Item**)LocalReAlloc(maciez.fItems,aCount*sizeof(Item*),LMEM_MOVEABLE);
	 for (long iT = maciez.fCount; iT < aCount; iT++)
		  {maciez.fItems[iT] = new Item();
			maciez.fItems[iT]->ipos = iT;
		  }
	 maciez.fCount =aCount;
	 return;
	}
else
	{
	 for (long iT = aCount; iT < maciez.fCount; iT++)
		  {delete maciez.fItems[iT];
		  }
	 maciez.fItems =(Item**)LocalReAlloc(maciez.fItems,aCount*sizeof(Item*),LMEM_MOVEABLE);
	 maciez.fCount =aCount;
	}
if (maciez.fCount==0 && maciez.fItems!=NULL)
	{LocalFree((void*)maciez.fItems);
	 maciez.fItems =NULL;
	}
}
//---------------------------------------------------------------------------

__declspec(dllexport)  long __stdcall TSoft::Database::Mov(TSoft::Database *aDatabase)
{
 if (aDatabase==NULL)
	 {this->Count = 0;
	  return 0;
	 }
else
	 {long  iT=0,iX =aDatabase->Count; this->Count = iX;
	  for (;iT < iX; iT++)
			{Items[iT]=aDatabase->Items[iT];
			}
	  return Count;
	 }
}
//---------------------------------------------------------------------------

__declspec(dllexport)  long __stdcall TSoft::Database::Cat(TSoft::Database *aDatabase)
{
 if (aDatabase==NULL)
	 {return Count;
	 }
else
	 {long  iT = Count, iX = iT + aDatabase->Count; this->Count = iX;
	  for (;iT < iX; iT++)
			{Items[iT]=aDatabase->Items[iT];
			}
	  return Count;
	 }
}
//---------------------------------------------------------------------------

long __stdcall TSoft::Database::Add(Item *aItems)
{
Count = Count+1; Items[Count-1] = aItems;
return  Count-1;
}
//---------------------------------------------------------------------------

__declspec(dllexport)  long __stdcall TSoft::Database::Cut(void)
{
	if (Count!=0) Count = Count-1;
return Count;
}
//---------------------------------------------------------------------------

__declspec(dllexport)  void __stdcall TSoft::Database::Insert(long aindex, Item *aItems)
{
Add(aItems);
Item *iItem = maciez.fItems[Count-1];

for (long iT = Count-1; iT > aindex; iT--) {

maciez.fItems[iT] = maciez.fItems[iT-1];
maciez.fItems[iT]->ipos = iT;
}
maciez.fItems[aindex] = iItem;
maciez.fItems[aindex]->ipos = aindex;
}
//---------------------------------------------------------------------------

__declspec(dllexport)  void __stdcall TSoft::Database::Delete(long aindex)
{
Item *dItem = maciez.fItems[aindex];

for (long iT = aindex; iT < Count-1; iT++) {

maciez.fItems[iT] = maciez.fItems[iT+1];
maciez.fItems[iT]->ipos = iT;
}
maciez.fItems[Count-1] = dItem;
maciez.fItems[Count-1]->ipos = Count-1;
Cut();
}
//---------------------------------------------------------------------------

void __stdcall TSoft::Database::Clr()
{
Count = 0;
}
//---------------------------------------------------------------------------

__declspec(dllexport)  long __stdcall TSoft::Database::Find(long aistart, char *aChar)
{
for (long iT = aistart; iT < Count; iT++) {
 if (strcmp(maciez.fItems[iT]->text,aChar)==0)
	 {return iT;
	 }
}
return -1;
}
//---------------------------------------------------------------------------

__declspec(dllexport)  void __stdcall TSoft::Database::Exchange(long aindex1, long aindex2)
{
		Item *eItem = maciez.fItems[aindex1];
maciez.fItems[aindex1] = maciez.fItems[aindex2];
maciez.fItems[aindex1]->ipos = aindex1;
maciez.fItems[aindex2] = eItem;
maciez.fItems[aindex2]->ipos = aindex2;
}
//---------------------------------------------------------------------------

__declspec(dllexport)  void __stdcall TSoft::Database::Sort()
{
for (long index1 = 0; index1 < Count; index1++)
for (long index2 = index1 + 1; index2 < Count; index2++) {
 if (strcmp(maciez.fItems[index1]->text,maciez.fItems[index2]->text) > 0)
	 {Exchange(index1, index2);
	 }
}
}
//---------------------------------------------------------------------------

__declspec(dllexport)  char *__stdcall TSoft::Database::get_Text(long aFormat)
{
strFree(fText);
return TEXT_FROM_DATA(&fText,this,aFormat);
}
//---------------------------------------------------------------------------

__declspec(dllexport)  void  __stdcall TSoft::Database::set_Text(long aFormat,char *aText)
{
DATA_FROM_TEXT(this,aText,aFormat);
}
//---------------------------------------------------------------------------

__declspec(dllexport)  bool __stdcall TSoft::Database::Read(void) {
HANDLE FHand = CreateFile(this->Alias,GENERIC_READ,FILE_SHARE_READ,NULL,OPEN_ALWAYS,FILE_ATTRIBUTE_NORMAL,NULL);
char emsg[256];
if (FHand==INVALID_HANDLE_VALUE) {
return MessageBox(NULL,strAdd(strAdd(strMov(emsg,"Invalid file or path not exists '"),maciez.fAlias),"'"),
						"TSoft::Database read error",
						MB_OK|MB_ICONERROR);
}
unsigned long size = GetFileSize(FHand,NULL);
unsigned long hread;
char *lptemp = strAlloc(size);
ReadFile(FHand,lptemp,size,&hread,NULL);
this->Text[LINES] = lptemp;
strFree(lptemp);
CloseHandle(FHand);
return TRUE;
}
//---------------------------------------------------------------------------

__declspec(dllexport)  bool __stdcall TSoft::Database::Save(void) {
HANDLE FHand = CreateFile(this->Alias,GENERIC_WRITE,FILE_SHARE_WRITE,NULL,CREATE_ALWAYS,FILE_ATTRIBUTE_NORMAL,NULL);
char emsg[256];
if (FHand==INVALID_HANDLE_VALUE) {
return MessageBox(NULL,strAdd(strAdd(strMov(emsg,"Invalid file or path not exists '"),this->Alias),"'"),
						"TSoft::Database Save error",
						MB_OK|MB_ICONERROR);
}
char *lptemp = this->Text[LINES];
unsigned long size = strLen(lptemp);
unsigned long hread;
WriteFile(FHand,lptemp,size,&hread,NULL);
CloseHandle(FHand);
return TRUE;
}
//---------------------------------------------------------------------------
//DODATKOWE FUNKCJE
//---------------------------------------------------------------------------

__declspec(dllexport)  TSoft::Database::Item *__stdcall ASCHAR(char *atext)
{
#pragma warning "This wont work for multithread! Won't fix it OLD.lib is OBSOLETE"
static TSoft::Database::Item xPARAM;
xPARAM.text = atext;
return &xPARAM;
}
//---------------------------------------------------------------------------

__declspec(dllexport)  char *__stdcall TEXT_FROM_DATA(char **aText, TSoft::Database *aDatabase, long aformat) {
char *text = strAlloc(1);

 if (aDatabase->Count==0) strMov(text,"");
else
 if (aformat==COMMA) {
for (long tpos = 0, tlen = 1, srclen, iT = 0; ;)
	 {
	  srclen = strLen(aDatabase->Items[iT]->text);
	  if (tpos+1+srclen+3+1 >= tlen)
		  {text = strReAlloc(text,tlen = tpos+srclen+256);
		  }
	  ptrMov((char*)((long)text+tpos), "\"", 1);
	  tpos += 1;
	  ptrMov((char*)((long)text+tpos), aDatabase->Items[iT]->text, srclen);
	  tpos += srclen;
	  ptrMov((char*)((long)text+tpos), "\", ", 3);
	  tpos += 3;
	  if (++iT>=aDatabase->Count) // ucinam 2
		  {
			text[tpos-2] = '\0';
			text = strReAlloc(text, tpos);
			break;
		  }
	 }
}
else
 if (aformat==LINES) {
for (long tpos = 0, tlen = 1, srclen, iT = 0; ;)
	 {
	  srclen = strLen(aDatabase->Items[iT]->text);
	  if (tpos+srclen+2+1 >= tlen)
		  {text = strReAlloc(text,tlen = tpos+srclen+256);
		  }
	  ptrMov((char*)((long)text+tpos), aDatabase->Items[iT]->text, srclen);
	  tpos += srclen;
	  ptrMov((char*)((long)text+tpos), "\r\n", 2);
	  tpos += 2;
	  if (++iT>=aDatabase->Count) // ucinam 2
		  {text[tpos-2] = '\0';
			text = strReAlloc(text, tpos);
			break;
		  }
	 }
}
	   *aText = text;
return *aText;
}
//---------------------------------------------------------------------------

__declspec(dllexport)  TSoft::Database *__stdcall DATA_FROM_TEXT(TSoft::Database *aData, char *aText, long aformat) {
long pos, pos_chk, pos_end = strLen(aText);
long sep, tpos, tpos_end = 256;
char *tText = strAlloc(256);

aData->Count = 0;

 if (aformat==COMMA) {
for (pos = 0; pos < pos_end; pos += sep)
	 {
	  for (; pos < pos_end && aText[pos]==' '; pos++);
	  pos += (long)(aText[pos]==',');
	  for (; pos < pos_end && aText[pos]==' '; pos++);
	  sep  = (long)(aText[pos]=='\"');
	  pos += sep;

	  for (tpos = 0; pos < pos_end;)
			{
			if (sep==0)
				{
				if (aText[pos+0]==',' || aText[pos+0]==' ')
					{break;
					}
				}
			else
				{
				if (aText[pos+0]=='\"')
				if (aText[pos+1]=='\"') pos++;
				else
					 break;
				}
			if (tpos +1 >= tpos_end)
				{tText = strReAlloc(tText, tpos_end+=256);
				}
			tText[tpos++] = aText[pos++];
			}
	  tText[tpos] = '\0';
	  aData->Add(ASCHAR(tText));
	 }
strFree(tText);
}
else
 if (aformat==LINES) {
for (pos = 0; pos < pos_end; pos = pos_chk)
	 {
	  for (pos_chk = pos; pos_chk < pos_end; pos_chk++)
		if (aText[pos_chk]=='\r' || aText[pos_chk]=='\n')
			{break;
			}

		if (pos_chk-pos+1 >= tpos_end)
			{tText = strReAlloc(tText, tpos_end+=256);
			}
	  ptrMov(tText, (char*)((long)aText + pos), pos_chk - pos);
	  tText[pos_chk - pos] = '\0';
	  aData->Add(ASCHAR(tText));

	  if (pos_chk==pos_end)
		  {break;
		  }
	  if (aText[pos_chk]=='\r')
		  {pos_chk++;
		  }
	  if (aText[pos_chk]=='\n')
		  {pos_chk++;
		  }

	 }
 if (pos_end!=0)
	 {
	 if (aText[pos_end-1]=='\n')
		 {aData->Add(ASCHAR(""));
		  pos_end++;
		 }
	 if (aText[pos_end-1]=='\r')
		 {aData->Add(ASCHAR(""));
		 }
	 }
strFree(tText);
}
return aData;
}
//---------------------------------------------------------------------------