#pragma once

#include <map>
#include <string>

#include "shader.h"

class ResourceManager
{
public:
	ResourceManager() = delete;
	~ResourceManager() = delete;

	static void loadShader(const char* vPath, const char* fPath, const char* shaderName);
	static Shader& getShader(const char* shaderName);

private:
	static std::map<std::string, Shader> shaders;

};