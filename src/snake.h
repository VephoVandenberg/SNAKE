#pragma once

#include <glm/glm.hpp>
#include <vector>
#include <queue>

#include "block.h"
#include "renderer.h"
#include "shader.h"

struct Direction
{
	int segmentsToProcess;
	State dir;
	glm::vec2 pos;
};

class Snake
{
public:

public:
	Snake(float boundaryX, float  boundarY, glm::vec2 pos, glm::vec3 color);
	~Snake();

	void growTail();
	void move(float dt);
	void draw(Renderer& renderer, Shader& shader);
	void changeDir(State dir);
	bool checkHit(Block& block);
	bool checkSelfBite();

private:
	std::vector<Block> m_segments;
	std::deque<Direction> m_turns;

	glm::vec2 m_pos;
	glm::vec3 m_color;

	const float m_boundaryX;
	const float m_boundaryY;
	const float m_speed = 100.0f;

	const int m_numberOfSegments = 8;
	const glm::vec2 m_segSize = glm::vec2(20.0f, 20.0f);
};