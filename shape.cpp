#include "shape.h"
#include <iostream>
#include <glad/glad.h>


// Vertex Shader source code
const char* vertexShaderSource = "#version 330 core\n"
	"layout (location = 0) in vec3 aPos;\n"
	"void main()\n"
	"{\n"
	"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
	"}\0";
//Fragment Shader source code
const char* fragmentShaderSource = "#version 330 core\n"
	"out vec4 FragColor;\n"
	"void main()\n"
	"{\n"
	"   FragColor = vec4(0.8f, 0.3f, 0.02f, 1.0f);\n"
	"}\n\0";

namespace krk {
	void Prop::init(GLuint *shaderProgram, GLuint *VAO, GLuint *VBO) const {
		//Load GLAD so it configures OpenGL
		gladLoadGL();
		// Specify the viewport of OpenGL in the Window
		// In this case the viewport goes from x = 0, y = 0, to x = 800, y = 800
		glViewport(0, 0, 800, 800);

		// Create Vertex Shader Object and get its reference
		GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
		// Attach Vertex Shader source to the Vertex Shader Object
		glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
		// Compile the Vertex Shader into machine code
		glCompileShader(vertexShader);

		// Create Fragment Shader Object and get its reference
		GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		// Attach Fragment Shader source to the Fragment Shader Object
		glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
		// Compile the Vertex Shader into machine code
		glCompileShader(fragmentShader);

		// Create Shader Program Object and get its reference
		*shaderProgram = glCreateProgram();
		// Attach the Vertex and Fragment Shaders to the Shader Program
		glAttachShader(*shaderProgram, vertexShader);
		glAttachShader(*shaderProgram, fragmentShader);
		// Wrap-up/Link all the shaders together into the Shader Program
		glLinkProgram(*shaderProgram);

		// Delete the now useless Vertex and Fragment Shader objects
		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);



		// Vertices coordinates
		GLfloat vertices[] =
		{
			-0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f, // Lower left corner
			0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f, // Lower right corner
			0.0f, 0.5f * float(sqrt(3)) * 2 / 3, 0.0f // Upper corner
		};

		// Generate the VAO and VBO with only 1 object each
		glGenVertexArrays(1, VAO);
		glGenBuffers(1, VBO);

		// Make the VAO the current Vertex Array Object by binding it
		glBindVertexArray(*VAO);

		// Bind the VBO specifying it's a GL_ARRAY_BUFFER
		glBindBuffer(GL_ARRAY_BUFFER, *VBO);
		// Introduce the vertices into the VBO
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		// Configure the Vertex Attribute so that OpenGL knows how to read the VBO
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
		// Enable the Vertex Attribute so that OpenGL knows to use it
		glEnableVertexAttribArray(0);

		// Bind both the VBO and VAO to 0 so that we don't accidentally modify the VAO and VBO we created
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);

	}

	void Prop::loop( GLenum shape, GLFWwindow *window, GLint start, GLint count, GLuint shaderProgram, GLuint VAO) const {
		// Specify the color of the background
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		// Clean the back buffer and assign the new color to it
		glClear(GL_COLOR_BUFFER_BIT);
		// Tell OpenGL which Shader Program we want to use
		glUseProgram(shaderProgram);
		// Bind the VAO so OpenGL knows to use it
		glBindVertexArray(VAO);
		// Draw the triangle using the GL_TRIANGLES primitive
		glDrawArrays(shape, start, count);
		glfwSwapBuffers(window);
	}

	
}