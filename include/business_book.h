#ifndef __BUSI_BOOK__
#define __BUSI_BOOK__

#include <string>
#include <unordered_map>
/*
    The bussiness book is the place where all the actions will be saved and that the
    narrator will execute.
*/

namespace rawr {
    struct verb {
        virtual std::string run(std::string obj) = 0;
    };

    struct describe : public verb {
        virtual std::string run(std::string obj) override {
            return "Description done";
        }
    } describe;

    class business_book {
        public:
            business_book();
            virtual std::string search(std::string name, std::string object)=0;
            ~business_book();
        private:
            std::unordered_map<std::string, const verb &> book = {
                { "describe", describe }
            };
    }; 
}

#endif