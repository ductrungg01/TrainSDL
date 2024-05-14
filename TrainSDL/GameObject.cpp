#include "GameObject.h"

GameObject::GameObject() {
	TransformX = 0;
	TransformY = 0;
}

GameObject::~GameObject() {

}

void GameObject::Show(SDL_Surface* des) {
	for (int i = 0; i < rects.size(); i++) {
		SDL_Rect rect = rects[i].first;
		Uint32 color = rects[i].second;

		int x = rect.x;
		int y = rect.y;
		int w = rect.w;
		int h = rect.h;
		
		x += this->TransformX;
		y += this->TransformY;

		SDLCommonFunc::drawRectangle(x, y, w, h, color);
	}

	for (int i = 0; i < circles.size(); i++) {
		int x = circles[i].x + this->TransformX;
		int y = circles[i].y + this->TransformY;
		int r = circles[i].radius;
		Uint32 color = circles[i].color;

		SDLCommonFunc::drawCircle(x, y, r, color);
	}
}

void GameObject::AddRect(int x, int y, int w, int h, Uint32 color) {
	SDL_Rect rect;
	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;

	rects.push_back(std::make_pair(rect, color));
}

void GameObject::AddCircle(int x, int y, int radius, Uint32 color) {
	Circle circle(x, y, radius, color);

	circles.push_back(circle);
}

void GameObject::Move(int x, int y) {
	this->TransformX += x;
	this->TransformY += y;
}