namespace BSTree {
struct Node {
  int key;
  Node* left;
  Node* right;
};
class Tree {
  Node* root;
  void remove(Node*& node);
  void add_node(int key, Node*& root);
  void showTree(Node* node, int field);
  void PreOrderTree(Node* node);
  void InOrderTree(Node* node);
  void PostOrderTree(Node* node);
  void WriteInFile(Node *root,  std::string name);

 public:
  Tree();
  bool zero();
  void show();
  void insert(int key);
  void PreOrder();
  void InOrder();
  void PostOrder();
  void Write();
  ~Tree();
};
}
