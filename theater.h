#ifndef KRK_THEATER
#define KRK_THEATER

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

/*
	The Theater class will take control of the main window of the game
	This class is the first to arrive and the last to leave.
*/
namespace krk {
	class Theater {
		public: 
			// Constructor
			Theater( int width, int height, const char *title );
			
			// Paint a window on the screen.
			void display();

			// Destructor
			~Theater();
		private:
			GLFWwindow* window;
			int width;
			int height;
	};
}

#endif // KRK_TEATHER