/*
 * TKConfig.h
 *
 *  Created on: 2014-11-22
 *      Author: Administrateur
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
const int kSol_Pince(0);
const int kSol_PistonHorizontal(6);
const int kSol_PistonVertical(4);
const int kSol_Shifter(5);					// DrivingBase.h

/**
 * PWM
 */
const int kPWM_MotorLeft(1);				// DrivingBase.h
const int kPWM_MotorRight(2);				// DrivingBase.h

/**
 * Other Constants
 */
const int kRobotLenght(37);




#endif /* TECHBOTHB2014_SRC_TKCONFIG_H_ */
