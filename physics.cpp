// 
// 
// 

#include "physics.h"

/* Laske painovoiman vaikutus */
void physics::calculateGravity(gameObject * object, longDataType time) {

	floatDataType timeInSeconds = time / 1000.0f;

	object->y += object->vSpeed * timeInSeconds;		// Muuta objektin sijaintia

	object->vSpeed += gravity * timeInSeconds;	// Lis‰‰ kiihtyvyys y-akselin suuntaiseen nopeuteen

	/* DEBUG */

	/*
	Serial.println("vSpeed = " + String(object->vSpeed));
	Serial.println("Gravity = " + String(gravity));
	Serial.println("Time = " + String(timeInSeconds));

	Serial.println();
	*/
}

/* Laske painovoiman vaikutus pikseli kerrallaan */
void physics::calculateGravity(tilengine * enginePointer, gameObject * object, longDataType time) {
	floatDataType timeInSeconds = time / 1000.0f;

	object->y += object->vSpeed * timeInSeconds;		// Muuta objektin sijaintia
	if (enginePointer->COLLISION_BELOW(object)) {		// Jos pelaaja meni maan sis‰‰n nosta pelaajaa yhdell‰ pikselill‰
		object->y -= 1;
	}

	object->vSpeed += gravity * timeInSeconds;	// Lis‰‰ kiihtyvyys y-akselin suuntaiseen nopeuteen
}