#include "header.h"

class TREASURE {
public:
	int xPos, yPos;
	bool taken;

	TREASURE(){ taken = FALSE; };
	~TREASURE(){};
};

class TREASURES {
public:				    	
	TREASURE treasures[NUM_OF_TREASURES];

	TREASURES();
	~TREASURES(){};

	int unique(int xPos, int yPos, int currNumOfTreasures);
	void sortTreasures();
};

TREASURES::TREASURES() {
	int i, j;

	for ( i = 0; i < NUM_OF_TREASURES; i++ ) {
		do {
			treasures[i].xPos = rand()%20 + 1;
			treasures[i].yPos = rand()%20 + 1;
		} while ( unique(treasures[i].xPos, treasures[i].yPos, i) == 0 );
	}
}

int TREASURES::unique(int xPos, int yPos, int currNumOfTreasures) {
	int i;

	for ( i = currNumOfTreasures - 1; i >= 0; i-- ) {
		if ( treasures[i].xPos == xPos && treasures[i].yPos == yPos ) {
			return 0;
		}
	}
	return 1;
}