#pragma once
#include "object.h"

// A quad is a primitive type of 2 triangles.
class Cuboid :
	public Object
{
public:
	Cuboid(float x, float y, float z, FloatColor* color);
};