#include "TKRobot.h"


/**
 * Constructor
 */
TKRobot::TKRobot()
{
	lw = LiveWindow::GetInstance();
	BrasDrapeau = new TKBras(6, 4);
	PinceDrapeau = new TKPince(0);
	Gamepad = new TKGamepad(1);
	DrivingBase = new TKDrivingBase();
}

/**
 * Destructor
 */
TKRobot::~TKRobot()
{
	delete BrasDrapeau;
	delete PinceDrapeau;
	delete Gamepad;
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
	BrasDrapeau->PositionBrasBase();
	//	PinceDrapeau->PinceOuvrir();
}

/**
 * Robot Routine: Robot in teleop mode.
 */
void TKRobot::TeleopPeriodic()
{

	DrivingBase->Drive(Gamepad->GetLeftX(), Gamepad->GetLeftY());
	if(Gamepad->Joystick::GetRawButton(0))
	{
		BrasDrapeau->PositionBrasPrise();
	}
	if(Gamepad->Joystick::GetRawButton(1))
		{
			BrasDrapeau->PositionBrasBase();
		}
	BrasDrapeau->Set();
	//PinceDrapeau->Set();

}

/**
 * Robot Routine: Robot in test mode.
 */
void TKRobot::TestPeriodic()
{
	lw->Run();
}



START_ROBOT_CLASS(TKRobot);
