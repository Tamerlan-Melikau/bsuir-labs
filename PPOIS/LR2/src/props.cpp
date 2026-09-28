#include <string>
#include <iostream>

class Costume{
private:
    int invenNumber;
    int cost;
    int size;
    std::string color;
public:
    Costume(int num, int cost, int size, std::string color)
        :invenNumber(num), cost(cost), size(size), color(color){}

    void tryOn(){std::cout << "Suit " << invenNumber << "примеряется";}
};

class Decoration{
private:
    int invenNumber;
    int cost;
public:
    Decoration(int num, int cost)
        :invenNumber(num), cost(cost){}

    void use(){std::cout << "Decoration " << invenNumber << "usess";}
};

class Instrument{
private:
    int cost;
    std::string type;
    int yold;
public:
    Instrument(int cost, std::string type, int yold)
        :cost(cost), type(type), yold(yold){}

    virtual ~Instrument(){}

    int getcost(){return cost;}
    std::string gettype(){return type;}
};

class Violin:public Instrument{
private:
    std::string material;
public:
    Violin(int cost, std::string type, int yold, std::string mat)
    :Instrument(cost, type, yold), material(mat){}

    void makeSound(){std::cout << "Издает высокий звук";}
};

class Cello:public Instrument{
private:
    int size;
public:
    Cello(int cost, std::string type, int yold, int size)
    :Instrument(cost, type, yold), size(size){}

    void makeSound(){std::cout << "Издает густой и глубокий звук";}
};

class Piano:public Instrument{
private:
    int keyCount;
public:
    Piano(int cost, std::string type, int yold, int key)
    :Instrument(cost, type, yold), keyCount(key){}

    void makeSound(){std::cout << "Издает богатый и объемный звук";}
};