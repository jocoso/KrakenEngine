#ifndef __NARRATOR__
#define __NARRATOR__

#include <vector>
#include <string>
#include <stdbool.h>

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
            void exec(std::vector<std::string> &input);
            void learnScene(rawr::scene &scene);
            bool knowScenes();
            ~narrator();
        private:
            std::vector<rawr::scene> scenes;
    };
}


#endif