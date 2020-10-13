
// By Dominykas Venclovas DM2 2020-09
/*
* To do:
* Pilnai sulietuvinti isvesti/padaryti viska angliskai
*/

#include "Header_struct.h"

int main()
{
    setlocale(LC_ALL, "Lithuanian");

    duomuo Eil;
    std::vector<duomuo> Eil_vect;
    printer(opening_statement);
    string ranka;
    while (true) {
        try {
            cin >> ranka;
            if (ranka != "n" && ranka != "r") {
                throw "Ivedete netinkama reiksme!\n";
            }
            break;
            
        }
        catch (const char* error) {
            printer(error);
            printer(opening_statement);
        }
    }

    if (ranka == "r") {

        int students;
        printer(student_number_ask_statement);
        students = mustInputNumber(student_number_ask_statement);

        printer(is_random_statement);
        string atsitiktinis;
        cin >> atsitiktinis;

        for (int k = 0; k < students; k++) {
            printer("\nIveskite duomenis: Vardas, Pavarde\n");
            int pazymys = 1;
            //Ivestis
            cin >> Eil.Vard >> Eil.Pav;
            if (atsitiktinis == "random") {
                Eil.egz = (std::rand() % 10) + 1;
                for (int i = 0; i < (std::rand() % 20) + 1; i++) {
                    pazymys = (std::rand() % 10) + 1;
                    Eil.GP = Eil.GP + (float)pazymys;
                    Eil.pazymiai.push_back(pazymys);
                }
            }
            else {
                printer("Iveskite egzamino pazymi\n");
                Eil.egz = mustInputNumber("Iveskite egzamino pazymi\n");
                printer(student_home_marks_statement);
                while (true) {
                    pazymys = mustInputNumber(student_home_marks_statement);
                    if (pazymys == 111) {
                        break;
                    }
                    Eil.GP = Eil.GP + (float)pazymys;
                    Eil.pazymiai.push_back(pazymys);
                }
            }
            //Skaiciavimas
            Eil = calculations(Eil);
            //Pridejimas i vektoriu
            Eil_vect.push_back(Eil);
            //Vektoriaus isvalymas
            Eil.pazymiai.clear();
        }
        //Vidurkio arba mediano pasirinkimas
        printer("\nDuomenu ivestis baigta\n");
        printer("Pasirinkite ar norite naudoti vidurki ar mediana, norint apskaiciuoti studentu namu darbu vidutini ivertinima (iveskite v, vidurkiui arba m - medianai):");
        char ivertinimo_tipas = 'v';
        cin >> ivertinimo_tipas;

        //Isvedimas i lentele
        cout << std::endl << std::endl;
        printer("Vardas      Pavardė     ");
        printer("Galutinis");
        if (ivertinimo_tipas == 'v') printer("(vid)");
        else printer("(med)");
        printer("\n------------------------------\n");
        for (int j = 0; j < students; j++) {
            cout << std::left << std::setw(13) << Eil_vect[j].Vard;
            cout << std::left << std::setw(13) << Eil_vect[j].Pav;
            if (ivertinimo_tipas == 'v') {
                cout << std::left << std::setw(13) << std::fixed << std::setprecision(2) << Eil_vect[j].GP << std::endl;
            }
            else {
                cout << std::left << std::setw(13) << std::fixed << std::setprecision(2) << Eil_vect[j].GP_med << std::endl;
            }
        }
        //Duomenu isvalymas
        Eil_vect.clear();
    }
    else if (ranka == "n") {
        string myText;
        // Read from the text file
        std::ifstream MyReadFile("C://Users//minyk//source//repos//FirstProjectOOP//kursiokai.txt");
        if (!MyReadFile) {
            printer("\nNepavyko pasiekti failo, pasitkrinkite ar jis tikrai pavadintas 'kursiokai.txt'.\n");
            exit(1);
        }

        //praleidziame, pirma eilute
        std::getline(MyReadFile, myText);

        int students = 0;// skaiciuosime studentu kieki patogesniam atspausdinimui
        //nuskaitome
        while (!MyReadFile.eof()) {
            students++;

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

        // rusiuojame
        std::sort(Eil_vect.begin(), Eil_vect.end(), &duomuo_sorter);

        // spausdiname rezultatus
        cout << std::endl << std::endl;
        cout << "Vardas         Pavarde          Galutinis (Vid.)   Galutinis (Med.)";
        cout << "\n-------------------------------------------------------------\n";
        for (int j = 0; j < students; j++) {
            cout << std::left << std::setw(16) << Eil_vect[j].Vard;
            cout << std::left << std::setw(16) << Eil_vect[j].Pav;
            
            cout << std::left << std::setw(20) << std::fixed << std::setprecision(2) << Eil_vect[j].GP;
            cout << std::left << std::setw(16) << std::fixed << std::setprecision(2) << Eil_vect[j].GP_med << std::endl;
        }
        //Duomenu isvalymas
        Eil_vect.clear();


    }
}

