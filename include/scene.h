#ifndef __SCENE__
#define __SCENE__

#include <string>
#include "./rawr_object.h"

/*
    The Scene class will be a placeholder
    for all the information regarding a specific place
*/
    namespace rawr {
        class scene : public rawr_object {
            public:
                scene();
                scene(std::string name, std::string new_intro);
                std::string get_scene_intro();
                void set_scene_intro(const std::string new_intro);
                ~scene();
        };
    }

#endif