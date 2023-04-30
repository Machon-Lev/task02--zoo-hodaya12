#include "..\include\Location.h"

std::ostream& operator<<(std::ostream& ostr, const Location& location)
{
    ostr << "(" << location.row << ", " << location.col << ")";
    return ostr;
}


Location& operator+=(Location& location1, const Location& location)
{
    location1.row += location.row;
    location1.col += location.col;
    return location1;
}

Location operator+(const Location& location1, const Location& location)
{
    return Location(location1.row + location.row, location1.col + location.col);
}

bool operator==(const Location& location1, const Location& location)
{
    return ((location1.row==location.row)&&(location1.col==location.col));
}

bool operator!=(const Location& location1, const Location& location)
{
    return !(location1==location);
}



