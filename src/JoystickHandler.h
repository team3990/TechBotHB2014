/*
 * JoystickHandler.h
 *
 *  Created on: 2014-11-23
 *      Author: 11110305
 */
/*
#ifndef TECHBOTHB2014_SRC_JOYSTICKHANDLER_H_
#define TECHBOTHB2014_SRC_JOYSTICKHANDLER_H_
#include "TKGamepad.h"
#include "TKDriveBase.h"
#include "TKBras.h"
#include "TKPince.h"



// Used to match the raw events to functions
class JoystickHandler {
public:
	JoystickHandler();
	virtual ~JoystickHandler();

	typedef void (JoystickHandler::*EventMethod)();
	void Call();
	std::map<NomBouton, EventMethod> eventmap;


private:
	TKGamepad * Gamepad;
	TKDrivingBase * DriveBase;
	TKBras 			* BrasDrapeau;
	TKPince			* PinceDrapeau;



	void FillEventList();
	void UpdateDriveBase();

	void ButtonMethod1();
	void ButtonMethod2();
	void ButtonMethod3();
	void ButtonMethod4();


};

#endif /* TECHBOTHB2014_SRC_JOYSTICKHANDLER_H_ */
