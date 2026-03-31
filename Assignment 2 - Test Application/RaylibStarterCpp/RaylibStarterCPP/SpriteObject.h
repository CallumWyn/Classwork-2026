#pragma once

#include "raylib.h"
#include "SceneObject.h"

// Need to figure out wtf to do here lol
class SpriteObject : public SceneObject{
public:
	SpriteObject() {}
	SpriteObject(std::string filename){}

	bool load(std::string filename);

protected:
	Texture2D m_texture = Texture2D();
};

