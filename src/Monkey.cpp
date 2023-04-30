#include "..\include\Monkey.h"

void Monkey::printDetails() const
{
	cout << "name: " << _Name << "  type: Monkey" << "  Location: " << _Location << "\n";
}

char Monkey::getInitial() const
{
	return 'M';
}

void Monkey::turnVertically()
{
	if (v_h == 'v') {
		if (_Direction == '+')
			_Direction = '-';
		if (_Direction == '-')
			_Direction = '+';
	}

}

void Monkey::turnHorizontally()
{
	if (v_h == 'h') {
		if (_Direction == '+')
			_Direction = '-';
		if (_Direction == '-')
			_Direction = '+';
	}
}

void Monkey::step()
{
	if (_CanMove) {
		if (v_h == 'v') {
			if (_Direction == '-')
				_Location += Location(size_step * -1, 0);
			else
				_Location += Location(size_step, 0);
		}
		if (v_h == 'h') {
			if (_Direction == '-')
				_Location += Location(0, size_step * -1);
			else
				_Location += Location(0, size_step);
		}
		if (_Location.row >= ROWS)
			_Location.row = ROWS - 1;
		if (_Location.row < 0)
			_Location.row = 0;
		if (_Location.col >= COLS)
			_Location.col = COLS - 1;
		if (_Location.col < 0)
			_Location.col = 0;
		turns++;
		if (turns == 5) {
			v_h = (std::rand() % 2 == 0) ? 'v' : 'h';
			size_step = (std::rand() % 2 == 0) ? 1 : 2;
			_Direction = (std::rand() % 2 == 0) ? '+' : '-';
			turns = 0;
		}
	}
	
	
	
}

void Monkey::move()
{
	_CanMove = true;
}



