#include "snake.h"

Snake::Snake(float boundaryX, float boundaryY, glm::vec2 pos, glm::vec3 color) :
	m_boundaryX(boundaryX), m_boundaryY(boundaryY), m_pos(pos), m_color(color)
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
	
	for (int i = 0; i < m_segments.size(); i++)
	{
		switch (m_segments[i].m_state)
		{
			case State::UP:
			{
				m_segments[i].m_pos.y -= delatPos;
				if (m_segments[i].m_pos.y + m_segSize.y < 0.0f)
				{
					m_segments[i].m_pos.y = m_boundaryY;
				}
			}break;

			case State::DOWN:
			{
				m_segments[i].m_pos.y += delatPos;
				if (m_segments[i].m_pos.y > m_boundaryY)
				{
					m_segments[i].m_pos.y = 0.0f - m_segSize.y;
				}
			}break;

			case State::LEFT:
			{
				m_segments[i].m_pos.x -= delatPos;
				if (m_segments[i].m_pos.x + m_segSize.x < 0.0f)
				{
					m_segments[i].m_pos.x = m_boundaryX;
				}
			}break;

			case State::RIGHT:
			{
				m_segments[i].m_pos.x += delatPos;
				if (m_segments[i].m_pos.x > m_boundaryX)
				{
					m_segments[i].m_pos.x = 0.0f - m_segSize.x;
				}
			}break;
		}

		if (!m_turns.empty())
		{
			for (int v = 0; v < m_turns.size(); v++)
			{
				int iSegToProcess = m_segments.size() - m_turns[v].segmentsToProcess;
				bool turnFromY = (m_segments[iSegToProcess].m_state == State::UP    && m_segments[iSegToProcess].m_pos.y <= m_turns[v].pos.y) ||
								 (m_segments[iSegToProcess].m_state == State::DOWN  && m_segments[iSegToProcess].m_pos.y >= m_turns[v].pos.y);
				bool turnFromX = (m_segments[iSegToProcess].m_state == State::LEFT  && m_segments[iSegToProcess].m_pos.x <= m_turns[v].pos.x) ||
								 (m_segments[iSegToProcess].m_state == State::RIGHT && m_segments[iSegToProcess].m_pos.x >= m_turns[v].pos.x);

				if (turnFromX || turnFromY)
				{
					m_segments[iSegToProcess].m_state = m_turns[v].dir;
					if (turnFromX)
					{
						m_segments[iSegToProcess].m_pos.x = m_turns[v].pos.x;
					}
					if (turnFromY)
					{
						m_segments[iSegToProcess].m_pos.y = m_turns[v].pos.y;
					}
					m_turns[v].segmentsToProcess--;
				}

				if (m_turns[v].segmentsToProcess <= 0)
				{
					m_turns.erase(m_turns.begin() + v);
				}
			}
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
	bool cantTurnX = (m_segments.begin()->m_state == State::LEFT  && (dir == State::LEFT || dir == State::RIGHT)) ||
					 (m_segments.begin()->m_state == State::RIGHT && (dir == State::LEFT || dir == State::RIGHT));
	bool cantTurnY = (m_segments.begin()->m_state == State::UP    && (dir == State::UP || dir == State::DOWN)) ||
					 (m_segments.begin()->m_state == State::DOWN  && (dir == State::UP || dir == State::DOWN));
	if (!cantTurnX && !cantTurnY)
	{
		m_turns.push_back({ (int)m_segments.size(), dir, m_segments.begin()->m_pos });
	}
}
