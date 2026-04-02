#pragma once

class Wall : public SceneObject{
public:
	float minX;
	float minY;
	float maxX;
	float maxY;

	Wall(){}
	Wall(float xmin, float ymin, float xmax, float ymax) {
		minX = xmin;
		minY = ymin;
		maxX = xmax;
		maxY = ymax;
	}
	~Wall(){}

	void onDraw() override {
		// I decided to draw lines instead of a rectangle so I could fully see if collision worked inside the box, instead of guessing with a filled rectangle
		// Also to see if the bullet was going through the rectangle a bit
		// MinX to MaxX
		DrawLine(minX, minY, maxX, minY, RED);
		// MinX to MaxY
		DrawLine(minX, minY, minX, maxY, RED);
		// MaxX to MaxY
		DrawLine(minX, maxY, maxX, maxY, RED);
		// MaxX to MaxY
		DrawLine(maxX, minY, maxX, maxY, RED);
	}
};

