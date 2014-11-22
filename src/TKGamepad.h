/*
 * TKGamepad.h
 *
 *  Created on: 2014-11-22
 *      Author: Administrateur
 */

#ifndef SRC_TKGAMEPAD_H_
#define SRC_TKGAMEPAD_H_

#include "WPILIB.h"


class TKGamepad : public Joystick
{
public:

// Constructors
	explicit 			TKGamepad(uint32_t port);
	virtual 			~TKGamepad();

	// Methods
	float				GetLeftX();
	float				GetLeftY();
	float				GetRightX();
	float				GetRightY();
	float				Trigger();

private:
	DISALLOW_COPY_AND_ASSIGN(TKGamepad);

};


#endif /* SRC_TKGAMEPAD_H_ */
