#ifndef __NARRATOR__
#define __NARRATOR__

#include <vector>
#include <string>

namespace rawr {
    class narrator {
        public:
            narrator();
            void exec(std::vector<std::string> &input);
            ~narrator();
    };
}


#endif