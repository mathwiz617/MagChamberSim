/*
 * Mouse.h
 *
 *  Created on: Apr 25, 2016
 *      Author: matt
 */

#ifndef MOUSE_H_
#define MOUSE_H_
#include <iostream>
#include <vector>
#include "Loot.h"
using namespace std;

class Mouse {
public:
	string mName; //mouse breed name
	int mPower; //mouse power
	int baitTier; //bait tier needed to attract this mouse
	int caught; //number caught
	int missed; //number missed
	int points; //points given for catch
	int gold; //gold given for catch
	double odds; //odds of this mouse appearing per attraction on this tier
	vector<Loot> lootPossible; //possible drops

	Mouse();
	Mouse(string, int, int, int, int, double);
	vector<Loot> GetLoot(string);
	virtual ~Mouse();
};

#endif /* MOUSE_H_ */
