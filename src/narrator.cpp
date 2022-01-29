#include "../include/narrator.h"
#include <iostream>
#include <stdio.h>

namespace rawr{
    narrator::narrator() {
        current_room = 0;
    }


    // Implements the action_book in the main loop. 
    std::string narrator::exec(std::vector<std::string> &input) {
        if(input.size() < 2) {
            // This message will be modifiable by the users in the future.
            return "Not an input I can recognize.";
        }

        if(this->book == nullptr) {
            perror("RAWR_ERROR: The narrator must have an instance of action_book assigned.");
            exit(2);
        }

        // TODO: Rememeber to add a sanity check to this clustefuck of a line
        std::string out = this->book->exec(input, scenes[current_room]);
        
        input.clear();
        return out;
    }

    void narrator::learnScene(rawr::scene &new_scene){
        scenes.push_back(new_scene);
    }

    void narrator::assignActionBook(rawr::action_book &book) {
        this->book = &book;
    }

    bool narrator::knowScenes(){
        return (scenes.size() > 0) ? true : false;
    }

    narrator::~narrator() {}
}