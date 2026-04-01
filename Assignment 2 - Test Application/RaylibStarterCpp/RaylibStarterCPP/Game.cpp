#include "Game.h"

void Game::Init() {
	
	Matrix3::print(tank->getGlobalTransform());

	tankSprite->Load("../Tank_images/tankBody_blue_outline.png");
	turretSprite->Load("../Tank_images/tankBlue_barrel1_outline.png");

	// Makes the sprites children of the objects
	tank->addChild(tankSprite);
	turret->addChild(turretSprite);
	tank->setPosition(200, 205);
	turret->setPosition(0, 235);
	


	// Attaches turret to tank
	tank->addChild(turret);


	Matrix3::print(tank->getGlobalTransform());
}

void Game::Update() {
	if (IsKeyDown(KEY_W)) { 
		// You translate it based off of values in the matrix to account for the angle it's on
		tank->translate(tank->getGlobalTransform().m1, tank->getGlobalTransform().m2);
		std::cout << tank->getLocalTransform().m7 << " | " << tank->getLocalTransform().m8 << '\n';
	}
	if (IsKeyDown(KEY_S)) { 
		tank->translate(-(tank->getGlobalTransform().m1), -(tank->getGlobalTransform().m2));
		std::cout << tank->getLocalTransform().m7 << " | " << tank->getLocalTransform().m8 << '\n';
	}
	if (IsKeyDown(KEY_D)) { 
		Matrix3::print(tank->getGlobalTransform());
		tank->rotate(0.01); 
		std::cout << tank->getLocalTransform().m1 << " | " << tank->getLocalTransform().m2 << " | " 
			<< tank->getLocalTransform().m4 << " | " << tank->getLocalTransform().m5 << '\n';
		//tank->translate(0, 1);
	}
	if (IsKeyDown(KEY_A)) { 
		tank->rotate(-0.01);
		std::cout << "\nTank Matrix: \n";
		Matrix3::print(tank->getLocalTransform());
		std::cout << "\nTurret Matrix: \n";
		Matrix3::print(turret->getGlobalTransform());
		// For some reason, instead of changing the rotation of the turret, it changes the position

	}
}

void Game::Draw() {
	tank->draw();
}



