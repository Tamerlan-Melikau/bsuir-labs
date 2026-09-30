#pragma once
#include <string>
#include <iostream>
#include <ctime>
#include "places.hpp"
#include "people.hpp"
#include "exceptions.hpp"

class Playbill{
private:
    std::string title;
    int price;
    std::string date;
    int posterSize;
public:
    Playbill(std::string title, int price, std::string date);
    virtual ~Playbill();

    void announce();
    void data();
    void printPoster();

    int getPrice() const{return price;}
};

class PremiereInvitation:private Playbill{
private:
    std::string guestName;
public:
    using Playbill::getPrice;
    using Playbill::announce;
    using Playbill::data;

    PremiereInvitation(std::string title, int price, std::string date, std::string guest);
    void present();
};

class Performance{
private:
    std::time_t data;
    int boxOffice;
    std::string title;
    Director director;
    Hall hall;
    Cast cast;
    int capacity;
    int ticketsSold;
public:
    Performance(std::time_t data, int boxOffice, Director d, Hall h, Cast c, int cap);
    virtual ~Performance();

    void setdata(const std::time_t& newData);
    void hold();
    void sellTicket();
};

class Rehearsal{
private:
    std::time_t data;
    int amount;
    int peopleCount;
    std::string location;
    Stage stage;
    Actor leadActor;
public:
    Rehearsal(std::time_t data, int amount, int peopleCount, Stage st, Actor a);
    virtual ~Rehearsal();

    void setdata(const std::time_t& newData);
    void setAmount(int newAmount);
    void setPeople(int newPeople);
    void cancel();
};

class Tour{
private:
    std::string transport;
    std::string city;
    int days;
    double budget;
    int ticketsSold;
    Playbill playbill;
public:
    Tour(std::string city, int days, double budget, int sold, Playbill pb);
    virtual ~Tour();

    void start();
    void end();
    void spend(double amount);

    double getProfit() const{return ticketsSold * 100.0 - budget;}
};

class Schedule{
private:
    int day;
    int month;
    int year;
    int eventsCount;
    bool isHoliday;
public:
    Schedule(int d, int m, int y, int events);
    virtual ~Schedule();

    void addEvent();
    void printDay();
    void removeEvent();

    int getEventsCount() const{return eventsCount;}
};

class Intermission{
private:
    int durationMinutes;
    std::string startTime;
    bool hasBuffet;
    std::string snackMenu;
public:
    Intermission(int duration, std::string time, bool buffet);
    virtual ~Intermission();

    void start();
    void extend();

    int getDuration() const{return durationMinutes;}
};

class ReservedStage:protected Stage{
public:
    using Stage::rotate;

    ReservedStage(int size, bool hasOrchestraPit);
    void reserve();
};