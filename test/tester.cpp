#include <iostream>
#include "../include/runner.h"
#include "../include/scene.h"
#include "../include/narrator.h"

int main() {
    rawr::runner main_loop;
    rawr::narrator main_narrator;

    rawr::scene room_0("Booting... Visuals: FALSE. Running secondary options.");
    
    main_loop.setNarrator(main_narrator);
    main_loop.run();
    return 0;
}