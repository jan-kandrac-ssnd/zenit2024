# Úloha KK-D

Odkaz na úlohu nájdeš tu: https://zenit.ksp.sk/task/zenit24kkd

Celé znenie zadania nájdeš na konci tohto `README`

# Riešenie

Jedná sa o vyváženú trojkovú sústavu. Takže výpočet bude podobný ako pri dvojkovej, či trojkovej sústave. Ale inak
budeme spracovávať zvyšok po delení:
1. vyrátame zvyšok po delení troma
2. ak je zvyšok po delení troma `0` alebo `1` zohľadníme klasicky teda prevedieme na znaky `0` a `+`
3. ak je zvyšok po delení troma `2` prevedieme na znak `-`
4. číslo predelíme troma

Kroky 1-4 opakujeme, kým vstupné číslo nebude 0.

# Zadanie

## Dračia číselná sústava
_Počet bodov: 30_

Draci odjakživa používajú čudesnú číselnú sústavu. Keďže majú tri prsty na nohách (a občas tri hlavy), ich sústava má
základ tri (oproti našej so základom desať). Namiesto hodnôt 0, 1 a 2 však ich číslice majú hodnoty $`-1, 0, 1`$
(povesť vraví, že to plynie z faktu, že hocikto pred drakom je buď zožraný, nezaujímavý, alebo nezožraný).

Draci majú aj veľa zlata, a tak sú lukratívnymi obchodnými partnermi. To by sme však ale museli vedieť prekladať
ľudské čísla na dračie…

## Úloha
Na vstupe dostanete niekoľko ľudských čísel. Preložte ich do dračej číselnej sústavy.

Draci rátajú v trojkovej sústave, teda najpravejšia pozícia má hodnotu 1, druhá zľava 3, tretia 9, štvrtá 27, …,
$`i`$-ta $`3^{i-1}`$. Dračie číslice však nemajú hodnoty $`0, 1, 2`$ ale $`-1, 0, 1`$, a zapisujeme ich $`-, 0, +`$.

Napríklad Dračie číslo $`+0-0`$ má v našej sústave hodnotu
$`0 \cdot 3^0 - 1 \cdot 3^1 + 0 \cdot 3^2 + 1 \cdot 3^3 = 0 - 3 + 0 + 27 = 24`$.

## Vstup a Výstup
Prvý riadok vstupu obsahuje číslo $`1 \leq T \leq 200`$ - počet čísiel na preloženie.

V každom z nasledovných $`T`$ riadkov je jedno číslo $`n_i`$. V prvej sade $`1 \leq n_i \leq 10`$.
V druhej $`1 \leq n_i \leq 1000`$

### Príklad

Input:

```
2
47
243
```

Output:

```
+--+-
+00000
```

_81 - 27 - 9 + 3 - 1 = 47_
