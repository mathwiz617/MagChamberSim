/*
 * Trap.h
 *
 *  Created on: Apr 25, 2016
 *      Author: matt
 */

#ifndef TRAP_H_
#define TRAP_H_

#include "Inventory.h"

class Trap {
public:
	Base base;
	Charm charm;
	Cheese cheese;
	Weapon weapon;
	int charmsRemaining;
	int cheeseRemaining;
	int trapPower; //total power before bonus
	int trapLuck; //total luck, no bonuses
	double trapPowerTotal; //total power
	double powerBonus; //power bonus
	double attractionRateBonus; //bonus to cheese attraction rate
	double attractionRate; //total attraction rate
	bool sheild; //Does your trap get +7 luck?

	Trap();
	Trap(Base, Charm, Cheese, Weapon, bool);
	virtual ~Trap();
};

#endif /* TRAP_H_ */
