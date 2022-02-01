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
                scene(std::string name);
                scene(std::string name, std::string new_intro);
                std::string getSceneIntro();
                std::string getSceneName();
                void setSceneIntro(const std::string new_intro);
                void setSceneName(const std::string name);
                ~scene();    
            
            private:
                std::string scene_intro;
                std::string scene_name;
        };
    }

#endif