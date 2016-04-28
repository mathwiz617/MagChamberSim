/*
 * MiceStats.h
 *
 *  Created on: Apr 26, 2016
 *      Author: matt
 */

#ifndef MICESTATS_H_
#define MICESTATS_H_

#include "Mouse.h"

class MiceStats {
public:
	//declare mice here
	Mouse none;
	Mouse heated;
	Mouse magma;
	Mouse gDragon;
	Mouse rDragon;
	Mouse bDragon;
	Mouse blkDragon;
	Mouse mother;
	Mouse attracted;

	MiceStats();
	virtual ~MiceStats();
};

#endif /* MICESTATS_H_ */
