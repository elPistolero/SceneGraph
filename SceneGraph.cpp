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
