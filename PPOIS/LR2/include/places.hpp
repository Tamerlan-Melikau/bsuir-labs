#pragma once
#include <string>
#include <iostream>
#include "exceptions.hpp"

class Stage{
private:
    int size;
    bool hasOrchestraPit;
    std::string floorType;
public:
    Stage(int size, bool hasOrchestraPit);
    virtual ~Stage() = default;

    void prepare();
    void clear();
    void rotate();
};

class Hall{
private:
    int acousticRating;
    int capacity;
    bool hasBalcony;
    Stage stage;
public:
    Hall(int capacity, bool hasBalcony, Stage st);
    virtual ~Hall() = default;

    void dimLights();
    void fill(int people);
    void empty();

    int getCapacity() const{return capacity;}
};

class DressingRoom{
private:
    int number;
    int mirrors;
    bool hasSofa;
    bool occupied;
public:
    DressingRoom(int number, int mirrors, bool hasSofa);
    virtual ~DressingRoom() = default;

    void occupy();
    void vacate();
    void reserve();
};

class Buffet{
private:
    int menuSize;
    bool isOpen;
    double revenue;
public:
    Buffet(int menuSize, bool isOpen);
    virtual ~Buffet() = default;

    void open();
    void close();
    void sell();
    void restock();
};