// physics.h

#ifndef _PHYSICS_h
#define _PHYSICS_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "variableType.h"
#include "gameObject.h"

/* T�m� luokka on pyhitetty fysiikoiden laskemiseen */
struct physics {
	void calculateGravity(gameObject * object, longDataType time);	// Objekti jolle fysiikat lasketaan, kiihtyvyys
																							// ja kulunut aika edellisest� p�ivityksest�

	floatDataType gravity = 80.0f;
};

#endif