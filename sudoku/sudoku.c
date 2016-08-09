// Check if a board of sudoku is won

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cs50.h>

#include "helpers.h"

// board
int sort_nine[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
int board[] = {\
9, 6, 2, 1, 5, 8, 3, 7, 4, \
4, 1, 8, 9, 7, 3, 2, 6, 5, \
3, 5, 7, 4, 2, 6, 9, 1, 8, \
5, 4, 9, 6, 8, 2, 1, 3, 7, \
8, 7, 6, 3, 1, 4, 5, 2, 9, \
2, 3, 1, 5, 9, 7, 4, 8, 6, \
6, 8, 3, 2, 4, 5, 7, 9, 1, \
1, 2, 4, 7, 6, 9, 8, 5, 3, \
7, 9, 5, 8, 3, 1, 6, 4, 2};

void col(int array[], int c);
void row(int array[], int r);
void square(int array[], int x, int y);
bool nine(int array[]);
bool won();


int main(void)
{
	if (won())
	{
		printf("You won!\n");
		return 0;
	}
	else
	{
		printf("Sorry, check your answer again.\n");
		return 1;
	}
}

// Generate an array of the c_th
// column of the board.
// c starts from 0.
void col(int array[], int c)
{
	for (int i = 0; i < 9; ++i)
	{
		array[i] = board[c + 9 * i];
	}
}

// Generate an array of the r_th
// row of the board.
// r starts from 0.
void row(int array[], int r)
{
	for (int i = 0; i < 9; ++i)
	{
		array[i] = board[r * 9 + i];
	}
}

// Generate an array of the (x, y) square
// of the board.
// x is the horizontal position from
// left to right of the board.
// y is the vertical position
// from top to bottom of the board
// Both x, y range in (0, 3).
void square(int array[], int x, int y)
{
	// start position of the first grid (the top left)
	// of the square
	int start = y * 9 * 3 + x * 3;
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			array[3 * i + j] = board[start + 9 * i + j];
		}
	}
}

bool nine(int array[])
{
	sort(array, 9);
	// check if the given array is the same as
	// the one of the sorted array from 1 to 9
	if (memcmp(array, sort_nine, 9 * 4) != 0)
	    {
	    	return false;
	    }
	else
	{
		return true;
	}
}

bool won()
{
	for (int i = 0; i < 9; ++i)
	{
		int i_col[9], i_row[9], xy_square[9];
		// generate column, row, and square arrays
		col(i_col, i);
		row(i_row, i);
		square(xy_square, i % 3, i / 3);
		// check if the arrays include 1 to 9
		// return false if any of them fail
		if ((!nine(i_col)) || (!nine(i_row)) || (!nine(xy_square)))
		{
			return false;
		}
	}
	return true;
}