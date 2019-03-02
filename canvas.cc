#include "canvas.h"

Canvas::Canvas(int width, int height) {
  SDL_Init(SDL_INIT_VIDEO);
  SDL_WM_SetCaption("L-system",NULL);
  SDL_SetVideoMode(width, height, 32, SDL_OPENGL);
  turtle_ = Turtle();
};

Canvas::~Canvas() {
  SDL_Quit();
}

SDL_EVENT Canvas::getEvent() {
  return event_;
}
