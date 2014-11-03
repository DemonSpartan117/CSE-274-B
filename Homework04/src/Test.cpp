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

void PrintBalanceResult(bool ToF) {
	if(ToF) {
		cout << "The tree is balanced" << endl;
	}
	else {
		cout << "The tree is not balanced" << endl;
	}
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

	cout << endl << "Time to test the is balanced function now" <<endl;

	PrintBalanceResult(tree1.isBalanced()); //the proper result is returned

	BinarySearchTree<BSTNode1<int>, int> tree2;
	tree2.add(50);
	//PrintBalanceResult(tree2.isBalanced());
	tree2.add(25);
	//PrintBalanceResult(tree2.isBalanced());
	tree2.add(75);
	//PrintBalanceResult(tree2.isBalanced());
	tree2.add(90);
	//PrintBalanceResult(tree2.isBalanced());
	/*if all the above return true I know that most of my logic
	 * is correct in the parts with the size of the child nodes
	 * are equal or only differ by one (or don't exist)*/
	/*NOTE: they all passed as expected. To see proof just uncomment
	 * the test code above. I commented them out so the consul will
	 * be less cluttered.Now to continue testing without checking to
	 * see if it is balanced after every addition to the binary search
	 * tree (but still need to see frequently*/

	tree2.add(100);
	PrintBalanceResult(tree2.isBalanced());//not balanced now
	tree2.add(30);
	tree2.add(65);
	tree2.add(15);
	tree2.add(5);
	PrintBalanceResult(tree2.isBalanced()); //balanced again
	tree2.add(80);
	tree2.add(20);
	PrintBalanceResult(tree2.isBalanced());//not balanced
	tree2.add(29);
	tree2.add(70);
	PrintBalanceResult(tree2.isBalanced());//balanced it again and I am done

	cout << endl << "now isBalanced has been tested so moving on" << endl << endl;

	return 0;
}

