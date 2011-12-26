/*
 * SceneNode.h
 *
 *  Created on: Dec 25, 2011
 *      Author: isaak
 */

#ifndef SCENENODE_H_
#define SCENENODE_H_

#include <list>
#include "ogl-math/glm/glm.hpp"
#include "iostream"

class SceneNode {
public:
	SceneNode();
	virtual ~SceneNode();
	void attachNode(SceneNode& child);
	void deleteNode();
	SceneNode& getParent();
	void setParent(SceneNode* parent);
	std::list<SceneNode*>& getChildren();

private:
	SceneNode* m_parent;
	std::list<SceneNode*> m_children;
	glm::mat4 m_transformation;
};

#endif /* SCENENODE_H_ */
