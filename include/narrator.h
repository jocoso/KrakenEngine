#ifndef NARRATOR_H
#define NARRATOR_H

#include <vector>
#include <string>
#include <stdbool.h>

#include "./scene.h"
#include "./action_book.h"
#include "./character.h"


/*
    The narrator class works as a centerpiece in the program
    It manages the execution of input an all the logic regarding 
    scenes and props.
*/
namespace rawr {
    class narrator {
        public:
            narrator();
            narrator( std::string intro );
            bool check_narrator_integrity();
            void learnScene( scene &scene );
            void meet_main_character( character &main );
            void assignActionBook( action_book &book );
            std::string exec( const char* input );
            std::string describeScene();
            void setIntro( const std::string intro );
            std::string getIntro();
            bool knowScenes();
            ~narrator();
        private:
            std::vector<rawr::scene> scenes;
            action_book *book = nullptr;
            character *main = nullptr;
            std::string game_intro;
            int current_room;
    };
}


#endif