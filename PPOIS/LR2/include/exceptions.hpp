#pragma once
#include <exception>
#include "exceptions.hpp"

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

class HallOverflowException : public std::exception{
public:
    const char* what() const noexcept override{
        return "Hall capacity exceeded";
    }
};