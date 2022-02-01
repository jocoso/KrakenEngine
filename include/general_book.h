#ifndef __GEN_BOOK__
#define __GEN_BOOK__
    #include "./action_book.h"

    namespace rawr {
        class general_book : public action_book {
            public:
                general_book();
                std::string exec(const char* input, rawr::scene current_scene);
                std::string describe(rawr::scene current_scene);
                ~general_book();
        };
    }

#endif