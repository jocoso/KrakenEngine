#include "../include/rawr_object.h"

namespace rawr {
    rawr_object::rawr_object( std::string name, std::string desc ) {
        this->name = name;
        this->description = desc;
    }

    std::string rawr_object::get_name() {
        return this->name;
    }

    void rawr_object::set_name( std::string name ) {
        this->name = name;
    }

    std::string rawr_object::get_description() {
        return this->description;
    }

    void rawr_object::set_description( std::string name ) {
        this->description = name;
    }

}