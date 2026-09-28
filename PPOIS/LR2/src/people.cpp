#include <string>
#include <iostream>

class Spectator{
private:
    int id;
    std::string name;
    int age;
    int salary;
    std::string sector;
    int placeNumber;
public:
    Spectator(int id, std::string name, int age, int sal, std::string sec, int place)
        :id(id), name(name), age(age), salary(sal), sector(sec), placeNumber(place){}

    virtual ~Spectator(){}

    void buyTicket(){std::cout << name << " buy ticket\n";}
};

class Worker{
protected:
    int id;
    std::string name;
    int age;
    int salary;
public:
    Worker(int id, std::string name, int age, int salary)
        :id(id), name(name), age(age), salary(salary){}

    virtual ~Worker(){}
    
    std::string getName() const{return name;}
    int getid() const{return id;}
    int getage() const{return age;}
    void setName(const std::string& newName){name = newName;}
    int getsalary() const{return salary;}
};

class Actor:public Worker{
private:
    int experience;
public:
    Actor(int id, std::string name, int age, int exp, int salary):
    Worker(id, name, age, salary), experience(exp){}

    void perform(){std::cout << name << " play the role\n";} 
};

class Director:public Worker{
private:
    int rewards;
public:
    Director(int id, std::string name, int age, int salary, int rew):
    Worker(id, name, age, salary), rewards(rew){}

    void direct(){std::cout << name << " puts the play\n";}
};

class Administrator:public Worker{
private:
    int metingAmount;
public:
    Administrator(int id, std::string name, int age, int salary, int met):
    Worker(id, name, age, salary), metingAmount(met){}

    void createSchedule(){std::cout << name << " creates schedule";}
    void controlBudget(){std::cout << name << " controls expenses";}
    void accept(){std::cout << name << " makes decisions";}
    void solve(){std::cout << name << " solves problems";}
    void raport(){std::cout << name << " makes raports";}
};

class Accountant:public Worker{
public:
    Accountant(int id, std::string name, int age, int salary):
    Worker(id, name, age, salary){}

    void document(){std::cout << name << " maintainces documentation";}
};

class HRManager:public Worker{
private:
    int amountOfTakenPeople;
public:
    HRManager(int id, std::string name, int age, int salary, int people):
    Worker(id, name, age, salary), amountOfTakenPeople(people){}

    void accept(){std::cout << name << " accepts offers";}
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

class Playwright:public Worker{
private:
    int playsWritten;
    std::string genre;
public:
    Playwright(int id, std::string name, int age, int salary, int plays, std::string gen)
        :Worker(id, name, age, salary), playsWritten(plays), genre(gen){}

    void writePlay(){std::cout << name << " write the play\n";}
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

class Musician:public Worker{
private:
    std::string instrument;
public:
    Musician(int id, std::string name, int age, int salary, std::string inst)
        :Worker(id, name, age, salary), instrument(inst){}

    void playInstrument(){std::cout << name << " play on " << instrument << "\n";}
    void tuneInstrument(){std::cout << name << " set the instrument\n";}
};

class Singer:public Worker{
private:
    std::string voiceType;
public:
    Singer(int id, std::string name, int age, int salary, std::string voice)
        :Worker(id, name, age, salary), voiceType(voice){}

    void singAria(){std::cout << name << " performs an aria\n";}
    void warmUp(){std::cout << name << " waming up\n";}
};

class Dancer:public Worker{
private:
    std::string style;
    int experienceYears;
public:
    Dancer(int id, std::string name, int age, int salary, std::string st, int exp)
        :Worker(id, name, age, salary), style(st), experienceYears(exp){}

    void dance(){std::cout << name << " dance\n";}
    void rehearseNumber(){std::cout << name << " rehearses number\n";}
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

class MakeupArtist:public Worker{
private:
    int clientsPerDay;
public:
    MakeupArtist(int id, std::string name, int age, int salary, int clients)
        :Worker(id, name, age, salary), clientsPerDay(clients){}

    void applyMakeup(){std::cout << name << " makes makeup\n";}
    void removeMakeup(){std::cout << name << " takes off makeup\n";}
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

class Bartender:public Worker{
    private:
    int soldAmount;
public:
    Bartender(int id, std::string name, int age, int salary, int amount)
        :Worker(id, name, age, salary), soldAmount(amount){}

    void sellfood(){std::cout << name << " sells food\n";}
};