#include <GL/gl.h>
#include <GL/glu.h>
#include <SDL/SDL.h>
#include <map>

#include "rules.h"
#include "turtle.h"

int main(int argc, char *argv[])
{
  SDL_Init(SDL_INIT_VIDEO);
  SDL_WM_SetCaption("Mon premier programme OpenGL !",NULL);
  SDL_SetVideoMode(600, 600, 32, SDL_OPENGL);

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
    const std::map<char, std::string>& prod = {{'F', "FF"}, {'X', "F[+X][-X]FX"}};
    //const std::map<char, std::string>& prod = {{'F', "F+f-FF+F+FF+Ff+FF-f+FF-F-FF-Ff-FFF"}, {'f', "ffffff"}};

    Rules r("X", prod);
    r.iterate(7);
    r.interpret(0.003, 25.7);

    glFlush();
    SDL_GL_SwapBuffers();
  }

  SDL_Quit();

  return 0;
}
