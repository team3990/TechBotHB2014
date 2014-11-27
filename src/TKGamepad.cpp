/**
 * Copyright (c) Équipe Team 3990: Tech for Kids 2014. All Rights Reserved.
 * Open Source Software - may be modified and shared by FRC teams. The code
 * must be accompanied by the FIRST BSD license file.
 * @author 		Esther Guerrier
 * @abstract	Class for handling joystick operations.
 */

#include "TKGamepad.h"

/**
 * Constructor.
 */
TKGamepad::TKGamepad(uint32_t port) : Joystick(port)
{
	// float LeftStick[1];
	// float RightStick[1];
}

/**
 * Destructor.
 */
TKGamepad::~TKGamepad()
{

}

/**
 * Get left axis horizontal values.
 * @return float
 */
float TKGamepad::GetLeftX()
{
	return -Joystick::GetRawAxis(0);
}

/**
 * Get left axis vertical values.
 * @return float
 */
float TKGamepad::GetLeftY()
{
	return Joystick::GetRawAxis(1);
}

/**
 * Get right axis horizontal values.
 * @return float
 */
float TKGamepad::GetRightX()
{
	return Joystick::GetRawAxis(4);
}

/**
 * Get right axis vertical values.
 * @return float
 */
float TKGamepad::GetRightY()
{
	return Joystick::GetRawAxis(5);
}

/**
 * Get left trigger values.
 * @return float
 */
float TKGamepad::GetLeftTriggerAxis()
{

	return Joystick::GetRawAxis(2);
}

/**
 * Get right trigger values.
 * @return float
 */
float TKGamepad::GetRightTriggerAxis()
{

	return Joystick::GetRawAxis(3);
}

/**
 * Get left trigger values.
 * @return float
 */
bool TKGamepad::GetLeftTriggerButton()
{
	bool isButtonPressed = false;
	if (Joystick::GetRawAxis(2) > 0.5) isButtonPressed = true;
	return isButtonPressed;
}

/**
 * Get right trigger values.
 * @return float
 */
bool TKGamepad::GetRightTriggerButton()
{
	bool isButtonPressed = false;
	if (Joystick::GetRawAxis(3) > 0.5) isButtonPressed = true;
	return isButtonPressed;
}
/*
std::vector<NomBouton> TKGamepad::Get()
{
	std::map<int, NomBouton> x;
	x[0] = BOUTONA;
	x[1] = BOUTONB;
	x[2] = BOUTONX;
	x[3] = BOUTONY;

	std::vector<NomBouton> aretourner;
	std::map<int,NomBouton>::iterator iter;
	for(iter=x.begin(); iter!=x.end(); iter++)
	{
		if(Joystick::GetRawButton(iter->first))
		{
			aretourner.push_back(iter->second);
		}
	}
	LeftStick[0] = this->GetLeftX();
	LeftStick[1] = this->GetLeftY();
	RightStick[0] = this->GetRightX();
	RightStick[1] = this->GetRightY();

	return aretourner;
}
*/
