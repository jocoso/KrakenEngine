#include <string>
#include <iostream>
#include <fstream>

#include "../include/script_book.h"
#include "../rapidxml-1.13/rapidxml.hpp"


int main() {
    rawr::script_book book;

    std::ifstream theFile( book.get_current_dir() + "\\scripts\\chapter1.xml" );
    
    if( theFile.is_open() ) {
        book.execute_script(theFile);
    } else {
        std::cout << "rtara" << std::endl;
    }

    return 0;
}