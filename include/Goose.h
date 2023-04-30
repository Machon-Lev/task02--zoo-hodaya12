#pragma once
#include <iostream>
#include <cstdlib>
#include "Animal.h"
#define ROWS 20
#define COLS 40
using namespace std;
class Goose : public Animal {
	char _Direction2;
public:
	Goose(const string& name, const Location& location) :Animal(name, location) { move(); }
	void printDetails() const override;
	char getInitial() const override;
	void turnVertically() override;
	void turnHorizontally() override;
	void step() override;
	void move() override;
};
