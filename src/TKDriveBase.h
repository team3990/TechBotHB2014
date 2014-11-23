/*
 * TKDriveBase.h
 *
 *  Created on: 2014-11-22
 *      Author: Administrateur
 */

#ifndef SRC_TKDRIVEBASE_H_
#define SRC_TKDRIVEBASE_H_

#include "WPILib.h"
#include "TKConfig.h"


class TKDrivingBase
{

public:

	// Constructors & Destructors
	TKDrivingBase();
	virtual ~TKDrivingBase();

	// Solenoids & pneumatics
	Solenoid		* mShifter;

	// PWM
	Victor			* mMotorLeft;
	Victor			* mMotorRight;

	// Other
	RobotDrive		* mMotors;

	// Methods
	void			SmartDashboardInit();
	void			SmartDashboardUpdate();
	void			Drive(float iForward, float iRotation);
	void			HighSpeed();
	void			LowSpeed();
	void			ToggleSpeed();

};



#endif /* SRC_TKDRIVEBASE_H_ */
