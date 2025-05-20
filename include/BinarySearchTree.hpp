#pragma once

struct TreeNode {
  int key;
  TreeNode* left;
  TreeNode* right;

  TreeNode(int k) : key(k), left(nullptr), right(nullptr) {}
};

class BST {
 private:
  // Helper Function
  void printTree(TreeNode* root);
  void del(TreeNode*& r, TreeNode*& q);
  TreeNode* newNode(int key);
  void LNR(TreeNode* root);
  void LRN(TreeNode* root);
  void NLR(TreeNode* root);
  void levelOrder(TreeNode* root);
  TreeNode* search(TreeNode* root, int key);
  void insert(TreeNode*& root, int key);
  void remove(TreeNode*& root, int key);
  void destroy(TreeNode*& root);

 protected:
  // Tree Root
  TreeNode* root;

 public:
  // Constructor and Destructor
  BST();
  virtual ~BST();

  // Traversal
  void LNR();
  void LRN();
  void NLR();
  void levelOrder();

  // Queries
  TreeNode* search(int key);
  void printTree();

  // Insertion and Deletion
  virtual void insert(int key);
  virtual void remove(int key);
  void destroy();
};
