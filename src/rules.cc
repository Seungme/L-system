#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

#include "rules.hh"

Rules::Rules(std::string file): file_(file) {}

//parse the input file
void Rules::generate() {
	std::ifstream in(file_);
	std::string line;
	std::string key, name;

	//get the basic configuration
	for (int i = 0; i < 4; i++)
	{
		std::getline(in, line);
		std::istringstream iss(line);
		iss >> name >> key;
		if (name == "Angle:")
			angle_ = std::stof(key);
		else if (name == "Distance:")
			distance_ = std::stof(key);
		else if (name == "Iteration:")
			iter_ = std::stoi(key);
		else if (name == "Axiom:")
			instructions_ = key;
	}

	//get the productions
	while (std::getline(in, line)) {
		std::string delimiter = "->";
		auto index = line.find(delimiter);
		Production p;
		p.pred = line.substr(0, index - 1);
		p.succ = line.substr(index + delimiter.length() + 1);
		prod_.push_back(p);
	}

	iterate();
}

//iterate the axiom and create the final instruction
void Rules::iterate() {
	for (unsigned i = 0; i < iter_; i++) {
		std::string finalInstruct = "";
		for (unsigned j = 0; j < instructions_.length(); j++) {
			std::string c(1, instructions_[j]);
			auto it = std::find_if(prod_.begin(), prod_.end(),
					[c](const Production& prod) -> bool { return prod.pred == c; });
			if (it != prod_.end())
			{
				auto index = std::distance(prod_.begin(), it);
				auto elm = prod_.at(index);
				finalInstruct += elm.succ;
			}
			else
				finalInstruct += c;
		}
		instructions_ = finalInstruct;
	}
	interpret();
}

//interpret the final instruction
void Rules::interpret(){
	for (unsigned i = 0; i < instructions_.length(); i++){
		char c = instructions_[i];
		if (c == 'F') {
			setPen(true);
			move(distance_);
		}
		else if (c == 'f') {
			setPen(false);
			move(distance_);
		}
		else if (c == '+')
			turn(angle_);
		else if (c == '-')
			turn(-angle_);
		else if (c == '&')
			pitch(angle_);
		else if (c == '^')
			pitch(-angle_);
		else if (c == '>')
			roll(angle_);
		else if (c == '<')
			roll(-angle_);
		else if (c == '|')
			turn(180);
		else if (c == '[')
			save();
		else if (c == ']')
			restore();
	}
}
