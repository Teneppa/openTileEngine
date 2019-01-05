// mushroomLevels.h

#ifndef _MUSHROOMLEVELS_h
#define _MUSHROOMLEVELS_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "variableType.h"

const dataType numberOfMushroomLevels = 2;

const uint16_t mushroomMap[8 * numberOfMushroomLevels] = {
	/* Level 1 */
	0b1111111111111111,
	0b1000000000000001,
	0b1100000000000001,
	0b1101000000000001,
	0b1000001000000001,
	0b1000000001000101,
	0b1000000011000001,
	0b1111111111111111,

	/* Level 2 */
	0b1111111111111111,
	0b1000000000000001,
	0b1000000000000001,
	0b1101000000000001,
	0b1000001000000011,
	0b1000000000000001,
	0b1000000011000001,
	0b1111111111111111
};

#endif

