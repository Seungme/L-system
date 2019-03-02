#include <GL/gl.h>
#include <GL/glu.h>
#include <SDL/SDL.h>

#include "canvas.h"

int main(int argc, char *argv[]) 
{ 
  Canvas canvas(640, 480);

  bool continuer = true;
  SDL_Event event;

  while (continuer)
  {
    SDL_WaitEvent(&event);
    switch(event.type)
    {
      case SDL_QUIT:
      continuer = false;
    }

    glClear(GL_COLOR_BUFFER_BIT);

    
    const std::map<char, std::string>& prod = {{'F', "F-F+F+FF-F-F+F"}};

    Rules r("F-F-F-F", prod);
    r.iterate(3);
    r.interpret(2, 90);

    glFlush();
    SDL_GL_SwapBuffers();
  }

  return 0;
}
