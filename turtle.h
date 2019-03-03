#pragma once

#include <stack>

struct state {
  float x;
  float y;
  float z;
  float angle;
  float vector[3];
};

class Turtle
{
  public:
    Turtle();

    state getState();
    void setCoord(float x, float y, float z);
    void setAngle(float angle);

    int getWidth();
    void setWidth(int);

    bool getPen();
    void setPen(bool pen);

    void move(float distance);
    void turn(float angle);
    void pitch(float angle);
    void roll(float angle);
    void save();
    void restore();

  private:
    state state_;
    int width_ = 1;
    bool pen_ = true;
    std::stack <state> s_;
};
