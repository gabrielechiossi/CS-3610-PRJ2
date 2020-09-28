#include <iostream>
#include "avl_tree.h"
using namespace std;


void AVLTree::insert(const int key){
	//call insert funtion passing the tree and key
	this->root = insert(this->root, key);
}

void AVLTree::deleteNode(const int key){
	//call delete node funtion passing the tree and key
	this->root = deleteNode(this->root, key);
}

void AVLTree::print(const char c){
	//call print function for height or key base on c
	if(c == 'h'){
		inOrderHeight(this->root);
	}else if(c == 'p'){
		inOrderKey(this->root);
	}
	cout << endl;
}

int AVLTree::height(Node *N){ 
	//return height of the tree
	if (N == NULL) 
		return 0; 
	return N->height; 
} 

int AVLTree::max(int a, int b){
	// A function to get maximum  of two integer
	return (a > b)? a : b; 
} 

Node *AVLTree::rightRotate(Node *y){
	//function to right rotate subtree with y 
	Node *x = y->left; 
	Node *T2 = x->right; 

	//rotation 
	x->right = y; 
	y->left = T2; 

	//heights 
	y->height = max(height(y->left),height(y->right)) + 1; 
	x->height = max(height(x->left), height(x->right)) + 1; 
	return x; 
} 

Node *AVLTree::leftRotate(Node *x){
	//function to left rotate subtree with x 
	Node *y = x->right; 
	Node *T2 = y->left; 

	//rotation 
	y->left = x; 
	x->right = T2; 

	//heights 
	x->height = max(height(x->left),height(x->right)) + 1; 
	y->height = max(height(y->left),height(y->right)) + 1; 
	return y; 
} 

 
int AVLTree::getBalance(Node *N) { 
	//balance factor of node N
	if (N == NULL) 
		return 0; 
	return height(N->left) - 
		height(N->right); 
} 

Node* AVLTree::insert(Node* node, int key){ 
	//performe the normal BST rotation
	if (node == NULL) 
		return new Node(key); 
	if (key < node->key) 
		node->left = insert(node->left, key); 
	else if (key > node->key) 
		node->right = insert(node->right, key); 
	else 
		return node; 

	//update height of this ancestor node
	node->height = 1 + max(height(node->left),height(node->right)); 

	//get the balance factor of this ancestor node to check whether this node became unbalanced
	int balance = getBalance(node); 

	//left left case 
	if (balance > 1 && key < node->left->key) 
		return rightRotate(node); 

	//right right case 
	if (balance < -1 && key > node->right->key) 
		return leftRotate(node); 

	//left right case 
	if (balance > 1 && key > node->left->key) 
	{ 
		node->left = leftRotate(node->left); 
		return rightRotate(node); 
	} 

	//right left case 
	if (balance < -1 && key < node->right->key) 
	{ 
		node->right = rightRotate(node->right); 
		return leftRotate(node); 
	} 
	return node; 
} 

Node * AVLTree::minValueNode(Node* node){
	//return the node with minimum key value found in that tree 
	Node* current = node; 
	while (current->left != NULL) 
		current = current->left; 

	return current; 
} 
 
Node* AVLTree::deleteNode(Node* root, int key) 
{ 
	
	//perform standard BST delete 
	if (root == NULL) 
		return root; 
	if ( key < root->key ) 
		root->left = deleteNode(root->left, key); 
	else if( key > root->key ) 
		root->right = deleteNode(root->right, key); 
	else{ 
		//node with only one child or no child 
		if( (root->left == NULL) || (root->right == NULL) ){ 
			Node *temp = root->left ? 
						root->left : 
						root->right; 

			// No child case 
			if (temp == NULL){ 
				temp = root; 
				root = NULL; 
			} 
			else // One child case 
				*root = *temp; 
				free(temp); 
		}else{ 
			Node* temp = minValueNode(root->right); 
			root->key = temp->key; 
			root->right = deleteNode(root->right, temp->key); 
		} 
	} 
	if (root == NULL) 
		return root; 

	//update height of the current node 
	root->height = 1 + max(height(root->left),height(root->right)); 

	//get the balance factor  
	int balance = getBalance(root);  

	//left left case 
	if (balance > 1 && getBalance(root->left) >= 0) 
		return rightRotate(root); 
	//left right case 
	if (balance > 1 && getBalance(root->left) < 0){ 
		root->left = leftRotate(root->left); 
		return rightRotate(root); 
	} 
	//right right case 
	if (balance < -1 && getBalance(root->right) <= 0) 
		return leftRotate(root); 
	// Right Left Case 
	if (balance < -1 && getBalance(root->right) > 0){ 
		root->right = rightRotate(root->right); 
		return leftRotate(root); 
	} 
	return root; 
} 
 
void AVLTree::inOrderHeight(Node *root){ 
	//print in order height of each node
	if(root != NULL) { 
		inOrderHeight(root->left);
        cout << root->height << " "; 
		inOrderHeight(root->right); 
	} 
} 

void AVLTree::inOrderKey(Node *root){ 
	//print in order key of each node
	if(root != NULL) { 
		inOrderKey(root->left);
        cout << root->key << " "; 
		inOrderKey(root->right); 
	} 
} 