#include "Game.h"

void Game::Init() {
	
	Matrix3::print(tank->getGlobalTransform());

	// Loads the sprites so that they are stored in the sprite variables
	tankSprite->Load("../Tank_images/tankBody_blue_outline.png");
	turretSprite->Load("../Tank_images/tankBlue_barrel1_outline.png");
	bulletSprite->Load("../Tank_images/bulletBlue1_outline.png");

	// Both of these try to put the sprites in the right positions so the rotation doesn't mess up, but it doesn't do it perfectly, and if the screen gets any bigger, it will not work
	// Puts the turret in approximately the right position
	turretSprite->rotate(-90 * (float)(PI / 180.f));
	turretSprite->setPosition(-turretSprite->getHeight() / 2.f, turretSprite->getWidth() - 72.5f);
	// Puts the tank in approximately the right position
	tankSprite->rotate(-90 * (float)(PI / 180.f));
	tankSprite->setPosition(-(tankSprite->getWidth() / 2.f), tankSprite->getHeight() / 2.f - 80);

	Matrix3::print(turret->getGlobalTransform());

	// Makes the sprites children of the objects
	tank->addChild(tankSprite);
	turret->addChild(turretSprite);
	bullet->addChild(bulletSprite);
	// Attaches turret to tank
	tank->addChild(turret);

	// Sets the actual tank object position
	tank->setPosition(s_Width / 2.f, s_Height / 2.f);



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
	if (IsKeyDown(KEY_SPACE)) {
		if (!bulletOn) {
			bulletOn = true;
			bullet->setLocalTransform(turret->getGlobalTransform());
			bullet->translate((bulletSprite->getWidth() / 10), bulletSprite->getHeight());
			/*std::cout << acosf(turret->getGlobalTransform().m1) * (PI / 180) << '\n';
			bullet->setRotation(acosf(turret->getGlobalTransform().m1) * (PI / 180));
			bullet->translate(turret->getGlobalTransform().m7, turret->getGlobalTransform().m8);*/
			std::cout << "Bullet: \n";
			Matrix3::print(bullet->getLocalTransform());
			bullet->updateTransform();
			Matrix3::print(bullet->getGlobalTransform());
			std::cout << "Turret: \n";
			Matrix3::print(turret->getGlobalTransform());

			
		}
	}
	// Checks if the bullet has been fired
	if (bulletOn) {
		// This if statement makes sure the bullet is still within the screen border
		if ((bullet->getGlobalTransform().m7 > -5) && (bullet->getGlobalTransform().m7 < s_Width + 5) && (bullet->getGlobalTransform().m8 > -5) && (bullet->getGlobalTransform().m8 < s_Height + 5)) {
			// This basically just consistantly moves the bullet
			bullet->translate(bullet->getGlobalTransform().m1 * 5, bullet->getGlobalTransform().m2 * 5);
			bullet->draw();
			std::cout << "Bullet: \n";
			Matrix3::print(bullet->getLocalTransform());
		}
		else {
			bulletOn = false;
		}
		
	}

	// Need to:
	// 1. Make a variable for bullet sprite and object, and make bullet object the parent in init
	// 2. Draw bullet when space is pressed, and change it's local tranform to turrets global transform (Possibly adding some numbers like turret width and height)
	// 3. After space is pressed, flip a switch to make player unable to spawn another bullet, and it fufills an if condition to move bullets position based on it's angle
	// 4. When bullet position is a good amount passed the screen border, flip the switch back so bullet stops moving and can be reset
	// 5. Figure out collision
}

void Game::Draw() {
	tank->draw();
}



