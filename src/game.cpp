#include <glm/gtc/matrix_transform.hpp>

#include "game.h"
#include "resource_manager.h"

Game::Game(unsigned int width, unsigned int height) :
	m_width(width), m_height(height), m_foodPosCounter(0)
{
}

Game::~Game()
{
	delete m_renderer;
	delete m_snake;
	delete m_food;
}

void Game::init()
{
	ResourceManager::loadShader("shaders/block.vert", "shaders/block.frag", "block");

	glm::mat4 projection = glm::ortho(0.0f, static_cast<float>(m_width), static_cast<float>(m_height), 0.0f, -1.0f, 1.0f);

	m_renderer = new Renderer();
	m_snake = new Snake(m_width, m_height, glm::vec2(m_width/2, m_height/2), glm::vec3(0.0f, 1.0f, 0.0f));
	m_food = new Food(State::IDLE, glm::vec2(m_width / 4, m_width / 4), glm::vec2(30.0f, 30.0f), glm::vec3(1.0f, 0.0f, 0.0f));

	ResourceManager::getShader("block").use();
	ResourceManager::getShader("block").setUniform4m("projection", projection);
}

void Game::renderObjects()
{
	m_snake->draw(*m_renderer, ResourceManager::getShader("block"));
	m_food->draw(*m_renderer, ResourceManager::getShader("block"));
}

void Game::updateObjects(float dt)
{
	if (m_snake->checkHit(*m_food))
	{
		m_snake->growTail();
		switch (m_foodPosCounter)
		{
			case 0:
			{
				m_food->move(glm::vec2(3 * m_width / 4, m_height / 4));
			}break;
			case 1:
			{
				m_food->move(glm::vec2(3 * m_width / 4, 3 * m_height / 4));
			}break;
			case 2:
			{
				m_food->move(glm::vec2(m_width / 4, 3 * m_height / 4));
			}break;
			case 3:
			{
				m_food->move(glm::vec2(m_width / 4, m_height / 4));
				m_foodPosCounter = 0;
			}break;
		}
		m_foodPosCounter++;

	}
	m_snake->move(dt);
}

void Game::processInput()
{
	if (keys[GLFW_KEY_W])
	{
		m_snake->changeDir(State::UP);
	}
	else if (keys[GLFW_KEY_A])
	{
		m_snake->changeDir(State::LEFT);
	}
	else if (keys[GLFW_KEY_D])
	{
		m_snake->changeDir(State::RIGHT);
	}
	else if (keys[GLFW_KEY_S])
	{
		m_snake->changeDir(State::DOWN);
	}

	keys[GLFW_KEY_W] = false;
	keys[GLFW_KEY_A] = false;
	keys[GLFW_KEY_D] = false;
	keys[GLFW_KEY_S] = false;
}

bool Game::gameShouldOver()
{
	if (m_snake->checkSelfBite())
	{
		return true;
	}

	return false;
}
