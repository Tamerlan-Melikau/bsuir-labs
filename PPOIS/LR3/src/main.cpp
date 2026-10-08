#include <iostream>
#include "weather.hpp"
#include "location.hpp"
#include "sensors.hpp"
#include "forecast.hpp"
#include "sources.hpp"
#include "people.hpp"
#include "alerts.hpp"
#include "other.hpp"
#include "exceptions.hpp"

int main() {
    try {
        GeoCoordinate coord;
        Location loc;
        Temperature temp;
        Wind wind;
        Pressure pressure;
        Humidity humidity;
        Weather weather;

        std::cout << weather.getSummary() << std::endl;

        WeatherStation station;
        std::cout << station.showAdres() << std::endl;

        User user;
        std::cout << user.login("admin", "1234") << std::endl;

        Alert alert;
        std::cout << alert.getFullText() << std::endl;

    } catch (WeatherException& e) {
        std::cerr << "Error: " << e.what() << " Code: " << e.getCode() << std::endl;
    }

    return 0;
}