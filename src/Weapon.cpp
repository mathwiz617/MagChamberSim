/*
 * Weapon.cpp
 *
 *  Created on: Apr 25, 2016
 *      Author: matt
 */

#include "Weapon.h"

Weapon::Weapon() {
	wName = "Disarmed!";
	wPower = 0;
	wPowerBonus = 0;
	wLuck = 0;
	wAttractionBonus = 0;
	inInventory = false;
	inSet = false;
}

Weapon::Weapon(string type, int pow, int powBonus, int lck, double atrBonus, bool have, bool set) {
	wName = type;
	wPower = pow;
	wPowerBonus = powBonus;
	wLuck = lck;
	wAttractionBonus = atrBonus;
	inInventory = have;
	inSet = set;
}

Weapon::~Weapon() {

}

