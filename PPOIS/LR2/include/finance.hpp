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
    Ticket(int cost, bool vip, int row, Spectator s)
        :cost(cost), VIP(vip), row(row), owner(s)
    {
        if(cost < 0) throw InvalidTicketPriceException();
    }
    virtual ~Ticket(){}

    void print(){std::cout << "Ticket row " << row << ", cost " << cost << "\n";}
    int getcost() const{return cost;}
    bool getVIP() const{return VIP;}
};

class Sponsor {
private:
    int contractYears;
    int id;
    std::string name;
    std::string company;
    double budget;
    Contract contract;
public:
    Sponsor(int id, std::string name, std::string company, double budget, Contract c)
        :id(id), name(name), company(company), budget(budget), contract(c){}
    virtual ~Sponsor(){}

    void donate(){std::cout << company << " спонсирует " << budget << "\n";}
    void signContract(){std::cout << company << " sign the contract\n"; }
    double getBudget() const{return budget;}
    std::string getName() const{return name;}
    void withdraw(){std::cout << company << " withdrew sponsorship\n";}
};