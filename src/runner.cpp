#include "../include/runner.h"

#include <stdbool.h>
#include <iostream>
#include <sstream>
#include <string.h>
#include <string>
#include <vector>



namespace rawr {

    runner::runner() {

    }
            
    
    void runner::run() {

        if( !this->main_narrator.check_narrator_integrity() ) {
            perror( "RAWR_ERROR[101]: Narrator is not set up correctly. Add to it an instace of general_book or scene to solve this issue." );
            exit( 1 );
        }
        
        std::string bye = "quit";
        char* input;
   
        std::cout << main_narrator.getIntro() << std::endl;

        while( true ) {

            std::string raw_input;
            int text_size = 0;
            
            std::cout << ">";

            // Get user input
            getline( std::cin, raw_input );
            input = strdup( raw_input.c_str() );
            
            // If input 1 is quit break

            if( strcmp( input, bye.c_str() ) == 0 ) break;


            std::cout << main_narrator.exec( strtok( input, " " ) ) << std::endl;
            input = nullptr;
        }
        // Bye message
        std::cout << "GoodBye!"<< std::endl;
    }

    void runner::setNarrator( narrator narrator ) {
        this->main_narrator = narrator;
    }
    
    runner::~runner() {}

}

