/**
 * Copyright (c) Équipe Team 3990: Tech for Kids 2014. All Rights Reserved.
 * Open Source Software - may be modified and shared by FRC teams. The code
 * must be accompanied by the FIRST BSD license file.
 * @author 		Olivier Lalonde
 * @abstract	Class for handling operations related to the arm.
 */

#ifndef SRC_BRAS_H_
#define SRC_BRAS_H_
#include "WPIlib.h"
#include <iostream>

/**
 * TKRobot subsystem: arm mechanism
 */
class TKBras {
	public:
		// Constructors & destructors
		TKBras(int PistonVerticalCanal, int PistonHorizontalCanal);
		virtual ~TKBras();

		// Setters de variables pour modifier les emplacements des pistons
		void 		PistonVerticalMonter();
		void 		PistonVerticalDescendre();
		void 		PistonHorizontalAvancer();
		void 		PistonHorizontalReculer();

		int 		descendrecompteur;
		int 		reculercompteur;
		bool 		descendre;
		bool 		reculer;

		void 		Set();
		void 		PositionBrasBase();
		void 		PositionBrasPrise();

	private:
		// Solenoids
		Solenoid 	* PistonVertical;
		Solenoid 	* PistonHorizontal;

		// Utilisés par la fonction Set
		bool 		EtatPistonVertical, EtatPistonHorizontal;
};

#endif /* SRC_BRAS_H_ */
