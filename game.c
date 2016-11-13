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

#include "game.h"

/* Requirement 3 - controls the flow of play in the game */
void play_game(void)
{

	char play_again[PROMPT_LENGTH];
	enum cell_contents board[BOARD_WIDTH][BOARD_HEIGHT];
	BOOLEAN quit = FALSE, end_of_game = FALSE, is_game_over=FALSE; 


	init_board(board);
	
	/*game algorithm */
	while(!quit && !end_of_game){
		
		if(is_game_over(board)==TRUE){
      char response[1+EXTRA_CHARS];
      sprintf(play_again, "Would you like to play again, y for yes and n for no? ");
      get_user_input(response, MOVE_LEN, play_again);
      if(strcmp(play_again, "y") == SAME_STRING){
        play_game();
      }else{
			quit = TRUE;
      }
		}
		
		
		if(player_move(board) == QUIT_THE_GAME){

         quit = TRUE;
         /* Break out of loop, as no more turns are needed */
         continue;
      };
	}/*end while loop */
	
  printf("Game end");
	/* display result */
  display_final_score(board);



}


/* Requirement 6 - tests to see whether a move is valid or not */
BOOLEAN is_valid_move(Move player_move, enum cell_contents board[][BOARD_HEIGHT])
{
  /* split player_move co-ordinates */
   int start_x = player_move.start.x;
   int start_y = player_move.start.y; 
   int end_x = player_move.end.x;
   int end_y = player_move.end.y;
  /* cell contents of moving positions. -start_Cell shouldbe PEG. end_cell should be HOLE.(inbetween-PEG)  */
   enum cell_contents start_cell = board[start_x][start_y];
   enum cell_contents end_cell = board[end_x][end_y];
   
   /* Integers to check the jump is only 2 (range -2,2,0) */
   int spaces_jumped_x = end_x - start_x;
   int spaces_jumped_y = end_y - start_y;

  /*1st validation: check the appropriate board piece is where it should be/ replacement for bounds checking */
  if(start_cell == PEG && end_cell == HOLE){
 

       /* 2nd validation: check that move is jumping only 2 spaces */
      if(spaces_jumped_x == -2 && spaces_jumped_y == 0){
        return TRUE;
        
      }
      else if(spaces_jumped_x == 2 && spaces_jumped_y == 0){
        return TRUE;
        
      }
      else if(spaces_jumped_y == -2 && spaces_jumped_x == 0){
        return TRUE;
        
      }
      else if(spaces_jumped_y == 2 && spaces_jumped_x == 0){
        return TRUE;  
      }
      else{
        printf("error in is_valid");
      }

    }   
    
    
  else{

    return FALSE;
  }
     /* If execution reaches here - - > no valid moves */
   return FALSE;

}

/* Requirement 7 - tests to see whether it is the end of the game */
BOOLEAN is_game_over(enum cell_contents board[][BOARD_HEIGHT])
{
  unsigned row,column;
  int i;
  Move gen_moves[4];

	for(column=0; column < BOARD_WIDTH; column++){
     for(row=0; row < BOARD_HEIGHT; row++){
          if(board[row][column]==PEG){
              generate_moves(gen_moves, row, column);

                for(i=0; i < 4; i++){
 
                    if(is_valid_move(gen_moves[i],board) == TRUE){
                         return FALSE;
                      }else{
                        return TRUE;
                      }
                  
					       }
				    }
			   }
		 }
	}



/* Requirement 5 - handle the logic for each individual move */
enum move_result player_move(enum cell_contents board[][BOARD_HEIGHT])
{
	/*get player input */
	char move_input[MOVE_LEN + EXTRA_CHARS];
	char make_move_prompt[PROMPT_LENGTH];
	Move move_pair;
	enum move_format is_format_correct;
  BOOLEAN is_valid_movee;

  

  BOOLEAN turn_over = FALSE;
  
 
  sprintf(make_move_prompt, "Please enter a move [enter Q or ctrl-D to quit: \n");
  
  while(turn_over == FALSE){

    display_board(board);

  	get_user_input(move_input, MOVE_LEN, make_move_prompt);

    /* If the input is empty, the user has selected to quit the game */  
   if (strcmp(move_input, "") == SAME_STRING || strcmp(move_input, "Q") == SAME_STRING)
   {
      return QUIT_THE_GAME;

   }
   is_format_correct = INCORRECT;
   is_valid_movee = FALSE;

  	/* Handles moving pieces once a move is validated */
  	is_format_correct = validate_move_format(move_input, &move_pair);
  	/*check if valid move */
  	is_valid_movee = is_valid_move(move_pair, board);

  	if(is_format_correct == CORRECT && is_valid_movee == TRUE){
  	     move_peg(move_pair, board);

  	} else if(is_format_correct == INCORRECT) {
      printf("Wrong format. Try again! \n\n");
     
    }
    else if(is_valid_movee == FALSE){
      printf("Invalid move. Try again!\n\n");
    }
    else{
      printf("problem has occured");
    }

   }
}


/* Validates that input from the user is in the correct format of a
 * move. If it is valid, it will create a move structure with this data 
 1. strtok to seperate start/end moves.
 2. then scanf seperates row/column moves and finally
 3.translate ascci to an integer
 Note: board x/y starts from 0 onwards at this stage 
 */
enum move_format validate_move_format(char * move_input, Move * move_pair){
	char * tok;
	char format_error[ERROR_LENGTH];
	char start_pos_block[POSITION_BLOCK_LENGTH + EXTRA_CHARS];
	char end_pos_block[POSITION_BLOCK_LENGTH + EXTRA_CHARS];
	unsigned start_x, start_y, end_x, end_y;
  Position starting_position, ending_position;


   sprintf(format_error, "The moves must be entered in the format such as these examples "
   	"B4-D4 or b4 d4 or b4, d4\n");
 

      /* 1. First strtok - grab the 2 positions */
    tok = strtok(move_input,DELIMS);

       /* move isnt in right format-give error*/
   if (tok == NULL)
   {
    	print_custom_error(format_error);
        return INCORRECT;
   }

    strcpy(start_pos_block,tok);
    tok = strtok(NULL,DELIMS);
    strcpy(end_pos_block,tok);
    

    /* seperate data to its individual integers where A=1 B=2 and so on*/
    
    /*validation - make sure letters are capital */
   	start_pos_block[0] = toupper(start_pos_block[0]);
    start_x = start_pos_block[0] - (0x41);
    start_y = atoi(&start_pos_block[1])-1;


    end_pos_block[0] = toupper(end_pos_block[0]);
    end_x = end_pos_block[0] - (0x41);
    end_y = atoi(&end_pos_block[1])-1;

     
    /* -- to counteract effect of arrays beginning with 0 rather than 1 */
    starting_position.x = start_x;
    starting_position.y = start_y;
    ending_position.x = end_x;
    ending_position.y = end_y;

    move_pair->start = starting_position;
    move_pair->end = ending_position;
    
    return CORRECT;
}


/* Handles the moving of pieces once a move is validated */
void move_peg(Move peg_move, enum cell_contents board[][BOARD_HEIGHT]){ 
 
  int jumped_peg_x;
  int jumped_peg_y;
  
  

   
   /*Copy the starting token to the target cell*/
   board[peg_move.end.x][peg_move.end.y] = PEG;
   board[peg_move.start.x][peg_move.start.y] = HOLE;
   
   /*Calculate/remove the value of the overtaken token - */
   jumped_peg_x = peg_move.start.x + ((int)(peg_move.end.x - peg_move.start.x)/2);
   jumped_peg_y = peg_move.start.y + ((int)(peg_move.end.y - peg_move.start.y)/2);
   /*remove overtaking peg*/
   board[jumped_peg_x][jumped_peg_y] = HOLE;

   
}




void display_final_score( enum cell_contents board[][BOARD_HEIGHT]){
  
  int pegs, column, row;
  
  pegs = 0;

  for(column=0; column < BOARD_WIDTH; column++){
       for(row=0; row < BOARD_HEIGHT; row++){
            if(board[row][column]==PEG){
              pegs++;
            }
          }
        }

  if(pegs > 1){
    printf("There are no more moves with %d pegs left.", pegs);
  }
  else if(board[3][3]==HOLE && pegs == 1){
    printf("You finished the puzzle with a single peg left.");

  }
  else{
    printf("You finished the puzzle with a single peg left in the centre");
  }

  }

  /* Takes in a peg on the board and returns 4 (up,down,left & right) unvalidated possible moves.*/
  void generate_moves(Move moves[], int x, int y)
  {
    /*moves jump by 2*/
    /* CLOCK-WISE: 1=UP,2=right,3=down, 4=left */
   int j;
   for(j=0;j<4;j++){
    moves[j].start.x = x;
    moves[j].start.y = y;

 } 
 

  /*up*/
  moves[0].end.y = moves[0].start.y - 2;
  moves[0].end.x = moves[0].start.x;
  
  /*right*/
   moves[1].end.x = moves[1].start.x + 2;
   moves[1].end.y = moves[1].start.y;
 
  /*down*/
  moves[2].end.y = moves[2].start.y + 2;
  moves[2].end.x = moves[2].start.x;
  /*left*/
  moves[3].end.x = moves[3].start.x - 2;
  moves[3].end.y = moves[3].start.x;
  
}





