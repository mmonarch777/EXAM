#include "SpellBook.hpp"

SpellBook::SpellBook() {};
SpellBook::~SpellBook() {
    iter it = spells.begin();
    iter ite = spells.end();
    for (;it != ite; ++it) {
        delete *it;
    }
    spells.clear();
}
void SpellBook::learnSpell(ASpell *spell) {
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
void SpellBook::forgetSpell(std::string const &spellName) {
    iter it = spells.begin();
    iter ite = spells.end();
    for (; it != ite; ++it) {
        if ((*it)->getName() == spellName) {
            delete *it;
            it = spells.erase(it);
        }
    }
}
ASpell *SpellBook::generateSpell(std::string const &spellName) {
    iter it = spells.begin();
    iter ite = spells.end();
    for (; it != ite; ++it) {
        if ((*it)->getName() == spellName) {
            return (*it);
        }
    }
    return (nullptr);
}