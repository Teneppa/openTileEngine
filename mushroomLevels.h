// mushroomLevels.h

#ifndef _MUSHROOMLEVELS_h
#define _MUSHROOMLEVELS_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "variableType.h"
#include "gameObject.h"

const dataType numberOfMushroomObjects = 2;
const dataType numberOfMushroomObjectVariables = 5;

const dataType numberOfMushroomLevels = 5;

/*
gameObject levelObjects[4 * numberOfMushroomLevels];

void initializeLevelVariables() {
	levelObjects[0].x = 8;
	levelObjects[0].y = 8;
	levelObjects[0].width = 8;
	levelObjects[0].height = 8;
}
*/

const uint16_t mushroomObjects[numberOfMushroomObjects * numberOfMushroomObjectVariables * 5] = {
	// x(ruutua),y(ruutua),width,height,bitmap id

	/* Level 1 */
	4,6,8,8,1,
	10,6,8,8,1,

	/* Level 2 */
	11,6,8,8,1,
	10,6,8,8,1,

	/* Level 3 */
	6,6,8,8,1,
	10,6,8,8,1,

	/* Level 4 */
	8,6,8,8,1,
	10,6,8,8,1,

	/* Level 5 */
	4,6,8,8,1,
	10,6,8,8,1
};

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
	0b1111111111111111,

	/* Level 3 */
	0b1111111111111111,
	0b1000000000000001,
	0b1000000100000001,
	0b1101100010010001,
	0b1000000000000001,
	0b1000000000001001,
	0b1000000001000001,
	0b1111111111111111,

	/* Level 4 */
	0b1111111111111111,
	0b1000000000000001,
	0b1110000001001101,
	0b1001000100000001,
	0b1000010000100001,
	0b1000000000001001,
	0b1000000001000001,
	0b1111111111111111,

	/* Level 5 */
	0b1111111111111111,
	0b1000000000000001,
	0b1110100001000001,
	0b1000010100100101,
	0b1000000000001001,
	0b1000001001000001,
	0b1000011100000001,
	0b1111111111111111
};

#endif

