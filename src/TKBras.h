/*
 * Bras.h
 *
 *  Created on: 2014-11-22
 *      Author: 11110305
 */

#ifndef SRC_BRAS_H_
#define SRC_BRAS_H_
#include "WPIlib.h"


class TKBras {
	public:
		TKBras(int PistonVerticalCanal, int PistonHorizontalCanal);
		virtual ~TKBras();

		// Setters de variables pour modifier les emplacements des pistons
		void PistonVerticalMonter();
		void PistonVerticalDescendre();
		void PistonHorizontalAvancer();
		void PistonHorizontalReculer();

		void Set();
		void PositionBrasBase();
		void PositionBrasPrise();

	private:
		Solenoid * PistonVertical;
		Solenoid * PistonHorizontal;

		// Utilisés par la fonction Set
		bool EtatPistonVertical, EtatPistonHorizontal;
};

#endif /* SRC_BRAS_H_ */
