#include "../include/narrator.h"
#include <iostream>
#include <stdio.h>

namespace rawr{
    narrator::narrator() {
        current_room = 0;
        game_intro = "An intro was not specified";
    }

    narrator::narrator(const std::string intro) {
        game_intro = intro;
    }

    // Implements the action_book in the main loop. 
    std::string narrator::exec(std::vector<std::string> &input) {
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

    void narrator::setIntro(const std::string intro) {
        game_intro = intro;
    }

    std::string narrator::getIntro() {
        return game_intro;
    }   

    bool narrator::knowScenes(){
        return (scenes.size() > 0) ? true : false;
    }

    narrator::~narrator() {}
}