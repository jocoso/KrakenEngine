#ifndef GEN_BOOK_H
#define GEN_BOOK_H
    #include "./action_book.h"

    namespace rawr {
        class general_book : public action_book {
            public:
                general_book();
                std::string exec( const char* input, scene current_scene );
                std::string describe( scene current_scene );
                ~general_book();
        };
    }

#endif