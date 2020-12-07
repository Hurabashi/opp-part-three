# Objektinio programavimo su C++ antroji užduotis

* [1 dalis](https://github.com/Hurabashi/oop-with-c-plus-plus/tree/V1.1)
* [2 dalis](https://github.com/Hurabashi/oop-with-c-plus-plus/tree/V1.2)


## 1.1 Versijos testavimas (debug):
     Naudojant funkcinį programavimą                                          Naudojant objektinį programavimą    

|      Įrašų skaičius       |    Operacijos    | Kiek užtruko | |     Įrašų skaičius   |    Operacijos    | Kiek užtruko | |
|---------------------|:------------------:|--------------:|-------------------------|---------------------|:------------------:|--------------:|---------------------|
| 100000 |    nuskaitymas iš failų   | 5.45 s | | 100000 |    nuskaitymas iš failų   |   6.56 s | |
|      |    studentų rusiavimas    | 1.81 s | |      |    studentų rusiavimas    |   3006.34 s | |
| 1000000 |    nuskaitymas iš failų   | 52.59 s | | 1000000 |    nuskaitymas iš failų   |   58.88 s | |
|      |    studentų rusiavimas    | 16.89 s | |      |    studentų rusiavimas    |   >24 h | ||

Iš to galime matyti, kad metodų taikymas užemė daug daugiau laiko nei funkcijų, bet taip pat vertėtų pastebėti, kad jis užėmė mažiau daug mažiau laikinosios atminties.
Dabar testuosime flag'us su objektine versija (release):

|    Įrašų skaičius  | 01 | 02 | 03 |
|----------------------|----|----|----|
| 10000  | 0.43 s  | 0.46 s| 0.44 s|
| 100000 | 26.53 s | 26.58 s| 27.21 s|


   Įranga su kuria atliktas testavimas:
| Tipas | Įranga |
| --------| --------|
| OS: | Windows 10, 64-bit|
| CPU: | i5-6400 2.70 GHz |
| RAM: | 8.00 GB |
| SSD: | 128.00 GB |

