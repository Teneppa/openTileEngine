// 
// 
// 

#include "physics.h"

/* Laske painovoiman vaikutus */
void physics::calculateGravity(gameObject * object, dataType acceleration) {
	object->vSpeed += acceleration;	// Lis‰‰ kiihtyvyys y-akselin suuntaiseen nopeuteen
}
