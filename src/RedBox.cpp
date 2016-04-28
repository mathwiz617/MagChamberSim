/*
 * RedBox.cpp
 *
 *  Created on: Apr 25, 2016
 *      Author: matt
 */

#include "RedBox.h"

RedBox::RedBox() {
	type = 1;
	amount = 0;
}

RedBox::RedBox(int drained, int value){
	type = drained;
	amount = value;
}

RedBox::~RedBox() {
	// TODO Auto-generated destructor stub
}

