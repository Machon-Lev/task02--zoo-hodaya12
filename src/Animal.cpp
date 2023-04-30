#include "..\include\Animal.h"

void Animal::stop()
{
	_CanMove = false;
}

void Animal::move()
{
	if (!_CanMove) 
		_Direction = (std::rand() % 2 == 0) ? '+' : '-';
	_CanMove = true;
		
	
}

Location Animal::getLocation() const
{
	return _Location;
}

Animal::Animal(const string& name,const Location& location):_Name(name),_Location(location)
{
	_CanMove = false;
	move();
}
