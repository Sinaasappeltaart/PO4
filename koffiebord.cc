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

koffiebord::koffiebord ( ) {
  // TODO
}//koffiebord::koffiebord

koffiebord::~koffiebord ( ) {
  // TODO
}//koffiebord::~koffiebord

void koffiebord::drukaf ( ) {
  cout << "Een koffiebord ziet er mooi uit." << endl;
  // TODO
}//koffiebord::drukaf

void koffiebord::Pointerstructuur(){
  //TODO
}
void koffiebord::plaatskoffie(){

}
void koffiebord::koffieburen(){

}
void koffiebord::resetbord(){

}

// TODO