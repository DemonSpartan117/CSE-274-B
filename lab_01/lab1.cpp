//============================================================================
// Name        : lab1.cpp
// Author      : Damon Duckett
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Rectangle.h"
using namespace std;



int main() {
	Rectangle rect;
	Rectangle rect2;

	Rectangle &refRect = rect;	/* Reference to the rect object and when making one of these you must make
	the reference of the object you want to reference in the line you create the reference
	(sounds weird but look at the syntax here and be good with it)*/

	Rectangle *pRect = new Rectangle(); //creating a pointer

	pRect->set_values(7,8); // -> is the operator you need to use to use pointer object's functions

	rect.set_values(2,5);
	rect2 = rect;			//this copies the rectangle but does not make a reference to the same object like Java would

	cout << "Area: " << rect.area() << endl;
	cout << "Area2: " << rect2.area() << endl;
	cout << "Area Pointer: " << pRect->area() << endl;
	cout << "Area Ref: " << refRect.area() << endl << endl;

	rect.set_values(6,9);

	cout << "Area: " << rect.area() << endl;
		cout << "Area2: " << rect2.area() << endl;
		cout << "Area Pointer: " << pRect->area() << endl;
		cout << "Area Ref: " << refRect.area() << endl << endl;
	refRect.set_values(2,3);

	cout << "Area: " << rect.area() << endl;
		cout << "Area2: " << rect2.area() << endl;
		cout << "Area Pointer: " << pRect->area() << endl;
		cout << "Area Ref: " << refRect.area() << endl;

	return 0;
}
