/*
 * Scenegraph.cpp
 *
 *  Created on: Dec 25, 2011
 *      Author: isaak
 */

#include "SceneGraph.h"

SceneGraph::SceneGraph() : m_root(0) {
	std::cout << "construct SceneGraph\n";
	m_root = new SceneNode();
}

SceneGraph::~SceneGraph() {
	std::cout << "destruct SceneGraph\n";
	delete m_root;
}

int main() {

	SceneGraph scene;
	SceneNode* root = scene.getRoot();
	SceneNode* child = new SceneNode();
	root->attachNode(*child);

	return 0;
}
