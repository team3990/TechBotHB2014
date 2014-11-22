/*
 * TKPince.cpp
 *
 *  Created on: 2014-11-22
 *      Author: 11110305
 */

#include "TKPince.h"

TKPince::TKPince()
{
	TKPince::PinceMoteur = new Victor((uint32_t)0);
}

TKPince::~TKPince() {

}

void TKPince::PinceOuvrir()
{
	this->PinceOuverture = 1;
}

void TKPince::PinceFermer()
{
	this->PinceOuverture = -1;
}

void TKPince::Set()
{
	if((this->OuverturePresente > 500) | (this->OuverturePresente < 0))
	{
		PinceMoteur->Set(0.0);

		this->PinceOuverture = this->OuverturePresente = 0;
	}
	this->PinceMoteur->Set(this->vitesse * this->PinceOuverture);
	if (!((!this->PinceOuverture) && (this->OuverturePresente == 0)))
	{
		this->OuverturePresente += this->PinceOuverture * 20;
	}

}
