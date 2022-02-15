#ifndef KRK_TRIANGLE_H
#define KRK_TRIANGLE_H

	#include "shape.h"
	#include <GLFW/glfw3.h>

	namespace krk {
		class Triangle : public Shape {
			public:
				void present(GLFWwindow* window) const override;

		};
	}

#endif