
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "prog3.h"
#include <time.h>
#include <string.h>



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
  // allocate space for n pointers
  // n point to the rows
  char ** m = (char**)malloc(sizeof(char*) *n);

  // allocate space for n columns
  for (int x = 0; x < n; x++) {
    m[x] = (char*)malloc(sizeof(char)*n);
  }
  
  return m; // placeholder

}

// deallocates all dynamically allocated componens of a matrix previously produced by alloc_square_mtx
void free_square_mtx(char **m, int n) {

  for(int i = 0; i < n; i++)
  {
    // free the columns m[0][0]
    free(m[i]);
  }
  // free the rows m[0]
  free(m);
}

// populates square matrix of characters
// *		with random, lower-case letters a..z
void pop_mtx_alpha(char **m, int n){
  srand(time(NULL));
  for(int i = 0; i < n; i++)
  {
    for(int j=0;j<n;j++) {
      // m[i][j] = '.';
      m[i][j] = (rand() % 26) + 'a'; // range 0 to 99
    }
  }
}


//  prints given square matrix row-by-row 
// (printing a newline after each row).
void display_mtx(char **m, int n){
  for(int i = 0; i < n; i++)
  {
    for(int j=0;j<n;j++) {
      printf("%c", m[i][j]);
    }
    printf("\n");
  }
}


// swaps the contents of rows r1 and r2 of square matrix m.  
// Ordering of characters within rows are preserved.

void swap_rows(char **m, int n, int r1, int r2){
  if ((r1 <0) || (r2 < 0) || (r1 >= n) || (r2 >= n)) {
    return;
  }
  char* temp = m[r1]; 
  m[r1] = m[r2];
  m[r2] = temp;
}

// swaps the contents of column c1 and c2 of square matrix m.  
// Ordering of characters within rows are preserved.

void swap_cols(char **m, int n, int c1, int c2){
  if (c1 < 0 || c2 < 0 || c1 >= n || c2 >= n) {
    return;
  }

  for (int i = 0; i < n; i++) {
    char temp = m[i][c1]; // a
    m[i][c1] = m[i][c2]; // a = b
    m[i][c2] = temp; // b = a
  }
}


// "rotates" square matrix m 90 degrees right

void rotate_right(char **m, int n){
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n/2; j++) {
      char temp = m[i][j];
      m[i][j] = m[i][n-j-1];
      m[i][n-j-1] = temp;
    }
  }

  int cols = n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < cols; j++) {
      char temp = m[i][j];
      m[i][j] = m[n-j-1][n-i-1];
      m[n-j-1][n-i-1] = temp;
    }
    cols--;
  }
}

// popluates the given matrix with with the specified number of  "boulders" randomly placed.

void floating_boulders(char **m, int n, int nb){
  if (nb < 0) { // if all air
    return;
  }

  if (nb > n*n) { // if all #
    nb = n*n;
  }

  srand(time(NULL));
  for (int i = 0; i < nb;) {
    // add boulder
    int r = (rand() % n) + 0;
    int c = (rand() % n) + 0;

    if (m[r][c] != '#') {
      m[r][c] = '#';
      i++;
    }
  }
}


// populates the given matrix with a random ASCII

void mountains(char **m, int n){
  // random number of nb
  srand(time(NULL));
  for (int i = 0; i < n; i++) {
    int nb = (rand() % (n+1)) + 0;
    // printf("%d",nb); // remove later

    int k = n;
    for(int j = 0; j < nb; j++) {
      k = k-1;
      m[k][i] = '#';
    }
  }

  // printf("\n"); //remove later
}

// each row is moved downward, while top row will be all  '.'

void sink(char **m, int n){
  
  for (int i = n-1; i > 0 ; i--) { 
    swap_rows(m, n, i,i-1);
    // m[i] = m[i-1];
  }

  for (int i = 0; i < n; i++) {
    m[0][i] = '.';
  }
}
// loop by column
// loop from last row to top row
// whenever we see '.'
// we swap it with the not != '.' character above

void gravity(char **m, int n){
  for (int i = 0; i < n; i++) {
    for (int rows = n-1; rows > 0; rows--) {
      if (m[rows][i] == '.') {
        for (int j = rows-1; j >= 0; j--) {
          if (m[j][i] != '.' ) {
            char temp = m[rows][i];
            m[rows][i] = m[j][i];
            m[j][i] = temp;
            break;
          }
        }
      }
    }
  } 
}


/***********************************************
*                                             **
*   STRING FUNCTIONS                          **
*                                             **
***********************************************/

// remove any space character, before and after the string != space
void str_trim(char *s) {
    int count = 0;

    for (int i = 0; i < strlen(s); i++){
      if (!isspace(s[i])) {
        break;
      }
      count++;
    }

    if (count > 0) {
      for (int i = 0; i < (strlen(s) - count); i++) {
        char temp = s[i];
        s[i] = s[i+count];
        s[i+count] = temp;
      }
    }

    int count_2 = 0;

    for (int i = strlen(s)-1; i > -1; i--) {
      if (!isspace(s[i])) {
        break;
      }
      count_2++;
    }

    if (count_2 > 0) {
      s[strlen(s)-count_2] = '\0';
    }
}

// search the given substring from a given string
// return the starting index where it's found
// else return -1

int str_search(char *s, char *pattern) {

  printf("%s\n", s);
  printf("%s\n", pattern);

  if (strlen(pattern) > strlen(s) || strlen(pattern) == 0) {
    return -1;
  }

  for (int i = 0; i <= strlen(s)-strlen(pattern); i++) {

    if (s[i] == pattern[0]) {
      int flag = 1;

      for (int j = 1; j < strlen(pattern); j++) {
        if(s[i+j] != pattern[j]) {
          flag = -1;
          break;
        }
      }

      if (flag == 1) {
        return i;
      }

    } 

  }
  
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
  int a[3][3],i,j;
	printf("\nENTER VALUES FOR THE MATRIX:\n");

	for(i=0;i<2;i++)
		for(j=0;j<3;j++)
			scanf("%d",&a[i][j]);
	printf("\nTHE VALUES OF THE MATRIX ARE:\n");
	for(i=0;i<2;i++)
   	{
		for(j=0;j<3;j++)
			printf("%5d",a[i][j]);
  		printf("\n");
	}
  // test driver
  


}


#endif        // DO NOT REMOVE THIS LINE!!!
