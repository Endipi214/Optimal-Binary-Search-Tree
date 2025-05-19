#include "BinarySearchTree.hpp"

#include <cstddef>
#include <iostream>
#include <queue>

// Helper Function
void BST::del(TreeNode*& r, TreeNode*& q) {
  if (r->right)
    del(r->right, q);
  else {
    q->key = r->key;
    q = r;
    r = r->left;
  }
}

TreeNode* BST::newNode(int key) { return new TreeNode({key, NULL, NULL}); }

void BST::LNR(TreeNode* root) {
  if (root) {
    this->LNR(root->left);
    std::cout << root->key << " ";
    this->LNR(root->right);
  }
}

void BST::LRN(TreeNode* root) {
  if (root) {
    this->LRN(root->left);
    this->LRN(root->right);
    std::cout << root->key << " ";
  }
}

void BST::NLR(TreeNode* root) {
  if (root) {
    std::cout << root->key << " ";
    this->NLR(root->left);
    this->NLR(root->right);
  }
}

void BST::levelOrder(TreeNode* root) {
  if (!root) return;
  std::queue<TreeNode*> valueQueue;
  valueQueue.push(root);

  while (!valueQueue.empty()) {
    TreeNode* curr = valueQueue.front();
    valueQueue.pop();
    std::cout << curr->key << " ";
    if (curr->left) valueQueue.push(curr->left);
    if (curr->right) valueQueue.push(curr->right);
  }
}

TreeNode* BST::search(TreeNode* root, int data) {
  if (!root || (root->key == data)) return root;
  if (data < root->key)
    return this->search(root->left, data);
  else
    return this->search(root->right, data);
}

void BST::insert(TreeNode*& root, int key) {
  if (!root)
    root = this->newNode(key);
  else {
    if (key < root->key)
      this->insert(root->left, key);
    else
      this->insert(root->right, key);
  }
}

void BST::remove(TreeNode*& root, int data) {
  if (!root) return;
  if (root->key < data)
    this->remove(root->right, data);
  else {
    if (root->key > data)
      this->remove(root->left, data);
    else {
      TreeNode* Del = root;
      if (!Del->right)
        root = Del->left;
      else {
        if (!Del->left)
          root = Del->right;
        else
          this->del(root->left, Del);
      }
      delete Del;
    }
  }
}

void BST::destroy(TreeNode*& root) {
  if (root) {
    this->destroy(root->left);
    this->destroy(root->right);
    delete root;
  }
}

// Constructor and Destructor
BST::BST() : root(NULL) {}
BST::~BST() { this->destroy(); }

void BST::LNR() { this->LNR(this->root); }
void BST::LRN() { this->LRN(this->root); }
void BST::NLR() { this->NLR(this->root); }
void BST::levelOrder() { this->levelOrder(this->root); }

TreeNode* BST::search(int key) { return this->search(this->root, key); }

void BST::insert(int key) { this->insert(this->root, key); }
void BST::remove(int key) { this->remove(this->root, key); }
void BST::destroy() { this->destroy(this->root); }
