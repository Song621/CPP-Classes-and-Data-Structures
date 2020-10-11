#pragma once
#include "Shape.h"
class Quadrilateral :
	public Shape
{
public:
	Quadrilateral();
	virtual float area() = 0;
};

