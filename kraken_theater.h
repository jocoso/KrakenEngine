#ifndef KRAKEN_THEATER
#define KRAKEN_THEATER

	#include <iostream>
	#include "shape.h"

	class KrakenTheater {

		const int WIDTH = 0;
		const int HEIGHT = 1;

		typedef enum Color { RED = 0, GREEN = 1, BLUE = 2, TRANSPARENCY = 3 };

	public:
		/// <summary>
		/// Creates a window. This function creates a window
		/// that will contain the main loop of the game.
		/// and control.
		/// </summary>
		/// <param name="w_win">Desired width of the window</param>
		/// <param name="h_win">Desired height of the window</param>
		/// <param name="name_win">Text that will appear on the tilebar</param>
		KrakenTheater(GLuint w_win, GLuint h_win, const GLchar* name_win);

		/// <summary>
		/// Change the basic colors of the screen.
		/// </summary>
		/// <param name="red"> A floating number between 0 and 1 that will correspond to red in the RGB Color system </param>
		/// <param name="green"> A floating number between 0 and 1 that will correspond to green in the RGB Color system </param>
		/// <param name="blue"> A floating number between 0 and 1 that will correspond to blue in the RGB Color system </param>
		/// <param name="transparency">A floating number between 0 and 1 that will correspond to transparency. Zero being totally transparent and one being totally opaque. </param>
		void changeCurtainsColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat transparency = 1.0f);

		/// <summary>
		/// Starts the window's main loop. All the window's functionalities,
		/// characters, settings etc... Should be created and pass down to the window
		/// before this function is called.
		/// </summary>
		void openCurtains(Shape* t);
		~KrakenTheater();

	private:
		GLFWwindow* main_window;
		float window_color[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
		int v_size[2];

	};

#endif