#pragma once

#include <glm/glm.hpp>

#include "shader.h"

class Renderer
{
public:
	Renderer();
	~Renderer();
	void draw(Shader& shader, glm::vec2 size, glm::vec2 pos, glm::vec3 color = glm::vec3(0.0f));

private:
	unsigned int m_quadVAO;

private:
	void initRenderData();
};