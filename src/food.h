#pragma once

#include "block.h"
#include "shader.h"
#include "renderer.h"

class Food : public Block
{
public:
	Food(State state, glm::vec2 pos, glm::vec2 size, glm::vec3 color = glm::vec3(0.0f));
	~Food();

	void move(glm::vec2 newPos);
private:

};

