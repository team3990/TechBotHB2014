/**
 * Copyright (c) Équipe Team 3990: Tech for Kids 2014. All Rights Reserved.
 * Open Source Software - may be modified and shared by FRC teams. The code
 * must be accompanied by the FIRST BSD license file.
 * @author 		Esther Guerrier
 * @abstract	Configuration file with constants and other global parameters.
 */

#ifndef TECHBOTHB2014_SRC_TKCONFIG_H_
#define TECHBOTHB2014_SRC_TKCONFIG_H_

/**
* Digital I/O
 */

/**
 * Analog Inputs
 */

/**
 * Solenoids & pneumatics
 */
const int kSol_PistonHorizontal		= 6;
const int kSol_PistonVertical		= 4;
const int kSol_Shifter				= 5;

/**
 * PWM
 */
const int kPWM_Pince				= 0;
const int kPWM_MotorLeft			= 1;
const int kPWM_MotorRight			= 2;

/**
 * USB
 */
const int kUSB_GamePadLeft			= 0;
const int kUSB_GamePadRight			= 1;

/**
 * Other Constants
 */
const int kRobotLenght 				= 37;
/**
 * Valeur maximale de OuverturePresente avant le blocage du moteur
 * (Valeur défaut de 0, incrémentée de 20 à chaque itération (de 20 millisecondes)
 * si PinceOuverture est positif, sinon décrémenté de 20).
 * 500 est une valeur aléatoire.
 */
const int kOuvertureMaximalePince 	= 300;

#endif /* TECHBOTHB2014_SRC_TKCONFIG_H_ */
