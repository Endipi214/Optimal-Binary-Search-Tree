#include <iostream>

#include "Benchmark.hpp"

int main() {
  int inputSize, times;
  std::cout << "Enter input size (Note: Trees will only be printed if size is "
               "20 or less): ";
  std::cin >> inputSize;
  std::cout << "Enter number of benchmark repetitions: ";
  std::cin >> times;
  benchmarking::benchmark(times, inputSize);
  return 0;
}
