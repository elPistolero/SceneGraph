/*
 * Scenegraph.cpp
 *
 *  Created on: Dec 25, 2011
 *      Author: isaak
 */

#include "SceneGraph.h"

SceneGraph::SceneGraph() : m_root(0) {
	m_root = new SceneNode();
}

SceneGraph::~SceneGraph() {
	delete m_root;
}

int main() {

	SceneGraph scene;
	SceneNode* root = scene.getRoot();
	SceneNode* child = new SceneNode();
	SceneNode* child2 = new SceneNode();
	SceneNode* child21 = new SceneNode();
	root->attachNode(*child);
	root->attachNode(*child2);
	child2->attachNode(*child21);
	root->setTransformation(glm::mat4(2));
	root->update();

	std::cout << "root:\n" << *root << std::endl;
	std::cout << "child:\n" << *child << std::endl;
	std::cout << "child2:\n" << *child2 << std::endl;
	std::cout << "childe21:\n" << *child21 << std::endl;

	root->setTransformation(glm::mat4(4));
	root->update();

	std::cout << "root:\n" << *root << std::endl;
	std::cout << "child:\n" << *child << std::endl;
	std::cout << "child2:\n" << *child2 << std::endl;
	std::cout << "childe21:\n" << *child21 << std::endl;

	child2->detachNode(*child21);
	root->update();

	std::cout << "root:\n" << *root << std::endl;
	std::cout << "child:\n" << *child << std::endl;
	std::cout << "child2:\n" << *child2 << std::endl;
	std::cout << "childe21:\n" << *child21 << std::endl;

	root->attachNode(*child21);
	root->update();

	std::cout << "root:\n" << *root << std::endl;
	std::cout << "child:\n" << *child << std::endl;
	std::cout << "child2:\n" << *child2 << std::endl;
	std::cout << "childe21:\n" << *child21 << std::endl;

	root->deleteNode(*child2);
	root->update();

	return 0;
}
