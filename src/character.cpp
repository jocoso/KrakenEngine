#include "../include/character.h"

namespace rawr {
    character::character( std::string name, std::string desc ) : prop( name, desc ) {}
    character::~character() {}
}