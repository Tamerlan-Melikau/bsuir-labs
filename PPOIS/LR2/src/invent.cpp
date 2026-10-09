#include "invent.hpp"

Costume::Costume(int num, int cost, int size, std::string color)
    :inventNumber(num), cost(cost), size(size), color(color){}

void Costume::tryOn(){std::cout << "Suit " << inventNumber << "примеряется";}
void Costume::repair(){std::cout << "Costume " << inventNumber << " repaired\n";}

Decoration::Decoration(int num, int cost, Stage st)
    :inventNumber(num), cost(cost), stage(st){}

void Decoration::use(){std::cout << "Decoration " << inventNumber << "usess";}
void Decoration::dismantle(){std::cout << "Decoration " << inventNumber << " dismantled\n";}

Instrument::Instrument(int cost, std::string type, int yold, std::string sound)
    :cost(cost), type(type), yold(yold), sound(sound){}

void Instrument::repairString(){std::cout << "String repaired\n";}
void Instrument::checkCondition(int yold){
    if(yold > 50) throw InstrumentBrokenException();
    std::cout << "Instrument is fine\n";
}

Violin::Violin(int cost, std::string type, int yold, std::string mat, std::string sound)
    :Instrument(cost, type, yold, sound), material(mat){}

void Violin::playPizzicato(){std::cout << "Violin plays pizzicato\n";}
void Violin::makeSound(){std::cout << "Sound: " << sound;}

Cello::Cello(int cost, std::string type, int yold, int size, std::string sound)
    :Instrument(cost, type, yold, sound), size(size){}

void Cello::playArco(){std::cout << "Cello plays arco\n";}
void Cello::makeSound(){std::cout << "Sound: " << sound;}

Piano::Piano(int cost, std::string type, int yold, int key, std::string sound)
    :Instrument(cost, type, yold, sound), keyCount(key){}

void Piano::makeSound(){std::cout << "Sound: " << sound;}
void Piano::playChord(){std::cout << "Piano plays a chord\n";}

Flute::Flute(int cost, std::string type, int yold, std::string mat, int holes, std::string sound)
    :Instrument(cost, type, yold, sound), material(mat), holesCount(holes){}

void Flute::playHigh(){std::cout << "Flute plays a high note\n";}
void Flute::makeSound(){std::cout << "Sound: " << sound;}

Contrabass::Contrabass(int cost, std::string type, int yold, int strings, int size, std::string sound)
    :Instrument(cost, type, yold, sound), stringCount(strings), bodySize(size){}

void Contrabass::playLow(){std::cout << "Contrabass plays a low tone\n";}
void Contrabass::makeSound(){std::cout << "Sound: " << sound;}

Equipment::Equipment(int cost, std::string brand)
    :cost(cost), brand(brand){}

Speaker::Speaker(int cost, std::string brand, int ch, int vol, Hall h)
    :Equipment(cost, brand), channels(ch), maxVolume(vol), hall(h){}

void Speaker::playSound(){std::cout << "Speaker plays sound\n";}
void Speaker::setVolume(int v){maxVolume = v; std::cout << "Volume set to " << v << "\n";}

Microphone::Microphone(int cost, std::string brand, std::string t, bool wireless)
    :Equipment(cost, brand), type(t), isWireless(wireless){}

void Microphone::capture(){std::cout << "Microphone captures voice\n";}
void Microphone::mute(){std::cout << "Microphone muted\n";}

Spotlight::Spotlight(int cost, std::string brand, std::string col, int ang)
    :Equipment(cost, brand), color(col), angle(ang){}

void Spotlight::turnOn(){std::cout << "Spotlight on, color: " << color << "\n";}
void Spotlight::turnOff(){std::cout << "Spotlight off\n";}
void Spotlight::rotate(int degrees){angle += degrees; std::cout << "Angle: " << angle << "\n";}