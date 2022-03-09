#include "resource_manager.h"

std::map<std::string, Shader> ResourceManager::shaders;


void ResourceManager::loadShader(const char* vPath, const char* fPath, const char* shaderName)
{
	shaders[shaderName] = Shader(vPath, fPath);
}

Shader& ResourceManager::getShader(const char *shaderName)
{
	return shaders[shaderName];
}
