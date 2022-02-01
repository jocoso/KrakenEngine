#ifndef __NARRATOR__
#define __NARRATOR__

#include <vector>
#include <string>
#include <stdbool.h>

#include "./scene.h"
#include "./action_book.h"


/*
    The narrator class works as a centerpiece in the program
    It manages the execution of input an all the logic regarding 
    scenes and props.
*/
namespace rawr {
    class narrator {
        public:
            narrator();
            narrator(std::string intro);
            bool check_narrator_integrity();
            void learnScene(rawr::scene &scene);
            void assignActionBook(rawr::action_book &book);
            std::string exec(const char* input);
            std::string describeScene();
            void setIntro(const std::string intro);
            std::string getIntro();
            bool knowScenes();
            ~narrator();
        private:
            std::vector<rawr::scene> scenes;
            rawr::action_book *book = nullptr;
            std::string game_intro;
            int current_room;
    };
}


#endif