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

#include "utility.h"


/* Tidy up residual data in stdin when encountering an error. You will 
 * need to use this when there is a possibility that there will be 
 * leftover characters in the input buffer. */
void read_rest_of_line(void)
{
        int ch;
        /* remove all characters from the buffer */
        while (ch = getc(stdin), ch != '\n' && ch != EOF)
                ;
        /* clear the error status of the input pointer */
        clearerr(stdin);
}

/*checks for extra unwanted chars and removes thems*/
void detect_buffer_overflow(char *buffer){
	

	if(buffer[strlen(buffer)-1] != '\n')
	{
		printf("bufferflow error\n" );
		/*function clears remaining input from input buffer */
		read_rest_of_line();
	}
	else
		{
			/* last character in string is \n newline. lets remove it */
			buffer[strlen(buffer) -1 ] = 0;
			
		}

}


/* NOTE TO SELF... change below function to implement detect_buffer_overflow function.. makes it simpler?? */

/* Prompts for and gets keyboard input from the user */
void get_user_input(char * input_string, unsigned max_length, char * prompt)
{
   char * entered_string;
   BOOLEAN finished;
   
   /* Allocate enough memory to store `max_length` number of characters, plus 2 
    * more to allow for \n and \0. */
   entered_string = (char *) malloc((max_length + INPUT_CHARS) * sizeof(char));   
   finished = FALSE;
   
   /* Ensure that memory was allocated successfully. Display an error if not. */
   if (entered_string == NULL)
   {
      print_custom_error("There is not enough memory. Please close "
      "other programs and try again.");
   }
   else
   {
      /* Keep prompting until a valid input has been entered */
      do
      {
         /* Display a prompt for the input */
         printf("%s", prompt);
         
         /* Get input from the user. Desired length increased by 2 to allow 
          * for \n and \0. If it returns NULL, string was empty. */
         if (fgets(entered_string, max_length + INPUT_CHARS, stdin) != NULL)
         {
            /* A string that doesn't have a newline character is too long. */
            if (entered_string[strlen(entered_string) - 1] != '\n')
            {
               /* String was too long. Reject string and flush input buffer. */
               print_custom_error("Input was too long.\n");
               read_rest_of_line();
            }
            /* Found newline character, string is acceptable length */
            else
            {
               /* Overwrite the \n character with \0. */
               entered_string[strlen(entered_string) - 1] = '\0';
               finished = TRUE;
            }
         }
         /* If an empty string has been entered, we don't need to process
          * as above */
         else
         {
            /* Print a newline, as pressing Ctrl-D will not do this, which may
             * result in the next print being displayed on the same line */
            printf("\n");
            finished = TRUE;
         }
         
         /* Put the entered string into the variable that's accessible to 
          * calling function */
         strcpy(input_string, entered_string);
         
      } while (!finished);
      
      /* Free the memory space used for the entered string */
      free(entered_string);
   }
}


/* Prompts for and gets an integer from the user.
 * Adapted from code written by Steven Burrows 
 * in getInteger-basic.c, June 2006 */
void get_integer(int * integer, unsigned length, char * prompt, int min, int max)
{
   int finished = FALSE;
   char * tempString;
   int tempInteger=0;
   char * endPtr;
   char bounds_error[ERROR_LENGTH];
   
   sprintf(bounds_error, "Input was not within range %d - %d.\n", min, max);
   
   /* Allocate enough memory to store `length` number of characters, plus 2 
    * more to allow for \n and \0. */
   tempString = malloc((length + INPUT_CHARS) * sizeof(char));

   /* Ensure that memory was allocated successfully. Display an error if not. */
   if (tempString == NULL)
   {
      print_custom_error("There is not enough memory. Please close "
      "other programs and try again.");
   }
   else
   {
      /* Keep prompting until a valid input has been entered */
      do
      {
         /* Display a prompt for the input */
         printf("%s", prompt);
         
         /* Get input from the user. Desired length increased by 2 to allow 
          * for \n and \0. */
         fgets(tempString, length + INPUT_CHARS, stdin);

         /* A string that doesn't have a newline character is too long. */
         if (tempString[strlen(tempString) - 1] != '\n')
         {
            /* String was too long. Reject string and flush input buffer. */
           /* necessarry????  print_custom_error("Input was too long.\n");   */
            read_rest_of_line();
         }
         /* Found newline character, string is acceptable length */
         else
         {
            /* Overwrite the \n character with \0. */
            tempString[strlen(tempString) - 1] = '\0';

            /* Convert string to an integer. */
            tempInteger = (int) strtol(tempString, &endPtr, 0);

            /* If a letter is found, input was not completely numeric */
            if (strcmp(endPtr, "") != SAME_STRING)
            {
               print_custom_error("Input was not numeric.\n");
            }
            /* Check that input number was within accepted range */
            else if (tempInteger < min || tempInteger > max)
            {
               print_custom_error(bounds_error);
            }
            else
            {
               finished = TRUE;
            }
         }
      } while (finished == FALSE);
      
      /* Free the memory space used for the entered string */
      free(tempString);
   }
   
   /* Make the result integer available to calling function. */
   *integer = tempInteger;
}


/* Prints a custom error message in yellow text */
void print_custom_error(char * error_message)
{
   fprintf(stderr, YELLOW_TEXT);
   /*fprintf(stderr, error_message);*/
   fprintf(stderr, DEFAULT_TEXT);
}

