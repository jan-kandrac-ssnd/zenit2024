# Úloha SK-F

Odkaz na úlohu nájdeš tu: https://zenit.ksp.sk/task/zenit24skf

Celé znenie zadania nájdeš na konci tohto `README`

# Riešenie

Kreatívna úloha, riešenie je extrémne jednoduché. Bez papiera sa nepohneš.

Ak mám k dispozícii riešenia vo forme **dvojciferných** čísel teda: _11, 22, 55, 69, 88 a 96_
(6 čísel)

Tak **trojciferné** čísla dostanem tak, že medzi tieto čísla (napr. sem: `1_1`) vložím
také číslo, ktoré je symetrické samo o sebe, teda _0, 1, 2, 5 a 8_ (5 čísel).
Trojciferných čísel teda bude `6 * 5 = 30`.

**Štvorciferné** čísla získam tak, že medzi dvojciferné čísla strčím symetrické dvojciferné čísla
(nesmiem zabudnúť, že uprostred čísla môže byť aj alternatíva `00`). Teda štvorciferných bude
`6 * 7 = 42`

Teda rekurzia vyzerá nasledovne:

```C++
int help(int i) {
    if (i == 1) return 5;
    if (i == 2) return 6;
    if (i % 2 == 1) return help(i - 1) * 5;
    return help(i - 2) * 7;
}
```

Toto si viem pre všetky prípady ($`1 \leq k \leq 20`$) zrátať aj na kalkulačke a výsledky
vrátiť vo switch-case alebo z `map`-y.

# Zadanie

## Fakt sú rovnaké?

_Počet bodov: 35_

Kika ide zas na chatu do Valče. Tento krát ale nie na dovolenku. Treba vyčistiť stoku.
Keďže nemá auto, tak sa rozhodla ísť vlakom. Ako je jej zvykom, na stanicu prišla
minútu pred odchodom vlaku. Ako bežala na vlak, tak si všimla, že lístok drží dole
hlavou, takže beží na vlak so zlým číslom. Keď ale lístok otočila správne, tak zistila,
že je to rovnaké číslo. Prišlo jej to zaujímavé, tak sa rozhodla zistiť, koľko takých
čísiel existuje.

### Úloha

Vašou úlohou bude zistiť, koľko existuje $`k`$-ciferných čísiel, ktoré sú rovnaké,
keď ich otočíte o 180 stupňov. Cifry vyzerajú nasledovne:

```
###   #   ###  ###  # #  ###  ###  ###  ###  ###
# #   #     #    #  # #  #    #      #  # #  # #
# #   #   ###  ###  ###  ###  ###    #  ###  ###
# #   #   #      #    #    #  # #    #  # #    #
###   #   ###  ###    #  ###  ###    #  ###  ###
```

### Vstup a Výstup

Na vstupe je jedno číslo $`1 \leq k \leq 20`$.

Na výstup vypíšte jedno číslo – počet $`k`$ -ciferných čísiel,
ktoré sú rovnaké, keď ich otočíte o 180 stupňov.

### Príklad

Input:
```
1
```

Output:

```
5
```
_0, 1, 2, 5 a 8_

Input:
```
2
```

Output:

```
6
```
_11, 22, 55, 69, 88 a 96_