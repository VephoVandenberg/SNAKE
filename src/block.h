#pragma once

#include <glm/glm.hpp>

#include "renderer.h"
#include "shader.h"

enum class State
{
	IDLE,
	UP,
	DOWN,
	LEFT,
	RIGHT
};

class Block
{
public:
	Block(State state, glm::vec2 pos, glm::vec2 size, glm::vec3 color = glm::vec3(0.0f));
	~Block();
	
	void render(Renderer& renderer, Shader& shader);
private:
	glm::vec2 m_pos;
	glm::vec2 m_size;
	glm::vec3 m_color;
	
	State m_state;

	friend class Snake;

	
};