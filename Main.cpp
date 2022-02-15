#include <iostream>
#include <algorithm>
#include <glad/glad.h>
#include <GLFW/glfw3.h>


const char* vertexShaderSource = "#version 330 core\n"
"layout (location=0) in vec3 aPos;\n"
"void main() {\n"
"	gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";

const char* fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;"
"void main() {\n"
"	FragColor = vec4(0.7f, 0.3f, 0.02f, 1.0f);\n"
"}\n\0";

GLuint createShaderProgram(unsigned int vertex, unsigned int fragment) {
	GLuint shaderProgram = glCreateProgram();

	glAttachShader(shaderProgram, vertex);
	glAttachShader(shaderProgram, fragment);

	glLinkProgram(shaderProgram);

	return shaderProgram;
}

void printArray(const float* array, int n) {
	for (int i = 0; i < n; i++) {
		std::cout << array[i] << std::endl;
	}
}


class Prop {
	public:
		virtual void display() = 0;
};

class Shape : public Prop {
	public:
		Shape(float vertice[]) {
			
			for (int i = 0; i < 9; i++) vertices[i] = vertice[i];

			GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
			glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
			glCompileShader(vertexShader);


			GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
			glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
			glCompileShader(fragmentShader);

			shape_shader_program = createShaderProgram(vertexShader, fragmentShader);

			glDeleteShader(vertexShader);
			glDeleteShader(fragmentShader);

			glGenVertexArrays(1, &VAO);
			glGenBuffers(1, &VBO);

			glBindVertexArray(VAO);

			glBindBuffer(GL_ARRAY_BUFFER, VBO);
			glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
			glEnableVertexAttribArray(0);

			glBindBuffer(GL_ARRAY_BUFFER, 0);
			glBindVertexArray(0);
		}

		/*virtual void display() = 0;*/
		void display() override {
			// Clean the back buffer and assign the new color to it
			glClear(GL_COLOR_BUFFER_BIT);
			// Tell OpenGL which Shader Program we want to use
			glUseProgram(shape_shader_program);
			// Bind the VAO so OpenGL knows to use it
			glBindVertexArray(VAO);
			// Draw the triangle using the GL_TRIANGLES primitive
			glDrawArrays(GL_TRIANGLES, 0, 3);
		}

		void clean() {
			glDeleteVertexArrays(1, &VAO);
			glDeleteBuffers(1, &VBO);
			glDeleteProgram(shape_shader_program);
		}

	protected:
		GLuint shape_shader_program;
		GLuint VAO, VBO;
		float vertices[9];

};

//class Triangle : public Shape {
//	public:
//		Triangle(const void* vertices) : Shape(vertices) {}
//
//	
//};


void displayShape(Shape *sh) {
	sh->display();
}

void cleanShape(Shape* sh) {
	sh->clean();
}

class KrakenTeather {
	
	const int WIDTH= 0;
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
	KrakenTeather(GLuint w_win, GLuint h_win, const GLchar* name_win) {
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
	void changeCurtainsColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat transparency = 1.0f) {
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
	void openCurtains(Shape *t) {
		while (!glfwWindowShouldClose(main_window)) {
			glClearColor(window_color[RED], window_color[GREEN], window_color[BLUE], window_color[TRANSPARENCY]);
			glClear(GL_COLOR_BUFFER_BIT);

			displayShape(t);
			glfwSwapBuffers(main_window);

			glfwPollEvents();
		}

		cleanShape(t);
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

	kt.changeCurtainsColor(0.07f, 0.13f, 0.17f);

	float vertices[] = {
		-0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f,
		0.5, -0.5f * float(sqrt(3)) / 3, 0.0f,
		0.0f, 0.5f * float(sqrt(3)) * 2 / 3, 0.0f
	};

	/*Triangle t(vertices);*/
	Shape s(vertices);

	kt.openCurtains(&s);
	

	return 0;
}