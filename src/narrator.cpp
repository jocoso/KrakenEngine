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

        std::string out = this->book->exec(input);
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

    std::string narrator::describeScene() {
        if(this->knowScenes() == true) {
            return scenes[current_room].getSceneIntro();
        }

        std::string a = "I'm sorry. I don't know.";

        return a;
    }

    narrator::~narrator() {}
}