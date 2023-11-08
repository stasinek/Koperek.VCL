//---------------------------------------------------------------------------
//-------- COPYRIGHT: Stanislaw Stasiak SSTSOFT.pl @2001-2004 ---------------
//-------- https://github.com/stasinek/Koperek.VCL --------------------------
//---------------------------------------------------------------------------
#include <windows.h>
#include <winbase.h>
#pragma hdrstop
//---------------------------------------------------------------------------
#include "TSoft_Kop32.h"
#include "TSoft_Pharser.h"
#include "TSoft_Koder.h"
//---------------------------------------------------------------------------

DWORD WINAPI TSoft::Kop32::WriteFileThread( LPVOID a)
{
register TSoft::Kop32 *Caller = (TSoft::Kop32*)a;

 while ((Caller->WriteFileThreadControl & 2) == 0) {
	if ((Caller->WriteFileThreadControl & 1) != 0) {
		int i =  Caller->mem_write_index;
		Caller->file.dst.buffer.Size = Caller->mem_buffer[i].Size;
		Caller->file.dst.buffer.Offset = Caller->mem_buffer[i].Offset;
		Caller->file.dst.buffer.Lptr = Caller->mem_buffer[i].Lptr;
		if (Caller->file.dst.buffer.Lptr==NULL)
		   {Caller->WriteFileThreadControl = 4;
		   }
		DWORD written;
		WriteFile(Caller->file.dst.Hand,&( (__int8*)Caller->file.dst.buffer.Lptr)[Caller->file.dst.buffer.Offset],Caller->file.dst.buffer.Size, &written,NULL);
		if (written!=Caller->file.dst.buffer.Size)
		   {Caller->WriteFileThreadControl = 4;
		   }
		if (Caller->options.Cached!=true)
			FlushFileBuffers(Caller->file.dst.Hand);
		ptrFree((void*)Caller->mem_buffer[i].Lptr );
		Caller->mem_buffer[i].Lptr = NULL;
		Caller->file.dst.Read += Caller->file.dst.buffer.Size;
		Caller->progress.dst.all.Read += Caller->file.dst.buffer.Size;
		Caller->progress.dst.one.Read  = Caller->file.dst.Read;
		Caller->progress.dst.one.Size  = Caller->file.dst.Size;
		Caller->FOnBreak(onPROGRESS,4);
		Caller->WriteFileThreadControl = 0;
		SwitchToThread();
		}
else
		{
		Sleep(1);
		}
}
return 0;
}
//---------------------------------------------------------------------------

__stdcall TSoft::Kop32::Kop32() : OnError(&DoError), OnBreak(&DoBreak)
{
list.src.Init.Alias = "SRC_INIT";
list.src.Main.Alias = "SRC_MAIN";
list.dst.Init.Alias = "DST_INIT";
list.dst.Main.Alias = "DST_MAIN";
}
//---------------------------------------------------------------------------

__stdcall TSoft::Kop32::~Kop32(void)
{
}
//---------------------------------------------------------------------------

void  __stdcall TSoft::Kop32::SetPassword(const char *ausrpassword) {
strMov(password.FUsr,ausrpassword);
strMov(password.FEnc,ausrpassword); password.FSize = (__int8)strLen(ausrpassword);

int  pos;  __int64 checksum = 0;
for (pos = password.FSize-1; pos!=-1; pos--)
	 {checksum +=password.FEnc[pos];
	 }
for (pos = password.FSize-1; pos!=-1; pos--)
    {password.FEnc[pos] = password.FEnc[pos] ^ (char)((checksum % (pos+1)) ^ pos);
	 }
}
//---------------------------------------------------------------------------

const char *__stdcall TSoft::Kop32::GetPassword()
{
return password.FUsr;
}
//---------------------------------------------------------------------------

int __stdcall TSoft::Kop32::GetPasswordSize()
{
return password.FSize;
}
//---------------------------------------------------------------------------

void __stdcall TSoft::Kop32::Clr(void)
{
ptrSet(&progress,sizeof(progress),NULL);
ptrSet(&options, sizeof(options), NULL);
ptrSet(&file, sizeof(file),	NULL);
ptrSet(&password,sizeof(password),NULL);

list.src.Init.Clr();
list.src.Main.Clr();
list.dst.Init.Clr();
list.dst.Main.Clr();

options.Batch.Clr();
options.Masks.Clr();
options.Argts.Clr();
}
//---------------------------------------------------------------------------

int __stdcall TSoft::Kop32::Execute(const char *AlpDst, const char *AlpSrc)
{
char  *templpDst = stack.Push(STACKSTR+strLen(AlpDst));
strMov(templpDst,AlpDst);
char  *templpSrc = stack.Push(STACKSTR+strLen(AlpSrc));
strMov(templpSrc,AlpSrc);
char  *templp    = stack.Push(STACKSTR+strLen(AlpDst)+strLen(AlpSrc));

int xpos[4];
int i,z,d,ret,blad;
Clr(); // czyszczenie list
options.Operation = opNULL;

strMov(templp,templpDst);
strupr(templp);
if (Pharser(templp,"DELETE ",NULL,xpos))
   {options.Operation = opUSUN;
    strDelEnd(templpDst,xpos[0],xpos[3]);
	goto ExecuteOPTIONS;
   }
strMov(templp,templpDst);
strupr(templp);
if (Pharser(templp,"DECOMPRESS ",NULL,xpos))
   {options.Operation = opDEKODUJ;
    strDelEnd(templpDst,xpos[0],xpos[3]);
	goto ExecuteOPTIONS;
   }
strMov(templp,templpDst);
strupr(templp);
if (Pharser(templp,"COMPRESS ",NULL,xpos))
   {options.Operation = opKODUJ;
    strDelEnd(templpDst,xpos[0],xpos[3]);
    goto ExecuteOPTIONS;
   }
strMov(templp,templpDst);
strupr(templp);
if (Pharser(templp,"MOVE ",NULL,xpos))
   {options.Operation = opPRZENIES;
    strDelEnd(templpDst,xpos[0],xpos[3]);
    goto ExecuteOPTIONS;
   }
strMov(templp,templpDst);
strupr(templp);
if (Pharser(templp,"COPY ",NULL,xpos))
   {options.Operation = opKOPIUJ;
    strDelEnd(templpDst,xpos[0],xpos[3]);
    goto ExecuteOPTIONS;
   }
strMov(templp,templpDst);
strupr(templp);
if (Pharser(templp,"LIST ",NULL,xpos))
   {options.Operation = opLISTUJ;
    strDelEnd(templpDst,xpos[0],xpos[3]);
    goto ExecuteOPTIONS;
   }
strMov(templp,templpDst);
strupr(templp);
if (Pharser(templp,"SELECT ",NULL,xpos))
   {options.Operation = opZAZNACZ;
    strDelEnd(templpDst,xpos[0],xpos[3]);
    goto ExecuteOPTIONS;
   }
ExecuteOPTIONS:
//
// break
//
options.Break = anQUEST;
strMov(templp,templpDst);
strupr(templp);
if (Pharser(templp,"BREAK",templp,xpos))
   {if (templp[0]=='T') options.Break = anALL;
    if (templp[0]=='?') options.Break = anQUEST;
    if (templp[0]=='N') options.Break = anNO;
    strDelEnd(templpDst,xpos[0],xpos[3]);
   }
//
// error
//
options.Error = anQUEST;
strMov(templp,templpDst);
strupr(templp);
if (Pharser(templp,"ERROR",templp,xpos))
   {if (templp[0]=='T') options.Error = anALL;
    if (templp[0]=='?') options.Error = anQUEST;
    if (templp[0]=='N') options.Error = anNO;
    strDelEnd(templpDst,xpos[0],xpos[3]);
   }
//
// maska
//
options.Masks.Text[COMMA] = "*.*";
    strMov(templp,templpDst);
    strupr(templp);
    if (Pharser(templp,"COMMA",templp,xpos))
	   {options.Masks.Text[COMMA] = templp;
        strDelEnd(templpDst,xpos[0],xpos[3]);
	   }
//
// ARGumenTS
//
options.Argts.Text[COMMA] = "%name%";
strMov(templp,templpDst);
strupr(templp);
if (Pharser(templp,"LIST",templp,xpos))
   {options.Argts.Text[COMMA] = templp;
    strDelEnd(templpDst,xpos[0],xpos[3]);
   }
//
// password
//
SetPassword("");
strMov(templp,templpDst);
strupr(templp);
if (Pharser(templp,"PASSWORD",templp,xpos))
   {SetPassword(templp);
    strDelEnd(templpDst,xpos[0],xpos[3]);
   }
//
// cutend
//
options.Cut = MAXLONG;
strMov(templp,templpDst);
strupr(templp);
if (Pharser(templp,"CUT",templp,xpos))
   {options.Cut = strToInt(templp);
    strDelEnd(templpDst,xpos[0],xpos[3]);
   }
//
// CACHE
//
options.Cached = true;
strMov(templp,templpDst);
strupr(templp);
if (Pharser(templp,"FLUSH",NULL,xpos))
   {options.Cached = false;
    strDelEnd(templpDst,xpos[0],xpos[3]);
   }
options.Block = 64 * 1024;
strMov(templp,templpDst);
strupr(templp);
if (Pharser(templp,"BUFFER",templp,xpos))
   {options.Block = strToInt(templp) * 1024;
    if (options.Block > 65536 * 1024 || options.Block==0)
       {FOnError(ERROR_INVALID_USER_BUFFER,MB_OK);
        options.Stop = true;
        return 0;
       }
    strDelEnd(templpDst,xpos[0],xpos[3]);
   }
//
// DICT
//
options.Dict = 4096;
strMov(templp,templpDst);
strupr(templp);
if (Pharser(templp,"DICT",templp,xpos))
   {options.Dict = strToInt(templp);
    if (options.Dict > 65536 || options.Dict < 256)
       {FOnError(ERROR_INVALID_USER_BUFFER,MB_OK);
        options.Stop = true;
        return 0;
		}
    strDelEnd(templpDst,xpos[0],xpos[3]);
   }
//
// methods
//
options.Methods = mtDEFAULT;
strMov(templp,templpDst);
strupr(templp);
if (Pharser(templp,"METHODS",templp,xpos))
   {options.Methods  = 0x00000000;

    if (-1!=strPos(templp,0,"CRC"))
       {options.Methods |= mtCRC;
        options.Methods &=~mtADLER;
       }
    if (-1!=strPos(templp,0,"ADLER"))
       {options.Methods |= mtADLER;
        options.Methods &=~mtCRC;
       }
    if (-1!=strPos(templp,0,"XOR"))
	    options.Methods |= mtXOR;
    if (-1!=strPos(templp,0,"SXQ"))
	    options.Methods |= mtSXQ;
    if (-1!=strPos(templp,0,"STORE"))
        options.Methods |= mtDEFAULT;
    if (-1!=strPos(templp,0,"LZS"))
        options.Methods |= mtLZS;
	if (-1!=strPos(templp,0,"HUF"))
	    options.Methods |= mtHUF;
	if (-1!=strPos(templp,0,"ARI"))
	    options.Methods |= mtARI;
    if (-1!=strPos(templp,0,"DEFAULT"))
	    options.Methods |= mtDEFAULT;
    if (-1!=strPos(templp,0,"BWT"))
        options.Methods |= mtBWT;
    if (-1!=strPos(templp,0,"MTF"))
        options.Methods |= mtMTF;
	if (-1!=strPos(templp,0,"ULTRA"))
        options.Methods |= mtULTRA;

    strDelEnd(templpDst,xpos[0],xpos[3]);
   }
//
// Src
//
TSoft::Database *LPreSrc = new TSoft::Database("DST_PRE");
LPreSrc->Text[COMMA] = templpSrc;
for (i = LPreSrc->Count-1; i!=-1;i--)
    {if (strPos(LPreSrc->Items[i]->text,0,":")==-1)
         LPreSrc->Delete(i);
    }
//
// Dst
//
TSoft::Database *LPreDst = new TSoft::Database("DST_PRE");
LPreDst->Text[COMMA] = templpDst;
for (i = LPreDst->Count-1; i!=-1;i--)
    {if (strPos(LPreDst->Items[i]->text,0,":")==-1)
         LPreDst->Delete(i);
    }
//----------------------------

if (options.Operation==opZAZNACZ)
   {
	list.src.Init.Mov(LPreDst);
	if (list.src.Init.Count==0)
	options.Operation =opNULL;
	list.dst.Init.Clr();
   }
else
if (options.Operation==opUSUN)
   {
	list.src.Init.Mov(LPreDst);
	if (list.src.Init.Count==0)
	options.Operation =opNULL;
	list.dst.Init.Clr();
   }
else
   {
	list.src.Init.Mov(LPreSrc);
	if (list.src.Init.Count==0)
	options.Operation = opNULL;
	list.dst.Init.Mov(LPreDst);
	if (list.dst.Init.Count==0)
	options.Operation = opNULL;
   }
if (options.Operation==opNULL)
   {
	FOnError(RPC_S_CANNOT_SUPPORT,MB_OK);
	goto ExecuteX;
   }
if (options.Operation==opZAZNACZ)
   {
	if (OpenClipboard(NULL)==false)
	   {if (options.Error==anQUEST)
		    FOnError(GetLastError(),MB_OK);
	    goto ExecuteX;
       }
    char *tStr = strDup(list.src.Init.Text[COMMA]);
    	 if (IsClipboardFormatAvailable(CF_TEXT))
    		  EmptyClipboard();
    SetClipboardData(CF_TEXT, tStr);
    CloseClipboard();
    goto ExecuteX;
   }
//
FOnBreak(onSTART,0); // START >>>>
//
#define IF_USER_ACCEPT_ERROR()\
if (FOnError(GetLastError(),MB_OKCANCEL)==IDCANCEL)\
   {options.Stop = true;\
	goto ExecuteX;\
   }
if (options.Break==anQUEST)
   {
		ret = FOnBreak(onQUEST,MB_YESNOCANCEL);
    if (ret!=IDOK && ret!=mrYes)
	   {options.Stop==0;
		goto ExecuteX;
	   }
   }
if (options.Operation==opUSUN || options.Operation==opLISTUJ)
   {
	for (z = 0; z < list.src.Init.Count && options.Stop==0; z++)
		{
		 blad = 0;

		 strFixFilePath(templpSrc, list.src.Init.Items[z]->text);
		 if (strLen(templpSrc) > 3)
			{
				 file.src.find.Hand =FindFirstFile(list.src.Init.Items[z]->text, &file.src.find.Data);
			 if (file.src.find.Hand==INVALID_HANDLE_VALUE)
				{blad =true;
				 SetLastError(ERROR_FILE_NOT_FOUND);
				}
			 else FindClose(file.src.find.Hand);
			}
		 if (blad==false ? SeekSrc(list.src.Init.Items[z]->text)==0 : true)
			{IF_USER_ACCEPT_ERROR()
			 else
				 continue;
			}
		}
	}
else
if (options.Operation==opKOPIUJ || options.Operation==opPRZENIES || options.Operation==opKODUJ || options.Operation==opDEKODUJ)
   {
   for (z = 0; z < list.src.Init.Count && options.Stop==0; z++)
   for (d = 0; d < list.dst.Init.Count && options.Stop==0; d++) // petla kopiowania XBar (krzy¿owego)
	   {
		blad = 0;

		strFixFilePath(templp,list.src.Init.Items[z]->text);
		if (strLen(templp) > 3)
		   {
				file.src.find.Hand =FindFirstFile(list.src.Init.Items[z]->text,&file.src.find.Data);
			if (file.src.find.Hand==INVALID_HANDLE_VALUE)
			   {blad =true;
				SetLastError(ERROR_FILE_NOT_FOUND);
			   }
			else FindClose(file.src.find.Hand);
		   }
		strFixFilePath(templp, list.dst.Init.Items[d]->text);
		if (strLen(templp) > 3)
		   {
				file.dst.find.Hand =FindFirstFile(list.dst.Init.Items[d]->text,&file.dst.find.Data);
			if (file.dst.find.Hand==INVALID_HANDLE_VALUE)
			   {blad =true;
				SetLastError(ERROR_FILE_NOT_FOUND);
			   }
			else FindClose(file.dst.find.Hand);
		   }
		strFixFilePath(templpSrc, list.src.Init.Items[z]->text);
		strupr(templpSrc);
		strAdd(templpSrc,"\\");
		strFixFilePath(templpDst, list.dst.Init.Items[d]->text);
		strupr(templpDst);
		strAdd(templpDst,"\\");
		if (strPos(templpDst,0,templpSrc)>=0)
		   {blad =true;
			SetLastError(EPT_S_CANT_PERFORM_OP);
		   }
		if (blad!=true ? SeekSrc(list.src.Init.Items[z]->text)==0 || SeekDst(list.dst.Init.Items[d]->text)==0 : true)
		   {IF_USER_ACCEPT_ERROR();
		   }
		if (DiskSpace(strExtractFileRoot(templpDst,list.dst.Init.Items[d]->text),progress.src.all.Size,progress.dst.all.Size,true,true) < 0)
		   {goto ExecuteX;
		   }
	   }
   }
//----------------------------

if (options.Operation==opUSUN)
   {list.iInc = -1;
    list.iBgn = list.src.Main.Count-1;
    list.iCur = list.iBgn;
   }
else
   {list.iInc = +1;
	list.iBgn = +0;
	list.iCur = list.iBgn;
   }
//
FOnBreak(onIO,0); // IO >>>>
WriteFileThreadControl = 0; //czekaj 1 startuj, 2 zakoñcz
WriteFileThreadHandle = CreateThread(NULL,0,&TSoft::Kop32::WriteFileThread,this,0,&WriteFileThreadId);
if (WriteFileThreadHandle==NULL) { options.Stop = true; goto ExecuteX;
   }

//
for (d = 0; list.iCur >= 0 && list.iCur < list.src.Main.Count && options.Stop==0; list.iCur+=list.iInc)
	{
	 /// CHECK SRC
	 if (list.src.Main.Items[list.iCur]->data_size[IS]!=EXISTS)
	 	 continue;

	 if (options.Operation==opKOPIUJ || options.Operation==opKODUJ || options.Operation==opDEKODUJ || options.Operation==opPRZENIES)  {
	 // CHECK DST
	 if (list.dst.Main.Items[list.iCur]->data_size[IS]==EXISTS)
     // PYTAJ
	 if (options.Break==anQUEST)
		{
		 ret = FOnBreak(onREPLACE_QUEST,MB_YESNOCANCEL); // zadanie potwierdzenia nadpisania
		 //
		 if (ret==mrCancel) // odpowiedŸ ->
			 {options.Stop = true;
			  continue;
			 }
		 else
		 if (ret==mrNoToAll)
			 {Skip(list.iCur,1);
			  continue;
			 }
		 else
		 if (ret==mrNo)
			 {Skip(list.iCur,0);
			  continue;
			 }
		 else
		 if (ret==mrYesToAll)
			 {d = strDelimiter(list.src.Main.Items[list.iCur]->text,'\\',-1);
			  options.Break =anALL;
			 }
		 else
		 if (ret==mrYes)
			 {// NOP
			 }
		 else
			 {continue;
			 }
		 }
	 else
		 {
		 if (d > strDelimiter(list.src.Main.Items[list.iCur]->text,'\\',-1))
			 {list.iCur--;
			  options.Break =anQUEST;
			  continue;
			 }
		 }
	 }
	 /// GO GO GO
	 if (Procede(list.iCur, options.Operation)==0)
		{
		 if (options.Error==anQUEST)
			  options.Stop |= FOnError(GetLastError(),MB_OKCANCEL)!=IDOK;
		 if (options.Error==anNO)
			  options.Stop = true;
		 if (options.Error==anALL)
			  continue;
		}
	}
//----------------------------

if (options.Operation==opPRZENIES)
   {
	int all_nor_dir = options.Masks.Find(0,"*.*")>=0, ret;

	for (list.iCur = list.src.Main.Count-1; options.Stop==0 && list.iCur >= 0; list.iCur--)
		{
		 if (list.src.Main.Items[list.iCur]->data_size[IS]!=EXISTS)
			 continue;

		 if (all_nor_dir ? false : (list.src.Main.Items[list.iCur]->data_size[ATTRIB] & FILE_ATTRIBUTE_DIRECTORY)!=0)
			{continue;
			}
		 if (list.src.Main.Items[list.iCur]->data_size[ATTRIB] & FILE_ATTRIBUTE_DIRECTORY)
			{
			 if (SetFileAttributes(list.src.Main.Items[list.iCur]->text,FILE_ATTRIBUTE_NORMAL)==false) ret=false;
			 else
				 ret = RemoveDirectory(list.src.Main.Items[list.iCur]->text);
			}
		 else
			{
			 if (SetFileAttributes(list.src.Main.Items[list.iCur]->text,FILE_ATTRIBUTE_NORMAL)==false) ret=false;
			 else
				 ret = DeleteFile(list.src.Main.Items[list.iCur]->text);
			}
		 if (ret==false)
			{
			 if (options.Error==anQUEST)
				 options.Stop |= FOnError(GetLastError(),MB_OKCANCEL)!=IDOK;
			 if (options.Error==anNO)
				 options.Stop = true;
			 if (options.Error==anALL)
				 continue;
			}
		}
	}
else
if (options.Operation==opLISTUJ) // zapisanie listy do fileu
   {
	for (list.iCur = 0; options.Stop==0 && list.iCur < list.dst.Init.Count; list.iCur++)
		{
			 strMov(templp, list.dst.Init.Items[list.iCur]->text);
			 strupr(templp);
		 if (strPos(templp,0,"CLIPBOARD:")>=0 ? ret = OpenClipboard(NULL) : 0)
			  {
			     char *tStr = strDup(options.Batch.Text[LINES]);
			     if (IsClipboardFormatAvailable(CF_TEXT)) EmptyClipboard();
			  	 SetClipboardData(CF_TEXT,tStr);
			     CloseClipboard();
			  }
		  else
			  {
			  options.Batch.Alias = list.dst.Init.Items[list.iCur]->text;
			  ret = options.Batch.Save();
			  }
		  if (ret==false)
			  {
			  if (options.Error==anQUEST)
					options.Stop |= FOnError(GetLastError(),MB_OKCANCEL)!=IDOK;
			  if (options.Error==anNO)
					options.Stop = true;
			  if (options.Error==anALL)
					continue;
			  }
		 }
	}
ExecuteX:
delete LPreDst; delete LPreSrc;
stack.Pop(3,true);
WriteFileThreadControl &= 2;
TerminateThread(WriteFileThreadHandle,0);
WriteFileThreadHandle = NULL;
if (options.Stop==true) {
MessageBeep(MB_ICONEXCLAMATION);
return 0;
}
else {
//MessageBeep(0xFFFFFFFF);
return -1;
}
}
//---------------------------------------------------------------------------

void __stdcall TSoft::Kop32::Stop(void) {
options.Stop = true;
}
//---------------------------------------------------------------------------

int __stdcall TSoft::Kop32::Skip(int aindex, bool an_all_not_one) {
char  *templpSrc = stack.Push(0);
strMov(templpSrc,list.src.Main.Items[aindex]->text);
int crt;

 if (an_all_not_one==true)
	 {strExtractFilePath(templpSrc,templpSrc);
	 }
for (crt = aindex; crt < list.src.Main.Count; crt++) {
 if (strPos(list.src.Main.Items[crt]->text,0,templpSrc)==-1)
	 {break;
	 }
 progress.src.all.Size -= list.src.Main.Items[crt]->data_size[SIZE];
 list.src.Main.Items[crt]->data_size[IS] = ~EXISTS;
}
if (options.Operation!=opKOPIUJ && options.Operation!=opPRZENIES && options.Operation!=opKODUJ && options.Operation!=opDEKODUJ) {
stack.Pop(1,true);
return 1;
}
char  *templpDst = stack.Push(0);
strMov(templpDst,list.dst.Main.Items[aindex]->text);

 if (an_all_not_one==true)
	 {strExtractFilePath(templpDst,templpDst);
	 }
for (crt = aindex; crt < list.dst.Main.Count; crt++) {
 if (strPos(list.dst.Main.Items[crt]->text,0,templpDst)==-1)
	 {break;
	 }
 progress.src.all.Size -= list.dst.Main.Items[crt]->data_size[SIZE];
 list.dst.Main.Items[crt]->data_size[IS] = ~EXISTS;
}
stack.Pop(2,true);
return 1;
}
//---------------------------------------------------------------------------

int __stdcall TSoft::Kop32::Procede(int aindex, int anaction) {
char  rootStr[3] = "A:";
char *templpStr1;
char *templpStr2;

if ( list.src.Main.Items[aindex]->data_size[IS]!=EXISTS) {
return 0;
}
else
if ((list.src.Main.Items[aindex]->data_size[ATTRIB] & FILE_ATTRIBUTE_DIRECTORY)==0) {
goto ProcedeFILE;
}
else
if (anaction==opPRZENIES) {
FOnBreak(anaction|isDIRECTORY|onPROGRESS,0);
//
	if (list.dst.Main.Items[aindex]->data_size[IS]==EXISTS) {
	if (SetFileAttributes(list.dst.Main.Items[aindex]->text,list.src.Main.Items[aindex]->data_size[ATTRIB])==false)
		{Skip(aindex,false);
		 return 0;
		}
	else
		{return 1;
		}
	}
	if ((list.src.Main.Items[aindex]->text[0] | 0x20L)==(list.dst.Main.Items[aindex]->text[0] | 0x20L)) {
	if (MoveFile(list.src.Main.Items[aindex]->text,list.dst.Main.Items[aindex]->text)==false)
		{Skip(aindex,false);
		 return 0;
		}
	else
		{Skip(aindex,true);
		 return 1;
		}
	}
	else {
	if (Procede(aindex,opKOPIUJ)==false)
		{Skip(aindex,false);
		 return 0;
		}
	else
		{return 1;
		}
	}
}
else
if (anaction==opUSUN) {
FOnBreak(anaction|isDIRECTORY|onPROGRESS,0);
//
	if (SetFileAttributes(list.src.Main.Items[aindex]->text,FILE_ATTRIBUTE_NORMAL)==false)
		{Skip(aindex,false);
		 return 0;
		}
	else
	if (RemoveDirectory(list.src.Main.Items[aindex]->text)==NULL)
		{Skip(aindex,false);
		 return 0;
		}
	else
		{return 1;
		}
}
else
if (anaction==opKOPIUJ || anaction==opKODUJ || anaction==opDEKODUJ) {
FOnBreak(anaction|isDIRECTORY|onPROGRESS,0);
//
	if (list.dst.Main.Items[aindex]->data_size[IS]==EXISTS) {
	if (SetFileAttributes(list.dst.Main.Items[aindex]->text,list.src.Main.Items[aindex]->data_size[ATTRIB])==false)
		{Skip(aindex,false);
		 return 0;
		}
	else
		{return 1;
		}
	}
else
	{
//TODO: If source direcotry is hardlink, need to createdirectory without_ex set attributes manualy
// or ask user what to do because otherwise it would fail to open source, destination files same time for read and write

	if (CreateDirectoryEx(list.src.Main.Items[aindex]->text, list.dst.Main.Items[aindex]->text,NULL)==false)
		{Skip(aindex,false);
		 return 0;
		}
	else
		{return 1;
		}
	}
}
return 1;
//
ProcedeFILE: // PLIK PLIK
//
if (anaction==opLISTUJ) {
FOnBreak(anaction|isFILE|onPROGRESS,0);
//
templpStr1 = stack.Push(0);
templpStr2 = stack.Push(0);

for (int iT = 0; iT < options.Argts.Count; iT++)
	 {
	 strMov(templpStr1,options.Argts.Items[iT]->text);

	 strExchange(templpStr1,"%name",
					list.src.Main.Items[aindex]->text);
	 strExchange(templpStr1,"%path",
					strExtractFilePath(templpStr2,list.src.Main.Items[aindex]->text));
	 strExchange(templpStr1,"%file",
					strExtractFileName(templpStr2,list.src.Main.Items[aindex]->text));
	 strExchange(templpStr1,"%extt",
					strExtractFileExtt(templpStr2,list.src.Main.Items[aindex]->text));
	 strExchange(templpStr1,"%size",
					intToStr(list.src.Main.Items[aindex]->data_size[SIZE]));
	 strExchange(templpStr1,"%attr",
					intToStr(list.src.Main.Items[aindex]->data_size[ATTRIB]));

	 options.Batch.Add(ASCHAR(templpStr1));
	 }
FOnBreak(onPROGRESS,0);
stack.Pop(2,true);
return 1;
}
else
if (anaction==opPRZENIES) {
FOnBreak(anaction|isFILE|onPROGRESS,0);
//
if ((list.src.Main.Items[aindex]->text[0] | 0x20L)==(list.dst.Main.Items[aindex]->text[0] | 0x20L)) // | 0x20L dla uzyskania ma³ych liter
	{
	file.src.Read = 0;
	file.src.Size = list.src.Main.Items[aindex]->data_size[SIZE];
	file.dst.Read = 0;
	file.dst.Size = list.dst.Main.Items[aindex]->data_size[SIZE];
	//
progress.src.one.Size = file.src.Size;
progress.dst.one.Size = file.dst.Size;
	//
	if (list.dst.Main.Items[aindex]->data_size[IS]==EXISTS) {
	if (SetFileAttributes(list.dst.Main.Items[aindex]->text,FILE_ATTRIBUTE_NORMAL)==false)
		{Skip(aindex,false);
		 return 0;
		}
	else
	if (DeleteFile(list.dst.Main.Items[aindex]->text)==NULL)
		{Skip(aindex,false);
		 return 0;
		}
	}
	if (MoveFile(list.src.Main.Items[aindex]->text,list.dst.Main.Items[aindex]->text)==false)
		{Skip(aindex,false);
		 FOnBreak(onPROGRESS,0);
		 return 0;
		}
	else
		{Skip(aindex,false);
		 FOnBreak(onPROGRESS,0);
		 return 1;
		}
	}
else
	{
	if (Procede(aindex,opKOPIUJ)==false)
		{Skip(aindex,false);
		 FOnBreak(onPROGRESS,0);
		 return 0;
		}
	else
		{FOnBreak(onPROGRESS,0);
		 return 1;
		}
	}
}
else
if (anaction==opUSUN) {
FOnBreak(anaction|isFILE|onPROGRESS,0);
//
file.src.Size = list.src.Main.Items[aindex]->data_size[SIZE];
file.src.Read = 0;
//
progress.src.one.Size = file.src.Size;
//
	if (SetFileAttributes(list.src.Main.Items[aindex]->text,FILE_ATTRIBUTE_NORMAL)==false)
		{Skip(aindex,false);
		 FOnBreak(onPROGRESS,0);
		 return 0;
		}
	else
	if (DeleteFile(list.src.Main.Items[aindex]->text)==NULL)
		{Skip(aindex,false);
		 FOnBreak(onPROGRESS,0);
		 return 0;
		}
	else
		{file.src.Read += file.src.Size;

progress.src.one.Read += file.src.Size;
progress.src.all.Read += file.src.Size;

		 FOnBreak(onPROGRESS,0);
		 return 1;
		}
}
else
if (anaction==opKOPIUJ || anaction==opKODUJ || anaction==opDEKODUJ) {
	// header
__header hdr;
__block_header b_hdr;
file.src.Hand = INVALID_HANDLE_VALUE;
file.src.HandMap = INVALID_HANDLE_VALUE;
file.src.Read = 0;
file.src.Size = list.src.Main.Items[aindex]->data_size[SIZE];
file.dst.Hand = INVALID_HANDLE_VALUE;
file.dst.HandMap = INVALID_HANDLE_VALUE;
file.dst.Read = 0;
file.dst.Size = list.dst.Main.Items[aindex]->data_size[SIZE];
	//
progress.src.one.Read  = 0;
progress.src.one.Size  = file.src.Size;
progress.src.all.Read += 0;
progress.dst.one.Read  = 0;
progress.dst.one.Size  = file.dst.Size;
progress.dst.all.Read += 0;
	 //
FOnBreak(anaction|isFILE|onPROGRESS,0);
	//
		          rootStr[0] = list.dst.Main.Items[aindex]->text[0];
	if (DiskSpace(rootStr,list.src.Main.Items[aindex]->data_size[SIZE],list.dst.Main.Items[aindex]->data_size[SIZE],true,false) < 0)
		{options.Stop = true;
		 goto ProcedeERRORIO;
		}
	 // Open Src >>
	file.src.Hand = CreateFile(list.src.Main.Items[aindex]->text,
									 GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING,
									 FILE_FLAG_SEQUENTIAL_SCAN, NULL);
	if (file.src.Hand==INVALID_HANDLE_VALUE)
		{goto ProcedeERRORIO;
		}
	 // Open Dst >>
	if (list.dst.Main.Items[aindex]->data_size[IS]==EXISTS)
	SetFileAttributes(list.dst.Main.Items[aindex]->text,FILE_ATTRIBUTE_NORMAL);
	file.dst.Hand = CreateFile(list.dst.Main.Items[aindex]->text,
									 GENERIC_READ|GENERIC_WRITE, FILE_SHARE_DELETE, NULL, CREATE_ALWAYS,
									 FILE_FLAG_SEQUENTIAL_SCAN|FILE_ATTRIBUTE_ARCHIVE, file.src.Hand);
	if (file.dst.Hand==INVALID_HANDLE_VALUE)
		{goto ProcedeERRORIO;
		}
	//
	// open HDR
	//
	if (anaction==opKOPIUJ)
		{
		file.src.Read = 0;
		file.src.Size = GetFileSize(file.src.Hand, NULL);
		file.dst.Read = 0;
		file.dst.Size = file.src.Size;
	if (SetFilePointer(file.dst.Hand, file.dst.Size, 0, FILE_BEGIN)==0xFFFFFFFF)
		{goto ProcedeERRORIO;
		}
//	_LARGE_INTEGER size; size.LowPart = file.dst.Size + 1; size.HighPart = 0;
//	if (SetFilePointerEx(file.dst.Hand,size,0,FILE_BEGIN)==0xFFFFFFFF)
//		{goto ProcedeERRORIO;
//		}
	SetEndOfFile(file.dst.Hand);
	if (SetFilePointer(file.dst.Hand, 0, 0, FILE_BEGIN)==0xFFFFFFFF)
		{goto ProcedeERRORIO;
		}
		FILETIME lastwrite;
		GetFileTime(file.src.Hand,NULL,NULL,&lastwrite);
		SetFileTime(file.dst.Hand,NULL,NULL,&lastwrite);
		}
	else
	if (anaction==opKODUJ)
		{
		file.src.Read = 0;
		file.src.Size = GetFileSize(file.src.Hand, NULL);
		file.dst.Read = 0;
		file.dst.Size = file.src.Size;
		file.dst.Size+= sizeof(__header) + sizeof(__block_header)*(1+(file.src.Size/options.Block));

		if (options.Methods &mtBWT)
		file.dst.Size+= BWT_TRASH_BPB(options.Block,options.Dict)*(1+(file.src.Size/options.Block));
		if (options.Methods &mtLZS)
		file.dst.Size+= LZS_TRASH_BPB(options.Block,options.Dict)*(1+(file.src.Size/options.Block));
		if (options.Methods &mtHUF)
		file.dst.Size+= HUF_TRASH_BPB(options.Block)*(1+(file.src.Size/options.Block));
		if (options.Methods &mtARI)
		file.dst.Size+= ARI_TRASH_BPB(options.Block)*(1+(file.src.Size/options.Block));

		file.dst.HandMap = CreateFileMapping(file.dst.Hand, NULL,
													 PAGE_READWRITE|SEC_RESERVE|SEC_NOCACHE,
													 0,sizeof(__header),NULL);
			file.dst.buffer.Lptr = MapViewOfFile(file.dst.HandMap,FILE_MAP_WRITE,0,0,sizeof(__header));
		if (file.dst.buffer.Lptr==NULL)
			{goto ProcedeERRORIO;
			}
		hdr.sig  = HEADER_SIG;
		hdr.size = file.src.Size;
		ptrMov(file.dst.buffer.Lptr,(void*)&hdr,sizeof(__header));
		file.dst.Read += sizeof(__header);
		if (options.Cached==0)
		FlushViewOfFile(file.dst.buffer.Lptr,sizeof(__block_header));
		UnmapViewOfFile(file.dst.buffer.Lptr);
		CloseHandle(file.dst.HandMap);
		//
progress.src.one.Read  = file.src.Read;
progress.src.one.Size  = file.src.Size;
progress.src.all.Read += 0;
progress.dst.one.Read  = file.dst.Read;
progress.dst.one.Size  = file.dst.Size;
progress.dst.all.Read += sizeof(__header);
		}
	else
	if (anaction==opDEKODUJ)
		{
		file.src.Read = 0;
		file.src.Size = GetFileSize(file.src.Hand, NULL);
		file.src.HandMap = CreateFileMapping(file.src.Hand, NULL,
													 PAGE_READONLY|SEC_RESERVE|SEC_NOCACHE,
													 0,sizeof(__header),NULL);
		file.src.buffer.Lptr = MapViewOfFile(file.src.HandMap, FILE_MAP_READ,0,0,sizeof(__header));
		if (file.src.buffer.Lptr==NULL)
			{goto ProcedeERRORIO;
			}
		ptrMov((void*)&hdr,file.src.buffer.Lptr,sizeof(__header));
		file.src.Read += sizeof(__header);
		UnmapViewOfFile(file.src.buffer.Lptr);
		CloseHandle(file.src.HandMap);
		if (hdr.sig!=HEADER_SIG)
			{SetLastError(ERROR_INVALID_DATATYPE);
			 goto ProcedeERRORIO;
			}
		file.dst.Read = 0;
		file.dst.Size = hdr.size;
		//
progress.src.one.Read  = file.src.Read;
progress.src.one.Size  = file.src.Size;
progress.src.all.Read += sizeof(__header);
progress.dst.one.Read  = file.dst.Read;
progress.dst.one.Size  = file.dst.Size;
progress.dst.all.Read += 0;
		}
	//
	if (file.src.Size > options.Cut) file.src.Size = options.Cut; // CUT CUT
	//
					  rootStr[0] = list.dst.Main.Items[aindex]->text[0];
	if (DiskSpace(rootStr,file.dst.Size,list.dst.Main.Items[aindex]->data_size[SIZE],true,false) < 0)
		{options.Stop = true;
		 goto ProcedeERRORIO;
		}
	 // Map Src >>
	if (anaction==opKODUJ || anaction==opDEKODUJ) {
	file.src.HandMap = CreateFileMapping(file.src.Hand, NULL,
									 PAGE_READONLY|SEC_RESERVE|SEC_NOCACHE,
									 0,file.src.Size,NULL);
	if (file.src.HandMap==INVALID_HANDLE_VALUE)
		{goto ProcedeERRORIO;
		}
	 // Map Dst >>
	file.dst.HandMap = CreateFileMapping(file.dst.Hand, NULL,
									 PAGE_READWRITE|SEC_RESERVE|SEC_NOCACHE,
									 0,file.dst.Size,NULL);
	if (file.dst.HandMap==INVALID_HANDLE_VALUE)
		{goto ProcedeERRORIO;
		}
	}
	//
	// START MOVE
	//
	FOnBreak(onPROGRESS,0);
	//
	if (anaction==opKOPIUJ) {
  for (mem_count = 2, mem_read_index = 0, mem_write_index = 0; options.Stop==0 && file.src.Read < file.src.Size;)
		{
		//
		//
		file.src.buffer.Size = file.src.Size - file.src.Read;
	if (file.src.buffer.Size > options.Block)
		file.src.buffer.Size = options.Block;
		file.src.buffer.Offset = 0;
		file.src.buffer.Lptr = ptrAlloc(file.src.buffer.Size);
	if (file.src.buffer.Lptr==NULL)
		{goto ProcedeERRORIO;
		}
		DWORD readed;
	if (!ReadFile(file.src.Hand,file.src.buffer.Lptr,file.src.buffer.Size,&readed,NULL))
	if (file.src.buffer.Size!=readed)
		{goto ProcedeERRORIO;
		}
		mem_buffer[mem_read_index].Lptr = file.src.buffer.Lptr;
		mem_buffer[mem_read_index].Size = file.src.buffer.Size;
		mem_buffer[mem_read_index].Offset = file.src.buffer.Offset;
		file.src.Read += file.src.buffer.Size;
progress.src.all.Read += file.src.buffer.Size;
progress.src.one.Read  = file.src.Read;
progress.src.one.Size  = file.src.Size;
		FOnBreak(onPROGRESS,2);
		//
		// ewentualne operacje na bufferze
		// ...
		DWORD x;
		if (WriteFileThreadHandle==NULL) goto ProcedeERRORIO;
		if (GetExitCodeThread(WriteFileThreadHandle,&x)==0) goto ProcedeERRORIO;
		if (x!=STILL_ACTIVE) goto ProcedeERRORIO; // jesli nie to przerwij natychmiast
	       if (WriteFileThreadControl & 1) SwitchToThread();
		while (WriteFileThreadControl & 1) { Sleep(1); FOnBreak(onPROGRESS,0); } // dopuki system nie zakoñczy poprzedniej procedury zapisu czekaj
		   if (WriteFileThreadControl & 4) {
				goto ProcedeERRORIO; // zapisywanie zakoñczone ale niepoprawnie
			  }
mem_write_index = mem_read_index;
			  if (mem_read_index==mem_count-1) mem_read_index =0;
			 else mem_read_index++;

		WriteFileThreadControl = 1; //startuj kolejny zapis
//      SwitchToThread();
		// doputy czekaj, pusci na jej starcie, a dalej sobie bedzie leciala równolegle,
		// wtedy dokona kolejnego odczytu w kolejnej petli i poczeka na zakoñczenie zapisu po jej zakoczeniu
		// F:\TELEDYSKI

		/*file.dst.buffer.Size = mem_buffer[mem_read_index].Size;
		file.dst.buffer.Offset = file.dst.Read % 65536;
		file.dst.buffer.Lptr = MapViewOfFile(file.dst.HandMap, FILE_MAP_WRITE, 0,
														 file.dst.Read - file.dst.buffer.Offset, file.dst.buffer.Size + file.dst.buffer.Offset);
		if (file.dst.buffer.Lptr==NULL)
			{goto ProcedeERRORIO;
			}
		file.dst.buffer.Lptr =(void*)((ULONG)file.dst.buffer.Lptr + file.dst.buffer.Offset);
		ptrMov(file.dst.buffer.Lptr, mem_buffer[mem_read_index].Lptr,mem_buffer[mem_read_index].Size);
		file.dst.Read += file.dst.buffer.Size;
		ptrFree(mem_buffer[mem_read_index].Lptr);
		if (options.Cached==0)
		FlushViewOfFile(file.dst.buffer.Lptr,file.dst.buffer.Size);
		UnmapViewOfFile((void*)((ULONG)file.dst.buffer.Lptr - file.dst.buffer.Offset));
progress.dst.one.Read  = file.dst.Read;
progress.dst.one.Size  = file.dst.Size;
progress.dst.all.Read += file.dst.buffer.Size;
		 */
		}
	 while (WriteFileThreadControl & 1) { Sleep(1); FOnBreak(onPROGRESS,0); } // dopuki system nie zakoñczy poprzedniej procedury zapisu czekaj
	}
else
	if (anaction==opKODUJ) {
  for	(;options.Stop==0 && file.src.Read < file.src.Size;)
		{
		//
		mem_read_index=0;
		//
		file.src.buffer.Size = file.src.Size -file.src.Read;
  if (file.src.buffer.Size > options.Block) file.src.buffer.Size = options.Block;
		file.src.buffer.Offset = file.src.Read % 65536;
		file.src.buffer.Lptr = MapViewOfFile(file.src.HandMap, FILE_MAP_READ, 0,
														 file.src.Read - file.src.buffer.Offset, file.src.buffer.Size + file.src.buffer.Offset);
		if (file.src.buffer.Lptr==NULL)
			{goto ProcedeERRORIO;
			}
		file.src.buffer.Lptr =(void*)((ULONG)file.src.buffer.Lptr + file.src.buffer.Offset);
		mem_buffer[mem_read_index].Lptr = ptrAlloc(file.src.buffer.Size+1);
		ptrMov(mem_buffer[mem_read_index].Lptr,file.src.buffer.Lptr,file.src.buffer.Size);
		mem_buffer[mem_read_index].Size = file.src.buffer.Size;
		file.src.Read += file.src.buffer.Size;
		UnmapViewOfFile((void*)((ULONG)file.src.buffer.Lptr - file.src.buffer.Offset));
		//
		mem_count=1;
		//
		if (options.Methods & mtBWT) {
		mem_buffer[mem_count].Size = mem_buffer[mem_count-1].Size + BWT_TRASH_BPB(mem_buffer[mem_count-1].Size,options.Dict);
		mem_count++;}
		if (options.Methods & mtLZS) {
		mem_buffer[mem_count].Size = mem_buffer[mem_count-1].Size + LZS_TRASH_BPB(mem_buffer[mem_count-1].Size,options.Dict);
		mem_count++;}
		if (options.Methods & mtHUF) {
		mem_buffer[mem_count].Size = mem_buffer[mem_count-1].Size + HUF_TRASH_BPB(mem_buffer[mem_count-1].Size);
		mem_count++;}
		if (options.Methods & mtARI) {
		mem_buffer[mem_count].Size = mem_buffer[mem_count-1].Size + ARI_TRASH_BPB(mem_buffer[mem_count-1].Size);
		mem_count++;}
		//
		// transformacja Burrowsa-Wheelra
		if (options.Methods & mtBWT)
			{mem_buffer[mem_read_index+1].Lptr = ptrAlloc(mem_buffer[mem_read_index+1].Size+1);
			 mem_buffer[mem_read_index+1].Size = Compress_BWT(mem_buffer[mem_read_index+1].Lptr,mem_buffer[mem_read_index].Lptr,mem_buffer[mem_read_index].Size,options.Dict);
			 ptrFree(mem_buffer[mem_read_index].Lptr);
			 mem_read_index++;
			}
		// kompresja LZS
		if (options.Methods & mtLZS)
			{mem_buffer[mem_read_index+1].Lptr = ptrAlloc(mem_buffer[mem_read_index+1].Size+1);
			 mem_buffer[mem_read_index+1].Size = Compress_LZS(mem_buffer[mem_read_index+1].Lptr,mem_buffer[mem_read_index].Lptr,mem_buffer[mem_read_index].Size,options.Dict);
			 ptrFree(mem_buffer[mem_read_index].Lptr);
			 mem_read_index++;
			}
		// kodowanie MTF
		if (options.Methods & mtMTF)
			{Cript_MTF(mem_buffer[mem_read_index].Lptr,mem_buffer[mem_read_index].Size);
			}
		// kompresja HUFFMANA
		if (options.Methods & mtHUF)
			{mem_buffer[mem_read_index+1].Lptr = ptrAlloc(mem_buffer[mem_read_index+1].Size+1);
			 mem_buffer[mem_read_index+1].Size = Compress_HUF(mem_buffer[mem_read_index+1].Lptr,mem_buffer[mem_read_index].Lptr,mem_buffer[mem_read_index].Size,options.Dict);
			 ptrFree(mem_buffer[mem_read_index].Lptr);
			 mem_read_index++;
			}
		// kompresja ARYTMETYCZNA
		if (options.Methods & mtARI)
			{mem_buffer[mem_read_index+1].Lptr = ptrAlloc(mem_buffer[mem_read_index+1].Size+1);
			 mem_buffer[mem_read_index+1].Size = Compress_ARI(mem_buffer[mem_read_index+1].Lptr,mem_buffer[mem_read_index].Lptr,mem_buffer[mem_read_index].Size,options.Dict);
			 ptrFree(mem_buffer[mem_read_index].Lptr);
			 mem_read_index++;
			}
		// QDRowanie
		if (options.Methods & mtSXQ)
			{Cript_SXQ(mem_buffer[mem_read_index].Lptr,mem_buffer[mem_read_index].Size,GetPasswordSize());
			}
		// Xorowanie
		if (options.Methods & mtXOR)
			{Cript_XOR(mem_buffer[mem_read_index].Lptr,mem_buffer[mem_read_index].Size,password.FEnc,GetPasswordSize());
			}
		if (options.Methods & mtCRC)
			{b_hdr.crc32 = Calc_CRC32(mem_buffer[mem_read_index].Lptr,mem_buffer[mem_read_index].Size);
			}
		// naglowek
					  // dalszy fragment mo¿na przeniesc do innego Thread   analogicznie jak kopiowanie pliku
		file.dst.buffer.Size = mem_buffer[mem_read_index].Size;
		file.dst.buffer.Offset = file.dst.Read % 65536;
		file.dst.buffer.Lptr = MapViewOfFile(file.dst.HandMap, FILE_MAP_WRITE, 0,
														 file.dst.Read - file.dst.buffer.Offset,sizeof(__block_header) + file.dst.buffer.Size + file.dst.buffer.Offset);
		if (file.dst.buffer.Lptr==NULL)
			{goto ProcedeERRORIO;
			}
		file.dst.buffer.Lptr =(void*)((ULONG)file.dst.buffer.Lptr + file.dst.buffer.Offset);
		ptrSet((void*)&b_hdr.size,sizeof(b_hdr.size),0);
		b_hdr.sig = BLOCK_HEADER_SIG;
		b_hdr.methods = options.Methods;
		for (__int8 i=0;i < mem_count; i++)
			 {b_hdr.size[i] =mem_buffer[i].Size;
			 }
		b_hdr.range = file.src.Read;
		ptrMov((void*)file.dst.buffer.Lptr,(void*)&b_hdr,sizeof(__block_header));
		file.dst.Read += sizeof(__block_header);
		ptrMov((void*)((ULONG)file.dst.buffer.Lptr+sizeof(__block_header)),mem_buffer[mem_read_index].Lptr,mem_buffer[mem_read_index].Size);
		file.dst.Read += file.dst.buffer.Size;
		ptrFree(mem_buffer[mem_read_index].Lptr);
		if (options.Cached==0)
		FlushViewOfFile(file.dst.buffer.Lptr,file.dst.buffer.Size+sizeof(__block_header));
		UnmapViewOfFile((void*)((ULONG)file.dst.buffer.Lptr-file.dst.buffer.Offset));

progress.src.one.Read  = file.src.Read;
progress.src.one.Size  = file.src.Size;
progress.src.all.Read += file.src.buffer.Size;
progress.dst.one.Read  = file.dst.Read;
progress.dst.one.Size  = file.dst.Size;
progress.dst.all.Read += file.dst.buffer.Size;
progress.dst.all.Read += sizeof(__block_header);

		FOnBreak(onPROGRESS,0);
		}
	}
else
	if (anaction==opDEKODUJ) {
  for (;options.Stop==0 && file.src.Read < file.src.Size;)
		{
		// naglowek
		file.src.buffer.Size = sizeof(__block_header);
		file.src.buffer.Offset = file.src.Read % 65536;
		file.src.buffer.Lptr = MapViewOfFile(file.src.HandMap, FILE_MAP_READ, 0,
														 file.src.Read - file.src.buffer.Offset,sizeof(__block_header) + file.src.buffer.Offset);
		file.src.buffer.Lptr =(void*)((ULONG)file.src.buffer.Lptr + file.src.buffer.Offset);
		ptrMov((void*)&b_hdr,file.src.buffer.Lptr,sizeof(__block_header));
		file.src.Read += sizeof(__block_header);
		mem_count=1;
		//
		if (b_hdr.methods & mtARI)
		mem_count++;
		if (b_hdr.methods & mtHUF)
		mem_count++;
		if (b_hdr.methods & mtLZS)
		mem_count++;
		if (b_hdr.methods & mtBWT)
		mem_count++;
		for (__int8 i=0;i < mem_count; i++)
			 {mem_buffer[i].Size = b_hdr.size[i];
			 }
		UnmapViewOfFile((void*)((ULONG)file.src.buffer.Lptr - file.src.buffer.Offset));
		if (b_hdr.sig!=BLOCK_HEADER_SIG)
			{SetLastError(ERROR_INVALID_DATATYPE);
			 goto ProcedeERRORIO;
			}
		//
		mem_read_index = mem_count-1;
		//
		file.src.buffer.Size = mem_buffer[mem_read_index].Size;
		file.src.buffer.Offset = file.src.Read % 65536;
		file.src.buffer.Lptr = MapViewOfFile(file.src.HandMap, FILE_MAP_READ, 0,
														 file.src.Read - file.src.buffer.Offset, file.src.buffer.Size + file.src.buffer.Offset);
		if (file.src.buffer.Lptr==NULL)
			{goto ProcedeERRORIO;
			}
		file.src.buffer.Lptr =(void*)((ULONG)file.src.buffer.Lptr + file.src.buffer.Offset);
		mem_buffer[mem_read_index].Lptr = ptrAlloc(mem_buffer[mem_read_index].Size+1);
		ptrMov(mem_buffer[mem_read_index].Lptr,file.src.buffer.Lptr,file.src.buffer.Size);
		file.src.Read += file.src.buffer.Size;
		UnmapViewOfFile((void*)((ULONG)file.src.buffer.Lptr - file.src.buffer.Offset));

		if (b_hdr.methods & mtCRC)
		if (b_hdr.crc32!=Calc_CRC32(mem_buffer[mem_read_index].Lptr,mem_buffer[mem_read_index].Size))
			{SetLastError(ERROR_CRC);
			 goto ProcedeERRORIO;
			}
		// DEXORowanie
		if (b_hdr.methods & mtXOR)
			{UnCript_XOR(mem_buffer[mem_read_index].Lptr,mem_buffer[mem_read_index].Size,password.FEnc,GetPasswordSize());
			}
		// DEQDRowanie
		if (b_hdr.methods & mtSXQ)
			{UnCript_SXQ(mem_buffer[mem_read_index].Lptr,mem_buffer[mem_read_index].Size,GetPasswordSize());
			}
		// DEkompresja ARI
		if (b_hdr.methods & mtARI)
			{mem_buffer[mem_read_index-1].Lptr = ptrAlloc(mem_buffer[mem_read_index-1].Size+1);
			 UnCompress_ARI(mem_buffer[mem_read_index-1].Lptr,mem_buffer[mem_read_index-1].Size,mem_buffer[mem_read_index].Lptr);
			 ptrFree(mem_buffer[mem_read_index].Lptr);
			 mem_read_index--;
			 }
		// DEkompresja HUF
		if (b_hdr.methods & mtHUF)
			{mem_buffer[mem_read_index-1].Lptr = ptrAlloc(mem_buffer[mem_read_index-1].Size+1);
			 UnCompress_HUF(mem_buffer[mem_read_index-1].Lptr,mem_buffer[mem_read_index-1].Size,mem_buffer[mem_read_index].Lptr);
			 ptrFree(mem_buffer[mem_read_index].Lptr);
			 mem_read_index--;
			 }
		// DEkodowanie MTF
		if (b_hdr.methods & mtMTF)
			{UnCript_MTF(mem_buffer[mem_read_index].Lptr,mem_buffer[mem_read_index].Size);
			}
		// DEkompresja LZS
		if (b_hdr.methods & mtLZS)
			{mem_buffer[mem_read_index-1].Lptr = ptrAlloc(mem_buffer[mem_read_index-1].Size+1);
			 UnCompress_LZS(mem_buffer[mem_read_index-1].Lptr,mem_buffer[mem_read_index-1].Size,mem_buffer[mem_read_index].Lptr);
			 ptrFree(mem_buffer[mem_read_index].Lptr);
			 mem_read_index--;
			 }
		// DEkompresja Burrowsa-Wheelra
		if (b_hdr.methods & mtBWT)
			{mem_buffer[mem_read_index-1].Lptr = ptrAlloc(mem_buffer[mem_read_index-1].Size+1);
			 UnCompress_BWT(mem_buffer[mem_read_index-1].Lptr,mem_buffer[mem_read_index-1].Size,mem_buffer[mem_read_index].Lptr);
			 ptrFree(mem_buffer[mem_read_index].Lptr);
			 mem_read_index--;
			}
		file.dst.buffer.Size = mem_buffer[mem_read_index].Size;
		file.dst.buffer.Offset = file.dst.Read % 65536;
		file.dst.buffer.Lptr = MapViewOfFile(file.dst.HandMap, FILE_MAP_WRITE, 0,
														 file.dst.Read - file.dst.buffer.Offset, file.dst.buffer.Size + file.dst.buffer.Offset);
		if (file.dst.buffer.Lptr==NULL)
			{goto ProcedeERRORIO;
			}
		file.dst.buffer.Lptr =(void*)((ULONG)file.dst.buffer.Lptr + file.dst.buffer.Offset);
		ptrMov(file.dst.buffer.Lptr,mem_buffer[mem_read_index].Lptr,mem_buffer[mem_read_index].Size);
		ptrFree(mem_buffer[mem_read_index].Lptr);
		if (options.Cached==0)
		FlushViewOfFile(file.dst.buffer.Lptr,file.dst.buffer.Size);
		UnmapViewOfFile((void*)((ULONG)file.dst.buffer.Lptr - file.dst.buffer.Offset));
		file.dst.Read += file.dst.buffer.Size;

progress.src.one.Read  = file.src.Read;
progress.src.one.Size  = file.src.Size;
progress.src.all.Read += file.src.buffer.Size;
progress.src.all.Read += sizeof(__block_header);
progress.dst.one.Read  = file.dst.Read;
progress.dst.one.Size  = file.dst.Size;
progress.dst.all.Read += file.dst.buffer.Size;

		FOnBreak(onPROGRESS,0);
		}
	}
//------------------------------------------
	ProcedeOKIO:
//------------------------------------------
	while (WriteFileThreadControl & 1) { Sleep(1); FOnBreak(onPROGRESS,0); } // dopuki system nie zakoñczy poprzedniej procedury zapisu czekaj
	WriteFileThreadControl = 0;
	if (anaction==opKODUJ || anaction==opDEKODUJ) {
		CloseHandle(file.src.HandMap);
		CloseHandle(file.dst.HandMap);
	}
	 SetFilePointer(file.dst.Hand, file.dst.Read, 0, FILE_BEGIN);
	   SetEndOfFile(file.dst.Hand);
		CloseHandle(file.src.Hand);
		CloseHandle(file.dst.Hand);

		if (file.src.Read < file.src.Size)
			{SetFileAttributes(list.dst.Main.Items[aindex]->text,FILE_ATTRIBUTE_NORMAL);
			 DeleteFile(list.dst.Main.Items[aindex]->text);
			}
		return 1;
//------------------------------------------
	ProcedeERRORIO:
//------------------------------------------
	while (WriteFileThreadControl & 1) { Sleep(1); FOnBreak(onPROGRESS,0); } // dopuki system nie zakoñczy poprzedniej procedury zapisu czekaj
	WriteFileThreadControl = 0;
	if (anaction==opKODUJ || anaction==opDEKODUJ) {
		if (file.src.HandMap!=INVALID_HANDLE_VALUE)
			 CloseHandle(file.src.HandMap);
		if (file.dst.HandMap!=INVALID_HANDLE_VALUE)
			 CloseHandle(file.dst.HandMap);
	}
		if (file.src.Hand!=INVALID_HANDLE_VALUE)
			 CloseHandle(file.src.Hand);
		if (file.dst.Hand!=INVALID_HANDLE_VALUE)
			 CloseHandle(file.dst.Hand);

		if (file.dst.Hand!=INVALID_HANDLE_VALUE)
			{SetFileAttributes(list.dst.Main.Items[aindex]->text,FILE_ATTRIBUTE_NORMAL);
			 DeleteFile(list.dst.Main.Items[aindex]->text);
			}

progress.src.all.Read -= progress.src.one.Read;
progress.src.all.Size -= progress.src.one.Size;
progress.src.one.Read  = 0;
progress.src.one.Size  = 1;
progress.dst.all.Read -= progress.dst.one.Read;
progress.dst.all.Size -= progress.dst.one.Size;
progress.dst.one.Read  = 0;
progress.dst.one.Size  = 1;

		FOnBreak(onPROGRESS,0);
		return 0;
//------------------------------------------
	}
return 1;
}
//---------------------------------------------------------------------------

__int64 __stdcall TSoft::Kop32::DiskSpace(char *avolumin, __int64 abajtSrc, __int64 abajtDst, bool auntilPositive, bool acouldIgnore) {
ULARGE_INTEGER diskCallUInt;
FOnBreak(onFREESPACE_QUEST,0);
int ret;
//
for (;::GetDiskFreeSpaceEx(avolumin,&diskCallUInt,NULL,NULL);)
	 {
	 if (__int64(diskCallUInt.QuadPart+abajtDst) > __int64(abajtSrc)) return diskCallUInt.QuadPart+abajtDst;
	 else
	 if (options.Error==anNO)
		  return -1;
	 else
	 if (options.Error==anALL && acouldIgnore==true)
		  return +0;
	 else
	 if (auntilPositive==false)
		  return -1;
	 else
	 if (acouldIgnore==true) ret=FOnError(ERROR_DISK_FULL,MB_ABORTRETRYIGNORE);
	 else
		  ret =FOnError(ERROR_DISK_FULL,MB_RETRYCANCEL);

	 if (ret==IDRETRY)
		  continue;
	 else
	 if (ret==IDIGNORE)
		  return +0;

	 SetLastError(ERROR_DISK_FULL);
	 return -1;
	 }
	 return  diskCallUInt.QuadPart+abajtDst;
}
//---------------------------------------------------------------------------

int __stdcall TSoft::Kop32::FOnError(int aCode,int aParam)
{
if (!OnError) return DoError(aCode,aParam);
else
	 return OnError(aCode,aParam);
}
//--------------------------------------------------------------------------

int __stdcall TSoft::Kop32::DoError(int aCode,int aParam) {
static char lpmsgText[128];

FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM,
			NULL,aCode,
			MAKELANGID(LANG_NEUTRAL,SUBLANG_DEFAULT),
			&lpmsgText[0], sizeof(lpmsgText),
			NULL);

if (options.Operation==opUSUN)
return MessageBox(NULL,lpmsgText,
			"Kop32 - error",
			aParam|MB_DEFBUTTON1|MB_ICONERROR|MB_SYSTEMMODAL);
else
if (options.Operation==opLISTUJ)
return MessageBox(NULL,lpmsgText,
			"Kop32 - error",
			aParam|MB_DEFBUTTON1|MB_ICONERROR|MB_SYSTEMMODAL);
else
return MessageBox(NULL,lpmsgText,
			"Kop32 - error",
			aParam|MB_DEFBUTTON1|MB_ICONERROR|MB_SYSTEMMODAL);
}
//---------------------------------------------------------------------------

int __stdcall TSoft::Kop32::FOnBreak(int aCode,int aParam)
{
if (!OnBreak) return DoBreak(aCode,aParam);
else
	 return OnBreak(aCode,aParam);
}
//---------------------------------------------------------------------------

int __stdcall TSoft::Kop32::DoBreak(int aCode,int aParam) {
static char lpmsgText[128];

if (options.Operation==opLISTUJ) {
strMov(lpmsgText,options.Masks.Text[COMMA]);
strAdd(lpmsgText," from \"");
strAdd(lpmsgText,list.src.Init.Text[LINES]);
strAdd(lpmsgText,"\" to file \"");
strAdd(lpmsgText,list.dst.Init.Text[LINES]);
strAdd(lpmsgText,"\"");
}
else
if (options.Operation==opUSUN) {
strMov(lpmsgText,options.Masks.Text[COMMA]);
strAdd(lpmsgText," from \"");
strAdd(lpmsgText,list.src.Init.Text[LINES]);
strAdd(lpmsgText,"\"");
}
else {
strMov(lpmsgText,options.Masks.Text[COMMA]);
strAdd(lpmsgText," form \"");
strAdd(lpmsgText,list.src.Init.Text[LINES]);
strAdd(lpmsgText,"\" to \"");
strAdd(lpmsgText,list.dst.Init.Text[LINES]);
strAdd(lpmsgText,"\"");
}

switch (aCode) {

case onREPLACE_QUEST:
return MessageBox(NULL,lpmsgText,
			"Kop32 - Do replace?",
			aParam|MB_DEFBUTTON1|MB_ICONQUESTION);
case onQUEST:
if (options.Operation==opKOPIUJ)
return MessageBox(NULL,lpmsgText,
			"Kop32 - Do copy?",
			aParam|MB_DEFBUTTON1|MB_ICONQUESTION);
else
if (options.Operation==opKODUJ)
return MessageBox(NULL,lpmsgText,
			"Kop32 - Do encode?",
			aParam|MB_DEFBUTTON1|MB_ICONQUESTION);
else
if (options.Operation==opDEKODUJ)
return MessageBox(NULL,lpmsgText,
			"Kop32 - Do dencode?",
			aParam|MB_DEFBUTTON1|MB_ICONQUESTION);
else
if (options.Operation==opPRZENIES)
return MessageBox(NULL,lpmsgText,
			"Kop32 - Do move?",
			aParam|MB_DEFBUTTON1|MB_ICONQUESTION);
else
if (options.Operation==opLISTUJ)
return MessageBox(NULL,lpmsgText,
			"Kop32 - Do list?",
			aParam|MB_DEFBUTTON1|MB_ICONQUESTION);
else
if (options.Operation==opUSUN)
return MessageBox(NULL,lpmsgText,
			"Kop32 - Do delete?",
			aParam|MB_DEFBUTTON1|MB_ICONQUESTION);
break;
}
return mrNo;
}
//---------------------------------------------------------------------------
