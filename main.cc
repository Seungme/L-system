#include <GL/gl.h>
#include <GL/glu.h>
#include <SDL/SDL.h>
#include <map>

#include "rules.h"
#include "turtle.h"
#include <iostream>

void load() {
    Rules r("input.txt");
    r.generate();
}

int main()
{
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

    load();

    glFlush();
    SDL_GL_SwapBuffers();
  }

  SDL_Quit();

  return 0;
}
