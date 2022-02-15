#ifndef MY_NARRATOR_H
#define MY_NARRATOR_H

	#include "narrator.h"
	
	const char* vertexShaderSource = "#version 330 core\n"
	"layout (location = 0) in vec3 aPos;\n"
	"void main() {\n"
	"	gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
	"}\0";

	const char* fragmentShaderSource = "#version 330 core\n"
		"out vec4 FragColor;\n"
		"void main() {\n"
		"	FragColor = vec4(0.8f, 0.3f, 0.02f, 1.0f);\n"
		"}\n\0";

	
	class MyNarrator : public krk::Narrator {
		public:
			MyNarrator();
			void narrate() override;
			~MyNarrator();
	};

#endif

