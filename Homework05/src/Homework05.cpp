//============================================================================
// Name        : Homework05.cpp
// Author      : Damon Wolfgang Duckett
// Version     :
// Copyright   : What copyright?
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "DataStructureTester.h"
#include "ChainedHashTable.h"
#include "LinearHashTable.h"
#include "BinarySearchTree.h"
#include "RedBlackTree.h"
#include "List.h"
using namespace std;
using namespace ods;

int main() {
	cout << "first up for a test is the Chained Hash Table." << endl << "Let the tests begin" << endl;
	DataStructureTester<ChainedHashTable<int> > chain;
	chain.StressTest();
	cout << "And thus ends the testing of the Chained Hash Table" << endl << endl;

	cout << "next up for testing is a Linear Hash Table" << endl;
	DataStructureTester<LinearHashTable<int> > linear;
	linear.StressTest();
	cout << "and this ends the testing for the Linear Hash Table" << endl << endl;

	cout << "Next for testing is Red Black Trees" << endl;
	//RedBlackTree<BSTNode1<int>, int> tree;
	DataStructureTester<RedBlackTree<BSTNode1<int>, int> > tree;
	tree.StressTest();
	cout << "And this ends all of the testing";

	/*Now I just need to encapsulate this process and repeat the process on every other data structure*/

	return 0;
}




