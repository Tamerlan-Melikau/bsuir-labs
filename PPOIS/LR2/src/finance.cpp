#include <string>
#include <iostream>

class Ticket{
private:
    int cost;
    bool VIP;
public:
    Ticket(int cost, bool vip)
        :cost(cost), VIP(vip){};

    virtual ~Ticket(){}

    int getcost() const{return cost;}
    bool getVIP() const{return VIP;}
};

class Sponsor {
private:
    int id;
    std::string name;
    std::string company;
    double budget;
public:
    Sponsor(int id, std::string name, std::string company, double budget)
        :id(id), name(name), company(company), budget(budget){}

    void donate(){std::cout << company << " спонсирует " << budget << "\n";}
    void signContract(){std::cout << company << " sign the contract\n"; }
    double getBudget() const{return budget;}
    std::string getName() const{return name;}
};