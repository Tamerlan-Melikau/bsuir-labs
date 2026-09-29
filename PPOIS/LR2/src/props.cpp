#include <string>
#include <iostream>

class Costume{
private:
    int inventNumber;
    int cost;
    int size;
    std::string color;
public:
    Costume(int num, int cost, int size, std::string color)
        :inventNumber(num), cost(cost), size(size), color(color){}

    void tryOn(){std::cout << "Suit " << inventNumber << "примеряется";}
};

class Decoration{
private:
    int inventNumber;
    int cost;
public:
    Decoration(int num, int cost)
        :inventNumber(num), cost(cost){}

    void use(){std::cout << "Decoration " << inventNumber << "usess";}
};

class Instrument{
protected:
    int cost;
    std::string type;
    int yold;
    std::string sound;
public:
    Instrument(int cost, std::string type, int yold, std::string sound)
        :cost(cost), type(type), yold(yold), sound(sound){}

    virtual ~Instrument(){}

    int getcost(){return cost;}
    std::string gettype(){return type;}
};

class Violin:public Instrument{
private:
    std::string material;
public:
    Violin(int cost, std::string type, int yold, std::string mat, std::string sound)
    :Instrument(cost, type, yold, sound), material(mat){}

    void makeSound(){std::cout << "Sound: " << sound;}
};

class Cello:public Instrument{
private:
    int size;
public:
    Cello(int cost, std::string type, int yold, int size, std::string sound)
    :Instrument(cost, type, yold, sound), size(size){}

    void makeSound(){std::cout << "Sound: " << sound;}
};

class Piano:public Instrument{
private:
    int keyCount;
public:
    Piano(int cost, std::string type, int yold, int key, std::string sound)
    :Instrument(cost, type, yold, sound), keyCount(key){}

    void makeSound(){std::cout << "Sound: " << sound;}
};