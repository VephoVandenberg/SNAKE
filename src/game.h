#pragma once

#include "renderer.h"
#include "block.h"

class Game
{
public:
	Game(unsigned int width, unsigned int height);
	~Game();

	void init();
	void updateObjects(float dt);
	void renderObjects();

private:
	Renderer *m_renderer;
	Block* m_block;
	unsigned int m_width;
	unsigned int m_height;
};

