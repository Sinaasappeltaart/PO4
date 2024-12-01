#ifndef KOFFIEBORD_H
#define KOFFIEBORD_H

// Functie om een getal in te lezen met een bovengrens
int leesgetal(int bovengrens);

// Klasse voor een enkel vakje op het bord
class bordvakje {
public:
    bool geopend;    // Is het vakje geopend?
    bool markeer;    // Is het vakje gemarkeerd?
    bool koffie;     // Bevat het vakje koffie?
    int aantal;      // Aantal omliggende koffievakjes
    bordvakje* buren[8]; // Pointer naar de 8 buren (N, NE, E, SE, S, SW, W, NW)

    // Constructor voor het vakje
    bordvakje();
};

// Klasse voor het koffiebord
class koffiebord {
private:
    bordvakje* ingang;  // Pointer naar het begin van het bord
    int hoogte, breedte; // Hoogte en breedte van het bord
    bordvakje* maakBovensteRij(int breedte); // Hulpfunctie om een rij te maken
    void rits(bordvakje* boven, bordvakje* onder); // Verbind twee rijen
    void bouwbord();  // Bouwt het bord
    void plaatskoffie(); // Plaatst koffie in de vakjes
    void koffieburen();  // Handelt de koffieburen af
    void resetbord();  // Reset het bord naar de beginstaat
    void openvakje(bordvakje* vakje); // Functie om een vakje te openen
    void markeervakje(bordvakje* vakje); // Functie om een vakje te markeren
    bool checkGewonnen();  // Controleert of het spel gewonnen is
    bool checkVerloren();  // Controleert of het spel verloren is

public:
    // Constructor en destructor van koffiebord
    koffiebord();
    ~koffiebord();
    void drukaf(); // Drukt het bord af
    void openvakje(); // Open een specifiek vakje
    void markeervakje(); // Markeer een vakje
    void undo(); // Undo de laatste actie
    bool gewonnen(); // Is het spel gewonnen?
    bool verloren(); // Is het spel verloren?
};

#endif
