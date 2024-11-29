// file koffiebord.h

int leesgetal (int bovengrens);
//klasse voor enkel vakje op het bord
class bordvakje {
  public:
    bool geopend; //is het vakje geopend?
    bool markeer; //is het vakje gemarkeerd?
    bool koffie; //bevat het vakje koffie?
    int aantal;           //     7 0 1
    //voor aantal omliggende koffie?
    bordvakje* buren[8];  //     6   2
    // pointer naar de 8 buren
    bordvakje ( );        //     5 4 3
    // TODO
};//bordvakje
//klasse voor het koffiebord
class koffiebord {
  private:
    bordvakje* ingang;
    int hoogte, breedte;
    void Pointerstructuur();
    void plaatskoffie();
    void koffieburen();
    void resetbord();
    // iets om vakje te selecteren met coordinaat? met pointers?
    // iets met de buren openen als het veilig is? 
    // iets met geschiedenis? 
    // TODO
  public:
    koffiebord ( );
    ~koffiebord ( );
    void drukaf ( );
    void openvakje(); // functie om vakje te openen
    void markeervakje(); // functie om vakje te markeren
    void undo(); //zet undoen
    bool gewonnen(); // is er gewonnen?
    bool verloren(); //is er verloren?
    // TODO
};//koffiebord
