#ifndef _COMMON_FUNCTION_H_
#define _COMMON_FUNCTION_H_

#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <Windows.h>

const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 600;
const int SCREEN_BPP = 32;

extern SDL_Surface* g_screen;
extern SDL_Event g_even;

namespace SDLCommonFunc {

	SDL_Surface* LoadImage(std::string file_path);
	void ApplySurface(SDL_Surface* src, SDL_Surface* des, int x, int y);
	void CleanUp();
	void drawRectangle(int x, int y, int width, int height, Uint32 color);
	void drawCircle(int x, int y, int radius, Uint32 color);
}

#endif
