// physics.h

#ifndef _PHYSICS_h
#define _PHYSICS_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "variableType.h"

/* Tämä luokka on pyhitetty fysiikoiden laskemiseen */
struct physics {
	void calculateGravity(dataType &ySpeed, dataType acceleration);

};

#endif

