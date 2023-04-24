#pragma once
#include <iostream>
#include <cstdlib>
#include <vector>
#include "Animal.h"
#include "Lion.h"
#include "Monkey.h"
#include "Goose.h"
using namespace std;
class Zoo {
	std::vector<std::unique_ptr<Animal>> _List;
	void stop(int);
	void move(int);
	void create(char, string);
	void del(int);
	void delAll(char);
	void help();
	void step();
	void print_map();
	void print_list();
public:
	Zoo();
	void run();
};
