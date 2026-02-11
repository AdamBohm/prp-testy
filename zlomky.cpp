//
// Created by adamb on 11.02.2026.
//

#include "zlomky.h"

int zlomky::nsd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

zlomky::zlomky() {
    citatel = 1;
    jmenovatel = 1;
}

zlomky::zlomky(int c, int j) {
    citatel = c;
    if (j == 0) {
        jmenovatel = 1;
    } else {
        jmenovatel = j;
    }
}

zlomky::~zlomky() {
}

int zlomky::get_j() {
    return jmenovatel;
}

int zlomky::get_c() {
    return citatel;
}

void zlomky::set_j(int j) {
    if (j == 0) {
        jmenovatel = 1;
    } else {
        jmenovatel = j;
    }
}

void zlomky::set_c(int c) {
    citatel = c;
}

std::string zlomky::toString() const {
    return std::to_string(citatel) + "/" + std::to_string(jmenovatel);
}

void zlomky::zkrat() {
    int spolecnyDelitel = nsd(citatel, jmenovatel); // Najdeme NSD
    citatel /= spolecnyDelitel;    // Vydělíme horní část
    jmenovatel /= spolecnyDelitel; // Vydělíme dolní část
}

float zlomky::naDesetinneCislo() const {
    return (float) citatel / jmenovatel;
}

bool zlomky::prevrat() {
    if (citatel == 0) {
        return false;
    }
    int d = citatel;
    citatel = jmenovatel;
    jmenovatel = d;
    return true;
}
