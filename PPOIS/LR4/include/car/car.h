#pragma once
#include <string>

class Car{
private:
    std::string brand;
    int year = 0;
    double mileage = 0.0;
public:
    Car() = default;
    Car(std::string brand, int year, double mileage);

    const std::string& getBrand() const;
    int getYear() const;
    double getMileage() const;

    void setBrand(const std::string& name);
    void setYear(int year);
    void setMileage(double mileage);

    bool operator<(const Car& other) const;
    bool operator==(const Car& other) const;

    std::string toString() const;
};

struct CarByBrand {
    bool operator()(const Car& left, const Car& right) const;
};

struct CarByYear {
    bool operator()(const Car& left, const Car& right) const;
};

struct CarByMileage {
    bool operator()(const Car& left, const Car& right) const;
};