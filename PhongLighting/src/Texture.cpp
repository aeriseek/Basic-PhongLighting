#include "Texture.h"
#include <stdexcept>


Texture::Texture(const char* imagePath, const char* type, GLuint slot) : type(type) {
	stbi_set_flip_vertically_on_load(true);
	int width, height, colCh;
	unsigned char* bytes = stbi_load(imagePath, &width, &height, &colCh, 0);

	glGenTextures(1, &ID);
	glActiveTexture(GL_TEXTURE0 + slot);
	unit = slot;
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glBindTexture(GL_TEXTURE_2D, ID);
	if (colCh == 4)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, bytes);
	}
	else if (colCh == 3)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, bytes);
	}
	else if (colCh == 1)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RED, GL_UNSIGNED_BYTE, bytes);
	}
	else throw std::invalid_argument("texture type wrong");

	glGenerateMipmap(GL_TEXTURE_2D);
	stbi_image_free(bytes);
	glBindTexture(GL_TEXTURE_2D, 0);
}




void Texture::Bind()
{
	glActiveTexture(GL_TEXTURE0 + unit);
	glBindTexture(GL_TEXTURE_2D, ID);
}

void Texture::Unbind()
{
	glBindTexture(GL_TEXTURE_2D, 0);
}
void Texture::Delete()
{
	glDeleteTextures(1, &ID);
}