#pragma once
#include "Shape.h"
class Ellipse :
	public Shape
{
public:
	Ellipse(float min, float maj);
	virtual float area();
protected:
	float min_axis;
	float maj_axis;
};

