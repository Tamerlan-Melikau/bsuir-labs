#include "people.hpp"

std::string Human::showInfo(){
    return name;
}

bool User::login(std::string l, std::string p){
    return login == l && password == p;
}

void User::logout(){
}

void User::addFavorite(Location loc){
    places.push_back(loc);
}

void User::removeFavorite(Location loc){
    for (auto it = places.begin(); it != places.end(); ++it){
        if (it->name == loc.name){
            places.erase(it);
            break;
        }
    }
}

bool Worker::isVacation(){
    return false;
}

int Worker::getSalary(){
    return salary;
}

void Admin::blockUser(User& u){
    u.logout();
}

int Admin::viewLogs(){
    return 0;
}

bool Master::repairStation(WeatherStation& station){
    station.calibrateAll();
    return true;
}

void Master::replaceSensor(Sensor* s){
    if (s != nullptr) s->calibrate();
}

void Master::requestParts(){
}