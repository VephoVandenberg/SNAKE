#pragma once

#include <map>
#include <string>

#include "shader.h"

class ResourceManager
{
public:
	ResourceManager() = delete;
	~ResourceManager() = delete;

	void loadShader(const char* vPath, const char* fPath, const char* shaderName);
	Shader& getShader(const char* shaderName);

private:
	static std::map<std::string, Shader> shaders;

};