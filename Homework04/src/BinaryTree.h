/*
 * BinaryTree.h
 *
 *  Created on: 2011-11-28
 *      Author: morin
 */

#ifndef BINARYTREE_H_
#define BINARYTREE_H_
#include <cstdlib>

#include "ArrayDeque.h"

using namespace std;
namespace ods {

template<class N>
class BTNode {
public:
	N *left;
	N *right;
	N *parent;
	BTNode() {
		left = right = parent = NULL;
	}
};


template<class Node>
class BinaryTree {
protected:
	Node *r;    // root node
	Node *nil;  // null-like node
	virtual int size(Node *u);
	virtual int height(Node *u);
	virtual void traverse(Node *u);
public:
	virtual ~BinaryTree();
	BinaryTree();
	BinaryTree(Node *nil);
	virtual void clear();
	virtual int depth(Node *u);
	virtual int size();
	virtual int size2();
	virtual int height();
	virtual void traverse();
	virtual void traverse2();
	virtual void bfTraverse();
	virtual int height2(Node* current); //one of my added methods for homework
};

class BTNode1 : public BTNode<BTNode1> { };


template<class Node>
BinaryTree<Node>::~BinaryTree() {
	clear();
}

template<class Node>
void BinaryTree<Node>::clear() {
	Node *u = r, *prev = nil, *next;
	while (u != nil) {
		if (prev == u->parent) {
			if (u->left != nil) next = u->left;
			else if (u->right != nil) next = u->right;
			else next = u->parent;
		} else if (prev == u->left) {
			if (u->right != nil) next = u->right;
			else next = u->parent;
		} else {
			next = u->parent;
		}
		prev = u;
		if (next == u->parent)
			delete u;
		u = next;
	}
	r = nil;
}

template<class Node>
BinaryTree<Node>::BinaryTree(Node *nil) {
	this->nil = nil;
	r = nil;
}

template<class Node>
BinaryTree<Node>::BinaryTree() {
	nil = NULL;
	r = nil;
}


template<class Node>
int BinaryTree<Node>::depth(Node *u) {
	int d = 0;
	while (u != r) {
		u = u->parent;
		d++;
	}
	return d;
}

template<class Node>
int BinaryTree<Node>::size() {
	return size(r);
}

template<class Node>
int BinaryTree<Node>::size(Node *u) {
	if (u == nil) return 0;
	return 1 + size(u->left) + size(u->right);
}

template<class Node>
int BinaryTree<Node>::size2() {
		Node *u = r, *prev = nil, *next;
		int n = 0;
		while (u != nil) {
			if (prev == u->parent) {
				n++;
				if (u->left != nil) next = u->left;
				else if (u->right != nil) next = u->right;
				else next = u->parent;
			} else if (prev == u->left) {
				if (u->right != nil) next = u->right;
				else next = u->parent;
			} else {
				next = u->parent;
			}
			prev = u;
			u = next;
		}
		return n;
	}


template<class Node>
int BinaryTree<Node>::height() {
	/*the below cout statement is for testing purposes only
	 * I added it to make sure the height2 and height methods
	 * get the same results*/
	cout << "height2 output: " << height2(r) << endl;
	return height(r);
}

template<class Node>
int BinaryTree<Node>::height(Node *u) {
	if (u == nil) return -1;
	return 1 + max(height(u->left), height(u->right));
}

template<class Node>
void BinaryTree<Node>::traverse() {
	traverse(r);
}

template<class Node>
void BinaryTree<Node>::traverse(Node *u) {
		if (u == nil) return;
		traverse(u->left);
		traverse(u->right);
}

template<class Node>
void BinaryTree<Node>::traverse2() {
	Node *u = r, *prev = nil, *next;
	while (u != nil) {
		if (prev == u->parent) {
			if (u->left != nil) next = u->left;
			else if (u->right != nil) next = u->right;
			else next = u->parent;
		} else if (prev == u->left) {
			if (u->right != nil) next = u->right;
			else next = u->parent;
		} else {
			next = u->parent;
		}
		prev = u;
		u = next;
	}
}

template<class Node>
void BinaryTree<Node>::bfTraverse() {
	ArrayDeque<Node*> q;
	if (r != nil) q.add(q.size(),r);
	while (q.size() > 0) {
		Node *u = q.remove(q.size()-1);
		if (u->left != nil) q.add(q.size(),u->left);
		if (u->right != nil) q.add(q.size(),u->right);
	}
}

/* the below is the first method I created for the
 * homework. (Tested and proved to work)*/
template<class Node>
int BinaryTree<Node>::height2(Node* current) {
	/* only increment the compare int. height will be
	 * determined by comparing the biggest height so far
	 * to what compare is at the moment (so the depth of
	 * the current node).*/
	int height = 0;
	int compare = 0;
	/* The below is copied and pasted from the traverse2 function
	 * I will use it as a basis for the height2 function*/
	Node *prev = nil, *next;
		while (current != nil) {

			if(height < compare && current != nil) {
				height = compare;
			}//stand alone for our height variable

			if (prev == current->parent) {

				if (current->left != nil) {
					next = current->left;
					compare++;
				}

				else if (current->right != nil) {
					next = current->right;
					compare++;
				}

				else {
					next = current->parent; // go back up
					compare--;
				}
			}//if statement

			else if (prev == current->left) { //when coming back up from the left

				if (current->right != nil) {
					next = current->right;
					compare++;
				}

				else {
					next = current->parent;
					compare--;
				}
			}//else if statement

			else {
				compare--;
				next = current->parent;
			}
			prev = current;
			current = next;
		}//end of copy and paste

		return height;
}



} /* namespace ods */
#endif /* BINARYTREE_H_ */
