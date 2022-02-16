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
		-0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f,
		0.5, -0.5f * float(sqrt(3)) / 3, 0.0f,
		0.0f, 0.5f * float(sqrt(3)) * 2 / 3, 0.0f
	};

	Triangle t(vertices);
	Shape* s = &t;

	kt.openCurtains(s);
	

	return 0;
}