#include "header.h"

class CHARACTER {
public:
	char name[30];
	int points, xPos, yPos, stepCount;

	CHARACTER();
	~CHARACTER(){};

	void movement(int keyPressed); //moves the character, decreases stepcount per each step and calling checkBoundaries()
	int checkBoundaries(int keyPressed); //checks whether character is inside the map
	int checkTreasure(MAP map);
};

CHARACTER::CHARACTER() {
	cout << "Type your name: ";
	cin >> this->name;
	xPos = 1;
	yPos = 1;
	points = 0;
	stepCount = 100;
}

void CHARACTER::movement(int keyPressed) {

	//initscr();
	//raw();
	//keypad(stdscr, TRUE);
	//noecho();
	if ( checkBoundaries(keyPressed) == 0 ) { 
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
	//endwin();
}

int CHARACTER::checkBoundaries(int keyPressed) {
	if ( keyPressed == KEY_UP && yPos == 1 ) {
		return 1;
	}
	else if ( keyPressed == KEY_DOWN && yPos == 20 ) {
		return 1;
	}
	else if ( keyPressed == KEY_LEFT && xPos == 1 ) {
		return 1;
	}
	else if ( keyPressed == KEY_RIGHT && xPos == 20 ) {
		return 1;
	}
	return 0;
}

int CHARACTER::checkTreasure(MAP map) {
	int i;

	for ( i = 0; i < NUM_OF_TREASURES; i++ ) {
		if ( map.treasures.treasures[i].xPos == xPos && map.treasures.treasures[i].yPos == yPos ) {
			points += 10;
		}
	}
}