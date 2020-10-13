
#ifndef HEADER_STRUCT_INCLUDED
#define HEADER_STRUCT_INCLUDED

#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cstdlib>
#include <fstream>

using std::cout;
using std::cin;
using std::string;

struct duomuo {
    string Vard, Pav;
    int egz;
    std::vector<int> pazymiai;
    float GP = 0; float GP_med = 0;
};

bool duomuo_sorter(duomuo const&, duomuo const&);
void printer(string);
bool isNumber(string);
int mustInputNumber(string);
duomuo calculations(duomuo);

string opening_statement = "Sveiki, jeigu norite įvesti duomenis ranka, rašykite - r, jeigu nuskaityti iš kursiokai.txt - n:";
string student_number_ask_statement = "\nIveskitite vertinamu mokiniu kieki (pvz.: 5, 10 51): ";
string is_random_statement = "\nJeigu norite duodi mokiniams atistiktinius ivertinimus parasykite - random (jeigu ne - rasykite ne): ";
string student_home_marks_statement = "Iveskite mokinio namu darbu ivertinimus, ivede visus norimus namu darbus iveskite 111\n";

#endif