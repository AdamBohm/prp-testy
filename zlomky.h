//
// Created by adamb on 11.02.2026.
//

#ifndef PROVERKAZLOMKY_ZLOMKY_H
#define PROVERKAZLOMKY_ZLOMKY_H
#include <string>

class zlomky {

private:
    int jmenovatel; // nesmi byt nula
    int citatel;

    int nsd(int a, int b);
public:
    zlomky();
    zlomky(int c, int j);
    ~zlomky();

    int get_j();
    int get_c();

    void set_j(int j);
    void set_c(int c);

    std::string toString() const;
    void zkrat();
    float naDesetinneCislo() const;
    bool prevrat();

};


#endif //PROVERKAZLOMKY_ZLOMKY_H