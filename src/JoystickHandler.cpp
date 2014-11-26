/*
 * JoystickHandler.cpp
 *
 *  Created on: 2014-11-23
 *      Author: 11110305
 */
/*
#include "JoystickHandler.h"

void JoystickHandler::ButtonMethod1() {BrasDrapeau->PositionBrasPrise();}
void JoystickHandler::ButtonMethod2() {BrasDrapeau->PositionBrasBase();}
void JoystickHandler::ButtonMethod3() {}
void JoystickHandler::ButtonMethod4() {}


JoystickHandler::JoystickHandler() {
	// TODO Auto-generated constructor stub
	Gamepad = new TKGamepad(0);
	DriveBase = new TKDrivingBase();
	BrasDrapeau = new TKBras(6, 4);
	PinceDrapeau = new TKPince(0);
	eventmap[BOUTONA] = &JoystickHandler::ButtonMethod1;
	eventmap[BOUTONB] = &JoystickHandler::ButtonMethod2;
	eventmap[BOUTONX] = &JoystickHandler::ButtonMethod3;
	eventmap[BOUTONY] = &JoystickHandler::ButtonMethod4;
}



JoystickHandler::~JoystickHandler() {
	// TODO Auto-generated destructor stub
}

//void JoystickHandler::FillEventList() {}


void JoystickHandler::UpdateDriveBase()
{
	DriveBase->Drive(Gamepad->GetLeftX(), Gamepad->GetLeftY());
}

void JoystickHandler::Call()
{
	UpdateDriveBase();
	std::vector<NomBouton> eventlist = Gamepad->Get();
	for (int i = 0; i < ((int)eventlist.size()); i++)
	{
		(this->*eventmap[eventlist[i]])();
	}

}
*/
