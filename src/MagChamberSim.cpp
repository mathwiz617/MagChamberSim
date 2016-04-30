/*
 * MagChamberSim.cpp
 *
 *  Created on: Apr 25, 2016
 *      Author: matt
 */

#include "RedBox.h"
#include "Player.h"
#include <iostream>
#include <ctime>
using namespace std;

const int EFF = 1;

Weapon ChooseWeapon(string, Player);
Base ChooseBase(string, Player);
Charm ChooseCharm(string, Player);
Cheese ChooseCheese(string, Player);
Player ChooseMouse(Player);
RedBox RedBoxValue(Player);
Player Shop(Player);
Player Craft(Player);
Player SetTrap(Player);
Player LootAdd(Player);
Player Hunt(Player);
bool Atr(double);
bool CatchRoll(Player);
bool RedBoxRoll();
void SeeMiceStats(Player, int);
void SeeInventory(Player);

int main() {
    Player hunter = Player::Player();
    string weaponName;
    string baseName;
    string charmName;
    string cheeseName;
    string input;
    int cycles;
    int charmCount;
    int huntsInArea = 0;

    srand(time(NULL));

    cout << "Enter starting options." << endl << "Defaulting to 20 Dragon Embers for testing." << endl;
    hunter.embers = 20;
    cout << "Defaulting to 12 million gold. " << endl;
    hunter.gold = 12000000;
    cout << "Defaulting to 1 billion points. " << endl;
    hunter.points = 1000000000;
    cout << "Defaulting to 1000 Gouda. " << endl;
    hunter.inventory.gouda.amount = 1000;
    cout << "Defaulting to 6 Ultimate charms. " << endl;
    charmCount = 6;
    hunter.inventory.ultimate.amount = charmCount;
    cout << "Defaulting to LGS active." << endl;
    hunter.inventory.shield = true;

    cout << endl;

    weaponName = "IceMaiden";
    hunter.inventory.weaponArmed = ChooseWeapon(weaponName, hunter);

    baseName = "Rift";
    hunter.inventory.baseArmed = ChooseBase(baseName, hunter);

    charmName = "None";
    hunter.inventory.charmArmed = ChooseCharm(charmName, hunter);

    cheeseName ="Gouda";
    hunter.inventory.cheeseArmed = ChooseCheese(cheeseName, hunter);

    hunter = SetTrap(hunter);

    cout << endl;

    do{
        cout << endl << "What do you want to do?" << endl;
        cout << "Weapon = change weapon."<< endl;
        cout << "Base = change base."<< endl;
        cout << "Charm = change charm."<< endl;
        cout << "Cheese = change cheese."<< endl;
        cout << "LGS = toggle LGS." << endl;
        cout << "Hunt = hunt for mouse."<< endl;
        cout << "Trap = view trap."<< endl;
        cout << "Mice = view catch/miss stats for each mouse."<< endl;
        cout << "Shop = go shopping."<< endl;
        cout << "Craft = craft something."<< endl;
        cout << "Inventory = view inventory."<< endl;
        cout << "Done = end simulation." << endl;

        cin >> input;

        if (input == "Weapon"){
            cout << "What do you want to change to? (Enter Ice Maiden, Power, Luck, or Best.)" << endl;
            cin >> weaponName;
            hunter.inventory.weaponArmed = ChooseWeapon(weaponName, hunter);
            hunter = SetTrap(hunter);
        }

        if (input == "Base"){
            cout << "What do you want to change to? (NYFI, enter Rift, Mino, or Basalt.)" << endl;
            cin >> baseName;
            hunter.inventory.baseArmed = ChooseBase(baseName, hunter);
            hunter = SetTrap(hunter);
        }

        if (input == "Charm"){
            cout << "What do you want to change to? (NYFI, enter None, Dragon, or Ultimate.)" << endl;
            cin >> charmName;
            hunter.inventory.charmArmed = ChooseCharm(charmName, hunter);
            hunter = SetTrap(hunter);
        }

        if (input == "Cheese"){
            cout << "What do you want to change to?" <<endl;
            cout <<	"(Only Gouda is available for regular cheeses. Enter Gouda, FF, MH, or THH.)" << endl;
            cin >> cheeseName;
            hunter.inventory.cheeseArmed = ChooseCheese(cheeseName, hunter);
            hunter = SetTrap(hunter);
        }

        if (input == "LGS"){
        	if (hunter.inventory.shield == true){
        		hunter.inventory.shield = false;
        	}
        	else {
        		hunter.inventory.shield = true;
        	}
        }

        if (input == "Hunt"){
        	if(hunter.inventory.cheeseArmed.tier == 0){
        		cout << "No mice will be attracted! Arm a real cheese type!" << endl;
        	}
        	else{
        		cout << "How many times? ";
        		cin >> cycles;
        		hunter.goldProfit = 0;
				hunter.rGainedTotal = 0;
				hunter.saGainedTotal = 0;
				hunter.eGainedTotal = 0;
				hunter.scGainedTotal = 0;
				hunter.charmsLootedTotal = 0;
				hunter.embersGainedTotal = 0;
        		hunter.cheeseMeltedAtOnce = 0;
        		int i = 0;

        		while(i < cycles && hunter.inventory.cheeseArmed.amount > 0){
        				huntsInArea++;
        				hunter = Hunt(hunter);
        				hunter.rGained = 0;
        				hunter.saGained = 0;
        				hunter.eGained = 0;
        				hunter.scGained = 0;
        				hunter.charmsLooted = 0;
        				hunter.embersGained = 0;
        				hunter = SetTrap(hunter);
        				i++;
        				if(hunter.inventory.cheeseArmed.amount < 1){
        					cout << "You ran out of cheese after " << i << " hunts. Go buy or craft more!" << endl;

        			        if ((hunter.inventory.cheeseArmed.cheeseName == "Gouda") && (hunter.inventory.cheeseArmed.amount < 0)){
        			        	hunter.inventory.gouda.amount = 0;
        			        	hunter.inventory.cheeseArmed.amount = 0;
        			        }

        			        if ((hunter.inventory.cheeseArmed.cheeseName == "Fiery Fondue") && (hunter.inventory.cheeseArmed.amount < 0)){
        			        	hunter.inventory.fieryFondue.amount = 0;
        			        	hunter.inventory.cheeseArmed.amount = 0;
        			        }

        			        if ((hunter.inventory.cheeseArmed.cheeseName == "Molten Havarti") && (hunter.inventory.cheeseArmed.amount < 0)){
        			        	hunter.inventory.moltenHavarti.amount = 0;
        			        	hunter.inventory.cheeseArmed.amount = 0;
        			        }

        			        if ((hunter.inventory.cheeseArmed.cheeseName == "Treasure Hoard Havarti") && (hunter.inventory.cheeseArmed.amount < 0)){
        			        	hunter.inventory.treasureHavarti.amount = 0;
        			        	hunter.inventory.cheeseArmed.amount = 0;
        			        }
        				}
        				if(hunter.inventory.charmArmed.amount < 1){

        			        if (hunter.inventory.charmArmed.charmName != "none"){
        					cout << "You ran out of charms! Disarming charms." << endl;
        			        }

        			        if ((hunter.inventory.charmArmed.charmName == "Ultimate") && (hunter.inventory.charmArmed.amount < 0)){
        			        	hunter.inventory.ultimate.amount = 0;
        			        	hunter.inventory.charmArmed.amount = 0;
        			        }

        			        if ((hunter.inventory.charmArmed.charmName == "Dragon") && (hunter.inventory.cheeseArmed.amount < 0)){
        			        	hunter.inventory.dragon.amount = 0;
        			        	hunter.inventory.charmArmed.amount = 0;
        			        }

        					hunter.inventory.charmArmed = hunter.inventory.noCharm;
        				}
        		}
        		cout << "You have made an overall profit of: " << hunter.goldProfit << " gold this last round of hunting." << endl;
        		cout << "You looted " << hunter.rGainedTotal << "/" << hunter.saGainedTotal << "/" << hunter.rGainedTotal
        				<< "/" << hunter.scGainedTotal
        				<< " rubies/sapphires/emeralds/scales." << endl;
        		cout << "You looted " << hunter.embersGainedTotal << " embers and melted " << hunter.cheeseMeltedAtOnce << " pieces of cheese." << endl;
        		cout << "You looted " << hunter.charmsLootedTotal << " Ultimate charms!" << endl;

        		if(hunter.inventory.cheeseArmed.cheeseName == "Gouda"){
            		cout << "You have " << hunter.inventory.gouda.amount << " " << hunter.inventory.gouda.cheeseName << " remaining." << endl;
        		}

        		if(hunter.inventory.cheeseArmed.cheeseName == "FieryFondue"){
        			cout << "You have " << hunter.inventory.fieryFondue.amount << " "
        					<< hunter.inventory.fieryFondue.cheeseName << " remaining." << endl;
        		}

        		if(hunter.inventory.cheeseArmed.cheeseName == "MoltenHavarti"){
        			cout << "You have " << hunter.inventory.moltenHavarti.amount << " "
        					<< hunter.inventory.moltenHavarti.cheeseName << " remaining." << endl;
        		}

        		if(hunter.inventory.cheeseArmed.cheeseName == "TreasureHoardHavarti"){
        			cout << "You have " << hunter.inventory.treasureHavarti.amount << " "
        					<< hunter.inventory.treasureHavarti.cheeseName << " remaining." << endl;
        		}
        	}
        }

        if (input == "Trap"){

        	cout << hunter.inventory.weaponArmed.wName << "/" << hunter.inventory.baseArmed.bName
        			<< "/" << hunter.inventory.charmArmed.charmName << "("
					<< hunter.inventory.charmArmed.amount << ")/" << hunter.inventory.cheeseArmed.cheeseName
					<< "(" << hunter.inventory.cheeseArmed.amount << ")" << endl;

        	if (hunter.inventory.shield == true){
        		cout << "The LGS is active." << endl;
        	}
        	else{
        		cout << "The LGS is not active." << endl;
        	}

        	cout << "Power: " << hunter.inventory.trapPowerTotal << endl;
        	cout << "Luck: " << hunter.inventory.trapLuck << endl;
        	cout << "Attraction rate: " << hunter.inventory.attractionRate << endl;
        	cout << "Hunting tier: " << hunter.inventory.cheeseArmed.tier << endl;
        }

        if (input == "Mice"){
            SeeMiceStats(hunter, huntsInArea);
        }

        if (input == "Shop"){
        	hunter = Shop(hunter);
			hunter = SetTrap(hunter);
        }

        if (input == "Craft"){
        	hunter = Craft(hunter);
			hunter = SetTrap(hunter);
        }

        if (input == "Inventory"){
        	SeeInventory(hunter);
        }

    }while (input != "Done");

    return 0;
}

//change weapon here
Weapon ChooseWeapon(string weaponName, Player hunter){
    Weapon weapon;

    if(weaponName == "IceMaiden"){
    	if (hunter.inventory.iceMaiden.inInventory == true){
    		weapon = hunter.inventory.iceMaiden;
    		cout << "Ice Maiden armed." << endl;
    	}
    	else {
    		cout << "You don't own that trap" << endl;
    	}
    }
    else if((weaponName == "Power") && (hunter.points > 1000000)){
    	if (hunter.inventory.powerTrap.inInventory == true){
    		weapon = hunter.inventory.powerTrap;
    		cout << "Power trap armed." << endl;
    	}
    	else {
    		cout << "You don't own that trap" << endl;
    	}
    }
    else if((weaponName == "Luck") && (hunter.points > 1000000)){
    	if (hunter.inventory.luckTrap.inInventory == true){
    		weapon = hunter.inventory.luckTrap;
    		cout << "Luck trap armed." << endl;
    	}
    	else {
    		cout << "You don't own that trap" << endl;
    	}
    }
    else if(weaponName == "Best"){
    	if (hunter.inventory.bestTrap.inInventory == true){
    		weapon = hunter.inventory.bestTrap;
    		cout << "Best trap armed." << endl;
    	}
    	else {
    		cout << "You don't own that trap" << endl;
    	}
    }
    else{
        weapon = hunter.inventory.invalidWeapon;
        cout << "Current weapon is invalid." << endl;
    }
    return weapon;
}

//change base here
Base ChooseBase(string baseName, Player hunter){
    Base base;

    if(baseName == "Rift"){
    	base = hunter.inventory.rift;
    	cout << "Rift Base armed." << endl;
    }
    else if(baseName == "Mino"){
    	base = hunter.inventory.mino;
    	cout << "Minotaur Base armed." << endl;
    }
    else if(baseName == "Basalt"){
    	base = hunter.inventory.basalt;
    	cout << "Basalt Base armed." << endl;
    }
    else{
        base = hunter.inventory.invalidBase;
        cout << "Current base is invalid." << endl;

    }
    return base;
}

//change charm here
Charm ChooseCharm(string charmName, Player hunter){
    Charm charm;

    if(charmName == "None"){
        charm = hunter.inventory.noCharm;
        cout << "No charm armed." << endl;
    }
    else if((charmName == "Ultimate") && (hunter.inventory.ultimate.amount > 0)){
        charm = hunter.inventory.ultimate;
        cout << "Ultimate charm armed. Charm will be used up on each hunt." << endl << "Catch those mice!" << endl;
    }
    else if((charmName == "Dragon") && (hunter.inventory.dragon.amount > 0)){
    	charm = hunter.inventory.dragon;
    	cout << "Dragon charm armed. Charm will be used up on each hunt." << endl;
    }
    else{
        charm = hunter.inventory.otherCharm;
        cout << "This charm is NYI. Effectively none." << endl;
    }
    return charm;
}

//change cheese here
Cheese ChooseCheese(string cheeseName, Player hunter){
    Cheese cheese = Cheese::Cheese();

    if((cheeseName == "Gouda") && (hunter.inventory.gouda.amount > 0)){
        cheese = hunter.inventory.gouda;
        cout << "Gouda armed." << endl;
        cout << "Tier one mice will be attracted." << endl;
        cout << "Cheese will be used at a rate of two per hunt." << endl;

    }
    else if ((cheeseName == "FF") &&  (hunter.inventory.fieryFondue.amount > 0)){
        cheese = hunter.inventory.fieryFondue;
        cout << "Fiery Fondue armed." << endl;
        cout << "Tier one mice will be attracted." << endl;
    }
    else if ((cheeseName == "MH") &&  (hunter.inventory.moltenHavarti.amount > 0)){
        cheese = hunter.inventory.moltenHavarti;
        cout << "Molten Havarti armed." << endl;
        cout << "Tier two mice will be attracted." << endl;
    }
    else if ((cheeseName == "THH") &&  (hunter.inventory.treasureHavarti.amount > 0)){
        cheese = hunter.inventory.treasureHavarti;
        cout << "Treasure Hoard Havarti armed." << endl;
        cout << "Tier three mice will be attracted." << endl;
    }
    else{
        cheese = hunter.inventory.otherCheese;
        cout << "Invalid cheese." << endl;
    }
    return cheese;
}

//pick mouse here
Player ChooseMouse( Player hunter){
    double r = ((double) rand() / (RAND_MAX));

    if (hunter.inventory.cheeseArmed.tier == 0){
    	hunter.mice.attracted = hunter.mice.none;
    }

    if (hunter.inventory.cheeseArmed.tier == 1){
        if (r <= .4){
        	hunter.mice.attracted = hunter.mice.heated;
        }
        else{
        	hunter.mice.attracted = hunter.mice.magma;
        }
    }

    if (hunter.inventory.cheeseArmed.tier == 2){
        if (r <= .3){
        	hunter.mice.attracted = hunter.mice.gDragon;
        }
        else if (r > .3 && r <= .6){
        	hunter.mice.attracted = hunter.mice.rDragon;
        }
        else if (r > .6 && r <= .9){
        	hunter.mice.attracted = hunter.mice.bDragon;
        }
        else{
        	hunter.mice.attracted = hunter.mice.blkDragon;
        }
    }

    if (hunter.inventory.cheeseArmed.tier == 3){
        hunter.mice.attracted = hunter.mice.mother;
    }

    return hunter;
}

//Add loot from caught mouse to inventory
Player LootAdd(Player hunter){
	string drops;
	Loot loot;
	double r = ((double) rand() / (RAND_MAX));

	loot.numPossible = 0;


	for(int i = 0; i < hunter.mice.attracted.lootPossible.size(); i++){
		loot = hunter.mice.attracted.lootPossible.at(i);

		for (int j = 0; j < loot.numPossible; j++){
			int numDropped = 0;
			if (r <= loot.chance.at(j)){
				numDropped++;
				if(numDropped > loot.numPossible){
					numDropped = loot.numPossible;
				}
			}

			if ((loot.lName == "Ember") && (numDropped > 0)){
				hunter.embers += numDropped;
				hunter.embersGained += numDropped;
				hunter.embersGainedTotal += numDropped;
			}

			if ((loot.lName == "Scale") && (numDropped > 0)){
				hunter.scales += numDropped;
				hunter.scGained += numDropped;
				hunter.scGainedTotal += numDropped;
			}

			if ((loot.lName == "Sapphire") && (numDropped > 0)){
				hunter.sapphires += numDropped;
				hunter.saGained += numDropped;
				hunter.saGainedTotal += numDropped;
			}

			if ((loot.lName == "Ruby") && (numDropped > 0)){
				hunter.rubies += numDropped;
				hunter.rGained += numDropped;
				hunter.rGainedTotal += numDropped;
			}

			if ((loot.lName == "Emerald") && (numDropped > 0)){
				hunter.emeralds += numDropped;
				hunter.eGained += numDropped;
				hunter.eGainedTotal += numDropped;
			}

			if ((loot.lName == "UC") && (numDropped > 0)){
				hunter.inventory.ultimate.amount += numDropped;
				hunter.charmsLooted += numDropped;
				hunter.charmsLootedTotal += numDropped;
			}
		}
	}

	if((hunter.embersGained > 0) || (hunter.rGained > 0) || (hunter.saGained > 0) || (hunter.eGained > 0) || (hunter.scGained > 0)
			||(hunter.charmsLooted > 0)){
	drops = hunter.BuildLootString(hunter.embersGained, hunter.rGained, hunter.saGained,
    		hunter.eGained, hunter.scGained, hunter.charmsLooted);

	cout << drops << endl;
	}

	return hunter;
}

//does the cheese attract?
bool Atr(double atrRate){
    double r = ((double) rand() / (RAND_MAX));

    if(r <= atrRate){
        return true;
    }
    else {
        return false;
    }
}

//does the trap catch the mouse?
bool CatchRoll(Player hunter){
    double catchRate;
    double r = ((double) rand() / (RAND_MAX));

    catchRate = ((EFF * hunter.inventory.trapPowerTotal) + ((3 - EFF) * (hunter.inventory.trapLuck * hunter.inventory.trapLuck)))
    		/ ((EFF * hunter.inventory.trapPowerTotal) + hunter.mice.attracted.mPower);

    if (r <= catchRate || hunter.inventory.charmArmed.charmName == "Ultimate"){
        return true;
    }
    else{
        return false;
    }
}

//if missed, is it a red box?
bool RedBoxRoll(){
    double r = ((double) rand() / (RAND_MAX));

    if (r <= .5){
        return true;
    }
    else{
        return false;
    }

}

//how much, of what, does the red box take away?
RedBox RedBoxValue(Player hunter){
    RedBox value;
    double r = ((double) rand() / (RAND_MAX));

    if (r <= .4 && hunter.inventory.cheeseArmed.storeCheese == true){
        value.type = 1; //extra cheese
        if (hunter.inventory.cheeseArmed.cheeseName == "Gouda"){
            value.amount = 10;
        }
        else{
            value.amount = 1;
        }
        if (hunter.inventory.cheeseArmed.amount < 0){
        	hunter.inventory.cheeseArmed.amount = 0;
        }
    }
    else if (r > .4 && r <= .7){
        value.type = 2; //drains points
        value.amount = 10000;
    }
    else if (r > .7 && hunter.gold > 999){
        value.type = 3; //drains gold
        value.amount = 1000;
    }
    return value;
}

//The actual hunt, plus result output
Player Hunt(Player hunter){
    RedBox redBox;
    bool atrMouse = false;
    bool isMouseCaught = false;
    bool isRedBox = false;

        atrMouse = Atr(hunter.inventory.attractionRate);
        if (atrMouse == true){
            hunter = ChooseMouse(hunter);
            isMouseCaught = CatchRoll(hunter);

            if (isMouseCaught == true){

            	if (hunter.inventory.charmArmed.charmName == "Ultimate"){
            		hunter.inventory.ultimate.amount -= 1;
            	}

            	if(hunter.mice.attracted.mName == "Superheated"){
            		hunter.mice.heated.caught++;
            	}
            	if(hunter.mice.attracted.mName == "Magma"){
            		hunter.mice.magma.caught++;
            	}
            	if(hunter.mice.attracted.mName == "Green Dragon"){
            		hunter.mice.gDragon.caught++;
            	}
            	if(hunter.mice.attracted.mName == "Red Dragon"){
            		hunter.mice.rDragon.caught++;
            	}
            	if(hunter.mice.attracted.mName == "Blue Dragon"){
            		hunter.mice.bDragon.caught++;
            	}
            	if(hunter.mice.attracted.mName == "Black Dragon"){
            		hunter.mice.blkDragon.caught++;
            	}
            	if(hunter.mice.attracted.mName == "Broodmother"){
            		hunter.mice.mother.caught++;
            	}

            	hunter.gold += hunter.mice.attracted.gold;
                hunter.goldGained += hunter.mice.attracted.gold;
                hunter.points += hunter.mice.attracted.points;

            	if (hunter.inventory.cheeseArmed.cheeseName == "Gouda"){
            		hunter.inventory.gouda.amount -= 2;
            	}

            	if (hunter.inventory.cheeseArmed.cheeseName == "Fiery Fondue"){
            		hunter.inventory.fieryFondue.amount--;
            	}

            	if (hunter.inventory.cheeseArmed.cheeseName == "Molten Havarti"){
            		hunter.inventory.moltenHavarti.amount--;
            	}

            	if (hunter.inventory.cheeseArmed.cheeseName == "Treasure Hoard Havarti"){
            		hunter.inventory.treasureHavarti.amount--;
            	}
            }
            else{

            	if(hunter.mice.attracted.mName == "Superheated"){
            		hunter.mice.heated.missed++;
            	}
            	if(hunter.mice.attracted.mName == "Magma"){
            		hunter.mice.magma.missed++;
            	}
            	if(hunter.mice.attracted.mName == "Green Dragon"){
            		hunter.mice.gDragon.missed++;
            	}
            	if(hunter.mice.attracted.mName == "Red Dragon"){
            		hunter.mice.rDragon.missed++;
            	}
            	if(hunter.mice.attracted.mName == "Blue Dragon"){
            		hunter.mice.bDragon.missed++;
            	}
            	if(hunter.mice.attracted.mName == "Black Dragon"){
            		hunter.mice.blkDragon.missed++;
            	}
            	if(hunter.mice.attracted.mName == "Broodmother"){
            		hunter.mice.mother.missed++;
            	}

            	isRedBox = RedBoxRoll();

            	if (hunter.inventory.cheeseArmed.cheeseName == "Gouda"){
            		hunter.inventory.gouda.amount -= 2;
            		hunter.meltedCheese += 1;
            		hunter.cheeseMeltedAtOnce += 1;
            	}

            	if (hunter.inventory.cheeseArmed.cheeseName == "Fiery Fondue"){
            		hunter.inventory.fieryFondue.amount--;
            	}

            	if (hunter.inventory.cheeseArmed.cheeseName == "Molten Havarti"){
            		hunter.inventory.moltenHavarti.amount--;
            	}

            	if (hunter.inventory.cheeseArmed.cheeseName == "Treasure Hoard Havarti"){
            		hunter.inventory.treasureHavarti.amount--;
            	}

                if(isRedBox == true){
                    redBox = RedBoxValue(hunter);

                    switch (redBox.type){
                        case 1:
                        	hunter.inventory.cheeseArmed.amount -= redBox.amount;
                        	if (hunter.inventory.cheeseArmed.cheeseName == "Gouda"){
                        		hunter.inventory.gouda.amount -= redBox.amount;
                        	}

                        	if (hunter.inventory.cheeseArmed.cheeseName == "Fiery Fondue"){
                        		hunter.inventory.fieryFondue.amount -= redBox.amount;
                        	}

                        	if (hunter.inventory.cheeseArmed.cheeseName == "Molten Havarti"){
                        		hunter.inventory.moltenHavarti.amount -= redBox.amount;
                        	}

                        	if (hunter.inventory.cheeseArmed.cheeseName == "Treasure Hoard Havarti"){
                        		hunter.inventory.treasureHavarti.amount -= redBox.amount;
                        	}
                            break;

                        case 2:
                            hunter.points -= redBox.amount;
                            break;

                        case 3:
                            hunter.gold -= redBox.amount;
                            hunter.goldLost += redBox.amount;
                            break;
                    }
                }
            }
            if(isMouseCaught == true){
            	hunter.goldProfit = hunter.goldGained - hunter.goldLost;
            	cout << endl << "You caught a(n) " << hunter.mice.attracted.mName << " Mouse!" << endl;
                hunter = LootAdd(hunter);
                hunter.embersGained = 0;
            }
            else{
            	cout << endl << "You missed a(n) " << hunter.mice.attracted.mName << " Mouse!" << endl;
            	if(isRedBox == true){
            		cout << "The mouse took ";
            		switch (redBox.type){
            		case 1:
            			cout << redBox.amount << " pieces of cheese!" << endl;
            			break;

            		case 2:
            			cout << redBox.amount << " points!" << endl;
            			break;

            		case 3:
            			cout << redBox.amount << " gold!" << endl;
            			break;
            		}
            	}
            	hunter.goldProfit = hunter.goldGained - hunter.goldLost;
            }
        }
        else{

        	if (hunter.inventory.cheeseArmed.cheeseName == "Gouda"){
        		hunter.inventory.gouda.amount -= 2;
        		hunter.meltedCheese += 2;
        		hunter.cheeseMeltedAtOnce += 2;
        	}

        	if (hunter.inventory.cheeseArmed.cheeseName == "Fiery Fondue"){
        		hunter.inventory.fieryFondue.amount--;
        		hunter.meltedCheese += 1;
        		hunter.cheeseMeltedAtOnce += 1;
        	}

        	if (hunter.inventory.cheeseArmed.cheeseName == "Molten Havarti"){
        		hunter.inventory.moltenHavarti.amount--;
        		hunter.meltedCheese += 1;
        		hunter.cheeseMeltedAtOnce += 1;
        	}

        	if (hunter.inventory.cheeseArmed.cheeseName == "Treasure Hoard Havarti"){
        		hunter.inventory.treasureHavarti.amount--;
        		hunter.meltedCheese += 1;
        		hunter.cheeseMeltedAtOnce += 1;
        	}


        	cout << endl << "No attraction!" << endl;
        }

    return hunter;
}

//self-described
void SeeMiceStats(Player hunter, int hunts){

	double rate = 0.0;

    cout << "Total hunts: " << hunts << endl;

    if((hunter.mice.heated.caught + hunter.mice.heated.missed) != 0){
    	rate = double(hunter.mice.heated.caught) / (hunter.mice.heated.caught + hunter.mice.heated.missed);
    	cout << "Superheated: " << hunter.mice.heated.caught << "/" << hunter.mice.heated.missed << " " << (rate * 100) << "%" << endl;
    }

    if((hunter.mice.magma.caught + hunter.mice.magma.missed) != 0){
        rate = double(hunter.mice.magma.caught) / (hunter.mice.magma.caught + hunter.mice.magma.missed);
        cout << "Magma: " << hunter.mice.magma.caught << "/" << hunter.mice.magma.missed << " " << (rate * 100) << "%" << endl;
    }

    if((hunter.mice.gDragon.caught + hunter.mice.gDragon.missed) != 0){
        rate = double(hunter.mice.gDragon.caught) / (hunter.mice.gDragon.caught + hunter.mice.gDragon.missed);
        cout << "Green Dragon: " << hunter.mice.gDragon.caught << "/" << hunter.mice.gDragon.missed << " " << (rate * 100) << "%" << endl;
    }

    if((hunter.mice.rDragon.caught + hunter.mice.rDragon.missed) != 0){
        rate = double(hunter.mice.rDragon.caught) / (hunter.mice.rDragon.caught + hunter.mice.rDragon.missed);
        cout << "Red Dragon: " << hunter.mice.rDragon.caught << "/" << hunter.mice.rDragon.missed << " " << (rate * 100) << "%" << endl;
    }

    if((hunter.mice.bDragon.caught + hunter.mice.bDragon.missed) != 0){
        rate = double(hunter.mice.bDragon.caught) / (hunter.mice.bDragon.caught + hunter.mice.bDragon.missed);
        cout << "Blue Dragon: " << hunter.mice.bDragon.caught << "/" << hunter.mice.bDragon.missed << " " << (rate * 100) << "%" << endl;
    }

    if((hunter.mice.blkDragon.caught + hunter.mice.blkDragon.missed) != 0){
        rate = double(hunter.mice.blkDragon.caught) / (hunter.mice.blkDragon.caught + hunter.mice.blkDragon.missed);
        cout << "Black Dragon: " << hunter.mice.blkDragon.caught << "/" << hunter.mice.blkDragon.missed << " " << (rate * 100) << "%" << endl;
    }

    if((hunter.mice.mother.caught + hunter.mice.mother.missed) != 0){
        rate = double(hunter.mice.mother.caught) / (hunter.mice.mother.caught + hunter.mice.mother.missed);
        cout << "Broodmother: " << hunter.mice.mother.caught << "/" << hunter.mice.mother.missed << " " << (rate * 100) << "%" << endl;
    }

    return;
}

//spend your gold here!
Player Shop(Player hunter){
	string input;
	char correct = 'n';
	char again = 'y';

	do{
		int goldCostPer = 0;
		int bought = 0;
		int totalGoldCost = 0;
		int emberCostPer = 0;
		int totalEmberCost = 0;

		cout << endl << "You own " << hunter.embers << " embers and " << hunter.gold << " gold." << endl;

		cout << "What would you like to buy?" << endl;
		cout << "Gouda = buy gouda, 600 gold per piece." << endl;
		cout << "MH = buy Molten Havarti. Spend 1 ember, 5,000 gold for pack of five pieces." << endl;
		cout << "Power = Power-based trap. Spend 100 embers, 5 million gold. Max of one." << endl;
		cout << "Luck = Luck-based trap. Spend 100 embers, 5 million gold. Max of one." << endl;
		cout << "None = leave shop." << endl;

		do{
			cin >> input;

			if(input == "None"){
				return hunter;
			}

			cout << endl << "How many would you like to buy?" << endl;
			cin >> bought;

			if (input == "Gouda"){
				goldCostPer = 600;
			}
			else if (input == "MH"){
				goldCostPer = 5000;
				emberCostPer = 1;
			}
			else if (input == "Power"){

				if (hunter.inventory.powerTrap.inInventory == true){
					cout << "You can't buy any more of those!" << endl;
					bought = 0;
				}
				else if (bought == 1){
					goldCostPer = 5000000;
					emberCostPer = 100;
				}
				else{
					cout << "You can only buy one of those!" << endl;
					bought = 1;
					goldCostPer = 5000000;
					emberCostPer = 100;
				}
			}
			else if(input == "Luck"){
				if (hunter.inventory.luckTrap.inInventory == true){
					cout << "You can't buy any more of those!" << endl;
					bought = 0;
				}
				else if (bought == 1){
					goldCostPer = 5000000;
					emberCostPer = 100;
				}
				else{
					cout << "You can only buy one of those!" << endl;
					bought = 1;
					goldCostPer = 5000000;
					emberCostPer = 100;
				}
			}
			else{
				cout << "Invalid choice! Leaving shop." << endl;
				return hunter;
			}

			totalGoldCost = bought * goldCostPer;
			totalEmberCost = bought * emberCostPer;

			cout << "You want to buy " << bought << " " << input << " for " << totalGoldCost << " gold and " << totalEmberCost
					<< " embers. Is this correct? Enter 'n' to choose again." << endl;
			cin >> correct;

			if(correct != 'n'){
				if ((hunter.gold < totalGoldCost) || (hunter.embers < totalEmberCost)){
					cout << "You can't afford that!" << endl;
				}
				else{

					if(input == "Gouda"){
						hunter.inventory.gouda.amount += bought;
					}

					if (input == "MH"){
						hunter.inventory.moltenHavarti.amount += (bought * 5);
					}

					if (input == "Power" && bought == 1){
						cout << "You bought the Power Trap!" << endl;
						hunter.inventory.powerTrap.inInventory = true;
					}

					if (input == "Luck" && bought == 1){
						cout << "You bought the Luck Trap!" << endl;
						hunter.inventory.luckTrap.inInventory = true;
					}

					hunter.gold -= totalGoldCost;
					hunter.goldLost += totalGoldCost;
					hunter.embers -= totalEmberCost;
				}
			}
		}while (correct == 'n');

		cout << "Do you want to buy anything else? Enter 'y' to buy again." << endl;
		cin >> again;
	}while(again == 'y');

	return hunter;
}

//Turn old stuff into new stuff
Player Craft(Player hunter){
	string input;
	int sapphiresSpentPer = 0;
	int emeraldsSpentPer = 0;
	int rubiesSpentPer = 0;
	int scalesSpentPer = 0;
	int meltedCheesePer = 0;
	int goldCostPer = 0;
	int crafted = 0;
	int totalScaleCost = 0;
	int totalRubyCost = 0;
	int totalSapphireCost = 0;
	int totalEmeraldCost = 0;
	int meltedCheeseTotal = 0;
	int emberCostPer = 0;
	int totalEmberCost = 0;
	int totalGoldCost = 0;
	char correct = 'n';
	char again = 'y';

	do{

	cout << "You own " << hunter.embers << " embers, " << hunter.meltedCheese << " melted cheese." << endl;
	cout << "You own " << hunter.rubies << "/" << hunter.sapphires << "/" << hunter.emeralds  << "/" << hunter.scales
			<< " rubies/sapphires/emeralds/scales." << endl;

	cout << "What would you like to craft?" << endl;
	cout << "Melt = Craft melted cheese, one ember per piece." << endl;
	cout << "FF = Craft Fiery Fondue. Spend 1 ember, 10 melted cheese for pack of ten pieces." << endl;
	cout << "THH3 = Craft 3 Treasure Hoard Havarti. Spend 10 embers, 3 Sapphires, 3 Rubies, 3 Emeralds, 30 Melted cheese." << endl;
	cout << "THH4 = Craft 4 Treasure Hoard Havarti. Spend 10 embers, 3 Sapphires, 3 Rubies, 3 Emeralds, 30 Melted cheese and 40,000 gold." << endl;
	cout << "Charm = Craft Dragon Charm. Spend 10 embers, 10 scales each." << endl;
	cout << "Trap = Craft Best trap. Spend 1000 embers, 50 scales, both Power and Luck traps. Max of one." << endl;
	cout << "Base = Craft Basalt base. Spend 500 embers, 50 scales. Max of one." << endl;
	cout << "None = stop crafting." << endl;

		do{
			cin >> input;

			if(input == "None"){
				return hunter;
			}

			cout << endl << "How many would you like to craft?" << endl;
			cin >> crafted;

			if (input == "Melt"){
				emberCostPer = 1;
			}
			else if (input == "FF"){
				meltedCheesePer = 10;
				emberCostPer = 1;
			}
			else if (input == "THH3"){
				meltedCheesePer = 30;
				rubiesSpentPer = 3;
				sapphiresSpentPer = 3;
				emeraldsSpentPer = 3;
				emberCostPer = 10;
			}
			else if (input == "THH4"){
				meltedCheesePer = 30;
				rubiesSpentPer = 3;
				sapphiresSpentPer = 3;
				emeraldsSpentPer = 3;
				emberCostPer = 10;
				goldCostPer = 40000;
			}
			else if(input == "Charm"){
				emberCostPer = 10;
				totalScaleCost = 10;
			}
			else if(input == "Trap"){
				if (hunter.inventory.bestTrap.inInventory){
					cout << "You can't craft any more of those!" << endl;
					crafted = 0;
				}
				else if (crafted == 1){
					emberCostPer = 1000;
					scalesSpentPer = 50;
				}
				else{
					cout << "You can only craft one of those!" << endl;
					crafted = 1;
					scalesSpentPer = 50;
					emberCostPer = 1000;
				}
			}
			else if(input == "Base"){
				if (hunter.inventory.basalt.inInventory){
					cout << "You can't craft any more of those!" << endl;
					crafted = 0;
				}
				else if (crafted == 1){
					emberCostPer = 500;
					scalesSpentPer = 50;
				}
				else{
					cout << "You can only craft one of those!" << endl;
					crafted = 1;
					scalesSpentPer = 50;
					emberCostPer = 500;
				}
			}
			else{
				cout << "Invalid choice! Leaving crafting menu." << endl;
				return hunter;
			}


			totalEmberCost = crafted * emberCostPer;
			totalScaleCost = crafted * scalesSpentPer;
			totalRubyCost = crafted * rubiesSpentPer;
			totalSapphireCost = crafted * sapphiresSpentPer;
			totalEmeraldCost = crafted * emeraldsSpentPer;
			meltedCheeseTotal = crafted * meltedCheesePer;
			totalGoldCost = crafted * goldCostPer;


			cout << "You are going to craft " << crafted << " " << input << "." << endl;
			cout << "This will require " << totalEmberCost << " embers, " << meltedCheeseTotal << " melted cheese, and "
					<< totalRubyCost << "/" << totalSapphireCost << "/" << totalEmeraldCost << "/" << totalScaleCost
					<< " rubies/sapphires/emeralds/scales." << endl;

			if (totalGoldCost != 0){
				cout << "You will also spend " << totalGoldCost << " gold on SB+." << endl;
			}
			cout << "Is this correct? Enter 'n' to choose again." << endl;
			cin >> correct;

			if(correct != 'n'){
				if (hunter.emeralds < totalEmeraldCost || hunter.rubies < totalRubyCost || hunter.sapphires < totalSapphireCost
						|| hunter.embers < totalEmberCost || hunter.scales < totalScaleCost || hunter.meltedCheese < meltedCheeseTotal){
					cout << "You can't afford that!" << endl;
				}
				else{
					if(input == "Melt"){
						hunter.meltedCheese += crafted;
					}

					if (input == "FF"){
						hunter.inventory.fieryFondue.amount += (crafted * 10);
					}

					if (input == "THH3"){
						hunter.inventory.treasureHavarti.amount += (crafted * 3);
					}

					if (input == "THH4"){
						hunter.inventory.treasureHavarti.amount += (crafted * 4);
					}

					if (input == "Trap" && crafted == 1 && hunter.inventory.powerTrap.inInventory == true
							&& hunter.inventory.luckTrap.inInventory == true){
						cout << "You made the Best Trap!" << endl;
						hunter.inventory.powerTrap.inInventory = false;
						hunter.inventory.luckTrap.inInventory = false;
						hunter.inventory.bestTrap.inInventory = true;
					}

					if (input == "Base"){
						cout << "You made the Basalt Base!" << endl;
						hunter.inventory.basalt.inInventory = true;
					}

					hunter.embers -= totalEmberCost;
					hunter.emeralds -= totalEmeraldCost;
					hunter.rubies -= totalRubyCost;
					hunter.sapphires -= totalSapphireCost;
					hunter.scales -= totalScaleCost;
					hunter.meltedCheese -= meltedCheeseTotal;
				}
			}

		}while (correct == 'n');

			cout << "Do you want to craft anything else? Enter 'y' to buy again." << endl;
			cin >> again;
		}while(again == 'y');


	return hunter;
}

//set the trap, called after initial setup, changing parts, and after each hunt
Player SetTrap(Player hunter){

	Cheese cheese;
	Charm charm;
	int setPieces = 0;
	int setPowerBonus = 0;
	int setLuckBonus = 0;

	if (hunter.inventory.cheeseArmed.cheeseName == "Gouda"){
		cheese = hunter.inventory.gouda;
	}

	if (hunter.inventory.cheeseArmed.cheeseName == "Fiery Fondue"){
		cheese = hunter.inventory.fieryFondue;
	}

	if (hunter.inventory.cheeseArmed.cheeseName == "Molten Havarti"){
		cheese = hunter.inventory.moltenHavarti;
	}

	if (hunter.inventory.cheeseArmed.cheeseName == "Treasure Hoard Havarti"){
		cheese = hunter.inventory.treasureHavarti;
	}

	hunter.inventory.cheeseArmed = cheese;

	if(hunter.inventory.charmArmed.charmName == "Ultimate"){
		charm = hunter.inventory.ultimate;
	}

	if(hunter.inventory.charmArmed.charmName == "Dragon"){
		charm = hunter.inventory.dragon;
	}

	if(hunter.inventory.charmArmed.charmName == "none"){
		charm = hunter.inventory.noCharm;
	}

	hunter.inventory.charmArmed = charm;

	if(hunter.inventory.weaponArmed.inSet == true){
		setPieces++;
	}

	if(hunter.inventory.baseArmed.inSet == true){
		setPieces++;
	}

	if(hunter.inventory.charmArmed.inSet == true){
		setPieces++;
	}

	if(setPieces > 1){
		setPowerBonus = 10000;
	}

	if(setPieces == 3){
		setLuckBonus = 30;
	}

	hunter.inventory.powerBonus = (hunter.inventory.weaponArmed.wPowerBonus + hunter.inventory.baseArmed.bPowerBonus
			+ hunter.inventory.charmArmed.charmPowerBonus) / 100.0;

	hunter.inventory.trapPower = hunter.inventory.weaponArmed.wPower + hunter.inventory.baseArmed.bPower
			+ hunter.inventory.charmArmed.charmPower + setPowerBonus;

	hunter.inventory.trapPowerTotal = hunter.inventory.trapPower + (hunter.inventory.trapPower * hunter.inventory.powerBonus);

	if(hunter.inventory.shield == true){
		hunter.inventory.trapLuck = hunter.inventory.weaponArmed.wLuck + hunter.inventory.baseArmed.bLuck
				+ hunter.inventory.charmArmed.charmLuck + 7 + setLuckBonus;
	}
	else{
		hunter.inventory.trapLuck = hunter.inventory.weaponArmed.wLuck + hunter.inventory.baseArmed.bLuck
				+ hunter.inventory.charmArmed.charmLuck + setLuckBonus;
	}

	hunter.inventory.attractionRateBonus = (1 - hunter.inventory.cheeseArmed.cheeseAttractionRate) * (hunter.inventory.weaponArmed.wAttractionBonus
			+ hunter.inventory.baseArmed.bAttractionBonus + hunter.inventory.charmArmed.charmAttractionBonus);

	hunter.inventory.attractionRate = hunter.inventory.cheeseArmed.cheeseAttractionRate + hunter.inventory.attractionRateBonus;

	return hunter;
}

//self-described
void SeeInventory(Player hunter){

	cout << endl << "You have " << hunter.gold << " gold and " << hunter.points << " points." << endl;
	cout << "You own " << hunter.embers << " embers, " << hunter.meltedCheese << " melted cheese." << endl;
	cout << "You own " << hunter.rubies << "/" << hunter.sapphires << "/" << hunter.emeralds  << "/" << hunter.scales
			<< " rubies/sapphires/emeralds/scales." << endl;

	if(hunter.inventory.iceMaiden.inInventory == true){
		cout << "You own the Ice Maiden." << endl;
	}
	if(hunter.inventory.powerTrap.inInventory == true){
		cout << "You own the Power trap." << endl;
	}
	if(hunter.inventory.luckTrap.inInventory == true){
		cout << "You own the Luck trap." << endl;
	}
	if(hunter.inventory.bestTrap.inInventory == true){
		cout << "You own the Best trap." << endl;
	}

	if(hunter.inventory.rift.inInventory == true){
		cout << "You own the Rift base." << endl;
	}

	if(hunter.inventory.mino.inInventory == true){
		cout << "You own the Minotaur Base."<< endl;
	}

	if(hunter.inventory.basalt.inInventory == true){
		cout << "You own the Basalt Base."<< endl;
	}

	cout << "You own " << hunter.inventory.ultimate.amount << " Ultimate Charms." << endl;
	cout << "You own " << hunter.inventory.dragon.amount << " Dragon Charms." << endl;

	cout << "You own " << hunter.inventory.gouda.amount << " gouda." << endl;
	cout << "You own " << hunter.inventory.fieryFondue.amount << " Fiery Fondue." << endl;
	cout << "You own " << hunter.inventory.moltenHavarti.amount << " Molten Havarti." << endl;
	cout << "You own " << hunter.inventory.treasureHavarti.amount << " Treasure Hoard Havarti." << endl;

	return;
}
