#pragma once
#include <chrono>
#include <iostream>
#include <thread>

class Timer {
private:
  std::chrono::time_point<std::chrono::steady_clock> start, end;

public:
  Timer() { start = std::chrono::high_resolution_clock::now(); }
  ~Timer() {
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> Duration = end - start;
    std::cout << "-----------------" << std::endl
              << "took time:" << Duration.count() << "s" << std::endl;
  }
};
