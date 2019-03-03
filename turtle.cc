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

void Turtle::move(float distance) {
  float radian = state_.angle * M_PI / 180;

  float vx =  cos(radian) * state_.vector[0] - sin(radian) * state_.vector[1];
  float vy =  sin(radian) * state_.vector[0] + cos(radian) * state_.vector[1];

  float length = sqrt(pow(vx, 2) + pow(vy, 2));

  state_.vector[0] = vx/length;
  state_.vector[1] = vy/length;
  float newX = state_.x + distance * state_.vector[0];
  float newY = state_.y + distance * state_.vector[1];

  if (pen_ == true) {
    glBegin(GL_LINES);
    glVertex2f(state_.x, state_.y);
    glVertex2f(newX, newY);
    glEnd();
  }

  setCoord(newX, newY, 0);
}

void Turtle::turn(float angle) {
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

