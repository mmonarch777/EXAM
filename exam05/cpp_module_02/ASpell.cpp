#include "ASpell.hpp"

ASpell::ASpell(): name(), effects() {};
ASpell::ASpell(std::string const &name, std::string const &effects): name(name), effects(effects) {};
ASpell::ASpell(ASpell const &obj): name(obj.name), effects(obj.effects) {};
ASpell::~ASpell() {};

ASpell &ASpell::operator=(ASpell const &obj) {
    if (this != &obj) {
        name = obj.name;
        effects = obj.effects;
    }
    return *this;
}
std::string const &ASpell::getName() const {
    return name;
}
std::string const &ASpell::getEffects() const {
    return effects;
}
void ASpell::launch(ATarget const &target) const {
    target.getHitBySpell(*this);
}