// 
// 
// 

#include "physics.h"

/* Laske painovoiman vaikutus */
void physics::calculateGravity(dataType &ySpeed, dataType acceleration) {
	ySpeed += acceleration;	// Lis‰‰ kiihtyvyys y-akselin suuntaiseen nopeuteen
}
