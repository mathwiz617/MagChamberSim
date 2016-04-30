/*
 * Weapon.h
 *
 *  Created on: Apr 25, 2016
 *      Author: matt
 */

#ifndef WEAPON_H_
#define WEAPON_H_
#include <iostream>
using namespace std;

class Weapon {
public:
	string wName; //name
	int wPower; //power
	int wPowerBonus; //power bonus
	int wLuck; //luck
	double wAttractionBonus; //added to cheese attraction rate
	bool inInventory; //do you have it?
	bool inSet; //Is it part of the Dragonslayer set?

	Weapon();
	Weapon(string, int, int, int, double, bool, bool);
	virtual ~Weapon();
};

#endif /* WEAPON_H_ */
