#define GLEW_STATIC

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>

#include "src/game.h"

const int width = 800;
const int height = 800;

Game game(width, height);

int main(int argc, char** argv)
{
	if (!glfwInit())
	{	
		std::cout << "GLFW init error!" << std::endl;
	}

	GLFWwindow* window = glfwCreateWindow(width, height, "Snake", NULL, NULL);
	glfwMakeContextCurrent(window);

	if (glewInit() != GLEW_OK)
	{
		std::cout << "GLEW init error!" << std::endl;
	}
	

	game.init();

	while (!glfwWindowShouldClose(window))
	{
		glClearColor(0.0f, 1.0f, 0.0f, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		game.renderObjects();

		glfwSwapBuffers(window);
		glfwPollEvents();

	}
	return 0;
}