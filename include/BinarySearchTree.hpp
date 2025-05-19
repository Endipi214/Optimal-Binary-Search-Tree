#pragma once

struct TreeNode {
  int key;
  TreeNode* left;
  TreeNode* right;
};

class BST {
 private:
  // Helper Function
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

  // Insertion and Deletion
  virtual void insert(int key);
  virtual void remove(int key);
  void destroy();
};
