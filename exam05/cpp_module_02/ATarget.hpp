#pragma once

#include <iostream>
#include <string>
#include "ASpell.hpp"

class ASpell;

class ATarget {
private:
    std::string type;

public:
    ATarget();
    ATarget(std::string const &type);
    ATarget(ATarget const &obj);
    virtual ~ATarget();

    ATarget &operator=(ATarget const &obj);
    std::string const &getType() const;
    void getHitBySpell(ASpell const &spell) const;
    virtual ATarget *clone() const = 0;
};