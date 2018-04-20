namespace BSTree {
struct Node {
  int data;
  Node* left;
  Node* right;
  int value;
};
class Tree {
  Node* root;
  void remove(Node*& node);
  void add_node(int data, Node*& root);
  void showTree(Node* node, int field);
  void PreOrderTree(Node* node);
  void InOrderTree(Node* node);
  void PostOrderTree(Node* node);
  void WriteInFile(Node* root, std::string name);
  bool LoadfromfileTree(Node* root);
  bool Deletenode(Node*& root, int value);

 public:
  Tree();
  bool zero();
  void show();
  void insert(int data);
  void PreOrder();
  void InOrder();
  void PostOrder();
  void Write();
  bool Loadfromfile();
  bool Deleten(int value);

  ~Tree();
};
}
