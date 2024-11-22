# Úloha SK-G

Odkaz na úlohu nájdeš tu: https://zenit.ksp.sk/task/zenit24skg

Celé znenie zadania nájdeš na konci tohto `README`

# Riešenie

Riešenie pre tento problém patrí do skupiny greedy algoritmov. Veľmi sa podobá
napríklad na riešenie [Scheduling problému](https://www.geeksforgeeks.org/scheduling-in-greedy-algorithms/).

V prípade  $`<2`$ vozňov a v prípade párneho počtu vozňov nevieme vyvoriť riešenie.
Pretože Cyril navštevuje vždy posledný vozeň, ktorý musí byť nepárny.

Keďže sa Adam nevie dostať do posledného vozňa (inak by nastali protesty), vieme,
že tento vozeň musí obslúžiť Cyril a nikto iný. Vybavíme teda najprv jeho vozeň.
Ak však zostali nejaké vozne aj Betke, Cyril sa musí trochu poflákať, lebo nikto
iný Betkine vozne neobslúži (Betka je stále na párnych a Cyril na nepárnych vozňoch).

V prípade vozňov
```
2 5 3 1 4 8 9
```

Potrebujeme obslúžiť posledné 2 vozne. Vykonáme teda `9` smien, aby Cyril svoju robotu
dokončil. Výsledkom bude takýto stav:

```
2 5 0 1 4 0 0
```

Betku a Cyrila pošleme o 2 vagóny späť a zopakujeme procedúru. Teda `4` smeny:

```
2 1 0 0 0 0 0
```

Vykonáme `1` smenu aby mala Betka vybavené a potom iba pričítame čo sa zvýši (`1`) na
prvej pozícii. Toto je jediný vozeň, ktorý môže obslúžiť len Adam.

Postup je teda:
1. vytvoríme ukazovátko pre Adama na `n / 2 - 1` vozni (aby Cyrilovi vyšiel `n`-tý)
2. vytvoríme ukazovátko pre Betku na `Adam * 2` vozni
3. vytvoríme ukazovátko pre Cyrila na `Betka + 1` vozni
4. Kým `Adam != 0`
   1. `smeny = max(Betka, Cyril)` = počet smien, ktoré musia vykonať `Betka` a `Cyril`
   2. `vysledok += smeny`
   3. `Adam = max(0, smeny)`, aby sme vyhodnotili aj Adamovu prácu
   4. posunieme Adamove ukazovátko o `-1`
   5. posunieme Betkino ukazovátko o `-2`
   6. posunieme Cyrilovo ukazovátko o `-2`
5. `vysledok += zostatok_vo_vozni_1`

# Zadanie

## Gombíky v rušni

_Počet bodov: 45_

Keďže vo vyspelých štátoch musia prevádzať vyspelé vlaky, a vyspelí ľudia vyspelých
štátov čítajú knihy, je samozrejmosťou, že vyspelé vlaky vyspelých štátov disponujú
vyspelými svetielkami na čítanie. Náš štát v snahe o vyspelosť sa teda rozhodol ku
každému sedadlu nainštalovať svietielko.

Aby sa to zmestilo do rozpočtu, celé to spadá na brigádnikov Adama, Betku, Cyrila a
Dávida. Traja z nich budú inštalovať svetielka do $`n`$ vozňov, a štvrtý bude v rušni
štuchať gombíky a overovať, že svetielka idú keď majú. Keďže štvrtý je Dávid, v
rušni bude on.

Adam, Betka a Cyril budú postupne inštalovať svetielka. Vozne sú očíslované od $`1`$
po $`n`$. Najskôr sa Adam rozhodne, v ktorom vozni bude pracovať. Betka a Cyril sa
chcú zdržiavať spolu, a tak chcú pracovať v susedných vozňoch, ideálne ďaleko od Adama.
Aby to však nebolo podozrivé, nepôjdu príliš ďaleko - ak Adam pracuje vo vozni
$`x`$, pôjde Betka do vozňa $`2x`$ a Cyril do vozňa $`2x + 1`$. Ak to nie je možné,
budú protestovať.

Adamovi je ich stratégia jasná, a môže len gúľať očami. Rád by však brigádu dorobil čo
najskôr, a tak by bol rád aby ste zistili, koľko im to bude trvať, ak si bude vyberať
vozne optimálne.

### Úloha

Vlak má $`n`$ vozňov očíslovaných od $`1`$ po $`n`$. V $`i`$-tom vozni treba nainštalovať
$`v_i`$ svetielok.

V jednej šichte pôjde Adam inštalovať svetielka do vozňa $`x`$, a Betka s Cyrilom pôjdu
inštalovať svetielka do vozňov $`2x`$ a $`2x + 1`$ . Adam nesmie vybrať také $`x`$, aby
im to neumožnil. Ak niekto inštaluje svetielko vo vozni kde už žiadne svetielka na
inštalovanie neostávajú, tak sa tam celú šichtu fláka. Počas jednej šichty nainštaluje
každý z nich práve jedno svetielko vo vozni v ktorom je.

Za koľko najmenej šícht vedia naší brigádnici nainštalovať všetky svetielka? Dá sa to vôbec?

### Vstup a Výstup

V prvom riadku je číslo $`n`$- počet vozňov vlaku. V druhom riadku je $`n`$ medzerou
oddelených celých čísel $`v_1, v_2, ... v_n`$- počet svetielok ktoré treba nainštalovať
v jednotlivých vozňoch.

Vypíšte jedno číslo. Ak sa nedajú nainštalovať všetky svetielka podľa pravidiel
popísaných v úlohe, vypíšte $`−1`$. Inak vypíšte najmenší počet šícht, za ktorý sa to dá.

V prvej sade $`1 \leq n, v_i \leq 1000`$.

V druhej sade $`1 \leq n \leq 1000`$ a $`1 \leq v_i \leq 10^9`$.

V tretej sade $`1 \leq n \leq 10^5`$ a $`1 \leq v_i \leq 10^9`$.

### Príklady

Input:
```
3
1 2 3
```

Output:

```
3
```
_Adam pôjde tri krát do vozňa 1, a tak Betka s Cyrilom pôjdu tri krát do vozňa 2 a 3, a všetky svetielka sa im podarí nainštalovať._

Input:
```
2
1 2
```

Output:

```
-1
```
_Ak si Adam vyberie vozeň 1, Cyril by chcel pracovať vo vozni 3, ale taký nieje. Ak si Adam vyberie vozeň 2, bude už protestovať aj Betka, lebo vo vlaku nie je ani vozeň 4 a ani vozeň 5._

Input:
```
7
2 5 3 1 4 8 9
```

Output:

```
15
```