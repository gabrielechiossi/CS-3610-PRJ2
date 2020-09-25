#include <iostream>
#include "avl_tree.h"
using namespace std;

int main() 
{ 
Node *root = NULL; 
    int rm, value; 
char option;
  do{
      cin >> option;
      switch(option){
          case 'i':
            cin >> value;
            root.insert(root, value);
            break;
          case 'r':
            cin >> rm;
            root = deleteNode(root, rm);
            break;
          case 'h':
            inOrderHeight(root);
            break;
          case 'p':
            inOrderKey(root);
      }
  }while(option != 'q');
	return 0; 
} 