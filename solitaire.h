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

#ifndef SOLITAIRE_H 
#define SOLITAIRE_H
#include "game.h"
 #include <stdlib.h>

#define MENU_OPTIONS 3
#define MENUCHOICE_LEN 3


enum menu_choice
{
  PLAY_GAME = 1, HOW_TO_PLAY = 2, QUIT = 3
};

void printMenu();
/* Prompt user for menu choice */
int get_menu_choice(void);

void game_description(void);

#endif
