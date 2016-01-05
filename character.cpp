#include "header.h"

class CHARACTER {
public:
	char name[30];
	int points, xPos, yPos, stepCount;

	CHARACTER();
	~CHARACTER(){};

	void movement(MAP map, int keyPressed); //moves the character, decreases stepcount per each step and calling checkBoundaries()
	int checkBoundaries(MAP map, int keyPressed); //checks whether character is inside the map
	int checkTreasure(MAP *map);
};

CHARACTER::CHARACTER() {
	cout << "Type your name: ";
	cin >> this->name;
	xPos = 1;
	yPos = 1;
	points = 0;
	stepCount = 100;
}

void CHARACTER::movement(MAP map, int keyPressed) {

	if ( checkBoundaries(map, keyPressed) == 0 ) { 
		if ( keyPressed == KEY_UP ) {	
				yPos--;
				stepCount--;
		}
		else if ( keyPressed == KEY_DOWN) {
			yPos++;
			stepCount--;
		}
		else if ( keyPressed == KEY_LEFT) { 
			xPos--;
			stepCount--;
		}
		else if ( keyPressed == KEY_RIGHT ) {
			xPos++;
			stepCount--;
		}
	}

}

int CHARACTER::checkBoundaries(MAP map, int keyPressed) {
	if ( keyPressed == KEY_UP && map.map[yPos - 1][xPos] == WATER_CHAR ) {
		return 1;
	}
	else if ( keyPressed == KEY_DOWN && map.map[yPos + 1][xPos] == WATER_CHAR) {
		return 1;
	}
	else if ( keyPressed == KEY_LEFT && map.map[yPos][xPos - 1] == WATER_CHAR ) {
		return 1;
	}
	else if ( keyPressed == KEY_RIGHT && map.map[yPos][xPos + 1] == WATER_CHAR ) {
		return 1;
	}
	return 0;
}

int CHARACTER::checkTreasure(MAP *map) {
	int i;

	for ( i = 0; i < NUM_OF_TREASURES; i++ ) {
		if ( map->treasures.treasures[i].xPos == xPos && map->treasures.treasures[i].yPos == yPos ) {
			points += 10;
			map->treasures.treasures[i].xPos = 0;
			map->treasures.treasures[i].yPos = 0;
			map->map[map->treasures.treasures[i].yPos][map->treasures.treasures[i].xPos] = GROUND_CHAR;
		}
	}
}