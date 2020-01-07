#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#include "BST.h"
#include "HashTable.h"
#include "List.h"

int main() {

	HashMap<int, int> hashtable;
	List<int> list;
	BinarySearchTree<int> bst;
	
	int array[] = { 5, 1, 9, 3, 7, 2, 4, 6, 8};
	for (int i = 0; i < 9; i++) {
		//cout << array[i] << endl;
		hashtable.insertNode(i, array[i]);
		list.insertByPos(i,array[i]);
		bst.insert(array[i]);
	}

	cout << endl;

	hashtable.display();
	list.print();
	bst.print_breadth();

}
