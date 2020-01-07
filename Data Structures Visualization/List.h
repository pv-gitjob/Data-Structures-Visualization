#pragma once
#ifndef List_h
#define List_h

#include <iostream>
#include <fstream>
using namespace std;

#include "ListNode.h"

template <typename T>
class List //linked list of LNode objects
{
public:
	List();
	~List();
	void print(); //prints the contents of the linked list
	bool search(T); //searches for a value in the linked list and returns true if it exists
	int getLength();
	void remove(int pos);
	void clear();
	T getEntry(int pos);
	//Giving 3 options for inserting
	void insertAscending(T); //fucntion used to insert new LNode in order in the list
	void insertByPos(int pos, T entry); //Allows you to insert at a specific position
	void insertDescending(T); //function used to insert new LNode in order in the list
	//Write list directly to a file
	void writeToFile(ostream &outfile);

private:
	LNode<T> *startPtr; //stores the pointer of first object in the linked list
	LNode<T> *endPtr; //stored the pointer of the last object in the linked list
	bool isEmpty(); //utility functions used to see if the list contains no elements
	void insertBegin(T); //inserts new LNode before the first LNode in the list
	void insertEnd(T); //inserts new LNode after the last LNode in the list
};

template <typename T>
List<T>::List() //creates list with start and end as NULL
{
	startPtr = NULL;
	endPtr = NULL;
}

template <typename T>
List<T>::~List()
{
	LNode<T> *node = startPtr;
	LNode<T> *next;

	if (startPtr != NULL) // List is not empty
	{
		while (node != NULL) // delete remaining LNodes
		{
			next = node->getNextPtr();
			node = NULL;
			//delete node;
			node = next;
		}
	}
}

template <typename T>
bool List<T>::isEmpty()
{
	if (startPtr == NULL && endPtr == NULL) //if the start pointer and end pointer are NULL then the list is empty
		return 1;
	else
		return 0;
}

template <typename T>
void List<T>::insertBegin(T dataIn)
{
	if (isEmpty()) //if the list is empty create first element of the list
	{
		LNode<T> * newPtr = new LNode<T>(dataIn); //creates new LNode
		startPtr = newPtr; //start and end pointer are same becuase there is only one object in list
		endPtr = newPtr;
	}
	else //if LNode(s) exist in list insert additional object before the first
	{
		LNode<T> * newPtr = new LNode<T>(dataIn);
		newPtr->setNextPtr(startPtr); //the next pointer of the new LNode points to the LNode that was previously first
		startPtr = newPtr; //the pointer for the new LNode is now the starting LNode
	}
}

template <typename T>
void List<T>::insertEnd(T dataIn)
{
	if (isEmpty()) //if the list is empty create first element of the list (same as first case in insert at begin)
	{
		LNode<T> * newPtr = new LNode<T>(dataIn);
		startPtr = newPtr;
		endPtr = newPtr;
	}
	else //if LNode(s) exist in the list then insert new LNode at the end of the list
	{
		LNode<T> * newPtr = new LNode<T>(dataIn);
		endPtr->setNextPtr(newPtr); //the current last LNode's next pointer points to the new LNode
		endPtr = newPtr; //the new LNode is now the last LNode in the list
	}
}

template <typename T>
void List<T>::insertAscending(T dataIn) //general funtionn to insert new LNode the proper order in the list
{
	if (isEmpty()) //if there is no LNodes in the list simply insert at beginning
	{
		insertBegin(dataIn);
	}
	else //otherwise
	{
		if (dataIn < startPtr->data) //if the data of the new object is less than than the data of first LNode in list insert at beginning
		{
			insertBegin(dataIn);
		}
		else if (dataIn >= endPtr->data) //if the data of the new object is greater than than the data of last LNode in list insert at end
		{
			insertEnd(dataIn);
		}
		else //the new LNode is being inserted in order but not at the beginning or end
		{
			LNode<T> * currentPtr = startPtr;
			LNode<T> * newPtr = new LNode<T>(dataIn); //creates new LNode
			while (currentPtr != endPtr) //runs until the end of the list is reached
			{
				if ((newPtr->data < currentPtr->nextPtr->data) && (newPtr->data >= currentPtr->data)) //if the data of the new LNode is less the data in the next LNode and greater than the data in the current LNode, insert after current LNode 
				{
					LNode<T> * next = currentPtr->nextPtr;
					currentPtr->nextPtr = newPtr; //current LNodes next pointer now points to the new LNode
					newPtr->nextPtr = next; //the new LNodes next pointer now points the LNode previously after the current LNode
					break;
				}
				currentPtr = currentPtr->nextPtr; //moves to the next LNode in the list
			}
		}
	}
}

template <typename T>
void List<T>::insertDescending(T dataIn) //general funtionn to insert new LNode the proper order in the list
{
	if (isEmpty()) //if there is no LNodes in the list simply insert at beginning
	{
		insertBegin(dataIn);
	}
	else //otherwise
	{
		if (dataIn > startPtr->data) //if the data of the new object is less than than the data of first LNode in list insert at beginning
		{
			insertBegin(dataIn);
		}
		else if (dataIn <= endPtr->data) //if the data of the new object is greater than than the data of last LNode in list insert at end
		{
			insertEnd(dataIn);
		}
		else //the new LNode is being inserted in order but not at the beginning or end
		{
			LNode<T> * currentPtr = startPtr;
			LNode<T> * newPtr = new LNode<T>(dataIn); //creates new LNode
			while (currentPtr != endPtr) //runs until the end of the list is reached
			{
				if ((newPtr->data > currentPtr->nextPtr->data) && (newPtr->data <= currentPtr->data)) //if the data of the new LNode is less the data in the next LNode and greater than the data in the current LNode, insert after current LNode 
				{
					LNode<T> * next = currentPtr->nextPtr;
					currentPtr->nextPtr = newPtr; //current LNodes next pointer now points to the new LNode
					newPtr->nextPtr = next; //the new LNodes next pointer now points the LNode previously after the current LNode
					break;
				}
				currentPtr = currentPtr->nextPtr; //moves to the next LNode in the list
			}
		}
	}
}

template <typename T>
void List<T>::print()
{
	if (isEmpty())
	{
		cout << "The list is empty" << endl;
	}
	else
	{
		LNode<T> * currentPtr = startPtr;
		int count = 0;

		while (currentPtr != NULL) //prints until the end of the list is reached
		{
			count++;
			cout << count << ". " << currentPtr->data << endl;
			currentPtr = currentPtr->nextPtr; //moves to next LNode in list
		}
	}
}

template <typename T>
bool List<T>::search(T key) //search functions that searches for LNode that contains data equal to the key
{
	LNode<T>* LNodePtr;
	bool found = false;

	LNodePtr = startPtr;

	while ((!found) && (LNodePtr != NULL)) //runs through list until data is found within a LNode or end of list is reached
	{
		if (LNodePtr->data == key) //if the LNode's data equals the key then the LNode has been found
			found = true;
		else
			LNodePtr = LNodePtr->nextPtr; //moves to next LNode in list
	}
	return found;
}

template <typename T>
int List<T>::getLength()
{
	LNode<T>* LNodePtr;
	int count = 0;

	LNodePtr = startPtr;

	while (LNodePtr != NULL) //runs through list until data is found within a LNode or end of list is reached
	{
		count++;
		LNodePtr = LNodePtr->getNextPtr(); //moves to next LNode in list
	}
	return count;
}

template <typename T>
void List<T>::remove(int pos)
{
	int length = getLength();
	if (pos<1 || pos>length) return;

	if (pos == 1)
	{
		startPtr = startPtr->getNextPtr();
		return;
	}

	LNode<T>* LNodePtr = startPtr;

	if (pos == length)
	{
		if (pos == 2)
		{
			T temp = startPtr->getData();
			clear();
			insertBegin(temp);
			return;
		}
		for (int i = 1; i < pos - 2; i++)
		{
			LNodePtr = LNodePtr->getNextPtr();
		}
		LNode<T>* tempPtr = new LNode<T>(LNodePtr->getNextPtr()->getData());
		LNodePtr->setNextPtr(tempPtr);
		endPtr = tempPtr;
		return;
	}

	for (int i = 1; i < pos - 1; i++)
	{
		LNodePtr = LNodePtr->getNextPtr();
	}
	LNodePtr->setNextPtr(LNodePtr->getNextPtr()->getNextPtr());
}

template <typename T>
void List<T>::clear()
{
	LNode<T> *tempPtr = startPtr;
	while (startPtr != NULL)
	{
		tempPtr = startPtr->getNextPtr();
		delete startPtr;
		startPtr = tempPtr;
	}
}

template <typename T>
T List<T>::getEntry(int pos)
{
	LNode<T>* LNodePtr = startPtr;
	for (int i = 1; i < pos; i++)
	{
		LNodePtr = LNodePtr->getNextPtr();
	}
	return LNodePtr->getData();
}

template <typename T>
void List<T>::insertByPos(int pos, T entry)
{
	if (pos == 1)
	{
		insertBegin(entry);
		return;
	}
	if (pos == getLength())
	{
		insertEnd(entry);
		return;
	}
	LNode<T>* LNodePtr = startPtr;
	LNode<T>* tempPtr = startPtr;
	LNode<T>* newPtr = new LNode<T>(entry);

	for (int i = 1; i < pos - 1; i++)
	{
		LNodePtr = LNodePtr->getNextPtr();
		tempPtr = tempPtr->getNextPtr();
	}
	tempPtr = tempPtr->getNextPtr();
	LNodePtr->setNextPtr(newPtr);
	newPtr->setNextPtr(tempPtr);
}

template <typename T>
void List<T>::writeToFile(ostream &outFile)
{
	if (isEmpty())
	{
		outFile << "The list is empty" << endl;
	}
	else
	{
		LNode<T> * currentPtr = startPtr;

		while (currentPtr != NULL) //prints until the end of the list is reached
		{
			outFile << currentPtr->data << endl;
			currentPtr = currentPtr->getNextPtr(); //moves to next LNode in list
		}
	}
}

#endif 