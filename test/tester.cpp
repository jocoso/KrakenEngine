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

    rawr::scene room_0("You wake up in the middle of the street. Your car is a wreck.");   
    main_narrator.learnScene(room_0);
    main_narrator.assignActionBook(book);

    main_loop.setNarrator(main_narrator);
    main_loop.run();
    return 0;
}