#pragma once
#include <string>
#include <iostream>
#include "people.hpp"
#include "documents.hpp"

class Ticket{
private:
    int row;
    int cost;
    bool VIP;
    Spectator owner;
public:
    Ticket(int cost, bool vip, int row, Spectator s);
    virtual ~Ticket();

    void print();

    int getcost() const{return cost;}
    bool getVIP() const{return VIP;}
};

class Sponsor{
private:
    int contractYears;
    int id;
    std::string name;
    std::string company;
    double budget;
    Contract contract;
public:
    Sponsor(int id, std::string name, std::string company, double budget, Contract c);
    virtual ~Sponsor();

    void donate();
    void signContract();
    void withdraw();

    double getBudget() const{return budget;}
    std::string getName() const{return name;}
};