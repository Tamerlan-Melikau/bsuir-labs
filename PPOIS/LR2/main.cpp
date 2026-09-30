#include "play.hpp"
#include "invent.hpp"
#include "places.hpp"
#include "documents.hpp"
#include "people.hpp"
#include "schedule.hpp"
#include "finance.hpp"
#include "exceptions.hpp"

int main(){
    Worker w(1, "Ivan", 30, 50000);
    std::cout << w.getName() << "\n";

    try{
        Worker bad(1, "Test", -5, 1000);
    }
    catch(const InvalidAgeException& e){
        std::cout << "Caught: " << e.what() << "\n";
    }

    try{
        Worker noName(1, "", 30, 5000);
    }
    catch(const EmptyNameException& e){
        std::cout << "Caught: " << e.what() << "\n";
    }

    try{
        Worker badSal(1, "Ivan", 30, -500);
    }
    catch(const InvalidSalaryException& e){
        std::cout << "Caught: " << e.what() << "\n";
    }

    try{
        Spectator sp(1, "Ivan", 30, 50000, "A", 5, 1000);
        Ticket badTicket(-100, false, 5, sp);
    }
    catch(const InvalidTicketPriceException& e){
        std::cout << "Caught: " << e.what() << "\n";
    }

    return 0;
}