#ifndef ACT_BOOK_H
#define ACT_BOOK_H

#include <vector>
#include <string>

#include "./scene.h"
/*
    The bussiness book is the place where all the actions will be saved and that the
    narrator will execute.
*/

namespace rawr {
    typedef struct line {
        std::string prompt;
        std::vector<std::string> options;
        void *action;
    } line;

    class action_book {
        public:
            virtual std::string exec(const char *input, rawr::scene current_scene) = 0;
            virtual void init() = 0;
        protected:
            std::vector<line> script;
    }; 
}

#endif