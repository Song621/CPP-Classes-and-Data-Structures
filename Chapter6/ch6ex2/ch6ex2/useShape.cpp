#include <iostream>
#include "Parallelogram.h"
#include "Trapezoid.h"
#include "Triangle.h"

using namespace std;

void calculateArea(Shape *p);

int main()
{
	Shape* shp[3];
	shp[0] = new Parallelogram(5.0, 4.0);
	shp[1] = new Trapezoid(4.0, 5.0, 4.0);
	shp[2] = new Triangle(4.0, 5.0);

	//多态
	for (int i = 0; i < 3; i++)
	{
		cout << "area is " << (*shp[i]).area() << endl;//shp[i]->area();
		calculateArea(shp[i]);
	}
	return 0;
}

void calculateArea(Shape *p)
{
	cout << "area is " << p->area() << endl;
}