#pragma once
#include <string>
#include <iostream>
#include "people.hpp"
#include "invent.hpp"
#include "exceptions.hpp"

class Contract{
private:
    int salary;
    std::string strtedData;
    int months;
    Worker worker;
    bool signed_ = false;
public:
    Contract(int salary, std::string strtedData, Worker w)
        :salary(salary), strtedData(strtedData), worker(w){}
    virtual ~Contract(){}

    void setSalary(int newSal){salary = newSal;}
    void sign(){
        signed_ = true;
        std::cout << "Sign the contract";
    }
    void terminate(){std::cout << "Contract terminated\n";}
    void work(){
        if(!signed_) throw ContractNotSignedException();
        std::cout << "Working under contract\n";
    }
};

class Advertisement{
private:
    int budget;
    int views;
    std::string channel;
public:
    Advertisement(int budget, int views)
        :budget(budget), views(views){}
    virtual ~Advertisement(){}

    void start(){std::cout << "Upload the ad";}
    void viewers(){std::cout << "Viewers: "<< views << "\n";}
    void stop(){std::cout << "Ad stopped\n";}
};

class Award{
private:
    std::string title;
    int year;
    std::string category;
    std::string recipient;
    int prizeMoney;
    Worker recipient_;
public:
    Award(std::string t, int y, std::string c, Worker r)
        :title(t), year(y), category(c), recipient_(r){}
    virtual ~Award(){}

    void give(){std::cout << "Awarded: " << title << "\n";}
    void printInfo(){std::cout << title << " (" << year << ") - " << category << "\n";}
    void payPrize(){std::cout << "Prize paid: " << prizeMoney << "\n";}
};

class Warehouse{
private:
    int itemsCount;
    int capacity;
    std::string address;
    Costume costume;
public:
    Warehouse(int i, int c, Costume co)
        :itemsCount(i), capacity(c), costume(co){}
    virtual ~Warehouse(){}

    void store(){
        if(itemsCount >= capacity) throw WarehouseFullException();
        itemsCount++;
        std::cout << "Stored. Total: " << itemsCount << "\n";
    }
    void take(){itemsCount--; std::cout << "Taken. Total: " << itemsCount << "\n";}
    bool isFull(){return itemsCount >= capacity;}   
};