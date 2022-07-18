#pragma once
#include <iostream>
#include <vector>

class Sudoku
{
public:
	unsigned* sudoku;
	unsigned  box[9][9];

	unsigned* ptr;

public:
	Sudoku();

	void ex();
	bool check();
	void Print();

};

