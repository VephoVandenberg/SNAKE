#pragma once

#include <glm/glm.hpp>

class Shader
{
public:
	Shader() {}
	Shader(const char *vPath, const char *fPath);
	~Shader();

	void use();
	void setUniform1i(const char *uniform, int value);
	void setUniform4m(const char *uniform, glm::mat4 matrix);
	void setUniform3v(const char *unifrom, glm::vec3 vector);

private:
	unsigned int ID;
};
