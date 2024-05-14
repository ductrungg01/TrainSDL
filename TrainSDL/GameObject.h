
#ifndef _GAMEOBJECT_H_
#define _GAMEOBJECT_H_

#include <SDL.h>
#include <SDL_image.h>
#include <vector>
#include "Common_Function.h"
#include "Circle.h"

class GameObject {
public:
	GameObject();
	~GameObject();

	virtual void Show(SDL_Surface* des);
	void AddRect(int x, int y, int w, int h, Uint32 color);
	void AddCircle(int x, int y, int radius, Uint32 color);
	virtual void Move(int x, int y);

protected:
	int TransformX, TransformY;
	std::vector<std::pair<SDL_Rect, Uint32>> rects;
	std::vector<Circle> circles;
};

#endif // !_GAMEOBJECT_H_
