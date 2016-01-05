#include "header.h"

class MAP {
public:
	int size, torchlightSize;
	char map[22][22], torchlightCoords[7][7];
	bool visible[22][22];
	TREASURES treasures;

	MAP();
	~MAP(){};

	void drawMap(int playerXpos, int playerYpos);
	void generateMap(int playerXpos, int playerYpos);
	bool torchlight(int playerXpos, int playerYpos, int i, int j);
	bool torchlightWall();
	void generateBarriers();
};

MAP::MAP() {
	int i;

	size = MAP_SIZE;
	torchlightSize = TORCH_SIZE;

	for ( i = 0; i < NUM_OF_TREASURES; i++ ) { 
		map[treasures.treasures[i].yPos][treasures.treasures[i].xPos] = TREASURE_CHAR;
	}

	generateBarriers();
}

void MAP::drawMap(int playerXpos, int playerYpos) {
	int i, j;

	for ( i = 0; i < size + 2; i++ ) {
		for ( j = 0; j < size + 2; j++ ) {
			if ( visible[i][j] || i == 0 || j == 0 || i == 21 || j == 21 ) {
				printw("%c", map[i][j]);
			}
			else {
				printw(" ");
			}
			if ( j == size + 1 ) printw("\n");
		}
	}
}

void MAP::generateMap(int playerXpos, int playerYpos) {
	int i, j;

	for ( i = 0; i < size + 2; i++ ) {
		for ( j = 0; j < size + 2; j++ ) {
			if ( i == 0 || i == size + 1 ) {
				map[i][j] = WATER_CHAR;
			}
			else if ( j == 0 || j == size + 1 ) {
				map[i][j] = WATER_CHAR;
			}
			else if ( i == playerYpos && j == playerXpos ) {
				map[i][j] = PLAYER_CHAR;
			}
			else if ( map[i][j] != TREASURE_CHAR && map[i][j] != '@' ) {
				map[i][j] = GROUND_CHAR;
			}
			if ( torchlight(playerXpos, playerYpos, i, j) ) {
				visible[j][i] = TRUE;
			}
			else {
				visible[j][i] = FALSE;
			}
		}
	}
}

bool MAP::torchlight(int playerXpos, int playerYpos, int i, int j) {
	int k, l;

	for ( k = -1; k < 2; k++ ) {
		if ( (i == playerXpos + k && j == playerYpos - 2 ) || (i == playerXpos + k && j == playerYpos + 2 ) )  { 
			return TRUE;
		}
	}
	for ( k = -2; k < 3; k++ ) {
		if ( (i == playerXpos + k && j == playerYpos - 1 ) || (i == playerXpos + k && j == playerYpos + 1 ) )  { 
			return TRUE;
		}
	}
	for ( k = -3; k < 4; k++ ) {
		if ( (i == playerXpos + k && j == playerYpos ) || (i == playerXpos + k && j == playerYpos ) )  { 
			return TRUE;
		}
	}
	if ( (i == playerXpos && j == playerYpos - 3 ) || (i == playerXpos && j == playerYpos + 3 ) )  { 
		return TRUE;
	}
	return FALSE;
}

void MAP::generateBarriers() {
	int horizontal, i, j, xPos, yPos, overlap;

	for ( i = 0; i < NUM_OF_BARRIERS; i++ ) {
		horizontal = rand()%2;
		if ( horizontal ) {
			xPos = rand()%MAP_SIZE + 1;
			yPos = rand()%MAP_SIZE + 1;
			overlap = (MAP_SIZE + 1) - BARRIER_SIZE - xPos;
			if ( overlap >= 0 ) {
				overlap = 0;
			}
			else {
				overlap *= -1;
			}
			for ( j = 0; j < BARRIER_SIZE - overlap; j++ ) {
				map[yPos][xPos + j] = '@';
			}
		}
		else {
			xPos = rand()%MAP_SIZE + 1;
			yPos = rand()%MAP_SIZE + 1;
			overlap = (MAP_SIZE + 1) - BARRIER_SIZE - yPos; 
			if ( overlap > 0 ) {
				overlap = 0;
			}
			else {
				overlap *= -1;
			}
			for ( j = 0; j < BARRIER_SIZE - overlap; j++ ) {
				map[yPos + j][xPos] = '@';
			}
		}
	}
}

//i == 0 || i == size + 1 || j == 0 || j == size + 1 || 
