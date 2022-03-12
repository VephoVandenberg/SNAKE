#pragma once

#include <GLFW/glfw3.h>

#include "renderer.h"
#include "block.h"
#include "snake.h"

class Game
{
public:
	bool keys[1024];

public:
	Game(unsigned int width, unsigned int height);
	~Game();

	void init();
	void updateObjects(float dt);
	void renderObjects();
	void processInput();

private:
	Renderer* m_renderer;
	Snake* m_snake;

	unsigned int m_width;
	unsigned int m_height;

};

