/**
 * Copyright (c) Équipe Team 3990: Tech for Kids 2014. All Rights Reserved.
 * Open Source Software - may be modified and shared by FRC teams. The code
 * must be accompanied by the FIRST BSD license file.
 * @author 		Olivier Lalonde
 * @abstract	Class for handling operations related to the claw.
 */

#ifndef TECHBOTHB2014_SRC_TKPINCE_H_
#define TECHBOTHB2014_SRC_TKPINCE_H_

#include "WPILib.h"
#include "TKConfig.h"

class TKPince {

public:
	// Constructor & destructor
				TKPince(int pwmChannel);
	virtual 	~TKPince();

	// Mutators
	void 		Open();
	void 		Close();

	// Accessors
	bool		isOpened();

	// Handler
	void 		Run();

private:
	// Variables
	float 		vitesse_;
	int 		pinceOuverture_;
	int 		ouverturePresente_;

	// Components
	Victor 		* pinceMoteur;

};

#endif /* TECHBOTHB2014_SRC_TKPINCE_H_ */
