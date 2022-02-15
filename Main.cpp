#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>


/*
*  Kraken Teather is a the main window class
*/

class KrakenTeather {
	const int WIDTH= 0;
	const int HEIGHT = 1;

	typedef enum Color { RED = 0, GREEN = 1, BLUE = 2, TRANSPARENCY = 3 };

	public:
	KrakenTeather(int w_win, int h_win, const char* name_win) {
		glfwInit();
		
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		main_window = glfwCreateWindow(w_win, h_win, name_win, NULL, NULL);
		
		v_size[WIDTH] = w_win;
		v_size[HEIGHT] = h_win;

		if (main_window == NULL) {
			std::cout << "Failed to create a Kraken Window" << std::endl;
			glfwTerminate();
			exit(-1);
		}

		glfwMakeContextCurrent(main_window);
		gladLoadGL();

		glViewport(0, 0, v_size[WIDTH], v_size[HEIGHT]);
		glClearColor(window_color[RED], window_color[GREEN], window_color[BLUE], window_color[TRANSPARENCY]);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(main_window);

	}

	void changeBackgroundColor(float red, float green, float blue, float transparency = 1.0f) {
		glViewport(0, 0, v_size[WIDTH], v_size[HEIGHT]);
		glClearColor(red, green, blue, transparency);

		window_color[RED] = red;
		window_color[GREEN] = green;
		window_color[BLUE] = blue;
		window_color[TRANSPARENCY] = transparency;

		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(main_window);
	}


	void openCurtains() {
		while (!glfwWindowShouldClose(main_window)) {
			glfwPollEvents();
		}
	}

	~KrakenTeather() {
		if (main_window != NULL) glfwDestroyWindow(main_window);
		glfwTerminate();
	}



	private:
		GLFWwindow *main_window;
		float window_color[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
		int v_size[2];

};


int main() {
	KrakenTeather kt(800, 800, "Kraken Prototype v.1");
	kt.changeBackgroundColor(0.3f, 0.3f, 1.0f, 0.3f);
	kt.openCurtains();

	return 0;
}