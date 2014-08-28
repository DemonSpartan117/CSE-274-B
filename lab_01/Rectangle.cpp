/*
 * Rectangle.cpp
 *
 *  Created on: Aug 28, 2014
 *      Author: ducketdw
 */

#include "Rectangle.h"
void Rectangle::set_values(int x, int y) {
	width = x;
	height = y;
}

int Rectangle::area() {
	return height*width;
}
