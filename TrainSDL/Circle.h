#ifndef _CIRCLE_H
#define _CIRCLE_H

class Circle {
public:
	Circle(int x, int y, int r, Uint32 color) {
		this->x = x;
		this->y = y;
		this->radius = r;
		this->color = color;
	}

	int x, y, radius;
	Uint32 color;
};

#endif