#pragma once

#ifndef _LEVELS_h
#define _LEVELS_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

uint16_t mushMap[8] = {
	0b1111111111111111,
	0b1000000000000001,
	0b1000000000000001,
	0b1000000000000001,
	0b1000000000000001,
	0b1000000001000101,
	0b1000000011000001,
	0b1111111111111111
};

#endif