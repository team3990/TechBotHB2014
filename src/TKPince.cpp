/*
 * TKPince.cpp
 *
 *  Created on: 2014-11-22
 *      Author: 11110305
 */

#include "TKPince.h"


TKPince::TKPince(int MoteurPinceCanal) {
	PinceMoteur = new Victor((uint32_t)MoteurPinceCanal);
}
TKPince::~TKPince() {
	delete PinceMoteur;
}

void TKPince::PinceOuvrir() {PinceOuverture = 1;}
void TKPince::PinceFermer() {PinceOuverture = -1;}

void TKPince::Set()
{
	// Si la pince a atteint son ouverture maximale et que la vitesse doit augmenter ou qu'elle a atteint son ouverture minimale et que la vitesse doit diminuer:
	// Définir PinceOuverture comme nul.
	if(((OuverturePresente > OuvertureMaximalePince) && (PinceOuverture == 1)) ||
			((OuverturePresente < 0) && (PinceOuverture == -1)))
	{
		PinceOuverture = 0;
	}

	// Si la condition précédente a été remplie, ces opérations seront forcément nulles.
	PinceMoteur->Set(vitesse * PinceOuverture);
	OuverturePresente += PinceOuverture * 20;
}
