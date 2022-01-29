#ifndef __ACT_BOOK__
#define __ACT_BOOK__

#include <vector>
#include <string>
#include <unordered_map>
/*
    The bussiness book is the place where all the actions will be saved and that the
    narrator will execute.
*/

namespace rawr {
    
    class action_book {
        public:
            virtual std::string exec(std::vector<std::string> input) = 0;
    }; 
}

#endif