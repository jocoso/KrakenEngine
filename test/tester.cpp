#include <iostream>
#include "../include/runner.h"
#include "../include/scene.h"

int main() {
    rawr::runner main_loop;
    rawr::scene room_0("Booting... Visuals: FALSE. Running secondary options.");
    main_loop.run();
    return 0;
}