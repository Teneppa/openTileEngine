// tilengine.h

#ifndef _TILENGINE_h
#define _TILENGINE_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "variableType.h"

struct tilengine {
	tilengine(dataType getEngineWidth, dataType getEngineHeight, dataType getTileWidth, dataType getTileHeight);
	~tilengine();

	void constructMap(dataType width, dataType height, dataType variableSize);	// M��rittele kartan koko ja tallennusmuoto

	inline bool checkTile(dataType getX, dataType getY);

	dataType width;
	dataType height;
	dataType tileWidth;
	dataType tileheight;

	private:
		dataType mapWidth;
		dataType mapHeight;
		dataType mapVariableSize;

		dataType * map;
};

#endif
