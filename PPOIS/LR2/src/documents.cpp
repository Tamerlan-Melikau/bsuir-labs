#include "documents.hpp"

Contract::Contract(int salary, std::string strtedData, Worker w)
    :salary(salary), strtedData(strtedData), worker(w){}
Contract::~Contract(){}

void Contract::setSalary(int newSal){salary = newSal;}
void Contract::sign(){
    signed_ = true;
    std::cout << "Sign the contract";
}
void Contract::terminate(){std::cout << "Contract terminated\n";}
void Contract::work(){
    if(!signed_) throw ContractNotSignedException();
    std::cout << "Working under contract\n";
}

Advertisement::Advertisement(int budget, int views)
    :budget(budget), views(views){}
Advertisement::~Advertisement(){}

void Advertisement::start(){std::cout << "Upload the ad";}
void Advertisement::viewers(){std::cout << "Viewers: " << views << "\n";}
void Advertisement::stop(){std::cout << "Ad stopped\n";}

Award::Award(std::string t, int y, std::string c, Worker r)
    :title(t), year(y), category(c), recipient_(r){}
Award::~Award(){}

void Award::give(){std::cout << "Awarded: " << title << "\n";}
void Award::printInfo(){std::cout << title << " (" << year << ") - " << category << "\n";}
void Award::payPrize(){std::cout << "Prize paid: " << prizeMoney << "\n";}

Warehouse::Warehouse(int i, int c, Costume co)
    :itemsCount(i), capacity(c), costume(co){}
Warehouse::~Warehouse(){}

void Warehouse::store(){
    if(itemsCount >= capacity) throw WarehouseFullException();
    itemsCount++;
    std::cout << "Stored. Total: " << itemsCount << "\n";
}
void Warehouse::take(){itemsCount--; std::cout << "Taken. Total: " << itemsCount << "\n";}
bool Warehouse::isFull(){return itemsCount >= capacity;}