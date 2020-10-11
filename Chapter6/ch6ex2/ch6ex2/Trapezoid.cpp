#include "Trapezoid.h"

Trapezoid::Trapezoid(float t, float b, float h)
    :top(t), bottom(b), height(h)
{
}

float Trapezoid::area()
{
    return (top + bottom)*height/2;
}