// By Dominykas Venclovas DM2 2020-09
/*
* To do:
* try except duomenu tipams ir range(1-10)
* Pilnai sulietuvinti isvesti/padaryti viska angliskai
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cstdlib>

using std::cout;
using std::cin;
using std::string;

struct duomuo {
    string Vard, Pav;
    int paz[10], egz;
    std::vector<int> pazymiai;
    float GP = 0; float GP_med = 0;
};

int main()
{

    duomuo Eil; duomuo Eil_mas[5];
    std::vector<duomuo> Eil_vect;

    int students;
    cout << "Sveiki, iveskitite vertinamu mokiniu kieki (pvz.: 5, 10 51): ";
    cin >> students;
  
    
    cout << "\nJeigu norite duodi mokiniams atistiktinius ivertinimus parasykite - random (jeigu ne - rasykite ne): ";
    string atsitiktinis;
    cin >> atsitiktinis;

    for (int k = 0; k < students; k++) {
        cout << "\nIveskite duomenis: Vardas, Pavarde\n";
        int pazymys = 1;
        //Ivestis
        cin >> Eil.Vard >> Eil.Pav;
        if (atsitiktinis == "random") {
            Eil.egz = (std::rand() % 10) + 1;
            for (int i = 0; i < (std::rand() % 20) + 1; i++){
                pazymys = (std::rand() % 10) + 1;
                Eil.GP = Eil.GP + (float)pazymys;
                Eil.pazymiai.push_back(pazymys);
            }
        }
        else {
            cout << "Iveskite egzamino pazymi\n";
            cin >> Eil.egz;
            cout << "Iveskite mokinio namu darbu ivertinimus, ivede visus norimus namu darbus iveskite neigiama skaiciu arba nuli\n";
            while (pazymys > 0) {
                cin >> pazymys;
                if (pazymys < 0) {
                    break;
                }
                Eil.GP = Eil.GP + (float)pazymys;
                Eil.pazymiai.push_back(pazymys);
            }
        }
        //Skaiciavimas
        Eil.GP = Eil.GP / 5.0;
        Eil.GP = Eil.GP * 0.4 + 0.6 * Eil.egz;

        std::sort(Eil.pazymiai.begin(), Eil.pazymiai.end());
        if (Eil.pazymiai.size() % 2 == 1) {
            Eil.GP_med = Eil.pazymiai[Eil.pazymiai.size() / 2];
            Eil.GP_med = Eil.GP_med * 0.4 + 0.6 * Eil.egz;
        }
        else {
            Eil.GP_med = (Eil.pazymiai[Eil.pazymiai.size() / 2] + Eil.pazymiai[(Eil.pazymiai.size() / 2) - 1]) / 2.0;
            Eil.GP_med = Eil.GP_med * 0.4 + 0.6 * Eil.egz;
        }

        //Isvedimas testavimui
        /*
        cout << "mediana?: " << Eil.GP_med << " ";
        for (int i = 0; i < Eil.pazymiai.size(); i++) cout << "\n" << Eil.pazymiai[i];
        cout << "Ivesta:\n" << Eil.Vard << " " << Eil.Pav << " " << Eil.egz;
        for (int i = 0; i < 5; i++) cout << " " << Eil.paz[i];
        cout << " " << Eil.GP << std::endl;
        cout << "    " << Eil.paz[2] << std::endl;
        */

        //Pridejimas i vektoriu
        Eil_vect.push_back(Eil);
        //Vektoriaus isvalymas
        Eil.pazymiai.clear();
    }
    //Vidurkio arba mediano pasirinkimas
    cout << "\nDuomenu ivestis baigta\n";
    cout << "Pasirinkite ar norite naudoti vidurki ar mediana, norint apskaiciuoti studentu namu darbu vidutini ivertinima (iveskite v, vidurkiui arba m - medianai):";
    char ivertinimo_tipas = 'v';
    cin >> ivertinimo_tipas;

    //Isvedimas i lentele
    cout << std::endl << std::endl;
    cout << "Vardas      Pavardė     ";
    cout << "Galutinis";
    if (ivertinimo_tipas == 'v') cout << "(vid)";
    else cout << "(med)";
    cout << "\n------------------------------\n";
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
