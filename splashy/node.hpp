#pragma once
#include "stdafx.h"

struct Node_object {
	int objectID;
	ImVec2 spacing;
	int flags;

};

struct Node_t {
	const NChar name;
	const NChar titlebar_name;
	Node_object attributes;
	int nodeID;

};