#include "places.hpp"

Stage::Stage(int size, bool hasOrchestraPit)
    :size(size), hasOrchestraPit(hasOrchestraPit){}
Stage::~Stage(){}

void Stage::prepare(){std::cout << "Stage is prepared\n";}
void Stage::clear(){std::cout << "Stage is cleaned\n";}
void Stage::rotate(){std::cout << "Stage rotates\n";}

Hall::Hall(int capacity, bool hasBalcony, Stage st)
    :capacity(capacity), hasBalcony(hasBalcony), stage(st){}
Hall::~Hall(){}

void Hall::dimLights(){std::cout << "Hall lights dimmed\n";}
void Hall::fill(int people){
    if(people > capacity) throw HallOverflowException();
    std::cout << "Hall is filled with " << people << " people\n";
}
void Hall::empty(){std::cout << "Hall is empty\n";}

DressingRoom::DressingRoom(int number, int mirrors, bool hasSofa)
    :number(number), mirrors(mirrors), hasSofa(hasSofa){}
DressingRoom::~DressingRoom(){}

void DressingRoom::occupy(){std::cout << "Dressing room is occupied\n";}
void DressingRoom::vacate(){std::cout << "Dressing room is vacated\n";}
void DressingRoom::reserve(){occupied = true; std::cout << "Room reserved\n";}

Buffet::Buffet(int menuSize, bool isOpen)
    :menuSize(menuSize), isOpen(isOpen){}
Buffet::~Buffet(){}

void Buffet::open(){isOpen = true; std::cout << "Buffet is open\n";}
void Buffet::close(){isOpen = false; std::cout << "Buffet is closed\n";}
void Buffet::sell(){if(isOpen) std::cout << "Item sold\n";}
void Buffet::restock(){std::cout << "Buffet restocked\n";}