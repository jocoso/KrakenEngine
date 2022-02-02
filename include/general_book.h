#ifndef GEN_BOOK_H
#define GEN_BOOK_H
    #include "./action_book.h"

    namespace rawr {
        class general_book : public action_book {
            public:
                general_book();
                std::string exec(const char* input, rawr::scene current_scene);
                void init();
                std::string print_options(std::vector<std::string> list);
                std::string describe(rawr::scene current_scene);
                ~general_book();
        };
    }

#endif