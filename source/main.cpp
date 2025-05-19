#include <iostream>
#include <vector>

#include "OptimalBinarySearchTree.hpp"

int main() {
  // Example data (same as textbook examples):
  std::vector<int> keys = {10, 20, 30, 40, 50};
  std::vector<int> successWeight = {15, 10, 5, 10, 20};   // p1 to p4
  std::vector<int> failureWeight = {5, 10, 5, 5, 5, 10};  // q0 to q4

  // === Test with Memoization ===
  OBST treeMemo(keys, successWeight, failureWeight, []() {});
  treeMemo.memoization();
  treeMemo.buildTree();
  std::cout << "[Memoization] cost: \n";
  treeMemo.getExpectedSearchCost();
  std::cout << "[Memoization] total prob: \n";
  treeMemo.getTotalProb();
  std::cout << "[Memoization] root: \n";
  treeMemo.getRoot();
  std::cout << "[Memoization]";
  treeMemo.NLR();
  std::cout << std::endl;

  // === Test with Tabulation ===
  OBST treeTab(keys, successWeight, failureWeight, []() {});
  treeTab.tabulation();
  treeTab.buildTree();
  std::cout << "[Tabulation] cost: \n";
  treeTab.getExpectedSearchCost();
  std::cout << "[Tabulation] total prob: \n";
  treeTab.getTotalProb();
  std::cout << "[Tabulation] root: \n";
  treeTab.getRoot();
  std::cout << "[Tabulation]";
  treeTab.NLR();
  std::cout << std::endl;

  // === Test with Knuth's optimization ===
  OBST treeKnuth(keys, successWeight, failureWeight, []() {});
  treeKnuth.knuthAlgo();
  treeKnuth.buildTree();
  std::cout << "[Knuth] cost: \n";
  treeKnuth.getExpectedSearchCost();
  std::cout << "[Knuth] total prob: \n";
  treeKnuth.getTotalProb();
  std::cout << "[Knuth] root: \n";
  treeKnuth.getRoot();
  std::cout << "[Knuth]";
  treeKnuth.NLR();
  std::cout << std::endl;

  return 0;
}
