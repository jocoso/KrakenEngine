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
        
        std::string bye = "quit";
        char* input;
   
        // std::cout << main_narrator.getIntro() << std::endl;

        while(true) {

            std::string raw_input;
            int text_size = 0;
            
            std::cout << ">";

            // Get user input
            getline(std::cin, raw_input);
            input = strdup(raw_input.c_str());
            
            // If input 1 is quit break

            if(strcmp(input, bye.c_str()) == 0) break;


            std::cout << main_narrator.exec(strtok(input, " ")) << std::endl;
            input = nullptr;
        }
        // Bye message
        std::cout << "GoodBye!"<< std::endl;
    }

    void runner::setNarrator(rawr::narrator narrator) {
        this->main_narrator = narrator;
    }
    
    runner::~runner() {

    }

}

