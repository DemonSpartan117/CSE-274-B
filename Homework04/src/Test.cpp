//============================================================================
// Name        : Homework04.cpp
// Author      : Damon Wolfgang Duckett
// Version     :
// Copyright   : What copyright?
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "BinaryTree.h"
#include "BinarySearchTree.h"
using namespace ods;
using namespace std;


int main() {
	cout << "Time to start Binary Trees for homework" << endl; // prints Time to start Binary Trees for homework
	BinarySearchTree<BSTNode1<int>, int> tree1;
	tree1.add(15);
	tree1.add(2);
	tree1.add(3);
	cout << tree1.height() << endl;

	return 0;
}
