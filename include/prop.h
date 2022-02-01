#ifndef PROP_H
#define PROP_H

    #include <string>

    namespace rawr {
        class prop {
            public: 
                explicit prop( std::string name, std::string desc );
                std::string get_name();
                void set_name( std::string name );
                std::string get_description();
                void set_description( std::string name );
            
            protected:
                std::string name;
                std::string description;
        };
    }

#endif