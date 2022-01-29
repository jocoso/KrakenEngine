#ifndef __ACT_BOOK__
#define __ACT_BOOK__

#include <vector>
#include <string>
#include <unordered_map>

#include "./scene.h"
/*
    The bussiness book is the place where all the actions will be saved and that the
    narrator will execute.
*/

namespace rawr {
    
    class action_book {
        public:
            virtual std::string exec(std::vector<std::string> input, rawr::scene current_scene) = 0;
    }; 
}

#endif