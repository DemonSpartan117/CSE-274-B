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

int randomNum() {
	return rand();
}


int main() {
	cout << "Time to start Binary Trees for homework" << endl; // prints Time to start Binary Trees for homework
	BinarySearchTree<BSTNode1<int>, int> tree1;
	cout << endl << endl << "input for the random binary tree:" << endl << endl;
	int num = 0;
	for(int i = 0; i < 20; i++) {
		num = randomNum() % 1000;
		tree1.add(num);
		cout << num << ", ";
	}
	cout << endl;

	cout << "original height output: " << tree1.height() << endl;
	/* because both of the outputs of the height functions match
	 * i conclude that my version of the function does indeed work*/

	return 0;
}

