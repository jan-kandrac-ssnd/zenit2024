# Úloha SK-D

Odkaz na úlohu nájdeš tu: https://zenit.ksp.sk/task/zenit24skd

Celé znenie zadania nájdeš na konci tohto `README`

# Riešenie

Možno je trochu náročnejšie pochopiť, čo je myslené dokonalou diagonálnosťou:

> Dve omrvinky sú na rovnakej diagonále, ak rozdiel `riadku` a `stĺpca` jednej omrvinky
je rovnaký ako rozdiel `riadku` a `stĺpca` druhej

V podstate to ale jednoducho znamená diagonálu z ľavej hornej časti do pravej dolnej.
Ukážka diagonál číslovaných od 0:

```
4 5 6 7 8
3 4 5 9 7
2 3 4 5 6
1 2 3 4 5
0 1 2 3 4
```

Ak idem prstom po každej jednej omrvinke, vidím, že je správna, ak omrvinka
o jednu pozíciu vpravo dole je rovnaká. Teda ak som na pozícii `X` potrebujem
skontrolovať pozíciu `Y`:

```
X .
. Y
```

Ak to spravím pre každú omrvinku, zistím dokonalú diagonálnosť.

# Zadanie

## Dokonale diagonále omrvinky

_Počet bodov: 24_

Keď Kubo konečne našiel svoje sedadlo, zistil že ja ňom strašne veľa omrviniek.
Všimol si, že omrvinky nie sú na sedadle len tak porozhadzované, ale sú
usporiadané do štvorca. To Kuba tak zaujalo, že sa na omrvinky pozeral
až do konca (teda kým vlak nedošiel na konečnú). Vyzerá to, že omrvinky sú
dokonca dokonale diagonálne. Je to však naozaj tak?

### Úloha

Napíšte program, ktorý zistí či sú omrvinky dokonale diagonálne.

Dve omrvinky sú na rovnakej diagonále, ak rozdiel riadku a stĺpca jednej omrvinky
je rovnaký ako rozdiel riadku a stĺpca druhej. Napríklad omrvinka v druhom riadku
a prvom stĺpci je na rovnakej diagonále ako omrvinka v štvrtom riadku a treťom stĺpci,
lebo u oboch je rozdiel $`2-1=4-3=1`$. Však pozrite príklady :).

Omrvinky sú dokonale diagonálne, ak pre každú diagonálu platí, že na nej je práve
jeden typ omrviniek.

### Vstup a Výstup

Na prvom riadku vstupu bude jedno číslo $`1 < n`$ - veľkosť sedadla.
Nasleduje $`n`$ riadkov, na každom z nich je $`n`$ medzerou oddelených
čísel,popisujúce omrvinky na sedadle. Rôzne typy omrviniek sú reprezentované
rôznymi celými číslami.

Na výstup vypíšte `dokonale diagonalne` ak sú omrvinky dokonale diagonálne,
a `kopa smetia` ak nie je. Nezabudnite na znak konca riadku.

### Obmedzenia
Budú dve sady, v prvej platí, že $`n \leq 3`$, v druhej $`n \leq 1000`$

### Príklad

Input:
```
5
1 2 3 4 8
5 1 2 3 4
4 5 1 2 3
7 4 5 1 2
2 7 4 5 1  
```

Output:

```
dokonale diagonalne
```

Input:

```
3
1 2 3
4 5 6
7 8 9
```
Output:

```
kopa smetia
```

Input:

```
4
4 8 5 3
4 4 8 5
2 4 5 8
1 2 4 5
```
Output:

```
kopa smetia
```

Input:

```
3
4 5 6
5 6 8
6 8 4
```
Output:

```
kopa smetia
```