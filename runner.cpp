#include "./runner.h"
#include <stdbool.h>
#include <iostream>
#include <sstream>
#include <string.h>
#include <string>
#include <vector>



namespace rawr {

    runner::runner() {}
            
    
    void runner::run() {
        
        std::vector<std::string> input;
        char *bye = "quit";

        while(true) {
            std::string raw_input;
            
            std::cout << ">";

            // Get user input
            std::getline(std::cin, raw_input);
            
            // If input 1 is quit break

            if(strcmp(raw_input.c_str(), bye) == 0) break;

            // Separate input into pieces
            std::stringstream ss(raw_input);

            while(ss.good()) {
                std::string a;
                std::getline(ss, a, ' ');
                input.push_back(a);
            }


            // cout verb piece one
            std::cout << "Verb: " << input[0] << std::endl;

            // cout object piece two
            std::cout << "Object: " << input[1] << std::endl;
        }
        // Bye message
        std::cout << "GoodBye!"<< std::endl;
    }

    
    runner::~runner() {
        std::cout << "lol" << std::endl;
    }

}

