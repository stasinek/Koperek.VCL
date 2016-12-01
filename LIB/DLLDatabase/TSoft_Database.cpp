//---------------------------------------------------------------------------
//-----------------Stanislaw Stasiak "TSoft_, where?" 2001-2002---------------
//---------------------------------------------------------------------------
#include <windows.h>
#include "TSoft_Database.h"
//---------------------------------------------------------------------------
//ASCHAR
//---------------------------------------------------------------------------
__stdcall TSoft_Database::TSoft_Item::TSoft_Item(void)
{
maciez.ftext = strAlloc(1);
maciez.fnode = new TSoft_Database();
data = maciez.fdata;										
data_size = maciez.fdata_size;
for (long i = 0; i < 8; i++)
	 {data_size[i] = 0;
	  data[i] = NULL;
	 }
maciez.fipos = 0;
}
//---------------------------------------------------------------------------

__stdcall TSoft_Database::TSoft_Item::TSoft_Item(char *atext, TSoft_Database *adatabase, long aipos)
{
maciez.ftext = strAlloc(1);
maciez.fnode = new TSoft_Database();
data = maciez.fdata;
data_size = maciez.fdata_size;
for (long i = 0; i < 8; i++)
	 {data_size[i] = 0;
	  data[i] = NULL;
	 }
 if (atext!=NULL)
	  maciez.ftext = strReDup(maciez.ftext,atext);
 if (adatabase!=NULL)
	  maciez.fnode->Eql(adatabase);
maciez.fipos = aipos;
}
//---------------------------------------------------------------------------

__stdcall TSoft_Database::TSoft_Item::~TSoft_Item(void)
{
delete maciez.fnode; strFree(maciez.ftext);
}
//---------------------------------------------------------------------------

void __stdcall TSoft_Database::TSoft_Item::set_ipos(long aipos)
{
maciez.fipos = aipos;
}
//---------------------------------------------------------------------------

void  __stdcall TSoft_Database::TSoft_Item::set_text_size(long asize)
{
maciez.ftext_size = asize;
maciez.ftext = strReAlloc(maciez.ftext,maciez.ftext_size+1);
maciez.ftext[asize] = '\0';
}
//---------------------------------------------------------------------------

void __stdcall TSoft_Database::TSoft_Item::set_text(char *atext)
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

void  __stdcall TSoft_Database::TSoft_Item::set_node(TSoft_Database *anode)
{
if (anode==NULL)
	{
	anode->Eql(NULL); //EQL database a nie item
	}
else
	{
	anode->Eql(anode);
	}
}
//---------------------------------------------------------------------------

void __stdcall TSoft_Database::TSoft_Item::Eql(TSoft_Item *aItems)
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

void __stdcall TSoft_Database::TSoft_Item::Clr()
{
Eql(NULL);
}
//---------------------------------------------------------------------------
//DATABASE
//---------------------------------------------------------------------------

__stdcall TSoft_Database::TSoft_Database(void)
{
maciez.fLevel = 0;
maciez.fItems = NULL;
maciez.fCount = 0;
maciez.fAlias = strAlloc(1);
maciez.fOwner = NULL;
//
fText = strAlloc(1);
}
//---------------------------------------------------------------------------

__stdcall TSoft_Database::TSoft_Database(TSoft_Database *aOwner)
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
fText = strAlloc(1);
}
//---------------------------------------------------------------------------

__stdcall TSoft_Database::TSoft_Database(char *aAlias)
{
maciez.fLevel = 0;
maciez.fItems = NULL;
maciez.fCount = 0;
maciez.fAlias = strAlloc(1);
maciez.fOwner = NULL;
if (aAlias!=NULL)
	{maciez.fAlias = strReDup(maciez.fAlias,aAlias);
	}
fText = strAlloc(1);
}
//---------------------------------------------------------------------------

__stdcall TSoft_Database::~TSoft_Database(void)
{
Clr();
strFree(maciez.fAlias);
strFree(fText);
}
//---------------------------------------------------------------------------

void __stdcall TSoft_Database::set_Owner(TSoft_Database *aOwner)
{
maciez.fOwner = aOwner;
}
//---------------------------------------------------------------------------

void __stdcall TSoft_Database::set_Alias(char *aAlias)
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

void __stdcall TSoft_Database::set_Level(long aLevel)
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

TSoft_Database::TSoft_Item *__stdcall TSoft_Database::get_Items(long index)
{
return maciez.fItems[index];
}
//---------------------------------------------------------------------------

void __stdcall TSoft_Database::set_Items(long aindex, TSoft_Item *aItems)
{
if (aItems==NULL)
	{
	 maciez.fItems[aindex]->Eql(NULL);
	}
else
	{
	 maciez.fItems[aindex]->Eql(aItems);
	}
}
//---------------------------------------------------------------------------

void __stdcall TSoft_Database::set_Count(long aCount)
{
if (maciez.fCount==aCount)
	 return;
if (maciez.fItems==NULL)
	{maciez.fItems =(TSoft_Item**)LocalAlloc(LPTR,aCount*sizeof(TSoft_Item*));
	}
if (maciez.fCount <aCount)
	{
	 maciez.fItems =(TSoft_Item**)LocalReAlloc(maciez.fItems,aCount*sizeof(TSoft_Item*),LMEM_MOVEABLE);
	 for (long iT = maciez.fCount; iT < aCount; iT++)
		  {maciez.fItems[iT] = new TSoft_Item();
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
	 maciez.fItems =(TSoft_Item**)LocalReAlloc(maciez.fItems,aCount*sizeof(TSoft_Item*),LMEM_MOVEABLE);
	 maciez.fCount =aCount;
	}
if (maciez.fCount==0 && maciez.fItems!=NULL)
	{LocalFree((void*)maciez.fItems);
	 maciez.fItems =NULL;
	}
}
//---------------------------------------------------------------------------

long __stdcall TSoft_Database::Eql(TSoft_Database *aDatabase)
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

long __stdcall TSoft_Database::Cat(TSoft_Database *aDatabase)
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

long __stdcall TSoft_Database::Add(TSoft_Item *aItems)
{
Count = Count+1; Items[Count-1] = aItems;
return  Count-1;
}
//---------------------------------------------------------------------------

long __stdcall TSoft_Database::Cut(void)
{
	if (Count!=0) Count = Count-1;
return Count;
}
//---------------------------------------------------------------------------

void __stdcall TSoft_Database::Insert(long aindex, TSoft_Item *aItems)
{
Add(aItems);
TSoft_Item *iItem = maciez.fItems[Count-1];

for (long iT = Count-1; iT > aindex; iT--) {

maciez.fItems[iT] = maciez.fItems[iT-1];
maciez.fItems[iT]->ipos = iT;
}
maciez.fItems[aindex] = iItem;
maciez.fItems[aindex]->ipos = aindex;
}
//---------------------------------------------------------------------------

void __stdcall TSoft_Database::Delete(long aindex)
{
TSoft_Item *dItem = maciez.fItems[aindex];

for (long iT = aindex; iT < Count-1; iT++) {

maciez.fItems[iT] = maciez.fItems[iT+1];
maciez.fItems[iT]->ipos = iT;
}
maciez.fItems[Count-1] = dItem;
maciez.fItems[Count-1]->ipos = Count-1;
Cut();
}
//---------------------------------------------------------------------------

void __stdcall TSoft_Database::Clr()
{
Count = 0;
}
//---------------------------------------------------------------------------

long __stdcall TSoft_Database::Find(long aistart, char *aChar)
{
for (long iT = aistart; iT < Count; iT++) {
 if (strcmp(maciez.fItems[iT]->text,aChar)==0)
	 {return iT;
	 }
}
return -1;
}
//---------------------------------------------------------------------------

void __stdcall TSoft_Database::Exchange(long aindex1, long aindex2)
{
		TSoft_Item *eItem = maciez.fItems[aindex1];
maciez.fItems[aindex1] = maciez.fItems[aindex2];
maciez.fItems[aindex1]->ipos = aindex1;
maciez.fItems[aindex2] = eItem;
maciez.fItems[aindex2]->ipos = aindex2;
}
//---------------------------------------------------------------------------

void __stdcall TSoft_Database::Sort()
{
for (long index1 = 0; index1 < Count; index1++)
for (long index2 = index1 + 1; index2 < Count; index2++) {
 if (strcmp(maciez.fItems[index1]->text,maciez.fItems[index2]->text) > 0)
	 {Exchange(index1, index2);
	 }
}
}
//---------------------------------------------------------------------------

char *__stdcall TSoft_Database::get_Text(long aFormat)
{
strFree(fText);
return TEXT_FROM_DATA(&fText,this,aFormat);
}
//---------------------------------------------------------------------------

void  __stdcall TSoft_Database::set_Text(long aFormat,char *aText)
{
DATA_FROM_TEXT(this,aText,aFormat);
}
//---------------------------------------------------------------------------

bool __stdcall TSoft_Database::Read(void) {
HANDLE FHand = CreateFile(this->Alias,GENERIC_READ,FILE_SHARE_READ,NULL,OPEN_ALWAYS,FILE_ATTRIBUTE_NORMAL,NULL);
char emsg[256];
if (FHand==INVALID_HANDLE_VALUE) {
return MessageBox(NULL,strAdd(strAdd(strEql(emsg,"Invalid file or path not exists '"),maciez.fAlias),"'"),
						"TSoft_Database read error",
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

bool __stdcall TSoft_Database::Post(void) {
HANDLE FHand = CreateFile(this->Alias,GENERIC_WRITE,FILE_SHARE_WRITE,NULL,CREATE_ALWAYS,FILE_ATTRIBUTE_NORMAL,NULL);
char emsg[256];
if (FHand==INVALID_HANDLE_VALUE) {
return MessageBox(NULL,strAdd(strAdd(strEql(emsg,"Invalid file or path not exists '"),this->Alias),"'"),
						"TSoft_Database post error",
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

TSoft_Database::TSoft_Item *__stdcall ASCHAR(char *atext)
{
static TSoft_Database::TSoft_Item xPARAM;
xPARAM.text = atext;
return &xPARAM;
}
//---------------------------------------------------------------------------

char *__stdcall TEXT_FROM_DATA(char **aText, TSoft_Database *aDatabase, long aformat) {
char *text = strAlloc(1);

 if (aDatabase->Count==0) strEql(text,"");
else
 if (aformat==COMMA) {
for (long tpos = 0, tlen = 1, srclen, iT = 0; ;)
	 {
	  srclen = strLen(aDatabase->Items[iT]->text);
	  if (tpos+1+srclen+3+1 >= tlen)
		  {text = strReAlloc(text,tlen = tpos+srclen+256);
		  }
	  ptrEql((char*)((long)text+tpos), "\"", 1);
	  tpos += 1;
	  ptrEql((char*)((long)text+tpos), aDatabase->Items[iT]->text, srclen);
	  tpos += srclen;
	  ptrEql((char*)((long)text+tpos), "\", ", 3);
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
	  ptrEql((char*)((long)text+tpos), aDatabase->Items[iT]->text, srclen);
	  tpos += srclen;
	  ptrEql((char*)((long)text+tpos), "\r\n", 2);
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

TSoft_Database *__stdcall DATA_FROM_TEXT(TSoft_Database *aData, char *aText, long aformat) {
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
	  ptrEql(tText, (char*)((long)aText + pos), pos_chk - pos);
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