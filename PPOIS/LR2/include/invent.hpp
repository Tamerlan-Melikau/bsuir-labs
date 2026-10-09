#pragma once
#include <string>
#include <iostream>
#include "places.hpp"
#include "exceptions.hpp"

class Costume{
private:
    int inventNumber;
    int cost;
    int size;
    std::string color;
    std::string material;
public:
    Costume(int num, int cost, int size, std::string color);
    virtual ~Costume() = default;

    void tryOn();
    void repair();
};

class Decoration{
private:
    std::string theme;
    int inventNumber;
    int cost;
    Stage stage;
public:
    Decoration(int num, int cost, Stage st);
    virtual ~Decoration() = default;

    void use();
    void dismantle();
};

class Instrument{
protected:
    int cost;
    int yold;
    std::string brand;
    std::string type;
    std::string sound;
public:
    Instrument(int cost, std::string type, int yold, std::string sound);
    virtual ~Instrument() = default;

    int getcost(){return cost;}
    std::string gettype(){return type;}
    void repairString();
    void checkCondition(int yold);
};

class Violin:public Instrument{
private:
    std::string bowHair;
    std::string material;
public:
    Violin(int cost, std::string type, int yold, std::string mat, std::string sound);
    void playPizzicato();
    void makeSound();
};

class Cello:public Instrument{
private:
    int size;
    int endpin;
public:
    Cello(int cost, std::string type, int yold, int size, std::string sound);
    void playArco();
    void makeSound();
};

class Piano:public Instrument{
private:
    std::string pedalType;
    int keyCount;
public:
    Piano(int cost, std::string type, int yold, int key, std::string sound);
    void makeSound();
    void playChord();
};

class Flute:public Instrument{
private:
    std::string material;
    int holesCount;
public:
    Flute(int cost, std::string type, int yold, std::string mat, int holes, std::string sound);
    void playHigh();
    void makeSound();
};

class Contrabass:public Instrument{
private:
    int stringCount;
    int bodySize;
public:
    Contrabass(int cost, std::string type, int yold, int strings, int size, std::string sound);
    void playLow();
    void makeSound();
};

class Equipment{
protected:
    int cost;
    std::string brand;
public:
    Equipment(int cost, std::string brand);
    virtual ~Equipment() = default;

    int getCost() const{return cost;}
    std::string getBrand() const{return brand;}
};

class Speaker:public Equipment{
private:
    int channels;
    int maxVolume;
    Hall hall;
public:
    Speaker(int cost, std::string brand, int ch, int vol, Hall h);
    void playSound();
    void setVolume(int v);
};

class Microphone:public Equipment{
private:
    std::string type;
    bool isWireless;
public:
    Microphone(int cost, std::string brand, std::string t, bool wireless);
    void capture();
    void mute();
};

class Spotlight:public Equipment{
private:
    std::string color;
    int angle;
public:
    Spotlight(int cost, std::string brand, std::string col, int ang);
    void turnOn();
    void turnOff();
    void rotate(int degrees);
};