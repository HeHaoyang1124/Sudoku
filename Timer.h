#pragma once
#include <iostream>
#include <thread>
#include <chrono>

class Timer
{
private:
	std::chrono::time_point<std::chrono::steady_clock> start, end;
public:
	Timer()
	{
		start = std::chrono::high_resolution_clock::now();
	}
	~Timer()
	{
		end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> Duration = end - start;
		std::cout << Duration.count() << std::endl;
	}
};
