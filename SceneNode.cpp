/*
 * SceneNode.cpp
 *
 *  Created on: Dec 25, 2011
 *      Author: isaak
 */

#include "SceneNode.h"

SceneNode::SceneNode()
: m_parent(0), m_children(0), m_transformation(1.0) {
	std::cout << "construct SceneNode\n";
}

SceneNode::~SceneNode() {
	std::cout << "destruct SceneNode\n";
	// delete children
	std::list<SceneNode*>::iterator it;
	for (it = m_children.begin(); it != m_children.end(); ++it)
		delete *it;
}

void SceneNode::setParent(SceneNode* parent) {
	m_parent = parent;
}

void SceneNode::attachNode(SceneNode& child) {
	child.setParent(this);
	m_children.push_back(&child);
}
