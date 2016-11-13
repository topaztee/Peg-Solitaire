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

#include "solitaire.h"


int main(int argc, char *argv[])
{
	int menu_choice = 0;
    

   while(menu_choice!= QUIT){
   	printMenu();
	
    menu_choice = get_menu_choice();


	/*--- menu choice actions ---*/
    	
    	switch(menu_choice)
    	{
    		case PLAY_GAME:
				play_game();
				break;
    		case HOW_TO_PLAY:
    			game_description();
    			break;
    		case QUIT:
    			printf("Thank you for playing.\n");
            	break;
            default:
            printf("\nPlease enter a number from %d to %d\n", 
               PLAY_GAME, QUIT);
    	}
    }
    


	return EXIT_SUCCESS;



}


/* Display the user menu */
void printMenu()
{
	 /*--- Game's main menu ---*/
	printf( "PEG SOLITIARE \n");
    printf("1. Play Game \n");
    printf("2. How to Play \n");
    printf("3. Quit\n");

}

/* Prompt user for menu choice */
int get_menu_choice(void)
{
   int selection;
   char menu_prompt[PROMPT_LENGTH];
   
   /* Create the message to prompt the user with, including the acceptable 
    * range of values */
   sprintf(menu_prompt, "Please enter a menu option (%d - %d): ", PLAY_GAME, 
      QUIT);
   
   /* Display the prompt and accept an integer from the user */
   get_integer(&selection, 1, menu_prompt, PLAY_GAME, 
      QUIT);
   
   return selection;
}

void game_description(void){
   
    char c = '\0';
     
    printf(" \n\n RULES OF PEG SOLITIARE \n");
    printf(" ----------------------- \n\n");
    printf("GAME OBJECTIVE \nThe object of the game is to remove as many pegs as possible"
    " before you are left in a position without any valid moves (i.e. no pegs can make a valid jump)."
    " The ideal solution to the puzzle is to be left with a single peg in the centre hole.\n"
    "\n HOW TO MOVE\n"
    "The only valid move in Peg Solitaire is jump a peg over an orthogonally "
    "adjacent peg (up, down, left or right, not diagonal) into an empty hole.\n\n"
    );

    while( c != '\n' ) {
      c = getchar();

    }
   
}

