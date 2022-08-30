#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {};
TargetGenerator::~TargetGenerator() {
    iter it = types.begin();
    iter ite = types.end();
    for (; it != ite; ++it) {
        delete *it;
    }
    types.clear();
}
void TargetGenerator::learnTargetType(ATarget *type) {
    if (type) {
        iter it = types.begin();
        iter ite = types.end();
        for (; it != ite; ++it) {
            if ((*it)->getType() == type->getType()) {
                return;
            }
        }
        types.push_back(type->clone());
    }
}
void TargetGenerator::forgetTargetType(std::string const &name) {
    iter it = types.begin();
    iter ite = types.end();
    for (; it != ite; ++it) {
        if ((*it)->getType() == name) {
            delete *it;
            it = types.erase(it);
        }
    }
}
ATarget *TargetGenerator::createTarget(std::string const &name) {
    iter it = types.begin();
    iter ite = types.end();
    for (; it != ite; ++it) {
        if ((*it)->getType() == name) {
            return (*it);
        }
    }
    return (nullptr);
}