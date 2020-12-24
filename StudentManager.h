#pragma once
#include "Studentas.h"
class StudentManager {
private:
    vector<Studentas> students_;
    vector<Studentas> failed_;
public:
    StudentManager() {

    }
    vector<Studentas> readStudents(string file_name, int studentu_sk);
    void createStudents(string file_name, bool Failed);
    void testing(int studentu_sk, string base_file, string vargs_file, string galvoc_file);

    void setStudents(vector<Studentas> students) {
        students_ = students;
    }
    vector<Studentas> getStudentai() {
        return students_;
    }

    void setFailed(vector<Studentas> students) {
        failed_ = students;
    }
    vector<Studentas> getFailed() {
        return failed_;
    }
};

