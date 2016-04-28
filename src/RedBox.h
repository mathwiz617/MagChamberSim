/*
 * RedBox.h
 *
 *  Created on: Apr 25, 2016
 *      Author: matt
 */

#ifndef REDBOX_H_
#define REDBOX_H_

class RedBox {
public:
	int type;
	int amount;

	RedBox();
	RedBox(int, int);
	virtual ~RedBox();
};

#endif /* REDBOX_H_ */
