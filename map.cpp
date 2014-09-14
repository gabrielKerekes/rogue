#include "header.h"

class MAP {
public:
	int size;
	char groundChar, treasureChar, waterChar, verticalWallChar, horizontalWallChar, playerChar;
	char map[22][22];
	TREASURES treasures;

	MAP();
	~MAP(){};

	void drawMap();
	void generateMap(int playerXpos, int playerYpos);
};

MAP::MAP() {
	int i;

	size = 20;
	treasureChar = 'T';
	waterChar = '@';
	verticalWallChar = '|';
	horizontalWallChar = '_';
	groundChar = ' ';
	playerChar = '!';

	for ( i = 0; i < NUM_OF_TREASURES; i++ ) { 
		map[treasures.treasures[i].yPos][treasures.treasures[i].xPos] = treasureChar;
	}
}

void MAP::drawMap() {
	int i, j;

	for ( i = 0; i < size + 2; i++ ) {
		for ( j = 0; j < size + 2; j++ ) {
			printw("%c", map[i][j]);
			if ( j == size + 1 ) printw("\n");
		}
	}
}

void MAP::generateMap(int playerXpos, int playerYpos) {
	int i, j;

	for ( i = 0; i < size + 2; i++ ) {
		for ( j = 0; j < size + 2; j++ ) {
			if ( i == 0 || i == size + 1 ) {
				map[i][j] = waterChar;
			}
			else if ( j == 0 || j == size + 1 ) {
				map[i][j] = waterChar;
			}
			else if ( i == playerYpos && j == playerXpos ) {
				map[i][j] = playerChar;
			}
			else if ( map[i][j] != treasureChar ) {
				map[i][j] = groundChar;
			}
		}
	}
}