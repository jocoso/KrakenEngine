#ifndef COMMON_H
#define COMMON_H

	extern const char* vertexShaderSource = "#version 330 core\n"
	"layout (location=0) in vec3 aPos;\n"
	"void main() {\n"
	"	gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
	"}\0";

	extern const char* fragmentShaderSource = "#version 330 core\n"
	"out vec4 FragColor;"
	"void main() {\n"
	"	FragColor = vec4(0.7f, 0.3f, 0.02f, 1.0f);\n"
	"}\n\0";

	extern GLuint createShaderProgram(unsigned int vertex, unsigned int fragment) {
		GLuint shaderProgram = glCreateProgram();

		glAttachShader(shaderProgram, vertex);
		glAttachShader(shaderProgram, fragment);

		glLinkProgram(shaderProgram);

		return shaderProgram;
	}

#endif