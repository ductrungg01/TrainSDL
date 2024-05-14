#ifndef _TRAIN_H_
#define _TRAIN_H_

#include "GameObject.h"
#include <random>

class Train : public GameObject {
public:
	Train(int x, int y, int numCarriage, int carriageWidth, int carriageHeight , int carriageOffset, 
		Uint32 trainColor, int wheelRadius, Uint32 wheelColor, Uint32 tractorColor, Uint32 chimneyColor, Uint32 windowCol);
	~Train();

	void Move(int x, int y) override;
	void Show(SDL_Surface* des) override;

private:
	int slowdown = 2;
	int curr = 0;
};


#endif