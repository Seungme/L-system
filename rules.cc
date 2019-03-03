
#include <iostream>
#include "rules.h"

Rules::Rules(std::string axiom, const std::map<char, std::string>& productions):
instructions_(axiom), productions_(productions) {}

void Rules::iterate(const unsigned& iter) {

  for (unsigned i = 0; i < iter; i++) {
    std::string finalInstruct = "";
    for (unsigned j = 0; j < instructions_.length(); j++) {
      char c = instructions_[j];
      if (productions_.find(c) != productions_.end())
        finalInstruct += productions_.find(c)->second;
      else
        finalInstruct += c;
    }
    instructions_ = finalInstruct;

  }
}

void Rules::interpret(const float& distance, const float& angle){
  for (unsigned i = 0; i < instructions_.length(); i++){
    char c = instructions_[i];
    if (c == 'F') {
      setPen(true);
      move(distance);
    }
    else if (c == 'f') {
      setPen(false);
      move(distance);
    }
    else if (c == '-')
      turn(angle);
    else if (c == '+')
      turn(-angle);
    else if (c == '[')
      save();
    else if (c == ']')
      restore();
  }
}
