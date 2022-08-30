#pragma once

#include "ASpell.hpp"
#include <vector>

class SpellBook {
public:
    typedef std::vector<ASpell *>::iterator iter;
private:
    std::vector<ASpell *> spells;

    SpellBook(SpellBook const &obj);
    SpellBook &operator=(SpellBook const &obj);

public:
    SpellBook();
    virtual ~SpellBook();

    void learnSpell(ASpell *spell);
    void forgetSpell(std::string const &spellName);
    ASpell *generateSpell(std::string const &spellName);
};