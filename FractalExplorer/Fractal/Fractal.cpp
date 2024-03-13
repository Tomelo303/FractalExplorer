#include "Fractal.h"
#include "../Window/Window.h"

#include <iostream>
#include <cmath>


Pixel pixels[Window::width][Window::height];

Fractal::Fractal()
{
	generate();
}

Fractal::~Fractal()
{
	std::cout << "Fractal destroyed.\n";
}

void Fractal::render()
{
	// Iterate through every pixel of the window and set its corresponding RGB value
	for (int w = 0; w < Window::width; w++)
		for (int h = 0; h < Window::width; h++)
		{
			SDL_SetRenderDrawColor(Window::renderer, pixels[w][h].R, pixels[w][h].G, pixels[w][h].B, 255);
			SDL_RenderDrawPoint(Window::renderer, w, h);
		}
	ready = false;
}

void Fractal::zoomIn(int mouseX, int mouseY)
{	
	center = convertWindowToFractalCoordinates(mouseX, mouseY);
	zoom(++zoom_level);
	
	// A way to prevent length value from going below 0, which would result in flipping the image vertically
	if (length.x > 0 && length.y > 0)
	{
		generate();
	}
	else
	{
		zoomOut(mouseX, mouseY);
		std::cout << "Cannot zoom in further.\n";
	}

	std::cout << "Centered to: " << center << ", length: " << length << ", zoom = " << zoom_level << "\n";
}

void Fractal::zoomOut(int mouseX, int mouseY)
{
	if (zoom_level > 2) // Normal zoom out behavior
	{
		center = convertWindowToFractalCoordinates(std::abs(Window::width - mouseX), std::abs(Window::height - mouseY));
		zoom(--zoom_level);
		generate();

		std::cout << "Centered to: " << center << ", length: " << length << ", zoom = " << zoom_level << "\n";
	}
	else if (zoom_level == 2) // Zoom out from level 2 to 1 results in image looking like at the beginnig
	{
		zoom_level--;

		center = start_center;
		length = start_length;

		generate();

		std::cout << "Centered to: " << center << ", length: " << length << ", zoom = " << zoom_level << "\n";
	}
	else // Cannot zoom out to level 0 (preventing dividing by zero)
	{
		std::cout << "Cannot zoom out further.\n";
	}
}

void Fractal::increaseMaxIteration()
{
	max_iteration += 1000;
	iteration_range.isRangeOf(max_iteration);
	generate();
	std::cout << "Max iteration set to " << max_iteration << "\n";
}

void Fractal::decreaseMaxIteration()
{
	max_iteration -= 1000;
	iteration_range.isRangeOf(max_iteration);
	generate();
	std::cout << "Max iteration set to " << max_iteration << "\n";
}

// PRIVATE

Vector2 Fractal::convertWindowToFractalCoordinates(int x, int y) const
{
	long double X = center.x + (x / static_cast<long double>(Window::width - 1) - 0.5) * length.x;
	long double Y = center.y + (y / static_cast<long double>(Window::height - 1) - 0.5) * length.y;
	return Vector2(X, Y);
}

void Fractal::zoom(unsigned int zoom_level)
{
	if (zoom_level <= 5)
	{
		length.x = start_length.x / static_cast<long double>(zoom_level);
		length.y = start_length.y / static_cast<long double>(zoom_level);
	}
	else // For levels above 5 zoom power increases by 0.5
	{
		length.x = start_length.x / std::pow(static_cast<long double>(zoom_level), 1 + 0.5 * (zoom_level - 5));
		length.y = start_length.y / std::pow(static_cast<long double>(zoom_level), 1 + 0.5 * (zoom_level - 5));
	}
}

void Fractal::generate()
{
	// DECLARATION OF VARIABLES
	// Variables marking the area of the fractal being calculated
	long double x0 = 0;
	long double y0 = 0;
	
	// Variables used in the equation
	long double x_temp = 0;
	long double x = 0;
	long double y = 0;
	int iteration = 0;

	// Variables for defining the colors
	long double color = 0;			 // Intensity of the color depending on the number of iterations and ranging from 0 to 255
	long double reversed_color = 0;  // Reversed color value (makes the fractal black and background colored)
	long double m = 0;				 // Color multiplier

	// GENERATION OF A FRACTAL
	for (int w = 0; w < Window::width; w++)
		for (int h = 0; h < Window::width; h++)
		{
			// These variables' values range from the start value to start value + end value throughout the execution of this for loop
			x0 = center.x + (w / static_cast<long double>(Window::width - 1) - 0.5) * length.x;
			y0 = center.y + (h / static_cast<long double>(Window::height - 1) - 0.5) * length.y;

			x = 0;
			y = 0;

			iteration = 0;

			while (x * x + y * y < 2 * 2 && iteration < max_iteration)
			{
				x_temp = x * x - y * y + x0;
				y = 2 * x * y + y0;
				x = x_temp;

				iteration += 1;
			}

			// Calculating RGB values based on the number of iterations
			color = 255 * (static_cast<long double>(iteration) / static_cast<long double>(max_iteration));
			reversed_color = 255 - color;
			m = reversed_color / 255.0;

			// Assigning RGB values to each pixel
			pixels[w][h].setPixelColor(127 * m, 169 * m, 250 * m);
		}
	
	ready = true;
}
