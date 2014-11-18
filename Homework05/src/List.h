/*
 * List.h
 *
 *  Created on: Nov 13, 2014
 *      Author: ducketdw
 */

#ifndef LIST_H_
#define LIST_H_

namespace ods {

template <class T>
class List {

	virtual T find(T x) = 0;
	virtual T remove(T x) = 0;
	virtual bool add(T x) = 0;
};




}

#endif /* LIST_H_ */
