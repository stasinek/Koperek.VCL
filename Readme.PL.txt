""C:\Koperek" /o... /bufor{1024} /argts{blabla;#file;#size;#attr;#path} /maska{*.txt,*.blabla,jeszcze.blabla} /kopiuj /przenies /usun /koduj /dekoduj /listuj /break{q} "c:\Katalog docelowy"" 

/kopiuj
kopiowanie plikow(katalogow) o nazwach znajduj�cych si� w schowku do "Katalog docelowy"
np. uruchomienie "Koperek.exe /kopiuj d:\smieci" spowoduje skopiowanie plik�w do d:\smieci

/przenies
przeniesienie plikow(katalogow) o nazwach znajduj�cych si� w schowku do "Katalog docelowy"
np. uruchomienie "Koperek.exe /przenies d:\smieci" spowoduje przeniesienie do d:\smieci

/koduj
szyfrowanie plikow(katalogow) o nazwach znajduj�cych si� w schowku do "Katalog docelowy"
np. uruchomienie "Koperek.exe /koduj d:\smieci" spowoduje zakodowanie do d:\smieci

/dekoduj
deszyfrowanie plikow(katalogow) znajduj�cych si� w schowku do "Katalog docelowy"
np. uruchomienie "Koperek.exe /dekoduj d:\smieci" spowoduje przeniesienie do d:\smieci

/listuj
umieszczenie w schowku jesli docel = "Clipboard:" lub w pliku listy plik�w z "C:\katalog zrodlowy"
np. uruchomienie "Koperek.exe /listuj d:\log.txt" spowoduje zlistowanie katalogu do logu w pliku d:\log.txt

/usun
Usuniecie "Katalog docelowy"
Uruchomienie "Koperek.exe /usun d:\smieci" spowoduje usuni�cie d:\smieci

/cutsize{x}
gdzie x to liczba bajt�w, od jakiej zostanie skr�cony plik 

/bufor{x}
gdzie x to liczba Kbajt�w, zmiana bufora plikowego
(domy�lna w programie to 64KB) 

/break{?}
t = potwierdzaj na wszystkie pytania
n = zaprzeczaj na wszystkie pytania
q = pytaj usera o odpowied�

/maska{maska1,maska2,maskaN}
wykonuje operacje na plikach o nazwach spelnaiaj�cych warunek nazwa pasuje do maska1 || maska2 || maskaN

/argts{jeden,drugi,...#}
parametry lini listowania gdzie dyrektywy: #file, #path, #size, #attr to nazwa kolejnego pliku, katalogu, rozmiaru, atrybut�w. Jeden, drugi - sta�e b�d� poprostu przepisane

/o...
okno informacji o programie

/zaznacz
np. uruchomienie "Koperek.exe /zaznacz  "C:\Windows" "c:\temp" "C:\autoexec.bat" spowoduje utworzenie w schowku listy tych plik�w potrzebnej do wykonania okre�lonej w nast�pnym wywo�aniu operacji 

/dict{x}
gdzie x to liczba bajt�w, zmiana rozmiaru s�ownika kompresji LZ77 
(domy�lna w programie to 4KB) 

Program napisany przez Stanis�aw Stasiak "TSoft, where?"(do you want to superfreak today?) (R) 2000-2002
w C++Builder 3 licencjonowanego na RoSt 2002 (R)

Szyforwanie jest oparte na metodach:
EXOrowanie, QDRowanie
Kompresja jest oparta na metodach:
LZ77,RLE,BWT,MTF

w przypadku wpisania niew�a�ciwego has�a do dekodowania niechybnie czeka AccessViolation