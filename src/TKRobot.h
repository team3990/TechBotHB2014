/**
 * Copyright (c) Équipe Team 3990: Tech for Kids 2014. All Rights Reserved.
 * Open Source Software - may be modified and shared by FRC teams. The code
 * must be accompanied by the FIRST BSD license file.
 * @author 		Olivier Lalonde, Esther Guerrier
 * @abstract	Class for handling robot operations.
 */

#ifndef TECHBOTHB2014_SRC_TKROBOT_H_
#define TECHBOTHB2014_SRC_TKROBOT_H_

#include "TKBras.h"
#include "TKPince.h"
#include "TKGamepad.h"
#include "TKDriveBase.h"
#include "TKConfig.h"

class TKRobot : public IterativeRobot
{
private:

public:
	// Constructors
	TKRobot();
	virtual ~TKRobot();

	// Objects
	TKBras 			* BrasDrapeau;
	TKPince			* PinceDrapeau;
	TKDrivingBase 	* DrivingBase;
	TKGamepad 		* gamepadLeft;
	TKGamepad		* gamepadRight;

	// Robot Routines
	void			RobotInit();
	void			AutonomousInit();
	void			AutonomousPeriodic();
	void			TeleopInit();
	void			TeleopPeriodic();
	void			TestPeriodic();
};



#endif /* TECHBOTHB2014_SRC_TKROBOT_H_ */
