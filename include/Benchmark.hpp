#include <functional>
#include <string>
#include <vector>

#include "OptimalBinarySearchTree.hpp"

namespace benchmarking {
std::vector<int> vectorGenerator(size_t size, int minVal = 0, int maxVal = 100);
std::pair<double, OBST> calExecutionTime(
    const std::vector<int>& key, const std::vector<int>& successWeight,
    const std::vector<int>& failureWeight, const std::string& algoName,
    const std::function<void(OBST&)>& algo);
void benchmark(int times, int inputSizes, std::vector<int> successWeight = {},
               std::vector<int> failureWeight = {});
}  // namespace benchmarking
