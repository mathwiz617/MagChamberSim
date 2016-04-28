/*
 * Player.cpp
 *
 *  Created on: Apr 26, 2016
 *      Author: matt
 */

#include "Player.h"

Player::Player() {
	inventory = Inventory::Inventory();
	mice = MiceStats::MiceStats();
	gold = 0;
	points = 0;
	goldProfit = 0;
	goldGained = 0;
	goldLost = 0;
	embers = 0;
	embersGained = 0;
	meltedCheese = 0;
	cheeseMeltedAtOnce = 0;
	rubies = 0;
	sapphires = 0;
	emeralds = 0;
	scales = 0;
	rGained = 0;
	eGained = 0;
	saGained = 0;
	scGained = 0;
	charmsLooted = 0;
	rGainedTotal = 0;
	saGainedTotal = 0;
	eGainedTotal = 0;
	scGainedTotal = 0;
	embersGainedTotal = 0;
	charmsLootedTotal = 0;

}

string Player::BuildLootString(int embersGained, int rGained, int saGained, int eGained, int scGained, int charmsLooted){
	string lootString;

	lootString += "You looted: ";
	if(embersGained > 0){
		lootString += to_string(embersGained) + " embers ";
	}

	if(rGained > 0){
		lootString += to_string(rGained) + " rubies ";
	}
	if(saGained > 0){
		lootString += to_string(saGained) + " sapphires ";
	}
	if(eGained > 0){
		lootString += to_string(eGained) + " emeralds ";
	}
	if(scGained > 0){
		lootString += to_string(scGained) + " scales ";
	}

	if(charmsLooted > 0){
		lootString += "You also looted " + to_string(charmsLooted) + " Ultimate charms! Lucky you!";
	}

	return lootString;
}


Player::~Player() {
	// TODO Auto-generated destructor stub
}

