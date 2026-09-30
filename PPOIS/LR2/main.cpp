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

    try{
        Stage st(100, true);
        Hall big(50, true, st);
        big.fill(200);
    }
    catch(const HallOverflowException& e){
        std::cout << "Caught: " << e.what() << "\n";
    }

    try{
        Costume c(1, 1000, 50, "red");
        Warehouse wh(10, 10, c);  // уже полный
        wh.store();
    }
    catch(const WarehouseFullException& e){
        std::cout << "Caught: " << e.what() << "\n";
    }

    try{
        Violin v(1000, "string", 60, "wood", "high");
        v.checkCondition(60);
    }
    catch(const InstrumentBrokenException& e){
        std::cout << "Caught: " << e.what() << "\n";
    }

    try{
        Playbill pb("Hamlet", 500, "2026-01-01");
        Tour t("Minsk", 5, 10000, 100, pb);
        t.spend(50000);
    }
    catch(const BudgetExceededException& e){
        std::cout << "Caught: " << e.what() << "\n";
    }

    try{
        Worker w2(2, "Petr", 40, 60000);
        Contract c(50000, "2026-01-01", w2);
        c.work();   // контракт ещё не подписан — исключение
    }
    catch(const ContractNotSignedException& e){
        std::cout << "Caught: " << e.what() << "\n";
    }

    try{
        Role r("Hamlet", 100, 60);
        r.perform();  // роль не выучена — исключение
    }
    catch(const RoleNotLearnedException& e){
        std::cout << "Caught: " << e.what() << "\n";
    }

    try{
        Schedule bad(45, 13, 2026, 0);  // день 45, месяц 13 — ошибка
    }
    catch(const InvalidDateException& e){
        std::cout << "Caught: " << e.what() << "\n";
    }

    try{
        Cast c(5);
        Stage st(100, true);
        Hall h(50, true, st);
        Director d(1, "Ivan", 40, 80000, 10, 15, c, st);
        Performance p(time(nullptr), 1000, d, h, c, 2);  // вместимость 2
        p.sellTicket();
        p.sellTicket();
        p.sellTicket();  // третий раз — исключение
    }
    catch(const TicketSoldOutException& e){
        std::cout << "Caught: " << e.what() << "\n";
    }

    Violin condViolin(5000, "string", 5, "wood", "warm");
    Conductor cond(1, "Ivan", 45, 90000, 20, "Big Orchestra", condViolin);
    cond.conduct();
    
    return 0;
}