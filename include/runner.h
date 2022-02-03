#ifndef RUNNER_H
#define RUNNER_H

#include "../include/narrator.h"

namespace rawr {
    class runner {
        public:
            runner();
            void run();
            void setNarrator( narrator narrator );
            ~runner();
        private:
            narrator main_narrator;
    };
}
#endif


