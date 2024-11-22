# Úloha KK-C

Odkaz na úlohu nájdeš tu: https://zenit.ksp.sk/task/zenit24kkc

Celé znenie zadania nájdeš na konci tohto `README`

# Riešenie

Nechápem ako ste sa tu mohli tak vytrápiť :) Táto úloha sa dá riešiť pekne sekvenčne, žiadne polia ani vektory
neboli potrebné. Potrebujem si len pamätať, na akej pozícii som sa nachádzal naposledy (`lastPos`) a koľko klikov
som zatiaľ vykonal (`sum`).

Hľadám prvú fotku, ktorú otvorím kliknutím. Teda ignorujem prvých
niekoľko núl a ak nájdem prvú jednodku, tak ju zarátam a zapamätám si poslednú navštívenú pozíciu:

```
if (value == 0) continue;
if (lastPos == -1) { lastPos = i; sum++; continue; }
```

Ak nájdem bezprostredne susediacu fotku, tak je rýchlejšie na ňu swipnúť, takže tiež zvýšim skóre len o 1 číslo:
```
if (i == lastPos + 1) { lastPos = i; sum++; continue; }
```
Ak je rozdiel väčší potrebujem vždy najmenej 2 kliky:
```
sum += 2;
lastPos = i;
```
Hotovo

# Zadanie

## Celú galériu si pozriem
_Počet bodov: 20_

Tí z vás, ktorí poznáte škriatka Zahradníka viete, že má neuveriteľnú schopnosť nepamätať si takmer nič. Robí mu to
problém napríklad v rozhovoroch s ľuďmi (kde počas rozhovoru zabudne, o čom sa rozpráva).

Škriatok o tomto probléme vie, takže si pomáha ako len môže. Napríklad má v galérii v telefóne označené, ktoré fotky
už videl a ktoré nie. Nedávno si chcel pozrieť fotky z minulého leta. Keďže je veľmi lenivý, urobil to tak, aby musel
čo najmenej krát ťuknúť do telefónu. Problém je, že už stihol zabudnúť nie len to, že si niekedy pozeral fotky, ale aj
že nejaké fotky vôbec má. To znamená, že ostalo na vás, aby ste zistili, koľko krát musel ťuknúť do telefónu, aby si
pozrel všetky fotky, ktoré ešte nevidel.

## Úloha
Dostanete zoznam fotiek, ktoré škriatok má. Škriatok každú fotku buď videl, alebo ešte nie. Pozeranie fotiek funguje
podobne, ako ste zvyknutí z pozerania fotiek v telefóne. Ak vidíte zoznam všetkých fotiek, môžete na ľubovoľnú fotku
ťuknúť, čím ju otvoríte. Ak máte otvorenú nejakú fotku, môžete sa buď vrátiť na zoznam všetkých fotiek, alebo na
predchádzajúcu alebo nasledujúcu fotku. Každá z vymenovaných operácií (otvorenie fotky, zatvorenie fotky, prejdenie
na predchádzajúcu fotku, prejdenie na nasledujúcu fotku) je rovná jednému ťuknutiu do mobilu. Vašou úlohou je povedať,
koľko najmenej ťuknutí treba urobiť, aby videl všetky fotky, ktoré doteraz nevidel.

## Vstup a Výstup
Na prvom riadku vstupu sa nachádza číslo $`n`$ – počet fotiek v galérii. Na druhom riadku sa nachádza $`n`$ medzerou
oddelených čísel $`f_i, f_i \in {0, 1}`$, ktoré reprezentujú fotky. Ak $`f_i = 0`$, znamená to, že fotku už škriatok
videl, ak $`f_i = 1`$, tak túto fotku škriatok ešte nevidel a chcel by si ju pozrieť.

### Príklad

Input:

```
3
1 0 1
```

Output:

```
3
```

_Môžeme napríklad ťuknúť na prvú fotku, potom ťuknúť dva krát na zobrazenie nasledujúcej, čím zobrazíme poslednú fotku.
Takto sme videli obe doteraz nevidené fotky a potrebovali sme kvôli tomu tri krát ťuknúť do mobilu. Všimnite si, že po
poslednej fotke sme sa nemuseli vrátiť na zoznam všetkých fotiek._

Input:

```
5
1 0 0 0 1
```
Output:

```
3
```

_Teraz môžeme napríklad ťuknúť na poslednú fotku, vrátiť sa naspäť na zoznam všetkých fotiek a potom ťuknúť na prvú fotku, čím budeme vidieť všetky doteraz nevidené fotky._