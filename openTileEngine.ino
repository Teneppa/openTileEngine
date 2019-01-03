/*
    Name:       openTileEngine.ino
    Created:	3.1.2019 12.03.58
    Author:     Teemu Laurila
*/

/*--  --*/

#include "mushroomGame.h"
#include "gameEvent.h"
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#include "variableType.h"
#include "tilengine.h"
#include "gameObject.h"

/*-- Määritä pinnit OLED-näytölle --*/

const uint8_t OLED_DC = 6;
const uint8_t OLED_CS = 7;
const uint8_t OLED_RESET = 8;

Adafruit_SSD1306 oled(OLED_DC, OLED_RESET, OLED_CS);

/*-- Asetukset OLED-näytölle --*/

void beginDisplay() {
	oled.begin(SSD1306_SWITCHCAPVCC);	// Käytä sisäistä jännitegeneraattoria
	oled.setRotation(2);				// Pyöräytä kuvaa 180 astetta
}

tilengine engine(16, 8, 8, 8);	// tilengine(kartan leveys, kartan korkeus,
								//			 laata leveys, laatan korkeus);

#include "mushroomGame.h"
#include "bitmaps.h"
#include "levels.h"

mushroomGame mGame(&engine);	// Anna pelille tile-enginen muistiosoite, jotta se voi käyttää sitä

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

	beginDisplay();			// Määritä OLED -juttuja

	engine.assignDrawingFunction(drawTile);		// Määritä piirtofunktio

	mGame.initialize(8, 8, bitmap_mushroom);	// Player width, height and bitmap
	mGame.loadMap(mushMap);					// Load map
}

void loop() {
	oled.clearDisplay();	// Tyhjennä puskuri

	mGame.draw();			// Piirrä peliä

	oled.display();			// Siirrä puskuri näytölle
}