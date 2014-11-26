/*
 * Bras.cpp
 *
 *  Created on: 2014-11-22
 *      Author: 11110305
 */

#include "TKBras.h"

TKBras::TKBras(int PistonVerticalCanal, int PistonHorizontalCanal)
{
	PistonVertical = new Solenoid(PistonVerticalCanal);
	PistonHorizontal = new Solenoid(PistonHorizontalCanal);
	descendrecompteur = 0;
	reculercompteur = 0;
	reculer = false;
	descendre = false;
	//PositionBrasBase();
}

TKBras::~TKBras() {

	delete PistonVertical;
	delete PistonHorizontal;
}

void TKBras::PistonVerticalMonter() {EtatPistonVertical = false; }
void TKBras::PistonVerticalDescendre() {EtatPistonVertical = true; }
void TKBras::PistonHorizontalAvancer() {EtatPistonHorizontal = true; }
void TKBras::PistonHorizontalReculer() {EtatPistonHorizontal = false; }

void TKBras::Set()
{

	if(reculer == true) {reculercompteur++;}
	if(descendre == true) {descendrecompteur++; }
	std::cout << "\nReculer compteur: " << reculercompteur;
	std::cout << "\nDescendre compteur: " << descendrecompteur;

	if(reculercompteur == 20)
	{
		PistonHorizontalReculer();
		reculercompteur = 0;
		reculer = false;
	}
	if(descendrecompteur == 20)
	{
		PistonVerticalDescendre();
		std::cout << "Descendre piston vertical";
		descendrecompteur = 0;
		descendre = false;
	}

	if (EtatPistonHorizontal|!EtatPistonVertical)
	{
		std::cout << "\nPiston horizontal: " << EtatPistonHorizontal << "\n";
		std::cout << "Piston vertical: " << EtatPistonVertical << "\n";
	}

	// Mesures de sécurité
	// Si le piston vertical est activé et que le piston horizontal doit être fermé
	// Ou que le piston horizontal est désactivé et que le piston vertical doit être ouvert
	// Bloquer l'opération!
	if(!(PistonVertical->Get()&!PistonHorizontal)) {PistonHorizontal->Set(EtatPistonHorizontal);}
	if(!(!EtatPistonHorizontal&PistonVertical)) {PistonVertical->Set(EtatPistonVertical);}

}
void TKBras::PositionBrasBase()
{
	PistonVerticalMonter();
	reculer = true;


}

void TKBras::PositionBrasPrise()
{
	PistonHorizontalAvancer();
	descendre = true;
}

