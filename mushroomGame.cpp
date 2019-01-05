// 
// 
// 

#include "mushroomGame.h"
#include "variableType.h"

/*-- Kun pelistä luodaan olio --*/
mushroomGame::mushroomGame(tilengine * engine) {
	player.x = 9;	// Aseta pelaajan koordinaateiksi (8,8)
	player.y = 9;

	localEngine = engine;
}

/*-- Kun peli käynnistetään muista määrittää pelaajan koko --*/
void mushroomGame::initialize(dataType width, dataType height) {
	player.width = width;		// Määritä pelaajan leveys ja korkeus
	player.height = height;
	io.begin();					// Aseta pinnien tilat
}

/*--  --*/
void mushroomGame::assignDrawingFunction(void(*getFunctionPointer)(dataType x, dataType y)) {
	pointToPlayerDrawingFunction = getFunctionPointer;
}

/*-- Pelin pääfunktio --*/
void mushroomGame::run() {

	/* Päivitä pelifunktiota n. 62,5 kertaa sekunnissa */
	if (millis() - oldMushroomUpdateTime > 16) {
		draw();	// Piirrä kartta ja pelaaja

		/* Tarkista onko pelaaja ilmassa vai maassa */
		if (!localEngine->COLLISION_BELOW(&player)) {
			playerPhysics.calculateGravity(&player, millis() - oldUpdateTime);		// Laske painovoima pelaajalle
		} else {
			if (io.returnKey(io.KEY_JUMP)) {	// Jos hyppynappia painetaan
				player.vSpeed = -80.0f;
				player.y -= 1;	// Nosta pelaajaa yhdellä pikselillä jotta tilengine ei luule että pelaaja olisi jo maassa
			}
		}

		/* Jos pelaaja liikkuu vasemmalle */
		if (!localEngine->COLLISION_LEFT(&player)) {
			if (io.returnKey(io.KEY_LEFT)) {
				player.x -= 1;

				/* Jos pelaaja meni seinän sisään, siirrä pelaaja pois sieltä */
				if (localEngine->COLLISION_LEFT(&player)) {
					player.x += 1;
				}
			}
		}

		/* Jos pelaaja liikkuu oikealle */
		if (!localEngine->COLLISION_RIGHT(&player)) {
			if (io.returnKey(io.KEY_RIGHT)) {
				player.x += 1;

				/* Jos pelaaja meni seinän sisään, siirrä pelaaja pois sieltä */
				if (localEngine->COLLISION_RIGHT(&player)) {
					player.x -= 1;
				}

			}
		}

		/* Jos pelaaja törmää yllä olevaan palikkaan */
		if (localEngine->COLLISION_ABOVE(&player)) {
			player.vSpeed = abs(player.vSpeed)/2;
		}

		/* DEBUG */

		/*
		Serial.println("Törmäys vasemmalle: " + String(localEngine->COLLISION_LEFT));
		Serial.println("Törmäys oikealle: " + String(localEngine->COLLISION_RIGHT));
		Serial.println("Törmäys alla: " + String(localEngine->COLLISION_BELOW));

		Serial.println();
		*/

		oldUpdateTime = millis();
	}
	
}

/*--  --*/
void mushroomGame::draw() {
	localEngine->drawMap();	// Piirrä kartta
	pointToPlayerDrawingFunction(player.x, player.y);	// Piirrä pelaaja
}

/*--  --*/
void mushroomGame::loadMap(mapDataType * m) {
	localEngine->loadMap(m);
}