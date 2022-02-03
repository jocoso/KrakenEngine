#ifndef CHARACTER_H
#define CHARACTER_H

    #include "./prop.h"

    namespace rawr {
        class character : public prop {
            character( std::string name, std::string desc );
            ~character();
        };
    }
#endif