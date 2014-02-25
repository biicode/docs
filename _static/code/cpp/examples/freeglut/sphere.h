#pragma once
#include "glui/glutwrapper/glut.h"

class Sphere{
    public:
        Sphere(float _radio=1.0, int _slices=20, int _stacks=20, bool _solid=true);
        virtual ~Sphere(); //default virtual destructor
        void draw();
        void setPosition(float _x=0.0, float _y=0.0, float _z=0.0){
			x = _x; y = _y; z = _z;
		}
        void setColor(unsigned char r=255, unsigned char g=255, unsigned char b=255){
			red = r; green = g; blue = b;
		}
        
    private:
		float radius;
		int slices;
		int stacks;
		unsigned char red, green, blue;
		float x,y,z;
		bool solid;
};
