#pragma once

#include <iostream>
#include <vector>
#include <assert.h>

#include "Matrix3.h"

class SceneObject
{
public:
	SceneObject() {}
	virtual ~SceneObject() {
		// Basically just sets m_parent back to nullptr when destroyed
		if (m_parent != nullptr) {
			m_parent->removeChild(this);
		}
		
		// Basically abandons children when destroyed
		for (SceneObject* child : m_children) {
			child->m_parent = nullptr;
		}
	}

	//Just a getter for everything that isn't a child of SceneObject
	SceneObject* getParent() const { return m_parent; }

	// I assume this is for things like passing the child vector into a function, as functions don't like it when you try to find the length in them
	size_t childCount() const { return m_children.size(); }

	// Simply just a getter for a specific child
	SceneObject* getChild(unsigned int index) const { return m_children[index]; }

protected:
	SceneObject* m_parent = nullptr;
	std::vector<SceneObject*> m_children;

	Matrix3 m_localTransform;
	Matrix3 m_globalTransform;

public:
	// Just a way to add and remove things in the m_children vector and the m_parent variable
	void addChild(SceneObject* child);
	void removeChild(SceneObject* child);

	// These functions are going to be overridden
	virtual void onUpdate(float deltaTime) {};
	virtual void onDraw() {};

	// These functions basically just run the overridden onUpdate and onDraw functions for all of the children in the vector
	void update(float deltaTime);
	void draw();

	// These functions are just getters for the different transforms
	const Matrix3& getLocalTransform() const;
	const Matrix3& getGlobalTransform() const;
	void setLocalTransform(Matrix3 matrix);

	// This function changes the global transform based on the local transform. 
	// If the object has a parent, it changes with local * global, if not, it's just global = local
	// It then goes through all the children in the array and does the same
	void updateTransform();

	// These functions are just using already existing functions in matrix, but adds the updateTransform function to them.
	// These functions are kinda useless, as there is not really much point in resetting the matrices
	void setPosition(float x, float y);
	void setRotation(float radians);
	void setScale(float x, float y);
	// These functions are ones we'll use
	void translate(float x, float y);
	void rotate(float radians);
	void scale(float x, float y);
};

