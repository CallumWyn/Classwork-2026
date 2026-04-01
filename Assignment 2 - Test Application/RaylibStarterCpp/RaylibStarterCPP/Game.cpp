#include "Game.h"

void Game::Init() {
	
	tankSprite->Load("../Tank_images/tankBody_blue_outline.png");
	turretSprite->Load("../Tank_images/tankBlue_barrel1_outline.png");

	// Makes the sprites children of the objects
	tank->addChild(tankSprite);
	turret->addChild(turretSprite);
	// turret->setPosition(40, 205);
	


	// Attaches turret to tank
	tank->addChild(turret);



}

void Game::Update() {
	if (IsKeyDown(KEY_W)) { 
		tank->translate(1, 1); 
		std::cout << tank->getLocalTransform().m7 << " | " << tank->getLocalTransform().m8 << '\n';
	}
	if (IsKeyDown(KEY_S)) { 
		tank->translate(-1, 0); std::cout << tank->getLocalTransform().m7 << " | " << tank->getLocalTransform().m8 << '\n';
	}
	if (IsKeyDown(KEY_D)) { 
		tank->rotate(0.0174533); std::cout << tank->getLocalTransform().m7 << " | " << tank->getLocalTransform().m8 << '\n';
	}
	if (IsKeyDown(KEY_A)) { 
		tank->rotate(-0.0174533); std::cout << tank->getLocalTransform().m7 << " | " << tank->getLocalTransform().m8 << '\n';
	}
}

void Game::Draw() {
	tank->draw();
}



