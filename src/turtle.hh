#pragma once

#include <stack>

struct point {
  float x;
  float y;
  float z;
};

struct state {
  point p;
  point vector[3];
};

class Turtle
{
  public:
    Turtle();
    ~Turtle();

    state getState();
    void setCoord(float x, float y, float z);

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

    void write_obj();

  private:
    state state_;
    int width_ = 1;
    bool pen_ = true;
    std::stack <state> s_;
};
