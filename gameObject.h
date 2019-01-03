// gameObject.h

#ifndef _GAMEOBJECT_h
#define _GAMEOBJECT_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "sprite.h"
#include "variableType.h"

/* gameObject sis‰lt‰‰ kaikki objektit */
struct gameObject : sprite {
	// Julkiset funktiot/muuttujat

	gameObject();
	gameObject(dataType width, dataType height, bitmapDataType * bitmap); // Kun olio luodaan
	~gameObject();  // Kun olio tuhotaan

	dataType getWidth();  // N‰ill‰ voi pyyt‰‰ olion koon
	dataType getHeight();

	bitmapDataType * bitmap;

	dataType x, y;    // Objektin koordinaatit
	dataType width, height;	// Objektin leveys ja korkeus
};

#endif

