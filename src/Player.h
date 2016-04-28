/*
 * Player.h
 *
 *  Created on: Apr 26, 2016
 *      Author: matt
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include "MiceStats.h"
#include "Trap.h"

class Player {
public:
	Inventory inventory;
	MiceStats mice;
	Trap setup;
	long long gold;
	long long points;
	int goldProfit;
	int goldGained;
	int goldLost;
	int embers;
	int embersGained;
	int meltedCheese;
	int cheeseMeltedAtOnce;
	int rubies, sapphires, emeralds, scales;
	int rGained;
	int saGained;
	int eGained;
	int scGained;
	int charmsLooted;
	int rGainedTotal;
	int saGainedTotal;
	int eGainedTotal;
	int scGainedTotal;
	int embersGainedTotal;
	int charmsLootedTotal;
	Player();
	string BuildLootString(int, int, int, int, int, int);
	virtual ~Player();
};

#endif /* PLAYER_H_ */
