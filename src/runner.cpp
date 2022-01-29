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
        
        std::vector<std::string> input;
        std::string bye = "quit";
   
        while(true) {
            std::string raw_input;
            
            std::cout << ">";

            // Get user input
            std::getline(std::cin, raw_input);
            
            // If input 1 is quit break

            if(strcmp(raw_input.c_str(), bye.c_str()) == 0) break;

            // Separate input into pieces
            std::stringstream ss(raw_input);

            while(ss.good()) {
                std::string a;
                std::getline(ss, a, ' ');
                input.push_back(a);
            }

            std::cout << main_narrator.exec(input) << std::endl;
        }
        // Bye message
        std::cout << "GoodBye!"<< std::endl;
    }

    void runner::setNarrator(rawr::narrator narrator) {
        main_narrator = narrator;
    }
    
    runner::~runner() {

    }

}

