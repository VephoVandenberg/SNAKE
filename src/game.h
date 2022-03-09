#pragma once


class Game
{
public:
	Game(unsigned int width, unsigned int height);
	~Game();

	void init();
	void updateObjects(float dt);
	void renderObjects();

private:
	unsigned int m_width;
	unsigned int m_height;
};

