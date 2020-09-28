#ifndef AVL_TREE_H
#define AVL_TREE_H

struct Node 
{ 
	public: 
  Node(const int key) : key(key), height(1), left(NULL), right(NULL){}

  ~Node(){
    delete left;
    delete right;
    left = right = NULL;
  }
	int key; 
	Node *left; 
	Node *right; 
	int height; 
};

class AVLTree{
  public:
    AVLTree() : root(NULL) {}
    ~AVLTree(){
      delete root;
    }
    int max(int a, int b);
    int height(Node *N);
    int getBalance(Node *N);
    void print(const char c);
    void insert(const int key);
    void deleteNode(const int key);
  private:
    Node* newNode(int key) ;
    Node *rightRotate(Node *y);
    Node *leftRotate(Node *x);
    Node* insert(Node* node, int key);
    Node * minValueNode(Node* node);
    Node* deleteNode(Node* root, int key);
    void inOrderHeight(Node *root);
    void inOrderKey(Node *root);
    Node* root;
};

#endif
