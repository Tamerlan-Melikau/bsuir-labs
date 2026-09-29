#include <string>
#include <iostream>
#include <ctime>

class Performance{
private:
    std::time_t data;
    int boxOffice;
    std::string title;
public:
    Performance(std::time_t data, int boxOffice)
        :data(data), boxOffice(boxOffice){}
    virtual ~Performance(){}

    void setdata(const std::time_t& newData){data = newData;}
    void hold(){std::cout << "Performance " << title << " on hold\n";}
};

class Rehearsal{
private:
    std::time_t data;
    int amount;
    int peopleCount;
    std::string location;
public:
    Rehearsal(std::time_t data, int amount, int peopleCount)
        :data(data), amount(amount), peopleCount(peopleCount){}
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
public:
    Tour(std::string city, int days, double budget, int sold)
        :city(city), days(days), budget(budget), ticketsSold(sold){}
    virtual ~Tour(){}

    void start(){std::cout << "Tour in " << city << " started\n";}
    double getProfit() const{return ticketsSold * 100.0 - budget;}
    void end(){std::cout << "Tour ended\n";}
};

class Schedule{
private:
    int day;
    int month;
    int year;
    int eventsCount;
    bool isHoliday;
public:
    Schedule(int d, int m, int y, int events)
        :day(d), month(m), year(y), eventsCount(events){}
    virtual ~Schedule(){}

    void addEvent(){eventsCount++;}
    void printDay(){std::cout << day << " " << month << ": " << eventsCount << " events\n";}
    int getEventsCount() const{return eventsCount;}
    void removeEvent(){eventsCount--; std::cout << "Event removed\n";}
};

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