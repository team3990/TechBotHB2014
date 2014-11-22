/*
 * TKDriveBase.cpp
 *
 *  Created on: 2014-11-22
 *      Author: Administrateur
 */


#include "TKDriveBase.h"

/**
 * Constructor
 */
TKDrivingBase::TKDrivingBase() : 	mShifter(NULL),
									mMotorLeft(NULL),
									mMotorRight(NULL),
									mMotors(NULL)
{
	// Initialize
	mShifter = new Solenoid(uint32_t(kSol_Shifter));
	mMotorLeft = new Victor(kPWM_MotorLeft);
	mMotorRight = new Victor(kPWM_MotorRight);

	// Instantiate
	mShifter->Set(true);
	mMotorLeft->Set(0.0);
	mMotorRight->Set(0.0);

	// Default value
	mMotorLeft->Set(0.0);
	mMotorRight->Set(0.0);

	// Create a new robot drive using standard left/right drive.
	//mMotors = new RobotDrive(&mMotorLeft, &mMotorRight);

	// Enable Motor Safety features
	mMotorLeft->EnableDeadbandElimination(true);
	mMotorRight->EnableDeadbandElimination(true);
}

/**
 * Destructor
 */
TKDrivingBase::~TKDrivingBase()
{

}

/**
 * Initialize the SmartDashboard.
 */
void TKDrivingBase::SmartDashboardInit()
{

}

/**
 * Update the SmartDashboard.
 */
void TKDrivingBase::SmartDashboardUpdate()
{

}

/**
 * Drive functionalities.
 */
void TKDrivingBase::Drive(float iForward, float iRotation)
{
	mMotors->ArcadeDrive(-iForward, iRotation);
}

/**
 * Drive in high speed.
 */
void TKDrivingBase::HighSpeed()
{
	mShifter->Set(true);
}

/**
 * Drive in low speed.
 */
void TKDrivingBase::LowSpeed()
{
	mShifter->Set(false);
}

/**
 * Toggle speed.
 */
void TKDrivingBase::ToggleSpeed()
{
	if (mShifter->Get() == true)
	{
		mShifter->Set(false);
	}
	else
	{
		mShifter->Set(true);
	}
}

