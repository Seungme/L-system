#pragma once

#include <string>
#include <vector>

#include "turtle.hh"

struct Production {
  std::string pred;
  std::string succ;
};

class Rules : public Turtle {
  public:
    Rules(std::string file);
    void generate();
    void iterate();
    void interpret();

  private:
    std::vector<Production> prod_;
    std::string instructions_;
    float distance_;
    float angle_;
    std::string file_;
    unsigned iter_;
};
