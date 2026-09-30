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
    Playbill(std::string title, int price, std::string date)
        :title(title), price(price), date(date){}
    virtual ~Playbill(){}

    void announce(){std::cout << "Announcing: " << title << "\n";}
    void data(){std::cout << "Data: " << date;}
    int getPrice() const{return price;}
    void printPoster(){std::cout << "Poster printed: " << title << "\n";}
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
    Performance(std::time_t data, int boxOffice, Director d, Hall h, Cast c, int cap)
        :data(data), boxOffice(boxOffice), director(d), hall(h), cast(c), capacity(cap), ticketsSold(0){}
    virtual ~Performance(){}

    void setdata(const std::time_t& newData){data = newData;}
    void hold(){std::cout << "Performance " << title << " on hold\n";}
    void sellTicket(){         // ← новый метод
        if(ticketsSold >= capacity) throw TicketSoldOutException();
        ticketsSold++;
        std::cout << "Ticket sold. Total: " << ticketsSold << "\n";
    }
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
    Rehearsal(std::time_t data, int amount, int peopleCount, Stage st, Actor a)
        :data(data), amount(amount), peopleCount(peopleCount), stage(st), leadActor(a){}
    virtual ~Rehearsal(){}

    void setdata(const std::time_t& newData){data = newData;}
    void setAmount(int newAmount){amount = newAmount;}
    void setPeople(int newPeople){peopleCount = newPeople;}
    void cancel(){std::cout << "Rehearsal cancelled\n";}
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
    Tour(std::string city, int days, double budget, int sold, Playbill pb)
        :city(city), days(days), budget(budget), ticketsSold(sold), playbill(pb){}
    virtual ~Tour(){}

    void start(){std::cout << "Tour in " << city << " started\n";}
    double getProfit() const{return ticketsSold * 100.0 - budget;}
    void end(){std::cout << "Tour ended\n";}
    void spend(double amount){
        if(amount > budget) throw BudgetExceededException();
        budget -= amount;
        std::cout << "Spent " << amount << ", left: " << budget << "\n";
    }
};

class Schedule{
private:
    int day;
    int month;
    int year;
    int eventsCount;
    bool isHoliday;
public:
    Schedule(int d, int m, int y, int events){
        if(d < 1 || d > 31 || m < 1 || m > 12) throw InvalidDateException();
        this->day = d;
        this->month = m;
        this->year = y;
        this->eventsCount = events;
    }
    virtual ~Schedule(){}

    void addEvent(){eventsCount++;}
    void printDay(){std::cout << day << " " << month << ": " << eventsCount << " events\n";}
    int getEventsCount() const{return eventsCount;}
    void removeEvent(){eventsCount--; std::cout << "Event removed\n";}
};

class Intermission{
private:
    int durationMinutes;
    std::string startTime;
    bool hasBuffet;
    std::string snackMenu;
public:
    Intermission(int duration, std::string time, bool buffet)
        :durationMinutes(duration), startTime(time), hasBuffet(buffet){}
    virtual ~Intermission(){}

    void start(){std::cout << "Intermission started at " << startTime << "\n";}
    int getDuration() const{return durationMinutes;}
    void extend(){durationMinutes += 5; std::cout << "Intermission extended\n";}
};