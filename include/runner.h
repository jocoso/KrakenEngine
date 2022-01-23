#ifndef _RUNNER_
#define _RUNNER_

#include "../include/narrator.h"

namespace rawr {
    class runner {
        public:
            runner();
            void run();
            ~runner();
        private:
            rawr::narrator main_narrator;
    };
}
#endif


