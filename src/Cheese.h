/*
 * Cheese.h
 *
 *  Created on: Apr 25, 2016
 *      Author: matt
 */

#ifndef CHEESE_H_
#define CHEESE_H_
#include <iostream>
using namespace std;

class Cheese {
public:
	string cheeseName; //type of cheese
	int tier; //bait tier
	int amount; //amount left
	double cheeseAttractionRate; //base AR
	bool storeCheese; //Can it be stolen in a red box?
	bool regularCheese; //Will it be used at 2x rate?

	Cheese();
	Cheese(string, int, int, double, bool, bool);
	virtual ~Cheese();
};

#endif /* CHEESE_H_ */
