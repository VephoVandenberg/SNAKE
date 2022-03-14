#pragma once

#include <GLFW/glfw3.h>

#include "renderer.h"
#include "block.h"
#include "snake.h"
#include "food.h"

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
	bool gameShouldOver();
private:
	Renderer* m_renderer;
	Snake* m_snake;
	Food* m_food;

	unsigned int m_width;
	unsigned int m_height;

	int m_foodPosCounter;
};

