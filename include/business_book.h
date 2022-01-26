#ifndef __BUSI_BOOK__
#define __BUSI_BOOK__

#include <string>
#include <unordered_map>
/*
    The bussiness book is the place where all the actions will be saved and that the
    narrator will execute.
*/

namespace rawr {
    
    class business_book {
        public:
            business_book();
            virtual std::string search(std::string name, std::string object)=0;
            std::string describe(std::string object);
            void temp();
            ~business_book();

    }; 
}

#endif