// 
// 
// 

#include "mushroomGame.h"
#include "variableType.h"

/*-- Kun pelist� luodaan olio --*/
mushroomGame::mushroomGame(tilengine * engine) {
	player.x = 9;	// Aseta pelaajan koordinaateiksi (8,8)
	player.y = 46;

	localEngine = engine;
}

/*-- Kun peli k�ynnistet��n --*/
void mushroomGame::initialize(dataType width, dataType height) {
	player.width = width;		// M��rit� pelaajan leveys ja korkeus
	player.height = height;
	io.begin();					// Aseta pinnien tilat

	key.x = 8;		// M��rit� 'avaimen' koordinaati ja koko
	key.y = 8;
	key.width = 8;
	key.height = 8;

	currentLevel = 0;	// Nollaa t�m�nhetkinen taso

	loadLevel(currentLevel);	// Lataa t�m�nhetkinen taso
}

/*--  --*/
void mushroomGame::assignBitmapDrawingFunction(void(*getFunctionPointer)(dataType x, dataType y, bitmapDataType * bitmap, dataType width, dataType height)) {
	pointToBitmapDrawingFunction = getFunctionPointer;
}

/*-- Lataa haluttu taso --*/
void mushroomGame::loadLevel(dataType levelToLoad) {
	if (levelToLoad >= 0 && levelToLoad < numberOfMushroomLevels) {

		player.x = 9;
		player.y = 46;
		
		const mapDataType * pointerToStartOfTheMap = &mushroomMap[levelToLoad*8];
		loadMap(pointerToStartOfTheMap);
		
	}
}

/*-- Pelin p��funktio --*/
void mushroomGame::run() {

	/* P�ivit� pelifunktiota n. 62,5 kertaa sekunnissa */
	if (millis() - oldMushroomUpdateTime > 8) {
		draw();	// Piirr� kartta ja pelaaja

		/* Jos pelaaja osuu avaimeen */
		if (key.collidesWithGameobject(&player)) {
			Serial.println(F("Player got the key!"));
			currentLevel += 1;
			loadLevel(currentLevel);
		}

		/* Tarkista onko pelaaja ilmassa vai maassa */
		if (!localEngine->COLLISION_BELOW(&player)) {
			//playerPhysics.calculateGravity(&player, millis() - oldUpdateTime);		// Laske painovoima pelaajalle
			playerPhysics.calculateGravity(localEngine, &player, millis() - oldUpdateTime);		// Laske painovoima pelaajalle
		} else {
			if (io.returnKey(io.KEY_JUMP)) {	// Jos hyppynappia painetaan
				player.vSpeed = -80.0f;
				player.y -= 1;	// Nosta pelaajaa yhdell� pikselill� jotta tilengine ei luule ett� pelaaja olisi jo maassa
			}
		}

		/* Jos pelaaja liikkuu vasemmalle */
		if (!localEngine->COLLISION_LEFT(&player)) {
			if (io.returnKey(io.KEY_LEFT)) {
				player.x -= 1;

				/* Jos pelaaja meni sein�n sis��n, siirr� pelaaja pois sielt� */
				if (localEngine->COLLISION_LEFT(&player)) {
					player.x += 1;
				}
			}
		}

		/* Jos pelaaja liikkuu oikealle */
		if (!localEngine->COLLISION_RIGHT(&player)) {
			if (io.returnKey(io.KEY_RIGHT)) {
				player.x += 1;

				/* Jos pelaaja meni sein�n sis��n, siirr� pelaaja pois sielt� */
				if (localEngine->COLLISION_RIGHT(&player)) {
					player.x -= 1;
				}

			}
		}

		/* Jos pelaaja t�rm�� yll� olevaan palikkaan */
		if (localEngine->COLLISION_ABOVE(&player)) {
			player.vSpeed = abs(player.vSpeed)/2;
		}

		/* DEBUG */

		/*
		Serial.println("T�rm�ys vasemmalle: " + String(localEngine->COLLISION_LEFT));
		Serial.println("T�rm�ys oikealle: " + String(localEngine->COLLISION_RIGHT));
		Serial.println("T�rm�ys alla: " + String(localEngine->COLLISION_BELOW));

		Serial.println();
		*/

		oldUpdateTime = millis();
	}
	
}

/*--  --*/
void mushroomGame::draw() {
	localEngine->drawMap();	// Piirr� kartta
	pointToBitmapDrawingFunction(player.x, player.y, bitmap_mushroom, player.width, player.height);	// Piirr� pelaaja
	pointToBitmapDrawingFunction(key.x, key.y, coin1, key.width, key.height);
}

/*--  --*/
void mushroomGame::loadMap(mapDataType * m) {
	localEngine->loadMap(m);
}

/*--  --*/
void mushroomGame::loadMap(const mapDataType * m) {
	localEngine->loadMap(m);
}