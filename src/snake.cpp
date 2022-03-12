#include "snake.h"

Snake::Snake(glm::vec2 pos, glm::vec3 color) :
	m_pos(pos), m_color(color), m_speed(30.0f)
{
	for (int i = 0; i < m_numberOfSegments; i++)
	{		
		glm::vec2 segPos = glm::vec2(m_pos.x + m_segSize.x*(i+1), m_pos.y);
		m_segments.push_back(Block(State::LEFT, segPos, m_segSize, m_color));
	}
}

Snake::~Snake()
{

}

void Snake::growTail()
{
	
}

void Snake::move(float dt)
{
	float delatPos = m_speed * dt;
	
	if (!m_turns.empty())
	{
		for (std::deque<Direction>::iterator it = m_turns.begin(); it != m_turns.end(); it++)
		{
			for (int i = m_segments.size() - it->segmentsToProcess; i < m_segments.size(); i++)
			{
				
			}
			it->segmentsToProcess--;
		}
	}
}

void Snake::draw(Renderer& renderer, Shader& shader)
{
	for (std::vector<Block>::iterator it = m_segments.begin(); it != m_segments.end(); it++)
	{
		it->render(renderer, shader);
	}
}

void Snake::changeDir(State dir)
{ 
	m_turns.push_front({ (int)m_segments.size(), dir, m_pos });
}
