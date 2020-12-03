# Instrukcija
Norint įvykdyti programą reikia turėti atitinkamai pavadintus failus: "studentai_1k.txt", "studentai_10k.txt", "studentai_100k.txt", "studentai_1kk.txt".
Šie teksto failai, tai tiesiog FileGenerator.cpp sugeneruoti pseudo-atsitiktiniai studentų vardai, pavardės ir įvertinimai. O 1k - tūkstantis studentų, 10k dešimt tūkstančių studentų ir t.t. Jie bus sugeneruoti vieną kartą paleidus FileGenerator.cpp

Struktūroje duomuo, saugoma studento informacija: Vardas, Pavardė, pažymiai, egzamino pažymys, galutinis pažymys bei galutinis pažymys skaičiuotas su mediana.
Timer klasė - matuoja laiką.
calculations funkcija - skaičioja duoto studento galutinį pažymį.
reading_file funkcija - nuskaito duotą failą ir grąžina studentų list.
create_file_from_list funkcija - sukuria failą duotu pavadinimu iš duoto studentų list.
testavimas - esminė kitas funkcijas bei klases jungianti funkcija, joje atliekamos visas studentų list rušiavimas bei kitų funkcijų pritaikymas, įvykdant funkcija sugeneruoja vargšiukų ir galvočių failus iš duoto studentų failo, ji taip pat spausdina laikus, kiek užtruko operacijų įgyvendimas.

main.cpp - įgyvendinta testavimo funkcija.



