#include "food.h"

Food::Food(State state, glm::vec2 pos, glm::vec2 size, glm::vec3 color) :
	Block(state, pos, size, color)
{

}

Food::~Food()
{

}

void Food::move(glm::vec2 newPos)
{
	m_pos = newPos;
}
