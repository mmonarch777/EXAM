#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "ASpell.hpp"
#include "ATarget.hpp"
#include "SpellBook.hpp"

class Warlock {
public:
    typedef std::vector<ASpell *>::iterator iter;
private:
    std::string name;
    std::string title;
    SpellBook   spellBook;

    Warlock();
    Warlock(Warlock const &other);
    Warlock &operator=(Warlock const &other);

public:
    Warlock(std::string const &name, std::string const &title);
    virtual ~Warlock();

    std::string const &getName() const;
    std::string const &getTitle() const;
    void setTitle(std::string const &title);
    void introduce() const;

    void learnSpell(ASpell *spell);
    void forgetSpell(std::string const &spellName);
    void launchSpell(std::string const &spellName, ATarget const &target);
};