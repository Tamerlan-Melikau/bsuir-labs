#include "car/car.h"

#include <iomanip>
#include <sstream>
#include <tuple>
#include <utility>

Car::Car(std::string brand, int year, double mileage)
    : brand(std::move(brand)), year(year), mileage(mileage) {
}

const std::string& Car::getBrand() const {
    return brand;
}

int Car::getYear() const {
    return year;
}

double Car::getMileage() const {
    return mileage;
}

void Car::setBrand(const std::string& value) {
    brand = value;
}

void Car::setYear(int value) {
    year = value;
}

void Car::setMileage(double value) {
    mileage = value;
}

bool Car::operator<(const Car& other) const {
    return std::tie(brand, year, mileage)
         < std::tie(other.brand, other.year, other.mileage);
}

bool Car::operator==(const Car& other) const {
    return brand == other.brand
        && year == other.year
        && mileage == other.mileage;
}

std::string Car::toString() const {
    std::ostringstream stream;
    stream << brand << " (" << year << "), пробег: "
           << std::fixed << std::setprecision(2) << mileage << " км";
    return stream.str();
}

bool CarByBrand::operator()(const Car& left, const Car& right) const {
    if (left.getBrand() != right.getBrand()) {
        return left.getBrand() < right.getBrand();
    }
    if (left.getYear() != right.getYear()) {
        return left.getYear() < right.getYear();
    }
    return left.getMileage() < right.getMileage();
}

bool CarByYear::operator()(const Car& left, const Car& right) const {
    if (left.getYear() != right.getYear()) {
        return left.getYear() < right.getYear();
    }
    return left.getBrand() < right.getBrand();
}

bool CarByMileage::operator()(const Car& left, const Car& right) const {
    if (left.getMileage() != right.getMileage()) {
        return left.getMileage() < right.getMileage();
    }
    return left.getBrand() < right.getBrand();
}