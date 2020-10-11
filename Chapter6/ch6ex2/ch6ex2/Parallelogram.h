#pragma once
#include "Quadrilateral.h"
class Parallelogram :
	public Quadrilateral
{
public:
	Parallelogram(float b, float h);
	virtual float area();
protected:
	float base;
	float height;
};

