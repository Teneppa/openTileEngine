// 
// 
// 

#include "physics.h"

/* Laske painovoiman vaikutus */
void physics::calculateGravity(gameObject * object, longDataType time) {

	floatDataType timeInSeconds = time / 1000.0f;

	object->y += object->vSpeed * timeInSeconds;		// Muuta objektin sijaintia
	object->vSpeed += gravity * timeInSeconds;	// Lisää kiihtyvyys y-akselin suuntaiseen nopeuteen

	/* DEBUG */

	/*
	Serial.println("vSpeed = " + String(object->vSpeed));
	Serial.println("Gravity = " + String(gravity));
	Serial.println("Time = " + String(timeInSeconds));
	*/

	Serial.println();
}
