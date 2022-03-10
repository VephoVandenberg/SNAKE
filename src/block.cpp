#include "block.h"

Block::Block(glm::vec2 pos, glm::vec2 size, glm::vec3 color) :
	m_pos(pos), m_size(size), m_color(color)
{

}

Block::~Block()
{

}

void Block::render(glm::vec2 deltaPos, Renderer& renderer, Shader& shader)
{
	m_pos += deltaPos;
	renderer.draw(shader, m_size, m_pos, m_color);
}