/*
 * TKRobot.h
 *
 *  Created on: 2014-11-22
 *      Author: Administrateur
 */

#ifndef TECHBOTHB2014_SRC_TKROBOT_H_
#define TECHBOTHB2014_SRC_TKROBOT_H_


#include "TKBras.h"
#include "TKPince.h"
#include "TKGamepad.h"
#include "TKDriveBase.h"


class TKRobot : public IterativeRobot
{
private:
	LiveWindow		* lw;

public:
	// Constructors
	TKRobot();
	virtual ~TKRobot();

	// Objects
	TKBras 			* BrasDrapeau;
	TKPince			* PinceDrapeau;
	TKDrivingBase 	* DrivingBase;
	TKGamepad 		* Gamepad;

	// Robot Routines
	void			RobotInit();
	void			AutonomousInit();
	void			AutonomousPeriodic();
	void			TeleopInit();
	void			TeleopPeriodic();
	void			TestPeriodic();
};



#endif /* TECHBOTHB2014_SRC_TKROBOT_H_ */
