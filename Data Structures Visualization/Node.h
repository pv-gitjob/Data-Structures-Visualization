#pragma once
/** @file Node.h */
#ifndef _NODE 
#define _NODE

#include <cstddef> 

template <class	ItemType>
class Node
{
protected:
	ItemType item;
	// A data item
	Node<ItemType>* next;
	// Pointer to next node
public:
	Node();
	Node(const ItemType& anItem);
	Node(const ItemType& anItem, Node<ItemType>* nextNodePtr);
	void setItem(const ItemType& anItem);		//Sets the item
	void setNext(Node<ItemType>* nextNodePtr);	//Sets the next Item
	ItemType getItem() const;					//Gets the item
	Node<ItemType>* getNext() const;		//Gets the next item
};
// end Node 
template <class	ItemType>
Node<ItemType>::Node() : next(nullptr)
{
} // end default constructor 

template<class ItemType>
Node<ItemType>::Node(const ItemType& anItem) : item(anItem), next(nullptr)
{
} // end constructor 

template <class ItemType>
Node<ItemType>::Node(const ItemType& anItem, Node<ItemType>* nextNodePtr) : item(anItem), next(nextNodePtr)
{
} // end constructor 

template<class ItemType>
void Node<ItemType>::setItem(const ItemType& anItem)
{
	item = anItem;
} // end setItem 

template <class	ItemType>
void Node<ItemType>::setNext(Node<ItemType>* nextNodePtr)
{
	next = nextNodePtr;
} // end setNext 

template <class ItemType>
ItemType Node<ItemType>::getItem() const
{
	return item;
} // end getItem 

template <class ItemType>
Node<ItemType>* Node<ItemType>::getNext() const
{
	return next;
} // end getNext 

#endif 