#define GLEW_STATIC

#include <GL/glew.h>

#include <iostream>

#include "src/game.h"

const int width = 800;
const int height = 800;

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mode);

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

	float previousFrame = 0.0f;
	float dt = 0.0f;

	while (!glfwWindowShouldClose(window))
	{
		float currentFrame = glfwGetTime();
		dt = currentFrame - previousFrame;
		previousFrame = currentFrame;

		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		game.updateObjects(dt);
		game.renderObjects();

		glfwSwapBuffers(window);
		glfwPollEvents();

	}
	return 0;
}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	if (key >= 0 && key <= 1024)
	{
		if (action == GLFW_PRESS)
		{
			game.keys[key] = true;
		}
		else if (action == GLFW_RELEASE)
		{
			game.keys[key] = false;
		}
	}
}