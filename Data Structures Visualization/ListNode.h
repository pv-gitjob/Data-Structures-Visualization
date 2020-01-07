#pragma once
#ifndef ListNode_h
#define ListNode_h

template <typename T>
class LNode //LNodes to be contained with a list
{

public:
	LNode(T);
	~LNode();
	T getData();
	LNode* getNextPtr();
	void setNextPtr(LNode*);
	T data; //templatized data stored in LNode
	LNode* nextPtr; //pointer to the next LNode in list
};

template <typename T>
LNode<T>::LNode(T dataIn)
{
	data = dataIn; //stores data in LNode
	setNextPtr(0); //initializes point to next LNode to null
}

template <typename T>
LNode<T>::~LNode()
{

}

template <typename T>
T LNode<T>::getData() //returns data stored in LNode
{
	return data;
}
template <typename T>
LNode<T>* LNode<T>::getNextPtr()
{
	return nextPtr;
}
template <typename T>
void LNode<T>::setNextPtr(LNode<T>* ptr) {
	nextPtr = ptr;
}
#endif