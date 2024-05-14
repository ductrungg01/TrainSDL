#include "Common_Function.h"

SDL_Surface* g_screen = NULL;
SDL_Event g_even;

SDL_Surface* SDLCommonFunc::LoadImage(std::string file_path)
{
    SDL_Surface* load_image = NULL;
    SDL_Surface* optimize_image = NULL;
    load_image = IMG_Load(file_path.c_str());
    if (load_image != NULL)
    {
        optimize_image = SDL_DisplayFormat(load_image);
        SDL_FreeSurface(load_image);
    }
    return optimize_image;
}


void SDLCommonFunc::ApplySurface(SDL_Surface* src, SDL_Surface* des, int x, int y)
{
    SDL_Rect offset;
    offset.x = x;
    offset.y = y;
    SDL_BlitSurface(src, NULL, des, &offset);
}

void SDLCommonFunc::CleanUp()
{
    SDL_FreeSurface(g_screen);
}

void SDLCommonFunc::drawRectangle(int x, int y, int width, int height, Uint32 color)
{
    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.w = width;
    rect.h = height;
    SDL_FillRect(g_screen, &rect, color);
}

void SDLCommonFunc::drawCircle(int x, int y, int radius, Uint32 color)
{
    for (int w = 0; w < radius * 2; w++)
    {
        for (int h = 0; h < radius * 2; h++)
        {
            int dx = radius - w; // Horizontal distance from center
            int dy = radius - h; // Vertical distance from center
            if ((dx * dx + dy * dy) <= (radius * radius))
            {
                int px = x + dx;
                int py = y + dy;
                if (px >= 0 && px < SCREEN_WIDTH && py >= 0 && py < SCREEN_HEIGHT)
                {
                    Uint32* pixels = (Uint32*)g_screen->pixels;
                    pixels[(py * g_screen->w) + px] = color;
                }
            }
        }
    }
}