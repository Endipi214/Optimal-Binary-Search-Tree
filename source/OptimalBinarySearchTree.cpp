#include "OptimalBinarySearchTree.hpp"

#include <cmath>
#include <iostream>
#include <limits>

// Helper\Initialize Function
void OBST::normalizeWeight(const std::vector<int>& successWeightRaw,
                           const std::vector<int>& failureWeightRaw) {
  // Compute total sum of all weights
  int totalSum = 0;
  for (int val : successWeightRaw) totalSum += val;
  for (int val : failureWeightRaw) totalSum += val;

  // Resize internal vectors if needed
  this->nTreeNode = successWeightRaw.size();
  this->successWeight.resize(this->nTreeNode + 1);
  this->failureWeight.resize(this->nTreeNode + 1);

  // Normalize and store
  for (int i = 1; i <= this->nTreeNode; ++i) {
    this->successWeight[i] =
        static_cast<double>(successWeightRaw[i - 1]) / totalSum;
  }

  for (int i = 0; i <= this->nTreeNode; ++i) {
    this->failureWeight[i] =
        static_cast<double>(failureWeightRaw[i]) / totalSum;
  }
}
void OBST::preCalculateTotalProb() {
  // Pre-calculate total probability
  for (int u = 1; u <= this->nTreeNode; ++u) {
    this->totalProbaility[u][u - 1] = this->failureWeight[u - 1];
    for (int v = u; v <= this->nTreeNode; ++v) {
      this->totalProbaility[u][v] = this->totalProbaility[u][v - 1] +
                                    this->failureWeight[v] +
                                    this->successWeight[v];
    }
  }
}

double OBST::memoizationHelper(int i, int j) {
  if (i == j + 1) {
    this->expectedSearchCost[i][j] = this->failureWeight[j];
    return this->failureWeight[j];
  }

  if (this->expectedSearchCost[i][j] != std::numeric_limits<double>::max())
    return this->expectedSearchCost[i][j];

  // Calculate the expected search cost
  for (int u = i; u <= j; ++u) {
    double temp = this->memoizationHelper(i, u - 1) +
                  this->memoizationHelper(u + 1, j) +
                  this->totalProbaility[i][j];
    if (temp < this->expectedSearchCost[i][j]) {
      this->expectedSearchCost[i][j] = temp;
      this->sufficientRoot[i][j] = u;
    }
  }
  return this->expectedSearchCost[i][j];
}

// Constructor and Destructor
OBST::OBST(const std::vector<int>& key, const std::vector<int>& successWeight,
           const std::vector<int>& failureWeight,
           const std::function<void()>& algo)
    : key(key), nTreeNode(key.size()) {
  this->normalizeWeight(successWeight, failureWeight);
  this->initMatrices(algo);
}
OBST::~OBST() {}

// Queries
double OBST::getTreeSearchCost() const {
  return this->expectedSearchCost[1][nTreeNode];
}

// Override function
void OBST::insert(int key) {
  std::cout << "Insert is not allow in OptimalBST!" << std::endl;
}
void OBST::remove(int key) {
  std::cout << "Remove is not allow in OptimalBST!" << std::endl;
}

// Build Function
void OBST::memoization() {
  this->preCalculateTotalProb();
  this->memoizationHelper(1, this->nTreeNode);
}

void OBST::tabulation() {
  // Base case
  for (int i = 1; i <= this->nTreeNode + 1; ++i) {
    this->expectedSearchCost[i][i - 1] = this->failureWeight[i - 1];
    this->totalProbaility[i][i - 1] = this->failureWeight[i - 1];
  }

  for (int length = 1; length <= this->nTreeNode; ++length) {
    for (int i = 1; i <= this->nTreeNode - length + 1; ++i) {
      int j = i + length - 1;

      this->totalProbaility[i][j] = this->totalProbaility[i][j - 1] +
                                    this->successWeight[j] +
                                    this->failureWeight[j];

      for (int r = i; r <= j; ++r) {
        double cost = this->expectedSearchCost[i][r - 1] +
                      this->expectedSearchCost[r + 1][j] +
                      this->totalProbaility[i][j];

        if (cost < this->expectedSearchCost[i][j]) {
          this->expectedSearchCost[i][j] = cost;
          this->sufficientRoot[i][j] = r;
        }
      }
    }
  }
}

void OBST::knuthAlgo() {
  for (int i = 1; i <= this->nTreeNode + 1; ++i) {
    this->expectedSearchCost[i][i - 1] = this->failureWeight[i - 1];
    this->totalProbaility[i][i - 1] = this->failureWeight[i - 1];
  }

  for (int length = 1; length <= this->nTreeNode; ++length) {
    for (int i = 1; i <= this->nTreeNode - length + 1; ++i) {
      int j = i + length - 1;

      this->totalProbaility[i][j] = this->totalProbaility[i][j - 1] +
                                    this->successWeight[j] +
                                    this->failureWeight[j];

      // Knuth Algorithm
      int left = (i <= j - 1) ? this->sufficientRoot[i][j - 1] : i;
      int right = (i + 1 <= j) ? this->sufficientRoot[i + 1][j] : j;
      for (int r = left; r <= right; ++r) {
        double cost = this->expectedSearchCost[i][r - 1] +
                      this->expectedSearchCost[r + 1][j] +
                      this->totalProbaility[i][j];

        if (cost < this->expectedSearchCost[i][j]) {
          this->expectedSearchCost[i][j] = cost;
          this->sufficientRoot[i][j] = r;
        }
      }
    }
  }
}

void OBST::initMatrices(const std::function<void()>& algo) {
  this->sufficientRoot.assign(
      this->nTreeNode + 1,
      std::vector<int>(this->nTreeNode + 1, std::numeric_limits<int>::max()));
  this->expectedSearchCost.assign(
      this->nTreeNode + 2,
      std::vector<double>(this->nTreeNode + 1,
                          std::numeric_limits<double>::max()));
  this->totalProbaility.assign(
      this->nTreeNode + 2,
      std::vector<double>(this->nTreeNode + 1,
                          std::numeric_limits<double>::max()));

  algo();
}

TreeNode* OBST::buildSubtree(int i, int j) {
  if (i > j) return nullptr;

  int r = this->sufficientRoot[i][j];
  TreeNode* node = new TreeNode(this->key[r - 1]);

  node->left = buildSubtree(i, r - 1);
  node->right = buildSubtree(r + 1, j);

  return node;
}

TreeNode* OBST::buildTree() {
  this->root = buildSubtree(1, this->nTreeNode);
  return this->root;
}
