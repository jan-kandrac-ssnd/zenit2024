# Úloha KK-H

Odkaz na úlohu nájdeš tu: https://zenit.ksp.sk/task/zenit24kkh

Celé znenie zadania nájdeš na konci tohto `README`

# Riešenie

Táto úloha si jednoznačne pýtala zistiť nejaký jednoduchý vzorček pre výpočet. Hneď zo začiatko bolo totiž zjavné, že
miestnosti s rovnakým pomerom strán budú mať rovnaký výsledok, teda miestnosť `1 x 2` ma rovnaký počet riešení ako
`40 x 80`. Šikovnejším dôjde, že k takémuto zovšeobecneniu vieme dospieť vyrátaním najväčšieho spoločného deliteľa
a predelením oboch rozmerov týmto číslom. Napríklad pri číslach `12` a `32` získame zmenšený rozmer nasledovne:

```
GCD(12, 32) = 4
a = 12 / 4 = 3
b = 32 / 4 = 8
```

Teda výsledok bude rovnaký ako pri rozmere miestnosti `3x8`

Vyrátal som si riešenie pre niekoľko po sebe nasledujúcich rozmerov napríklad pre `5x6`, `5x7`, `5x8`, `6x7`
a pozorovaním som dospel ku vzorcu:

```
(8 * a) + (b - a) * 4 - 8
```

# Zadanie

## Hrôzostrašný darček
_Počet bodov: 50_

Konco je konečne veľký, a ako mu Lenka raz sľúbila, kúpila mu zrkadlový dom aby sa mohol obdivovať. To však nevedel,
čo na neho tá fikusáčka nastražila.

Prechádzal sa po jeho obvode, omámený z tej nádhery. Potom sa ale kúsok otočil a uvidel ducha! Zľakol sa tak, že rozbil
zrkadlo za sebou a vybehol z domu. No a keď uvidel Lenku, všetko bolo jasné. Veď ona dala duchov do všetkých rohov domu!

No ale rozbité zrkadlo treba opraviť. Konco si už aj objednal zlepovačov zrkadiel, len im musí povedať, kde sa rozbité
zrkadlo nachádza. No ale do domu už ani náhodou nejde. Poraďte mu, na koľkých miestach a smeroch sa mohol nachádzať
keď uvidel ducha.

## Úloha
Zrkadlový dom má tvar obdĺžnika rozmerov $`n \times m`$ a všade po jeho obvode sa nachádzajú zrkadlá. V jeho rohoch
sa nachádzajú duchovia. Okrem toho je dom úplne prázdny, aj bez stien.

Konco sa nachádzal niekde na celočíselných súradniciach na obvode domu, nie však v rohu. Pozeral sa smerom do
miestnosti pod 45-stupňovým uhlom od steny. To znamená, že na každom mieste mohol byť dvoma spôsobmi.

Keď sa takto pozeral, uvidel ducha – možno v odraze zrkadiel, možno nie. Koľkými spôsobmi sa toto mohlo stať?

## Vstup a Výstup
Jediný riadok vstupu obsahuje dve celé čísla – $`m`$ a $`n`$ popisujúce rozmery miestnosti.

Na jeden riadok vypíšte jediné číslo – počet spôsobov, ako mohol Konco uvidieť ducha.

## Obmedzenia
Vstupy úlohy sa skladajú z piatich sád, v ktorých platia nasledujúce obmedzenia:

- Sada 1: $`1 \leq m,n \leq 100`$
- Sada 2: $`1 \leq m,n \leq 5000`$
- Sada 3: $`1 \leq m,n \leq 2 \cdot 10^5`$
- Sada 4: $`1 \leq m,n \leq 10^9`$
- Sada 5: $`1 \leq m,n \leq 10^9`$

Na jeden riadok vypíšte jediné číslo – počet spôsobov, ako mohol Konco uvidieť ducha.

### Príklad

Input:

```
1 4
```

Output:

```
12
```

_V tomto prípade hocikde by Konco bol, a hocijak by sa pritom pozeral, uvidel by ducha._

Input:

```
2 2
```

Output:

```
0
```

_Tu ducha Konco nemal ako vidieť._

Input:

```
47 74
```

Output:

```
476
```