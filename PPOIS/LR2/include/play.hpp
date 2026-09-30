#pragma once
#include <string>
#include <iostream>
#include "exceptions.hpp"

class Role{
private:
    std::string name;
    int linesCount;
    int durationMin;
    bool isMain;
    bool learned_ = false;
public:
    Role(std::string name, int lines, int dur);
    virtual ~Role() = default;

    void learn();
    void perform();

    int getLines() const{return linesCount;}
    void setLines(int newLines){linesCount = newLines;}
    bool isMainRole() const{return isMain;}
};

class Character{
private:
    std::string name;
    int age;
    std::string description;
    bool isAlive;
public:
    Character(std::string name, int age, std::string description);
    virtual ~Character() = default;

    void describe();
    void kill();

    int getAge() const{return age;}
};

class Scene{
private:
    int number;
    int duration;
    std::string location;
    int actNumber;
    Character mainChar;
public:
    Scene(int number, int duration, std::string location, Character mc);
    virtual ~Scene() = default;

    void start();
    void finish();
    void setLocation(const std::string& newLoc);

    int getDuration() const{return duration;}
};

class Act{
private:
    int number;
    int scenesCount;
    std::string title;
    Scene firstScene;
public:
    Act(int n, int s, std::string t, Scene fs);
    virtual ~Act() = default;

    void printInfo();
};

class Audition{
private:
    std::string date;
    int applicantsCount;
    std::string roleName;
public:
    Audition(std::string d, int a, std::string r);
    virtual ~Audition() = default;

    void start();
};