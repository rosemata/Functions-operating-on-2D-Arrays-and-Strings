
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "prog3.h"



/**
* 
*  Function "stubs" for Assignment 3 exercises.
*
*  See prog3.h for specifications of function behavior.
*
*/



/***********************************************
*                                             **
*   MATRIX FUNCTIONS                          **
*                                             **
*   NOTE:  parameter n ALWAYS expresses the   **
*     dimensions of the square matrix in      **
*     question.                               **
*                                             **
***********************************************/
char ** alloc_square_mtx(int n) {

    return NULL; // placeholder

}

void free_square_mtx(char **m, int n) {

}

void pop_mtx_alpha(char **m, int n){


}


void display_mtx(char **m, int n){


}

void swap_rows(char **m, int n, int r1, int r2){


}

void swap_cols(char **m, int n, int c1, int c2){

}


void rotate_right(char **m, int n){

}


void floating_boulders(char **m, int n, int nb){

}


void mountains(char **m, int n){

}



void sink(char **m, int n){

}



void gravity(char **m, int n){

}




/***********************************************
*                                             **
*   STRING FUNCTIONS                          **
*                                             **
***********************************************/


void str_trim(char *s) {

}


int str_search(char *s, char *pattern) {

  return -1;  // just a placeholder to make gcc happy for now

}





#ifndef _LIB  // DO NOT REMOVE THIS LINE!!!
              // IT DOESN"T CHANGE HOW YOUR PROGRAM
              // WORKS, BUT IT GIVES US A WAY TO CALL
              // YOUR FUNCTIONS FROM OUR CODE FOR
              // TESTING

/**
* Write a test driver in main below to exercise and
*   your function implementations.
*
* Think carefully about your test cases!
*/
int main(){



  // test driver


}


#endif        // DO NOT REMOVE THIS LINE!!!
