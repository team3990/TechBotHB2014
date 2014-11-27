/**
 * Copyright (c) Équipe Team 3990: Tech for Kids 2014. All Rights Reserved.
 * Open Source Software - may be modified and shared by FRC teams. The code
 * must be accompanied by the FIRST BSD license file.
 * @author 		Olivier Lalonde
 * @abstract	Class for handling operations related to the arm.
 */

#include "TKBras.h"

/**
 * Constructor.
 * @param int PistonVerticalCanal, int PistonHorizontalCanal
 */
TKBras::TKBras(int PistonVerticalCanal, int PistonHorizontalCanal)
{
	descendrecompteur = 0;
	reculercompteur = 0;
	reculer = false;
	descendre = false;
	PistonVertical = new Solenoid(PistonVerticalCanal);
	PistonHorizontal = new Solenoid(PistonHorizontalCanal);
	EtatPistonVertical = false;
	EtatPistonHorizontal = false;
}

/**
 * Destructor.
 */
TKBras::~TKBras() {

	delete PistonVertical;
	delete PistonHorizontal;
}

/**
 * Change state variable used by the handler to set the state of the solenoid.
 * @return void
 */
void TKBras::PistonVerticalMonter()
{
	EtatPistonVertical = false;
}

/**
 * Change state variable used by the handler to set the state of the solenoid.
 * @return void
 */
void TKBras::PistonVerticalDescendre()
{
	EtatPistonVertical = true;
}

/**
 * Change state variable used by the handler to set the state of the solenoid.
 * @return void
 */
void TKBras::PistonHorizontalAvancer()
{
	EtatPistonHorizontal = true;
}

/**
 * Change state variable used by the handler to set the state of the solenoid.
 * @return void
 */
void TKBras::PistonHorizontalReculer()
{
	EtatPistonHorizontal = false;
}

/**
 * Handler method. Sets the state of the solenoid according to the state of the state variables.
 * @return void
 */
void TKBras::Set()
{
	if(reculer == true) 	reculercompteur++;
	if(descendre == true) 	descendrecompteur++;
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
	// if(!(PistonVertical->Get()&&!PistonHorizontal)) {PistonHorizontal->Set(EtatPistonHorizontal);}
	// if(!(!EtatPistonHorizontal&&PistonVertical)) {PistonVertical->Set(EtatPistonVertical);}

	PistonHorizontal->Set(EtatPistonHorizontal);
	PistonVertical->Set(EtatPistonVertical);

}

/**
 * Bring the arm to its home position, that is, retract the arm inside the robot.
 * @return void
 */
void TKBras::PositionBrasBase()
{
	PistonVerticalMonter();
	reculer = true;
}

/**
 * Bring the arm to grab position, that is, extend the arm outside the robot.
 * @return void
 */
void TKBras::PositionBrasPrise()
{
	PistonHorizontalAvancer();
	descendre = true;
}
