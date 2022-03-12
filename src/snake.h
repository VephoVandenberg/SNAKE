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
	Snake(glm::vec2 pos, glm::vec3 color);
	~Snake();

	void growTail();
	void move(float dt);
	void draw(Renderer& renderer, Shader& shader);
	void changeDir(State dir);

private:
	std::vector<Block> m_segments;
	std::deque<Direction> m_turns;

	glm::vec2 m_pos;
	glm::vec3 m_color;
	
	float m_speed;

	const int m_numberOfSegments = 5;
	const glm::vec2 m_segSize = glm::vec2(20.0f, 20.0f);
};