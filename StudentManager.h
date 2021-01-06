//
// Created by minyk on 12/27/2020.
//

#ifndef INC_2_0V_STUDENTMANAGER_H
#define INC_2_0V_STUDENTMANAGER_H

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


#endif //INC_2_0V_STUDENTMANAGER_H
