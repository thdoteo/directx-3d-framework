#pragma once
#include "entity.h"

// A quad is a primitive type of 2 triangles.
class Quad :
	public Entity
{
public:

	Quad();
	Quad(float x, float y, float z);
	~Quad() {}
};

