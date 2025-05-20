#pragma once

#include <functional>
#include <vector>

#include "BinarySearchTree.hpp"

class OBST : public BST {
 private:
  // Input
  std::vector<int> key;
  std::vector<double> successWeight;
  std::vector<double> failureWeight;
  int nTreeNode;

  // Processed data
  std::vector<std::vector<double>> expectedSearchCost;
  std::vector<std::vector<double>> totalProbaility;
  std::vector<std::vector<int>> sufficientRoot;

  // Helper\Initialize Function
  void normalizeWeight(const std::vector<int>& successWeightRaw,
                       const std::vector<int>& failureWeightRaw);
  void preCalculateTotalProb();
  double memoizationHelper(int i, int j);
  void initMatrices(const std::function<void()>& algo);

 public:
  OBST(const std::vector<int>& key, const std::vector<int>& successWeight,
       const std::vector<int>& failureWeight,
       const std::function<void()>& algo);
  virtual ~OBST();

  // Build function
  void knuthAlgo();
  void memoization();
  void tabulation();
  TreeNode* buildSubtree(int i, int j);
  TreeNode* buildTree();

  // Queries
  double getTreeSearchCost() const;

  // Insertion and Deletion
  void insert(int key) override;
  void remove(int key) override;
};
