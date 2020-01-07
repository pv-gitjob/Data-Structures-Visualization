#pragma once
#include <string>
#include <iomanip>
#include "BSTNode.h"
using namespace std;
template<class T>
class BinarySearchTree
{
private:
	//Pointer root of the tree
	BSTNode<T>* root;

	// We have two different BST
	void inorder(BSTNode<T>*);	// Takes in the node and does in order travesal
	void preorder(BSTNode<T>*);	// Takes in the node and does in order travesal
	void postorder(BSTNode<T>*);	// Takes in root node and does in order travesal
	bool printLevel(BSTNode<T>*, int);	// Function to print all nodes of a given level from left to right
	void levelOrderTraversal(BSTNode<T>*);	// Function to print level order traversal of given binary tree
	void indented(BSTNode<T>*, int indent);


	void sInorder(BSTNode<T>*, string&);	//Does inorder travesal
	void sPreorder(BSTNode<T>*, string&);	// Does preorder travesal
	void sPostorder(BSTNode<T>*, string&);	//Does postorder travesal
	bool sPrintLevel(BSTNode<T>*, int, string&);	//Prints the level of the tree
	void sLevelOrderTraversal(BSTNode<T>*, string&);	// Function to print level order traversal of given binary tree

public:
	BinarySearchTree()
	{
		root = NULL;
	}
	bool isEmpty() const { return root == NULL; }		// Checks if the tree is empty
	void print_inorder();	// Calls inorder(in order travesal)
	void print_preorder();	//Calls preorder(pre order travesal)
	void print_postorder();	//Calls postorder(post order travesal)	
	void print_breadth();	//Prints breadth first	
	void string_indented();

	void insert(T);		//Used to insert into bst
	void remove(T);		// Used to remove from bst
	bool search(T);		//Ued to search through bst

	string string_inorder();	//Returns string and calls sInorder (calls first then returns)
	string string_preorder();	//Returns string and calls sPreorder (calls first then returns)
	string string_postorder();	//Returns string and calls sPostorder (calls first then returns)
	string string_breadth();	//Returns string and calls sLevelOrderTraversal (calls first then returns)

};

template<class T>
void BinarySearchTree<T>::indented(BSTNode<T>* p, int indent)
{
	if (p != NULL) {
		if (p->getRight()) {
			indented(p->getRight(), indent + 4);
		}
		if (indent) {
			std::cout << std::setw(indent) << ' ';
		}
		if (p->getRight()) std::cout << " /\n" << std::setw(indent) << ' ';
		std::cout << p->getItem() << "\n ";
		if (p->getLeft()) {
			std::cout << std::setw(indent) << ' ' << " \\\n";
			indented(p->getLeft(), indent + 4);
		}
	}
}

template<class T>
void BinarySearchTree<T>::string_indented()
{
	indented(root, 0);
}

//Calls sLevelOrderTraversal and returns a string
template<class T>
string BinarySearchTree<T>::string_breadth()
{
	string temp;
	sLevelOrderTraversal(root, temp);
	return temp;
}

//Takes in the pointer to root and the int level value and the string from string_breadth. makes a breadth first traversal
template<class T>
bool BinarySearchTree<T>::sPrintLevel(BSTNode<T>* root, int level, string& temp)
{
	// If root is the nullpointer then return false
	if (root == nullptr)
		return false;
	// If there is one node then temp is added to the root and itself
	if (level == 1)
	{
		temp += root->getItem() + "\n";
		// return true if at-least one node is present at given level
		return true;
	}
	//Left node
	bool left = sPrintLevel(root->getLeft(), level - 1, temp);
	//Right node
	bool right = sPrintLevel(root->getRight(), level - 1, temp);
	//Returns left or right
	return left || right;
}


template<class T>
void BinarySearchTree<T>::sLevelOrderTraversal(BSTNode<T>* root, string &temp)
{
	// start from level 1 -- till height of the tree
	int level = 1;

	// run till printLevel() returns false
	while (sPrintLevel(root, level, temp))
		level++;
}

template<class T>// Function to print level order traversal of given binary tree
void BinarySearchTree<T>::levelOrderTraversal(BSTNode<T>* root)
{
	// start from level 1 -- till height of the tree
	int level = 1;

	// run till printLevel() returns false
	while (printLevel(root, level))
	{
		level++;
	}
}
template<class T>// Function to print all nodes of a given level from left to right
bool BinarySearchTree<T>::printLevel(BSTNode<T>* root, int level)
{
	if (root == nullptr)
		return false;

	if (level == 1)
	{
		cout << root->getItem() << endl;
		// return true if at-least one node is present at given level
		return true;
	}

	bool left = printLevel(root->getLeft(), level - 1);
	bool right = printLevel(root->getRight(), level - 1);

	return left || right;
}
// Calls levelOrderTraversal to print breadth first traversal
template<class T>
void BinarySearchTree<T>::print_breadth()
{
	//Inputs the root node
	levelOrderTraversal(root);
}

//Calls sInorder  and returns a string (in order travesal)
template<class T>
string BinarySearchTree<T>::string_inorder()
{
	string temp;
	sInorder(root, temp);
	return temp;
}
template<class T>
// Function to do in order traversal of given binary tree
void BinarySearchTree<T>::sInorder(BSTNode<T>* p, string& temp)
{
	if (p != NULL)
	{
		if (p->getLeft()) sInorder(p->getLeft(), temp);
		temp += p->getItem() + "\n";
		if (p->getRight()) sInorder(p->getRight(), temp);
	}
	else return;
}


//Calls sPreorder  and returns a string (pre order travesal)
template<class T>
string BinarySearchTree<T>::string_preorder()
{
	string temp;
	sPreorder(root, temp);
	return temp;
}


template<class T>
// Function to do pre order traversal of given binary tree
void BinarySearchTree<T>::sPreorder(BSTNode<T>* p, string& temp)
{
	if (p != NULL)
	{
		temp += p->getItem() + "\n";
		if (p->getLeft()) sPreorder(p->getLeft(), temp);
		if (p->getRight()) sPreorder(p->getRight(), temp);
	}
	else return;
}

//Calls sPostorder and returns a string (post order travesal)
template<class T>
string BinarySearchTree<T>::string_postorder()
{
	string temp;
	sPostorder(root, temp);
	return temp;
}

template<class T>
// Function to do post order traversal of given binary tree
void BinarySearchTree<T>::sPostorder(BSTNode<T>* p, string& temp)
{
	if (p != NULL)
	{
		if (p->getLeft()) sPostorder(p->getLeft(), temp);
		if (p->getRight()) sPostorder(p->getRight(), temp);
		temp += p->getItem() + "\n";
	}
	else return;
}


// Used to insert a node in the bst
template <class T>
void BinarySearchTree<T>::insert(T d)
{
	//Creates a new BSTNODE<T>
	BSTNode<T>* t = new BSTNode<T>(d);
	//Parent node
	BSTNode<T>* parent;
	//t->setItem(d);
	t->setLeft(NULL);
	t->setRight(NULL);
	parent = NULL;
	// is this a new tree?
	if (isEmpty()) root = t;
	else
	{
		//Note: ALL insertions are as leaf nodes
		BSTNode<T>* curr;
		curr = root;
		// Find the BSTNode's parent
		while (curr)
		{
			parent = curr;
			if (t->getItem() > curr->getItem()) curr = curr->getRight();
			else curr = curr->getLeft();
		}

		if (t->getItem() < parent->getItem())
			parent->setLeft(t);
		else
			parent->setRight(t);
	}
}
//Used to search the bst
template <class T>
bool BinarySearchTree<T>::search(T d)
{
	//Locate the element
	bool found = false;
	if (isEmpty())
	{
		cout << "This Tree is empty!" << endl;
		return false;
	}
	//Current node pointer
	BSTNode<T>* curr;
	//Parent node pointer
	BSTNode<T>* parent;
	curr = root;
	parent = (BSTNode<T>*)NULL;
	// While curr is not null
	while (curr != NULL)
	{
		// Return true if curr is == d
		if (curr->getItem() == d)
		{
			found = true;
			break;
		}
		// else parent is curr
		else
		{
			parent = curr;
			//IF d is greater than the current item then curr becomes the higher node
			if (d>curr->getItem()) curr = curr->getRight();
			//if d is not greater than the current item then curr becomes the left node
			else curr = curr->getLeft();
		}
	}
	return found;
}

//Used to remove from the bst
template <class T>
void BinarySearchTree<T>::remove(T d)
{
	bool found = false;
	// Checks if the tree is empty
	if (isEmpty())
	{
		cout << "This Tree is empty!" << endl;
		return;
	}

	BSTNode<T>* curr;
	BSTNode<T>* parent;
	curr = root;
	parent = (BSTNode<T>*)NULL;
	// makes curr go through the whole bst to find the the desired node just like the search function
	while (curr != NULL)
	{
		if (curr->getItem() == d)
		{
			found = true;
			break;
		}
		else
		{
			parent = curr;
			if (d>curr->getItem()) curr = curr->getRight();
			else curr = curr->getLeft();
		}
	}
	// If the thing the user is trying to look for is not there then prints data not found
	if (!found)
	{
		cout << "Data not found!" << endl;
		return;
	}

	// BSTNode with single child
	if ((curr->getLeft() == NULL && curr->getRight() != NULL) || (curr->getLeft() != NULL
		&& curr->getRight() == NULL))
	{
		if (curr->getLeft() == NULL && curr->getRight() != NULL)
		{
			if (parent->getLeft() == curr)
			{
				parent->setLeft(curr->getRight());
				delete curr;
			}
			else
			{
				parent->setRight(curr->getRight());
				delete curr;
			}
		}
		else // left child present, no right child
		{
			if (parent->getLeft() == curr)
			{
				parent->setLeft(curr->getLeft());
				delete curr;
			}
			else
			{
				parent->setRight(curr->getLeft());
				delete curr;
			}
		}
		return;
	}

	//We're looking at a leaf node
	if (curr->getLeft() == NULL && curr->getRight() == NULL)
	{
		if (parent == NULL)
		{
			delete curr;

		}
		else
			if (parent->getLeft() == curr) parent->setLeft(NULL);
			else parent->setRight(NULL);
			delete curr;
			return;
	}


	//BSTNode with 2 children
	// replace node with smallest value in right subtree
	if (curr->getLeft() != NULL && curr->getRight() != NULL)
	{
		BSTNode<T>* chkr;
		chkr = curr->getRight();
		if ((chkr->getLeft() == NULL) && (chkr->getRight() == NULL))
		{
			curr = chkr;
			delete chkr;
			curr->setRight(NULL);
		}
		else // right child has children
		{
			//if the node's right child has a left child
			// Move all the way down left to locate smallest element

			if ((curr->getRight())->getLeft() != NULL)
			{
				BSTNode<T>* lcurr;
				BSTNode<T>* lcurrp;
				lcurrp = curr->getRight();
				lcurr = (curr->getRight())->getLeft();
				while (lcurr->getLeft() != NULL)
				{
					lcurrp = lcurr;
					lcurr = lcurr->getLeft();
				}
				curr->setItem(lcurr->getItem());
				delete lcurr;
				lcurrp->setLeft(NULL);
			}
			// Move all the way down right
			else
			{
				BSTNode<T>* tmp;
				tmp = curr->getRight();
				curr->setItem(tmp->getItem());
				curr->setRight(tmp->getRight());
				// Delete the tmp
				delete tmp;
			}

		}
		return;
	}
}
//Calls inorder(in order travesal)
template<class T>
void BinarySearchTree<T>::print_inorder()
{
	inorder(root);
}

template<class T>
// Function to make in order traversal of given binary tree
void BinarySearchTree<T>::inorder(BSTNode<T>* p)
{
	if (p != NULL)
	{
		if (p->getLeft()) inorder(p->getLeft());
		cout << p->getItem() << endl;
		if (p->getRight()) inorder(p->getRight());
	}
	else return;
}

//Calls preorder(pre order travesal)
template<class T>
void BinarySearchTree<T>::print_preorder()
{
	preorder(root);
}

template<class T>
// Function to make pre order traversal of given binary tree
void BinarySearchTree<T>::preorder(BSTNode<T>* p)
{
	if (p != NULL)
	{
		cout << p->getItem() << endl;
		if (p->getLeft()) preorder(p->getLeft());
		if (p->getRight()) preorder(p->getRight());
	}
	else return;
}

//Calls postorder(post order travesal)
template<class T>
void BinarySearchTree<T>::print_postorder()
{
	postorder(root);
}

template<class T>
// Function to make post order traversal of given binary tree
void BinarySearchTree<T>::postorder(BSTNode<T>* p)
{
	if (p != NULL)
	{
		if (p->getLeft()) postorder(p->getLeft());
		if (p->getRight()) postorder(p->getRight());
		cout << p->getItem() << endl;
	}
	else return;
}