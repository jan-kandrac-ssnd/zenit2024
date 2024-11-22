# Úloha SK-C

Odkaz na úlohu nájdeš tu: https://zenit.ksp.sk/task/zenit24skc

Celé znenie zadania nájdeš na konci tohto `README`

# Riešenie

Podľa ukážok vstupov je vidieť presne, ako bude vyzerať vlak.
Každý rušeň má dĺžku 9 znakov (výška nás nezaujíma, pretože
všetky riadky sú rovnako dlhé).

Tu je ukážka rušňa, spočítaj koľko znakov má na dĺžku naozaj:
```
      ___  
 _][__|o|  
<_______|
 /O-O-O    
```

Vozne majú pre zmenu dĺžku 10, ak rátame aj spojku s rušňom a
ostatnými vozňami.

Tu je ukážka:

```
_________ 
|O O O O| 
|_______|-
  o   o   
```

Ak nás rušeň nezaujíma, môžeme jeho dĺžku odrátať (`-9`).

Ak chceme vedieť dĺžku zvyšku vlaku zavoláme jednoducho `/10`,
teda koľko desaťznakových vozňov sa doň vojde.

Preto bude výsledok:

```C++
(dlzka_riadku - 9) / 10
```


# Zadanie

## Celkom dlhý vlak

_Počet bodov: 20_

Skúsený vedúci Matej kupuje miestenky pre deti na sústredenie. Ale zas a znovu stránka
železníc robí blbosti a ukazuje mu vlak s absurdne veľa vozňami. Už sa mu to zopár krát
stalo ale tento krát je to asi rekord. Vozňov je ale moc veľa na to, aby ich spočítal ručne.
Preto sa rozhodol poprosiť vás o pomoc.

### Úloha

Napíšte program, ktorý zistí koľko vozňov má vlak.

### Vstup a Výstup

Na vstupe dostanete obrázok vlaku (štyri riadky).

Na výstup vypíšte jedno číslo - koľko vozňov má vlak. Vozňov bude maximálne 100.

### Príklad

Input:
```
      ___  
 _][__|o|  
<_______|-1
 /O-O-O    
```

Output:

```
0
```

Input:

```
_________ ___      
|O O O O| |o|__][_ 
|_______|-|_______>
  o   o     O-O-O\ 
```
Output:

```
1
```

Input:

```
      ___ _________ _________
 _][__|o| |O O O O| |O O O O|
<_______|-|_______|-|_______|
 /O-O-O     o   o     o   o  
```
Output:

```
2
```