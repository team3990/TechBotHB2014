/*
 * TKRobot.h
 *
 *  Created on: 2014-11-22
 *      Author: Administrateur
 */

#ifndef SRC_TKROBOT_H_
#define SRC_TKROBOT_H_

#include "WPILib.h"

class TKRobot : public IterativeRobot
{
private:
	LiveWindow 	* lw;

public:
	// Constructors
	TKRobot();
	virtual ~TKRobot();

	// Robot Routines
	void		RobotInit();
	void		AutonomousInit();
	void		AutonomousPeriodic();
	void		TeleopInit();
	void		TeleopPeriodic();
	void		TestPeriodic();
};



#endif /* SRC_TKROBOT_H_ */
