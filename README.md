#dclusr50.VCL

Application uses non standard controls.
Before you start put content of dclusr50.VCL repo into ./SRC/OBSOLETE/PACKAGES
Application repo (.VCL) into ./SRC/OBSOLETE/PROG/Koperek.VCL
Forms repo -> ./SRC/OBSOLETE/PROG/FORM_TEMPLATES/
Libraries -> ./SRC/X86_LIBRARIES/
Classes.VCL repo -> ./SRC/X86_WIN32_CLASSES/

Before you open project, you must compile/install user package and install into your IDE toolbox, 
then open and compile application. Otherwise IDE will ask you about missing .bpl library

# Koperek_VCL

""C:\Koperek.exe" /o... /bufor{1024} /argts{blabla;#file;#size;#attr;#path} /maska{*.txt,*.blabla,another mask.blabla} /copy /move /delete /code /decode /list /break{q} "c:\Destination directory"" 

/copy
copying files (directories) with names in the clipboard to "Destination directory"
e.g. running "Koperek.exe /copy d:\junk" will copy files to d:\junk

/move
moving files (directories) with names in the clipboard to "Target directory"
e.g. running "Dill.exe /move d:\junk" will move to d:\junk

/encode
encrypting files (directories) with names in the clipboard to "Target directory"
e.g. running "Dill.exe /encode d:\junk" will encode to d:\junk

/decode
decryption of files (directories) in the clipboard to "Target directory"
e.g. running "Dill.exe /decode d:\junk" will take you to d:\junk

/list
put in clipboard if destination = "Clipboard:" or in filelist file from "C:\source directory"
e.g. running "Koperek.exe /list d:\log.txt" will list the directory to the log in the file d:\log.txt

/delete
Delete "Target Directory"
Running "Dill.exe /remove d:\junk" will delete d:\junk

/cutsize{x}
where x is the number of bytes from which the file will be shortened

/buffer{x}
where x is the number of Kbytes, file buffer change
(default in the program is 64KB)

/break{?}
t = confirm to all questions
n = deny all questions
q = ask user for answer

/mask{mask1,mask2,maskN}
performs operations on files with names satisfying the condition name matches mask1 || mask2 || maskN
there is no black list mask implemented YET

/argts{one,second,...#}
enables you to format list line by line 
using directives: #file, #path, #size, #attr are the name of the next file, directory, size, attributes. One, the other - the constants will simply be rewritten

/o...
program information window

/select
e.g. running "Koperek.exe /select "C:\Windows" "c:\temp" "C:\autoexec.bat" will create a list of these files in the clipboard needed to perform the operation specified in the next call

/dict{x}
where x is the number of bytes, resizing the LZ77 compression dictionary
(default in the program is 4KB)

Program written by Stanis³aw Stasiak "TSoft, where?" (R) 2000-2002 in C++Builder 3 licensed under RoSt 2002 (R)

Encryption is based on the most basic methods: EXORing, QDRing (row->collumns)
Compression is based on the methods: LZ77 simmilar to used NTFS,RLE,BWT,MTF,HUF,ARI

If you enter the wrong password for decoding, AccessViolation will inevitably occur there is no error handling on this part