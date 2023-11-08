//---------------------------------------------------------------------------
#include <vcl.h>
#include <shlobj.h>
#include <stdio.h>
#include <shellapi.h>
#pragma hdrstop
//---------------------------------------------------------------------------
#include "Kop32_common.h"
#include "Koper_frm.h"
#include "Infos_frm.h"
//---------------------------------------------------------------------------
#pragma link "EXERES"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
TInfos_form *Infos_form;
//---------------------------------------------------------------------------

__fastcall TInfos_form::TInfos_form(TComponent* Owner)
    : TForm(Owner)
{
hInst = (HINSTANCE)HInstance;
}
//---------------------------------------------------------------------------

int __fastcall TInfos_form::ZastopInfo(AnsiString DstFileName, AnsiString SrcFileName)
{
SHFILEINFO sfi;
//---------------------------------------
SYSTEMTIME SystemTimeDst;
WIN32_FIND_DATA findDataDst;
HANDLE findHandDst = FindFirstFile(DstFileName.c_str(), &findDataDst);
FileTimeToSystemTime(&findDataDst.ftLastWriteTime, &SystemTimeDst);//
char dateStrDst[32];
sprintf(dateStrDst, "%02d-%02d-%02d, %02d:%02d:%02d\n",
		SystemTimeDst.wYear, SystemTimeDst.wMonth, SystemTimeDst.wDay,
		SystemTimeDst.wHour, SystemTimeDst.wMinute, SystemTimeDst.wSecond);
char sizeStrDst[32];
if (findDataDst.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) sizeStrDst[0] = '\0';
else
	sprintf(sizeStrDst, "%s\n", Koper_form->GetBajtText(findDataDst.nFileSizeLow));
if (findHandDst!=INVALID_HANDLE_VALUE)
	FindClose(findHandDst);
AnsiString tempNameDst = DstFileName;
for (;this->Label1->Canvas->TextWidth(tempNameDst)>=220; )
   {
    tempNameDst.Delete(1, 8);
    tempNameDst.Insert("...\\",1);
   }
this->Label1->Caption = "'"+tempNameDst+"'\n"+sizeStrDst+"zmodyfikowano: "+dateStrDst;
SHGetFileInfo(DstFileName.c_str(), NULL,
	&sfi,
	sizeof(SHFILEINFO),
	SHGFI_TYPENAME|SHGFI_DISPLAYNAME|SHGFI_ICON|SHGFI_LARGEICON|SHGFI_SHELLICONSIZE);
Image1->Canvas->Brush->Color = clBtnFace;
Image1->Canvas->FillRect(Rect(0,0,32,32));
DrawIconEx(Image1->Canvas->Handle,
		   0,0,sfi.hIcon,32,32,NULL,NULL,DI_NORMAL);
DeleteObject(sfi.hIcon);
//---------------------------------------
Label0->Caption = "Ten folder zawiera ju¿ '"+String(sfi.szTypeName)+"' o nazwie '"+String(sfi.szDisplayName)+"'";
//---------------------------------------
SYSTEMTIME SystemTimeSrc;
WIN32_FIND_DATA findDataSrc;
HANDLE findHandSrc = FindFirstFile(SrcFileName.c_str(), &findDataSrc);
FileTimeToSystemTime(&findDataSrc.ftLastWriteTime, &SystemTimeSrc);//
char dateStrSrc[32];
sprintf(dateStrSrc, "%02d-%02d-%02d, %02d:%02d:%02d\n",
		SystemTimeSrc.wYear, SystemTimeSrc.wMonth, SystemTimeSrc.wDay,
		SystemTimeSrc.wHour, SystemTimeSrc.wMinute, SystemTimeSrc.wSecond);
char sizeStrSrc[32];
if (findDataSrc.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) sizeStrSrc[0] = '\0';
else
	sprintf(sizeStrSrc, "%s\n", Koper_form->GetBajtText(findDataSrc.nFileSizeLow));
if (findHandSrc!=INVALID_HANDLE_VALUE)
	FindClose(findHandSrc);
AnsiString tempNameSrc = SrcFileName;
for (;this->Label2->Canvas->TextWidth(tempNameSrc)>=220; )
   {
	tempNameSrc.Delete(1, 8);
	tempNameSrc.Insert("...\\",1);
   }
this->Label2->Caption = "'"+tempNameSrc+"'\n"+sizeStrSrc+"zmodyfikowano: "+dateStrSrc;
SHGetFileInfo(SrcFileName.c_str(), NULL,
	&sfi,
	sizeof(SHFILEINFO),
	SHGFI_TYPENAME|SHGFI_DISPLAYNAME|SHGFI_ICON|SHGFI_LARGEICON|SHGFI_SHELLICONSIZE);
Image2->Canvas->Brush->Color = clBtnFace;
Image2->Canvas->FillRect(Rect(0,0,32,32));
DrawIconEx(Image2->Canvas->Handle,
		   0,0,sfi.hIcon,32,32,NULL,NULL,DI_NORMAL);
DeleteObject(sfi.hIcon);
//---------------------------------------
Application->ProcessMessages();
return this->ShowModal();
}
//----------------------------------------------------------------------------

void __fastcall TInfos_form::FormShow(TObject *Sender)
{
Koper_form->Timer1->Enabled = false;
time=timeGetTime();
}
//---------------------------------------------------------------------------

void __fastcall TInfos_form::FormHide(TObject *Sender)
{
Koper_form->OldCzas+=timeGetTime()-time;
Koper_form->Timer1->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TInfos_form::FormCreate(TObject *Sender)
{
Image3->Canvas->Brush->Color = clBtnFace;
Image3->Canvas->FillRect(Rect(0,0,48,48));
DrawIconEx(Image3->Canvas->Handle,
		   8,8,(HICON)ExeResource1->Handle["#146"],32,32,
		   NULL,NULL,DI_NORMAL);
}
//---------------------------------------------------------------------------




