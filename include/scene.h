#ifndef SCENE_H
#define SCENE_H
    #include <string>
    #include <vector>
    #include "./rawr_object.h"
    
    namespace rawr {
        class scene : public rawr_object {
            public:
                scene( std::string scene_name, std::string scene_desc );
                std::string get_scene_intro();
                void add_item_list( std::vector<rawr_object> item_list );
                void add_item( rawr_object object );
            
            private:
                std::vector<rawr_object> item_list;
        };
    }

#endif