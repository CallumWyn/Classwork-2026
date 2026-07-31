#pragma once
#include "Critter.h"
#include <stdlib.h>
#include <vector>
#include "raylib.h"
#include "raymath.h"
#include <iostream>

class Quadtree
{
protected:
	// These store the critters in the quads
	std::vector<Critter*> Quad1;
	std::vector<Critter*> Quad2;
	std::vector<Critter*> Quad3;
	std::vector<Critter*> Quad4;

	// These store the width, height and position of the area the quad tree is in
	int x;
	int y;
	int width;
	int height;

	int capacity;

	enum Quadrants {
		Quadrant1,
		Quadrant2,
		Quadrant3,
		Quadrant4
	};

	// These handle the possible subdivisions that can happen
	// I made them smart pointers so they can be easily reset
	std::unique_ptr<Quadtree> subQuad1; // Top Left			= new Quadtree(x / 2, y / 2, w/2, h/2, 2);		
	std::unique_ptr<Quadtree> subQuad2; // Top Right		= new Quadtree(x * 1.5f, y / 2, w/2, h/2, 2);	
	std::unique_ptr<Quadtree> subQuad3; // Bottom Left		= new Quadtree(x / 2, y * 1.5f, w/2, h/2, 2);	
	std::unique_ptr<Quadtree> subQuad4; // Bottom Right		= new Quadtree(x * 1.5f, y * 1.5f, w/2, h/2, 2);
	
	
public:
	Quadtree(int x1, int y1, int w1, int h1, int capacity1) {
		x = x1;
		y = y1;
		width = w1;
		height = h1;
		capacity = capacity1;

		subQuad1 = nullptr;
		subQuad2 = nullptr;
		subQuad3 = nullptr;
		subQuad4 = nullptr;
		

	}
	~Quadtree() {
		Quad1.clear();
		Quad2.clear();
		Quad3.clear();
		Quad4.clear();
	}
	void Insert(Critter &critter);
	void Update(Critter critters[], const int size);
	void Update(const std::vector<Critter*> critters); // I added an overloaded version of update for subdivisions to run cleaner

	void Subdivision(Quadrants quad, const std::vector<Critter*> critters);
	bool AABB(const float x1, const float y1, const float w1, const float h1, Critter& critter);
	void checkQuads();
	void checkCollisionsCritters(std::vector<Critter*> critters);
		
	void debugCheck();


};

