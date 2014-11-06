/*
 * BinarySearchTree.h
 *
 *  Created on: 2011-11-28
 *      Author: morin
 */

#ifndef BINARYSEARCHTREE_H_
#define BINARYSEARCHTREE_H_
#include <climits>
#include <cmath>
#include "BinaryTree.h"
#include "utils.h"
#include "DLList.h"

using namespace std;
namespace ods {

template<class Node, class T>
class BSTNode: public BTNode<Node> {
public:
	T x;
	int inOrder;
	int postOrder;
	int preOrder;
};

/**
 * A binary search tree class.  The Node parameter should be a subclass
 * of BSTNode<T> (or match it's interface)
 */
template<class Node, class T>
class BinarySearchTree: public BinaryTree<Node> {
protected:
	using BinaryTree<Node>::r;
	using BinaryTree<Node>::nil;
	int n;
	T null;
	virtual Node *findLast(T x);
	virtual bool addChild(Node *p, Node *u);
	virtual void splice(Node *u);
	virtual void remove(Node *u);
	virtual void rotateRight(Node *u);
	virtual void rotateLeft(Node *u);
	virtual bool add(Node *u);
	//below methods made for homework
	virtual void preOrderNumber(Node *current, int* count);
	virtual void postOrderNumber(Node *current, int* count);
	virtual void inOrderNumber(Node *current, int* count);
	virtual bool getLE(T data, Node *current, DLList<T> *list);
public:
	BinarySearchTree();
	BinarySearchTree(T null);
	virtual ~BinarySearchTree();
	virtual bool add(T x);
	virtual bool remove(T x);
	virtual T find(T x);
	virtual T findEQ(T x);
	virtual int size();
	virtual void clear();
	//below methods made for homework
	virtual void preOrderNumber();
	virtual void postOrderNumber();
	virtual void inOrderNumber();
	virtual DLList<T> getLE(T x);
};

template<class T>
class BSTNode1: public BSTNode<BSTNode1<T>, T> {
};

template<class T>
class BinarySearchTree1: public BinarySearchTree<BSTNode1<T>, T> {
public:
	BinarySearchTree1();
};

/*
 * FIXME: Why doesn't this work?
 template<class Node>
 BinarySearchTree<Node,int>::BinarySearchTree()  {
 this->null = INT_MIN;
 n = 0;
 }
 */

template<class Node, class T>
BinarySearchTree<Node, T>::BinarySearchTree() {
	this->null = (T) NULL;  // won't work for non-primitive types
	n = 0;
}

template<class Node, class T>
BinarySearchTree<Node, T>::BinarySearchTree(T null) {
	this->null = null;
	n = 0;
}

template<class Node, class T>
Node* BinarySearchTree<Node, T>::findLast(T x) {
	Node *w = r, *prev = nil;
	while (w != nil) {
		prev = w;
		int comp = compare(x, w->x);
		if (comp < 0) {
			w = w->left;
		} else if (comp > 0) {
			w = w->right;
		} else {
			return w;
		}
	}
	return prev;
}

template<class Node, class T>
T BinarySearchTree<Node, T>::findEQ(T x) {
	Node *w = r;
	while (w != nil) {
		int comp = compare(x, w->x);
		if (comp < 0) {
			w = w->left;
		} else if (comp > 0) {
			w = w->right;
		} else {
			return w->x;
		}
	}
	return null;
}

template<class Node, class T>
T BinarySearchTree<Node, T>::find(T x) {
	Node *w = r, *z = nil;
	while (w != nil) {
		int comp = compare(x, w->x);
		if (comp < 0) {
			z = w;
			w = w->left;
		} else if (comp > 0) {
			w = w->right;
		} else {
			return w->x;
		}
	}
	return z == nil ? null : z->x;
}

template<class Node, class T>
BinarySearchTree<Node, T>::~BinarySearchTree() {
	// nothing to do - BinaryTree destructor does cleanup
}

template<class Node, class T>
bool BinarySearchTree<Node, T>::addChild(Node *p, Node *u) {
	if (p == nil) {
		r = u;              // inserting into empty tree
	} else {
		int comp = compare(u->x, p->x);
		if (comp < 0) {
			p->left = u;
		} else if (comp > 0) {
			p->right = u;
		} else {
			return false;   // u.x is already in the tree
		}
		u->parent = p;
	}
	n++;
	return true;
}

template<class Node, class T>
bool BinarySearchTree<Node, T>::add(T x) {
	Node *p = findLast(x);
	Node *u = new Node;
	u->x = x;
	return addChild(p, u);
}

template<class Node, class T>
bool BinarySearchTree<Node, T>::add(Node *u) {
	Node *p = findLast(u->x);
	return addChild(p, u);
}

template<class Node, class T>
void BinarySearchTree<Node, T>::splice(Node *u) {
	Node *s, *p;
	if (u->left != nil) {
		s = u->left;
	} else {
		s = u->right;
	}
	if (u == r) {
		r = s;
		p = nil;
	} else {
		p = u->parent;
		if (p->left == u) {
			p->left = s;
		} else {
			p->right = s;
		}
	}
	if (s != nil) {
		s->parent = p;
	}
	n--;
}

template<class Node, class T>
void BinarySearchTree<Node, T>::remove(Node *u) {
	if (u->left == nil || u->right == nil) {
		splice(u);
		delete u;
	} else {
		Node *w = u->right;
		while (w->left != nil)
			w = w->left;
		u->x = w->x;
		splice(w);
		delete w;
	}
}

template<class Node, class T>
bool BinarySearchTree<Node, T>::remove(T x) {
	Node *u = findLast(x);
	if (u != nil && compare(x, u->x) == 0) {
		remove(u);
		return true;
	}
	return false;
}

template<class Node, class T> inline
int BinarySearchTree<Node, T>::size() {
	return n;
}

template<class Node, class T> inline
void BinarySearchTree<Node, T>::clear() {
	BinaryTree<Node>::clear();
	n = 0;
}

template<class Node, class T>
void BinarySearchTree<Node, T>::rotateLeft(Node *u) {
	Node *w = u->right;
	w->parent = u->parent;
	if (w->parent != nil) {
		if (w->parent->left == u) {
			w->parent->left = w;
		} else {
			w->parent->right = w;
		}
	}
	u->right = w->left;
	if (u->right != nil) {
		u->right->parent = u;
	}
	u->parent = w;
	w->left = u;
	if (u == r) {
		r = w;
		r->parent = nil;
	}
}

template<class Node, class T>
void BinarySearchTree<Node, T>::rotateRight(Node *u) {
	Node *w = u->left;
	w->parent = u->parent;
	if (w->parent != nil) {
		if (w->parent->left == u) {
			w->parent->left = w;
		} else {
			w->parent->right = w;
		}
	}
	u->left = w->right;
	if (u->left != nil) {
		u->left->parent = u;
	}
	u->parent = w;
	w->right = u;
	if (u == r) {
		r = w;
		r->parent = nil;
	}
}

/* all of the cout statements are strictly for testing purposes and should be ignored.
 * They are needed to make the testing class work and that is a part of the assignment
 * so there you go. I don't like it but it's what I got.*/
template<class Node, class T>
void BinarySearchTree<Node, T>::preOrderNumber() {
	int count = 0;
	cout << "time for some Pre-Ordered Numbers" << endl << endl;
	preOrderNumber(r, &count);
	cout << "end of the pre-ordered numbers" << endl << endl;
}

template<class Node, class T>
void BinarySearchTree<Node, T>::preOrderNumber(Node *current, int* count) {

	if (current == nil)
		return;

	*count = *count + 1;
	current->preOrder = *count;
	cout << "Node: " << current->x << " has pre ordered number "
			<< current->preOrder << endl;

	preOrderNumber(current->left, count);
	preOrderNumber(current->right, count);
}

template<class Node, class T>
void BinarySearchTree<Node, T>::inOrderNumber() {
	int count = 0;
	cout << "time for some In Order Numbers" << endl << endl;
	inOrderNumber(r, &count);
	cout << "end of the in ordered numbers" << endl << endl;
}

template<class Node, class T>
void BinarySearchTree<Node, T>::inOrderNumber(Node *current, int* count) {

	if (current == nil)
		return;

	inOrderNumber(current->left, count);

	*count = *count + 1;
	current->inOrder = *count;
	cout << "Node: " << current->x << " has in ordered number "
			<< current->inOrder << endl;

	inOrderNumber(current->right, count);
}

template<class Node, class T>
void BinarySearchTree<Node, T>::postOrderNumber() {
	int count = 0;
	cout << "time for some Post Order Numbers" << endl << endl;
	postOrderNumber(r, &count);
	cout << "end of the post ordered numbers" << endl << endl;
}

template<class Node, class T>
void BinarySearchTree<Node, T>::postOrderNumber(Node *current, int* count) {

	if (current == nil)
		return;

	postOrderNumber(current->left, count);
	postOrderNumber(current->right, count);

	*count = *count + 1;
	current->postOrder = *count;
	cout << "Node: " << current->x << " has post ordered number "
			<< current->postOrder << endl;
}

/*
 template<class T>
 BinarySearchTree1<T*>::BinarySearchTree1() : BinarySearchTree<BSTNode1<T*>, T*>(NULL) {
 }
 */

template<class Node, class T>
DLList<T> BinarySearchTree<Node, T>::getLE(T data) {
	/* need to pay attention to lecture so I will come back to this
	 * and when I do I will need to re-think my approach to this method
	 * because after the first two lines below, the code is not usable
	 * or I need to figure out exactly how to approach this*/
	DLList<T> list;
	Node *prev = r;
	Node *current = r->left;
	while (current != nil) { //this while loop makes current the smallest element in the tree
		prev = current;
		current = current->left;
	} //now temp is set as the smallest element
	current = prev; //now current is smallest too

	Node *next;
	prev = nil;
	bool isTooBig = false;
	while (current != nil) {
		isTooBig = !getLE(data, current, &list);
		if(!isTooBig && current->left == nil && current->right == nil) {
			list.add(current->x);
			/*so adding current->x if it is not too big and it has no children
			 * because current will not be visited again*/
		}


		if (prev == current->parent) {
			if (isTooBig && current->left != nil) {
				next = current->left;
			}

			else if (!isTooBig && current->right != nil) {
				next = current->right;
			} else
				next = current->parent;
		} else if (prev == current->left) {
			if(!isTooBig && current->left != nil) {
				list.add(current->x);
			}

			if (isTooBig)
				break;

			if (current->right != nil)
				next = current->right;
			else
				next = current->parent;
		} else {
			next = current->parent;
			if(!isTooBig && current->left == nil && current->right != nil) {
				list.add(current->x);
			}
		}
		prev = current;
		current = next;
	}

	return list;
}

template<class Node, class T>
bool BinarySearchTree<Node, T>::getLE(T data, Node *current, DLList<T> *list) {
	if (current->x > data) {
		return false;
	}
	if (current->x <= data) {

		return true;
	}
	return true;
}
template<class T>
BinarySearchTree1<T>::BinarySearchTree1() {
}

} /* namespace ods */
#endif /* BINARYSEARCHTREE_H_ */
