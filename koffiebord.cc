// file koffiebord.cc
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "koffiebord.h"
using namespace std;

int leesgetal (int bovengrens) { //gepakt uit opdracht 3
    int resultaat = 0;
    char kar;
    while (cin.get(kar) && kar != '\n') {
        if (kar >= '0' && kar <= '9') { // Check of het karakter een cijfer is
            resultaat = resultaat * 10 + (kar - '0'); // Bouw getal op met cijfers
            if (resultaat > bovengrens) { // Stop als getal boven limiet komt
                resultaat = bovengrens;
                break;
            }
        }
    }
    return resultaat;
}
//leesgetal

bordvakje::bordvakje ( ) {
  // TODO
}//bordvakje::bordvakje

// Constructor van koffiebord
koffiebord::koffiebord() : ingang(nullptr), hoogte(0), breedte(0) {
    // Constructor-initiatie, ingaande waarde voor ingang, hoogte en breedte
    // Andere initiaties kunnen hier worden toegevoegd, zoals de initialisatie van het bord
}

koffiebord::~koffiebord ( ) {
  // TODO
}//koffiebord::~koffiebord

void koffiebord::drukaf() {
    bordvakje* rij = ingang;  // Begin bij de bovenste rij

    for (int i = 0; i < hoogte; ++i) {  // Loop door alle rijen
        bordvakje* vakje = rij;  // Begin bij het eerste vakje in de rij
        for (int j = 0; j < breedte; ++j) {  // Loop door alle kolommen
            if (vakje != nullptr) {
                // Als het vakje geopend is, geef dan het aantal buren weer
                if (vakje->geopend) {
                    cout << "[" << vakje->aantal << "] ";  // Aantal koffie in het vakje
                } else {
                    cout << "[ ] ";  // Leeg vakje (gesloten)
                }
            }
            if (vakje->buren[2] != nullptr) {  // Beweeg naar het volgende vakje in de rij
                vakje = vakje->buren[2];
            }
        }
        cout << endl;
        if (rij->buren[4] != nullptr) {  // Beweeg naar de volgende rij
            rij = rij->buren[4];
        }
    }
}


void koffiebord::rits(bordvakje* boven, bordvakje* onder){
  while(boven!= nullptr && onder!= nullptr){
    boven -> buren[4]= onder;
    onder -> buren[0]= boven;
    if (boven -> buren[2] != nullptr) { // rechter buren bestaan
    boven -> buren[3]= onder -> buren[2];//rechtsonder
    onder -> buren[1]= boven -> buren[2];//rechtsbeneden
    }
    if (boven -> buren[6] !=nullptr){
    boven -> buren[5]= onder -> buren[6];//linksonder
    onder -> buren[7]= onder -> buren[6];//linksbenden
    }
    boven = boven->buren[2]; // Ga naar het volgende vakje in de rij boven
    onder = onder->buren[2]; // Ga naar het volgende vakje in de rij onder
  }
}

bordvakje* koffiebord::maakBovensteRij(int breedte) {
    bordvakje* rij = new bordvakje[breedte]; // Maak een nieuwe rij
    for (int i = 0; i < breedte; ++i) {
        rij[i].buren[2] = (i + 1 < breedte) ? &rij[i + 1] : nullptr;  // Verbind rechter buur
        rij[i].buren[6] = (i - 1 >= 0) ? &rij[i - 1] : nullptr;  // Verbind linker buur
    }
    return rij;  // Retourneer de gemaakte rij
}

void koffiebord::bouwbord() {
    ingang = maakBovensteRij(breedte); // Maak de bovenste rij
    bordvakje* bovensteRij = ingang;
    bordvakje* tussenrij = nullptr;   // Declareer tussenrij lokaal

    for (int j = 1; j < hoogte; ++j) {
        tussenrij = maakBovensteRij(breedte); // Nieuwe rij maken
        rits(bovensteRij, tussenrij);         // Verbind bovenste rij met nieuwe rij
        bovensteRij = tussenrij;             // Ga naar de volgende rij
    }
}
void koffiebord::plaatskoffie(){

}
void koffiebord::koffieburen(){

}
void koffiebord::resetbord(){

}

// TODO