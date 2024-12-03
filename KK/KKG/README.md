# Úloha KK-G

Odkaz na úlohu nájdeš tu: https://zenit.ksp.sk/task/zenit24kkg

Celé znenie zadania nájdeš na konci tohto `README`

# Riešenie

Problém pri takej mriežke, kde je jeden z rozmerov nepárne číslo je triviálny. Jednoducho môžeme prejsť všetky body,
keďže záporné hodnoty sa v mriežke nenachádzajú. Problém je s rozmermi mriežky, kde $`r`$ aj $`c`$ sú párne čísla.

Pre riešenie som použil rekurzívny backtracking pre hľadanie najdlhšej cesty. Toto riešenie zďaleka nie je
najefektívnejšie pretože pričasto prehľadáva rovnaký stavový priestor. Keďže veľkosť mriežky je max 1000x1000, tak
do úvahy neprichádza ani DP pomocou memoizácie a potrebujem nájsť riešenie pomocou nejakej formy grafového algoritmu.

Použitá rekurzia navyše pri veľkých vstupoch padá, preto je toto riešenie vhodné len pre malé mriežky.

# Zadanie

## Groše na Konci
_Počet bodov: 45_

Počuli ste to? Ževraj sa na Konci dúhy nachádza mýtický poklad! Jóóój, nie na tomto konci, ale na tom druhom, nevadí.
Cesta na Koniec vôbec nie je taká zložitá, ako si myslíte. Koniec koncov, máte predsa kompletnú mapu, ktorá vám na
ceste isto pomôže. A dokonca si môžete po ceste natrhať aj zopár štvorlístkov. Čo ak je štastie to, čo naozaj hľadáte?

Cesta vedie krajinou riek, morí a potokov. Ako jedno múdre príslovie hovorí: “Neprejdeš cez jednu rieku dvakrát.” A
možno v tom bude problém? Už len zistiť nalepšiu cestu.

## Úloha
Za Koncom dúhy pôjdete cez krajinu, ktorá je rozdelená na $`r`$ riadkov a $`c`$ stĺpcov. Na každom políčku krajiny
sa nachádza niekoľko štvorlístkov a rieka, kvôli ktorej nemôžete na žiadne políčko stúpit dvakrát.

Vašou úlohou je nájsť cestu začínajúcu na jednom Konci dúhy (ľavý dolný roh) a končiacu na druhom (pravý horný roh)
tak, aby ste po ceste pozbierali čo najviac šťastia (teda štvorlístkov). Ale pozor, na každé políčko môžete stúpiť
najviac raz. Hýbať sa môžete do štyroch základných smerov.

## Vstup a Výstup
Prvý riadok vstupu obsahuje čísla $`r`$ a $`c`$ $`(1 \leq r, c \leq 1000)`$, ktoré označuje počet riadkov a
stĺpcov mapy krajiny. Nasleduje $`r`$ riadkov, na každom z nich $`c`$ čísel $`a_{i,j}(0 \leq a_{i,j} \leq 1000)`$,
ktoré hovoria o počte štvorlístkov na tomto políčku.

Na jeden riadok vypíšte jedno číslo, najväčší počet štvorlístkov, ktoré viete po ceste z jedného Konca dúhy na
druhý pozbierať, bez toho, aby ste na nejaké políčko stúpili viac ako raz.

V sade za $`15`$ bodov navyše platí $`1 \leq r, c \leq 5`$.

### Príklad

Input:

```
1 5
1 2 3 4 5
```

Output:

```
15
```

_Môžeme prejsť cez všetky políčka krajiny._

Input:

```
2 2
2 1
1 3
```

Output:

```
5
```
