// ex02.cpp : Defines the entry point for the application.
//


#include "Zoo.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#define ROWS 20
#define COLS 40
using namespace std;

int main()
{
	std::srand(std::time(nullptr));
	cout << "Welcome to the zoo!" << endl;
	Zoo z;
	z.run();



	


	return 0;
}
