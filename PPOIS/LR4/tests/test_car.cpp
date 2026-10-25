#include <gtest/gtest.h>
#include "car/car.h"

TEST(CarTest, DefaultConstructor) {
    Car car;
    EXPECT_EQ(car.getBrand(), "");
    EXPECT_EQ(car.getYear(), 0);
    EXPECT_DOUBLE_EQ(car.getMileage(), 0.0);
}

TEST(CarTest, ParameterizedConstructor) {
    Car car("Toyota", 2015, 120000.5);
    EXPECT_EQ(car.getBrand(), "Toyota");
    EXPECT_EQ(car.getYear(), 2015);
    EXPECT_DOUBLE_EQ(car.getMileage(), 120000.5);
}

TEST(CarTest, Setters) {
    Car car;
    car.setBrand("BMW");
    car.setYear(2020);
    car.setMileage(50000.0);
    
    EXPECT_EQ(car.getBrand(), "BMW");
    EXPECT_EQ(car.getYear(), 2020);
    EXPECT_DOUBLE_EQ(car.getMileage(), 50000.0);
}

TEST(CarTest, LessThanOperator) {
    Car car1("Audi", 2018, 80000);
    Car car2("BMW", 2020, 50000);
    
    EXPECT_TRUE(car1 < car2);
    EXPECT_FALSE(car2 < car1);
}

TEST(CarTest, EqualityOperator) {
    Car car1("Toyota", 2015, 120000);
    Car car2("Toyota", 2015, 120000);
    Car car3("Toyota", 2016, 120000);
    
    EXPECT_TRUE(car1 == car2);
    EXPECT_FALSE(car1 == car3);
}

TEST(CarTest, ToString) {
    Car car("Toyota", 2015, 120000.5);
    std::string expected = "Toyota (2015), mileage: 120000.50 km";
    EXPECT_EQ(car.toString(), expected);
}

TEST(CarByBrandTest, Sorting) {
    Car car1("Audi", 2018, 80000);
    Car car2("BMW", 2020, 50000);
    CarByBrand comp;
    
    EXPECT_TRUE(comp(car1, car2));
    EXPECT_FALSE(comp(car2, car1));
}

TEST(CarByYearTest, Sorting) {
    Car car1("Toyota", 2015, 120000);
    Car car2("BMW", 2020, 50000);
    CarByYear comp;
    
    EXPECT_TRUE(comp(car1, car2));
    EXPECT_FALSE(comp(car2, car1));
}

TEST(CarByMileageTest, Sorting) {
    Car car1("Toyota", 2015, 50000);
    Car car2("BMW", 2020, 120000);
    CarByMileage comp;
    
    EXPECT_TRUE(comp(car1, car2));
    EXPECT_FALSE(comp(car2, car1));
}