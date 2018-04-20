#include <iostream>
#include "bstree.h"
#include <fstream>

using namespace BSTree;
using namespace std;

Tree::Tree() { root = nullptr; }
void Tree::add_node(int data, Node*& root) {
  if (root == nullptr) {
    root = new Node;
    root->data = data;
    root->left = root->right = nullptr;
  }
  if (data < root->data) {
    if (root->left != nullptr)
      add_node(data, root->left);
    else {
      root->left = new Node;
      root->left->left = root->left->right = nullptr;
      root->left->data = data;
    }
  }
  if (data > root->data) {
    if (root->right != nullptr)
      add_node(data, root->right);
    else {
      root->right = new Node;
      root->right->left = root->right->right = nullptr;
      root->right->data = data;
    }
  }
}

bool Tree::zero() { return (root == nullptr ? true : false); }

void Tree::insert(int data) { add_node(data, root); }

void Tree::showTree(Node* node, int field) {
  if (root != nullptr) {
    cout << " ";
    if (node->left != nullptr) {
      showTree(node->left, field + 1);
      for (int i = 0; i < field; i++) {
        cout << " ";
      }
    }
    cout << node->data << endl;
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
    cout << node->data << " ";
    if (node->right != nullptr) {
      InOrderTree(node->right);
    }
  }
}

void Tree::PreOrderTree(Node* node) {
  if (root != nullptr) {
    cout << node->data << " ";
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
    cout << node->data << " ";
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

bool Tree::Deletenode(Node*& root, int value) {
  if (root == nullptr) {
    return root;
  }
  if (value < root->data) {
    root->left;
    Deletenode(root->left, value);
  } else if (value > root->data) {
    root->right;
    Deletenode(root->right, value);
  } else if (root->left != nullptr && root->right != nullptr) {
    root->data == root->right->data;
    root->right;
    Deletenode(root->right, root->data);
  } else if (root->left != nullptr)
    root = root->left;
  else
    root = root->right;
  return true;
}

bool Tree::Deleten(int value) { Deletenode(root, value); }

void Tree::WriteInFile(Node* root, std::string name) {
  ofstream fout(name, ios::app);
  if (root == nullptr) return;
  WriteInFile(root->left, name);
  fout << root->data << endl;
  WriteInFile(root->right, name);
  fout.close();
}

void Tree::Write() {
  string name;
  cout << "Введите название файла:";
  cin >> name;
  ifstream fin(name, ios_base::in);
  string ch_3;
  if (fin.is_open()) {
    cout << "Вы хотите переписать файл? Да/Нет" << endl;
    cin >> ch_3;
  }
  fin.close();
  if ((ch_3 == "y") || (ch_3 == "Да") || (ch_3 == "Нет") || (ch_3 == "да") ||
      (ch_3 == "нет")) {
    WriteInFile(root, name);
  }
}

bool Tree::LoadfromfileTree(Node* root) {
  cout << "Введите путь к файлу:" << endl;
  string file_name;
  cin >> file_name;
  ifstream fin(file_name);
  if (!fin.is_open()) return false;
  string str;
  getline(fin, str);
  int elements = 1;
  for (int i = 0; i < str.length(); i++) {
    if (str[i] == ' ') elements++;
  }
  fin.close();
  fin.open(file_name);
  for (int i = 0; i < elements; i++) {
    fin >> str;
    this->insert(atoi(str.c_str()));
  }
  return true;
}

bool Tree::Loadfromfile() { LoadfromfileTree(root); }

void Tree::show() {
  if (root != nullptr)
    showTree(root, 0);
  else
    cerr << "Дерево пусто" << endl;
}
Tree::~Tree() { remove(root); }

