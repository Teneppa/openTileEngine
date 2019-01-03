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

/*-- M‰‰rit‰ pinnit OLED-n‰ytˆlle --*/

const uint8_t OLED_DC = 6;
const uint8_t OLED_CS = 7;
const uint8_t OLED_RESET = 8;

Adafruit_SSD1306 oled(OLED_DC, OLED_RESET, OLED_CS);

/*-- Asetukset OLED-n‰ytˆlle --*/

void beginDisplay() {
	oled.begin(SSD1306_SWITCHCAPVCC);	// K‰yt‰ sis‰ist‰ j‰nnitegeneraattoria
	oled.setRotation(2);				// Pyˆr‰yt‰ kuvaa 180 astetta
}

tilengine engine(16, 8, 8, 8);	// tilengine(kartan leveys, kartan korkeus,
								//			 laata leveys, laatan korkeus);

#include "mushroomGame.h"
#include "bitmaps.h"
#include "levels.h"

mushroomGame mGame(&engine);	// Anna pelille tile-enginen muistiosoite, jotta se voi k‰ytt‰‰ sit‰

/* Piirtofunktio palikalle */
void drawTile(dataType x, dataType y) {
	oled.drawBitmap(x, y, bitmap_block, 8, 8, 1);
}

/* Piirtofunktio pelaajalle */
void drawPlayer(dataType x, dataType y) {
	oled.drawBitmap(x, y, bitmap_mushroom, 8, 8, 1);
}

#define USE_DEBUGGING
//#undef USE_DEBUGGING

void setup() {

#ifdef USE_DEBUGGING
	Serial.begin(115200);
	Serial.println(">Starting up...");
#endif

	beginDisplay();			// M‰‰rit‰ OLED -juttuja

	engine.assignDrawingFunction(drawTile);		// M‰‰rit‰ piirtofunktio palikoille
	mGame.assignDrawingFunction(drawPlayer);	// M‰‰rit‰ piirtofunktio pelaajalle

	mGame.initialize(8, 8);	// Player width and height
	mGame.loadMap(mushMap);	// Lataa kartta muistiin
}

void loop() {
	oled.clearDisplay();	// Tyhjenn‰ puskuri

	mGame.draw();			// Piirr‰ peli‰

	oled.display();			// Siirr‰ puskuri n‰ytˆlle
}