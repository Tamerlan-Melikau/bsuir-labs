#pragma once
#include <string>
#include <iostream>
#include "play.hpp"
#include "invent.hpp"
#include "places.hpp"
#include "exceptions.hpp"

class Cast{
private:
    int actorsCount;
public:
    Cast(int actorsCount);
    virtual ~Cast() = default;

    void addActor();
    void printInfo();

    int getActor() const{return actorsCount;}
};

class Spectator{
private:
    int id;
    std::string name;
    int age;
    int salary;
    std::string sector;
    int placeNumber;
    double balance;
public:
    Spectator(int id, std::string name, int age, int sal, std::string sec, int place, double balance);
    virtual ~Spectator() = default;

    void buyTicket();
    void pay();
    void leaveReview();
    void arrive();
};

class Worker{
protected:
    int id;
    std::string name;
    int age;
    int salary;
public:
    Worker(int id, std::string name, int age, int salary);
    virtual ~Worker() = default;

    std::string getName() const{return name;}
    int getid() const{return id;}
    int getage() const{return age;}
    void setName(const std::string& newName){name = newName;}
    int getsalary() const{return salary;}
};

class Director:public Worker{
private:
    int rewards;
    int experience;
    Cast cast;
    Stage stage;
public:
    Director(int id, std::string name, int age, int salary, int rew, int exp, Cast c, Stage st);
    void direct();
    void chooseScript();
    void giveNotes();
    void approveCostumes();
};

class Administrator:public Worker{
private:
    int metingAmount;
    int experience;
    Violin violin;
public:
    Administrator(int id, std::string name, int age, int salary, int met, int exp, Violin v);
    void createSchedule();
    void controlBudget();
    void accept();
    void solve();
    void raport();
};

class Accountant:public Worker{
private:
    int amountOfDocuments;
    int amountOfMetings;
public:
    Accountant(int id, std::string name, int age, int salary, int doc, int met);
    void document();
};

class HRManager:public Worker{
private:
    int amountOfTakenPeople;
    int amountOfMetings;
public:
    HRManager(int id, std::string name, int age, int salary, int people, int met);
    void accept();
};

class Composer:public Worker{
private:
    int worksCount;
    std::string instrument;
public:
    Composer(int id, std::string name, int age, int salary, int works, std::string inst);
    void composeMusic();
};

class Playwright:public Worker{
private:
    int playsWritten;
    std::string genre;
public:
    Playwright(int id, std::string name, int age, int salary, int plays, std::string gen);
    void writePlay();
};

class Choreographer:public Worker{
private:
    int experience;
public:
    Choreographer(int id, std::string name, int age, int salary, int exp);
    void stageDance();
    void teachDancers();
};

class SoundDesigner:public Worker{
private:
    int tracksCount;
public:
    SoundDesigner(int id, std::string name, int age, int salary, int tr);
    void createMusic();
    void setupMicrophones();
};

class Conductor:public Worker{
private:
    int experience;
    std::string orchestraName;
    Instrument instrument;
public:
    Conductor(int id, std::string name, int age, int salary, int exp, std::string orch, Instrument inst);
    void conduct();
    void rehearseOrchestra();
};

class Musician{
protected:
    std::string name;
    int experience;
public:
    Musician(std::string n, int exp);
    virtual ~Musician() = default;

    std::string getName() const{return name;}
    int getExperience() const{return experience;}

    virtual void play() = 0;
};

class Violinist:public Musician{
private:
    Violin violin;
public:
    Violinist(std::string n, int exp, Violin v);
    void play() override;
};

class Cellist:public Musician{
private:
    Cello cello;
public:
    Cellist(std::string n, int exp, Cello c);
    void play() override;
};

class Pianist:public Musician{
private:
    Piano piano;
public:
    Pianist(std::string n, int exp, Piano p);
    void play() override;
};

class Flutist:public Musician{
private:
    Flute flute;
public:
    Flutist(std::string n, int exp, Flute f);
    void play() override;
};

class Contrabassist:public Musician{
private:
    Contrabass contrabass;
public:
    Contrabassist(std::string n, int exp, Contrabass c);
    void play() override;
};

class Actor:virtual public Worker{
private:
    int experience;
    int height;
    Role role;
    Costume costume;
    Character character;
public:
    Actor(int id, std::string name, int age, int salary, int exp, int height, Role r, Costume c, Character ch);
    void perform();
    void rehearse();
    void memorizeLines();
    void takeBreak();
};

class Singer:virtual public Worker{
private:
    std::string voiceType;
    Microphone mic;
public:
    Singer(int id, std::string name, int age, int salary, std::string voice, Microphone m);
    void singAria();
    void warmUp();
};

class OperaActor : public Actor, public Singer{
private:
    int vocalRange;
public:
    using Actor::perform;
    using Singer::singAria;

    OperaActor(int id, std::string name, int age, int salary,
               int exp, int height, Role r, Costume c, Character ch,
               std::string voice, Microphone m, int range);

    void singOperaAria();
};

class Acrobat:public Worker{
private:
    int experince;
    int weight;
public:
    Acrobat(int id, std::string name, int age, int salary, int exp, int wei);
    void perform();
};

class Cashier:public Worker{
private:
    int soldTickets;
public:
    Cashier(int id, std::string name, int age, int salary, int ticket);
    void amount(int soldTickets);
};

class Cleaner:public Worker{
private:
    int hours;
public:
    Cleaner(int id, std::string name, int age, int salary, int hours);
    void work();
    void mop();
    void vacuum();
};

class Doctor:public Worker{
private:
    int patientsPerDay;
public:
    Doctor(int id, std::string name, int age, int salary, int patients);
    void examine();
    void prescribeMedicine();
    void giveSickLeave();
};

class Dancer:public Worker{
private:
    std::string style;
    int experienceYears;
    Costume costume;
public:
    Dancer(int id, std::string name, int age, int salary, std::string st, int exp, Costume c);
    void dance();
    void rehearseNumber();
};

class MakeupArtist:public Worker{
private:
    int clientsPerDay;
public:
    MakeupArtist(int id, std::string name, int age, int salary, int clients);
    void applyMakeup();
    void removeMakeup();
};

class Bartender:public Worker{
private:
    int soldAmount;
public:
    Bartender(int id, std::string name, int age, int salary, int amount);
    void sellfood();
};

class Security:public Worker{
private:
    std::string gunType;
public:
    Security(int id, std::string name, int age, int salary, std::string gun);
    void patrol();
    void type();
};