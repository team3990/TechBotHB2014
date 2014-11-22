#include "TKRobot.h"

/**
 * Constructor
 */
TKRobot::TKRobot()
{
	lw = LiveWindow::GetInstance();
}

/**
 * Destructor
 */
TKRobot::~TKRobot()
{
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

}

/**
 * Robot Routine: Robot in teleop mode.
 */
void TKRobot::TeleopPeriodic()
{

}

/**
 * Robot Routine: Robot in test mode.
 */
void TKRobot::TestPeriodic()
{
	lw->Run();
}



START_ROBOT_CLASS(TKRobot);
