#ifndef ACT_BOOK_H
#define ACT_BOOK_H

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
            virtual std::string exec(const char *input, rawr::scene current_scene) = 0;
    }; 
}

#endif