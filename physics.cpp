// 
// 
// 

#include "physics.h"

/* Laske painovoiman vaikutus */
void physics::calculateGravity(gameObject * object, dataType acceleration, longDataType time) {
	object->y += object->vSpeed * time;		// Muuta objektin sijaintia
	object->vSpeed += acceleration * time;	// Lis‰‰ kiihtyvyys y-akselin suuntaiseen nopeuteen
}
