#ifndef RUNNER_H
#define RUNNER_H

    #include <wx/wxprec.h>

    /*
        Opens a window and instantiates all the parts of the 
        graphic Interface. Serves as a hub where the distinct
        information of each window can be shared and processed.
    */

    namespace krk {
        class runner {
            public:
                runner();
                void run();
                ~runner();
        };
    }
#endif


