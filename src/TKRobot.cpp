/**
 * Copyright (c) Équipe Team 3990: Tech for Kids 2014. All Rights Reserved.
 * Open Source Software - may be modified and shared by FRC teams. The code
 * must be accompanied by the FIRST BSD license file.
 * @author 		Olivier Lalonde, Esther Guerrier
 * @abstract	Class for handling robot operations.
 */

#include "TKRobot.h"

/**
 * Constructor
 */
TKRobot::TKRobot()
{
	// Robot Objects
	printf("\nInstantiate TKBras");
	BrasDrapeau = new TKBras(kSol_PistonVertical, kSol_PistonHorizontal);

	printf("\nInstantiate TKPince");
	PinceDrapeau = new TKPince(kPWM_Pince);

	printf("\nInstantiate TKGamepad");
	gamepadLeft = new TKGamepad(kUSB_GamePadLeft);
	gamepadRight = new TKGamepad(kUSB_GamePadRight);

	printf("\nInstantiate TKDrivingBase");
	DrivingBase = new TKDrivingBase();
}

/**
 * Destructor
 */
TKRobot::~TKRobot()
{
	delete BrasDrapeau;
	delete PinceDrapeau;
	delete gamepadLeft;
	delete DrivingBase;
}

/**
 * Robot Routine: Initialize the robot on power.
 */
void TKRobot::RobotInit()
{

}

/**
 * Robot Routine: Initialize the robot on autonomous.
 */
void TKRobot::AutonomousInit()
{

}

/**
 * Robot Routine: Robot in autonomous mode.
 */
void TKRobot::AutonomousPeriodic()
{

}

/**
 * Robot Routine: Initialize the robot on teleop.
 */
void TKRobot::TeleopInit()
{
	// Mettre en position initiale (x- z+ p-)
	printf("\nTeleopInit: brasdrapeau=%p\n", BrasDrapeau);
	PinceDrapeau->Open();
}

/**
 * Robot Routine: Robot in teleop mode.
 */
void TKRobot::TeleopPeriodic()
{
	// Driving Base
	DrivingBase->Drive(gamepadRight->GetRawAxis(0), gamepadRight->GetRawAxis(1));

	// Handlers
	BrasDrapeau->Set();
	PinceDrapeau->Run();

	// Put arm in grab position
	if (gamepadLeft->GetRawButton(1))
	{
		BrasDrapeau->PositionBrasPrise();
	}

	// Retract arm inside the robot
	if (gamepadLeft->GetRawButton(2))
	{
		BrasDrapeau->PositionBrasBase();
	}

	// Open clamp
	if (gamepadLeft->GetRawButton(5) || gamepadLeft->GetRawButton(6) ||
			gamepadLeft->GetLeftTriggerButton() || gamepadLeft->GetRightTriggerButton())
	{
		PinceDrapeau->Open();
	}
	else
	{
		PinceDrapeau->Close();
	}

}

/**
 * Robot Routine: Robot in test mode.
 */
void TKRobot::TestPeriodic()
{
}

START_ROBOT_CLASS(TKRobot);
