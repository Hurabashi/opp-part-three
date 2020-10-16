
#pragma once
#include "Header.h"

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

extern string opening_statement;
extern string student_number_ask_statement;
extern string is_random_statement;
extern string student_home_marks_statement;
