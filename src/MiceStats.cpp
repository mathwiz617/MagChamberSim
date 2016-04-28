/*
 * MiceStats.cpp
 *
 *  Created on: Apr 26, 2016
 *      Author: matt
 */

#include "MiceStats.h"

MiceStats::MiceStats() {
	//define mice here
	//("Name", power, bait tier, point value, gold value, attraction odds at the right tier)
	none = Mouse::Mouse("None", 0, 0, 0, 0, 0.0);
	heated =  Mouse::Mouse("Superheated", 1500, 1, 50000, 5000, .4);
	magma = Mouse::Mouse("Magma", 1500, 1, 30000, 3000, .6);
	gDragon = Mouse::Mouse("Green Dragon", 3000, 2, 50000, 50000, .3);
	rDragon = Mouse::Mouse("Red Dragon", 3000, 2, 100000, 10000, .3);
	bDragon = Mouse::Mouse("Blue Dragon", 3000, 2, 10000, 100000, .3);
	blkDragon = Mouse::Mouse("Black Dragon", 4000, 2, 100000, 100000, .1);
	mother = Mouse::Mouse("Broodmother", 8000, 3, 1000000, 1000000, 1);
	attracted = Mouse::Mouse();
}

MiceStats::~MiceStats() {
	// TODO Auto-generated destructor stub
}

