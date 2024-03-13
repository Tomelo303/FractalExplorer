#include "Window.h"
#include <iostream>

SDL_Renderer* Window::renderer = nullptr;
SDL_Event Window::event;

Window::Window(const char* title, int x, int y)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "Subsystems initialized.\n";

		window = SDL_CreateWindow(title, x, y, width, height, SDL_WINDOW_FULLSCREEN);
		//window = SDL_CreateWindow(title, x, y, width, height, 0);
		if (window)
			std::cout << "Window created.\n";

		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "Renderer created.\n";
		}

		fractal = new Fractal();

		running = true;
	}
	else
	{
		running = false;
	}
}

Window::~Window()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	delete fractal;
	SDL_Quit();
	std::cout << "Application closed.\n";
}

void Window::handleEvents()
{
	SDL_PollEvent(&event);

	switch (event.type)
	{
	case SDL_QUIT:
		quit();
		break;

	// Pressing a key on a keyboard
	case SDL_KEYDOWN:
		switch (event.key.keysym.sym)
		{
		case SDLK_ESCAPE:
			quit();
			break;

		case SDLK_UP:
			fractal->increaseMaxIteration();
			break;

		case SDLK_DOWN:
			fractal->decreaseMaxIteration();
			break;

		default:
			break;
		}
		break;

	// Using mouse wheel
	case SDL_MOUSEWHEEL:
		if (event.wheel.y == 1)
			fractal->zoomIn(event.wheel.mouseX, event.wheel.mouseY);
		else if (event.wheel.y == -1)
			fractal->zoomOut(event.wheel.mouseX, event.wheel.mouseY);
		//std::cout << event.wheel.mouseX << ", " << event.wheel.mouseY << "\n";
		break;

	default:
		break;
	}
}

void Window::update()
{
	if (fractal->generated())
	{
		render();
	}
}

void Window::render()
{
	SDL_RenderClear(renderer);  // Clear previous render
	fractal->render();
	SDL_RenderPresent(renderer);
}
