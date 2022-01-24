#ifndef __NARRATOR__
#define __NARRATOR__

#include <vector>
#include <string>
#include <stdbool.h>
#include <unordered_map>

#include "../include/scene.h"


/*
    The narrator class works as a centerpiece in the program
    It manages the execution of input an all the logic regarding 
    scenes and props.
*/
namespace rawr {
    class narrator {
        public:
            narrator();
            void learnScene(rawr::scene &scene);
            std::string exec(std::vector<std::string> &input);
            std::string describeScene();
            bool knowScenes();
            ~narrator();
        private:
            std::vector<rawr::scene> scenes;

            int current_room;
    };
}


#endif