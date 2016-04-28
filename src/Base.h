/*
 * Base.h
 *
 *  Created on: Apr 25, 2016
 *      Author: matt
 */

#ifndef BASE_H_
#define BASE_H_
#include <iostream>
using namespace std;

class Base {
public:
	string bName; //base name
	int bPower; //power
	int bPowerBonus; //power bonus
	int bLuck; //luck
	double bAttractionBonus; //added to cheese attraction rate
	bool inInventory; //do you have it?


	Base();
	Base(string, int, int, int, double, bool);
	virtual ~Base();
};

#endif /* BASE_H_ */
