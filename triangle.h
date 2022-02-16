#ifndef TRIANGLE_H
#define TRIANGLE_H
	#include "shape.h"

	class Triangle : public Shape {
	public:
		Triangle(const float vertices[18], const unsigned int indices[9]) : Shape(vertices, indices) {};
		void display() override;
	};

#endif
