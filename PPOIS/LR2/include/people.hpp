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
    Cast(int actorsCount)
        :actorsCount(actorsCount){}
    virtual ~Cast(){}

    void addActor(){
        actorsCount++;
        std::cout << "Actor added. Total: " << actorsCount << "\n";
    }
    int getActor() const{return actorsCount;}
    void printInfo(){std::cout << "Actors in cast: " << actorsCount << "\n";}
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
    Spectator(int id, std::string name, int age, int sal, std::string sec, int place, double balance)
        :id(id), name(name), age(age), salary(sal), sector(sec), placeNumber(place), balance(balance){}
    virtual ~Spectator(){}

    void buyTicket(){std::cout << name << " buy ticket\n";}
    void pay(){balance -= 100; std::cout << name << " paid\n";}
    void leaveReview(){std::cout << name << " left a review\n";}
    void arrive(){std::cout << name << " arrived at the theater\n";}
};

class Worker{
protected:
    int id;
    std::string name;
    int age;
    int salary;
public:
    Worker(int id, std::string name, int age, int salary){
        if(age < 0 || age > 120) throw InvalidAgeException();
        if(name.empty()) throw EmptyNameException();
        if(salary < 0) throw InvalidSalaryException();
        this->id = id;
        this->name = name;
        this->age = age;
        this->salary = salary;
    }
    virtual ~Worker(){}
    
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
    Director(int id, std::string name, int age, int salary, int rew, int exp, Cast c, Stage st):
    Worker(id, name, age, salary), rewards(rew), experience(exp), cast(c), stage(st){}

    void direct(){std::cout << name << " puts the play\n";}
    void chooseScript(){std::cout << name << " chooses a script\n";}
    void giveNotes(){std::cout << name << " gives notes to actors\n";}
    void approveCostumes(){std::cout << name << " approves costumes\n";}
};

class Administrator:public Worker{
private:
    int metingAmount;
    int experience;
    Violin violin;
public:
    Administrator(int id, std::string name, int age, int salary, int met, int exp, Violin v):
    Worker(id, name, age, salary), metingAmount(met), experience(exp), violin(v){}

    void createSchedule(){std::cout << name << " creates schedule";}
    void controlBudget(){std::cout << name << " controls expenses";}
    void accept(){std::cout << name << " makes decisions";}
    void solve(){std::cout << name << " solves problems";}
    void raport(){std::cout << name << " makes raports";}
};

class Accountant:public Worker{
private:
    int amountOfDocuments;
    int amountOfMetings;
public:
    Accountant(int id, std::string name, int age, int salary, int doc, int met):
    Worker(id, name, age, salary), amountOfDocuments(doc), amountOfMetings(met){}

    void document(){std::cout << name << " maintainces documentation";}
};

class HRManager:public Worker{
private:
    int amountOfTakenPeople;
    int amountOfMetings;
public:
    HRManager(int id, std::string name, int age, int salary, int people, int met):
    Worker(id, name, age, salary), amountOfTakenPeople(people), amountOfMetings(met){}

    void accept(){std::cout << name << " accepts offers";}
};

class Composer:public Worker{
private:
    int worksCount;
    std::string instrument;
public:
    Composer(int id, std::string name, int age, int salary, int works, std::string inst)
        :Worker(id, name, age, salary), worksCount(works), instrument(inst){}

    void composeMusic(){std::cout << name << " composes music\n";}
};

class Playwright:public Worker{
private:
    int playsWritten;
    std::string genre;
public:
    Playwright(int id, std::string name, int age, int salary, int plays, std::string gen)
        :Worker(id, name, age, salary), playsWritten(plays), genre(gen){}

    void writePlay(){std::cout << name << " write the play\n";}
};

class Choreographer:public Worker{
private:
    int experience;
public:
    Choreographer(int id, std::string name, int age, int salary, int exp)
        :Worker(id, name, age, salary), experience(exp){}

    void stageDance(){std::cout << name << " sets the dance\n";}
    void teachDancers(){std::cout << name << " trains dancers\n";}
};

class SoundDesigner:public Worker{
private:
    int tracksCount;
public:
    SoundDesigner(int id, std::string name, int age, int salary, int tr)
        :Worker(id, name, age, salary), tracksCount(tr){}

    void createMusic(){std::cout << name << " creates music\n";}
    void setupMicrophones(){std::cout << name << " sets mikrophones\n";}
};

class Conductor:public Worker{
private:
    int experience;
    std::string orchestraName;
public:
    Conductor(int id, std::string name, int age, int salary, int exp, std::string orch)
        :Worker(id, name, age, salary), experience(exp), orchestraName(orch){}

    void conduct(){std::cout << name << " conducting\n"; }
    void rehearseOrchestra(){std::cout << name << " rehearses with orchestra\n";}
};

class Violinist{
private:
    std::string name;
    int experience;
    Violin violin;
public:
    Violinist(std::string n, int exp, Violin v)
        :name(n), experience(exp), violin(v){}
    void play(){std::cout << name << " plays violin\n";}
};

class Cellist{
private:
    std::string name;
    int experience;
    Cello cello;
public:
    Cellist(std::string n, int exp, Cello c)
        :name(n), experience(exp), cello(c){}
    void play(){std::cout << name << " plays cello\n";}
};

class Pianist{
private:
    std::string name;
    int experience;
    Piano piano;
public:
    Pianist(std::string n, int exp, Piano p)
        :name(n), experience(exp), piano(p){}
    void play(){std::cout << name << " plays piano\n";}
};

class Flutist{
private:
    std::string name;
    int experience;
    Flute flute;
public:
    Flutist(std::string n, int exp, Flute f)
        :name(n), experience(exp), flute(f){}
    void play(){std::cout << name << " plays flute\n";}
};

class Contrabassist{
private:
    std::string name;
    int experience;
    Contrabass contrabass;
public:
    Contrabassist(std::string n, int exp, Contrabass c)
        :name(n), experience(exp), contrabass(c){}
    void play(){std::cout << name << " plays contrabass\n";}
};

class Actor:public Worker{
private:
    int experience;
    int height;
    Role role;
    Costume costume;
    Character character;
public:
    Actor(int id, std::string name, int age, int exp, int salary, int height, Role r, Costume c, Character ch):
    Worker(id, name, age, salary), experience(exp), height(height), role(r), costume(c), character(ch){}

    void perform(){std::cout << name << " play the role\n";}
    void rehearse(){std::cout << name << " rehearses\n";}
    void memorizeLines(){std::cout << name << " memorizes lines\n";}
    void takeBreak(){std::cout << name << " takes a break\n";}
};

class Acrobat:public Worker{
private:
    int experince;
    int weight;
public:
    Acrobat(int id, std::string name, int age, int salary, int exp, int wei)
    :Worker(id, name, age, salary), experince(exp), weight(wei){}

    void perform(){std::cout << name << " perform the acrobatic element";}
};


class Cashier:public Worker{
private:
    int soldTickets;
public:
    Cashier(int id, std::string name, int age, int salary, int ticket)
    :Worker(id, name, age, salary), soldTickets(ticket){}

    void amount(int soldTickets){std::cout << "Sold " << soldTickets << " tickets";}
};

class Cleaner:public Worker{
private:
    int hours;
public:
    Cleaner(int id, std::string name, int age, int salary, int hours)
    :Worker(id, name, age, salary), hours(hours){}

    void work(){std::cout << "Works " << hours << "hour";}
    void mop(){std::cout << name << " mops floor\n";}
    void vacuum(){std::cout << name << " vacuums the hall\n";}
};

class Doctor:public Worker{
private:
    int patientsPerDay;
public:
    Doctor(int id, std::string name, int age, int salary,int patients)
        :Worker(id, name, age, salary), patientsPerDay(patients){}

    void examine(){std::cout << name << " осматривает пациента\n";}
    void prescribeMedicine(){ std::cout << name << " выписывает лекарство\n";}
    void giveSickLeave(){ std::cout << name << " выдает больничный\n";}
};

class Singer:public Worker{
private:
    std::string voiceType;
    Microphone mic;
public:
    Singer(int id, std::string name, int age, int salary, std::string voice, Microphone m)
        :Worker(id, name, age, salary), voiceType(voice), mic(m){}

    void singAria(){std::cout << name << " performs an aria\n";}
    void warmUp(){std::cout << name << " waming up\n";}
};

class Dancer:public Worker{
private:
    std::string style;
    int experienceYears;
    Costume costume;
public:
    Dancer(int id, std::string name, int age, int salary, std::string st, int exp, Costume c)
        :Worker(id, name, age, salary), style(st), experienceYears(exp), costume(c){}

    void dance(){std::cout << name << " dance\n";}
    void rehearseNumber(){std::cout << name << " rehearses number\n";}
};

class MakeupArtist:public Worker{
private:
    int clientsPerDay;
public:
    MakeupArtist(int id, std::string name, int age, int salary, int clients)
        :Worker(id, name, age, salary), clientsPerDay(clients){}

    void applyMakeup(){std::cout << name << " makes makeup\n";}
    void removeMakeup(){std::cout << name << " takes off makeup\n";}
};

class Bartender:public Worker{
    private:
    int soldAmount;
public:
    Bartender(int id, std::string name, int age, int salary, int amount)
        :Worker(id, name, age, salary), soldAmount(amount){}

    void sellfood(){std::cout << name << " sells food\n";}
};

class Security:public Worker{
private:
    std::string gunType;
public:
    Security(int id, std::string name, int age, int salary, std::string gun):
    Worker(id, name, age, salary), gunType(gun){}

    void patrol(){std::cout << "Patroling the area;\n";}
    void type(){std::cout << "Gun type: " << gunType;}
};