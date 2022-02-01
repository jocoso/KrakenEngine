#ifndef SCENE_H
#define SCENE_H
    #include <string>
    #include <vector>
    #include "./prop.h"
    
    namespace rawr {
        class scene : public prop {
            public:
                scene( std::string scene_name, std::string scene_desc );
                std::string get_scene_intro();
                void add_item_list( std::vector<prop> item_list );
                void add_item( prop object );
            
            private:
                std::vector<prop> item_list;
        };
    }

#endif