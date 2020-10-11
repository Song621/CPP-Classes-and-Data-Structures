#pragma once
#include "Shape.h"
class Triangle :
	public Shape
{
public:
	Triangle(float b, float h);
	virtual float area();
protected:
	float base;
	float height;
};

