/*
 * Base.cpp
 *
 *  Created on: Apr 25, 2016
 *      Author: matt
 */

#include "Base.h"

Base::Base() {
	bName = "Disarmed!";
	bPower = 0;
	bPowerBonus = 0;
	bLuck = 0;
	bAttractionBonus = 0;
	inInventory = false;
	inSet = false;
}

Base::Base(string type, int pow, int powBonus, int lck, double atrBonus, bool have, bool set) {
	bName = type;
	bPower = pow;
	bPowerBonus = powBonus;
	bLuck = lck;
	bAttractionBonus = atrBonus;
	inInventory = have;
	inSet = set;
}

Base::~Base() {

}

