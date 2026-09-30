#pragma once
#include <exception>

class InvalidAgeException:public std::exception{
public:
    const char* what() const noexcept override{
        return "Invalid age value";
    }
};

class EmptyNameException:public std::exception{
public:
    const char* what() const noexcept override{
        return "Name cannot be empty";
    }
};

class InvalidSalaryException:public std::exception{
public:
    const char* what() const noexcept override{
        return "Invalid salary value";
    }
};

class InvalidTicketPriceException:public std::exception{
public:
    const char* what() const noexcept override{
        return "Invalid ticket price";
    }
};

class HallOverflowException:public std::exception{
public:
    const char* what() const noexcept override{
        return "Hall capacity exceeded";
    }
};

class WarehouseFullException:public std::exception{
public:
    const char* what() const noexcept override{
        return "Warehouse is full";
    }
};

class InstrumentBrokenException:public std::exception{
public:
    const char* what() const noexcept override{
        return "Instrument is broken";
    }
};

class BudgetExceededException:public std::exception{
public:
    const char* what() const noexcept override{
        return "Budget exceeded";
    }
};

class ContractNotSignedException:public std::exception{
public:
    const char* what() const noexcept override{
        return "Contract not signed";
    }
};

class RoleNotLearnedException:public std::exception{
public:
    const char* what() const noexcept override{
        return "Role is not learned";
    }
};

class InvalidDateException:public std::exception{
public:
    const char* what() const noexcept override{
        return "Invalid date";
    }
};

class TicketSoldOutException:public std::exception{
public:
    const char* what() const noexcept override{
        return "Ticket is sold out";
    }
};