// sprite.h

#ifndef _SPRITE_h
#define _SPRITE_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

typedef uint8_t dataType;

struct sprite {
	virtual dataType getWidth() = 0;  // N‰it‰ voi k‰ytt‰‰ olion koon pyyt‰miseen
	virtual dataType getHeight() = 0;
	virtual dataType returnBitmap(dataType &bitmap) = 0;
};


#endif

