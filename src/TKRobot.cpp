#include "TKRobot.h"


/**
 * Constructor
 */
TKRobot::TKRobot()
{
	printf("\nInstantiate LiveWindow");
	lw = LiveWindow::GetInstance();
	printf("\nPointeur lw: %p", lw);

	// Robot Objects
	printf("\nInstantiate TKBras");
	BrasDrapeau = new TKBras(kSol_PistonVertical, kSol_PistonHorizontal);

	printf("\nInstantiate TKPince");
	// PinceDrapeau = new TKPince(kSol_Pince);

	printf("\nInstantiate TKGamepad");
	Gamepad = new TKGamepad(0);

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
	printf("\nTeleopInit: brasdrapeau=%p\n", BrasDrapeau);
	//PinceDrapeau->PinceOuvrir();
}

/**
 * Robot Routine: Robot in teleop mode.
 */
void TKRobot::TeleopPeriodic()
{
	DrivingBase->Drive(Gamepad->GetRawAxis(0), Gamepad->GetRawAxis(1));

	// Put arm in grab position
	if(Gamepad->Joystick::GetRawButton(1))
	{
		printf("\nBouton A activated...");
		BrasDrapeau->PositionBrasPrise();
	}


	if(Gamepad->Joystick::GetRawButton(2))
		{

			printf("\nBouton B activated...");
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
	printf("\nTestPeriodic Running...");
	// lw->Run();
}



START_ROBOT_CLASS(TKRobot);
