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
	Charm charmArmed;

	//declare cheeses
	Cheese otherCheese;
	Cheese gouda;
	Cheese fieryFondue;
	Cheese moltenHavarti;
	Cheese treasureHavarti;
	Cheese cheeseArmed;

	Inventory();
	virtual ~Inventory();
};

#endif /* INVENTORY_H_ */
