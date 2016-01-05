#include "header.h"
#include "treasure.cpp"
#include "map.cpp"
#include "character.cpp"

int main() {
	srand(time(0));
	int keyPressed = '1';
	CHARACTER player;
	MAP map;
	int centerX, centerY, height = MAP_SIZE + 10, width = MAP_SIZE + 10;

	initscr();
	raw();
	cbreak();
	keypad(stdscr, TRUE);
	refresh();
	centerX = (COLS - width) / 2;
	centerY = (LINES - height) / 2;
	while ( keyPressed != 'q' && player.stepCount > 0 ) {
		player.movement(map, keyPressed);
		player.checkTreasure(&map);
		map.generateMap(player.xPos, player.yPos);
		printw("%s\n\n\n", player.name);
		map.drawMap(player.xPos, player.yPos);
		printw("\n\n(Current position: %i,%i :: Steps lefts: %i)\nPoints: %i\n\n%i %i", player.xPos, player.yPos, player.stepCount, player.points,LINES/2 - MAP_SIZE/2, LINES/2);
		refresh();
		keyPressed = getch();
		clear();
	}


	clear();


	if ( keyPressed != 'q' ) {
		mvprintw(10,1,"Final score: %i\n", player.points);
	}

	printw("Press any key to quit...");

	keyPressed = getch();

	endwin();

	return 0;
}
