#ifndef SCENE_H
#define SCENE_H
    #include "./rawr_object.h"
    #include <string>

    namespace rawr {
        class scene : public rawr_object {
            public:
                scene( std::string scene_name, std::string scene_desc );
                std::string get_scene_intro();
        };
    }

#endif