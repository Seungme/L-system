#include <cmath>
#include "turtle.h"
#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <iostream>
#include <stdlib.h>

Turtle::Turtle() {
  state_.p = {0, 0, 0};
  state_.vector[0] = {1, 0, 0};
  state_.vector[1] = {0, 1, 0};
  state_.vector[2] = {0, 0, 1};
}

state Turtle::getState() {
  return state_;
}

void Turtle::setCoord(float x, float y, float z) {
  state_.p = {x, y, z};
}

int Turtle::getWidth() {
  return width_;
}

void Turtle::setWidth(int width) {
  width_ = width;
}

bool Turtle::getPen() {
  return pen_;
}

void Turtle::setPen(bool pen) {
  pen_ = pen;
}

float absolute(point p)
{
  return sqrt(pow(p.x, 2) + pow(p.y, 2) + pow(p.z, 2));
}

point multiply(float n, point p) {
   return {p.x * n, p.y * n, p.z * n};
}

point plus(point p1, point p2) {
 return { p1.x + p2.x, p1.y + p2.y, p1.z + p2.z };
}

void Turtle::move(float distance) {

  point p = plus(state_.p, multiply(distance, state_.vector[0]));

  if (pen_ == true) {
    glBegin(GL_LINES);
    glColor3ub(rand() % 256, rand() % 256, rand() % 256);
    glVertex3f(state_.p.x, state_.p.y, state_.p.z);
    glVertex3f(p.x, p.y, p.z);
    glEnd();
  }
  state_.p = p;
}

void Turtle::turn(float angle) {
  float radian = angle * M_PI / 180;

  point vx = plus(multiply(cos(radian), state_.vector[0]),  multiply(sin(radian), state_.vector[1]));
  point vy = plus(multiply(-sin(radian), state_.vector[0]), multiply(cos(radian), state_.vector[1]));

  state_.vector[0] = vx;
  state_.vector[1] = vy;
}

void Turtle::pitch(float angle) {
  float radian = angle * M_PI / 180;

  point vx =  plus(multiply(cos(radian), state_.vector[0]), multiply(-sin(radian), state_.vector[2]));
  point vz =  plus(multiply(sin(radian), state_.vector[0]), multiply(cos(radian), state_.vector[2]));

  state_.vector[0] = vx;
  state_.vector[2] = vz;
}

void Turtle::roll(float angle) {
  float radian = angle * M_PI / 180;

  point vy =  plus(multiply(cos(radian), state_.vector[1]), multiply(sin(radian), state_.vector[2]));
  point vz =  plus(multiply(-sin(radian), state_.vector[1]), multiply(cos(radian), state_.vector[2]));

  state_.vector[1] = vy;
  state_.vector[2] = vz;
}

void Turtle::save() {
  s_.push(state_);
}

void Turtle::restore() {
  state s = s_.top();
  state_ = s;
  s_.pop();
}
