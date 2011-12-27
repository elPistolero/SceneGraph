/*
 * SceneNode.cpp
 *
 *  Created on: Dec 25, 2011
 *      Author: isaak
 */

#include "SceneNode.h"

SceneNode::SceneNode()
: m_parent(0), m_children(0), m_transformation(1.0), m_updated(false) {
}

SceneNode::~SceneNode() {
	// delete children
	while (!m_children.empty()) {
		SceneNode* first = m_children.front();
		m_children.pop_front();
		delete first;
	}
}

void SceneNode::detachNode(SceneNode& child) {
	std::list<SceneNode*>::iterator it;
	for (it = m_children.begin(); it != m_children.end(); ++it) {
		if (&child == *it) {
			m_children.erase(it);
			break;
		}
	}
	child.m_parent = 0;
	child.m_transformation = glm::mat4(1);
}

void SceneNode::attachNode(SceneNode& child) {
	child.m_parent = this;
	m_children.push_back(&child);
	child.m_updated = false;
}

void SceneNode::deleteNode(SceneNode& child) {
	std::list<SceneNode*>::iterator it;
	for (it = m_children.begin(); it != m_children.end(); ++it) {
		if (&child == *it) {
			delete *it;
			m_children.erase(it);
			break;
		}
	}
}

void SceneNode::setTransformation(const glm::mat4& trans) {
	m_transformation = trans;
	m_updated = false;
}

glm::mat4& SceneNode::getTransformation() {
	return m_transformation;
}

void SceneNode::update() {
	// skip if there are no changes
	if (m_updated) {
		return;
	// otherwise update
	} else {
		// update from parent
		if (m_parent) {
			m_transformation = m_parent->getTransformation() * m_transformation;
			m_updated = true;
		// we are at the root
		} else {
			m_updated = true;
		}

		// update possible children
		if (!m_children.empty()) {
			std::list<SceneNode*>::iterator it;
			for (it = m_children.begin(); it != m_children.end(); ++it) {
				(*it)->m_updated = false;
				(*it)->update();
			}
		}
	}
}

std::ostream& operator<< (std::ostream& out, const SceneNode& node) {
	if (node.m_parent)
		out << "parent: 1\n";
	else
		out << "parent: 0\n";
	out << "children: " << node.m_children.size() << std::endl;
	out << "updated: " << node.m_updated << std::endl;
	out << "[" << node.m_transformation[0][0] << ", " << node.m_transformation[0][1] << ", " << node.m_transformation[0][2] << ", " << node.m_transformation[0][3] << "]\n";
	out << "[" << node.m_transformation[1][0] << ", " << node.m_transformation[1][1] << ", " << node.m_transformation[1][2] << ", " << node.m_transformation[1][3] << "]\n";
	out << "[" << node.m_transformation[2][0] << ", " << node.m_transformation[2][1] << ", " << node.m_transformation[2][2] << ", " << node.m_transformation[2][3] << "]\n";
	out << "[" << node.m_transformation[3][0] << ", " << node.m_transformation[3][1] << ", " << node.m_transformation[3][2] << ", " << node.m_transformation[3][3] << "]\n";

	return out;
}
