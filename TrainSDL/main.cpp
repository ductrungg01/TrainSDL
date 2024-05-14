#include <Windows.h>
#include <SDL.h>
#include <SDL_image.h>
#include <string.h>
#include <string>
#include <iostream>

#include "Common_Function.h"
#include "GameObject.h"
#include "Building.h"
#include "Train.h"

std::vector<Building> buildings;

bool Init()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
    {
        return false;
    }

    g_screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE);

    if (g_screen == NULL)
    {
        return false;
    }

    Uint32 backgroundColor = SDL_MapRGB(g_screen->format, 22, 70, 104);
    SDL_FillRect(g_screen, NULL, backgroundColor);

    return true;
}

void InitCityBackground() {
    Uint32 buildingColor = SDL_MapRGB(g_screen->format, 5, 51, 83);
    Building b1(0, 200, 70, 250, 6, 3, 10, 20, 10, 10, buildingColor);
    Building b2(100, 50, 70, 400, 9, 3, 10, 20, 10, 10, buildingColor);
    Building b3(200, 50, 100, 400, 7, 4, 10, 20, 10, 10, buildingColor);
    Building b4(300, 150, 70, 300, 6, 3, 10, 20, 10, 10, buildingColor);
    Building b5(400, 50, 70, 400, 6, 3, 10, 20, 10, 10, buildingColor);
    Building b6(50, 300, 70, 150, 3, 3, 10, 20, 10, 10, buildingColor);
    Building b7(150, 200, 100, 250, 6, 4, 10, 20, 10, 10, buildingColor);
    Building b8(350, 150, 210, 300, 6, 10, 10, 30, 10, 10, buildingColor);
    Building b9(770, 100, 70, 350, 6, 3, 10, 20, 10, 10, buildingColor);
    Building b10(450, 200, 70, 250, 6, 3, 10, 20, 10, 10, buildingColor);
    Building b11(550, 20, 70, 430, 13, 3, 10, 20, 10, 10, buildingColor);
    Building b12(700, 50, 70, 400, 8, 3, 10, 20, 10, 10, buildingColor);
    Building b13(600, 300, 150, 150, 2, 5, 10, 20, 10, 10, buildingColor);
    Building b14(750, 200, 100, 250, 5, 4, 10, 20, 10, 10, buildingColor);
    Building b15(850, 150, 210, 300, 3, 10, 10, 30, 10, 10, buildingColor);
    Building b16(900, 200, 70, 250, 6, 3, 10, 20, 10, 10, buildingColor);
    Building b17(950, 200, 70, 250, 4, 3, 10, 20, 10, 10, buildingColor);
    Building b18(1000, 150, 210, 300, 2, 10, 10, 30, 10, 10, buildingColor);
    Building b19(1100, 200, 70, 250, 5, 3, 10, 20, 10, 10, buildingColor);
    Building b20(1150, 200, 70, 250, 2, 3, 10, 20, 10, 10, buildingColor);


    buildingColor = SDL_MapRGB(g_screen->format, 4, 2, 55);
    Building b21(0, 300, 150, 150, 3, 4, 25, 30, 10, 10, buildingColor);
    Building b22(175, 200, 150, 250, 5, 4, 25, 30, 10, 10, buildingColor);
    Building b23(350, 250, 150, 200, 4, 4, 25, 30, 10, 10, buildingColor);
    Building b24(550, 300, 200, 150, 3, 5, 35, 30, 10, 10, buildingColor);
    Building b25(650, 200, 150, 250, 5, 4, 25, 30, 10, 10, buildingColor);
    Building b26(750, 340, 250, 110, 2, 4, 25, 30, 10, 10, buildingColor);
    Building b27(900, 100, 150, 350, 8, 4, 25, 30, 10, 10, buildingColor);
    Building b28(125, 350, 175, 100, 3, 3, 40, 20, 10, 10, buildingColor);
    Building b29(375, 350, 175, 100, 3, 3, 40, 20, 10, 10, buildingColor);
    Building b30(1005, 350, 175, 100, 3, 3, 40, 20, 10, 10, buildingColor);


    buildings.push_back(b1);
    buildings.push_back(b2);
    buildings.push_back(b3);
    buildings.push_back(b4);
    buildings.push_back(b5);
    buildings.push_back(b6);
    buildings.push_back(b7);
    buildings.push_back(b8);
    buildings.push_back(b9);
    buildings.push_back(b10);
    buildings.push_back(b11);
    buildings.push_back(b12);
    buildings.push_back(b13);
    buildings.push_back(b14);
    buildings.push_back(b15);
    buildings.push_back(b16);
    buildings.push_back(b17);
    buildings.push_back(b18);
    buildings.push_back(b19);
    buildings.push_back(b20);
    buildings.push_back(b21);
    buildings.push_back(b22);
    buildings.push_back(b23);
    buildings.push_back(b24);
    buildings.push_back(b25);
    buildings.push_back(b26);
    buildings.push_back(b27);
    buildings.push_back(b28);
    buildings.push_back(b29);
    buildings.push_back(b30);
}

void DrawCityBackground() {
    for (int i = 0; i < buildings.size(); i++) {
        buildings[i].Show(g_screen);
    }
}

void DrawRiver() {
    Uint32 riverCol = SDL_MapRGB(g_screen->format, 0, 255, 250);
    SDLCommonFunc::drawRectangle(0, 500, 1200, 100, riverCol);
}

void DrawRailway() {
    Uint32 color = SDL_MapRGB(g_screen->format, 91, 96, 96);
    SDLCommonFunc::drawRectangle(10, 410, 10, 70, color);
    SDLCommonFunc::drawRectangle(310, 410, 10, 70, color);
    SDLCommonFunc::drawRectangle(610, 410, 10, 70, color);
    SDLCommonFunc::drawRectangle(910, 410, 10, 70, color);
    SDLCommonFunc::drawRectangle(1190, 410, 10, 70, color);
    SDLCommonFunc::drawRectangle(0, 410, 1200, 5, color);
}

#undef main

int main(int arc, char* argv[])
{
    bool is_quit = false;
    if (Init() == false)
        return 0;

    InitCityBackground();


    Uint32 red = SDL_MapRGB(g_screen->format, 255, 0, 0);
    Uint32 black = SDL_MapRGB(g_screen->format, 0, 0, 0);
    Uint32 tractorCol = SDL_MapRGB(g_screen->format, 170, 41, 0);
    Uint32 chimneyCol = SDL_MapRGB(g_screen->format, 203, 197, 195);
    Uint32 windowCol = SDL_MapRGB(g_screen->format, 121, 43, 17);
    Train train(0, 405, 5, 70, 30, 10, red, 6, black, tractorCol, chimneyCol, windowCol);

    while (!is_quit)
    {
        DrawCityBackground();
        DrawRiver();
        DrawRailway();
        train.Show(g_screen);
        train.Move(1, 0);

        while (SDL_PollEvent(&g_even))
        {
            if (g_even.type == SDL_QUIT)
            {
                is_quit = true;
                break;
            }
        }
        if (SDL_Flip(g_screen) == -1)
            return 0;
    }
    SDLCommonFunc::CleanUp();
    SDL_Quit();
    return 1;
}
