/***********************************************************************
 * COSC1076 - Advanced Programming Techniques
 * Summer 2015 Assignment #1 
 * Full Name        : TOPAZ TURKENITZ
 * Student Number   : S3435042
 * Course Code      : BP094
 * Program Code     : COSC1076
 * Start up code provided by David Shaw
 * Based on 2014 code by Paul Miller and Virginia King
 **********************************************************************/

#ifndef BOARD_H 
#define BOARD_H
 #include "utility.h"

#define BOARD_WIDTH	7
#define BOARD_HEIGHT 7

/* colour codes for displaying the board */
#define COLOR_RESET     "\x1b[0m"
#define COLOR_LINES     "\x1b[2;34m"    /* blue */
#define COLOR_HOLE      "\x1b[2;34m" "."    /* blue */
#define COLOR_PEG       "\x1b[1;37m" "o"   /* white */

/*added*/
#define LINE_PADDING 53
#define CELL_PADDING 2
#define CELL_SPACING 5
#define HALF_CELL_SPACING 2
#define COLUMN_SPACING 1

#define DASH "-"
#define PLUS "+"
enum cell_contents {
	INVALID, HOLE, PEG
};

/* The initial game board - this is an example of the occasional
 * exception to the rule against global variables. Be aware that
 * this should be the only global variable in your program */
static const enum cell_contents master_board[BOARD_HEIGHT][BOARD_WIDTH] = {
	{ INVALID, INVALID, PEG, PEG, PEG, INVALID, INVALID },
	{ INVALID, INVALID, PEG, PEG, PEG, INVALID, INVALID },
	{ PEG, PEG, PEG, PEG, PEG, PEG, PEG },
	{ PEG, PEG, PEG, HOLE, PEG, PEG, PEG },
	{ PEG, PEG, PEG, PEG, PEG, PEG, PEG },
	{ INVALID, INVALID, PEG, PEG, PEG, INVALID, INVALID },
	{ INVALID, INVALID, PEG, PEG, PEG, INVALID, INVALID }
};


/***  Game board for Testing end of game function ***/
/*
static const enum cell_contents test_board[BOARD_HEIGHT][BOARD_WIDTH] = {
	{ INVALID, INVALID, HOLE, HOLE, HOLE, INVALID, INVALID },
	{ INVALID, INVALID, HOLE, HOLE, HOLE, INVALID, INVALID },
	{ HOLE, HOLE, HOLE, HOLE, HOLE, HOLE, PEG },
	{ HOLE, HOLE, HOLE, HOLE, HOLE, HOLE,  PEG },
	{ HOLE, HOLE, HOLE, HOLE, HOLE, HOLE, HOLE },
	{ INVALID, INVALID, HOLE, HOLE, HOLE, INVALID, INVALID },
	{ INVALID, INVALID, HOLE, HOLE, HOLE, INVALID, INVALID }
};
*/
/******/

/* Requirement 2 - copies the contents of master_board to a local
 * board for each game */
void init_board(enum cell_contents board[][BOARD_WIDTH]);

/* Requirement 4 - displays the puzzle game board to the screen */
void display_board(enum cell_contents board[][BOARD_WIDTH]);


/* Outputs formatting chars*/
void putline(size_t numspaces, char ch);

#endif
