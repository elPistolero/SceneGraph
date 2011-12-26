/*
 * Scenegraph.h
 *
 *  Created on: Dec 25, 2011
 *      Author: isaak
 */

#ifndef SCENEGRAPH_H_
#define SCENEGRAPH_H_

#include "SceneNode.h"
#include "iostream"

class SceneGraph {
public:
	SceneGraph();
	virtual ~SceneGraph();
	SceneNode* getRoot() { return m_root; }
	void setRoot(SceneNode* root) { m_root = root; }

private:
	SceneNode* m_root;
};

#endif /* SCENEGRAPH_H_ */
