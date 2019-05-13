// inputOutput.h

#ifndef _INPUTOUTPUT_h
#define _INPUTOUTPUT_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "variableType.h"

/* All of the keys defined */

#define PIN_KEY_UP			PD4
#define PIN_KEY_RIGHT		PD5
#define PIN_KEY_DOWN		A3
#define PIN_KEY_LEFT		A2

#define PIN_KEY_Y			PD3
#define PIN_KEY_B			PD0
#define PIN_KEY_A			PD1
#define PIN_KEY_X			PD2

#define PIN_LDR				A6

#define PIN_NRF_CSN			A0
#define PIN_NRF_CE			D10

#define PIN_SPI_CS			PD7
#define PIN_SPI_DC			PD6
#define PIN_SPI_RES			D8

struct inputOutput {

	static const dataType keyAmount = 3;

	/* Napeille järkevät nimet */
	enum key {
		KEY_LEFT,
		KEY_RIGHT,
		KEY_JUMP
	};

	void begin();

	/* Tallenna digitaaliset pinnit napeille */
	//const dataType keyList[keyAmount] = {3, 4, A2};	// Prototyyppi
	//const dataType keyList[keyAmount] = { A7, A1, PD2 };	// PCB versio 1
	const dataType keyList[keyAmount] = { A2, PD5, PD2 };	// PCB versio 2

	bool returnKey(dataType nKey);
};

#endif

