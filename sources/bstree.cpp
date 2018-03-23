#include "bstree.h"
#include <iostream>

using namespace BSTree;
using namespace std;

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

bool Tree::zero() { return (root == nullptr ? true : false); }

void Tree::insert(int key) { add_node(key, root); }

void Tree::showTree(Node* node, int field) {
  if (root != nullptr) {
    cout << "   ";
    if (node->left != nullptr) {
      showTree(node->left, field + 1);
      for (int i = 0; i < field; i++) {
        cout << " ";
      }
    }
    cout << node->key << endl;
    if (node->right != nullptr) {
      showTree(node->right, field + 1);
    }
  }
}

void Tree::InOrderTree(Node* node) {
  if (root != nullptr) {
    if (node->left != nullptr) {
      InOrderTree(node->left);
    }
    cout << node->key << " ";
    if (node->right != nullptr) {
      InOrderTree(node->right);
    }
  }
}

void Tree::PreOrderTree(Node* node) {
  if (root != nullptr) {
    cout << node->key << " ";
    if (node->left != nullptr) {
      PreOrderTree(node->left);
    }
    if (node->right != nullptr) {
      PreOrderTree(node->right);
    }
  }
}

void Tree::PostOrderTree(Node* node) {
  if (root != nullptr) {
    if (node->left != nullptr) {
      PostOrderTree(node->left);
    }
    if (node->right != nullptr) {
      PostOrderTree(node->right);
    }
    cout << node->key << " ";
  }
}
void Tree::InOrder() { InOrderTree(root); }
void Tree::PreOrder() { PreOrderTree(root); }
void Tree::PostOrder() { PostOrderTree(root); }

void Tree::remove(Node*& node) {
  if (node == nullptr) return;
  if (node->left != nullptr) remove(node->left);
  if (node->right != nullptr) remove(node->right);
  delete node;
  node = nullptr;
}
void Tree::show() {
  if (root != nullptr)
    showTree(root, 0);
  else
    cout << "nothing to show" << endl;
}
Tree::~Tree() { remove(root); }

