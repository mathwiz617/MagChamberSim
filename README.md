# MagChamberSim
A simulator for a Mousehunt area idea.
Yeah, I know I ignored a bunch of coding standards. Bite me, this isn't professionally done.

Notes: To add trap components, declare them in "Inventory.h", and define them in "Inventory.cpp". Make sure to add a way to get them, and add them to SeeInventory, SetTrap, and the relevant Choose function. If you add cheese or a charm, make sure to subtract them appropriately after each hunt.

To change mouse power or add new mice, change "MiceStats.cpp" and "Mouse.h". Make sure to add loot in Mouse.cpp and SeeMiceStats.

Catch rate is determined through the community-determined 3-eff model. Effectiveness multiplier is a constant, set globally.

To add loot, change "Inventory.cpp" and "Inventory.h". Make sure to add it to Mouse::GetLoot and SeeInventory, and give it a purpose.
