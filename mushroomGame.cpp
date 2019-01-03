// 
// 
// 

#include "mushroomGame.h"
#include "variableType.h"

mushroomGame::mushroomGame() {
	player.x = 8;
	player.y = 8;
}

void mushroomGame::initialize(dataType width, dataType height, bitmapDataType * bitmap) {
	player.bitmap = bitmap;
	player.width = width;
	player.height = height;
}

void mushroomGame::draw(tilengine &engine) {

}

void mushroomGame::loadMap(uint16_t * map) {

}