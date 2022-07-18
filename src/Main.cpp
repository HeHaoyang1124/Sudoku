#include "Sudoku.h"

int main() {
	Sudoku s;

	while (s.sudoku[0] <= 9)
	{
		s.ex();
		//s.Print();
		if (s.check())
		{
			if (s.ptr < &s.sudoku[80])
			{
				s.ptr++;
				continue;
			}
			else if (s.ptr == &s.sudoku[80])
			{

				s.Print();
				continue;
			}
		}
	}

	std::cin.get();
	return 0;
}