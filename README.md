# MagChamberSim
A simulator for a Mousehunt area idea.
Yeah, I know I ignored a bunch of coding standards. Bite me, this isn't professionally done.

Notes: To add trap components, declare them in "Inventory.h", and define them in "Inventory.cpp". Make sure to add a way to get them!
To change mouse power or add new mice, change "MiceStats.cpp".
Catch rate is determined through the community-determined 3-eff model. Effectiveness multiplier is a constant, set globally.
