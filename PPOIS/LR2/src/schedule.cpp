#include "schedule.hpp"

Playbill::Playbill(std::string title, int price, std::string date)
    : title(title), price(price), date(date) {}
Playbill::~Playbill() {}
void Playbill::announce(){ std::cout << "Announcing: " << title << "\n"; }
void Playbill::data(){ std::cout << "Data: " << date; }
void Playbill::printPoster(){ std::cout << "Poster printed: " << title << "\n"; }

PremiereInvitation::PremiereInvitation(std::string title, int price, std::string date, std::string guest)
    : Playbill(title, price, date), guestName(guest) {}
void PremiereInvitation::present(){
    announce();
    std::cout << "Dear " << guestName << ", price: " << getPrice() << "\n";
}

Performance::Performance(std::time_t data, int boxOffice, Director d, Hall h, Cast c, int cap)
    : data(data), boxOffice(boxOffice), director(d), hall(h), cast(c), capacity(cap), ticketsSold(0) {}
Performance::~Performance() {}
void Performance::setdata(const std::time_t& newData){ data = newData; }
void Performance::hold(){ std::cout << "Performance " << title << " on hold\n"; }
void Performance::sellTicket(){
    if(ticketsSold >= capacity) throw TicketSoldOutException();
    ticketsSold++;
    std::cout << "Ticket sold. Total: " << ticketsSold << "\n";
}

Rehearsal::Rehearsal(std::time_t data, int amount, int peopleCount, Stage st, Actor a)
    : data(data), amount(amount), peopleCount(peopleCount), stage(st), leadActor(a) {}
Rehearsal::~Rehearsal() {}
void Rehearsal::setdata(const std::time_t& newData){ data = newData; }
void Rehearsal::setAmount(int newAmount){ amount = newAmount; }
void Rehearsal::setPeople(int newPeople){ peopleCount = newPeople; }
void Rehearsal::cancel(){ std::cout << "Rehearsal cancelled\n"; }

Tour::Tour(std::string city, int days, double budget, int sold, Playbill pb)
    : city(city), days(days), budget(budget), ticketsSold(sold), playbill(pb) {}
Tour::~Tour() {}
void Tour::start(){ std::cout << "Tour in " << city << " started\n"; }
void Tour::end(){ std::cout << "Tour ended\n"; }
void Tour::spend(double amount){
    if(amount > budget) throw BudgetExceededException();
    budget -= amount;
    std::cout << "Spent " << amount << ", left: " << budget << "\n";
}

Schedule::Schedule(int d, int m, int y, int events){
    if(d < 1 || d > 31 || m < 1 || m > 12) throw InvalidDateException();
    this->day = d;
    this->month = m;
    this->year = y;
    this->eventsCount = events;
}
Schedule::~Schedule() {}
void Schedule::addEvent(){ eventsCount++; }
void Schedule::printDay(){ std::cout << day << " " << month << ": " << eventsCount << " events\n"; }
void Schedule::removeEvent(){ eventsCount--; std::cout << "Event removed\n"; }

Intermission::Intermission(int duration, std::string time, bool buffet)
    : durationMinutes(duration), startTime(time), hasBuffet(buffet) {}
Intermission::~Intermission() {}
void Intermission::start(){ std::cout << "Intermission started at " << startTime << "\n"; }
void Intermission::extend(){ durationMinutes += 5; std::cout << "Intermission extended\n"; }

ReservedStage::ReservedStage(int size, bool hasOrchestraPit)
    : Stage(size, hasOrchestraPit) {}
void ReservedStage::reserve(){
    prepare();
    std::cout << "Stage reserved\n";
}