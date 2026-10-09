#include "finance.hpp"

Ticket::Ticket(int cost, bool vip, int row, Spectator s)
    :cost(cost), VIP(vip), row(row), owner(s)
{
    if(cost < 0) throw InvalidTicketPriceException();
}

void Ticket::print(){std::cout << "Ticket row " << row << ", cost " << cost << "\n";}

Sponsor::Sponsor(int id, std::string name, std::string company, double budget, Contract c)
    :id(id), name(name), company(company), budget(budget), contract(c){}

void Sponsor::donate(){std::cout << company << " спонсирует " << budget << "\n";}
void Sponsor::signContract(){std::cout << company << " sign the contract\n";}
void Sponsor::withdraw(){std::cout << company << " withdrew sponsorship\n";}