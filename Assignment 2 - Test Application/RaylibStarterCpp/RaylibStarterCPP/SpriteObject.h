#pragma once

#include "raylib.h"
#include "SceneObject.h"

// Need to figure out wtf to do here lol
class SpriteObject : public SceneObject{
public:
	SpriteObject() {}
	SpriteObject(const char* filename) {
		Load(filename);
	}

	~SpriteObject() { delete m_texture; delete m_image; }

	// Gets the height and width of the texture
	float getWidth();
	float getHeight();

	// Have a look at this later to see what it does
	void Load(const char* filename);
	
	// Overrides SceneObject's OnDraw function
	void onDraw() override {
		// Gets the rotation in radians from the globalTransform matrix
		float rotation = (float)atan2(m_globalTransform.m2, m_globalTransform.m1);
		// Creates a Vector2 and Sets it to the translation values in the globalTransform array
		// DrawTextureEx doesn't like vector3's, nor does it like individual values
		Vector2 a; a.x = m_globalTransform.m7; a.y = m_globalTransform.m8;
		// Draws the texture using the texture file, the vector2, the rotation, a scale of 1 and a tint of WHITE (Which means it looks normal)
		DrawTextureEx(*m_texture, a, rotation * (float)(180.f / PI), 1, WHITE);
	}
	

protected:
	Texture2D *m_texture = new Texture2D();
	Image *m_image = new Image();
};

