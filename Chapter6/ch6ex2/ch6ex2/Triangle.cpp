#include "Triangle.h"

Triangle::Triangle(float b, float h)
    :base(b), height(h)
{
}

float Triangle::area()
{
    return (base*height)/2;
}