#pragma once
#include <iostream>
#include <cstdlib>
#include "Location.h"

using namespace std;
class Animal {
protected:
	string _Name;
	Location _Location;
	bool _CanMove;
	char _Direction;

public:
	virtual void printDetails() const = 0;
	virtual char getInitial() const = 0;
	virtual void turnVertically() = 0;
	virtual void turnHorizontally() = 0;
	virtual void step() = 0;
	void stop();
	virtual void move();
	Location getLocation() const;
	Animal(const string&, const Location&);
};
