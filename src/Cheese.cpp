/*
 * Cheese.cpp
 *
 *  Created on: Apr 25, 2016
 *      Author: matt
 */

#include "Cheese.h"

Cheese::Cheese(){
	cheeseName = "Disarmed!";
	tier = 0;
	amount = 0;
	cheeseAttractionRate = 0;
	storeCheese = false;
}

Cheese::Cheese(string type, int baitTier, int stash, double atr, bool isStoreCheese) {
	cheeseName = type;
	tier = baitTier;
	amount = stash;
	cheeseAttractionRate = atr;
	storeCheese = isStoreCheese;
}

Cheese::~Cheese(){

}

