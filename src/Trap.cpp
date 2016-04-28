/*
 * Trap.cpp
 *
 *  Created on: Apr 25, 2016
 *      Author: matt
 */

#include "Trap.h"

Trap::Trap() {
	base = Base::Base();
	charm = Charm::Charm();
	cheese = Cheese::Cheese();
	weapon = Weapon::Weapon();
	sheild = false;
	charmsRemaining = 0;
	cheeseRemaining = 0;
	powerBonus = 0.0;
	trapPower = 0;
	trapPowerTotal = 0.0;
	trapLuck = 0;
	attractionRateBonus = 0;
	attractionRate = 0;
}

Trap::Trap(Base baseUsed, Charm charmUsed, Cheese cheeseUsed, Weapon weaponUsed, bool lgs) {
	base = baseUsed;
	charm = charmUsed;
	cheese = cheeseUsed;
	weapon = weaponUsed;
	sheild = lgs;
	charmsRemaining = charm.amount;
	cheeseRemaining = cheese.amount;
	powerBonus = (weapon.wPowerBonus + base.bPowerBonus + charm.charmPowerBonus) / 100.0;
	trapPower = weapon.wPower + base.bPower + charm.charmPower;
	trapPowerTotal = trapPower + (trapPower * powerBonus) + 7;
	if(sheild == true){
		trapLuck = weapon.wLuck + base.bLuck + charm.charmLuck + 7;
	}
	else{
		trapLuck = weapon.wLuck + base.bLuck + charm.charmLuck;
	}
	attractionRateBonus = (1 - cheese.cheeseAttractionRate) * (weapon.wAttractionBonus + base.bAttractionBonus + charm.charmAttractionBonus);
	attractionRate = cheese.cheeseAttractionRate + attractionRateBonus;
}


Trap::~Trap() {

}

