#include <string>
#include <iostream>
#include <ctime>

class Performance{
private:
    std::time_t data;
    int boxOffice;
public:
    Performance(std::time_t data, int boxOffice)
        :data(data), boxOffice(boxOffice){}

    virtual ~Performance(){}

    void setdata(const std::time_t& newData){data = newData;}
};

class Rehearsal{
private:
    std::time_t data;
    int amount;
    int peopleCount;
public:
    Rehearsal(std::time_t data, int amount, int peopleCount)
        :data(data), amount(amount), peopleCount(peopleCount){}

    virtual ~Rehearsal(){}

    void setdata(const std::time_t& newData){data = newData;}
    void setAmount(int newAmount){amount = newAmount;}
    void setPeople(int newPeople){peopleCount = newPeople;}
};

class Tour{
private:
    std::string city;
    int days;
    double budget;
    int ticketsSold;
public:
    Tour(std::string city, int days, double budget, int sold)
        :city(city), days(days), budget(budget), ticketsSold(sold){}

    void start(){std::cout << "Tour in " << city << " started\n";}
    double getProfit() const{return ticketsSold * 100.0 - budget;}
};

class Schedule{
private:
    int day;
    int month;
    int year;
    int eventsCount;
public:
    Schedule(int d, int m, int y, int events)
        :day(d), month(m), year(y), eventsCount(events){}

    void addEvent(){eventsCount++;}
    void printDay(){std::cout << day << " " << month << ": " << eventsCount << " events\n";}
    int getEventsCount() const{return eventsCount;}
};

class Playbill{
private:
    std::string title;
public:
    Playbill(std::string title)
        :title(title){}

    void announce(){std::cout << "Announcing: " << title << "\n";}
};

class Intermission{
private:
    int durationMinutes;
    std::string startTime;
    bool hasBuffet;
public:
    Intermission(int duration, std::string time, bool buffet)
        :durationMinutes(duration), startTime(time), hasBuffet(buffet){}

    void start(){std::cout << "Intermission started at " << startTime << "\n";}
    int getDuration() const{return durationMinutes;}
};