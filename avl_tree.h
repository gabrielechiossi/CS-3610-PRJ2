#ifndef AVL_TREE_H
#define AVL_TREE_H

struct Node 
{ 
	public: 
	int key; 
	Node *left; 
	Node *right; 
	int height; 
  
};

class AVLTree{
  public:
    int max(int a, int b);
    int height(Node *N);
    int getBalance(Node *N);
    void inOrderHeight(Node *root);
    void inOrderKey(Node *root);
  private:
    
    Node* newNode(int key) ;
    Node *rightRotate(Node *y);
    Node *leftRotate(Node *x);
    
    Node* insert(Node* node, int key);
    Node * minValueNode(Node* node);
    Node* deleteNode(Node* root, int key);
    
};

#endif
