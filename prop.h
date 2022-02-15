#ifndef KRK_DRAWABLE_H
#define KRK_DRAWABLE_H
#include <GLFW/glfw3.h>

	namespace krk {
		class Prop {
		public:
			virtual void init(GLuint *shaderProgram, GLuint *VAO, GLuint *VBO) const;
			virtual void loop(GLenum shape, GLFWwindow* window, GLint start, GLint count, GLuint shaderProgram, GLuint VAO) const;
		};
	}
#endif