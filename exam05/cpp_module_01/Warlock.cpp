#include "Warlock.hpp"

Warlock::Warlock(std::string const &name, std::string const &title): name(name), title(title) {
    std::cout << this->name << ": This looks like another boring day.\n";
};
Warlock::~Warlock() {
    std::cout << this->name << ": My job here is done!\n";
    iter it = spells.begin();
    iter ite = spells.end();
    for(; it != ite; ++it) {
        delete *it;
    }
    spells.clear();
};

std::string const &Warlock::getName() const {
    return this->name;
}
std::string const &Warlock::getTitle() const {
    return this->title;
}
void Warlock::setTitle(std::string const &title) {
    this->title = title;
}
void Warlock::introduce() const {
    std::cout << this->name << ": I am " << this->name << ", " << this->title << "!\n";
}
void Warlock::learnSpell(ASpell *spell) {
    if (spell) {
        iter it = spells.begin();
        iter ite = spells.end();
        for (; it != ite; ++it) {
            if ((*it)->getName() == spell->getName()) {
                return;
            }
        }
        spells.push_back(spell->clone());
    }
}
void Warlock::forgetSpell(std::string const &spellName) {
    iter it = spells.begin();
    iter ite = spells.end();
    for (; it != ite; ++it) {
        if ((*it)->getName() == spellName) {
            delete *it;
            it = spells.erase(it);
        }
    }
}
void Warlock::launchSpell(std::string const &spellName, ATarget const &target) {
    iter it = spells.begin();
    iter ite = spells.end();
    for (; it != ite; ++it) {
        if ((*it)->getName() == spellName) {
            (*it)->launch(target);
            return;
        }
    }
}