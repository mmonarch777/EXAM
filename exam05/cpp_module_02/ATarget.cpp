#include "ATarget.hpp"

ATarget::ATarget(): type() {};
ATarget::ATarget(std::string const &type): type(type) {};
ATarget::ATarget(ATarget const &obj): type(obj.type) {};
ATarget::~ATarget() {};

ATarget &ATarget::operator=(ATarget const &obj) {
    if (this != &obj) {
        type = obj.type;
    }
    return *this;
}
std::string const &ATarget::getType() const {
    return type;
}
void ATarget::getHitBySpell(ASpell const &spell) const {
    std::cout << this->type << " has been " << spell.getEffects() << "!\n";
}