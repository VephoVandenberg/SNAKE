#define GLEW_STATIC

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>

const int width = 800;
const int height = 800;

int main(int argc, char** argv)
{
	if (!glfwInit())
	{	
		std::cout << "GLFW init error!" << std::endl;
	}

	GLFWwindow* window = glfwCreateWindow(width, height, "Snake", NULL, NULL);

	if (glewInit() != GLEW_OK)
	{
		std::cout << "GLEW init error!" << std::endl;
	}
	glfwMakeContextCurrent(window);

	while (!glfwWindowShouldClose(window))
	{
		glClearColor(0.0f, 1.0f, 0.0f, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window);
		glfwPollEvents();

	}
	return 0;
}