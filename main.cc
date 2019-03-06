#include <GL/gl.h>
#include <GL/glu.h>
#include <SDL/SDL.h>
#include <map>

#include "rules.h"
#include "turtle.h"
#include <iostream>

void load(std::string filename) {
    Rules r(filename);
    r.generate();
}

int main(int argc, char **argv)
{
  if (argc < 2) {
    std::cout << "Please enter a filename" << std::endl;
    return 1;
  }

  SDL_Init(SDL_INIT_VIDEO);
  SDL_WM_SetCaption("Mon premier programme OpenGL !",NULL);
  SDL_SetVideoMode(600, 600, 32, SDL_OPENGL);

  bool continuer = true;
  SDL_Event event;
  glMatrixMode( GL_PROJECTION );
  glLoadIdentity();
  gluPerspective(70,1,1,1000);
  glEnable(GL_DEPTH_TEST);

  while (continuer)
  {
    SDL_WaitEvent(&event);
    switch(event.type)
    {
      case SDL_QUIT:
        continuer = false;
    }
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(3,4,2,0,0,0,0,0,1);

    load(argv[1]);

    glFlush();
    SDL_GL_SwapBuffers();
  }

  SDL_Quit();

  return 0;
}
