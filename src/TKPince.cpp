/**
 * Copyright (c) Équipe Team 3990: Tech for Kids 2014. All Rights Reserved.
 * Open Source Software - may be modified and shared by FRC teams. The code
 * must be accompanied by the FIRST BSD license file.
 * @author 		Olivier Lalonde
 * @abstract	Class for handling operations related to the claw.
 */

#include "TKPince.h"

/**
 * Constructor.
 * @param int pwmChannel
 */
TKPince::TKPince(int pwmChannel) {
	vitesse_ 			= 1.0;
	pinceOuverture_ 	= 0;
	ouverturePresente_ 	= 0;
	pinceMoteur 		= new Victor(pwmChannel);
}

/**
 * Destructor.
 */
TKPince::~TKPince() {
	delete pinceMoteur;
}

/**
 * Mutator to set the variable state to open. The handler will set the claw according to the variable state.
 * @return void
 */
void TKPince::Open()
{
	pinceOuverture_ = 1;
	printf("#nOpen() pinceOuverture_: %d", pinceOuverture_);
}

/**
 * Mutator to set the variable state to close. The handler will set the claw according to the variable state.
 * @return void
 */
void TKPince::Close()
{
	pinceOuverture_ = -1;
	printf("\nClose() pinceOuverture_: %d", pinceOuverture_);
}

/**
 * Handler method. Sets the state of the claw according to the state of the state variables
 * @return void
 */
void TKPince::Run()
{
	// Si la pince a atteint son ouverture maximale et que la vitesse doit augmenter ou qu'elle a atteint son ouverture minimale et que la vitesse doit diminuer:
	// Définir pinceOuverture_ comme nul.
	if(((ouverturePresente_ > kOuvertureMaximalePince) && (pinceOuverture_ == 1)) ||
			((ouverturePresente_ < 0) && (pinceOuverture_ == -1)))
	{
		pinceOuverture_ = 0;
	}

	// Si la condition précédente a été remplie, ces opérations seront forcément nulles.
	pinceMoteur->Set(vitesse_ * pinceOuverture_);
	ouverturePresente_ += pinceOuverture_ * 20;

	printf("\nVitesse * pinceOuverture_ : %.2f", (vitesse_ * pinceOuverture_));
	printf("\nouverturePresente_ : %d", ouverturePresente_);
}


/**
 * Accessor to get the state of the claw. Since the claw is contolled by a motor, the float value of the
 * motor speed has to be converted to a true/false value.
 */
bool TKPince::isOpened()
{
	bool isOpened;

	if (pinceMoteur->Get() > 0) 	// 0 to 1: claw is opened
	{
		isOpened = true;
	}
	else
	{
		isOpened = false;			// -1 to 0: claw is closed
	}

	return isOpened;
}
