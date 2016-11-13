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

#include "board.h"

/* copies the master board to a local copy for each game */
void init_board(enum cell_contents board[][BOARD_HEIGHT])
{
   unsigned row = 0, 
   			column = 0;
   for(row = 0; row < BOARD_HEIGHT; row++)
   {
      for(column = 0; column < BOARD_HEIGHT; column++)
      {
         board[column][row] = master_board[row][column];
      }
   }
}

/* display the game board to the screen */
void display_board(enum cell_contents board[][BOARD_HEIGHT])
{
	unsigned row,column;
  int i;
  char row_letters[] = " ABCDEFG";
  char *loop_through_row;
  loop_through_row = row_letters;

	for(column=0; column<BOARD_WIDTH;column++)
	{
		  int w;   
      int g;
      for(w=0;w<7;w++){ 
        if(board[column][w] == INVALID ){printf("         ");}
        else if(board[column][w]==PEG){printf("%s%*s%s%*s%s%*s", DASH,COLUMN_SPACING,  "", DASH,COLUMN_SPACING,  "", PLUS, COLUMN_SPACING,  "");}
        else if(board[column][w]==HOLE){printf("%s%*s%s%*s%s%*s", DASH,COLUMN_SPACING,  "", DASH,COLUMN_SPACING,  "", PLUS, COLUMN_SPACING,  "");}

    }  putchar('\n');

    g = column+1;
    /*prints column number*/
    printf("\n  %d  ", g);
    g++;

		for(row = 0; row < BOARD_HEIGHT; row++)
		{
			
        	switch(board[row][column])
         	{
         	case INVALID:
                printf("%*s ", CELL_SPACING, " ");
               break;
         	case HOLE:
         		printf("|%*s%s%*s%s", CELL_PADDING,  "",
                     COLOR_HOLE, CELL_PADDING, "", COLOR_RESET);
         		break;
         	case PEG:
         	   printf("|%*s%s%*s%s", CELL_PADDING,  "",
                     COLOR_PEG, CELL_PADDING, "", COLOR_RESET );
         		break;

          	}     

        }
	
   putchar('\n');
   putchar('\n');

}

/*Prints bottom row letters */

for(i=0;loop_through_row[i];i++){
      printf("%*s%c%*s ", HALF_CELL_SPACING, "",loop_through_row[i],HALF_CELL_SPACING, "");
    }
    putchar('\n');
    putchar('\n');

}

