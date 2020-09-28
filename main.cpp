#include <iostream>
#include "avl_tree.h"
using namespace std;

int main(){ 
  AVLTree root; 
  int rm, value; 
  char option;
    do{
        cin >> option;
        switch(option){
            case 'i':
              cin >> value;
              root.insert(value);
              break;
            case 'r':
              cin >> rm;
              root.deleteNode(rm);
              break;
            case 'h':
              root.print('h');
              break;
            case 'p':
              root.print('p');
        }
    }while(option != 'q');
	return 0; 
} 