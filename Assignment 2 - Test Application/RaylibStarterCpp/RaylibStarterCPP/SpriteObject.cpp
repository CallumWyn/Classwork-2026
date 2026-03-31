#include "SpriteObject.h"

float SpriteObject::getWidth() {
	return m_texture->width;
}

float SpriteObject::getHeight() {
	return m_texture->height;
}

void SpriteObject::Load(const char* filename) {
	Image img = LoadImage(filename);
	*m_texture = LoadTextureFromImage(img);
}