#include <cmath>
#include "turtle.h"
#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <iostream>

Turtle::Turtle() {
  state_.x = 0;
  state_.y = 0;
  state_.z = 0;
  state_.angle = 0;
  state_.vector[0] = 0;
  state_.vector[1] = 1;
  state_.vector[2] = 0;
  state_.axis = 'z';
};

state Turtle::getState() {
  return state_;
}

void Turtle::setCoord(float x, float y, float z) {
  state_.x = x;
  state_.y = y;
  state_.z = z;
}

void Turtle::setAngle(float angle) {
  state_.angle = angle;
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

float absolute(float x, float y, float z)
{
  return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}

void Turtle::move(float distance) {
  float radian = state_.angle * M_PI / 180;
  float vx, vy, vz;
  if (state_.axis == 'z') {
    vx = cos(radian) * state_.vector[0] - sin(radian) * state_.vector[1];
    vy = sin(radian) * state_.vector[0] + cos(radian) * state_.vector[1];
    vz = state_.vector[2];
  }
  else if (state_.axis == 'y')
  {
    vx = cos(radian) * state_.vector[0] + sin(radian) * state_.vector[2];
    vz = -sin(radian) * state_.vector[0] + cos(radian) * state_.vector[2];
    vy = state_.vector[1];
  }
  else
  {
    vy = cos(radian) * state_.vector[1] - sin(radian) * state_.vector[2];
    vz = sin(radian) * state_.vector[1] + cos(radian) * state_.vector[2];
    vx = state_.vector[0];
  }
  float length = absolute(vx, vy, vz);

  state_.vector[0] = vx/length;
  state_.vector[1] = vy/length;
  state_.vector[2] = vz/length;
  float newX = state_.x + distance * state_.vector[0];
  float newY = state_.y + distance * state_.vector[1];
  float newZ = state_.z + distance * state_.vector[2];

  if (pen_ == true) {
    glBegin(GL_LINES);
    glVertex3f(state_.x, state_.y, state_.z);
    glVertex3f(newX, newY, newZ);
    glEnd();
  }
  setCoord(newX, newY, newZ);
}

void Turtle::turn(float angle) {
  state_.axis = 'z';
  setAngle(angle);
}

void Turtle::pitch(float angle) {
  state_.axis = 'y';
  setAngle(angle);
}

void Turtle::roll(float angle) {
  state_.axis = 'x';
  setAngle(angle);
}

void Turtle::save() {
  s_.push(state_);
}

void Turtle::restore() {
  state s = s_.top();
  state_ = s;
  s_.pop();
}

