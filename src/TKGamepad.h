/**
 * Copyright (c) Équipe Team 3990: Tech for Kids 2014. All Rights Reserved.
 * Open Source Software - may be modified and shared by FRC teams. The code
 * must be accompanied by the FIRST BSD license file.
 * @author 		Esther Guerrier
 * @abstract	Class for handling joystick operations.
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
	// Constructor & destructor
	explicit 			TKGamepad(uint32_t port);
	virtual 			~TKGamepad();

	// Left Axis
	float				GetLeftX();
	float				GetLeftY();

	// Right Axis
	float				GetRightX();
	float				GetRightY();

	// Trigger Axis
	float				GetLeftTriggerAxis();
	float 				GetRightTriggerAxis();

	// Trigger Buttons
	bool				GetLeftTriggerButton();
	bool				GetRightTriggerButton();

	// std::vector<NomBouton>   Get();
	// float LeftStick[];
	// float RightStick[];

private:
	DISALLOW_COPY_AND_ASSIGN(TKGamepad);

};

#endif /* TECHBOTHB2014_SRC_TKGAMEPAD_H_ */
