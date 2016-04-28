/*
 * Charm.h
 *
 *  Created on: Apr 25, 2016
 *      Author: matt
 */

#ifndef CHARM_H_
#define CHARM_H_
#include <iostream>
using namespace std;

class Charm {
public:
	string charmName; //charm name
	int charmPower; //power
	int charmPowerBonus; //power bonus
	int charmLuck; //luck
	int amount;
	double charmAttractionBonus; //added to cheese attraction rate

	Charm();
	Charm(string, int, int, int, int, double);
	virtual ~Charm();
};

#endif /* CHARM_H_ */
