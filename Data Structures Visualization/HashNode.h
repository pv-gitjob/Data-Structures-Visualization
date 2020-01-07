#pragma once
//Hashnode class
using namespace std;

//template for generic type
template<typename K, typename V>
class HashNode
{
public:
	V value;
	K key;

	//Constructor of hashnode 
	HashNode(K key, V value)
	{
		this->value = value;
		this->key = key;
	}

	//Constructor of hashnode 
	HashNode()
	{

	}

	void copy(HashNode other)
	{
		value = other.value;
		key = other.key;
	}
};