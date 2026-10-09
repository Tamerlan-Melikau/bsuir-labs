#pragma once
#include <string>
#include <vector>
#include "location.hpp"
#include "weather.hpp"
#include "sensors.hpp"
#include "sources.hpp"

class Human {
private:
    int ID = 0;
    std::string name = "";
public:
    std::string showInfo();
};

class User : public virtual Human {
private:
    std::string loginName = "";
    std::string password = "";
    std::string email = "";
    std::vector<Location> places;
public:
    bool login(std::string, std::string);
    void logout();
    void addFavorite(Location);
    void removeFavorite(Location);
};

class Worker : public virtual Human {
private:
    std::string rightsAcces = "";
    int experience = 0;
    std::string role = "";
    int salary = 0;
public:
    bool isVacation();
    int getSalary();
};

class Admin : public Worker {
private:
    std::vector<std::string> permissions;
public:
    void blockUser(User&);
    int viewLogs();
};

class Master : public Worker {
private:
    std::string specialization = "";
    int certificationLevel = 0;
    std::vector<std::string> tools;
public:
    bool repairStation(WeatherStation&);
    void replaceSensor(Sensor*);
    void requestParts();
};

class Supervisor : public Worker, public User {
public:
    void reviewWork();
};