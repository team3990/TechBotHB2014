#include "TKRobot.h"


/**
 * Constructor
 */
TKRobot::TKRobot()
{
	lw = LiveWindow::GetInstance();
	BrasDrapeau = new TKBras(0, 0);
	PinceDrapeau = new TKPince(0);

}

/**
 * Destructor
 */
TKRobot::~TKRobot()
{
	delete BrasDrapeau;
	delete PinceDrapeau;
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
	PinceDrapeau->PinceOuvrir();
}

/**
 * Robot Routine: Robot in teleop mode.
 */
void TKRobot::TeleopPeriodic()
{
	BrasDrapeau->Set();
	PinceDrapeau->Set();
}

/**
 * Robot Routine: Robot in test mode.
 */
void TKRobot::TestPeriodic()
{
	lw->Run();
}



START_ROBOT_CLASS(TKRobot);
