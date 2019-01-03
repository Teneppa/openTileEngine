// 
// 
// 

#include "tilengine.h"

tilengine::tilengine(dataType getEngineWidth, dataType getEngineHeight, dataType getTileWidth, dataType getTileHeight) {

}

tilengine::~tilengine() {

}

void tilengine::assignDrawingFunction(void(*getFunctionPointer)(dataType x, dataType y)) {
	pointToTileDrawingFunction = getFunctionPointer;
}

/* T‰ll‰ funktiolla voi tarkistaa onko kyseisess‰ koordinaatissa palikkaa */
inline bool tilengine::checkTile(dataType getX, dataType getY) {

}

void tilengine::loadMap(dataType * getMap) {
	map = getMap;
}

/* T‰m‰ funktio piirt‰‰ kartan */
void tilengine::drawMap() {
	for (dataType y = 0; y < height; y++) {
		for (dataType x = 0; x < width; x++) {

			if (((map[y] & (1 << x)) >> x)) { // Check if there is a bitmap to draw on this tile
				dataType xpos = dataType((width - 1) * 8 - x * 8); // Get the coordinates for the bitmap
				dataType ypos = dataType(y * 8);
				pointToTileDrawingFunction(xpos, ypos);            // K‰yt‰ funktio-osoitinta piirt‰miseen
			}

		}
	}
}