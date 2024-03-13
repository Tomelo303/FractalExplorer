#ifndef WINDOW_H
#define WINDOW_H

#include <SDL.h>
#include "../Fractal/Fractal.h"


class Window
{
  public:
	Window(const char* title, int x, int y);
	~Window();

	void handleEvents();  // Handle user input
	void update();		  // Update the state of the game
	bool isRunning() const { return running; }

	static SDL_Renderer* renderer;
	static SDL_Event event;
	static const int width = 1920;   // Width of the window
	static const int height = 1080;  // Height of the window

  private:
	void render();  // Display the changes on the screen
	inline void quit() { running = false; }

	SDL_Window* window = nullptr;
	Fractal* fractal = nullptr;
	bool running = false;
};

#endif // WINDOW_H

