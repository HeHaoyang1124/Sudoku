#include "Sudoku.h"
#include <cstring>
#include <iostream>

Sudoku::Sudoku()
{

	sudoku = new unsigned[81];
	memset(sudoku, 0, 81 * sizeof(unsigned));

	available = new bool[81];
	memset(available, true, 81 * sizeof(bool));

	memset(box, 0, sizeof(box));

	Input();

	for (index = 0; index < 81; index++)
	{
		if (available[index])
			break;
	}

	for (unsigned i = 0; i < 81; i++)
	{
		if (!available[i])
		{
			unsigned column = index % 9;
			unsigned line = index / 9;
			unsigned palace = column / 3 + 3 * (line / 3);
			unsigned block = column % 3 + 3 * (line % 3);
			box[palace][block] = sudoku[i];
		}
	}
}

void Sudoku::Print()
{
	for (unsigned i = 0; i < 9; i++)
	{
		for (unsigned j = 0; j < 9; j++)
		{
			printf("%d ", sudoku[j + 9 * i]);
		}
		printf("\n");
	}
	std::cin.get();
	std::cout << std::endl;
}

void Sudoku::ex()
{
	sudoku[index]++;
	while (sudoku[index] > 9)
	{
		sudoku[index] = 0;
		unsigned column = index % 9;
		unsigned line = index / 9;
		unsigned palace = column / 3 + 3 * (line / 3);
		unsigned block = column % 3 + 3 * (line % 3);
		box[palace][block] = 0;

		if (find_available(false))
			sudoku[index]++;
	}
}

bool Sudoku::Check()
{
	//get column, line
	//    x     , y
	unsigned column = index % 9;
	unsigned line = index / 9;
	unsigned palace = column / 3 + 3 * (line / 3);
	unsigned block = column % 3 + 3 * (line % 3);

	//Check line
	for (unsigned i = 0; i < 9; i++)
	{
		if (sudoku[i + 9 * line] == sudoku[index] && column != i)
		{
			return false;
		}
	}


	//Check column
	for (unsigned i = 0; i < 9; i++)
	{
		if (sudoku[column + i * 9] == sudoku[index] && line != i)
		{
			return false;
		}
	}

	//Check palace
	for (unsigned i = 0; i < 9; i++)
	{
		if (box[palace][i] == sudoku[index] && i != block)
		{
			return false;
		}
	}


	box[palace][block] = sudoku[index];
	return true;
}

void Sudoku::Input()
{
	for (int i = 0; i < 81; i++)
	{
		scanf_s("%d", &sudoku[i]);
		if (sudoku[i] <= 9 && sudoku[i] >= 1)
		{
			available[i] = false;
		}
		else
		{
			sudoku[i] = 0;
		}
	}
}

bool Sudoku::find_available(bool afterthis)
{
	if (afterthis == true)
	{
		while (available[++index] == false && index < 80) {}
		if (available[index] == true)
			return true;
		else return false;

	}

	else
	{
		while (available[--index] == false && index > 0) {}
		if (available[index] == true)
			return true;
		else return false;
	}
}

void Sudoku::Solve()
{
	while (sudoku[0] <= 9)
	{
		ex();
		//s.Print();

		if (Check())
		{
			if (index < 80)
			{
				if (find_available(true))
					continue;
			}
			else if (index == 80)
			{

				Print();
				break;
			}
		}
	}
}