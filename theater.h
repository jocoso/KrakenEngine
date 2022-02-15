#ifndef KRK_THEATER
#define KRK_THEATER

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>


#include "shape.h"

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
			void display( Shape &shape );

			// Destructor
			~Theater();
		private:
			GLFWwindow* window;
			int width;
			int height;
			const char* vertexShaderSource = "#version 330 core\n"
				"layout (location = 0) in vec3 aPos;\n"
				"void main() {\n"
				"	gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
				"}\0";

			const char* fragmentShaderSource = "#version 330 core\n"
				"out vec4 FragColor;\n"
				"void main() { \n"
				"	FragColor = vec4(0.8f, 0.3f, 0.02f, 1.0f);\n"
				"}\n\0";
	};
}

#endif // KRK_TEATHER