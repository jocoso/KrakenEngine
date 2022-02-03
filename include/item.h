#ifndef ITEM_H
#define ITEM_H

#include "./prop.h"


namespace rawr {
    class item : public prop {
        item( std::string name, std::string desc );
        ~item();
    };
}

#endif