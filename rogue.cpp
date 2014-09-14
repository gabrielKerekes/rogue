#include "header.h"
#include "treasure.cpp"
#include "map.cpp"
#include "character.cpp"

WINDOW *create_newwin(int height, int width, int starty, int startx)
{	WINDOW *local_win;

	local_win = newwin(height, width, starty, startx);
	box(local_win, 0 , 0);		/* 0, 0 gives default characters 
					 * for the vertical and horizontal
					 * lines			*/
	wrefresh(local_win);		/* Show that box 		*/

	return local_win;
}

int main() {
	int keyPressed = '1', gd = DETECT, gm;
	CHARACTER player;
	MAP map;
	int centerX, centerY, height = MAP_SIZE + 10, width = MAP_SIZE + 10;
	
	initgraph(&gd, &gm, NULL);

	closegraph();

	srand(time(0));

	/*initscr();
	raw();
	cbreak();
	keypad(stdscr, TRUE);
	refresh();
	centerX = (COLS - width) / 2;
	centerY = (LINES - height) / 2;
	keyPressed = getch();
	while ( keyPressed != 'q' && player.stepCount > 0 ) {
		player.movement(keyPressed);
		player.checkTreasure(map);
		map.generateMap(player.xPos, player.yPos);
		printw("%s\n", player.name);
		map.drawMap();
		printw("(%i,%i :: %i)\nPoints: %i\n\n%i %i", player.xPos, player.yPos, player.stepCount, player.points,LINES/2 - MAP_SIZE/2, LINES/2);
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

	endwin();*/

	return 0;
}