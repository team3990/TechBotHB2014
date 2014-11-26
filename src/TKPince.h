/*
 * TKPince.h
 *
 *  Created on: 2014-11-22
 *      Author: 11110305
 */

#ifndef TECHBOTHB2014_SRC_TKPINCE_H_
#define TECHBOTHB2014_SRC_TKPINCE_H_

#include <WPIlib.h>

//Port utilisé lors de l'instantiation du Victor


// Valeur maximale de OuverturePresente avant le blocage du moteur
// (Valeur défaut de 0, incrémentée de 20 à chaque itération (de 20 millisecondes) si PinceOuverture est positif, sinon décrémenté de 20)
// 500 est une valeur aléatoire
const int OuvertureMaximalePince = 200;

class TKPince {
public:
	TKPince(int MoteurPinceCanal);
	virtual ~TKPince();

	//Constantes utilisées dans l'application des modifications
	float vitesse = 0.5;

	//Setters
	void PinceOuvrir();
	void PinceFermer();

	//Fonction chargée d'envoyer les informations au moteur
	void Set();

private:
	int PinceOuverture = 0;
	int OuverturePresente = 0;
	Victor* PinceMoteur;

};

#endif /* TECHBOTHB2014_SRC_TKPINCE_H_ */
