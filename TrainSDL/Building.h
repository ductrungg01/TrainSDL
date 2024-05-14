#ifndef _BUILDING_H_
#define _BUILDING_H_

#include "GameObject.h"
#include <random>

class Building : public GameObject {
public:
	Building(int x, int y, int width, int height, int windowRows, int windowColumns, int windowW, int windowH, int windowW_offset, int windowH_offset, Uint32 buildingColor);
	~Building();

protected:
	const int shadowDirectionX = 3, shadowDirectionY = -3;
};


#endif