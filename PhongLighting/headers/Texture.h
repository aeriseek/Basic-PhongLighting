#pragma once
#include <glad/glad.h>
#include <stb_image.h>
#include "Shader.h"

class Texture
{
public:
	GLuint ID;
	const char* type;
	GLuint unit;
	Texture(const char* imagePath, const char* type, GLuint slot);
	void TexUnit(Shader& shader, const char* uniform, GLuint unit);
	void Bind();
	void Unbind();
	void Delete();
};