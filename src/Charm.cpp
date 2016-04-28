/*
 * Charm.cpp
 *
 *  Created on: Apr 25, 2016
 *      Author: matt
 */

#include "Charm.h"

Charm::Charm() {
	charmName = "none";
	charmPower = 0;
	charmPowerBonus = 0;
	charmLuck = 0;
	amount = 0;
	charmAttractionBonus = 0;
}

Charm::Charm(string type, int pow, int powBonus, int lck, int owned, double atrBonus) {
	charmName = type;
	charmPower = pow;
	charmPowerBonus = powBonus;
	charmLuck = lck;
	amount = owned;
	charmAttractionBonus = atrBonus;
}

Charm::~Charm() {

}

