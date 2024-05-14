#include "Train.h"

Train::Train(int x, int y, int numCarriage, int carriageWidth,  int carriageHeight, int carriageOffset, 
	Uint32 trainColor, int wheelRadius, Uint32 wheelColor, Uint32 tractorColor, Uint32 chimneyColor, Uint32 windowCol) {
	for (int i = 0; i < numCarriage; i++) {
		// Carriage
		AddRect(x, y - carriageHeight, carriageWidth, carriageHeight, trainColor);
		
		// Wheel
		AddCircle(x + carriageWidth / 4, y, wheelRadius, wheelColor);
		AddCircle(x + 3 * carriageWidth / 4, y, wheelRadius, wheelColor);

		// Window
		AddRect(x + carriageWidth / 5, y - 2 * carriageHeight / 3, carriageWidth / 5, carriageHeight / 3, windowCol);
		AddRect(x + 3 * carriageWidth / 5, y - 2 * carriageHeight /3, carriageWidth / 5, carriageHeight / 3, windowCol);

		// calc next x
		x += carriageOffset + carriageWidth;
	}

	// Chimney
	AddRect(x + carriageWidth / 6, y - 3 * carriageHeight / 2, carriageWidth / 4, carriageHeight, chimneyColor);

	// Tractor
	AddRect(x, y - 2 * carriageHeight / 3, carriageWidth, 2 * carriageHeight / 3, tractorColor);
	AddRect(x, y - carriageHeight, carriageWidth/2, 2 * carriageHeight / 3, tractorColor);
	AddRect(x + carriageWidth / 5, y - 2 * carriageHeight / 3, carriageWidth / 5, carriageHeight / 3, windowCol);
	AddCircle(x + carriageWidth / 4, y, wheelRadius, wheelColor);
	AddCircle(x + 3 * carriageWidth / 4, y, wheelRadius, wheelColor);
	
}

Train::~Train(){}

void Train::Move(int x, int y) 
{
	curr += x;

	if (curr >= slowdown) {
		curr = 0;

		GameObject::Move(x, y);
	}
}

void Train::Show(SDL_Surface* des) {
	for (int i = 0; i < rects.size(); i++) {
		SDL_Rect rect = rects[i].first;
		Uint32 color = rects[i].second;

		int x = rect.x;
		int y = rect.y;
		int w = rect.w;
		int h = rect.h;

		x += this->TransformX;
		y += this->TransformY;

		x %= SCREEN_WIDTH;

		SDLCommonFunc::drawRectangle(x, y, w, h, color);
	}

	for (int i = 0; i < circles.size(); i++) {
		int x = circles[i].x + this->TransformX;
		int y = circles[i].y + this->TransformY;
		int r = circles[i].radius;
		Uint32 color = circles[i].color;

		x %= SCREEN_WIDTH;

		SDLCommonFunc::drawCircle(x, y, r, color);
	}
}
