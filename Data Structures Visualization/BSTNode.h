#pragma once
#include "Node.h"
template <class	ItemType>
class BSTNode : private Node<ItemType>
{
public:
	//constructor
	BSTNode<ItemType>() : Node<ItemType>() {}

	BSTNode<ItemType>(ItemType& anItem) : Node<ItemType>(anItem) {}
protected:
	BSTNode<ItemType>* left;
	// Pointer to left node
	BSTNode<ItemType>* right;
	// Pointer to right node

public:
	//Sets the left node
	void setLeft(BSTNode<ItemType>* leftNodePtr);
	BSTNode<ItemType>* getLeft() const;

	//Sets the right node
	void setRight(BSTNode<ItemType>* rightNodePtr);
	BSTNode<ItemType>* getRight() const;

	//gets the item
	ItemType getItem() const;
	void setItem(const ItemType&);

	//Deconstructor
	~BSTNode<ItemType>() {};
};
template <class	ItemType>
ItemType BSTNode<ItemType>::getItem() const {
	return Node<ItemType>::getItem();
}

template <class	ItemType>
void BSTNode<ItemType>::setItem(const ItemType& d) {
	return Node<ItemType>::setItem(d);
}

template <class	ItemType>
//Sets the left node
void BSTNode<ItemType>::setLeft(BSTNode<ItemType>* leftNodePtr)
{
	left = leftNodePtr;
} // end setNext 

template <class ItemType>
//Gets the left node
BSTNode<ItemType>* BSTNode<ItemType>::getLeft() const
{
	return left;
} // end getNext 

template <class	ItemType>
//Sets the right node
void BSTNode<ItemType>::setRight(BSTNode<ItemType>* rightNodePtr)
{
	right = rightNodePtr;
} // end setNext 

template <class ItemType>
// GEts the right node
BSTNode<ItemType>* BSTNode<ItemType>::getRight() const
{
	return right;
} // end getNext 