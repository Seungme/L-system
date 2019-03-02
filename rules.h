#pragma once

#include <string>
#include <map>

#include "turtle.h"

class Rules : public Turtle {
  public:
    Rules(std::string axiom, const std::map<char, std::string>& productions);
    void iterate(const unsigned& iter);
    void interpret(const float &distance, const int &angle);

  private:
    std::string instructions_;
    const std::map<char, std::string>& productions_;
};
