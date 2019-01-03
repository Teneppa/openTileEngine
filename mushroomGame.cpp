// 
// 
// 

#include "mushroomGame.h"
#include "variableType.h"

mushroomGame::mushroomGame(tilengine * engine) {
	player->x = 8;
	player->y = 8;

	localEngine = engine;
}

void mushroomGame::initialize(dataType width, dataType height, bitmapDataType * bitmap) {
	player->bitmap = bitmap;
	player->width = width;
	player->height = height;
}

void mushroomGame::draw() {
	localEngine->drawMap();
}

void mushroomGame::loadMap(mapDataType * m) {
	localEngine->loadMap(m);
}