#include "../include/item.h"

namespace rawr {
    item::item( std::string name, std::string desc ) : prop( name, desc ) {}
    item::~item() {}
}