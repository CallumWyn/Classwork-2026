#pragma once

#include <iostream>
#include "raylib.h"
#include "SceneObject.h"
#include "SpriteObject.h"
#include "Wall.h"

class Game{

public:

	Game(){
		s_Width = 800;
		s_Height = 450;
	}
	Game(int screenWidth, int screenHeight) {
		s_Width = screenWidth;
		s_Height = screenHeight;
	}
	~Game() {
		delete tank;
		delete turret;
		delete bullet;
		delete tankSprite;
		delete turretSprite;
		delete bulletSprite;

		tank = nullptr;
		turret = nullptr;
		bullet = nullptr;
		tankSprite = nullptr;
		turretSprite = nullptr;
		bulletSprite = nullptr;

		for (Wall* wall : walls) {
			delete wall;
			wall = nullptr;
		}
	}

	// Init basically just starts off the code, sets all of the variables, does all of the things it needs to do before the game runs
	// It will need to define the tank and turret, and set the turret as a child of the tank
	void Init();
	// Update runs every bit of the game, detecting when the player clicks a key, and what function to run when that happens
	void Update();
	// Basically just runs the onDraw function in spriteObject for all sprites
	void Draw();

	bool bulletCollision(const Wall wall, float x, float y);

protected:
	SceneObject* tank = new SceneObject();
	SceneObject* turret = new SceneObject();
	SceneObject* bullet = new SceneObject();

	SpriteObject* tankSprite = new SpriteObject();
	SpriteObject* turretSprite = new SpriteObject();
	SpriteObject* bulletSprite = new SpriteObject();

	Wall* wall1 = new Wall(100, 100, 200, 350);
	Wall* wall2 = new Wall(600, 100, 700, 350);
	std::vector<Wall*> walls = { wall1, wall2 };

	bool bulletOn = false;

	int s_Width;
	int s_Height;
};





