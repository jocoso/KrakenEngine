#ifndef ACT_BOOK_H
#define ACT_BOOK_H

#include <vector>
#include <cstring>
#include <stdbool.h>

#include "./scene.h"
/*
    The bussiness book is the place where all the actions will be saved and that the
    narrator will execute.
*/

using std::string;

namespace rawr {
    class action_book {
        public:
            virtual string exec(const char *input, scene current_scene) = 0;
            bool compare(const char *string1, const char *string2);
    }; 
}

#endif