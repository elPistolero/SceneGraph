/*
 * SceneNode.h
 *
 *  Created on: Dec 25, 2011
 *      Author: isaak
 */

#ifndef SCENENODE_H_
#define SCENENODE_H_

#include <list>
#include "glm/glm/glm.hpp"
#include "iostream"

class SceneNode {
public:
	SceneNode();
	virtual ~SceneNode();
	SceneNode& getParent();
	void attachNode(SceneNode& child);
	void detachNode(SceneNode& child);
	void deleteNode(SceneNode& child);
	std::list<SceneNode*>& getChildren();
	void setTransformation(const glm::mat4& trans);
	glm::mat4& getTransformation();
	void update();

	friend std::ostream& operator<< (std::ostream& out, const SceneNode& node);

private:
	SceneNode* m_parent;
	std::list<SceneNode*> m_children;
	glm::mat4 m_transformation;
	bool m_updated;
};

#endif /* SCENENODE_H_ */
