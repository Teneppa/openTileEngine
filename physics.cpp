// 
// 
// 

#include "physics.h"

void physics::assignEnginePointer(tilengine * enginePointer) {
	m_localEnginePointer = enginePointer;
}

/* Laske painovoiman vaikutus pikseli kerrallaan */
void physics::calculateGravity(gameObject * object, longDataType time) {
	floatDataType timeInSeconds = time / 1000.0f;

	object->y += object->vSpeed * timeInSeconds;		// Muuta objektin sijaintia

	if (m_localEnginePointer->COLLISION_BELOW(object)) {		// Jos pelaaja meni maan sis‰‰n

		object->vSpeed = object->vSpeed * 0.6;		// 0.6 on kerroin nopeuden hidastumiselle, jos pelaaja
													// joutuu maan sis‰lle.

		object->y -= object->vSpeed * timeInSeconds;	// Siirr‰ pelaajaa hieman takaisin

	}

	object->vSpeed += gravity * timeInSeconds;	// Lis‰‰ kiihtyvyys y-akselin suuntaiseen nopeuteen
}

void physics::calculateAccelerations(gameObject * object, longDataType time) {
	floatDataType timeInSeconds = time / 1000.0f;

	/*
	// Laske liikkuminen vaakatasossa
	object->x += object->hSpeed * timeInSeconds;		// Muuta objektin sijaintia

	if (m_localEnginePointer->COLLISION_LEFT (object) || m_localEnginePointer->COLLISION_RIGHT(object)) {		// Jos pelaaja meni maan sis‰‰n

		object->hSpeed = object->hSpeed * 0.6;		// 0.6 on kerroin nopeuden hidastumiselle, jos pelaaja
													// joutuu sein‰n sis‰‰n

		object->x -= object->hSpeed * timeInSeconds;	// Siirr‰ pelaajaa hieman takaisin

	}

	if (object->hSpeed > 0) {
		object->hSpeed -= hAccel * timeInSeconds;	// Lis‰‰ kiihtyvyys y-akselin suuntaiseen nopeuteen
	}
	if (object->hSpeed < 0) {
		object->hSpeed += hAccel * timeInSeconds;	// Lis‰‰ kiihtyvyys y-akselin suuntaiseen nopeuteen
	}

	// Laske liikkuminen pystysuunnassa
	object->y += object->vSpeed * timeInSeconds;	// Muuta objektin sijaintia pystysuunnassa

	if (m_localEnginePointer->COLLISION_ABOVE(object) || m_localEnginePointer->COLLISION_BELOW(object))	{

		object->vSpeed = object->vSpeed * 0;		// 0.6 on kerroin nopeuden hidastumiselle, jos pelaaja
													// joutuu sein‰n sis‰‰n

		object->y -= object->vSpeed * timeInSeconds;	// Siirr‰ pelaajaa hieman takaisin

	}

	if (object->vSpeed > 0) {
		object->vSpeed -= vAccel * timeInSeconds;	// Lis‰‰ kiihtyvyys y-akselin suuntaiseen nopeuteen
	}
	if (object->vSpeed < 0) {
		object->vSpeed += vAccel * timeInSeconds;	// Lis‰‰ kiihtyvyys y-akselin suuntaiseen nopeuteen
	}
	*/
}