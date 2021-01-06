#include <iostream>
#include "StudentManager.h"
int main() {
    StudentManager manager1;
    StudentManager manager2;

    cout << "Testuojame su 1000 irasu:\n";
    manager1.testing(1000, "studentai_1k.txt", "vargsiukai_1k.txt", "galvociai_1k.txt");

    cout << "Testuojame su 10000 irasu:\n";
    manager2.testing(10000, "studentai_10k.txt", "vargsiukai_10k.txt", "galvociai_10k.txt");

    //cout << "Testuojame su 100000 irasu:\n";
    //manager2.testing(100000, "studentai_100k.txt", "vargsiukai_100k.txt", "galvociai_100k.txt");

    //cout << "Testuojame su 1000000 irasu:\n";
    //manager2.testing(1000000, "studentai_1kk.txt", "vargsiukai_1kk.txt", "galvociai_1kk.txt");

    return 0;
}
