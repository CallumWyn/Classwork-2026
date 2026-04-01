#pragma once

#include <iostream>
#include "raylib.h"
#include "SceneObject.h"
#include "SpriteObject.h"

class Game{

public:

	Game(){}
	Game(int screenWidth, int screenHeight) {

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
	}

	

	

	// Init basically just starts off the code, sets all of the variables, does all of the things it needs to do before the game runs
	// It will need to define the tank and turret, and set the turret as a child of the tank
	void Init();
	// I think this runs functions when you quit the game? not sure
	void Shutdown();
	// Update runs every bit of the game, detecting when the player clicks a key, and what function to run when that happens
	void Update();
	// Basically just runs the onDraw function in spriteObject for all sprites
	void Draw();

protected:
	SceneObject* tank = new SceneObject();
	SceneObject* turret = new SceneObject();
	SceneObject* bullet = new SceneObject();

	SpriteObject* tankSprite = new SpriteObject();
	SpriteObject* turretSprite = new SpriteObject();
	SpriteObject* bulletSprite = new SpriteObject();

	bool bulletOn = false;

	int s_Width = 800;
	int s_Height = 450;
};





