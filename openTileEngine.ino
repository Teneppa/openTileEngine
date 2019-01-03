/*
    Name:       openTileEngine.ino
    Created:	3.1.2019 12.03.58
    Author:     Teemu Laurila
*/

#include "mushroomGame.h"
#include "gameEvent.h"
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#include "variableType.h"
#include "tilengine.h"
#include "gameObject.h"

/*<<//>>\\<<//>>\\<<//>>\\<<//>>\\<<//==- Oled things -==\\<<//>>\\<<//>>\\<<//>>\\<<//>>*/

const uint8_t OLED_DC = 6;
const uint8_t OLED_CS = 7;
const uint8_t OLED_RESET = 8;

Adafruit_SSD1306 oled(OLED_DC, OLED_RESET, OLED_CS);

void beginDisplay() {
	oled.begin(SSD1306_SWITCHCAPVCC); //use internal voltage generator
	oled.setRotation(2); //set rotation to 2
}

/*<<//>>\\<<//>>\\<<//>>\\<<//>>\\<<//>>\\<<//>>\\<<//>>\\<<//>>\\<<//>>\\<<//>>\\<<//>>*/

tilengine engine(16, 8, 8, 8);	// tilengine(kartan leveys, kartan korkeus,
								//			 laata leveys, laatan korkeus);

#include "mushroomGame.h"
#include "bitmaps.h"
#include "levels.h"

mushroomGame mGame(&engine);

/* Piirtofunktio palikalle */
void drawTile(dataType x, dataType y) {
	oled.drawBitmap(x, y, bitmap_block, 8, 8, 1);
}

#define USE_DEBUGGING
//#undef USE_DEBUGGING

void setup() {

#ifdef USE_DEBUGGING
	Serial.begin(115200);
	Serial.println(">Starting up...");
#endif

	beginDisplay();			// M‰‰rit‰ OLED

	engine.assignDrawingFunction(drawTile);		// M‰‰rit‰ piirtofunktio

	mGame.initialize(8, 8, bitmap_mushroom);	// Player width, height and bitmap
	mGame.loadMap(mushMap);					// Load map
}

void loop() {
	oled.clearDisplay();

	mGame.draw();		// Draw

	oled.display();
}