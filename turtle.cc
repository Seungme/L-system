#include <cmath>
#include <fstream>
#include "turtle.h"
#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <iostream>
#include <stdlib.h>
#include <string>

//initialize the turtle with basis for vector space
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

//multiply a vector by a scalar
point multiply(float n, point p) {
   return {p.x * n, p.y * n, p.z * n};
}

//add two vectors
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
    this->save();
    glEnd();
  }
  state_.p = p;
}
me/parallels/Documents/L-system/turtle.obj' 

void Turtle::turn(float angle) {
  float radian = angle * M_PI / 180;

  point vx = plus(multiply(cos(radian), state_.vector[0]),
                  multiply(sin(radian), state_.vector[1]));
  point vy = plus(multiply(-sin(radian), state_.vector[0]),
                  multiply(cos(radian), state_.vector[1]));

  state_.vector[0] = vx;
  state_.vector[1] = vy;
}

void Turtle::pitch(float angle) {
  float radian = angle * M_PI / 180;

  point vx =  plus(multiply(cos(radian), state_.vector[0]),
                   multiply(-sin(radian), state_.vector[2]));
  point vz =  plus(multiply(sin(radian), state_.vector[0]),
                   multiply(cos(radian), state_.vector[2]));

  state_.vector[0] = vx;
  state_.vector[2] = vz;
}

void Turtle::roll(float angle) {
  float radian = angle * M_PI / 180;

  point vy =  plus(multiply(cos(radian), state_.vector[1]),
                   multiply(sin(radian), state_.vector[2]));
  point vz =  plus(multiply(-sin(radian), state_.vector[1]),
                   multiply(cos(radian), state_.vector[2]));

  state_.vector[1] = vy;
  state_.vector[2] = vz;
}

//use stack to save the current state
void Turtle::save() {
  s_.push(state_);
}

//get the last added element
void Turtle::restore() {
  state s = s_.top();
  state_ = s;
  s_.pop();
}

void Turtle::write_obj() {
  remove("turtle.obj");
  std::ofstream file("turtle.obj");
  
  std::string data;
  int stack_len = 0;

  while(!s_.empty())
  {
    state curr_s = s_.top();
    s_.pop();
    point curr_pt = curr_s.p;
    data += "v " + std::to_string(curr_pt.x) + ' ' + std::to_string(curr_pt.y) + ' ' + std::to_string(curr_pt.z) + '\n';
    stack_len += 1;
  }

  data += '\n';

  for (int i = 0; i < stack_len-1; i++) {
    data += "l " + std::to_string(i+1) + ' ' + std::to_string(i+2) + '\n';
  }

  file << data;
  file.close();
}

Turtle::~Turtle() {
  write_obj();
}
