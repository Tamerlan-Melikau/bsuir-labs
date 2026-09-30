#include "people.hpp"

Cast::Cast(int actorsCount) : actorsCount(actorsCount) {}
Cast::~Cast() {}
void Cast::addActor(){ actorsCount++; std::cout << "Actor added. Total: " << actorsCount << "\n"; }
void Cast::printInfo(){ std::cout << "Actors in cast: " << actorsCount << "\n"; }

Spectator::Spectator(int id, std::string name, int age, int sal, std::string sec, int place, double balance)
    : id(id), name(name), age(age), salary(sal), sector(sec), placeNumber(place), balance(balance) {}
Spectator::~Spectator() {}
void Spectator::buyTicket(){ std::cout << name << " buy ticket\n"; }
void Spectator::pay(){ balance -= 100; std::cout << name << " paid\n"; }
void Spectator::leaveReview(){ std::cout << name << " left a review\n"; }
void Spectator::arrive(){ std::cout << name << " arrived at the theater\n"; }

Worker::Worker(int id, std::string name, int age, int salary){
    if(age < 0 || age > 120) throw InvalidAgeException();
    if(name.empty()) throw EmptyNameException();
    if(salary < 0) throw InvalidSalaryException();
    this->id = id;
    this->name = name;
    this->age = age;
    this->salary = salary;
}
Worker::~Worker() {}

Director::Director(int id, std::string name, int age, int salary, int rew, int exp, Cast c, Stage st)
    : Worker(id, name, age, salary), rewards(rew), experience(exp), cast(c), stage(st) {}
void Director::direct(){ std::cout << name << " puts the play\n"; }
void Director::chooseScript(){ std::cout << name << " chooses a script\n"; }
void Director::giveNotes(){ std::cout << name << " gives notes to actors\n"; }
void Director::approveCostumes(){ std::cout << name << " approves costumes\n"; }

Administrator::Administrator(int id, std::string name, int age, int salary, int met, int exp, Violin v)
    : Worker(id, name, age, salary), metingAmount(met), experience(exp), violin(v) {}
void Administrator::createSchedule(){ std::cout << name << " creates schedule"; }
void Administrator::controlBudget(){ std::cout << name << " controls expenses"; }
void Administrator::accept(){ std::cout << name << " makes decisions"; }
void Administrator::solve(){ std::cout << name << " solves problems"; }
void Administrator::raport(){ std::cout << name << " makes raports"; }

Accountant::Accountant(int id, std::string name, int age, int salary, int doc, int met)
    : Worker(id, name, age, salary), amountOfDocuments(doc), amountOfMetings(met) {}
void Accountant::document(){ std::cout << name << " maintainces documentation"; }

HRManager::HRManager(int id, std::string name, int age, int salary, int people, int met)
    : Worker(id, name, age, salary), amountOfTakenPeople(people), amountOfMetings(met) {}
void HRManager::accept(){ std::cout << name << " accepts offers"; }

Composer::Composer(int id, std::string name, int age, int salary, int works, std::string inst)
    : Worker(id, name, age, salary), worksCount(works), instrument(inst) {}
void Composer::composeMusic(){ std::cout << name << " composes music\n"; }

Playwright::Playwright(int id, std::string name, int age, int salary, int plays, std::string gen)
    : Worker(id, name, age, salary), playsWritten(plays), genre(gen) {}
void Playwright::writePlay(){ std::cout << name << " write the play\n"; }

Choreographer::Choreographer(int id, std::string name, int age, int salary, int exp)
    : Worker(id, name, age, salary), experience(exp) {}
void Choreographer::stageDance(){ std::cout << name << " sets the dance\n"; }
void Choreographer::teachDancers(){ std::cout << name << " trains dancers\n"; }

SoundDesigner::SoundDesigner(int id, std::string name, int age, int salary, int tr)
    : Worker(id, name, age, salary), tracksCount(tr) {}
void SoundDesigner::createMusic(){ std::cout << name << " creates music\n"; }
void SoundDesigner::setupMicrophones(){ std::cout << name << " sets mikrophones\n"; }

Conductor::Conductor(int id, std::string name, int age, int salary, int exp, std::string orch, Instrument inst)
    : Worker(id, name, age, salary), experience(exp), orchestraName(orch), instrument(inst) {}
void Conductor::conduct(){ std::cout << name << " conducting\n"; }
void Conductor::rehearseOrchestra(){ std::cout << name << " rehearses with orchestra\n"; }

Musician::Musician(std::string n, int exp) : name(n), experience(exp) {}
Musician::~Musician() {}

Violinist::Violinist(std::string n, int exp, Violin v) : Musician(n, exp), violin(v) {}
void Violinist::play(){ std::cout << name << " plays violin\n"; }

Cellist::Cellist(std::string n, int exp, Cello c) : Musician(n, exp), cello(c) {}
void Cellist::play(){ std::cout << name << " plays cello\n"; }

Pianist::Pianist(std::string n, int exp, Piano p) : Musician(n, exp), piano(p) {}
void Pianist::play(){ std::cout << name << " plays piano\n"; }

Flutist::Flutist(std::string n, int exp, Flute f) : Musician(n, exp), flute(f) {}
void Flutist::play(){ std::cout << name << " plays flute\n"; }

Contrabassist::Contrabassist(std::string n, int exp, Contrabass c) : Musician(n, exp), contrabass(c) {}
void Contrabassist::play(){ std::cout << name << " plays contrabass\n"; }

Actor::Actor(int id, std::string name, int age, int salary, int exp, int height, Role r, Costume c, Character ch)
    : Worker(id, name, age, salary), experience(exp), height(height), role(r), costume(c), character(ch) {}
void Actor::perform(){ std::cout << name << " play the role\n"; }
void Actor::rehearse(){ std::cout << name << " rehearses\n"; }
void Actor::memorizeLines(){ std::cout << name << " memorizes lines\n"; }
void Actor::takeBreak(){ std::cout << name << " takes a break\n"; }

Singer::Singer(int id, std::string name, int age, int salary, std::string voice, Microphone m)
    : Worker(id, name, age, salary), voiceType(voice), mic(m) {}
void Singer::singAria(){ std::cout << name << " performs an aria\n"; }
void Singer::warmUp(){ std::cout << name << " waming up\n"; }

OperaActor::OperaActor(int id, std::string name, int age, int salary,
                       int exp, int height, Role r, Costume c, Character ch,
                       std::string voice, Microphone m, int range)
    : Worker(id, name, age, salary),
      Actor(id, name, age, salary, exp, height, r, c, ch),
      Singer(id, name, age, salary, voice, m),
      vocalRange(range) {}
void OperaActor::singOperaAria(){
    std::cout << name << " sings opera aria, range " << vocalRange << "\n";
}

Acrobat::Acrobat(int id, std::string name, int age, int salary, int exp, int wei)
    : Worker(id, name, age, salary), experince(exp), weight(wei) {}
void Acrobat::perform(){ std::cout << name << " perform the acrobatic element"; }

Cashier::Cashier(int id, std::string name, int age, int salary, int ticket)
    : Worker(id, name, age, salary), soldTickets(ticket) {}
void Cashier::amount(int soldTickets){ std::cout << "Sold " << soldTickets << " tickets"; }

Cleaner::Cleaner(int id, std::string name, int age, int salary, int hours)
    : Worker(id, name, age, salary), hours(hours) {}
void Cleaner::work(){ std::cout << "Works " << hours << "hour"; }
void Cleaner::mop(){ std::cout << name << " mops floor\n"; }
void Cleaner::vacuum(){ std::cout << name << " vacuums the hall\n"; }

Doctor::Doctor(int id, std::string name, int age, int salary, int patients)
    : Worker(id, name, age, salary), patientsPerDay(patients) {}
void Doctor::examine(){ std::cout << name << " осматривает пациента\n"; }
void Doctor::prescribeMedicine(){ std::cout << name << " выписывает лекарство\n"; }
void Doctor::giveSickLeave(){ std::cout << name << " выдает больничный\n"; }

Dancer::Dancer(int id, std::string name, int age, int salary, std::string st, int exp, Costume c)
    : Worker(id, name, age, salary), style(st), experienceYears(exp), costume(c) {}
void Dancer::dance(){ std::cout << name << " dance\n"; }
void Dancer::rehearseNumber(){ std::cout << name << " rehearses number\n"; }

MakeupArtist::MakeupArtist(int id, std::string name, int age, int salary, int clients)
    : Worker(id, name, age, salary), clientsPerDay(clients) {}
void MakeupArtist::applyMakeup(){ std::cout << name << " makes makeup\n"; }
void MakeupArtist::removeMakeup(){ std::cout << name << " takes off makeup\n"; }

Bartender::Bartender(int id, std::string name, int age, int salary, int amount)
    : Worker(id, name, age, salary), soldAmount(amount) {}
void Bartender::sellfood(){ std::cout << name << " sells food\n"; }

Security::Security(int id, std::string name, int age, int salary, std::string gun)
    : Worker(id, name, age, salary), gunType(gun) {}
void Security::patrol(){ std::cout << "Patroling the area;\n"; }
void Security::type(){ std::cout << "Gun type: " << gunType; }