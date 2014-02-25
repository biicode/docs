#include "sphere.h"

Sphere::Sphere(float _radius, int _slices, int _stacks, bool _solid):
radius(_radius),slices(_slices),stacks(_stacks),solid(_solid){
	setPosition();
	setColor();
}

Sphere::~Sphere(){}

void Sphere::draw(){	
	glColor3ub(red,green,blue);
	glTranslatef(x,y,z);
	if (solid)
		glutSolidSphere(radius, slices, stacks);
	else
		glutWireSphere(radius, slices, stacks);
	glTranslatef(-x,-y,-z);			
}
