#pragma once
using namespace std;
#include "HashNode.h"
//template for generic type
template<typename K, typename V>

//Our own Hashmap class
class HashMap
{
private:
	HashNode<K, V> **arr;//hash element array
	int capacity;
	int size;//current size
	HashNode<K, V> *dummy;//dummy node
	int collisions = 0;//collision counter

public:
	HashMap();
	int hashCode(K key);
	void rehash();//rehash
	void insertNode(K key, V value);//Function to add key value pair
	V deleteNode(K key);//Function to delete a key value pair
	V get(K key);//Function to search the value for a given key
	int getCapacity();//Return capacity
	bool isEmpty();//Return true if size is 0
	void display();//Function to display the stored key value pairs
	int getCollisions();
	double loadFactor();
	int getSize();
	void keySequence();
};

template<typename K, typename V>
HashMap<K, V>::HashMap()
{
	//Initial capacity of hash array
	capacity = 100;
	size = 0;
	arr = new HashNode<K, V>*[capacity];

	//Initialise all elements of array as NULL
	for (int i = 0; i < capacity; i++)
		arr[i] = NULL;
}

// This implements hash function to find index
// for a key
// hash function adapted from: Thomas Wang https://gist.github.com/badboy/6267743
template<typename K, typename V>
int HashMap<K, V>::hashCode(K key)
{
	int c2 = 0x27d4eb2d; // a prime or an odd constant
	key = (key ^ 61) ^ (key >> 16);
	key = key + (key << 3);
	key = key ^ (key >> 4);
	key = key * c2;
	key = key ^ (key >> 15);
	return key % capacity;
}

//rehash
template<typename K, typename V>
void HashMap<K, V>::rehash()
{
	collisions = 0;
	capacity += 100;

	HashNode<K, V> *temp;

	HashNode<K, V> **tempArr = new HashNode<K, V>*[capacity];

	for (int i = 0; i < capacity; i++)
	{
		tempArr[i] = NULL;
	}

	for (int i = 0; i < capacity - 100; i++)
	{
		temp = arr[i];
		// Apply hash function to find index for given key
		int hashIndex = hashCode(arr[i]->key);

		//find next free space 
		while (tempArr[hashIndex] != NULL && tempArr[hashIndex]->key != hashCode(arr[i]->key))
		{
			hashIndex++;
			collisions++;
			hashIndex %= capacity;
		}

		//if new node to be inserted increase the current size
		if (tempArr[hashIndex] == NULL)
			size++;
		tempArr[hashIndex] = temp;
	}
	arr = tempArr;
}

//Function to add key value pair
template<typename K, typename V>
void HashMap<K, V>::insertNode(K key, V value)
{
	HashNode<K, V> *temp = new HashNode<K, V>(key, value);

	// Apply hash function to find index for given key
	int hashIndex = hashCode(key);

	//find next free space 
	while (arr[hashIndex] != NULL && arr[hashIndex]->key != key)
	{
		hashIndex++;
		collisions++;
		hashIndex %= capacity;
	}

	//if new node to be inserted increase the current size
	if (arr[hashIndex] == NULL)
		size++;
	arr[hashIndex] = temp;

	if (loadFactor()>80)
	{
		rehash();
	}
}

//Function to delete a key value pair
template<typename K, typename V>
V HashMap<K, V>::deleteNode(K key)
{
	// Apply hash function to find index for given key
	int hashIndex = hashCode(key);

	//finding the node with given key
	while (arr[hashIndex] != NULL)
	{
		//if node found
		if (arr[hashIndex]->key == key)
		{
			HashNode<K, V> *temp = arr[hashIndex];

			//Insert dummy node here for further use
			arr[hashIndex] = dummy;

			// Reduce size
			size--;
			return temp->value;
		}
		hashIndex++;
		hashIndex %= capacity;

	}

	//If not found;
	cout << "Not found" << endl;
	int temp = 0;
	while (arr[temp] == NULL)
	{
		temp++;
	}
	return arr[temp]->value;
}

//Function to search the value for a given key
template<typename K, typename V>
V HashMap<K, V>::get(K key)
{
	// Apply hash function to find index for given key
	int hashIndex = hashCode(key);

	//finding the node with given key   
	while (arr[hashIndex] != NULL)
	{
		//if node found return its value
		if (arr[hashIndex]->key == key)
			return arr[hashIndex]->value;
		hashIndex++;
		hashIndex %= capacity;
	}

	//If not found;
	cout << "Not found, here is a random value" << endl;
	int temp = 0;
	while (arr[temp] == NULL)
	{
		temp++;
	}
	return arr[temp]->value;
}

//Return current size 
template<typename K, typename V>
int HashMap<K, V>::getSize()
{
	return size;
}

//Return true if size is 0
template<typename K, typename V>
bool HashMap<K, V>::isEmpty()
{
	return size == 0;
}

//Function to display the stored key value pairs
template<typename K, typename V>
void HashMap<K, V>::display()
{
	for (int i = 0; i < capacity; i++)
	{
		if (arr[i] != NULL)
		{
			cout << "key = " << arr[i]->key << "  value = " << arr[i]->value << endl;
		}

	}
}

template<typename K, typename V>
int HashMap<K, V>::getCollisions()
{
	return collisions;
}

template<typename K, typename V>
double HashMap<K, V>::loadFactor()
{
	double temp = size;
	temp = temp / capacity * 100;
	return temp;
}

template<typename K, typename V>
int HashMap<K, V>::getCapacity()
{
	return capacity;
}

template<typename K, typename V>
void HashMap<K, V>::keySequence()
{
	HashNode<K, V> **tempArr = new HashNode<K, V>*[capacity];
	for (int i = 0; i < capacity; i++)
	{
		tempArr[i] = arr[i];
	}

	int j;
	HashNode<K, V>* temp;

	for (int i = 0; i < size; i++)
	{
		j = i;

		while (j > 0 && tempArr[j]->key < tempArr[j - 1]->key)
		{
			temp = tempArr[j];
			tempArr[j] = tempArr[j - 1];
			tempArr[j - 1] = temp;
			j--;
		}
	}

	for (int i = 0; i < size; i++)
	{
		cout << "key = " << tempArr[i]->key << "  value = " << tempArr[i]->value << endl;
	}
}
