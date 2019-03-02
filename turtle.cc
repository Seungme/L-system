#include <cmath>
#include "turtle.h"
#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <iostream>

Turtle::Turtle() {
  state_.x = 0.0;
  state_.y = 0.0;
  state_.angle = 90;
};

state Turtle::getState() {
  return state_;
}

void Turtle::setCoord(float x, float y) {
  state_.x = x;
  state_.y = y;
}

void Turtle::setAngle(int angle) {
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
  float newX;
  float newY;


  newX = state_.x + distance * cos(state_.angle * M_PI / 180);
  newY = state_.y + distance * sin(state_.angle * M_PI / 180);

  if (pen_ == true) {
    glBegin(GL_LINES);
      glVertex2f(state_.x, state_.y);
      glVertex2f(newX, newY);
    glEnd();
  }

  setCoord(newX, newY);
}

void Turtle::turnRight(int angle) {
  setAngle(state_.angle - angle);
}

void Turtle::turnLeft(int angle) {
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

