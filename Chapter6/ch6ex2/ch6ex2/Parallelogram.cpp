#include "Parallelogram.h"

Parallelogram::Parallelogram(float b, float h)
    :base(b), height(h)
{
}

float Parallelogram::area()
{
    return (base*height)/2;
}