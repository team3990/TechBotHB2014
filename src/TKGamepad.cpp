/**
 * Copyright (c) TechForKid 2014. All Rights Reserved.
 * More details at www.team3990.com
 * Open Source Software - may be modified and shared by FRC teams.
 * Code is based on the new roboRIO 2015 and is published as an illustrative
 * example of what to expect regarding C++ on a FRC robot.
 */

#include "TKGamepad.h"
/**
 * Constructor.
 */
TKGamepad::TKGamepad(uint32_t port) : Joystick(port)
{
}

/**
 * Destructor.
 */
TKGamepad::~TKGamepad()
{

}

float TKGamepad::GetLeftX()
{
	return -Joystick::GetRawAxis(2);
}

float TKGamepad::GetLeftY()
{
	return Joystick::GetRawAxis(1);
}

float TKGamepad::GetRightY()
{
	return Joystick::GetRawAxis((uint32_t)4);
}

float TKGamepad::Trigger()
{
	return Joystick::GetRawAxis(uint32_t(3));
}

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

	return aretourner;
}
