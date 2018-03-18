#include "bstree.h"
#include <iostream>

using namespace BSTree;

Tree::Tree() { root = nullptr; }
void Tree::add_node(int key, Node*& root) {
  if (root == nullptr) {
    root = new Node;
    root->key = key;
    root->left = root->right = nullptr;
  }
  if (key < root->key) {
    if (root->left != nullptr)
      add_node(key, root->left);
    else {
      root->left = new Node;
      root->left->left = root->left->right = nullptr;
      root->left->key = key;
    }
  }
  if (key > root->key) {
    if (root->right != nullptr)
      add_node(key, root->right);
    else {
      root->right = new Node;
      root->right->left = root->right->right = nullptr;
      root->right->key = key;
    }
  }
}

void Tree::insert(int key) { add_node(key, root); }
void Tree::remove(Node*& node) {
  if (node == nullptr) return;
  if (node->left != nullptr) remove(node->left);
  if (node->right != nullptr) remove(node->right);
  delete node;
  node = nullptr;
}
Tree::~Tree() { remove(root); }
