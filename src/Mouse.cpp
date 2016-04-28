/*
 * Mouse.cpp
 *
 *  Created on: Apr 25, 2016
 *      Author: matt
 */

#include "Mouse.h"
#include "Loot.h"

Mouse::Mouse() {
	mName = "None!";
	mPower = 0;
	baitTier = 0;
	points = 0;
	gold = 0;
	odds = 0.0;
	caught = 0;
	missed = 0;
	lootPossible = GetLoot("None");
}

Mouse::Mouse(string name, int power, int tier, int pointValue, int goldValue,  double atrOdds){
	mName = name;
	mPower = power;
	baitTier = tier;
	points = pointValue;
	gold = goldValue;
	odds = atrOdds;
	lootPossible = GetLoot(name);
	caught = 0;
	missed = 0;
}

vector<Loot> Mouse::GetLoot(string mouse){
    Loot dropOne = Loot::Loot();
    Loot dropTwo = Loot::Loot();
    Loot dropThree = Loot::Loot();
    int maxDroppedFirst;
    int maxDroppedSecond;
    int maxDroppedThird;
    string lootFirstName;
    string lootSecondName;
    string lootThirdName;
    vector<Loot> lootList;
	vector<double> chancesFirst;
	vector<double> chancesSecond;
	vector<double> chancesThird;

	lootList.clear();

	chancesFirst.clear();
	chancesSecond.clear();
	chancesThird.clear();

	if (mouse == "None"){
		lootFirstName = "None";

        chancesFirst.push_back(0);

        maxDroppedFirst = 0;

        dropOne.lName = lootFirstName;
		dropOne.numPossible = maxDroppedFirst;
		dropOne.chance = chancesFirst;

		lootList.push_back(dropOne);
        lootList.push_back(dropTwo);
        lootList.push_back(dropThree);
	}

	if (mouse == "Superheated"){
        lootFirstName = "Ember";

        chancesFirst.push_back(.3);

        maxDroppedFirst = 1;

        dropOne.lName = lootFirstName;
        dropOne.numPossible = maxDroppedFirst;
        dropOne.chance = chancesFirst;

        lootList.push_back(dropOne);
        lootList.push_back(dropTwo);
        lootList.push_back(dropThree);
	}

	if (mouse == "Magma"){
        lootFirstName = "Ember";

        chancesFirst.push_back(.2);

        maxDroppedFirst = 1;

        dropOne.lName = lootFirstName;
        dropOne.numPossible = maxDroppedFirst;
        dropOne.chance = chancesFirst;

        lootList.push_back(dropOne);
        lootList.push_back(dropTwo);
        lootList.push_back(dropThree);
	}

	if (mouse == "Green Dragon"){
        lootFirstName = "Scale";
        lootSecondName = "Emerald";

        chancesFirst.push_back(.2);

        chancesSecond.push_back(1);

        maxDroppedFirst = 1;
        maxDroppedSecond = 1;

        dropOne.lName = lootFirstName;
        dropOne.numPossible = maxDroppedFirst;
        dropOne.chance = chancesFirst;

        dropTwo.lName = lootSecondName;
        dropTwo.numPossible = maxDroppedSecond;
        dropTwo.chance = chancesSecond;

        lootList.push_back(dropOne);
        lootList.push_back(dropTwo);
        lootList.push_back(dropThree);
    }

	if (mouse == "Blue Dragon"){
        lootFirstName = "Scale";
        lootSecondName = "Sapphire";

        chancesFirst.push_back(.2);

        chancesSecond.push_back(1);

        maxDroppedFirst = 1;
        maxDroppedSecond = 1;

        dropOne.lName = lootFirstName;
        dropOne.numPossible = maxDroppedFirst;
        dropOne.chance = chancesFirst;

        dropTwo.lName = lootSecondName;
        dropTwo.numPossible = maxDroppedSecond;
        dropTwo.chance = chancesSecond;

        lootList.push_back(dropOne);
        lootList.push_back(dropTwo);
        lootList.push_back(dropThree);
	}

	if (mouse == "Red Dragon"){
        lootFirstName = "Scale";
        lootSecondName = "Ruby";

        chancesFirst.push_back(.2);

        chancesSecond.push_back(1);

        maxDroppedFirst = 1;
        maxDroppedSecond = 1;

        dropOne.lName = lootFirstName;
        dropOne.numPossible = maxDroppedFirst;
        dropOne.chance = chancesFirst;

        dropTwo.lName = lootSecondName;
        dropTwo.numPossible = maxDroppedSecond;
        dropTwo.chance = chancesSecond;

        lootList.push_back(dropOne);
        lootList.push_back(dropTwo);
        lootList.push_back(dropThree);
    }

	if (mouse == "Black Dragon"){
		lootFirstName = "Scale";
		lootSecondName = "Ember";

        chancesFirst.push_back(.5);

        chancesSecond.push_back(2/3);
        chancesSecond.push_back(2/3);
        chancesSecond.push_back(2/3);

        maxDroppedFirst = 1;
        maxDroppedSecond = 3;

        dropOne.lName = lootFirstName;
        dropOne.numPossible = maxDroppedFirst;
        dropOne.chance = chancesFirst;

        dropTwo.lName = lootSecondName;
        dropTwo.numPossible = maxDroppedSecond;
        dropTwo.chance = chancesSecond;

        lootList.push_back(dropOne);
        lootList.push_back(dropTwo);
        lootList.push_back(dropThree);
    }

	if (mouse == "Broodmother"){
        lootFirstName = "Scale";
        lootSecondName = "Ember";
        lootThirdName = "UC";

        chancesFirst.push_back(1.0);
        chancesFirst.push_back(.8);
        chancesFirst.push_back(.6);
        chancesFirst.push_back(.4);
        chancesFirst.push_back(.2);

        chancesSecond.push_back(1.0);
        chancesSecond.push_back(.2);
        chancesSecond.push_back(.8);
        chancesSecond.push_back(.7);
        chancesSecond.push_back(.6);
        chancesSecond.push_back(.5);
        chancesSecond.push_back(.4);
        chancesSecond.push_back(.3);
        chancesSecond.push_back(.2);
        chancesSecond.push_back(.1);

        chancesThird.push_back(.01);

        maxDroppedFirst = 5;
        maxDroppedSecond = 10;
        maxDroppedThird = 1;

        dropOne.lName = lootFirstName;
        dropOne.numPossible = maxDroppedFirst;
        dropOne.chance = chancesFirst;

        dropTwo.lName = lootSecondName;
        dropTwo.numPossible = maxDroppedSecond;
        dropTwo.chance = chancesSecond;

        dropThree.lName = lootThirdName;
        dropThree.numPossible = maxDroppedThird;
        dropThree.chance = chancesThird;

        lootList.push_back(dropOne);
        lootList.push_back(dropTwo);
        lootList.push_back(dropThree);
    }

	return lootList;
}

Mouse::~Mouse() {
}

