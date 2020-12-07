#pragma once
#include "Header.h"
class Studentas {

private:
    string vardas_;
    string pavarde_;
    float egzaminas_;
    std::vector<float> nd_;
    float galutinis_pazymys_;
public:
    Studentas(string vard, string pavard, float egzam, vector<float> nd) {
        vardas_ = vard;
        pavarde_ = pavard;
        egzaminas_ = egzam;
        nd_ = nd;
    }

    float skaiciuok();
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

    void setEgzaminas(float e) {
        egzaminas_ = e;
    }
    double getEgzaminas() {
        return egzaminas_;
    }

    void setND(vector<float> nd) {
        nd_ = nd;
    }
    vector<float> getND() {
        return nd_;
    }

    void setGP(float gp) {
        galutinis_pazymys_ = gp;
    }
    float getGP() {
        return galutinis_pazymys_;
    }
};

