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

#ifndef UTILITY_H 
#define UTILITY_H
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 

#define PROMPT_LENGTH 180
#define INPUT_CHARS 2

 /*PAUL MILLER INSPIRED */
 #define ERROR_LENGTH 150
 /* When comparing strings, a value of 0 indicates that they are equal */
 #define SAME_STRING 0

 #define YELLOW_TEXT "\x1b[33m"
#define DEFAULT_TEXT "\x1b[0m" 

typedef enum {
	FALSE, TRUE
} BOOLEAN;

/* clears residual data from stdin */
void read_rest_of_line(void);


/* Prompts for and gets keyboard input from the user */
void get_user_input(char * input_string, unsigned max_length, char * prompt);

/* Prompts for and gets an integer from the user */
void get_integer(int * integer, unsigned length, char * prompt, int min, int max);


void print_custom_error(char * error_message);
#endif
