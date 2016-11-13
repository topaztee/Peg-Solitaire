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

#ifndef GAME_H 
#define GAME_H

#include "board.h"
#include "utility.h"

#define MOVE_LEN 8
/*plus 2 to allow for \n and \0 */
#define EXTRA_CHARS 2
#define DELIMS "-, "



/*#define VALID_BOARDHEIGHT_MAIN 7 */
#define POSITION_BLOCK_LENGTH 2

typedef struct position {
	unsigned x, y;
}Position;

typedef struct move {
	Position start, end;
}Move;

enum move_result
{
	QUIT_THE_GAME, SUCCESSFUL_MOVE
};

/* tranlates column letters to numbers in order to change 2d-array board */
enum column
{
   A = 0, B = 1, C = 2, D = 3, E = 4, F = 5, G = 6
};

/* is move in the correct format */
enum move_format
{
   CORRECT, INCORRECT, QUIT_GAME
};
/* Is it a valid move */
enum move_type
{
   VALID_MOVE, INVALID_MOVE
};



/* Requirement 3 - controls the flow of play in the game */
void play_game(void);

/* Requirement 6 - tests to see whether a move is valid or not */
BOOLEAN is_valid_move(Move curr_move, enum cell_contents board[][BOARD_HEIGHT]);

/* Requirement 7 - tests to see whether it is the end of the game */
BOOLEAN is_game_over(enum cell_contents board[][BOARD_HEIGHT]);

/* Requirement 5 - handle the logic for each individual move */
enum move_result player_move(enum cell_contents board[][BOARD_HEIGHT]);

/* my functions */
enum move_format validate_move_format(char * move_input, Move * move_pair);

/* Handles moving validated peg piece */
void move_peg(Move move_to_process, enum cell_contents board[][BOARD_HEIGHT]);

void display_final_score(enum cell_contents board[][BOARD_HEIGHT]);
/*for end of game function checks if moves are available*/
void generate_moves(Move moves[], int x, int y);



#endif


