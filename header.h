#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <string>
#include <ncurses.h>
#include <time.h>

#define MAP_SIZE 20
#define MAX_STEPS 100
#define NUM_OF_TREASURES 100
#define NUM_OF_BARRIERS 5
#define TORCH_SIZE 3
#define BARRIER_SIZE 3
#define TREASURE_CHAR 'T'
#define WATER_CHAR '@'
#define GROUND_CHAR '.'
#define PLAYER_CHAR '!'

using namespace std;