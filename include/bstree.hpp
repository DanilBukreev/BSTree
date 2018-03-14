namespace BSTree {
struct Node {
  int key;
  Node *left;
  Node *right;
};
class Tree {
  Node *root;
  void remove(Node *&node);

 public:
  Tree();
  void add_node(int key, Node *&root);
  void insert(int key);
  ~Tree();
};
}
