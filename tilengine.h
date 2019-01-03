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
	~tilengine();	// Poista karttapuskuri kun t‰t‰ ei en‰‰ tarvita

	mapDataType * mapBuffer;       // Puskuri kartalle

	void assignDrawingFunction(void(*getFunctionPointer)(dataType x, dataType y));
	void loadMap(mapDataType * getMap);	// M‰‰rittele kartan koko ja tallennusmuoto

	void(*pointToTileDrawingFunction)(dataType, dataType);	// Hae osoitin piirtofunktioon

	inline bool checkTile(dataType getX, dataType getY);

	void drawMap();

	dataType width;
	dataType height;
	dataType tileWidth;
	dataType tileheight;
	dataType tilecount;

	private:
		dataType mapWidth;
		dataType mapHeight;
		dataType mapVariableSize;
};

#endif

