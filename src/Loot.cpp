/*
 * Loot.cpp
 *
 *  Created on: Apr 25, 2016
 *      Author: matt
 */

#include "Loot.h"

Loot::Loot() {
	lName = "None!";
	numPossible = 1;
	chance.resize(1);
	chance.at(0) = 0;
}

Loot::Loot(string name, int numMax){
	lName = name;
	numPossible = numMax;
	chance.resize(1);
	chance.at(0) = 0;
}

Loot::~Loot() {

}

