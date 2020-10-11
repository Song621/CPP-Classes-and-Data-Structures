#pragma once
#include "Quadrilateral.h"
class Trapezoid :
	public Quadrilateral
{
public:
	Trapezoid(float t, float b, float h);
	virtual float area();
protected:
	float top;
	float bottom;
	float height;
};

