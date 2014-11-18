/*
 * DataStructureTesyer.h
 *
 *  Created on: Nov 13, 2014
 *      Author: ducketdw
 */

#ifndef DATASTRUCTURETESTER_H_
#define DATASTRUCTURETESTER_H_

#include <iostream>
#include "List.h"
#include <time.h>
#include <cstdlib>

using namespace std;
namespace ods {

template<class L>
class DataStructureTester {
protected:
  L list;

  int randomNum() {
  		return rand();
  	}

public:
  void DoSomething(int x);
  int DoSequentialAdd(int start, int end, int step);
  int DoRandomAdd(int n);
  int DoSequentialRemove(int start, int end, int step);
  int DoRandomRemove(int n);
  int DoSequentialFind(int start, int end, int step);
  int DoRandomFind(int n);
  void StressTest();
};

template<class L>
void DataStructureTester<L>::DoSomething(int x) {
  list.add(x);
  cout << list.find(x) << endl;
}

template<class L>
int DataStructureTester<L>::DoSequentialAdd(int start, int end, int step) {
	clock_t t;
	t = clock();
	for(int i = start; i <= end; i += step) {
		list.add(i);
	}
	return (clock() - t) * 1000;
}

template<class L>
int DataStructureTester<L>::DoRandomAdd(int n) {
	clock_t t;
	t = clock();

	int num = 0;
	for(int i = 0; i < n; i++) {
		num = rand();
		if(rand() % 2 == 0) {
			num *= -1;
		}
		list.add(num);
	}
	return (clock() - t) * 1000;
}

template<class L>
int DataStructureTester<L>::DoSequentialRemove(int start, int end, int step) {
	clock_t t;
	t = clock();

	for(int i = start; i <= end; i += step) {
		list.remove(i);
	}

	return (clock() - t) * 1000;
}

template<class L>
int DataStructureTester<L>::DoRandomRemove(int n) {
	clock_t t;
	t = clock();

	int num = 0;
	for(int i = 0; i < n; i++) {
		num = rand();
		if(rand() % 2 == 0) {
			num *= -1;
		}
		list.remove(num);
	}

	return (clock() - t) * 1000;
}

template<class L>
int DataStructureTester<L>::DoSequentialFind(int start, int end, int step) {
	clock_t t;
	t = clock();

	for(int i = start; i < end; i += step) {
		list.find(i);
	}

	return (clock() - t) * 1000;
}

template<class L>
int DataStructureTester<L>::DoRandomFind(int n) {
	clock_t t;
	t = clock();

	int num = 0;
	for(int i = 0; i < n; i++) {
		num = rand();
		if(rand() % 2 == 0) {
			num *= -1;
		}
		list.find(num);
	}

	return (clock() - t) * 1000;
}

template<class L>
void DataStructureTester<L>::StressTest() {
	cout << "the time to do sequential add from -100,000 to 100,000 by steps of 2 was: ";
		cout << DoSequentialAdd(-100000, 100000, 2) << endl;
		cout << "the time to randomly add an additional 100,000 random items: ";
		cout << DoRandomAdd(100000) << endl;
		cout << "the time it took to find items added sequentially from above: ";
		cout << DoSequentialFind(-100000, 100000, 2) << endl;
		cout << "the time it took to do 100,000 random finds: ";
		cout << DoRandomFind(100000) << endl;
		cout << "the time it takes to remove the items sequentially added from above: ";
		cout << DoSequentialRemove(-100000, 100000, 2) << endl;
		cout << "the time it took to do 100,000 random removes";
		cout << DoRandomRemove(100000) << endl;
}

};

#endif /* DATASTRUCTURETESYER_H_ */
