#include "play.hpp"

Role::Role(std::string name, int lines, int dur)
    :name(name), linesCount(lines), durationMin(dur){}
Role::~Role(){}

void Role::learn(){
    learned_ = true;
    std::cout << "Learning role: " << name << "\n";
}
void Role::perform(){
    if(!learned_) throw RoleNotLearnedException();
    std::cout << "Performing role: " << name << "\n";
}

Character::Character(std::string name, int age, std::string description)
    :name(name), age(age), description(description){}
Character::~Character(){}

void Character::describe(){std::cout << name << ", " << age << ": " << description << "\n";}
void Character::kill(){isAlive = false; std::cout << name << " died\n";}

Scene::Scene(int number, int duration, std::string location, Character mc)
    :number(number), duration(duration), location(location), mainChar(mc){}
Scene::~Scene(){}

void Scene::start(){std::cout << "Scene " << number << " started\n";}
void Scene::finish(){std::cout << "Scene " << number << " finished\n";}
void Scene::setLocation(const std::string& newLoc){location = newLoc;}

Act::Act(int n, int s, std::string t, Scene fs)
    :number(n), scenesCount(s), title(t), firstScene(fs){}
Act::~Act(){}

void Act::printInfo(){std::cout << "Act " << number << ": " << title << "\n";}

Audition::Audition(std::string d, int a, std::string r)
    :date(d), applicantsCount(a), roleName(r){}
Audition::~Audition(){}

void Audition::start(){std::cout << "Audition for " << roleName << " started\n";}