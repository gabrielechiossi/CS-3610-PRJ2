#ifndef AVL_TREE_H
#define AVL_TREE_H

//An Avl Tree Node
struct Node{ 
	public: 
  //Constructor
  Node(const int key) : key(key), height(1), left(NULL), right(NULL){}

  //Destructor
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
    //Constructor
    AVLTree() : root(NULL) {}
    //Desctructor 
    ~AVLTree(){
      delete root;
    }
    //max between two variables
    int max(int a, int b);
    //return height of the node
    int height(Node *N);
    //get balnce factor of the node
    int getBalance(Node *N);
    //print function
    void print(const char c);
    //allocate a new node with key passed
    void insert(const int key);
    //delete node key
    void deleteNode(const int key);
  private:
    //allocate a new node with key passed
    Node* newNode(int key) ;
    //right rotate the sub tree rooted with y
    Node *rightRotate(Node *y);
    // left rotate the sub tree rooted with x
    Node *leftRotate(Node *x);
    //insert new node in tree
    Node* insert(Node* node, int key);
    //return the node with minimum key value found in that tree
    Node * minValueNode(Node* node);
    //delete node with key passed
    Node* deleteNode(Node* root, int key);
    //print in order the height of each node
    void inOrderHeight(Node *root);
    //print in order the key of each node
    void inOrderKey(Node *root);
    Node* root;
};

#endif
