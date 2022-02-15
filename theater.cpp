#include "theater.h"



namespace krk {
	Theater::Theater( int width, int height, const char* title ) {
		// Initiate GLFW
		glfwInit();

		// TODO: Make a Size class that will take an x and y. 
		// Replace width and height with it.

		// Save Width and height information
		this->width = width;
		this->height = height;

		// Hint the window
		// ====================================
		// We are using version 3 of GLFW only
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		// Only recent updates of GLFW
		glfwWindowHint( GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE );
		// ====================================

		// Creating the window
		this->window = glfwCreateWindow( width, height, title, NULL, NULL );

		// Sanity Check (window couldn't be initialized)
		// ====================================
		if( window == NULL ) {
			std::cout << "ERROR_0: Couldn't create a new Window. If the error persists reinstall the library." << std::endl;
			glfwTerminate();
			exit( -1 );
		}
		// ====================================
	}

	void Theater::display( Shape &shape ) {
		// Open Window
		glfwMakeContextCurrent(window);
		gladLoadGL();

		// As long as the window is open execute the window's events
		while (!glfwWindowShouldClose(window)) {
			shape.present(window);
			glfwPollEvents();
		}

		
	}

	
	Theater::~Theater() {

		// Destroy the Window (self explanatory)
		// Sanity Check
		if ( !( window == NULL ) ) {
			glfwDestroyWindow( window );
		}

		glfwTerminate();
	}
}
