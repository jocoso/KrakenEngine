#include "kraken_theater.h"


	/// <summary>
	///		Tool to display children of Shape
	/// </summary>
	/// <param name="sh">An instance of children of Shape class to display.</param>
	void displayShape(Shape* sh) {
		sh->display();
	}

	/// <summary>
	///		Tool to clean children of Shape
	/// </summary>
	/// <param name="sh">An instance of children of Shape class to clean.</param>
	void cleanShape(Shape* sh) {
		sh->clean();
	}

	/// <summary>
	/// Creates a window. This function creates a window
	/// that will contain the main loop of the game.
	/// and control.
	/// </summary>
	/// <param name="w_win">Desired width of the window</param>
	/// <param name="h_win">Desired height of the window</param>
	/// <param name="name_win">Text that will appear on the tilebar</param>
	KrakenTheater::KrakenTheater(GLuint w_win, GLuint h_win, const GLchar* name_win) {
		// Initiating GLFW so we can use their fuctions
		glfwInit();

		// Prepping GLFW. Letting the window kno the version we are using is 3.0
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		// Creates a window
		main_window = glfwCreateWindow(w_win, h_win, name_win, NULL, NULL);

		// Saves the width and height of the window so we can use it later
		v_size[WIDTH] = w_win;
		v_size[HEIGHT] = h_win;

		// If the window couldn't be instantiated for any particular reason,
		// return an error message and terminate the program
		if (main_window == NULL) {
			std::cout << "Failed to create a Kraken Window" << std::endl;
			glfwTerminate();
			exit(-1);
		}

		// Make this window the main focus source
		glfwMakeContextCurrent(main_window);


		gladLoadGL();

	}

	/// <summary>
	/// Change the basic colors of the screen.
	/// </summary>
	/// <param name="red"> A floating number between 0 and 1 that will correspond to red in the RGB Color system </param>
	/// <param name="green"> A floating number between 0 and 1 that will correspond to green in the RGB Color system </param>
	/// <param name="blue"> A floating number between 0 and 1 that will correspond to blue in the RGB Color system </param>
	/// <param name="transparency">A floating number between 0 and 1 that will correspond to transparency. Zero being totally transparent and one being totally opaque. </param>
	void KrakenTheater::changeCurtainsColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat transparency) {
		glClearColor(red, green, blue, transparency);
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(main_window);


		window_color[RED] = red;
		window_color[GREEN] = green;
		window_color[BLUE] = blue;
		window_color[TRANSPARENCY] = transparency;
	}

	/// <summary>
	/// Starts the window's main loop. All the window's functionalities,
	/// characters, settings etc... Should be created and pass down to the window
	/// before this function is called.
	/// </summary>
	void KrakenTheater::openCurtains(Shape* t) {
		while (!glfwWindowShouldClose(main_window)) {
			glClearColor(window_color[RED], window_color[GREEN], window_color[BLUE], window_color[TRANSPARENCY]);
			glClear(GL_COLOR_BUFFER_BIT);

			displayShape(t);
			glfwSwapBuffers(main_window);

			glfwPollEvents();
		}

		cleanShape(t);
	}

	KrakenTheater::~KrakenTheater() {
		if (main_window != NULL) glfwDestroyWindow(main_window);
		glfwTerminate();
	}
