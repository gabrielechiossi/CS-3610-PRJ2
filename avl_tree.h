#ifndef AVL_TREE_H
#define AVL_TREE_H

struct BinaryNode {
  BinaryNode(const int key) : key(key), left(NULL), right(NULL) {}

  ~BinaryNode() {
    delete left;
    delete right;
    left = right = NULL;
    height = 1;
  }

  int key;
  int height;
  BinaryNode *left, *right;
};

class AVLTree {

public:
  AVLTree() : root(NULL) {}
  ~AVLTree() { 
    delete root;
  }

  void insert(const int key);
  int height(struct BinaryNode *p);
  int getBalance(BinaryNode *n);
  int max(int a, int b);
  void print(BinaryNode *root);
  

private:
  BinaryNode* insert(const int key, BinaryNode* node);
  BinaryNode* newNode(int key);
  BinaryNode* rightRotate(BinaryNode *y);
  BinaryNode* leftRotate(BinaryNode *x);
  BinaryNode* minValueNode(BinaryNode *node);
  BinaryNode* deleteNode(BinaryNode* root, int key);
};

#endif
