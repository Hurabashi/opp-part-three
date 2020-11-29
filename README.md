# Objektinio programavimo su C++ pirmoji užduotis

* [1 dalis](https://github.com/Hurabashi/oop-with-c-plus-plus/tree/V0.1)
* [2 dalis](https://github.com/Hurabashi/oop-with-c-plus-plus/tree/V0.2)
* [3 dalis](https://github.com/Hurabashi/oop-with-c-plus-plus/tree/V0.3.1)
* [4 dalis](https://github.com/Hurabashi/oop-with-c-plus-plus/tree/V0.4)
* [5 dalis](https://github.com/Hurabashi/oop-with-c-plus-plus/tree/V0.5)

## 0.5/0.4 Versijos testavimas (1 strategija):
     Vector duomenų tipas                                          List duomenų tipas    

|      Įrašų skaičius       |    Operacijos    | Kiek užtruko | |     Įrašų skaičius   |    Operacijos    | Kiek užtruko | |
|---------------------|:------------------:|--------------:|-------------------------|---------------------|:------------------:|--------------:|---------------------|
| 1000 |    nuskaitymas iš failų   | 0.08 s | | 1000 |    nuskaitymas iš failų   |   0.04 s | |
|      |    studentų rusiavimas    | 0.02 s | |      |    studentų rusiavimas    |   0.01 s | |
| 10000 |    nuskaitymas iš failų   | 0.57 s | | 10000 |    nuskaitymas iš failų   |   0.42 s | |
|      |    studentų rusiavimas    | 0.17 s | |      |    studentų rusiavimas    |   0.11 s | |
| 100000 |    nuskaitymas iš failų   | 4.86 s | | 100000 |    nuskaitymas iš failų   |   4.21 s | |
|      |    studentų rusiavimas    | 1.55 s | |      |    studentų rusiavimas    |   1.03 s | |
| 1000000 |    nuskaitymas iš failų   | 46.86 s | | 1000000 |    nuskaitymas iš failų   |   40.37 s | |
|      |    studentų rusiavimas    | 15.37 s | |      |    studentų rusiavimas    |   9.57 s | ||
| 10000000 |    nuskaitymas iš failų   | 7.97 min | | 10000000 |    nuskaitymas iš failų   |   6.12 min | |
|      |    studentų rusiavimas    | 5.27 min | |      |    studentų rusiavimas    |   5.93 min | |

## 1.0 Versijos testavimas (2 strategija):
     Vector duomenų tipas                                          List duomenų tipas    

|      Įrašų skaičius       |    Operacijos    | Kiek užtruko | |     Įrašų skaičius   |    Operacijos    | Kiek užtruko | |
|---------------------|:------------------:|--------------:|-------------------------|---------------------|:------------------:|--------------:|---------------------|
| 1000 |    nuskaitymas iš failų   | 0.05 s | | 1000 |    nuskaitymas iš failų   |   0.04 s | |
|      |    studentų rusiavimas    | 0.02 s | |      |    studentų rusiavimas    |   0.01 s | |
| 10000 |    nuskaitymas iš failų   | 0.58 s | | 10000 |    nuskaitymas iš failų   |   0.51 s | |
|      |    studentų rusiavimas    | 0.17 s | |      |    studentų rusiavimas    |   0.15 s | |
| 100000 |    nuskaitymas iš failų   | 5.45 s | | 100000 |    nuskaitymas iš failų   |   4.32 s | |
|      |    studentų rusiavimas    | 1.81 s | |      |    studentų rusiavimas    |   1.28 s | |
| 1000000 |    nuskaitymas iš failų   | 52.59 s | | 1000000 |    nuskaitymas iš failų   |   40.09 s | |
|      |    studentų rusiavimas    | 16.89 s | |      |    studentų rusiavimas    |   12.30 s | ||

   Įranga su kuria atliktas testavimas:
| Tipas | Įranga |
| --------| --------|
| OS: | Windows 10, 64-bit|
| CPU: | i5-6400 2.70 GHz |
| RAM: | 8.00 GB |
| SSD: | 128.00 GB |

