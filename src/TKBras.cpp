/*
 * Bras.cpp
 *
 *  Created on: 2014-11-22
 *      Author: 11110305
 */

#include "TKBras.h"

TKBras::TKBras(int PistonVerticalCanal, int PistonHorizontalCanal) {

	PistonVertical = new Solenoid(PistonVerticalCanal);
	PistonHorizontal = new Solenoid(PistonHorizontalCanal);
	PositionBrasBase();

}

TKBras::~TKBras() {

	delete PistonVertical;
	delete PistonHorizontal;
}

void TKBras::PistonVerticalMonter() {EtatPistonVertical = false; }
void TKBras::PistonVerticalDescendre() {EtatPistonVertical = true; }
void TKBras::PistonHorizontalAvancer() {EtatPistonVertical = true; }
void TKBras::PistonHorizontalReculer() {EtatPistonVertical = false; }

void TKBras::Set()
{
	PistonHorizontal->Set(EtatPistonHorizontal);
	PistonVertical->Set(EtatPistonVertical);
}
void TKBras::PositionBrasBase()
{
	PistonVerticalMonter();
	PistonHorizontalReculer();
}

void TKBras::PositionBrasPrise()
{
	PistonHorizontalAvancer();
	PistonVerticalDescendre();
}

