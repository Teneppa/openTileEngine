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

/* Tämä luokka on pyhitetty fysiikoiden laskemiseen */
struct physics {
	void calculateGravity(gameObject * object, longDataType time);	// Objekti jolle fysiikat lasketaan, kiihtyvyys
																							// ja kulunut aika edellisestä päivityksestä

	floatDataType gravity = 200.0f;
};

#endif