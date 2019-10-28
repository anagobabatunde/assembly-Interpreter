# TIC-CRW2 2019 APE
![companyLogo](https://newsroom.ionis-group.com/wp-content/uploads/2018/12/etna-logo-1-noir.png)

## Informations
 1. Name of project : **TIC-CRW2**
 2. Duration : **3 weeks** (*20 oct. to 9 nov.*)

## Goal
> AbstractVM est une machine à pile qui permet d'évaluer des expressions arithmétiques simples. Ces expressions sont fournies à la machine par le biais de programmes écrits dans un langage s'apparentant à l'assembleur.

En voici un petit exemple :
```
; exemple.avm
push int32(42`
push int32(33)
add
push float(44.55)
mul
push double(42.42)
push int32(42)
pop
assert double(42.42)
exit
```

## Requirements
- Debian **10**

# Utilisation

## Lauch with Docker
```
docker run --rm -it -v $(PWD):/workdir/ --name crw2 jaschac/debian-gcc /bin/bash
# OR
docker build . -t containers.ikf3.com/etna/tic-crw2
```

## Additional Data
**Contributors:**
[talamo_a](www.ikf3.com), [anago_b](www.anago.me)

