# Úloha KK-F

Odkaz na úlohu nájdeš tu: https://zenit.ksp.sk/task/zenit24kkf

Celé znenie zadania nájdeš na konci tohto `README`

# Riešenie

Jedná sa o Undounded Knapsack problem s dodatočnou podmienkou navyše. Riešenie dosť presne tiplo aj GPT

# Zadanie

## Fauni a flóra
_Počet bodov: 40_

Faun Tumnus sa raz tak prechádzal po lese a zbieral ovocie, až kým mal plný košík. Potom ale našiel ešte dve jablká a
tie má veľmi rád, ale už mu neostalo miesto v košíku, takže musel vyhodiť jahody, a tak bol smutný.

## Úloha
Na vstupe dostanete zoznam ovocia ktorý si faun doma pripravil. O každom ovocí vieme, koľko váži a akú
má pre Tumnusa cenu.

Vašou úlohou je zistiť akú najväčšiu cenu môže mať Tumnusov košík s nosnosťou $`k`$, keď nazbiera správne počty
jednotlivých typov ovocia. Dávajte však pozor, Tumnus nesmie mať zo žiadneho ovocia práve jeden kus (potom by
sa nemohol podeliť). Takže buď nazbiera viac ako jeden, alebo nula kusov. Počet kusov jedného typu nie je v lese
nijako obmedzený, ale súčet váh nazbieraného ovocia musí byť najviac $`k`$ .

## Vstup a Výstup
Prvý riadok vstupu obsahuje čísla $`n(1 \leq n \leq 1000)`$ a $`n(1 \leq k \leq 1024)`$, ktoré označujú počet
typov ovocia a nosnosť košíka.

Nasleduje $`n`$ riadkov, na každom dve celé čísla $`v_i(0 < v_i \leq 1024)`$ a $`c_i(0 < c_i \leq 10^6)`$,
označujúce váhu a cenu i-teho typu ovocia.

V prvej sade $`n, k \leq 50`$.

Na jeden riadok vypíšte jedno celé číslo: Maximálnu cenu ovocia v košíku.



### Príklad

Input:

```
4 17
6 8
5 6
2 2
1 1
```

Output:

```
21
```

_Tumnus môže zobrať ovocie v hodnote 2x8+5x1, ktorých váha bude 12+5=17, čiže košík to unesie._