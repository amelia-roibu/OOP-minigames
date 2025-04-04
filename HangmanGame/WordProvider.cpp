//
// Created by Amelia Roibu on 4/4/2025.
//
#include "WordProvider.h"
#include <vector>
#include <cstdlib>
#include <ctime>

WordProvider::WordProvider() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    words = {"amelie", "eduard", "project", "family", "student", "exploring"};

    // se genereaza timpul de la 1 ianuarie 1970 pana in prezent, in secunde
    // time e un tip de date care stocheaza in long int / long long nr de secunde
    // dar srand are nevoie de un parametru unsigned, deci se face conversie
    // folosind static_cast<in_ce_convertesc>(valoare_convertita)
    // se foloseste asta pt a garanta ca orice folosire a functiei srand()
    // va genera un nr diferit de fiecare data (wth)
}

std::string WordProvider::getRandomWord() const{
    int index = std::rand() % words.size();
    return words[index];
}