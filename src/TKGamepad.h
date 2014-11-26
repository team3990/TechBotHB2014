/*
 * TKGamepad.h
 *
 *  Created on: 2014-11-22
 *      Author: Administrateur
 */

#ifndef TECHBOTHB2014_SRC_TKGAMEPAD_H_
#define TECHBOTHB2014_SRC_TKGAMEPAD_H_

#include "WPILib.h"
// #include <vector>
// #include <map>

// enum NomBouton {BOUTONA, BOUTONB, BOUTONX, BOUTONY, RBBUTTON, LBBUTTON, BACKBUTTON, STARTBUTTON, LEFTSTICKBUTTON, RIGHTSTICKBUTTON};
// enum NomAxe {LEFTSTICKXAXIS, LEFTSTICKYAXIS, LEFTTRIGGER, RIGHTTRIGGER, RIGHTSTICKXAXIS, RIGHTSTICKYAXIS};

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
	// std::vector<NomBouton>   Get();
	// float LeftStick[];
	// float RightStick[];

private:
	DISALLOW_COPY_AND_ASSIGN(TKGamepad);

};


#endif /* TECHBOTHB2014_SRC_TKGAMEPAD_H_ */
