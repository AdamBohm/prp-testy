//
// Created by adamb on 10.02.2026.
//

#ifndef PROVERKACAS_CAS_H
#define PROVERKACAS_CAS_H


class cas {
public:
    cas(); //nastavi systime
    cas(int h, int m, int s); //kontrola platnosti, jinak systime
    cas(const cas &staryCas); //kopirovaci konstruktor
    ~cas();

    int sekundyOdPulnoci() const;
    void vypisCas();
    bool nastavCas(int h, int m, int s);
    int nastavZeSekund(int celkemSekund);

    private:
    int hodiny;
    int minuty;
    int sekundy;
    void set_sysTime();
    bool jePlatny(int hod, int min, int sek);
};


#endif //PROVERKACAS_CAS_H
