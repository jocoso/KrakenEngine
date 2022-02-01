#ifndef _RAWR_OBJECT_H
#define _RAWR_OBJECT_H

    #include <string>

    namespace rawr {
        class rawr_object {
            public: 
                rawr_object();
                rawr_object( std::string name, std::string desc );
                std::string get_name();
                void set_name( std::string name );
                std::string get_description();
                void set_description( std::string name );
            
            private:
                std::string name;
                std::string description;
        };
    }

#endif