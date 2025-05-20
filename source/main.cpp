#include <iostream>

#include "Benchmark.hpp"

int main() {
  int choice;
  std::cout << "===== OBST Benchmark Menu =====\n";
  std::cout << "1. Run benchmark with random input\n";
  std::cout << "2. Run benchmark with custom input\n";
  std::cout << "Select an option (1 or 2): ";
  std::cin >> choice;

  int inputSize, times;
  if (choice == 1) {
    std::cout << "Enter input size (Note: Trees will only be printed if size "
                 "is 20 or less): ";
    std::cin >> inputSize;
    std::cout << "Enter number of benchmark repetitions: ";
    std::cin >> times;
    benchmarking::benchmark(times, inputSize);
  } else if (choice == 2) {
    std::cout << "Enter the number of keys: ";
    std::cin >> inputSize;

    int keys = inputSize;
    std::vector<int> successWeights(inputSize);
    std::vector<int> failureWeights(inputSize + 1);

    std::cout << "Keys will be automatically generated as 10, 20, 30, ...\n";

    std::cout << "Please enter " << inputSize
              << " success weights (space-separated): ";
    for (int i = 0; i < inputSize; ++i) std::cin >> successWeights[i];

    std::cout << "Please enter " << inputSize + 1
              << " failure weights (space-separated): ";
    for (int i = 0; i <= inputSize; ++i) std::cin >> failureWeights[i];

    benchmarking::benchmark(1, keys, successWeights, failureWeights);
  } else {
    std::cout << "Invalid option. Exiting.\n";
  }

  return 0;
}
