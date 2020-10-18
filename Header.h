#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include <vector>
#include <map>
#include <chrono>
#include <random>
#include <cstdlib>
#include <cctype>
#include <chrono>

using std::string;
using std::cout;

using std::vector;
using std::map;
using std::mt19937;


struct duomuo {
    string Vard, Pav;
    int egz = 1;
    std::vector<int> pazymiai;
    float GP = 0; float GP_med = 0;
};

class Timer
{
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> start;
public:
    Timer() : start{ std::chrono::high_resolution_clock::now() } {}
    void reset() {
        start = std::chrono::high_resolution_clock::now();
    }
    double elapsed() const {
        return std::chrono::duration<double>
            (std::chrono::high_resolution_clock::now() - start).count();
    }
};

using hrClock = std::chrono::high_resolution_clock;

typedef std::uniform_int_distribution<int>  int_distribution;

struct zmogus {
	string vardas, pavarde;
};

char lytis() {
    mt19937 mt(static_cast<long unsigned int>(hrClock::now().time_since_epoch().count()));
    int_distribution dist(0,1);

    if (0 == dist(mt)) {
        return 'v';
    }
    else {
        return 'm';
    }
}

int rand_number() {
    mt19937 mt(static_cast<long unsigned int>(hrClock::now().time_since_epoch().count()));
    int_distribution dist(1, 10);

    return dist(mt);
}

zmogus gen_map(char lytis) {

    mt19937 mt(static_cast<long unsigned int>(hrClock::now().time_since_epoch().count()));
    int_distribution dist(100, 109);

    zmogus a;
    if (lytis == 'v') {
        map<int, string> vardai, pavardes;
        vardai[100] = "Vytautas";
        vardai[101] = "Tomas";
        vardai[102] = "Lukas";
        vardai[103] = "Deividas";
        vardai[104] = "Mantas";
        vardai[105] = "Petras";
        vardai[106] = "Jonas";
        vardai[107] = "Dominykas";
        vardai[108] = "Darius";
        vardai[109] = "Simas";

        a.vardas = vardai[dist(mt)];

        pavardes[200] = "Kazlauskas";
        pavardes[201] = "Petrauskas";
        pavardes[202] = "Jankauskas";
        pavardes[203] = "Ramanauskas";
        pavardes[204] = "Urbonas";
        pavardes[205] = "Venclovas";
        pavardes[206] = "Vasiliauskas";
        pavardes[207] = "Pocius";
        pavardes[208] = "Paulauskas";
        pavardes[209] = "Navickas";

        a.pavarde = pavardes[dist(mt) + 100];
    }
    else {
        map<int, string> vardai, pavardes;
        vardai[100] = "Monika";
        vardai[101] = "Toma";
        vardai[102] = "Luka";
        vardai[103] = "Irma";
        vardai[104] = "Lina";
        vardai[105] = "Kristina";
        vardai[106] = "Jovita";
        vardai[107] = "Dominyka";
        vardai[108] = "Ona";
        vardai[109] = "Egle";

        a.vardas = vardai[dist(mt)];

        pavardes[200] = "Kazlauskaite";
        pavardes[201] = "Petrauskaite";
        pavardes[202] = "Jankauskaite";
        pavardes[203] = "Ramanauskaite";
        pavardes[204] = "Urbonaite";
        pavardes[205] = "Venclovaite";
        pavardes[206] = "Vasiliauskaite";
        pavardes[207] = "Povilaite";
        pavardes[208] = "Paulauskaite";
        pavardes[209] = "Navickaite";

        a.pavarde = pavardes[dist(mt) + 100];

    }
    
    return a;
}

void generator_of_students(int students, string file_name) {
    std::ofstream myfile;
    myfile.open(file_name);

    for (int i = 1; i < students; i++) {
        char lytis_char = lytis();
        myfile << gen_map(lytis_char).vardas << " " << gen_map(lytis_char).pavarde;
        for (int j = 0; j < 5; j++) {
            myfile << " ";
            myfile << rand_number();
        }
        myfile << " " << rand_number();
        myfile << "\n";
    }
    myfile.close();
 
}

duomuo calculations(duomuo Eil) {
    Eil.GP = Eil.GP / 5.0f;
    Eil.GP = Eil.GP * 0.4f + 0.6f * Eil.egz;

    std::sort(Eil.pazymiai.begin(), Eil.pazymiai.end());
    if (Eil.pazymiai.size() % 2 == 1) {
        Eil.GP_med = float(Eil.pazymiai[Eil.pazymiai.size() / 2]);
        Eil.GP_med = Eil.GP_med * 0.4f + 0.6f * Eil.egz;
    }
    else {
        Eil.GP_med = (Eil.pazymiai[Eil.pazymiai.size() / 2] + Eil.pazymiai[(Eil.pazymiai.size() / 2) - 1]) / 2.0f;
        Eil.GP_med = Eil.GP_med * 0.4f + 0.6f * Eil.egz;
    }
    return Eil;
}

std::vector<duomuo> reading_file(string file_name) {
    std::ifstream MyReadFile(file_name);
    if (!MyReadFile) {
        cout << "\nNepavyko pasiekti failo, pasitkrinkite ar jis tikrai pavadintas 'kursiokai.txt'.\n";
        exit(1);
    }
    cout << "Pavyko atidaryti faila... \n";
    duomuo Eil;
    std::vector<duomuo> Eil_vect;

    //nuskaitome
    while (!MyReadFile.eof()) {

        MyReadFile >> Eil.Vard >> Eil.Pav;
        int pazymys = 1;
        for (int i = 0; i < 5; i++) {
            MyReadFile >> pazymys;
            Eil.GP = Eil.GP + (float)pazymys;
            Eil.pazymiai.push_back(pazymys);
        }
        MyReadFile >> Eil.egz;
        //skaiciuojame
        Eil = calculations(Eil);
        //Pridejimas i vektoriu
        Eil_vect.push_back(Eil);
        //Vektoriaus isvalymas
        Eil.pazymiai.clear();

    }
    // uzdarome
    MyReadFile.close();
    return Eil_vect;
}

void create_file_from_vector(std::vector<duomuo> Eil_vect, string file_name) {

    std::ofstream myfile;
    myfile.open(file_name);

    myfile << "Vardas         Pavarde          Galutinis (Vid.)   Galutinis (Med.)";
    myfile << "\n-------------------------------------------------------------\n";
    for (int j = 0; j < Eil_vect.size(); j++) {
        myfile << std::left << std::setw(16) << Eil_vect[j].Vard;
        myfile << std::left << std::setw(16) << Eil_vect[j].Pav;

        myfile << std::left << std::setw(20) << std::fixed << std::setprecision(2) << Eil_vect[j].GP;
        myfile << std::left << std::setw(16) << std::fixed << std::setprecision(2) << Eil_vect[j].GP_med << std::endl;
    }
    //Duomenu isvalymas ir uzdarymas
    Eil_vect.clear();
    myfile.close();
}

void testavimas(int studentu_sk, string base_file, string vargs_file, string galvoc_file) {
    Timer t;
    //cout << "Kuriame faila... \n";
    Timer t1;
    generator_of_students(studentu_sk, base_file);
    cout << "Failo sukurimas uztruko: " << t1.elapsed() << " s\n";

    //cout << "Skaitome faila... \n";
    Timer t2;
    std::vector<duomuo> Eil_vect = reading_file(base_file);
    cout << "Failo nuskaitymas uztruko: " << t2.elapsed() << " s\n";

    //cout << "Rusiuojame... \n";
    Timer t3;
    std::vector<duomuo> Eil_vect_vargsiukai;
    std::vector<duomuo> Eil_vect_galvociai;
    for (int j = 0; j < Eil_vect.size(); j++) {
        if (Eil_vect[j].GP < 5.0f) {
            Eil_vect_vargsiukai.push_back(Eil_vect[j]);
        }
        else {
            Eil_vect_galvociai.push_back(Eil_vect[j]);
        }
    }
    cout << "Vektoriaus dydis: " << Eil_vect.size() << "\n";
    //Duomenu isvalymas
    Eil_vect.clear();
    cout << "Failo rusiavimas uztruko: " << t3.elapsed() << " s\n";


    //cout << "Kuriame failus...\n";
    Timer t4;
    create_file_from_vector(Eil_vect_galvociai, galvoc_file);
    cout << "Failo 'galvociai' kurimas uztruko: " << t4.elapsed() << " s\n";
    Timer t5;
    create_file_from_vector(Eil_vect_vargsiukai, vargs_file);
    cout << "Failo 'vargsiukai' kurimas uztruko: " << t4.elapsed() << " s\n";

    cout << "\n";
    cout << "Bendrai uztruko: " << t.elapsed() << " s\n" << "\n";
}
