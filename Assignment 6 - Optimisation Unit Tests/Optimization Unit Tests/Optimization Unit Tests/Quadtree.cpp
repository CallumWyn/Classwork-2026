#include "pch.h"
#include "Quadtree.h"

bool Quadtree::AABB(const float x1, const float y1, const float width1, const float height1, Critter& critter) {
	// Goes through and checks whether the critter fits within the bounds of the box
	if (critter.GetX() < x1 + width1) { // Checks if the critter is to the left of the box
		if (critter.GetX() > x1 - width1) { // Checks if the critter is to the right of the box
			if (critter.GetY() < y1 + height1) { // Checks if the critter is below the box
				if (critter.GetY() > y1 - height1) { // Checks if the critter is above the box
					return true;
				}
			}
		}
	}
	return false;

	/// Had this version before, but found it harder to read and didn't find a difference in run time
	//return (critter.GetX() < x1 + w1 &&
	//		critter.GetX() > x1 - w1 &&
	//		critter.GetY() < y1 + h1 &&
	//		critter.GetY() > y1 - h1
	//	);
}


// Fix Logic Here
void Quadtree::Insert(Critter& critter) {
	// To account for subdivision, we quarter the width and height and subtract it from x and y during AABB. It also saves a bit of proccessing power by not doing as many calculations
	float quarterWidth = width / 4;
	float quarterHeight = height / 4;
	// Goes through each Quad and checks which one the critter fits into, then puts the critter in a vector
	if (AABB(x - quarterWidth, y - quarterHeight, quarterWidth, quarterHeight, critter)) Quad1.push_back(&critter);			// If Critter is in the Top Left 
	else if (AABB(x + quarterWidth, y - quarterHeight, quarterWidth, quarterHeight, critter)) Quad2.push_back(&critter);		// If Critter is in the Top Right 
	else if (AABB(x - quarterWidth, y + quarterHeight, quarterWidth, quarterHeight, critter)) Quad3.push_back(&critter);		// If Critter is in the Bottom Left 
	else if (AABB(x + quarterWidth, y + quarterHeight, quarterWidth, quarterHeight, critter)) Quad4.push_back(&critter);	// If Critter is in the Bottom Right 

}

void Quadtree::Update(Critter critters[], const int size) {
	// Resets the entire Quadtree to be refilled with updated data
	Quad1.clear();
	Quad2.clear();
	Quad3.clear();
	Quad4.clear();

	// Goes through the container of critters and puts them back in the Quads
	for (int i = 0; i < size; i++) {
		if (!critters[i].IsDirty()) {
			Insert(critters[i]);
		}
	}

	// If there are too many critters in the Quad, it subdivides
	if (Quad1.size() > capacity) Subdivision(Quadrant1, Quad1);
	else subQuad1.reset();

	if (Quad2.size() > capacity) Subdivision(Quadrant2, Quad2);
	else subQuad2.reset();

	if (Quad3.size() > capacity) Subdivision(Quadrant3, Quad3);
	else subQuad3.reset();

	if (Quad4.size() > capacity) Subdivision(Quadrant4, Quad4);
	else subQuad4.reset();

}

void Quadtree::Update(std::vector<Critter*> critters) {
	// Resets the entire Quadtree to be refilled with updated data
	Quad1.clear();
	Quad2.clear();
	Quad3.clear();
	Quad4.clear();

	// Goes through the container of critters and puts them back in the Quads
	for (Critter* critter : critters) {
		if (!critter->IsDirty()) {
			Insert(*critter);
		}
	}

	// If there are too many critters in the Quad, it subdivides
	if (Quad1.size() > capacity) Subdivision(Quadrant1, Quad1);
	else subQuad1.reset();

	if (Quad2.size() > capacity) Subdivision(Quadrant2, Quad2);
	else subQuad2.reset();

	if (Quad3.size() > capacity) Subdivision(Quadrant3, Quad3);
	else subQuad3.reset();

	if (Quad4.size() > capacity) Subdivision(Quadrant4, Quad4);
	else subQuad4.reset();
}

void Quadtree::Subdivision(Quadrants quad, std::vector<Critter*> critters) {
	// To account for future subdivisions, we quarter the width and height and use them in the calculations instead of dividing and multiplying x and y by a set amount
	float quarterWidth = width / 4;
	float quarterHeight = height / 4;
	// This switch case checks which Quadrant needs to be subdivided, and creates a new quadtree in that area. It clears the original quad after for collision detection
	switch (quad) {
	case Quadrant1: // Top Left
		subQuad1 = std::make_unique<Quadtree>(x - quarterWidth, y - quarterHeight, width / 2, height / 2, capacity);
		subQuad1->Update(critters);
		Quad1.clear();
		break;
	case Quadrant2: // Top Right
		subQuad2 = std::make_unique<Quadtree>(x + quarterWidth, y - quarterHeight, width / 2, height / 2, capacity);
		subQuad2->Update(critters);
		Quad2.clear();
		break;
	case Quadrant3: // Bottom Left
		subQuad3 = std::make_unique<Quadtree>(x - quarterWidth, y + quarterHeight, width / 2, height / 2, capacity);
		subQuad3->Update(critters);
		Quad3.clear();
		break;
	case Quadrant4: // Bottom Right
		subQuad4 = std::make_unique<Quadtree>(x + quarterWidth, y + quarterHeight, width / 2, height / 2, capacity);
		subQuad4->Update(critters);
		Quad4.clear();
		break;
	default:
		break;
	}
}

void Quadtree::checkQuads() {
	// This function checks whether a Quadrant Child (subQuad) exists before testing collisions. If it does, it only checks for collisions in that.
	// Since the original Quads are emptied out when a subQuad is created, we only have to check if it's empty.
	// If they are empty, it also checks to see if the subQuads are nullptrs, to prevent errors
	// Quad 1
	if (!Quad1.empty()) checkCollisionsCritters(Quad1);
	else if (subQuad1 != nullptr) subQuad1->checkQuads();

	// Quad 2
	if (!Quad2.empty()) checkCollisionsCritters(Quad2);
	else if (subQuad2 != nullptr) subQuad2->checkQuads();

	// Quad 3
	if (!Quad3.empty()) checkCollisionsCritters(Quad3);
	else if (subQuad3 != nullptr) subQuad3->checkQuads();

	// Quad 4
	if (!Quad4.empty()) checkCollisionsCritters(Quad4);
	else if (subQuad4 != nullptr)subQuad4->checkQuads();

}

void Quadtree::checkCollisionsCritters(std::vector<Critter*> critters) {
	for (int i = 0; i < critters.size(); i++) {
		if (critters[i] == nullptr) continue;
		for (int j = 0; j < critters.size(); j++) {
			if (i == j || critters[i]->IsDirty()) continue; // note: the other critter (j) could be dirty - that's OK    
			// check every critter against every other critter

			float dist = Vector2Distance(critters[i]->GetPosition(), critters[j]->GetPosition());
			if (dist < critters[i]->GetRadius() + critters[j]->GetRadius()) {// <-- collision!.. do math to get critters bouncing
				Vector2 normal = Vector2Normalize(Vector2Subtract(critters[j]->GetPosition(), critters[i]->GetPosition()));
				critters[i]->SetVelocity(Vector2Scale(normal, -80)); // not even close to real physics, but fine for our needs
				critters[i]->SetDirty(); // set the critter to *dirty* so we know not to process any more collisions on it
				// we still want to check for collisions in the case where 1 critter is dirty - so we need a check 
				// to make sure the other critter is clean before we do the collision response
				if (!critters[j]->IsDirty()) {
					critters[j]->SetVelocity(Vector2Scale(normal, 80));
					critters[j]->SetDirty();
				}
				break;
			}
		}
	}
}


/// This was just to test to see if the critters went into the Quads right and there was no duplication or accidental deletion or anything like that.
//void Quadtree::debugCheck() {
//	// system("cls");
//	std::cout << Quad1.size() << " | ";
//	std::cout << Quad2.size() << " | ";
//	std::cout << Quad3.size() << " | ";
//	std::cout << Quad4.size() << '\n';
//}


/// I did have a clearQuads function before, but found out it was causing errors, as the pointers it was deleting weren't originally from Quadtree, but from the main function, practically deleting the critters.
//void Quadtree::clearQuads() {
//	// I have this to safely delete the Quad vectors that have pointers in it, as every element needs to be deleted in the vector to avoid a memory leak
//	// I made it into a function because I plan to use it in the destructor and update function
//	for (Critter* critter : Quad1) {
//		delete critter;
//	}
//	Quad1.clear();
//
//	for (Critter* critter : Quad2) {
//		delete critter;
//	}
//	Quad2.clear();
//
//	for (Critter* critter : Quad3) {
//		delete critter;
//	}
//	Quad3.clear();
//
//	for (Critter* critter : Quad4) {
//		delete critter;
//	}
//	Quad4.clear();
//}