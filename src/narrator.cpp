#include "../include/narrator.h"
#include <iostream>
#include <stdio.h>

namespace rawr{
    narrator::narrator() {
        current_room = 0;
        game_intro = "An intro was not specified\n\n";
    }

    narrator::narrator(const std::string intro) {
        current_room = 0;
        game_intro = intro + "\n\n";
    }

    bool narrator::check_narrator_integrity() {
        if( this->book == nullptr || 
            !this->knowScenes()   ||
            this->main == nullptr
          ) return false;
        return true;
    }

    // Implements the action_book in the main loop. 
    std::string narrator::exec( const char* input ) {
        // TODO: Rememeber to add a sanity check to this clustefuck of a line
        std::string out = this->book->exec( input, scenes[ current_room ], *main ) + "\n\n";
        
        return out;
    }

    void narrator::learnScene( scene &new_scene ){
        scenes.push_back( new_scene );
    }

    void narrator::meet_main_character( character &main ) {
        this->main = &main;
    }

    void narrator::assignActionBook( action_book &book ) {
        this->book = &book;
    }

    void narrator::setIntro( const std::string intro ) {
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