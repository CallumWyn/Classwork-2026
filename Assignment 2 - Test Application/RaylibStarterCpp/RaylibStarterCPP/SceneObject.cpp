#include "SceneObject.h"

void SceneObject::addChild(SceneObject* child) {
	// Checks if child already has parent
	assert(child->m_parent == nullptr);

	// Makes the child's parent the object calling the function
	child->m_parent = this;
	// Adds the child to the parents children vector
	m_children.push_back(child);
}

void SceneObject::removeChild(SceneObject* child) {
	// Finds if child is in the parents vector
	auto iter = std::find(m_children.begin(), m_children.end(), child);

	if (iter != m_children.end()) {
		// Makes the child forget the parent
		child->m_parent = nullptr;
		// Erases the child (From the parent's children vector)
		m_children.erase(iter);
	}
}

void SceneObject::update(float deltaTime) {
	// Runs the overridden onUpdate command if it has one, or just does nothing
	onUpdate(deltaTime);

	// Makes the children go through the same process
	for (SceneObject*& child : m_children) {
		child->update(deltaTime);
	}
}

void SceneObject::draw() {
	// Runs the overridden onDraw command if it has one, or just does nothing
	onDraw();

	// Makes the children go through the same process
	for (SceneObject*& child : m_children) {
		child->draw();
	}
}

const Matrix3& SceneObject::getLocalTransform() const {
	return m_localTransform;
}
const Matrix3& SceneObject::getGlobalTransform() const {
	return m_globalTransform;
}

void SceneObject::updateTransform() {
	// Checks if the object has a parent
	if (m_parent != nullptr) { m_globalTransform = m_parent->m_globalTransform * m_localTransform; }
	// If it doesn't, global transform is set to local
	else { m_globalTransform = m_localTransform; }

	// Goes through all of the children and does the same
	for (SceneObject* child : m_children){
		child->updateTransform();
	}
}

void SceneObject::setPosition(float x, float y) {
	m_localTransform = Matrix3::MakeTranslate(x, y);
}
void SceneObject::setRotation(float radians) {
	m_localTransform = Matrix3::MakeRotate(radians);
}
void SceneObject::setScale(float x, float y) {
	m_localTransform = Matrix3::MakeScale(x, y);
}

void SceneObject::translate(float x, float y) {
	m_localTransform.translate(x, y);
	updateTransform();
}

void SceneObject::rotate(float radians) {
	m_localTransform.rotate(radians);
	updateTransform();
}

void SceneObject::scale(float x, float y) {
	m_localTransform.scale(x, y);
	updateTransform();
}
