#pragma once


#include "raylib.h"

class Critter
{
public:
	Vector2 m_position;
	Vector2 m_velocity;
	float m_radius;

	Texture2D m_texture;

	bool m_isLoaded = new bool(false);
	bool m_isDirty = new bool(false);		// indicates if we've already processed a collision response for this critter



public:
	Critter();
	~Critter() {
		//delete m_position;
		//delete m_velocity;
		//delete m_radius;
		//delete m_isLoaded;
		//delete m_isDirty;

		//m_position = nullptr;
		//m_velocity = nullptr;
		//m_radius = nullptr;
		//m_isLoaded = nullptr;
		//m_isDirty = nullptr;
	};

	void Init(Vector2 position, Vector2 velocity, float radius, const char* texture);
	void ReInit(Vector2 position, Vector2 velocity, float radius);
	void Destroy();
	void Update(float dt);
	void Draw();

	Vector2* GetTextureWH() {
		Vector2* wh = new Vector2();
		wh->x = m_texture.width;
		wh->y = m_texture.height;
		return wh;
	};


	float GetX() { return m_position.x; }
	float GetY() { return m_position.y; }
	void SetX(float x) { m_position.x = x; }
	void SetY(float y) { m_position.y = y; }

	Vector2 GetPosition() { return m_position; }
	void SetPosition(Vector2 position) { m_position = position; }

	Vector2 GetVelocity() { return m_velocity; }
	void SetVelocity(Vector2 velocity) { m_velocity = velocity; }

	float GetRadius() { return m_radius; }

	bool IsDirty() { return m_isDirty; }
	void SetDirty() { m_isDirty = true; }

	bool IsDead() { return m_isLoaded == false; }

};

