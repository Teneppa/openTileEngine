// inputOutput.h

#ifndef _INPUTOUTPUT_h
#define _INPUTOUTPUT_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "variableType.h"

struct inputOutput {

	static const dataType keyAmount = 3;

	/* Napeille järkevät nimet */
	enum key {
		KEY_LEFT,
		KEY_RIGHT,
		KEY_JUMP
	};

	/* Tallenna digitaaliset pinnit napeille */
	const dataType keyList[keyAmount] = {2, 3, 4};

	bool returnKey(dataType nKey);
};

#endif

