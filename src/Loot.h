/*
 * Loot.h
 *
 *  Created on: Apr 25, 2016
 *      Author: matt
 */

#ifndef LOOT_H_
#define LOOT_H_
#include <iostream>
#include <vector>
using namespace std;

class Loot {
public:
	string lName; //loot type
	int numPossible; //max dropped
	vector<double> chance; //chances of each successive drop

	Loot();
	Loot(string, int);
	virtual ~Loot();
};

#endif /* LOOT_H_ */
