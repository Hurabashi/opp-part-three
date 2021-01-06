//
// Created by minyk on 12/27/2020.
//

#include "StudentManager.h"
vector<Studentas> StudentManager::readStudents(string file_name, int studentu_sk) {
    std::ifstream MyReadFile(file_name);
    if (!MyReadFile) {
        cout << "\nNepavyko pasiekti failo, pasitkrinkite ar jis tikrai tokiu pavadinimu.\n";
        exit(1);
    }


    while (!MyReadFile.eof()) {
        string vardas;
        string pavarde;
        MyReadFile >> vardas >> pavarde;
        float pazymys = 1;
        vector<float> pazymiai;
        for (int i = 0; i < 5; i++) {
            MyReadFile >> pazymys;
            pazymiai.push_back(pazymys);
        }
        float egz;
        MyReadFile >> egz;
        Studentas student(vardas, pavarde, egz, pazymiai);
        student.setGP(student.skaiciuok());
        students_.push_back(student);
    }
    return students_;
}

void StudentManager::createStudents(string file_name, bool Failed) {

    std::ofstream myfile;
    myfile.open(file_name);

    myfile << "Vardas          Pavarde         Galutinis (Vid.)";
    myfile << "\n----------------------------------------------------\n";
    vector<Studentas> students = Failed ? failed_ : students_;
    for (Studentas stud : students) {
        myfile << std::left << std::setw(16) << stud.getVardas();
        myfile << std::left << std::setw(16) << stud.getPavarde();

        myfile << std::left << std::setw(20) << std::fixed << std::setprecision(2) << stud.getGP() << std::endl;
    }
    // uzdarymas
    myfile.close();
}

void StudentManager::testing(int studentu_sk, string base_file, string vargs_file, string galvoc_file) {
    Timer t;
    students_ = this->readStudents(base_file, studentu_sk);
    cout << "Failo nuskaitymas uztruko: " << t.elapsed() << " s\n";


    Timer t2;
    vector<Studentas>::iterator it = students_.begin();
    while (it != students_.end()) {
        if ((*it).getGP() < 5.0f) {
            failed_.push_back(*it);
            it = students_.erase(it);
        }
        else ++it;
    }
    cout << "Failo rusiavimas uztruko: " << t2.elapsed() << " s\n";

    cout << "Kuriame failus...\n";
    this->createStudents(galvoc_file, false);
    this->createStudents(vargs_file, true);

    cout << "Bendrai uztruko: " << t.elapsed() << " s\n" << "\n";
}