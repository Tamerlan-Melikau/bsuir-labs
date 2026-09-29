#include <string>
#include <iostream>

class Costume{
private:
    int inventNumber;
    int cost;
    int size;
    std::string color;
    std::string material;
public:
    Costume(int num, int cost, int size, std::string color)
        :inventNumber(num), cost(cost), size(size), color(color){}
    virtual ~Costume(){}

    void tryOn(){std::cout << "Suit " << inventNumber << "примеряется";}
    void repair(){std::cout << "Costume " << inventNumber << " repaired\n";}
};

class Decoration{
private:
    std::string theme;
    int inventNumber;
    int cost;
public:
    Decoration(int num, int cost)
        :inventNumber(num), cost(cost){}
    virtual ~Decoration(){}

    void use(){std::cout << "Decoration " << inventNumber << "usess";}
    void dismantle(){std::cout << "Decoration " << inventNumber << " dismantled\n";}
};

class Instrument{
protected:
    int cost;
    int yold;
    std::string brand;
    std::string type;
    std::string sound;
public:
    Instrument(int cost, std::string type, int yold, std::string sound)
        :cost(cost), type(type), yold(yold), sound(sound){}
    virtual ~Instrument(){}

    int getcost(){return cost;}
    std::string gettype(){return type;}
    void repairString(){std::cout << "String repaired\n";}
};

class Violin:public Instrument{
private:
    std::string bowHair;
    std::string material;
public:
    Violin(int cost, std::string type, int yold, std::string mat, std::string sound)
    :Instrument(cost, type, yold, sound), material(mat){}

    void playPizzicato(){std::cout << "Violin plays pizzicato\n";}
    void makeSound(){std::cout << "Sound: " << sound;}
};

class Cello:public Instrument{
private:
    int size;
    int endpin;
public:
    Cello(int cost, std::string type, int yold, int size, std::string sound)
    :Instrument(cost, type, yold, sound), size(size){}

    void playArco(){std::cout << "Cello plays arco\n";}
    void makeSound(){std::cout << "Sound: " << sound;}
};

class Piano:public Instrument{
private:
    std::string pedalType;
    int keyCount;
public:
    Piano(int cost, std::string type, int yold, int key, std::string sound)
    :Instrument(cost, type, yold, sound), keyCount(key){}

    void makeSound(){std::cout << "Sound: " << sound;}
    void playChord(){std::cout << "Piano plays a chord\n";}
};

class Flute:public Instrument{
private:
    std::string material;
    int holesCount;
public:
    Flute(int cost, std::string type, int yold, std::string mat, int holes, std::string sound)
    :Instrument(cost, type, yold, sound), material(mat), holesCount(holes){}

    void playHigh(){std::cout << "Flute plays a high note\n";}
    void makeSound(){std::cout << "Sound: " << sound;}
};

class Contrabass:public Instrument{
private:
    int stringCount;
    int bodySize;
public:
    Contrabass(int cost, std::string type, int yold, int strings, int size, std::string sound)
    :Instrument(cost, type, yold, sound), stringCount(strings), bodySize(size){}

    void playLow(){std::cout << "Contrabass plays a low tone\n";}
    void makeSound(){std::cout << "Sound: " << sound;}
};

class Equipment{
protected:
    int cost;
    std::string brand;
public:
    Equipment(int cost, std::string brand)
        :cost(cost), brand(brand){}
    virtual ~Equipment(){}

    int getCost() const{return cost;}
    std::string getBrand() const{return brand;}
};

class Speaker:public Equipment{
private:
    int channels;
    int maxVolume;
public:
    Speaker(int cost, std::string brand, int ch, int vol)
        :Equipment(cost, brand), channels(ch), maxVolume(vol){}

    void playSound(){std::cout << "Speaker plays sound\n";}
    void setVolume(int v){maxVolume = v; std::cout << "Volume set to " << v << "\n";}
};

class Microphone:public Equipment{
private:
    std::string type;
    bool isWireless;
public:
    Microphone(int cost, std::string brand, std::string t, bool wireless)
        :Equipment(cost, brand), type(t), isWireless(wireless){}

    void capture(){std::cout << "Microphone captures voice\n";}
    void mute(){std::cout << "Microphone muted\n";}
};

class Spotlight:public Equipment{
private:
    std::string color;
    int angle;
public:
    Spotlight(int cost, std::string brand, std::string col, int ang)
        :Equipment(cost, brand), color(col), angle(ang){}

    void turnOn(){std::cout << "Spotlight on, color: " << color << "\n";}
    void turnOff(){std::cout << "Spotlight off\n";}
    void rotate(int degrees){angle += degrees; std::cout << "Angle: " << angle << "\n";}
};