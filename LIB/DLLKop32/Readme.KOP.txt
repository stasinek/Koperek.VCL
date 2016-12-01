Readme(void)
{

""C:\BlaBla\Koperek" /o... /buforsize(1024) /argts(blabla;[nazwa];[rozmiar];[atrybuty];[data]) /maska(*.txt;*.blabla;jeszczjedno.blabla) /kopiuj /przenies /usun /koduj /dekoduj /listuj /jakreaguj(quest) "c:\Katalog docelowy"" 

/kopiuj - kopiowanie plikow(katalogow) o nazwach znajduj¹cych siê w schowku do "Katalog docelowy"
          np. uruchomienie "Koperek.exe /kopiuj d:\smieci" spowoduje skopiowanie nazw w showku do d:\smieci

/przenies - przeniesienie plikow(katalogow) o nazwach znajduj¹cych siê w schowku do "Katalog docelowy"
            np. uruchomienie "Koperek.exe /przenies d:\smieci" spowoduje przeniesienie nazw w showku do d:\smieci

/koduj - szyfrowanie nazw(y) plikow(katalogow) o nazwach znajduj¹cych siê w schowku do "Katalog docelowy"
         np. uruchomienie "Koperek.exe /przenies d:\smieci" spowoduje przeniesienie nazw w showku do d:\smieci

/dekoduj - deszyfrowanie nazw(y) plikow(katalogow) znajduj¹cych siê w schowku do "Katalog docelowy"
           np. uruchomienie "Koperek.exe /przenies d:\smieci" spowoduje przeniesienie nazw w showku do d:\smieci

/listuj - umieszczenie w schowku jesli docel = "Clipboard:" lub w pliku docel listy plików i katalogów w "C:\katalog zrodlowy"
          np. uruchomienie "Koperek.exe /listuj d:\log.txt" spowoduje zlistowanie katalogu z nazw¹ umieszczon¹ w schowku do logu w pliku lub schowku

Jako "plik" docelowy listy mo¿na wpisaæ "clipboard:" spowoduje to listowanie do schowka

/usun - Usuniecie "Katalog docelowy"
        Uruchomienie "Koperek.exe /usun d:\smieci" spowoduje usuniêcie d:\smieci

/cutiffilesize(x) - gdzie x to liczba bajtów, od jakiej zostanie skrócony plik 

/cuttofilesize(x) - gdzie x to liczba bajtów, do jakiej zostanie skrócony plik 

/buforsize(x) - gdzie x to liczba Kbajtów, zmiana bufora plikowego na wartosc np x "/buforsize(x) (domyœlna w programie to 64KB) 

/jakreaguj(tak) - potwierdzaj na wszystkie pytania

/jakreaguj(nie) - zaprzeczaj na wszystkie pytania

/jakreaguj(quest) - pytaj usera o odpowiedx

/maska(maska1;maska2;maskaN) - wykonuje operacje na plikach o nazwach
                               spelnaiaj¹cych warunek nazwa pasuje do maska1 || maska2 || maskaN

/argts(jeden;drugi;[nazwa];[rozmiar];[atrybuty]) - parametry lini listowania gdzie [nazwa];[rozmiar];[atrybut] to nazwa kolejnego pliku itp, sta³e bêd¹ poprostu przepisane

/o... okno About (czy to jeszcze dzie³a?)

nie aktywne /przegladaj - przgl¹dnie struktury rozmiarowej katalogów (kiedyœ by³o i to fajne ale nie ma, trzeba do³¹czyæ istniej¹ce ¿ród³o i zadzia³a gdyby ktoœ chcia³ mi to zleciæ)
 
/zaznacz - np. uruchomienie "Koperek.exe /zaznacz  "C:\Windows" "c:\temp" "C:\autoexec.bat" spowoduje przeniesienie nazw w showku do d:\smieci
           spowoduje skopiowanie do schowka takiego String'a 

Program napisany przez Stanis³aw Stasiak "TSoft, where?"(do you want to superfreak today?) (R) 2000-2002
w C++Builder 3 licencjonowanego na RoSt 2002 (R)

return Zadowolenie;
}

(dla u³atwienia) Szyforwanie jest oparte na trzech metodach :

1. ExOrowanie 
2. NQuadrowanie
3. Over4Space

w przypadku wpisania niew³aœciwego has³a do dekodowania niechybnie czeka AccessViolation