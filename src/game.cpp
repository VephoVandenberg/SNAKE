#include <glm/gtc/matrix_transform.hpp>

#include "game.h"
#include "resource_manager.h"

Game::Game(unsigned int width, unsigned int height) :
	m_width(width), m_height(height)
{
}

Game::~Game()
{

}

void Game::init()
{
	ResourceManager::loadShader("shaders/block.vert", "shaders/block.frag", "block");

	glm::mat4 projection = glm::ortho(0.0f, static_cast<float>(m_width), static_cast<float>(m_height), 0.0f, -1.0f, 1.0f);

	m_renderer = new Renderer();
	m_block = new Block(glm::vec2(m_width/2, m_height/2), glm::vec2(50.0f, 50.0f));

	ResourceManager::getShader("block").use();
	ResourceManager::getShader("block").setUniform4m("projection", projection);
}

void Game::renderObjects()
{
	m_block->render(glm::vec2(0.0f), *m_renderer, ResourceManager::getShader("block"));
}

void Game::updateObjects(float dt)
{

}
