Program do operacji plikowych zamiennik funkcji kopiowania, przenoszenia i usuwania z explorera systemu windows.

Nie gwarantuje ¿e jest dobry ani nawet ¿e to stabilna kompilacja,
pobierasz i u¿ywasz na w³asn¹ odpowiedzialnoœæ.
Wersja 1.0 to w zasadzie jedyna jak¹ obecnie dysponuje przed drastycznymi zmianami w kodzie Ÿród³owym, ka¿da kolejna od 2.0 jest bli¿sza w akcie tworzenia jêzykowi C, proces migracji do œrodowiska Visual Studio 2003 oraz przede wszystkim nie ma graficznych okienek poniewa¿ skupia³em siê na algorytmach kompresji,
W kolejnej ods³ownie planowane jest stworzenie GUI na bazie html i innych socketowych códów.
Jeœli potrzebujesz drobnych kosmetycznych zmian bo program spe³nia oczekiwania, napisz to jest ³atwe w realizacji, mam nadzieje utrzymywaæ wersje 1.0 przy ¿yciu i kto wie mo¿e nawet z czasem uzupe³niæ o wprowadzone zmiany funkcjonalne.

Ultracopier, Copy Handler, Turbocopy to przekombinowane programy mój rodzima produkcja odpowiedŸ na powolne kopiowanie w Win98 oraz 2k, napisany w licencjonowanym œrodowisku Borland BCB 3, okno potwierdzania kopiowañ pixel w pixel z windowsowym oknem(¿eby nie wprowadzaæ zamieszania) Jeœli jest zapotrzebowanie to nowy kombaj do zbierania kur po wioskach powstanie wkrótce.
Ma opcje pauzowania i wylicza czas lepiej ni¿ microsoftowe potworki, konfigurowalny poprzez parametry uruchomieniowe, potrafi kopiowaæ, przenosiæ, usuwaæ, kompresowaæ(format zbli¿ony do kompresji NTFS) i szyfrowaæ do plików .eno(encoded) 

INSTALACJA:
Skopiuj pliki programu do katalogu C:\Program Files\Kop32 lub wypakuj archiwum jeœli nim dysponujesz do Program Files(archiwum ma ju¿ w strukturze podkatalog Kop32).

Otwórz plik KOP_REG.reg (polecenie scal) i po zapytaniu systemu dodaj treœæ do rejestru
aby deinstalowaæ wpisy uruchom KOP_UNINSTALL_REG.reg i "dodaj" treœæ do rejestu.

Powinny pojawiæ siê wpisy w menu prawokliku explorera dla plików katalogów i dysków o treœci np. sstsoft->Kop32->ZAZNACZ
co powoduje skopiowanie nazwy katalogu do schowka albo sstsoft->Kop32->LISTUJ co spowoduje pokazanie okna i proœbe o dodanie listy plików w podkatalogu do schowka zgodnie z wybranym wzorcem.

Jeœli nie chcesz mieszaæ w rejestrze utwórz skróty w Wyœlij do.
Mo¿esz zmieniæ ikone dla ka¿dego z poleceñ program ma ich kilka wbudowane w .exe
Wiesz jak to zrobiæ?
Jeœli nie pisz sstsoft@wp.pl

""C:\Koperek" /o... /BUFOR{1024} /ARGTS{blabla;#file;#size;#attr;#path} /MASKA{*.txt,*.blabla,jeszcze.blabla} /KOPIUJ /PRZENIES /USUN /KODUJ /DEKODUJ /listuj /BREAK{q} "c:\Katalog docelowy"" 

/KOPIUJ
kopiowanie plikow(katalogow) o nazwach znajduj¹cych siê w schowku do "Katalog docelowy"
np. uruchomienie "Koperek.exe /KOPIUJ d:\smieci" spowoduje skopiowanie plików do d:\smieci

/PRZENIES
przeniesienie plikow(katalogow) o nazwach znajduj¹cych siê w schowku do "Katalog docelowy"
np. uruchomienie "Koperek.exe /PRZENIES d:\smieci" spowoduje przeniesienie do d:\smieci

/KODUJ
szyfrowanie plikow(katalogow) o nazwach znajduj¹cych siê w schowku do "Katalog docelowy"
np. uruchomienie "Koperek.exe /KODUJ d:\smieci" spowoduje zakodowanie do d:\smieci

/DEKODUJ
deszyfrowanie plikow(katalogow) znajduj¹cych siê w schowku do "Katalog docelowy"
np. uruchomienie "Koperek.exe /DEKODUJ d:\smieci" spowoduje przeniesienie do d:\smieci

/LISTUJ
umieszczenie w schowku jesli docel = "Clipboard:" lub w pliku listy plików z "C:\katalog zrodlowy"
np. uruchomienie "Koperek.exe /listuj d:\log.txt" spowoduje zlistowanie katalogu do logu w pliku d:\log.txt

/USUN
Usuniecie "Katalog docelowy"
Uruchomienie "Koperek.exe /USUN d:\smieci" spowoduje usuniêcie d:\smieci

/TNIJ{x}
gdzie x to liczba bajtów, od jakiej zostanie skrócony plik 

/BUFOR{x}
gdzie x to liczba Kbajtów, zmiana bufora plikowego
(domyœlna w programie to 64KB) 

/BREAK{?}
t = potwierdzaj na wszystkie pytania
n = zaprzeczaj na wszystkie pytania
q = pytaj usera o odpowiedŸ

/MASKA{maska1,maska2,maskaN}
wykonuje operacje na plikach o nazwach spelnaiaj¹cych warunek nazwa pasuje do maska1 || maska2 || maskaN

/ARGTS{jeden,drugi,...#}
parametry lini listowania gdzie dyrektywy: #file, #path, #size, #attr to nazwa kolejnego pliku, katalogu, rozmiaru, atrybutów. Jeden, drugi - sta³e bêd¹ poprostu przepisane

/o...
okno informacji o programie

/ZAZNACZ
np. uruchomienie "Koperek.exe /ZAZNACZ  "C:\Windows" "c:\temp" "C:\autoexec.bat" spowoduje utworzenie w schowku listy tych plików potrzebnej do wykonania okreœlonej w nastêpnym wywo³aniu operacji 

/SLOWNIK{x}
gdzie x to liczba bajtów, zmiana rozmiaru s³ownika kompresji LZ77 
(domyœlna w programie to 4KB) 

Szyforwanie jest oparte na metodach:
EXOrowanie, QDRowanie
Kompresja jest oparta na metodach:
LZ77,RLE,BWT,MTF

w przypadku wpisania niew³aœciwego has³a do dekodowania niechybnie czeka AccessViolation

http://goo.gl/596Ui - Readme
Archiwum SFX Kop32.exe - http://goo.gl/khYmE
http://goo.gl/fbtNY - Instalator
Deinstalator wpisów - http://goo.gl/m9sfb

INNE

https://dl.dropboxusercontent.com/u/10755180/START.html