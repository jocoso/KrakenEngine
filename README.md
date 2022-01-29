# Rawr

Rawr is a free and open-source library for the development of text-adventure games and applications like videogames using C++. 

## Installation

<pre><code>git clone git@github.com:jocoso/RawrV2.git<code></pre>


## Help

Rawr should be pretty easy to use, clone or download the repository and add it to your project using the following includes.

<pre><code>
    #include "../include/scene.h"
    #include "../include/runner.h"
    #include "../include/narrator.h"
    #include "../include/general_book.h"

    int main() {

        // The runner class is the core of the game loop
        rawr::runner main_loop;

        // Creates an instance of the narrator class.
        // The narrator class takes care of feeding inputs, maps, actions
        // and all other important game pieces to the main loop.
        rawr::narrator main_narrator;

        // General book is a child of the class action_book. 
        // action_book as a virtual class is in charge of checking for inputs
        // and managing actions to these inputs by using information supplied by the narrator class.
        
        // Go to <strong>src/general_book.cpp</strong> to see an example
        rawr::general_book book;

        // Example of how we create a room.
        rawr::scene room_0("You wake up in the middle of the street. Your car is a wreck.");

        // The narrator will accept each room separatedly and save it in its map.
        // TODO: The narrator can accept a vector map instead.
        main_narrator.learnScene(room_0);

        // Assign the action_book child to the narrator. 
        // Then narrator class will then execute the actions and reactions listed in the child class.
        main_narrator.assignActionBook(book);

        // The main loop requires to be given a narrator
        main_loop.setNarrator(main_narrator);

        // Stars the main loop.
        main_loop.run();

        return 0;

    }

</code></pre>