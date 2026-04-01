#include "Game.h"

void Game::Init() {
	
	Matrix3::print(tank->getGlobalTransform());

	// Loads the sprites so that they are stored in the sprite variables
	tankSprite->Load("../Tank_images/tankBody_blue_outline.png");
	turretSprite->Load("../Tank_images/tankBlue_barrel1_outline.png");

	// Both of these try to put the sprites in the right positions so the rotation doesn't mess up, but it doesn't do it perfectly, and if the screen gets any bigger, it will not work
	// Puts the turret in approximately the right position
	turretSprite->rotate(-90 * (float)(PI / 180.0f));
	turretSprite->setPosition(-turretSprite->getHeight() / 2, turretSprite->getWidth() - 72.5f);
	// Puts the tank in approximately the right position
	tankSprite->rotate(-90 * (float)(PI / 180.0f));
	tankSprite->setPosition(-(tankSprite->getWidth() / 2.0f), tankSprite->getHeight() / 2.0f - 80);

	// Makes the sprites children of the objects
	tank->addChild(tankSprite);
	turret->addChild(turretSprite);
	// Attaches turret to tank
	tank->addChild(turret);

	// Sets the actual tank object position
	tank->setPosition(s_Width / 2.0f, s_Height / 2.0f);

}

void Game::Update() {
	// Detects if a key is being held down
	if (IsKeyDown(KEY_W)) { 
		// Moves the tank object and all of it's children
		tank->translate(tank->getGlobalTransform().m1, tank->getGlobalTransform().m2);
		// Gives debug info about the tank and turret's matrices
		std::cout << "\nTank Matrix: \n";
		Matrix3::print(tank->getLocalTransform());
		std::cout << "\nTurret Matrix: \n";
		Matrix3::print(turret->getGlobalTransform());
	}
	if (IsKeyDown(KEY_S)) { 
		tank->translate(-(tank->getGlobalTransform().m1), -(tank->getGlobalTransform().m2));
		std::cout << "\nTank Matrix: \n";
		Matrix3::print(tank->getLocalTransform());
		std::cout << "\nTurret Matrix: \n";
		Matrix3::print(turret->getGlobalTransform());
	}
	if (IsKeyDown(KEY_D)) { 
		Matrix3::print(tank->getGlobalTransform());
		tank->rotate(0.01); 
		std::cout << "\nTank Matrix: \n";
		Matrix3::print(tank->getLocalTransform());
		std::cout << "\nTurret Matrix: \n";
		Matrix3::print(turret->getGlobalTransform());
	}
	if (IsKeyDown(KEY_A)) { 
		tank->rotate(-0.01);
		std::cout << "\nTank Matrix: \n";
		Matrix3::print(tank->getLocalTransform());
		std::cout << "\nTurret Matrix: \n";
		Matrix3::print(turret->getGlobalTransform());
	}
	if (IsKeyDown(KEY_E)) { 
		turret->rotate(0.01);
		std::cout << "\nTank Matrix: \n";
		Matrix3::print(tank->getLocalTransform());
		std::cout << "\nTurret Matrix: \n";
		Matrix3::print(turret->getGlobalTransform());
	}
	if (IsKeyDown(KEY_Q)) { 
		turret->rotate(-0.01);
		std::cout << "\nTank Matrix: \n";
		Matrix3::print(tank->getLocalTransform());
		std::cout << "\nTurret Matrix: \n";
		Matrix3::print(turret->getGlobalTransform());
	}
}

void Game::Draw() {
	tank->draw();
}



