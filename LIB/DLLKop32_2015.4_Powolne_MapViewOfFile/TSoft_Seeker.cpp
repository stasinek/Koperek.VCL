//---------------------------------------------------------------------------
//-----------------Stanislaw Stasiak "SSTSOFT.pl" 2001-2002------------------
//---------------------------------------------------------------------------
// --------------------cos jak SHFileOperation(..., ...);--------------------
//---------------------------------------------------------------------------
#include <windows.h>
#include "TSoft_Koder.h"
#include "TSoft_Pharser.h"
#pragma hdrstop
#include "TSoft_Kop32.h"
//
//---------------------------------------------------------------------------

#define SEEKSRC_FIND_FIRST(patch)\
		  file.src.find.Next = (file.src.find.Hand = FindFirstFile(patch, &file.src.find.Data))!=INVALID_HANDLE_VALUE;\
	for (;file.src.find.Next ?  file.src.find.Data.cFileName[0]=='.' : false;)\
		{ file.src.find.Next =  FindNextFile(file.src.find.Hand, &file.src.find.Data);\
		}
#define SEEKSRC_FIND_NEXT()\
	file.src.find.Next = FindNextFile(file.src.find.Hand, &file.src.find.Data);
#define SEEKSRC_FIND_CLOSE()\
	if (file.src.find.Hand!=INVALID_HANDLE_VALUE)\
		{FindClose(file.src.find.Hand);\
		}
#define SEEKSRC_FIND_ADD_TO_LIST(patch,found)\
	if (found!=0 && file.src.find.Data.nFileSizeHigh==0)\
		{crt = list.src.Main.Add(ASCHAR(patch));\
		 list.src.Main.Items[crt]->data_size[IS] = EXISTS;\
		 list.src.Main.Items[crt]->data_size[ATTRIB] = file.src.find.Data.dwFileAttributes;\
		 list.src.Main.Items[crt]->data_size[SIZE] = file.src.find.Data.nFileSizeLow;\
         progress.src.all.Size += file.src.find.Data.nFileSizeLow;\
		}\
	else\
		{crt = list.src.Main.Add(ASCHAR(patch));\
		 list.src.Main.Items[crt]->data_size[IS] = 0;\
		 list.src.Main.Items[crt]->data_size[ATTRIB] = 0;\
		 list.src.Main.Items[crt]->data_size[SIZE] = 0;\
		}
#define SEEKSRC_STACK_PUSH(patch)\
		crt = list_seek_stack->Add(ASCHAR(patch));\
		list_seek_stack->Items[crt]->data[IS] = file.src.find.Hand;

#define SEEKSRC_STACK_POP(patch)\
		file.src.find.Hand = list_seek_stack->Items[list_seek_stack->Count-1]->data[0];\
		strEql(patch, list_seek_stack->Items[list_seek_stack->Count-1]->text);

int __stdcall TSoft_Kop32::SeekSrc(char *alpSrc) {
char *currentlpStr = stack.Push(0);
strEql(currentlpStr,alpSrc);
strFixFilePath(currentlpStr,alpSrc);
char *templpStr    = stack.Push(0);
TSoft_Database *list_seek_stack = new TSoft_Database("lprzesz");
int crt;
//
FOnBreak(onSEEKING|isSRC,0);
//
file.dst.find.Next = (file.src.find.Hand = FindFirstFile(currentlpStr,&file.src.find.Data))!=INVALID_HANDLE_VALUE;
//
if (file.dst.find.Next==0 ? strLen(currentlpStr) > 3 : false)
	{SetLastError(ERROR_FILE_NOT_FOUND);
	 stack.Pop(2,true);
	 return 0;
	}
if (file.src.find.Next!=0 ? (file.src.find.Data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)==0 : false)
	{FindClose(file.src.find.Hand);
	     SEEKSRC_FIND_ADD_TO_LIST(currentlpStr,file.dst.find.Next);
     stack.Pop(2,true);
	 return 1;
	}
if (file.src.find.Next!=0)
	{FindClose(file.src.find.Hand);
	}
//------------------------------------------
for (;options.Stop==0;) {
//------------------------------------------

        FOnBreak(opSEEKPROGRESS|isSRC,0);
	SEEKSRC_FIND_ADD_TO_LIST(currentlpStr,file.dst.find.Next);
	SeekSrcFile(currentlpStr); // szukaj w katalogu
	strEql(templpStr,currentlpStr);
	strAdd(templpStr,"\\*.*");
	SEEKSRC_FIND_FIRST(templpStr);
	SEEKSRC_STACK_PUSH(currentlpStr);

//------------------------------------------
for (;options.Stop==0;) {
//------------------------------------------

	if ((file.src.find.Next)==0)
		{
		SEEKSRC_STACK_POP(currentlpStr);
		SEEKSRC_FIND_CLOSE();

		if (list_seek_stack->Cut()==0)
		break;

		SEEKSRC_STACK_POP(currentlpStr);
		SEEKSRC_FIND_NEXT();
		continue;
		}
	else
	if ((file.src.find.Data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)!=0)
		{
		strAdd(currentlpStr,"\\");
		strAdd(currentlpStr,file.src.find.Data.cFileName);
		break;
		}
	else
		{
		SEEKSRC_FIND_NEXT();
		continue;
		}
//------------------------------------------
}
//------------------------------------------
		if (list_seek_stack->Count==0)
		break;
//------------------------------------------
}
//------------------------------------------
SeekSrcX:
//------------------------------------------
delete list_seek_stack;
stack.Pop(2,true);
return 1;
}
//---------------------------------------------------------------------------

int __stdcall TSoft_Kop32::SeekSrcFile(char *alpSrc) {
char *currentlpStr = stack.Push(0);
int   crt;

FOnBreak(opSEEKPROGRESS|isSRC,0);
for (int iMaska = 0; iMaska < options.Masks.Count && options.Stop==0; iMaska++) {

// szukaj plikow o "kolejnych maskach"
	strEql(currentlpStr,alpSrc);
	strAdd(currentlpStr, "\\");
	strAdd(currentlpStr,options.Masks.Items[iMaska]->text);
	SEEKSRC_FIND_FIRST(currentlpStr);
//------------------------------------------
for (;options.Stop==0;) {
//------------------------------------------

	if ((file.src.find.Next)==0)
		{
		SEEKSRC_FIND_CLOSE();
		break;
		}
	else
	if ((file.src.find.Data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)==0)
		{
		strEql(currentlpStr,alpSrc);
		strAdd(currentlpStr, "\\");
		strAdd(currentlpStr,file.src.find.Data.cFileName);
		SEEKSRC_FIND_ADD_TO_LIST(currentlpStr,file.dst.find.Next);
		SEEKSRC_FIND_NEXT();
		continue;
		}
	else
		{
		SEEKSRC_FIND_NEXT();
		continue;
		}
//------------------------------------------
}
//------------------------------------------
}
//------------------------------------------
stack.Pop(1,true);
return 1;
}
//----------------------------------------------------------------------------

#define SEEKDST_FIND_FIRST(patch)\
	file.dst.find.Next =(file.dst.find.Hand = FindFirstFile(patch, &file.dst.find.Data))!=INVALID_HANDLE_VALUE;
#define SEEKDST_FIND_NEXT()\
	file.dst.find.Next = FindNextFile(file.dst.find.Hand, &file.dst.find.Data);
#define SEEKDST_FIND_CLOSE()\
	if (file.dst.find.Hand!=INVALID_HANDLE_VALUE)\
		{FindClose(file.dst.find.Hand);\
		}
#define SEEKDST_FIND_ADD_TO_LIST(patch,found)\
	if (found!=0 && file.dst.find.Data.nFileSizeHigh==0)\
		{crt = list.dst.Main.Add(ASCHAR(patch));\
		 list.dst.Main.Items[crt]->data_size[IS] = EXISTS;\
		 list.dst.Main.Items[crt]->data_size[ATTRIB] = file.dst.find.Data.dwFileAttributes;\
		 list.dst.Main.Items[crt]->data_size[SIZE] = file.dst.find.Data.nFileSizeLow;\
	     progress.dst.all.Size += file.dst.find.Data.nFileSizeLow; \
	 	}\
	else\
		{crt = list.dst.Main.Add(ASCHAR(patch));\
		 list.dst.Main.Items[crt]->data_size[IS] = 0;\
		 list.dst.Main.Items[crt]->data_size[ATTRIB] = 0;\
		 list.dst.Main.Items[crt]->data_size[SIZE] = 0;\
		}
int __stdcall TSoft_Kop32::SeekDst(char *alpDst) {
char *lpSrc     = stack.Push(0);
char *templpSrc = stack.Push(0);
strFixFilePath(lpSrc,list.src.Main.Items[list.dst.Main.Count]->text);
char *lpDst     = stack.Push(0);
char *templpDst = stack.Push(0);
strFixFilePath(lpDst,alpDst);
char *templpStr = stack.Push(0);
int crt;

FOnBreak(onSEEKING|isDST,0);

if (strLen(lpSrc) > 3)
	{
	 strAdd(lpDst, "\\");
	 strExtractFileName(templpSrc,lpSrc);
	 strAdd(lpDst, templpSrc);

	 if (options.Operation==opKODUJ)
		 {strAdd(lpDst,".eno");
		 }
	 else
	 if (options.Operation==opDEKODUJ)
		 {if (*(int*)((int)lpDst+strLen(lpDst)-4)==*(int*)".eno")
				lpDst[strLen(lpDst)-4] = '\0';
		 }
	}
if (options.Operation!=opKODUJ && options.Operation!=opDEKODUJ)
	{
	 strEql(templpSrc,lpSrc);
	 strupr(templpSrc);
	 strEql(templpDst,lpDst);
	 strupr(templpDst);

	 if (strcmp(templpSrc,templpDst)==0)
	for (int nKopii =1; options.Stop==0; nKopii++)
		 {
		  strExtractFilePath(lpDst,lpDst);

		  if (nKopii==1)
			  {
				strAdd(lpDst, "\\Kopia ");
				strExtractFileName(templpStr,lpSrc);
				strAdd(lpDst, templpStr);
			  }
		  else
			  {
				strAdd(lpDst, "\\Kopia (");
				strAdd(lpDst, intToStr(nKopii));
				strAdd(lpDst, ") ");
				strExtractFileName(templpStr,lpSrc);
				strAdd(lpDst, templpStr);
			  }
		  SEEKDST_FIND_FIRST(templpStr);
		  if (file.dst.find.Next==0)
			  {break;
			  }
		  SEEKDST_FIND_CLOSE();
		 }
	}
for (int  srclen_old = strLen(lpSrc), dstlen_old = strLen(lpDst); list.dst.Main.Count < list.src.Main.Count && options.Stop==0; )
	 {
         FOnBreak(opSEEKPROGRESS|isDST,0);
	 // ustawiam now¹ nazwê najpierw kopiujê star¹ pierwotn¹
	 strEql(templpStr, lpDst);
	 strAdd(templpStr, (char*)((int)list.src.Main.Items[list.dst.Main.Count]->text + srclen_old));
	 // preparuj nazwê dla kodowania lub dekodowania
	 if (options.Operation==opKODUJ)
		 {for (int p = strLen(templpStr); p > dstlen_old; p--)
			if (templpStr[p]=='\\' || templpStr[p]=='\0')
				 strInsert(templpStr,p,".eno");
		 }
	 else
	 if (options.Operation==opDEKODUJ)
		 {for (int p = strLen(templpStr); p > dstlen_old; p--)
			if (templpStr[p]=='\\' || templpStr[p]=='\0')
				 if (*(int*)((int)templpStr+p-4)==*(int*)".eno")
					  strDel(templpStr,p-=4,4);
		 }
	 // szukaj fileu lub katalogu by dobrze ocenic iloœæ wolnego miejsca (to co jest zajête tak naprawdê jest wolnym miejscem)
	 SEEKDST_FIND_FIRST(templpStr);
	 SEEKDST_FIND_ADD_TO_LIST(templpStr,file.dst.find.Next);
	 SEEKDST_FIND_CLOSE();
	 }
stack.Pop(5,true);
return 1;
}
//---------------------------------------------------------------------------
