# Úloha SK-B

Odkaz na úlohu nájdeš tu: https://zenit.ksp.sk/task/zenit24skb

Celé znenie zadania nájdeš na konci tohto `README`

# Riešenie

Ak `cislo % 2 == 0` teda je párne, potom chceme na výstup napísať číslo o jedno väčšie ako `cislo`

V opačnom prípade chceme vypísať číslo o 1 menšie.

V jazyku C++ je `0 == false` a `1 == true` preto nám stačí vypísať výsledok výrazu:

```C++
cislo % 2 ? cislo - 1 : cislo + 1
```


# Zadanie

## Budeš mojim rýchlikom?

_Počet bodov: 15_

Život slovenského rýchlika vôbec nie je jednoduchý. Nikto neocení, keď vzplanieš vášňou. Nikto ťa neuteší, keď sa utápaš žiaľom. Vnútri niekedy cítiš nevysvetliteľný mrazivý chlad (konkrétne v zime) alebo nevysvetliteľné neznesiteľné teplo (konkrétne v lete). Všetci na teba frflú a občas máš dokonca pocit, že ťa nikto nemá rád. Keby ťa naozaj chceli, tak im nevadí si na dobré veci počkať. Kľudne aj 300 minút.

No jednu vec ti môžu všetci závidieť. Nech sa deje čokoľvek, niekde tam vonku je určite rýchlik, s ktorým tvoríš dvojicu. Keď ty vychádzaš zo svojej východziej stanice, z tvojej cieľovej stanice v približne rovnakom čase vychádza rýchlik, ktorý ide tú istú trasu, len opačne. Ak štastie dá a nič nemešká (rozumej skoro nikdy), tak sa dokonca stretnete na polceste a vaši rušňovodiči si môžu zamávať.

Každý rýchlik má svoje číslo. Pre rýchliky, ktoré majú párne číslo platí, že ich dvojica má číslo o jedna väčšie. Pre rýchliky, ktoré majú nepárne číslo platí, že ich dvojica má číslo o jedna menšie. Napríklad taký rýchlik 614 tvorí pár s rýchlikom 615. Teraz, keď viete, ako to funguje, pre každý rýchlik, ktorý vám čislom zadáme viete povedať, akú má dvojicu a môžeme mu všetci spolu závidieť.

### Úloha

Na vstupe dostanete číslo $`A`$ reprezentujúce číslo rýchlika. Vašou úlohou je vypísať číslo rýchlika, ktoré s týmto rýchlikom tvorí pár.


### Vstup a Výstup

Na jedinom riadku vstupu sa nachádza celé číslo $`A\left( 1 \leq A \leq 2 \cdot 10^2\right)`$

Na jeden riadok vypíšte celé číslo zodpovedajúce rýchliku, ktorý s rýchlikom zo vstupu tvorí pár.



### Príklady

Input:

```
614
```

Output:

```
615
```

Input:

```
615
```
Output:

```
614
```