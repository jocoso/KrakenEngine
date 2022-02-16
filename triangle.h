#ifndef TRIANGLE_H
#define TRIANGLE_H
	#include "shape.h"

	class Triangle : public Shape {
	public:
		Triangle(const float vertices[9]) : Shape(vertices) {};
		void display() override;
	};

#endif
