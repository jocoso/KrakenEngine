#include "prop.h"
#include <GLFW/glfw3.h>

namespace krk {
	class Shape : public Prop {
		public: 
			virtual void present(GLFWwindow* window) const;
			void init(GLuint* shaderProgram, GLuint* VAO, GLuint* VBO) const override;
			void loop(GLenum shape, GLFWwindow* window, GLint start, GLint count, GLuint shaderProgram, GLuint VAO) const override;

	};
}

