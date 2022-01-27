#include <iostream>
#include <unordered_map>
#include <string>
#include "../include/runner.h"
#include "../include/scene.h"
#include "../include/narrator.h"

struct book {
        using verb = std::string(std::string);
        std::unordered_map<std::string, verb*> page;
};

int main() {
    rawr::runner main_loop;
    rawr::narrator main_narrator;

    rawr::scene room_0("You wake up in the middle of the street. Your car is a wreck.");
    main_narrator.learnScene(room_0);

    auto ra = [&](std::string) {
        return "lalla";
    };
    std::cout << ra("lol") << std::endl;

    main_loop.setNarrator(main_narrator);
    main_loop.run();
    return 0;
}

std::string rara(std::string obj) {
    return "dala";
}