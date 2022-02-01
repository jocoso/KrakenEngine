#include <iostream>
#include <unordered_map>
#include <string>

#include "../include/scene.h"
#include "../include/runner.h"
#include "../include/narrator.h"
#include "../include/general_book.h"


int main() {
    rawr::runner main_loop;
    rawr::narrator main_narrator;
    rawr::general_book book;

    main_narrator.setIntro("You woke up inside a cloud of black.\
    The smoke burning the soft tissue of your lungs. You coughed,\
    a ping of pain followed your desperated attempts to breathe.");

    rawr::scene room_0("Crash Scene", "You wake up in the middle of the street. Your car is a wreck.");   
    main_narrator.learnScene(room_0);
    main_narrator.assignActionBook(book);

    main_loop.setNarrator(main_narrator);
    main_loop.run();
    return 0;
}