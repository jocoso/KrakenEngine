#ifndef SHAPE_H
#define SHAPE_H
	#include <glad/glad.h>
	#include <GLFW/glfw3.h>
	#include "prop.h"
	
	class Shape : public Prop {
		public:
			/// <summary>
			///		Draw a shape on the screen.
			/// </summary>
			/// <param name="vertice">Plane points as a float array.</param>
			
			Shape(const float vertice[]);
			virtual void display() = 0;

			/// <summary>
			///		Delete all the unusable data in the shape class.
			/// </summary>
			void clean();

		protected:
			GLuint shape_shader_program;
			GLuint VAO, VBO;
			float vertices[9];
	};

#endif
