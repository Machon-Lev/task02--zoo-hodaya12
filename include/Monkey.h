#pragma once
#include <iostream>
#include <cstdlib>
#include "Animal.h"
#define ROWS 20
#define COLS 40
using namespace std;
class Monkey : public Animal {
	int turns;
	char v_h;
	int size_step;
public:
	Monkey(const string& name, const Location& location) :Animal(name, location), turns(0), v_h('v'), size_step(1){}
	void printDetails() const override;
	char getInitial() const override;
	void turnVertically() override;
	void turnHorizontally() override;
	void step() override;
	void move() override;

	

};
