#ifndef __GEN_BOOK__
#define __GEN_BOOK__
    #include "./action_book.h"

    namespace rawr {
        class general_book : public action_book {
            public:
                general_book();
                std::string exec(std::vector<std::string> input);
                std::string describe(std::string obj);
                ~general_book();
        };
    }

#endif