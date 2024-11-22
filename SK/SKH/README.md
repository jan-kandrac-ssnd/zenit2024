# Úloha SK-H

Odkaz na úlohu nájdeš tu: https://zenit.ksp.sk/task/zenit24skh

Celé znenie zadania nájdeš na konci tohto `README`

# Riešenie

Prvý postup, ktorý vám asi napadne je si zakaždým ukladať podcestu, ktorou
vláčik prechádza. Ak taká podcesta ešte neexistuje, je potrebné ju vytvoriť.

Kvôli časovým obmedzeniam môže byť porovnávanie textových reťazcov vo veľkom
sete dát problém, aj keď neskúšal som. Možno použitie `set`-u alebo `map`-y so
`string`-ami stačí.

Rovno som šiel do grafov a vytvoril som si štruktúru pre stanicu:

```C++
struct station {
     string name;
     vector<station *> neighbors;
};
```

Ak teda vstupujem do nového riadku so zoznamom staníc, nastavím sa na koreň
môjho grafu (stanica bez mena) a za každým sa snažím dostať k jednému zo
susedov. Ak taký sused neexistuje, vytvorím ho a urobím si zárez na pažbe.

```C++
/**
* @stationName nazov stanice kam sa chcem dostat
* @target tu sa ulozi najdena stanica (funkcia s referenciou)
* @return vrati true ak bola vytvorena nova stanica
*/
bool go_to(string stationName, station* &target)
```

Najväčší problém sa mi zdalo parsovanie textov. To v C++ nie je veľmi čitateľné.

# Zadanie

## Hor sa do sveta

_Počet bodov: 50_

Ocko Rušeň a mamka Koľajnica majú spolu veľa detí-vláčat.

Všetky vláčatá už odrástli, a vybrali sa do sveta. S rodičmi sú stále v kontakte, a vždy
sa im ozvú, keď na svojich vandrovkách dorazia na ďalšiu stanicu.

Rodičia si to všetko pozorne zapisujú do zápisníka, a vedia o každom vláčati, akými stanicami
si prešlo.

K tomuto zápisníku sa nedávno dostal Ujo Vozeň, ktorý ich chce na štyridsiate siedme výročie
ich svadby prekvapiť darčekom: mapou sveta, so všetkými stanicami ktoré navštívilo nejaké ich
vláča.

Samotná mapa so stanicami sa kreslí ľahko - trasy vláčat sa nikde nekrižujú ani nespájajú.
Problém sú názvy staníc. Každú z nich bude musieť Ujo Vozeň vlastnoručne vystrihnúť a nalepiť
na mapu.

Keby aspoň vedel, koľko roboty ho čaká…


### Úloha

Do sveta sa vybralo $`n`$ vláčat.

Trasa každého vláčaťa je popísaná jedným reťazcom, určujúc postupnosť navštívených staníc.
Názvy staníc sú neprázdne a pozostávajú z malých písmen anglickej abecedy. Názvy jednotlivých
staníc v postupnosti sú oddelené znakom /.

Všetky vláčatá začali na domácej stanici home, ktorá je implicitná, a teda si ju Rušeň s
Koľajnicou do zápisníka nepísali, a ich trasy začínajú / a názvom prvej stanice, ktorú
potom navštívili.

Stanice s rovnakým názvom sú odlišné stanice práve vtedy, keď sú ich trasy z domu odlišné.

Zistite, koľko rôznych staníc bolo navštívených.

### Vstup a Výstup

V prvom riadku je číslo $`1 \leq n \leq 10^5`$- počet vláčat.

V každom z nasledujúcich $`n`$ riadkov je jeden reťazec, popisujúc trasu jedného vláčaťa.

Súčet dĺžok všetkých trás na vstupe bude v prvej sade najviac $`1000`$,
a v druhej najviac $`10^6`$ .

Vypíšte jedno číslo: počet rôznych staníc, ktorými vláčatá prešli.

### Príklady

Input:
```
3
/bratislava/prievidza
/bratislava/pezinok
/dolnykubin/hornykubin/prievidza
```

Output:

```
6
```
_Ujo Vozeň musí vystrihnúť nasledovné názvy: dolnykubin, hornykubin, bratislava,
pezinok, prievidza, prievidza. bratislava stačí len raz, keďže prvé aj druhé
vláča prešli tou istou stanicou. Prievidze sú však rôzne stanice, keďže k jednej
je trasa cez bratislavu, a v druhej cez kubíny._

Input:
```
4
/zenit/zenit/zenit
/zenit/zenit/ksp
/ksp/zenit/ioi
/ksp/zenit/ioi
```

Output:

```
7
```

_Prvé dve zenity prvých dvoch vláčat sú rovnaké stanice, ako aj všetky stanice
posledných dvoch. Zvyšok sú všetko unikátne stanice._