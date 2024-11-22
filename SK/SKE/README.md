# Úloha SK-E

Odkaz na úlohu nájdeš tu: https://zenit.ksp.sk/task/zenit24ske

Celé znenie zadania nájdeš na konci tohto `README`

# Riešenie

Konečne ťažšia úloha.
Keďže lístky sú na 5, 7 alebo 13 zástavok, čo sú prvočísla, postup:
> Odrátam čo najviac 13-tok a potom zvyšok

nebude fungovať. Ako príklad uvádzam číslo `14`. `14 - 13 = 1` a k výsledku sa nedostanem.
Ale `14 - 7 - 7 = 0`.

### Idea - vnorené for cykly
Musíme teda vyskúšať všetky kombinácie čísel. To vieme dosiahnuť aj pomocou trojnásobného
cyklu (neskúšal som, ale tu je idea):
```C++
for (int patky = 0; patky <= n / 5; patky++) {
    for (int sedmicky = 0; sedmicky <= n / 7; sedmicky++) {
        for (int trinastky = 0; trinastky <= n / 13; trinastky++) {
            if (patky * 5 + sedmicky * 7 + trinastky * 13 == input) {
                cout << "ANO" << endl;
            }
        }
    }
}
```

Toto riešenie je už z princípu pomalé, lebo len veľmi pomaly konverguje k výsledku a nijako
neprepoužíva výsledky.

### Idea - rekurzia a dynamické programovanie
Tento postup som vyskúšal, pretože je jednoduchý na napísanie, ale pri hraničných hodnotách
ako napríklad `99999999` rekurzia padala zrejme na vyčerpaní pamäte. (samozrejme som
pridal aj [memoizáciu](https://en.wikipedia.org/wiki/Memoization))

```C++
bool moze(const long &zvysok) {
    return zvysok >= 0 && (
        zvysok == 0 || moze(zvysok - 13) || moze(zvysok - 7) || moze(zvysok - 5)
    );
}
```

### Idea - DFS
Algoritmus DFS ([Depth-First-Search](https://en.wikipedia.org/wiki/Depth-first_search))
je algoritmus na prehľadávanie do hĺbky. Teda sa snaží čím skôr nájsť hoci neideálne
riešenie v grafe.

1. Do `stack`-u som si vložil požadované riešenie.
2. Kým `stack` nebol prázdny
   1. vyberiem z neho posledné vložené `číslo`
   2. ak je `číslo` výsledkom vyhral som
   3. ak je `číslo` nevalidné (`<0`) ignorujem ho
   4. vrátim do `stack`-u `číslo-5`
   5. vrátim do `stack`-u `číslo-7`
   6. vrátim do `stack`-u `číslo-13`
3. Ak som sa dostal až sem, potom riešenie neexistuje

Ak som k bodu 2. ii. pridal aj skontrolovanie deliteľnosti 5, 7 a 13, riešenie
konvergovalo dostatočne rýchlo aj bez memoizácie.

# Zadanie

## Exaktne použiť kupóny

_Počet bodov: 30_

Maťko je vášnivý cestovateľ a milovník vlakov. Každý týždeň netrpezlivo otvára
svoj obľúbený časopis Dopravca, pretože v niektorých vydaniach objaví špeciálne
kupóny na vlakové lístky. Každý z týchto kupónov je platný presne na 5, 7, alebo
13 zástavok obojsmerne.

Tieto kupóny chce využiť na to aby si spravil výlet k svojím obľúbeným staniciam
a lepšie si ich prehliadol. A keďže si okrem staníc chce pozrieť aj mestá v ktorých
sú, tak ku každej z nich plánuje samostatný celodenný výlet. Napriek tomu že kupónov
nazbieral už veľmi veľa, nechce nimi plytvať. Chce si byť istý, že každú svoju cestu môže
zaplatiť presne jedným alebo viacerými z týchto kupónov, bez toho, aby mu zostali nevyužité
zástavky. Ak by mal vystúpiť predčasne, radšej odloží výlet na neskôr.

Pomôžte Maťkovi zistiť, ktoré výlety dokáže zaplatiť presne pomocou kupónov na 5,
7 alebo 13 zástavok, a ktoré výlety sa nedajú pokryť týmito kupónmi.

### Úloha

Napíšte program, ktorý pomôže Maťkovi zistiť, ktoré z jeho plánovaných výletov
vie zaplatiť presne, a ktoré nie.

### Vstup a Výstup

Prvé číslo na vstupe je $`1 \leq n \leq 1000`$ – počet výletov ktoré Maťko plánuje.

Nasleduje $`n`$ riadkov. Na každom z nich je $`1 \leq a_i \leq 10^9`$ – počet zástavok,
ktoré musí Maťko prejsť, aby sa dostal do cieľovej destinácie.

Pre každý z výletov vypíšte `ANO`, ak sa dá presný počet zastávok vyskladať z kupónov
na 5, 7 alebo 13 zástavok. Ak to nie je možné, vypíšte `NIE`.

Polovičný počet bodov viete získať za program ktorý vyrieši vstupy kde všetky výlety
sú vzdialené najviac 30 zastávok.

### Príklad

Input:
```
4
5
6
10
12
```

Output:

```
ANO
NIE
ANO
ANO
```