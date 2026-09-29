#include <string>
#include <iostream>

class Stage{
private:
    int size;
    bool hasOrchestraPit;
    std::string floorType;
public:
    Stage(int size, bool hasOrchestraPit)
        :size(size), hasOrchestraPit(hasOrchestraPit){}
    virtual ~Stage(){}

    void prepare(){std::cout << "Stage is prepared\n";}
    void clear(){std::cout << "Stage is cleaned\n";}
    void rotate(){std::cout << "Stage rotates\n";}
};

class Hall{
private:
    int acousticRating;
    int capacity;
    bool hasBalcony;
public:
    Hall(int capacity, bool hasBalcony)
        :capacity(capacity), hasBalcony(hasBalcony){}
    virtual ~Hall(){};

    void dimLights(){std::cout << "Hall lights dimmed\n";}
    void fill(){std::cout << "Hall is filled\n";}
    void empty(){std::cout << "Hall is empty\n";}
    int getCapacity() const{return capacity;}
};

class DressingRoom{
private:
    int number;
    int mirrors;
    bool hasSofa;
    bool occupied;
public:
    DressingRoom(int number, int mirrors, bool hasSofa)
        :number(number), mirrors(mirrors), hasSofa(hasSofa){}
    virtual ~DressingRoom(){};

    void occupy(){std::cout << "Dressing room is occupied\n";}
    void vacate(){std::cout << "Dressing room is vacated\n";}
    void reserve(){occupied = true; std::cout << "Room reserved\n";}
};

class Buffet{
private:
    int menuSize;
    bool isOpen;
    double revenue;
public:
    Buffet(int menuSize, bool isOpen)
        :menuSize(menuSize), isOpen(isOpen){}
    virtual ~Buffet(){};

    void open(){isOpen = true; std::cout << "Buffet is open\n";}
    void close(){isOpen = false; std::cout << "Buffet is closed\n";}
    void sell(){if(isOpen) std::cout << "Item sold\n";}
    void restock(){std::cout << "Buffet restocked\n";}
};