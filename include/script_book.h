#ifndef SCRIPT_BOOK_H
#define SCRIPT_BOOK_H

    #include <string>
    #include <iostream>
    #include <fstream>
    #include <experimental/filesystem>
    #include <vector>
    #include <unistd.h>
    #include "../rapidxml-1.13/rapidxml.hpp"

    using std::string;
    using std::ifstream;
    using std::cout;
    using std::endl;

    using std::experimental::filesystem::current_path;
    
    namespace rawr {
        class script_book {
            public:
                string get_current_dir();
                void execute_script( ifstream &file );
                void print( const char *content );
            private:
                rapidxml::xml_document<> doc;
                rapidxml::xml_node<> *root_node = NULL;
        };
    }

#endif