#include <iostream>
#include "cas.h"

using std::cout;
using std::cin;
using std::endl;

int main() {
    cout << "--- cas oprava ---" << endl << endl;

    // 1. Objekt vytvořený výchozím konstruktorem (systémový čas)
    cas c1;
    cout << "Objekt vytvoreny vychozim konstruktorem c1" << endl;
    cout << "pocet sekund od pulnoci " << c1.sekundyOdPulnoci() << endl;
    c1.vypisCas();
    cout << endl;

    // 2. Objekt vytvořený konstruktorem s parametry (00:00:01)
    cas c2(0, 0, 1);
    cout << "Objekt vytvoreny konstruktorem s parametry c2" << endl;
    cout << "pocet sekund od pulnoci " << c2.sekundyOdPulnoci() << endl;
    c2.vypisCas();
    cout << endl;

    // 3. Objekt vytvořený konstruktorem s parametry (23:59:59)
    cas c3(23, 59, 59);
    cout << "Objekt vytvoreny konstruktorem s parametry c3" << endl;
    cout << "pocet sekund od pulnoci " << c3.sekundyOdPulnoci() << endl;
    c3.vypisCas();
    cout << endl;

    // 4. Objekt vytvořený kopírovacím konstruktorem
    cas c4(c1);
    cout << "Objekt vytvoreny kopirovacim konstruktorem c4(c1)" << endl;
    cout << "pocet sekund od pulnoci " << c4.sekundyOdPulnoci() << endl;
    c4.vypisCas();
    cout << endl;

    // 5. Nastavení času u objektu c1
    int h, m, s;
    cout << "Nastaveni casu u objektu c1" << endl;
    cout << "Zadej hodiny: "; cin >> h;
    cout << "Zadej minuty: "; cin >> m;
    cout << "Zadej sekundy: "; cin >> s;

    if (c1.nastavCas(h, m, s)) {
        cout << "pocet sekund od pulnoci " << c1.sekundyOdPulnoci() << endl;
        cout << "Cas po zmene ";
        c1.vypisCas();
    } else {
        cout << "Zadan neplatny cas!" << endl;
    }
    cout << endl;

    // 6. Převedení sekund na čas u objektu c2
    int sek;
    cout << "Prevedeni sekund na cas u objektu c2" << endl;
    cout << "Zadej pocet sekund: "; cin >> sek;

    int dny = c2.nastavZeSekund(sek);
    cout << "Sekundy " << sek << " dny " << dny << " a cas ";
    c2.vypisCas();
    cout << endl;

    cout << "Pro pokracovani stiskni klavesu 'k'...";
    char k; cin >> k;

    return 0;
}