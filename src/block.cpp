#include "block.h"

Block::Block(State state, glm::vec2 pos, glm::vec2 size, glm::vec3 color) :
	m_state(state), m_pos(pos), m_size(size), m_color(color)
{

}

Block::~Block()
{

}

void Block::draw(Renderer& renderer, Shader& shader)
{
	renderer.draw(shader, m_size, m_pos, m_color);
}
