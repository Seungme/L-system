#pragma once

#include <stack>

struct state {
  float x;
  float y;
  int angle;
};

class Turtle
{
  public:
    Turtle();
  
    state getState();
    void setCoord(float x, float y);
    void setAngle(int angle);

    int getWidth();
    void setWidth(int);

    bool getPen();
    void setPen(bool pen);

    void move(float distance);
    void turnRight(int angle);
    void turnLeft(int angle);
    void save();
    void restore();

  private:
    state state_;
    int width_ = 1;
    bool pen_ = true;
    std::stack <state> s_;
};