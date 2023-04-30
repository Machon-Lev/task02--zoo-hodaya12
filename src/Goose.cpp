#include "..\include\Goose.h"

void Goose::printDetails() const
{
	cout << "name: " << _Name << "  type: Goose" << "  Location: " << _Location << "\n";
}

char Goose::getInitial() const
{
	return 'G';
}

void Goose::turnVertically()
{
	if (_Direction2 == '+')
		_Direction2 = '-';
	if (_Direction2 == '-')
		_Direction2 = '+';
}

void Goose::turnHorizontally()
{
	if (_Direction == '+')
		_Direction = '-';
	if (_Direction == '-')
		_Direction = '+';
}

void Goose::step()
{

	if (_CanMove) {
		int row, col;
		if (_Direction == '+')
			col = _Location.col+1;
		if (_Direction == '-')
			col = _Location.col-1;
		if (_Direction2 == '+')
			row = _Location.row+ 1;
		if (_Direction2 == '-')
			row = _Location.row -1;
		if (col < 0 || col >= COLS) {
			if (_Direction == '+')
				_Direction = '-';
			else
				_Direction = '+';
			step();
			
		}
		else {
			if (row < 0 || row >= ROWS) {
				if (_Direction2 == '+')
					_Direction2 = '-';
				else
					_Direction2 = '+';
				step();
			}
			else
			{
				_Location = Location(row, col);
				if (_Direction2 == '+')
					_Direction2 = '-';
				else
					_Direction2 = '+';
			}

		}
	}
	
}

void Goose::move()
{
	Animal::move();
	_Direction2 = (std::rand() % 2 == 0) ? '+' : '-';
	
}
