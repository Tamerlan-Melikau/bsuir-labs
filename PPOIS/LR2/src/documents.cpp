#include <string>
#include <iostream>

class Contract{
private:
    int salary;
    std::string strtedData;
    int months;
public:
    Contract(int salary, std::string strtedData)
        :salary(salary), strtedData(strtedData){}
    virtual ~Contract(){}

    void setSalary(int newSal){salary = newSal;}
    void sign(){std::cout << "Sign the contract";}
    void terminate(){std::cout << "Contract terminated\n";}
};

class Advertisement{
private:
    int budget;
    int views;
    std::string channel;
public:
    Advertisement(int budget, int views)
        :budget(budget), views(views){}
    virtual ~Advertisement(){}

    void start(){std::cout << "Upload the ad";}
    void viewers(){std::cout << "Viewers: "<< views << "\n";}
    void stop(){std::cout << "Ad stopped\n";}
};

class Award{
private:
    std::string title;
    int year;
    std::string category;
    std::string recipient;
    int prizeMoney;
public:
    Award(std::string t, int y, std::string c)
        :title(t), year(y), category(c){}
    virtual ~Award(){}

    void give(){std::cout << "Awarded: " << title << "\n";}
    void printInfo(){std::cout << title << " (" << year << ") - " << category << "\n";}
    void payPrize(){std::cout << "Prize paid: " << prizeMoney << "\n";}
};

class Warehouse{
private:
    int itemsCount;
    int capacity;
    std::string address;
public:
    Warehouse(int i, int c)
        :itemsCount(i), capacity(c){}
    virtual ~Warehouse(){}

    void store(){itemsCount++; std::cout << "Stored. Total: " << itemsCount << "\n";}
    void take(){itemsCount--; std::cout << "Taken. Total: " << itemsCount << "\n";}
    bool isFull(){return itemsCount >= capacity;}   
};