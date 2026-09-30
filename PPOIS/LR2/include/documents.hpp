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
    Contract(int salary, std::string strtedData, Worker w);
    virtual ~Contract() = default;

    void setSalary(int newSal);
    void sign();
    void terminate();
    void work();
};

class Advertisement{
private:
    int budget;
    int views;
    std::string channel;
public:
    Advertisement(int budget, int views);
    virtual ~Advertisement() = default;

    void start();
    void viewers();
    void stop();
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
    Award(std::string t, int y, std::string c, Worker r);
    virtual ~Award() = default;

    void give();
    void printInfo();
    void payPrize();
};

class Warehouse{
private:
    int itemsCount;
    int capacity;
    std::string address;
    Costume costume;
public:
    Warehouse(int i, int c, Costume co);
    virtual ~Warehouse() = default;

    void store();
    void take();
    bool isFull();
};