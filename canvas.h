#pragma once

#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include "turtle.h"

class Canvas
{
  public:
    Canvas(int width, int height);
    ~Canvas(); 
 
  private:
    Turtle turtle_;
}
