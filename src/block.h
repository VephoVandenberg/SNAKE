#pragma once

#include <glm/glm.hpp>

#include "renderer.h"
#include "shader.h"

class Block
{
public:
	Block(glm::vec2 pos, glm::vec2 size, glm::vec3 color = glm::vec3(0.0f));
	~Block();
	
	void render(glm::vec2 deltaPos, Renderer& renderer, Shader& shader);

private:
	glm::vec2 m_pos;
	glm::vec2 m_size;
	glm::vec3 m_color;
};