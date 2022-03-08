#include <iostream>
#include <algorithm>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "triangle.h"
#include "kraken_theater.h"

void printArray(const float* array, int n) {
	for (int i = 0; i < n; i++) {
		std::cout << array[i] << std::endl;
	}
}


int main() {
	KrakenTheater kt(800, 800, "Kraken Prototype v.1");

	kt.changeCurtainsColor(0.07f, 0.13f, 0.17f);

	float vertices[] = {
		-0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f,      // Lower Left
		0.5, -0.5f * float(sqrt(3)) / 3, 0.0f,        // Lower Right
		0.0f, 0.5f * float(sqrt(3)) * 2 / 3, 0.0f,    // Upper Corner
		-0.5f / 2, 0.5f * float(sqrt(3)) / 6, 0.0f,   // Inner Left    
		0.5f / 2, 0.5f * float(sqrt(3)) / 6, 0.0f,   // Inner right
		0.0f, -0.5f * float(sqrt(3)) / 3, 0.0f         // Inner down
	};

	unsigned int indices[] = {
		0, 3, 5,	// Lower left
		3, 2, 4,	// Lower right
		5, 4, 1		// Upper triangle
	};

	Triangle t(vertices, indices);
	Shape* s = &t;

	kt.openCurtains(s);
	

	return 0;
}