#ifndef __SCENE__
#define __SCENE__

#include <string>
/*
    The Scene class will be a placeholder
    for all the information regarding a specific place
*/
    namespace rawr {
        class scene {
            public:
                scene();
                scene(std::string new_intro);
                std::string getSceneIntro();
                void setSceneIntro(std::string new_intro);
                ~scene();    
            
            private:
                std::string scene_intro;
        };
    }

#endif