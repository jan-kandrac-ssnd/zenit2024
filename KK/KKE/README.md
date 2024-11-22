# Úloha KK-E

Odkaz na úlohu nájdeš tu: https://zenit.ksp.sk/task/zenit24kke

Celé znenie zadania nájdeš na konci tohto `README`

# Riešenie
Mriežku nie je potrebné otáčať, rovnaký efekt dostaneme, keď všetky žetóny presunieme na pravú stranu.
Po tomto presune len skontrolujeme, kto má bod.

# Zadanie

## Ešte neprišiel Erikin čas
_Počet bodov: 30_

Každý robí chyby. Jožko zahodil lyžičku do koša a téglik od jogurtu naložil do umývačky. Maťka si nechala peračník
doma. Ondrej zabudol vypísať koniec riadku pri riešení Zenitu. Erika upísala svoju dušu Diablovi pri snahe zrecitovať
Latinské texty.

Čo sa stalo, stalo sa.

Jožko musel lyžičku vyloviť. Maťka na výtvarnej kreslila perom. Ondrej za 15 minút prepísal svoje riešenie do pythonu,
ktorý vypisuje koniec riadku automaticky. Erika musí bojovať o dušu (literally).

Diabol, ako je zvykom, svojim obetiam dá šancu vyhrať svoju dušu v hre. Klasicky v kartách, ale to ho už omrzelo -
dnešnou dobou sa hrá “Connect-K”, hru v ktorej sa hráči striedajú vo vhodení žetónu do mriežky, a snažia sa dosiahnuť
$`K`$ susediacich žetónov v riadku, stĺpci, alebo diagonálne.

Diabol je však Diabolsky dobrý, a má Eriku v kúte.

Erika má v zásobe poslednú zbraň - ukáže Diablovi cez plece do neba, skríkne “Wau, anjel!”, a keď sa Diabol obzrie,
druhou rukou otočí mriežku o 90 stupňov v smere hodinových ručičiek.

Vzápätí, keďze sa mriežke zmenil smer “dole”, žetóny popadajú, a… no snáď Erika vyhrá, to si nestihla potvrdiť.

Mali ste možnosť tento zápas sledovať v priamom prenose, keďže Erika má moderný mobil a luxusný dátový balíček.

Nanešťastie ho pri svojom manévri zhodila zo stola, a ja si teraz kúšem nechty od nervozity, čo sa s Erikou vlastne stalo.

Pomôžete mi zistiť, či po tomto manévri hra skončila?

## Úloha
Dostanete popis hracej mriežky “Connect-K” aj s žetónmi. Ich rozloženie bude valídne, teda žetóny nebudú levitovať
vo vzduchu.

Zistite, ktorý z hráčov bude mať aspoň $`K`$ žetónov za radom, a to už v riadku, stĺpci, či diagonálne, keď ju v tomto
stave otočíme o 90 stupňov v smere hodinových ručičiek, a necháme žetóniky popadať.

```
.......                 .......                 .......
.......                 R......                 .......
.......                 BB.....                 .......
...R...  --otocime-->   BRRR...  --spadne-->    R......
...RB..                 RBB....                 BB.....
..BRB..                 .......                 BRR....
.RBBR..                 .......                 RBBR...
```

## Vstup a Výstup
V prvom riadku je číslo $`t`$ - počet mriežok, pre ktoré hľadáme odpoveď. Nasleduje $`t`$ popisov mriežok.

V prvom riadku popisu sú čísla $`N`$ a $`K`$ - rozmer mriežky a vyhrávajúci počet žetónov.

V každom z nasledovných $`N`$ riadkov je $`N`$ znakov, popisujúc mriežku, zhora dole. `.` reprezentuje prázdne
políčko, `R` Erikin žetón, a `B` Diablov žetón.

Platí $`1 \leq t \leq 100`$ , $`3 \leq K \leq N`$. V prvej sade $`N \leq 7`$. V druhej $`N \leq 50`$.

Pre každú mriežku vypíšte stav hry po jej otočení: Nikto ak nikto nevyhral, Erika ak vyhrala Erika, Diabol ak vyhral Diabol, a Dilema ak vyhrali obaja.

### Príklad

Input:

```
4
6 4
......
......
.R...R
.R..BB
.R.RBR
RB.BBB
4 4
R...
BR..
BR..
BR..
3 3
B..
RB.
RB.
7 3
.......
.......
.......
...R...
...BB..
..BRB..
.RRBR..
```

Output:

```
Dilema
Erika
Diabol
Nikto
```
