#pragma once

#include <vector>
#include "ATarget.hpp"

class TargetGenerator {
public:
    typedef std::vector<ATarget *>::iterator iter;
private:
    std::vector<ATarget *> types;

    TargetGenerator(TargetGenerator const &obj);
    TargetGenerator &operator=(TargetGenerator const &obj);
public:
    TargetGenerator();
    virtual ~TargetGenerator();
    void learnTargetType(ATarget *type);
    void forgetTargetType(std::string const &name);
    ATarget *createTarget(std::string const &name);
};