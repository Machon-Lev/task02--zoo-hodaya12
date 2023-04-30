#include "..\include\Lion.h"




void Lion::printDetails() const
{
	cout << "name: " << _Name  << "  type: Lion" << "  Location: " << _Location<<"\n";
	
}

char Lion::getInitial() const
{
	return 'L';
}

void Lion::turnVertically()
{
}

void Lion::turnHorizontally()
{
	if (_Direction == '+')
		_Direction = '-';
	if (_Direction == '-')
		_Direction = '+';



}

void Lion::step()
{
	if (_CanMove) {
		int col;
		if (_Direction == '+') 
			col = (_Location.col + 2);
		
		if (_Direction == '-') 
			col = (_Location.col - 2);
		
		if (col < 0 || col >= COLS) {
			if (_Direction == '+') 
				_Direction = '-';
			else 
				_Direction = '+';
			
			step();
		}
		else
			_Location = Location(_Location.row, col);
	}
	
	
		
	
	
}


