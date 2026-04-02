#pragma once

class Wall : public SceneObject{
public:
	float minX;
	float minY;
	float maxX;
	float maxY;

	Wall(float xmin, float ymin, float xmax, float ymax) {
		minX = xmin;
		minY = ymin;
		maxX = xmax;
		maxY = ymax;
	}
	~Wall(){}

	void onDraw() override {
		DrawRectangle(minX, minY, maxX - minX, maxY - minY, RED);
	}
};

