#include "Building.h"

Uint32 getRandomColor(const std::vector<Uint32>& colors) {
	static std::random_device rd;  // Seed for random number generator
	static std::mt19937 gen(rd()); // Mersenne Twister random number generator
	std::uniform_int_distribution<> dis(0, colors.size() - 1); // Uniform distribution

	int randomIndex = dis(gen); // Generate random index
	return colors[randomIndex]; // Return the random color
}

Building::Building(int x, int y, int width, int height, int windowRows, int windowColumns, int windowW, int windowH, int windowW_offset, int windowH_offset, Uint32 buildingColor) {
	Uint32 shadowColor = SDL_MapRGB(g_screen->format, 14, 63, 96);

	Uint32 lightColor1 = SDL_MapRGB(g_screen->format, 142, 120, 4);
	Uint32 lightColor2 = SDL_MapRGB(g_screen->format, 177, 149, 5);
	Uint32 lightColor3 = SDL_MapRGB(g_screen->format, 92, 81, 23);

	std::vector<Uint32> lightCols = { lightColor1, lightColor2, lightColor3 };

	AddRect(x + shadowDirectionX, y + shadowDirectionY, width, height, shadowColor);
	AddRect(x, y, width, height, buildingColor);

	int u = windowW_offset + x;
	int v = windowH_offset + y;

	for (int i = 0; i < windowRows; i++) {
		u = windowH_offset + x;
		for (int j = 0; j < windowColumns; j++) {
			Uint32 randomColor = getRandomColor(lightCols);
			AddRect(u, v, windowW, windowH, randomColor);

			u += windowW + windowW_offset;
		}

		v += windowH + windowH_offset;
	}
}

Building::~Building() {

}