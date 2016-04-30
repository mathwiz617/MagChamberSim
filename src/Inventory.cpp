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
	iceMaiden = Weapon::Weapon("Ice Maiden", 5200, 12, 8, 0.0, true, false);
	powerTrap = Weapon::Weapon("Power", 20000, 50, 50, 0.0, false, false);
	luckTrap = Weapon::Weapon("Luck", 15000, 30, 90, 0.0, false, false);
	bestTrap = Weapon::Weapon("Best", 40000, 60, 90, 0.0, true, false);
	invalidWeapon = Weapon::Weapon();
	weaponArmed = Weapon::Weapon();

	//define bases
	//("Name", power, power bonus, luck, attraction bonus, owned)
	rift = Base::Base("Rift Base", 250, 12, 11, 0.0, true, false);
	mino = Base::Base("Minotaur Base", 1000, 20, 15, 10.0, true, false);
	basalt = Base::Base("Basalt Base", 3000, 40, 30, 0.0, true, false);
	invalidBase = Base::Base();
	baseArmed = Base::Base();

	//define charms
	//("Name", power, power bonus, luck, number owned, attraction bonus)
	otherCharm = Charm::Charm("NYI", 0, 0, 0, 0, 0.0, false);
	ultimate = Charm::Charm("Ultimate", 0, 0, 0, 0, 0.0, false);
	dragon = Charm::Charm("Dragon", 10000, 40, 30, 0, 0.0, true);
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

