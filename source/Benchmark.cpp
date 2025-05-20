#include "Benchmark.hpp"

#include <chrono>
#include <iomanip>
#include <iostream>
#include <random>
#include <utility>

std::vector<int> benchmarking::vectorGenerator(size_t size, int minVal,
                                               int maxVal) {
  std::mt19937 gen(std::random_device{}());
  std::uniform_int_distribution<int> dist(minVal, maxVal);
  std::vector<int> vec(size);
  for (auto& num : vec) {
    num = dist(gen);
  }
  return vec;
}

std::pair<double, OBST> benchmarking::calExecutionTime(
    const std::vector<int>& key, const std::vector<int>& successWeight,
    const std::vector<int>& failureWeight, const std::string& algoName,
    const std::function<void(OBST&)>& algo) {
  auto start = std::chrono::high_resolution_clock::now();
  OBST tree(key, successWeight, failureWeight, [&]() { algo(tree); });
  tree.buildTree();
  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> duration = end - start;
  return {duration.count(), std::move(tree)};
}

void benchmarking::benchmark(int times, int inputSizes,
                             std::vector<int> successWeight,
                             std::vector<int> failureWeight) {
  bool printTree = inputSizes <= 20;
  std::cout << "===== OBST Benchmarking =====\n";
  std::cout << "Input size: " << inputSizes << ", Repetitions: " << times
            << "\n\n";

  int printRange;
  if (printTree)
    printRange = inputSizes;
  else
    printRange = 20;

  for (int i = 0; i < times; ++i) {
    std::cout << "----- Test Run " << (i + 1) << " -----\n";

    std::vector<int> key;

    for (int j = 0; j < inputSizes; ++j) {
      key.push_back((j + 1) * 10);
    }

    if (successWeight.empty() && failureWeight.empty()) {
      successWeight = vectorGenerator(inputSizes);
      failureWeight = vectorGenerator(inputSizes + 1);
    }

    std::cout << std::left << std::setw(17) << "Input Keys";
    std::cout << "[";
    std::cout << std::setw(4) << "";
    for (size_t t = 0; t < printRange; ++t) {
      std::cout << std::right << std::setw(4) << key[t];
    }
    if (printRange < inputSizes)
      std::cout << std::right << std::setw(4) << "...";
    std::cout << "]" << std::endl;

    std::cout << std::left << std::setw(17) << "Success Weights";
    std::cout << "[";
    std::cout << std::setw(4) << "";
    for (size_t t = 0; t < printRange; ++t) {
      std::cout << std::right << std::setw(4) << successWeight[t];
    }
    if (printRange < inputSizes)
      std::cout << std::right << std::setw(4) << "...";
    std::cout << "]" << std::endl;

    std::cout << std::left << std::setw(17) << "Failure Weights";
    std::cout << "[";
    for (size_t t = 0; t < printRange + 1; ++t) {
      std::cout << std::right << std::setw(4) << failureWeight[t];
    }
    if (printRange < inputSizes)
      std::cout << std::right << std::setw(4) << "...";
    std::cout << "]" << std::endl;
    std::cout << std::endl;

    std::cout << std::fixed << std::setprecision(6);
    if (!printTree)
      std::cout << "Skipping tree printout for inputs larger than 20 elements."
                << std::endl
                << std::endl;

    auto [memoTime, memoTree] =
        calExecutionTime(key, successWeight, failureWeight, "Memoization",
                         [](OBST& tree) { tree.memoization(); });
    memoTree.buildTree();
    if (printTree) {
      std::cout << "[Memoization Tree]\n";
      memoTree.printTree();
    }
    std::cout << "Memoization tree cost: " << memoTree.getTreeSearchCost()
              << "\n";
    std::cout << "Memoization time: " << memoTime << " seconds\n\n";

    auto [tabTime, tabTree] =
        calExecutionTime(key, successWeight, failureWeight, "Tabulation",
                         [](OBST& tree) { tree.tabulation(); });
    tabTree.buildTree();
    if (printTree) {
      std::cout << "[Tabulation Tree]\n";
      tabTree.printTree();
    }
    std::cout << "Tabulation tree cost: " << tabTree.getTreeSearchCost()
              << "\n";
    std::cout << "Tabulation time: " << tabTime << " seconds\n\n";

    auto [knuthTime, knuthTree] =
        calExecutionTime(key, successWeight, failureWeight, "Knuth Algorithm",
                         [](OBST& tree) { tree.knuthAlgo(); });
    knuthTree.buildTree();
    if (printTree) {
      std::cout << "[Knuth Algorithm Tree]\n";
      knuthTree.printTree();
    }
    std::cout << "Knuth Algorithm tree cost: " << knuthTree.getTreeSearchCost()
              << "\n";
    std::cout << "Knuth Algorithm time: " << knuthTime << " seconds\n";
    key.clear();
    successWeight.clear();
    failureWeight.clear();
    std::cout << "----------------------------\n\n";
  }
}
