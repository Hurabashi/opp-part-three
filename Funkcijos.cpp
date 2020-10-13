#include "Header_struct.h"

void printer(string words) {
    cout << words;
}
bool duomuo_sorter(duomuo const& lhs, duomuo const& rhs) {
    if (lhs.Vard != rhs.Vard)
        return lhs.Vard < rhs.Vard;
    if (lhs.Pav != rhs.Pav)
        return lhs.Pav < rhs.Pav;
    return lhs.GP < rhs.GP;
}

bool isNumber(string s)
{
    for (int i = 0; i < s.length(); i++) {
        if (isdigit(s[i]) == false) {
            return false;
        }
    }
    return true;
}

int mustInputNumber(string message) {
    string number;
    while (true) {
        try
        {
            cin >> number;
            if (!isNumber(number)) {
                throw "Ivedete ne skaiciu!!!\n";

            }
            break;
        }
        catch (const char* error) {
            cout << error;
            cout << message;
        }
    }
    cout << " be stoi: " << " " << number;
    cout << "\n su stoi:   " << stoi(number);
    return stoi(number);
}

duomuo calculations(duomuo Eil) {
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
    return Eil;
}

