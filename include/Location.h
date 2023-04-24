#pragma once
#include <iostream>
#include <cstdlib>

struct Location {
    int row;
    int col;

};

std::ostream& operator<<(std::ostream& ostr, const Location& location);
Location& operator+=(Location& location1,const Location& location);
Location operator+(const Location& location1,const Location& location);
bool operator==(const Location& location1, const Location& location);
bool operator!=(const Location& location1, const Location& location);