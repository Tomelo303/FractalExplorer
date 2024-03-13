#include "Window/Window.h"
#include "Vector2/Vector2.h"


int main(int argc, char* argv[])
{
	Window fractal_explorer("Fractal Explorer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);

	while (fractal_explorer.isRunning())
	{
		fractal_explorer.handleEvents();
		fractal_explorer.update();
	}

	return 0;
}
