#include <string>
#include <iostream>

class Spectator{
private:
    int id;
    std::string name;
    int age;
    int salary;
    std::string sector;
    bool VIP;
    int placeNumber;

public:
    Spectator(int id, std::string name, int age, int sal, std::string sec, bool vip, int place):id(id), name(name), age(age), salary(sal), sector(sec), VIP(vip), placeNumber(place){

    }
    void buyTicket(){
        std::cout << name << " покупает билет.\n";
    }
};

class Worker{
protected:
    int id;
    std::string name;
    int age;
    int salary;

public:
    Worker(int id, std::string name, int age, int salary):id(id), name(name), age(age), salary(salary){

    }
    std::string getName() const{
        return name;
    }
    int getid() const{
        return id;
    }
    int getage() const{
        return age;
    }
    void setName(const std::string& newName){
        name = newName;
    }
    int getsalary(){
        return salary;
    }
};

class Actor:public Worker{
private:
    int experience;

public:
    Actor(int id, std::string name, int age, int exp, int salary):Worker(id, name, age, salary), experience(exp){

    }
    void perform(){
        std::cout << name << " играет роль\n";
    } 
};

class Director:public Worker{
private:
    int rewards;

public:
    Director(int id, std::string name, int age, int salary, int rew):Worker(id, name, age, salary), rewards(rew){

    }
    void direct() { std::cout << name << " стаивт спектакль\n"; }
};

class Gimnast:public Worker{
private:
    int experince;
    int weight;
public:
    Gimnast(int id, std::string name, int age, int salary, int exp, int wei):Worker(id, name, age, salary), experince(exp), weight(wei){

    }
};

class Cashier:public Worker{
private:

public:
    Cashier(int id, std::string name, int age, int exp, int salary):Worker(id, name, age, salary){

    }
}