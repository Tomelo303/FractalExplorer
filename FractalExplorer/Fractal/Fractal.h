#ifndef FRACTAL_H
#define FRACTAL_H

#include <SDL.h>
#include "../Vector2/Vector2.h"


struct Pixel
{
    int R, G, B;

    void setPixelColor(int r, int g, int b)
    {
        R = r;
        G = g;
        B = b;
    }
};

class Fractal
{
  public:
	Fractal();
	~Fractal();

    /* Render the fractal. */
    void render();

    /* Zoom in on the fractal and center to the position of the mouse cursor. */
	void zoomIn(int mouseX, int mouseY);
	
    /* Zoom out of the fractal and center to the position of the mouse cursor. */
    void zoomOut(int mouseX, int mouseY);
    
    /* Increase the precision of calculation (the larger the number of max iteration the longer it takes to generate the image). */
    void increaseMaxIteration();
    
    /* Decrease the precision of calculation. */
    void decreaseMaxIteration();
    
    /* Return true when fractal is generated and ready to be rendered. */
    bool generated() const { return this->ready; }

  private:
    /* Converts mouse position to numbers that are useful for generating a fractal. */
    Vector2 convertWindowToFractalCoordinates(int x, int y) const;
    
    /* Calculate new length value(pass ++zoom_level to zoom in and --zoom_level to zoom out). */
    void zoom(unsigned int zoom_level);
    
    /* Generate a fractal and calculate RGB values of every pixel of the window. */
    void generate();

    Vector2 center = Vector2(-0.75, 0.0);  // Fractal coordinates of the center of the window
    Vector2 length = Vector2(3.5, 2.0);    // Size of the image in Fractal units
    const Vector2 start_center = Vector2(-0.75, 0.0);      // Reference value of center
    const Vector2 start_length = Vector2(3.5, 2.0);        // Reference value of length
    const Vector2 iteration_range = Vector2(1000, 10000);  // Range in which max iteration number is allowed to be
    int max_iteration = 1000;     // Number of iterations after which the result for given arguments is considered to be divergent
    unsigned int zoom_level = 1;  // How much the image is magnified (NOTE: the way the image is magnified is non-linear)
    bool ready = false;           // Is the fractal ready to be rendered
};

#endif // FRACTAL_H
