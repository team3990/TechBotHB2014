/*
 * TKPince.h
 *
 *  Created on: 2014-11-22
 *      Author: 11110305
 */

#ifndef SRC_TKPINCE_H_
#define SRC_TKPINCE_H_

#include <wpilib.h>

class TKPince {
public:
	TKPince();
	virtual ~TKPince();

	//Constantes utilisées dans l'application des modifications
	int PinceOuverture = 0;
	int OuverturePresente = 0;
	float vitesse = 0.5;

	Victor* PinceMoteur;

	//Setters
	void PinceOuvrir();
	void PinceFermer();

	//Fonction chargée d'envoyer les informations au moteur
	void Set();


};

#endif /* SRC_TKPINCE_H_ */
