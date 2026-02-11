//
// Created by adamb on 10.02.2026.
//

#include "cas.h"
#include <ctime>
#include <iostream>
#include <iomanip>
cas::cas() {
    set_sysTime();
}

cas::cas(int h, int m, int s) {
    if (jePlatny(h, m, s)){
        hodiny = h;
        minuty = m;
        sekundy = s;
    } else {
        set_sysTime();
    }
}

cas::cas(const cas &staryCas) {
    hodiny = staryCas.hodiny;
    minuty = staryCas.minuty;
    sekundy = staryCas.sekundy;
}

cas::~cas() {
}

int cas::sekundyOdPulnoci() const {
    return hodiny*3600+minuty*60+sekundy;
}

void cas::vypisCas() {
    std::cout << std::setw(2) << std::setfill('0') << hodiny << ":"
    << std::setw(2) << std::setfill('0') << minuty << ":" <<
        std::setw(2) << std::setfill('0') << sekundy << std::endl;
}

bool cas::nastavCas(int h, int m, int s) {
    if (jePlatny(h, m, s)) {
        hodiny = h;
        minuty = m;
        sekundy = s;
        return true;
    }
    return false;
}

int cas::nastavZeSekund(int celkemSekund){
    int dny = celkemSekund / 86400;
    int zbytek = celkemSekund % 86400;
    hodiny = zbytek / 3600;
    minuty = (zbytek % 3600) /60;
    sekundy = zbytek % 60;
    return dny;
}

void cas::set_sysTime() {
    time_t t = time(nullptr);
    tm *ted = localtime(&t);

    this->hodiny = ted->tm_hour;
    this->minuty = ted->tm_min;
    this->sekundy = ted->tm_sec;
}


bool cas::jePlatny(int hod, int min, int sek) {
    if (hod >= 0 && hod <= 23 && min >= 0 && min <= 59 && sek >= 0 && sek <= 59) {
        return true;
    } else {
        return false;
    }
}
