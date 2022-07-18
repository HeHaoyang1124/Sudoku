#include "Sudoku.h"
#include <cstring>
#include <iostream>

Sudoku::Sudoku()
{

	sudoku = new unsigned[81];
	memset(sudoku, 0, 81 * sizeof(unsigned));

	memset(box, 0, sizeof(box));

	ptr = sudoku;
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
}

void Sudoku::ex()
{
	(*ptr)++;
	while (*ptr > 9)
	{
		*ptr = 0;
		(*(--ptr))++;
	}
}

bool Sudoku::check()
{
	//get column, line
	//    x     , y
	unsigned column = (ptr - sudoku) % 9;
	unsigned line = (ptr - sudoku) / 9;
	unsigned palace = column / 3 + 3 * (line / 3);
	unsigned block = column % 3 + 3 * (line % 3);

	//check line
	for (unsigned i = 0; i < column; i++)
	{
		if (sudoku[i + 9 * line] == *ptr)
		{
			return false;
		}
	}


	//check column
	for (unsigned i = 0; i < line; i++)
	{
		if (sudoku[column + i * 9] == *ptr)
		{
			return false;
		}
	}

	//check palace
	for (unsigned i = 0; i < block; i++)
	{
		if (box[palace][i] == *ptr)
		{
			return false;
		}
	}
	box[palace][block] = *ptr;
	return true;
}