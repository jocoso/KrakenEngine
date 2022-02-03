#include "../include/prop.h"

namespace rawr {
    prop::prop( std::string name, std::string desc ) {
        this->name = name;
        this->description = desc;
    }

    std::string prop::get_name() {
        return this->name;
    }

    void prop::set_name( std::string name ) {
        this->name = name;
    }

    std::string prop::get_description() {
        return this->description;
    }

    void prop::set_description( std::string name ) {
        this->description = name;
    }

}