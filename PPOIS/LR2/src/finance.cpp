#include <string>
#include <iostream>

class Ticket{
private:
    int row;
    int cost;
    bool VIP;
public:
    Ticket(int cost, bool vip, int row)
        :cost(cost), VIP(vip), row(row){};
    virtual ~Ticket(){}

    void print(){std::cout << "Ticket row " << row << ", cost " << cost << "\n";}
    int getcost() const{return cost;}
    bool getVIP() const{return VIP;}
};

class Sponsor {
private:
    int contractYears;
    int id;
    std::string name;
    std::string company;
    double budget;
public:
    Sponsor(int id, std::string name, std::string company, double budget)
        :id(id), name(name), company(company), budget(budget){}
    virtual ~Sponsor(){}

    void donate(){std::cout << company << " спонсирует " << budget << "\n";}
    void signContract(){std::cout << company << " sign the contract\n"; }
    double getBudget() const{return budget;}
    std::string getName() const{return name;}
    void withdraw(){std::cout << company << " withdrew sponsorship\n";}
};