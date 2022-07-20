#pragma once
#include <iostream>
#include <vector>

class Sudoku
{
public:
	unsigned* sudoku;
	unsigned  box[9][9];

	unsigned index;

	bool* available;

public:
	Sudoku();

	void ex();
	bool Check();
	void Print();
	void Input();

	bool find_available(bool afterthis = true);

	void Solve();
};

