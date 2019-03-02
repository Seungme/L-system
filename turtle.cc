#include <cmath>
#include "turtle.h"
#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <iostream>

Turtle::Turtle() {
  state_.x = 0.0;
  state_.y = 0.0;
  state_.z = 0.0;
  state_.angle = 90;
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

  float newX = state_.x + distance * (cos(radian));
  float newY = state_.y + distance * (sin(radian));
  float newZ = 0;

  if (pen_ == true) {
    glBegin(GL_LINES);
      glVertex3f(state_.x, state_.y, state_.z);
      glVertex3f(newX, newY, newZ);
    glEnd();
  }

  setCoord(newX, newY, newZ);
}

void Turtle::turnRight(float angle) {
  setAngle(state_.angle - angle);
}

void Turtle::turnLeft(float angle) {
  setAngle(state_.angle + angle);
}

void Turtle::save() {
  s_.push(state_);
}

void Turtle::restore() {
  state s = s_.top();
  state_ = s;
  s_.pop();
}

