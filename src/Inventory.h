/*
 * Inventory.h
 *
 *  Created on: Apr 26, 2016
 *      Author: matt
 */

#ifndef INVENTORY_H_
#define INVENTORY_H_

#include "Base.h"
#include "Charm.h"
#include "Cheese.h"
#include "Weapon.h"

class Inventory {
public:
	//declare weapons
	Weapon iceMaiden;
	Weapon powerTrap;
	Weapon luckTrap;
	Weapon bestTrap;
	Weapon invalidWeapon;
	Weapon weaponArmed;

	//declare bases
	Base rift;
	Base invalidBase;
	Base baseArmed;

	//declare charms
	Charm otherCharm;
	Charm noCharm;
	Charm ultimate;
	Charm dragon;
	Charm charmArmed;

	//declare cheeses
	Cheese otherCheese;
	Cheese gouda;
	Cheese fieryFondue;
	Cheese moltenHavarti;
	Cheese treasureHavarti;
	Cheese cheeseArmed;

	int trapPower; //total power before bonus
	int trapLuck; //total luck, no bonuses
	double trapPowerTotal; //total power
	double powerBonus; //power bonus
	double attractionRateBonus; //bonus to cheese attraction rate
	double attractionRate; //total attraction rate
	bool shield; //Does your trap get +7 luck?


	Inventory();
	virtual ~Inventory();
};

#endif /* INVENTORY_H_ */
