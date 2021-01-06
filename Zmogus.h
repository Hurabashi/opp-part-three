//
// Created by minyk on 12/27/2020.
//

#ifndef INC_2_0V_ZMOGUS_H
#define INC_2_0V_ZMOGUS_H
#pragma once
#include "Header.h"
class Zmogus
{
protected:
    string vardas_;
    string pavarde_;
public:
    void setVardas(string v) {
        vardas_ = v;
    }
    string getVardas() {
        return vardas_;
    }

    void setPavarde(string p) {
        pavarde_ = p;
    }
    string getPavarde() {
        return pavarde_;
    }
};

#endif //INC_2_0V_ZMOGUS_H
