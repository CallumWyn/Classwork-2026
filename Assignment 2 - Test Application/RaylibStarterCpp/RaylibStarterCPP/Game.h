#pragma once
class Game {
public:
	Game();
	virtual ~Game();
	virtual bool startup(); // also known as Init()
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

};

