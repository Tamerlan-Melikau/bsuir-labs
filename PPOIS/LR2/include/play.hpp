#pragma once
#include <string>
#include <iostream>

class Role{
private:
    std::string name;
    int linesCount;
    int durationMin;
    bool isMain;
public:
    Role(std::string name, int lines, int dur)
        :name(name), linesCount(lines), durationMin(dur){}
    virtual ~Role(){}

    void learn(){std::cout << "Learning role: " << name << "\n";}
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
    Character(std::string name, int age, std::string description)
        :name(name), age(age), description(description){}
    virtual ~Character(){}

    void describe(){std::cout << name << ", " << age << ": " << description << "\n";}
    int getAge() const{return age;}
    void kill(){isAlive = false; std::cout << name << " died\n";}
};

class Scene{
private:
    int number;
    int duration;
    std::string location;
    int actNumber;
    Character mainChar;
public:
    Scene(int number, int duration, std::string location, Character mc)
        :number(number), duration(duration), location(location), mainChar(mc){}
    virtual ~Scene(){}

    void start(){std::cout << "Scene " << number << " started\n";}
    int getDuration() const{return duration;}
    void setLocation(const std::string& newLoc){location = newLoc;}
    void finish(){std::cout << "Scene " << number << " finished\n";}
};

class Act{
private:
    int number;
    int scenesCount;
    std::string title;
    Scene firstScene;
public:
    Act(int n, int s, std::string t, Scene fs)
        :number(n), scenesCount(s), title(t), firstScene(fs){}
    virtual ~Act(){}

    void printInfo(){std::cout << "Act " << number << ": " << title << "\n";}
};

class Audition{
private:
    std::string date;
    int applicantsCount;
    std::string roleName;
public:
    Audition(std::string d, int a, std::string r)
        :date(d), applicantsCount(a), roleName(r){}
    virtual ~Audition(){}

    void start(){std::cout << "Audition for " << roleName << " started\n";}
};
