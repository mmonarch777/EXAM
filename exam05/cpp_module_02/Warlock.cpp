#include "Warlock.hpp"

Warlock::Warlock(std::string const &name, std::string const &title): name(name), title(title) {
    std::cout << this->name << ": This looks like another boring day.\n";
};
Warlock::~Warlock() {
    std::cout << this->name << ": My job here is done!\n";
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
    spellBook.learnSpell(spell);
}
void Warlock::forgetSpell(std::string const &spellName) {
    spellBook.forgetSpell(spellName);
}
void Warlock::launchSpell(std::string const &spellName, ATarget const &target) {
    ASpell *spell = spellBook.generateSpell(spellName);
    ATarget const *test = nullptr;
    if (test == &target) {
        return;
    }
    if (spell) {
        spell->launch(target);
    }
}