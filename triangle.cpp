#include "triangle.h"

namespace krk {
	void Shape::present(GLFWwindow *window) const {
		GLuint shaderProgram, VBO, VAO;

		this->init(&shaderProgram, &VAO, &VBO);
		this->loop(GL_TRIANGLES, window, 0, 3, shaderProgram, VAO);

		
	}


}