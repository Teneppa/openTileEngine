// 
// 
// 

#include "tilengine.h"

tilengine::tilengine(dataType getEngineWidth, dataType getEngineHeight, dataType getTileWidth, dataType getTileHeight) {
	
	tilecount = getEngineWidth * getEngineHeight / 16;	// Laske tarvittavan tilan m‰‰r‰
	width = getEngineWidth;						// Tallenna kartan leveys ja korkeus
	height = getEngineHeight;

	mapBuffer = new mapDataType[tilecount];		// Varaa muistia kartalle

}

tilengine::~tilengine() {
	delete[] mapBuffer;			// Vapauta kartan viem‰ muisti
}

/* T‰ll‰ funktiolla voi m‰‰ritt‰‰ tilenginen k‰ytt‰m‰n piirtofunktion palikoille */
void tilengine::assignDrawingFunction(void(*getFunctionPointer)(dataType x, dataType y)) {
	pointToTileDrawingFunction = getFunctionPointer;
}

/* T‰ll‰ funktiolla voi tarkistaa onko kyseisess‰ koordinaatissa palikkaa */
inline bool tilengine::checkTile(dataType getX, dataType getY) {

}

/* T‰ll‰ funktiolla ladataan kartta mapBufferiin */
void tilengine::loadMap(mapDataType *getMap) {
	memcpy(mapBuffer, getMap, sizeof(uint16_t)*width * height / 16);	// Siirr‰ kartta karttapuskuriin
}

/* T‰m‰ funktio piirt‰‰ kartan */
void tilengine::drawMap() {
	for (dataType y = 0; y < height; y++) {
		for (dataType x = 0; x < width; x++) {

			if (((mapBuffer[y] & (1 << x)) >> x)) { // Check if there is a bitmap to draw on this tile
				dataType xpos = dataType((width - 1) * 8 - x * 8); // Get the coordinates for the bitmap
				dataType ypos = dataType(y * 8);
				pointToTileDrawingFunction(xpos, ypos);            // K‰yt‰ funktio-osoitinta piirt‰miseen
			}

		}
	}
}