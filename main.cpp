#include <iostream>
#include "zlomky.h"

int main() {
    // 1. Vytvoření objektů podle ukázky [cite: 416]
    zlomky z1;                      // Konstruktor bez parametrů (1/1)
    zlomky z2(3, 2);                // Konstruktor s parametry (3/2)
    zlomky z3(2, 6);                // Zlomek, který půjde zkrátit (2/6)
    zlomky z4(0, 2);                // Zlomek s nulou v čitateli [cite: 416]

    // 2. Výpis základních informací [cite: 416]
    std::cout << "Objekt 'z1' vytvoreny konstruktorem bez parametru: " << z1.toString() << ", " << z1.naDesetinneCislo() << std::endl;
    std::cout << "Objekt 'z2' vytvoreny konstruktorem s parametry: " << z2.toString() << ", " << z2.naDesetinneCislo() << std::endl;

    // Ukázka krácení u z3
    std::cout << "Objekt 'z3' pred kracenim: " << z3.toString() << ", " << z3.naDesetinneCislo() << std::endl;
    z3.zkrat();
    std::cout << "Objekt 'z3' po kraceni: " << z3.toString() << std::endl;

    std::cout << "Objekt 'z4' vytvoreny konstruktorem s parametry: " << z4.toString() << ", " << z4.naDesetinneCislo() << std::endl;
    std::cout << "------------------------------------------" << std::endl;

    // 3. Test převrácení
    std::cout << "Objekt 'z2' pred prevracenim: " << z2.toString() << std::endl;
    if (z2.prevrat()) {
        std::cout << "Objekt 'z2' po prevraceni: " << z2.toString() << std::endl;
    }

    if (!z4.prevrat()) {
        std::cout << "Zlomek 'z4' (" << z4.toString() << ") nelze prevratit." << std::endl;
    }
    std::cout << "------------------------------------------" << std::endl;

    // 4. Změna zlomku uživatelem (Settery) [cite: 418, 419, 420]
    int n_cit, n_jmen;
    std::cout << "Zmena zlomku 'z1':" << std::endl;
    std::cout << "Zadej citatele: ";
    std::cin >> n_cit;
    std::cout << "Zadej jmenovatele: ";
    std::cin >> n_jmen;

    z1.set_c(n_cit); // Použití setteru pro čitatele
    z1.set_j(n_jmen); // Použití setteru pro jmenovatele (včetně tvé kontroly nuly)

    std::cout << "Objekt 'z1' po zmene: " << z1.toString() << std::endl;

    return 0;
}