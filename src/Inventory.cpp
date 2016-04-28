/*
 * Inventory.cpp
 *
 *  Created on: Apr 26, 2016
 *      Author: matt
 */

#include "Inventory.h"

Inventory::Inventory() {
	//define pieces of trap here

	//define weapons
	//("Name", power, power bonus, luck, attraction bonus, owned)
	iceMaiden = Weapon::Weapon("Ice Maiden", 5200, 12, 8, 0.0, true);
	powerTrap = Weapon::Weapon("Power", 7000, 15, 0, 0.0, false);
	luckTrap = Weapon::Weapon("Luck", 4000, 7, 30, 0.0, false);
	bestTrap = Weapon::Weapon("Best", 8000, 20, 30, 0.0, false);
	invalidWeapon = Weapon::Weapon();
	weaponArmed = Weapon::Weapon();

	//define bases
	//("Name", power, power bonus, luck, attraction bonus, owned)
	rift = Base::Base("Rift Base", 250, 12, 11, 0.0, true);
	invalidBase = Base::Base();
	baseArmed = Base::Base();

	//define charms
	//("Name", power, power bonus, luck, number owned, attraction bonus)
	otherCharm = Charm::Charm("NYI", 0, 0, 0, 0, 0.0);
	ultimate = Charm::Charm("Ultimate", 0, 0, 0, 0, 0.0);
	noCharm = Charm::Charm();
	charmArmed = noCharm;

	//define cheeses
	//("Name", bait tier, owned, attraction, store-bought, regular)
	otherCheese = Cheese::Cheese("NYI", 0, 0, 0, false);
	gouda = Cheese::Cheese("Gouda", 1, 0, .85, true);
	fieryFondue = Cheese::Cheese("Fiery Fondue", 1, 0, .9, false);
	moltenHavarti = Cheese::Cheese("Molten Havarti", 2, 0, .99, true);
	treasureHavarti = Cheese::Cheese("Treasure Hoard Havarti", 3, 0, 1, false);
	cheeseArmed = Cheese::Cheese();

	//other variables defined here
	shield = false;
	powerBonus = 0.0;
	trapPower = 0;
	trapPowerTotal = 0.0;
	trapLuck = 0;
	attractionRateBonus = 0;
	attractionRate = 0;
}

Inventory::~Inventory() {
	// TODO Auto-generated destructor stub
}

