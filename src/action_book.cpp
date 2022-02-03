#include "../include/action_book.h"

namespace rawr {
    bool action_book::compare(const char* string1, const char* string2) {
        return (strcmp(string1, string2) == 0);
    }
}