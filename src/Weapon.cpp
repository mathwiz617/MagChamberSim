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
}

Weapon::Weapon(string type, int pow, int powBonus, int lck, double atrBonus, bool have) {
	wName = type;
	wPower = pow;
	wPowerBonus = powBonus;
	wLuck = lck;
	wAttractionBonus = atrBonus;
	inInventory = have;

}

Weapon::~Weapon() {

}

